#include <iostream>
#include <string>
#include "File.h"
#include "Parser.h"
using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "Error : Invalid argument" << endl;
		return -1;
	}

	string input_filename = argv[1];
	string output_filename = argv[2];

	File file = File();
	string strLineForRead;
	string strLineForWrite;
	if (file.OpenFile(input_filename, output_filename) == false) {
		cout << "Error : File cannot open" << endl;
		return -1;
	}

	Parser parser = Parser();
	
	while (true) {
		strLineForRead = file.ReadLine();
		if (strLineForRead == "") break;
		strLineForWrite = parser.parse(strLineForRead);
		file.WriteLine(strLineForWrite);
	}

	return 0;
}
