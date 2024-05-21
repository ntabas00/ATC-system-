#pragma once
#ifndef OPCONSOLE_H_
#define OPCONSOLE_H_

#include <iostream>
#include "computer_system.h"
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <sync.h>
#include <sys/siginfo.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <sys/syspage.h>
#include <inttypes.h>
#include <stdint.h>

using namespace std; 

typedef struct {
	int planeID;
	Vec3 newVelocity;
} OperatorSpeedChange;

typedef struct{
	int planeID;
	Vec3 currentVelocity;
 } OperatorCollsionNotification;


class opConsole {
public: 
	opConsole(); 
	//~opConsole(); 
	//int getTime(); no need use  t = clock() from ctime 
	int getChid(); 

	void reqChangeAircraftInfo(int planeId);
	void waitForMsg();

	

private: 
	int chid;
	int coid;

};

