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
		while (true) {
			strLineForRead = file.ReadLine();
			if (strLineForRead == "") break;
			strLineForWrite = parser.parse(strLineForRead);
			file.WriteLine(strLineForWrite);
		}
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

char testArray[100000][100];

TEST(IntegrationTest, ITScene2forSpeedCheck) {

	// GCR Project 구동부	
	string strLineForRead;
	string strLineForWrite;
	Parser parser = Parser();
	char name1[10] = "A"; char name2[10] = "B";
	int cl = 1; int phone1 = 0; int phone2 = 0;
	int birthday = 19700101; char certi[] = "PRO";
	for (int i = 0; i < 100000; i++) {
		sprintf(testArray[i], "ADD, , , ,%08d,%s %s,CL%d,010-%04d-%04d,%8d,%s",
			i, name1, name2, cl, phone1, phone2, birthday, certi
		);
		name1[2] = 0;
		name1[1] = name1[0];
		name1[0] = ((name1[0] - 'A' + 1) % ('Z' - 'A' + 1)) + 'A';
		name2[2] = 0;
		name2[1] = name2[0];
		name2[0] = ((name1[0] - 'A' + 1) % ('Z' - 'A' + 1)) + 'A';
		cl = ((cl) % 4) + 1;
		phone1 = (phone1 + 1);
		phone2 = (phone1 + 1);
	}

	time_t start_time = time(NULL);
	try {
		for (int i = 0; i < 100000; i++) {
			//strLineForRead = file.ReadLine();
			strLineForRead = testArray[i];
			if (strLineForRead == "") break;
			strLineForWrite = parser.parse(strLineForRead);
			//file.WriteLine(strLineForWrite);
		}
		strLineForRead = "SCH, , , ,cl,CL2";
		strLineForWrite = parser.parse(strLineForRead);
		cout << "result: " << strLineForWrite << endl;
		strLineForRead = "SCH,-p, , ,certi,PRO";
		strLineForWrite = parser.parse(strLineForRead);
		cout << "result: " << strLineForWrite << endl;
	}
	catch (const exception& e) {
		cout << "Error : " << e.what() << endl;
	}

	time_t end_time = time(NULL);
	cout << "Time Elapsed :" << difftime(end_time, start_time) << endl;
}