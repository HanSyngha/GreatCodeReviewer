
#include "File.h"

bool File::OpenFile(string inFileName, string outFileName) {
	inFileName_ = inFileName;
	outFileName_ = outFileName;

	inFile_.open(inFileName, ios_base::in);
	outFile_.open(outFileName, ios_base::out);

	if (IsValidFiles() == false) return false;

	//cout << "OpenFile() OK" << endl;
	return true;
}

string File::ReadLine(void) {
	string strLine;
	if (IsValidFiles() == false) return strLine;
	if (inFile_.eof()) return strLine;

	//cout << "ReadLine() OK" << endl;
	getline(inFile_, strLine);
	
	return strLine;
}

void File::WriteLine(string strLine) {
	outFile_ << strLine << endl;
}

void File::CloseFile(void) {
	inFile_.close();
	outFile_.close();
}

bool File::IsValidFiles(void) {
	return inFile_.is_open() && outFile_.is_open();
}