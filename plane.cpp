#include "plane.h"
#include <time.h>
#include <iostream>
#include <sys/neutrino.h>
#include <pthread.h>

// Plane constructor. Parameters taken from input file
Plane::Plane(initialPlaneParameters &params) {
	initialParams(params);
	Plane.currentPosition = initialParams.initialPosition;
	Plane.currentVelocity = initialParams.initialVelocity;
	Plane.chid = -1;
}

// Plane ID getter
int Plane::getPlaneId() const {
	return initialParams.id;
}

// Plane Channel ID getter
int Plane::getChid() const {
	return chid;
}

// Plane position getter
int Plane::getCurrentPosition() const {
	return currentPosition;
}

// Plane velocity getter
int Plane::getCurrentVelocity() const {
	return currentVelocity;
}

void Plane::updatePosition() {
	currentPosition.x += currentVelocity.x * time_period;
	currentPosition.y += currentVelocity.y * time_period;
	currentPosition.z += currentVelocity.z * time_period;

	if (currentPosition.x < 0
		|| currentPosition.x > 100000
		|| currentPosition.y < 0
		|| currentPosition.y > 100000
		|| currentPosition.z < 0
		|| currentPosition.z > 25000) {
		left = true;
	}
}

void Plane::waitForCmd() {
	int rcvid;
	planeCommand cmd;

	while (true) {
		// Wait indefinitely until message is sent to plane.
		rcvid = MsgReceive(chid, &cmd, sizeof(cmd), NULL);

		// If the message received is not a pulse
		if (rcvid != 0) {
			switch (cmd.command) {
			case 1: {
				// 1 signifies a ping from the radar, plane responds with position and velocity.
				currentPlanePosition curr{ currentPlanePosition, currentVelocity };
				MsgReply(rcvid, EOK, &curr, sizeof(curr));
				break;
			}
			case 2: {
				// 2 signifies a command to change velocity to avoid violation.
				currentVelocity = cmd.newVelocity;
				MsgReply(rcvid, EOK, NULL, 0);
				break;
			}
			default:
				// If the command does not match one of the cases, a function is not implemented error will occur.
				std::cout << "Plane" << initialPlaneParameters.id << " has received an unknown command." << std::endl;
				MsgError(rcvid, ENOSYS);
				break;
			}

		}
	}
}

void Plane::enterAirspace() {
	
	// Create new communication channel for plane
	if ((chid = ChannelCreate(0)) == -1) {
		// If ChannelCreate(0) returns -1, channel creation has failed
		std::cout << "Plane" << initialPlaneParameters.id << " has failed to create a communication channel. Terminating thread." << std::endl;
		return;
	}
	Timer planeTimer(chid);

	planeTimer.setTimer(initialParams.arrivalTime, 0, POSIION_UPDATE_INTERVAL, 0);

	waitForCmd();

}


void *thread_start (void *arg) {
	struct thread_args *targs = ( struct thread_args * ) arg;

	int *i=targs->location;
	int length=targs->length;


	for (int j=0; j<length; j++ ){
		if (*(i+j)==0){
			*(i+j)=1;
		}
		else{
			*(i+j)=0;
		}
	}
	return NULL;
}
