/*
 * fileReader.cpp
 *
 *  Created on: Mar. 31, 2023
 *      Author: coen320
 */

#include "fileReader.h"
//#include "plane.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

fileReader::fileReader(){


}

fileReader::~fileReader(){


}

void fileReader::fileReadMe(string fileName) {



    std::string filename = "input.txt";
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return ;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    inputFile.close();
    return ;

	/*

	fileName = "input.txt";
    //ifstream input(fileName);
    ifstream input;
    input.open(fileName);


    if (!input.is_open()) {
        cout << "Error: Could not open file " << fileName << endl;
        return ;
    }
    stringstream ss;
    ss << input.rdbuf(); // Read the entire file into the stringstream
    input.close(); // Close the input file
    if (ss.str().empty()) {
        cout << "Error: File " << fileName << " is empty" << endl;
        return;
    }
    vector<string> tokens;
    string temp_str;

    while (getline(ss, temp_str, ',')) {
        tokens.push_back(temp_str);
        cout << "Hello World" << endl;
    }
    for (unsigned int i = 0; i < tokens.size(); i++) {
        cout << tokens[i] << endl;
        cout << "Hello World" << endl;
    }

*/




}

/*
void fileReader::fileReadMe(string fileName){
	ifstream input;
	input.open(fileName.c_str());
	stringstream ss;
	ss << input.rdbuf(); // Read the entire file into the stringstream
	input.close(); // Close the input file
	vector<string> tokens;
	string temp_str;

	while(getline(ss, temp_str, ',')){
		tokens.push_back(temp_str);
		cout << "Hello World" << endl;
	}
	for(unsigned int i=0; i<tokens.size(); i++){
		cout << tokens[i] << endl;
		cout << "Hello World" << endl;
	}

}
*/
