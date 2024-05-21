#include "opConsole.h"

opConsole::opConsole()
{
	chid = -1;
	coid = -1;
}

int opConsole::getChid(){
	return chid;
}

int opConsole::getCoid(){
	return coid;
}

void opConsole::reqChangeAircraftInfo(int planeId) {
	int newVelocity;
	cout << "input new velocity to avoid plane collision: " << endl; 
	cin >> newVelocity; 
	MsgSend(chid, newVelocity, NULL, 0);
}


void waitForMsg(){
// Wait for collision notification from computer system
	while(true){
		 if(int rcvid = MsgReceive(chid, OperatorCollisionNotification, sizeof(OperatorCollisionNotification), NULL) != -1){
			 int currentVelocity = OperatorCollisionNotification.currentVelocity;
			 int planeId = OperatorCollsionNotification.planeId;
			 MsgReply(rcvid, EOK, OperatorCollisionNotification, sizeof(OperatorCollisionNotification)); //Not sure if message replied is supposed to be OperatorCollisionNotification
		 }
	}
}

void opConsole::reqInfoRadar(){
	int planeID;
	cout << "input plane ID to get info of: " << endl; 
	cin >> planeID;
	MsgSend(chid, planeID, NULL, 0);
}
