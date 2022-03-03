#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class File {
public:
	bool OpenFile(string inFileName, string outFileName);
	string ReadLine(void);
	void WriteLine(string strLine);
	void CloseFile(void);
	bool IsValidFiles(void);

private:
	fstream inFile_;
	fstream outFile_;
	string inFileName_;
	string outFileName_;
};