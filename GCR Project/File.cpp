
#include "File.h"

bool File::OpenFile(string input_filename, string output_filename) {
	input_filename_ = input_filename;
	output_filename_ = output_filename;

	return true;
}

string File::ReadLine(void) {
	return "";
}

void File::WriteLine(string input_string) {
}

void File::CloseFile() {
}