#include "pch.h"
#include "../GCR Project/Employee.h"
#include "../GCR Project/EmployeeManager.h"
#include "../GCR Project/Parser.cpp"


TEST(ParserTest, ParserAdd) {
	Parser parser;
	string str = parser.parse("ADD, , , ,15123099,BMU MPOSXU,CL3,010-3112-2609,19771211,ADV");
	EXPECT_EQ(str.compare(""), 0);
	EXPECT_TRUE(true);
}

TEST(ParserTest, ParserDELdefult) {
	Parser parser;
	parser.parse("ADD, , , ,18115040,BMU MPOSXU,CL3,010-3112-2609,19771211,ADV");
	EXPECT_EQ(parser.parse("DEL, , , ,employeeNum,18115040"), "DEL,1");
	EXPECT_TRUE(true);
}

TEST(ParserTest, ParserDELbyname) {
	Parser parser;
	parser.parse("ADD, , , ,08117441,BMU MPOSXU,CL3,010-2703-3153,20010215,ADV");
	EXPECT_EQ(parser.parse("DEL,-p,-l, ,name,MPOSXU"), "DEL,08117441,BMU MPOSXU,CL3,010-2703-3153,20010215,ADV");
	EXPECT_TRUE(true);
}

TEST(ParserTest, ParserSRHdefult) {
	Parser parser;
	parser.parse("ADD, , , ,15123099,BMU MPOSXU,CL3,010-3112-2609,19770901,ADV");
	EXPECT_EQ(parser.parse("SCH,-p, , ,certi,ADV"), "SCH,15123099,BMU MPOSXU,CL3,010-3112-2609,19770901,ADV");
	EXPECT_TRUE(true);
}

TEST(ParserTest, ParserSRHNone) {
	Parser parser;
	parser.parse("ADD, , , ,15123099,BMU MPOSXU,CL3,010-3112-2609,19770901,ADV");
	string str = parser.parse("SCH,-p,-d, ,birthday,10");
	EXPECT_EQ(str.compare("SCH,NONE"), 0);
	EXPECT_TRUE(true);
}

TEST(ParserTest, ParserMOD) {
	Parser parser;
	parser.parse("ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO");
	EXPECT_EQ(parser.parse("MOD,-p, , ,name,FB NTAWR,birthday,20050520"),"MOD,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO");
	EXPECT_TRUE(true);
}

