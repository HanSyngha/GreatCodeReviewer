#include "pch.h"
#include "../GCR Project/Employee.h"
#include "../GCR Project/EmployeeManager.h"
#include "../GCR Project/Parser.cpp"


TEST(ParserTest, ParserAdd) {
	Parser parser;
	string str;
	parser.parse(str, "ADD, , , ,15123099,BMU MPOSXU,CL3,010-3112-2609,19771211,ADV");
	EXPECT_EQ(str.compare(""), 0);
	EXPECT_TRUE(true);
}

TEST(ParserTest, ParserDELdefult) {
	Parser parser;
	string str;
	parser.parse(str, "ADD, , , ,18115040,BMU MPOSXU,CL3,010-3112-2609,19771211,ADV");
	parser.parse(str, "DEL, , , ,employeeNum,18115040");
	EXPECT_EQ(str, "DEL,1");
	EXPECT_TRUE(true);
}

TEST(ParserTest, ParserDELbyname) {
	Parser parser;
	string str;
	parser.parse(str, "ADD, , , ,08117441,BMU MPOSXU,CL3,010-2703-3153,20010215,ADV");
	parser.parse(str, "DEL,-p,-l, ,name,MPOSXU");
	EXPECT_EQ(str, "DEL,08117441,BMU MPOSXU,CL3,010-2703-3153,20010215,ADV");
	EXPECT_TRUE(true);
}

TEST(ParserTest, ParserSRHdefult) {
	Parser parser;
	string str;
	parser.parse(str, "ADD, , , ,15123099,BMU MPOSXU,CL3,010-3112-2609,19770901,ADV");
	parser.parse(str, "SCH,-p, , ,certi,ADV");
	EXPECT_EQ(str, "SCH,15123099,BMU MPOSXU,CL3,010-3112-2609,19770901,ADV");
	EXPECT_TRUE(true);
}

TEST(ParserTest, ParserSRHNone) {
	Parser parser;
	string str;
	parser.parse(str, "ADD, , , ,15123099,BMU MPOSXU,CL3,010-3112-2609,19770901,ADV");
	parser.parse(str, "SCH,-p,-d, ,birthday,10");
	EXPECT_EQ(str.compare("SCH,NONE"), 0);
	EXPECT_TRUE(true);
}

TEST(ParserTest, ParserMOD) {
	Parser parser;
	string str;
	parser.parse(str, "ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO");
	parser.parse(str, "MOD,-p, , ,name,FB NTAWR,birthday,20050520");
	EXPECT_EQ(str,"MOD,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO");
	EXPECT_TRUE(true);
}

