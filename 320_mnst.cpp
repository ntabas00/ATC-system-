#include <iostream>
#include "fileReader.h"
using namespace std;

int main() {

	fileReader reader;
	reader.fileReadMe("input.txt");
	cout << "Hello World!!!" << endl; // prints Hello World!!!


	return 0;
}
