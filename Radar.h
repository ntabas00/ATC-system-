#ifndef RADAR_H_
#define RADAR_H_
#include "plane.h"

// both radars (PSR & SSR) in one file called RADAR

class PSR{
    // constructor & destructor
    PSR();
    ~PSR();

    //methods
    std::vector<int> findAllPlanesInAirspace(std::vector<Plane*> planes);
};

class SSR{
    // constructor & destructor
    SSR();
    ~SSR();

    //methods
    std::vector<PlaneInfo*> interrogatePlanesInAirspace (std::vector<int>planes, int signal);
    void sendToComputerSystem(std::vector<PlaneInfo*> planes);

};

//Create an object of plane information, combining 4 variables into 1
struct PlaneInfo{
    Vec3 planeSpeed;
    Vec3 planePosition;
};



#endif /* RADAR_H_ */
