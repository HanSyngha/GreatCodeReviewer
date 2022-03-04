#include "pch.h"
#include "exception"
#include "../GCR Project/File.h"
#include "../GCR Project/Parser.h"

TEST(IntegrationTest, ITScene1) {
	string input_file = "../GCR Project/input_20_20.txt";
	string output_file = "../GCR Project/output_test.txt";
	string compare_file = "../GCR Project/output_20_20.txt";

	// GCR Project 구동부
	File file = File();

	bool bOpen = file.OpenFile(input_file, output_file);
	EXPECT_EQ(bOpen, true);

	string strLineForRead;
	string strLineForWrite;
	Parser parser = Parser();

	try {
		do {
			strLineForRead = file.ReadLine();
			strLineForWrite = parser.parse(strLineForRead);
			file.WriteLine(strLineForWrite);
		} while (strLineForRead != "");
	}
	catch (const exception& e) {
		cout << "Error : " << e.what() << endl;
	}

	// 구동후 데이터 비교
	fstream resultFile(output_file, ios_base::in);
	fstream correctFile(compare_file, ios_base::in);
	string correctStr;
	string resultStr;
	do {
		getline(resultFile, resultStr);
		getline(correctFile, correctStr);
		EXPECT_EQ(resultStr, correctStr);
	} while (resultStr != "" || correctStr != "");
	resultFile.close();
	correctFile.close();
	
	EXPECT_TRUE(true);
}
