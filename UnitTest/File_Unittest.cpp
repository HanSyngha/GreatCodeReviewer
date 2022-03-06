#include "pch.h"
#include "../GCR Project/File.cpp"
#include "../GCR Project/Parser.h"

TEST(FileTest, FileSelfTest1) {
	File file = File();
	bool bOpen = file.OpenFile("../GCR Project/input_20_20.txt", "../GCR Project/output_test1.txt");

	ASSERT_EQ(bOpen, true);
}

TEST(FileTest, FileCallParseTest2) {
	File file = File();
	bool bOpen = file.OpenFile("../GCR Project/input_20_20.txt", "../GCR Project/output_test2.txt");
	
	ASSERT_EQ(bOpen, true);
	ASSERT_EQ(file.IsValidFiles(), true);

	string strLineForRead;
	string strLineForWrite;

	strLineForRead = file.ReadLine();
	EXPECT_EQ(strLineForRead, "ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");

	Parser parser = Parser();
	strLineForWrite = parser.parse(strLineForRead);
	EXPECT_EQ(strLineForWrite, "");

	file.WriteLine(strLineForWrite);
	file.CloseFile();

	ASSERT_EQ(file.IsValidFiles(), false);
}