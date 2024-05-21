#include "computer_system.h"
#include "plane.h"

using namespace std;

// Computer System Constructor
ComputerSystem::ComputerSystems() {
	
	initialize();

}

// Computer System Destructor

ComputerSystem::~ComputerSystem() {

}

void ComputerSystem::positionLog() {
	// Temp radar function name
	vector<int> airspace;
	airspace = PSR.findAllPlanesInAirspace();

	vector<pair<int, planeInfo*>> planePositions = SSR.interrogatePlanesInAirspace(airspace);
	// Log plane's position, velocity and ID into arrays
	int coid;
	if(coid = ConnectAttach(0, 0, dataChid, 0, 0) == -1){
		cout << "Error. Connection not established" << endl;
		return;
	}
	msgSend(coid, planePositions, planePositions.size(), NULL, 0);
	
	////// file writing ////////////////////
	char buffer[];
    int  fd;
    int  size_written;

    for ( int i = 0; i < airspace.size(); i++){
    	buffer[i] = planePositions[i].first + " " + planePositions[i].second;
    }
    /* open a file for output          */
    /* replace existing file if it exists */

/* The flags in the function creat(...) gives the user the writing, reading and searching priviliges*/

    fd = creat( "/data/home/qnxuser/myfile.dat", S_IRUSR | S_IWUSR | S_IXUSR );

    /* write the text              */
    size_written = write( fd, buffer,
              sizeof( buffer ) );

    /* test for error              */
    if( size_written != sizeof( buffer ) ) {
        perror( "Error writing myfile.dat" );
        return EXIT_FAILURE;
    }

    /* close the file              */
    close( fd );

}

void ComputerSystem::checkViolation(Plane p1, Plane p2, int lookaheadValue) {
	// Check for potential future aircraft within 1000 unit z limit or 3000 unit x or y limit
	// Function takes two planes and a lookahead value (in seconds) and determines 
	// if seperation constraints will be violated within that lookahead window

	int zLimit = 1000;
	int xyLimit = 3000;

	Vec3 p1CurrentPos = p1.getCurrentPosition;
	Vec3 p2CurrentPos = p2.getCurrentPosition;
	Vec3 p1CurrentVel = p1.getCurrentVelocity;
	Vec3 p2CurrentVel = p2.getCurrentVelocity;

	Vec3 p1Projection = (p1CurrentPos.sum(p1CurrentVel.scalarMult(lookaheadValue)));
	Vec3 p2Projection = (p2CurrentPos.sum(p2CurrentVel.scalarMult(lookaheadValue)));

	// Take the projected position of the plane and add/sub the limits to get a 3D space around the plane that no other plane can occupy
	int x1Min = p1Projection.x - xyLimit;
	int x1Max = p1Projection.x + xyLimit;
	int y1Min = p1Projection.y - xyLimit;
	int y1Max = p1Projection.y + xyLimit;
	int z1Min = p1Projection.z - zLimit;
	int z2Min = p1Projection.z + zLimit;

	int x2Min = p2Projection.x - xyLimit;
	int x2Max = p2Projection.x + xyLimit;
	int y2Min = p2Projection.y - xyLimit;
	int y2Max = p2Projection.y + xyLimit;
	int z2Min = p2Projection.z - zLimit;
	int z2Min = p2Projection.z + zLimit;

	// Check if any values overlap, signalling a violation
	if ((x1Max >= x2Min && x2Max >= x1Min) && (y1Max >= y2Min && y2Max >= y1Min) && (z1Max >= z2Min && z2Max >= z1Min) {
		// Send message to operator console
		
		// Change speed of plane 1
	}

}

void ComputerSystem::checkAll(int lookaheadValue) {
	// Temp radar function name
	this->airspace = radar.scan();
		for (size_t i = 0; i < airspace.size(); i++) {
			for (size_t j = 0; j < airspace.size(); j++) {
				checkViolation(airspace[i], airspace[j], lookaheadValue);
			}
		}
}

void ComputerSystem::waitForOpCon(){
	// Temp operator channel ID name
	int coid = ConnectAttach(0, 0, operatorChid, _NTO_SIDE_CHANNEL, 0);

	// Data type for sending message to operator console = outgoingMsg;
	// Data type for receiving message from operator console = incomingMsg;


}


void ComputerSystem::sendToComm(int planeId, Vec3 newVelocity) {
	// Send velocity changes to communication system for violation avoidance
	int coid = ConnectAttach(0, 0, commChid, _NTO_SIDE_CHANNEL, 0);
	
}
