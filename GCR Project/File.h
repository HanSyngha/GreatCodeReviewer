#pragma once

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <string>

class File {
public:
	bool OpenFile(const std::string& inFileName, const std::string& outFileName);
	std::string ReadLine(void);
	void WriteLine(const std::string& strLine);
	void CloseFile(void);
	bool IsValidFiles(void);
	bool IsExistedFile(const std::string& filename);

private:
	std::fstream inFile_;
	std::fstream outFile_;
	std::string inFileName_;
	std::string outFileName_;
};