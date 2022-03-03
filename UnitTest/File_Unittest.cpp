#include "pch.h"
#include "../GCR Project/File.cpp"

TEST(FileTest, FileTest1) {
	string input_filename = "input.txt";
	string output_filename = "output.txt";
	File file = File();

	bool bOpen = file.OpenFile(input_filename, output_filename);
	EXPECT_EQ(bOpen, 1);
	EXPECT_TRUE(true);
}