/*
 * comsys.cpp
 *
 *  Created on: Mar. 24, 2023
 *      Author:nabila coen320
 */

#include "comsys.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/dispatch.h>
//#include "cTimer.h"

using namespace std;

/* This is the name that will be used by the server to create a channel and used by
 * the client to connect to the appropriated channel */
#define ATTACH_POINT "my_channel"

/* We specify the header as being at least a pulse */
/* All of your messages should start with this header */
/* This struct contains a type/subtype field as the first 4 bytes.
 * The type and subtype field can be used to identify the message that is being received.
/ * This allows you to identify data which isn't destined for your server. */
/* Our real data comes after the header */
comsys::comsys() {
	// TODO Auto-generated constructor stub

}

comsys::~comsys() {
	// TODO Auto-generated destructor stub
}

Vec3 comsys::waitForCommunication(){
     int rcvid;
     planeCommand cmd;
     if(chid = ChannelCreate(0)){
    	 std::cout<< 'Error channel not created' <<std::endl;
     }
     while(true){
    	 rcvid = MsgReceive(chid,&cmd,sizeof(cmd),NULL);

    	 if (rcvid != 0 ){
    		 if (cmd.command == 2){
    			 newVelocity = cmd.newVelocity;
    		 }
    	 }
     }
     return newVelocity;
}
void comsys::sendToPlane(Plane R, Vec3 newVelocity){
	int chid = R.chid;
	int coid;
	int sndid;

	// Check to see if channel is properly connected
	if(ConnectAttach(0, 0, chid, 0, 0) == -1){
		std::cout<< 'Error channel not connected' << std::endl;
		return;
	}
	else{
		sndid = MsgSend(coid, *newVelocity, newVelocity.size(), NULL, 0);
	}
}




