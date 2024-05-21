// Header file for computer system
// Created on: March 18, 2023
// Author: Michael Dickson

#ifndef COMPUTERSYSTEM_H_
#define COMPUTERSYSTEM_H_

#include <pthread.h>
#include <vector>
#include "Radar.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>



class ComputerSystem {
public:
	// Computer system constructor
	ComputerSystem();

	// Computer system destructor
	~ComputerSystem();

private:
	// Function for logging plane position data from radar
	void positionLog();
	void checkViolation(Plane p1, Plane p2, int lookaheadValue);
	void checkAll(int lookaheadValue);
	void waitForOpCon();
	void sendToDisplay();
	void sendToComm(int planeId, Vec3 newVelocity);
};
