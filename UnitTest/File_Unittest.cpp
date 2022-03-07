#include "pch.h"
#include "../GCR Project/File.cpp"
#include "../GCR Project/Parser.h"
#include <time.h>

TEST(FileTest, FileSelfTest1) {
	time_t t1 = time(NULL);
	string output_file;
	char output_file_cstr[100];
	sprintf_s(output_file_cstr, "../GCR Project/output_test_%d.txt", (int)t1);
	output_file = string(output_file_cstr);

	File file = File();
	bool bOpen = file.OpenFile("../GCR Project/input_20_20.txt", output_file);

	ASSERT_EQ(bOpen, true);
}

TEST(FileTest, FileCallParseTest2) {
	Delay1Sec();
	time_t t1 = time(NULL);
	string output_file;
	char output_file_cstr[100];
	sprintf_s(output_file_cstr, "../GCR Project/output_test_%d.txt", (int)t1);
	output_file = string(output_file_cstr);

	File file = File();
	bool bOpen = file.OpenFile("../GCR Project/input_20_20.txt", output_file);
	
	ASSERT_EQ(bOpen, true);
	ASSERT_EQ(file.IsValidFiles(), true);

	string strLineForRead;
	string strLineForWrite;

	strLineForRead = file.ReadLine();
	EXPECT_EQ(strLineForRead, "ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");

	Parser parser = Parser();
	parser.parse(strLineForWrite, strLineForRead);
	EXPECT_EQ(strLineForWrite, "");

	file.WriteLine(strLineForWrite);
	file.CloseFile();

	ASSERT_EQ(file.IsValidFiles(), false);
}