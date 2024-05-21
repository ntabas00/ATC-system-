/*
 * fileReader.h
 *
 *  Created on: Mar. 31, 2023
 *      Author: coen320
 */

//#ifndef FILEREADER_H_
//#define FILEREADER_H_
#include <string>
#include <fstream>

//#include "plane.h"
using namespace std;
class fileReader {
	std::string fileName;
	//std::vector<plane> input;
public:
	fileReader();
	~fileReader();

	void fileReadMe(string fileName);
	//std::vector<plane> getSchedule(long time);
};
