/*
 * comsys.h
 *
 *  Created on: Mar. 24, 2023
 *      Author: coen320
 */

#ifndef COMSYS_H_
#define COMSYS_H_
#include "plane.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/dispatch.h>

using namespace std;

class comsys {
public:
	comsys();

	virtual ~comsys();


private:
	Vec3 waitForCommunication();
	void sendToPlane(Plane R, Vec3 newVelocity);

};

#endif /* COMSYS_H_ */
