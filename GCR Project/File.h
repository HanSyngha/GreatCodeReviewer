#pragma once

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <string>
using namespace std;

class File {
public:
	bool OpenFile(string inFileName, string outFileName);
	string ReadLine(void);
	void WriteLine(string strLine);
	void CloseFile(void);
	bool IsValidFiles(void);
	bool IsExistedFile(string& filename);

private:
	fstream inFile_;
	fstream outFile_;
	string inFileName_;
	string outFileName_;
};