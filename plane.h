#ifndef PLANE_H_
#define PLANE_H_

#include "timer.h"

using namespace std;

// 3D Vector data type
typedef struct Vec3{
	int x;
	int y;
	int z;
	
	Vec3 sum(Vec3 v) {
		return { x + v.x, y + v.y, z + v.z };
	}

	Vec3 scalarMult(int scalar) {
		return { x * scalar, y * scalar, z * scalar };
	}
}Vec3;

// Data type containing initial parameters for constructing Plane object
typedef struct {
	int id;
	int arrivalTime;
	Vec3 initialPosition;
	Vec3 initialVelocity;
}initialPlaneParameters;

// Data type containing current position and velocity of a plane
typedef struct {
	Vec3 currentPosition;
	Vec3 currentVelocity;
}currentPlanePosition;

typedef struct {
	struct _pulse header;
	int command;
	Vec3 newVelocity;
}planeCommand;

typedef struct{    /* Used as argument to the start routine thread_start() */
	pthread_t thread_id;        /* ID returned by pthread_create() */
	int length;        /* length of the row */
	int* location;      /* Location of the row */
} thread_args;

class Plane {
public:
	// Plane Constructor
	Plane(initialPlaneParameters &params);
	// Getters
	int getPlaneId() const;
	int getChid() const;
	int getCurrentPosition() const;
	int getCurrentVelocity() const;

private:
	// Function for updating the postion of the plane
	void updatePosition();
	void waitForCmd();
	void enterAirspace();
	initialPlaneParameters initialParams;
	Vec3 currentPosition;
	Vec3 currentVelocity;
	bool left;
	int chid;


};
