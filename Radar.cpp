#include "Radar.h"
#include <vector>


PSR::PSR(){
    // constructor
};

std::vector<int> PSR::findAllPlanesInAirspace(std::vector<Plane*> planes) {

    //create a vector for planes in airspace
    std::vector<int> planesInAirspace = {} ;

    // create a for loop to check if planes
    for (i=0; i < planes.size(); i++){

        Vec3 position = planes[i] -> currentPlanePosition.currentPosition;

        // check if the plane has entered the Airspace, x, y & z

    if (position.x > 0
            || position.x < 100000
            || position.y > 0
            || position.y < 100000
            || position.z > 0
            || position.z < 25000) {

        int id = planes[i] -> getChid();
        planesInAirspace.push_back(id);
        }
    }

    return planesInAirspace;
};


SSR::SSR(){

    //constructor

};

std::vector<pair<int, PlaneInfo*>> SSR::interrogatePlanesInAirspace(std::vector<int>planes, int signal){

    // create a vector
    std::vector<int, PlaneInfo> planesInfo = {};

    //create a for loop in order that for each id, ask the plane for its info
    for (j=0; j < planes.size(); j++){

            //create a channel
            int chid = ChannelCreate(planes[j]);

            //create a message
            planeCommand cmd = { NULL, 1, NULL};

            //send the message to the plane
            MsgSend(planes[j], &cmd, sizeof(cmd), NULL, 0);

            //receive the message from the plane
            currentPlanePosition crPP;
            MsgReceive(chid, &crPP, sizeof(cmd), NULL);

            // add the plane id and the response to the vector
            PlaneInfo planeInfo = {crPP.currentPosition, crPP.currentVelocity};
            planesInfo.push_back(std::make_pair(planes[j], planeInfo));
    }

    return planesInfo;
};

void SSR::sendToComputerSystem(std::vector<pair<int, PlaneInfo*>> planes) {

    //create a for loop to send the info to the computer system
    for (const auto& data : planes)
    {
        MsgSend(data.first, &data, sizeof(data), NULL, 0);
    }
};
