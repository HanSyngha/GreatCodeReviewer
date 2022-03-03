#pragma once

#include <string>
using namespace std;

class File {
public:
	File() :
		input_file_(nullptr),
		output_file_(nullptr),
		input_filename_(""),
		output_filename_("")
	{
	}

	bool OpenFile(string input_filename, string output_filename);
	string ReadLine(void);
	void WriteLine(string input_string);
	void CloseFile();

private:
	FILE* input_file_;
	FILE* output_file_;
	string input_filename_;
	string output_filename_;
};