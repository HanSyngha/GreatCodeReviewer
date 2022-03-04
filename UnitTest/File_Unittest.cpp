#include "pch.h"
#include "../GCR Project/File.cpp"
#include "../GCR Project/Parser.h"

TEST(FileTest, FileSelfTest1) {
	File file = File();
	bool bOpen = file.OpenFile("../GCR Project/input_20_20.txt", "../GCR Project/output_test.txt");

	if (bOpen) cout << "Opened" << endl;
	else cout << "Error" << endl;

	EXPECT_EQ(bOpen, 1);
	EXPECT_TRUE(true);
}

TEST(FileTest, FileCallParseTest) {
	File file = File();
	bool bOpen = file.OpenFile("../GCR Project/input_20_20.txt", "../GCR Project/output_test.txt");
	
	EXPECT_EQ(bOpen, true);
	EXPECT_EQ(file.IsValidFiles(), true);

	//Parser parser(parser_);
	//EXPECT_CALL(parser_, parse()).Times(AtLeast(1));
	//Parser parser = Parser();
	//do {
	//	strLineForRead = file.ReadLine();
	//	strLineForWrite = parser.parse(strLineForRead);
	//} while (strLineForRead != "");
	string strLineForRead;
	string strLineForWrite;

	strLineForRead = file.ReadLine();
	EXPECT_EQ(strLineForRead, "ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");

	Parser parser = Parser();
	strLineForWrite = parser.parse(strLineForRead);
	EXPECT_EQ(strLineForWrite, "");

	file.WriteLine(strLineForWrite);
	file.CloseFile();

	EXPECT_EQ(file.IsValidFiles(), false);
}