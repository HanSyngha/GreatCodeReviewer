#include "pch.h"
#include <vector>
#include "../GCR Project/EmployeeManager.h"
#include "../GCR Project/Employee.h"

using namespace std;

void initEmployeeData(EmployeeManager& em) {
	map<int, Employee> emptyResult;
	Option option = { COMMAND::ADD, OPTION1::NONE, OPTION2::NONE, { "85125741", "FBAH RTIJ", "CL1", "010-8900-1478", "19780228", "ADV" }, COLUMN::NONE, string(), COLUMN::NONE, string()};	
	em.execute(&emptyResult, option);

	option.employee = { "08117441", "BMU MPOSXU", "CL3", "010-2703-3153", "20010215", "ADV" };
	em.execute(&emptyResult, option);

	option.employee = { "10127115", "KBU MHU", "CL3", "010-3284-4054", "19660814", "ADV" };
	em.execute(&emptyResult, option);

	option.employee = { "12117017", "LFIS JJIVL", "CL1", "010-7914-4067", "20120812", "PRO" };
	em.execute(&emptyResult, option);

	option.employee = { "11125777", "TKOQKIS HC", "CL1", "010-6734-2289", "19991001", "PRO" };
	em.execute(&emptyResult, option);

	option.employee = { "11109136", "QKAHCEX LTODDO", "CL4", "010-2627-8566", "19640130", "PRO" };
	em.execute(&emptyResult, option);

	option.employee = { "05101762", "VCUHLE HMU", "CL4", "010-3988-9289", "20030819", "PRO" };
	em.execute(&emptyResult, option);
}

TEST(EmployeeManagerTest2, SearchNoOptionTest) {
	EmployeeManager em;
	map<int, Employee> results;

	initEmployeeData(em);

	Option option = { COMMAND::SCH, OPTION1::NONE, OPTION2::NONE, Employee(), COLUMN::EMPLOYEENUM, "11125777", COLUMN::NONE, string() };

	//EmployeeNum search
	results = em.search(option);
	EXPECT_EQ(1, results.size());
	results.clear();

	//CL search
	option.searchColumn = COLUMN::CL;
	option.searchData = "CL4";
	results = em.search(option);
	EXPECT_EQ(2, results.size());
	results.clear();

	//Add CL4
	Option option2 = { COMMAND::ADD, OPTION1::NONE, OPTION2::NONE, { "20091154", "LFIS AEDLW", "CL4", "010-6681-1104", "20081113", "ADV" }, COLUMN::NONE, string(), COLUMN::NONE, string() };
	em.execute(&results, option2);
	results = em.search(option);
	EXPECT_EQ(3, results.size());
	results.clear();

	//Certi search
	option.searchColumn = COLUMN::CERTI;
	option.searchData = "PRO";
	results = em.search(option);
	EXPECT_EQ(4, results.size());
	results.clear();
}

TEST(EmployeeManagerTest2, SearchFirstNameTest) {
	EmployeeManager em;
	map<int, Employee> results;

	initEmployeeData(em);

	Option option = { COMMAND::SCH, OPTION1::NONE, OPTION2::FIRST_NAME, Employee(), COLUMN::NAME, "LFIS", COLUMN::NONE, string() };
	results = em.search(option);
	EXPECT_EQ(1, results.size());
	results.clear();

	//ADD 1 more first name with LFIS
	Option option2 = { COMMAND::ADD, OPTION1::NONE, OPTION2::NONE, { "20091154", "LFIS AEDLW", "CL2", "010-6681-1104", "20081113", "ADV" }, COLUMN::NONE, string(), COLUMN::NONE, string() };
	em.execute(&results, option2);

	results = em.search(option);
	EXPECT_EQ(2, results.size());
	results.clear();

	//Modify
	Option option3 = { COMMAND::MOD, OPTION1::NONE, OPTION2::FIRST_NAME, Employee(), COLUMN::NAME, "LFIS", COLUMN::CL, "CL3" };
	results = em.execute(&em.search(option3), option3);
	EXPECT_EQ(2, results.size());
	results.clear();

	option.searchData = "TKOQKIS";
	results = em.search(option);
	EXPECT_EQ(1, results.size());
	results.clear();

	//Delete
	Option option4 = { COMMAND::DEL, OPTION1::NONE, OPTION2::FIRST_NAME, Employee(), COLUMN::NAME, "TKOQKIS", COLUMN::NONE, string() };
	em.execute(&em.search(option4), option4);
	results = em.search(option);
	EXPECT_EQ(0, results.size());
	results.clear();
}

TEST(EmployeeManagerTest2, SearchLastNameTest) {
	EmployeeManager em;
	map<int, Employee> results;

	initEmployeeData(em);

	Option option = { COMMAND::SCH, OPTION1::NONE, OPTION2::LAST_NAME, Employee(), COLUMN::NAME, "MPOSXU", COLUMN::NONE, string() };
	results = em.search(option);
	EXPECT_EQ(1, results.size());
	results.clear();

	//Add
	Option option2 = { COMMAND::ADD, OPTION1::NONE, OPTION2::NONE, { "20091154", "QKAHCEX MPOSXU", "CL4", "010-1978-6651", "20100111", "PRO" }, COLUMN::NONE, string(), COLUMN::NONE, string() };
	em.execute(&results, option2);

	results = em.search(option);
	EXPECT_EQ(2, results.size());
	results.clear();

	//Modify
	Option option3 = { COMMAND::MOD, OPTION1::NONE, OPTION2::LAST_NAME, Employee(), COLUMN::NAME, "MPOSXU", COLUMN::CL, "CL4" };
	results = em.execute(&em.search(option3), option3);

	results = em.search(option);
	EXPECT_EQ(2, results.size());
	results.clear();

	option.searchData = "RTIJ";
	results = em.search(option);
	EXPECT_EQ(1, results.size());
	results.clear();

	//Delete
	Option option4 = { COMMAND::DEL, OPTION1::NONE, OPTION2::LAST_NAME, Employee(), COLUMN::NAME, "RTIJ", COLUMN::NONE, string() };
	em.execute(&em.search(option4), option4);

	results = em.search(option);
	EXPECT_EQ(0, results.size());
	results.clear();
}

TEST(EmployeeManagerTest2, SearchPhoneMiddleNumberTest) {
	EmployeeManager em;
	map<int, Employee> results;

	initEmployeeData(em);

	Option option = { COMMAND::SCH, OPTION1::NONE, OPTION2::MID_NUMBER, Employee(), COLUMN::PHONENUM, "7914", COLUMN::NONE, string() };
	results = em.search(option);
	EXPECT_EQ(1, results.size());
	results.clear();

	//Add
	Option option2 = { COMMAND::ADD, OPTION1::NONE, OPTION2::NONE, { "20091154", "LFIS AEDLW", "CL2", "010-7914-2808", "20110925", "PRO" }, COLUMN::NONE, string(), COLUMN::NONE, string() };
	em.execute(&results, option2);

	results = em.search(option);
	EXPECT_EQ(2, results.size());
	results.clear();

	//Modify
	Option option3 = { COMMAND::MOD, OPTION1::NONE, OPTION2::MID_NUMBER, Employee(), COLUMN::PHONENUM, "7914", COLUMN::CERTI, "ADV" };
	results = em.execute(&em.search(option3), option3);

	results = em.search(option);
	EXPECT_EQ(2, results.size());
	results.clear();

	//Delete
	Option option4 = { COMMAND::DEL, OPTION1::NONE, OPTION2::MID_NUMBER, Employee(), COLUMN::PHONENUM, "7914", COLUMN::NONE, string() };
	em.execute(&em.search(option4), option4);

	results = em.search(option);
	EXPECT_EQ(0, results.size());
	results.clear();
}

TEST(EmployeeManagerTest2, SearchPhoneLastNumberTest) {
	EmployeeManager em;
	map<int, Employee> results;

	initEmployeeData(em);

	Option option = { COMMAND::SCH, OPTION1::NONE, OPTION2::LAST_NUMBER, Employee(), COLUMN::PHONENUM, "8566", COLUMN::NONE, string() };
	results = em.search(option);
	EXPECT_EQ(1, results.size());
	results.clear();

	//Add
	Option option2 = { COMMAND::ADD, OPTION1::NONE, OPTION2::NONE, { "20091154", "LFIS AEDLW", "CL2", "010-7914-8566", "20110925", "PRO" }, COLUMN::NONE, string(), COLUMN::NONE, string() };
	em.execute(&results, option2);

	results = em.search(option);
	EXPECT_EQ(2, results.size());
	results.clear();

	//Modify
	Option option3 = { COMMAND::MOD, OPTION1::NONE, OPTION2::LAST_NUMBER, Employee(), COLUMN::PHONENUM, "8566", COLUMN::CERTI, "ADV" };
	results = em.execute(&em.search(option3), option3);

	results = em.search(option);
	EXPECT_EQ(2, results.size());
	results.clear();

	//Delete
	Option option4 = { COMMAND::DEL, OPTION1::NONE, OPTION2::LAST_NUMBER, Employee(), COLUMN::PHONENUM, "8566", COLUMN::NONE, string() };
	em.execute(&em.search(option4), option4);

	results = em.search(option);
	EXPECT_EQ(0, results.size());
	results.clear();
}

TEST(EmployeeManagerTest2, SearchBirthYearTest) {
	EmployeeManager em;
	map<int, Employee> results;

	initEmployeeData(em);

	Option option = { COMMAND::SCH, OPTION1::NONE, OPTION2::YEAR, Employee(), COLUMN::BIRTHDAY, "2012", COLUMN::NONE, string() };
	results = em.search(option);
	EXPECT_EQ(1, results.size());
	results.clear();

	//Add
	Option option2 = { COMMAND::ADD, OPTION1::NONE, OPTION2::NONE, { "20091154", "LFIS AEDLW", "CL2", "010-7914-8566", "20120925", "PRO" }, COLUMN::NONE, string(), COLUMN::NONE, string() };
	em.execute(&results, option2);

	results = em.search(option);
	EXPECT_EQ(2, results.size());
	results.clear();

	//Modify
	Option option3 = { COMMAND::MOD, OPTION1::NONE, OPTION2::YEAR, Employee(), COLUMN::BIRTHDAY, "2012", COLUMN::NAME, "ERGY DFEH" };
	results = em.execute(&em.search(option3), option3);

	results = em.search(option);
	EXPECT_EQ(2, results.size());
	results.clear();

	//Delete
	Option option4 = { COMMAND::DEL, OPTION1::NONE, OPTION2::YEAR, Employee(), COLUMN::BIRTHDAY, "2012", COLUMN::NONE, string() };
	em.execute(&em.search(option4), option4);

	results = em.search(option);
	EXPECT_EQ(0, results.size());
	results.clear();
}

TEST(EmployeeManagerTest2, SearchBirthMonthTest) {
	EmployeeManager em;
	map<int, Employee> results;

	initEmployeeData(em);

	Option option = { COMMAND::SCH, OPTION1::NONE, OPTION2::MONTH, Employee(), COLUMN::BIRTHDAY, "02", COLUMN::NONE, string() };
	results = em.search(option);
	EXPECT_EQ(2, results.size());
	results.clear();

	//Add
	Option option2 = { COMMAND::ADD, OPTION1::NONE, OPTION2::NONE, { "20091154", "LFIS AEDLW", "CL2", "010-7914-8566", "20120225", "PRO" }, COLUMN::NONE, string(), COLUMN::NONE, string() };
	em.execute(&results, option2);

	results = em.search(option);
	EXPECT_EQ(3, results.size());
	results.clear();

	//Modify
	Option option3 = { COMMAND::MOD, OPTION1::NONE, OPTION2::MONTH, Employee(), COLUMN::BIRTHDAY, "02", COLUMN::NAME, "QWRY DHUJ" };
	results = em.execute(&em.search(option3), option3);

	results = em.search(option);
	EXPECT_EQ(3, results.size());
	results.clear();

	option.searchData = "08";
	results = em.search(option);
	EXPECT_EQ(3, results.size());
	results.clear();

	//Delete
	Option option4 = { COMMAND::DEL, OPTION1::NONE, OPTION2::MONTH, Employee(), COLUMN::BIRTHDAY, "08", COLUMN::NONE, string() };
	em.execute(&em.search(option4), option4);

	results = em.search(option);
	EXPECT_EQ(0, results.size());
	results.clear();
}

TEST(EmployeeManagerTest2, SearchBirthDayTest) {
	EmployeeManager em;
	map<int, Employee> results;

	initEmployeeData(em);

	Option option = { COMMAND::SCH, OPTION1::NONE, OPTION2::DAY, Employee(), COLUMN::BIRTHDAY, "15", COLUMN::NONE, string() };
	results = em.search(option);
	EXPECT_EQ(1, results.size());
	results.clear();

	//Add
	Option option2 = { COMMAND::ADD, OPTION1::NONE, OPTION2::NONE, { "20091154", "LFIS AEDLW", "CL2", "010-7914-8566", "20120215", "PRO" }, COLUMN::NONE, string(), COLUMN::NONE, string() };
	em.execute(&results, option2);

	results = em.search(option);
	EXPECT_EQ(2, results.size());
	results.clear();

	//Modify
	Option option3 = { COMMAND::MOD, OPTION1::NONE, OPTION2::DAY, Employee(), COLUMN::BIRTHDAY, "15", COLUMN::CL, "CL2" };
	results = em.execute(&em.search(option3), option3);

	results = em.search(option);
	EXPECT_EQ(2, results.size());
	results.clear();

	option.searchData = "12";
	results = em.search(option);
	EXPECT_EQ(1, results.size());
	results.clear();

	//Delete
	Option option4 = { COMMAND::DEL, OPTION1::NONE, OPTION2::DAY, Employee(), COLUMN::BIRTHDAY, "12", COLUMN::NONE, string() };
	em.execute(&em.search(option4), option4);

	results = em.search(option);
	EXPECT_EQ(0, results.size());
	results.clear();
}

TEST(EmployeeManagerTest2, DeleteNoOptionTest) {
	EmployeeManager em;
	map<int, Employee> searchResults;
	map<int, Employee> deleteResults;

	initEmployeeData(em);

	//EmployeeNum delete
	Option option = { COMMAND::SCH, OPTION1::NONE, OPTION2::NONE, Employee(), COLUMN::EMPLOYEENUM, "10127115", COLUMN::NONE, string() };
	searchResults = em.search(option);
	option.cmd = COMMAND::DEL;
	deleteResults = em.execute(&searchResults, option);
	EXPECT_EQ(deleteResults.size(), searchResults.size());
	searchResults.clear();
	deleteResults.clear();

	//CL delete
	option.cmd = COMMAND::SCH;
	option.searchColumn = COLUMN::CL;
	option.searchData = "CL3";
	searchResults = em.search(option);
	option.cmd = COMMAND::DEL;
	deleteResults = em.execute(&searchResults, option);
	EXPECT_EQ(deleteResults.size(), searchResults.size());
	searchResults.clear();
	deleteResults.clear();

	//Certi delete
	option.cmd = COMMAND::SCH;
	option.searchColumn = COLUMN::CERTI;
	option.searchData = "PRO";
	searchResults = em.search(option);
	option.cmd = COMMAND::DEL;
	deleteResults = em.execute(&searchResults, option);
	EXPECT_EQ(deleteResults.size(), searchResults.size());
	searchResults.clear();
	deleteResults.clear();
}

TEST(EmployeeManagerTest2, DeleteFirstNameTest) {
	EmployeeManager em;
	map<int, Employee> searchResults;
	map<int, Employee> deleteResults;

	initEmployeeData(em);

	Option option = { COMMAND::SCH, OPTION1::NONE, OPTION2::FIRST_NAME, Employee(), COLUMN::NAME, "LFIS", COLUMN::NONE, string() };
	searchResults = em.search(option);
	option.cmd = COMMAND::DEL;
	deleteResults = em.execute(&searchResults, option);
	EXPECT_EQ(deleteResults.size(), searchResults.size());
	searchResults.clear();
	deleteResults.clear();	
}

TEST(EmployeeManagerTest2, DeleteLastNameTest) {
	EmployeeManager em;
	map<int, Employee> searchResults;
	map<int, Employee> deleteResults;

	initEmployeeData(em);

	Option option = { COMMAND::SCH, OPTION1::NONE, OPTION2::LAST_NAME, Employee(), COLUMN::NAME, "LTODDO", COLUMN::NONE, string() };
	searchResults = em.search(option);
	option.cmd = COMMAND::DEL;
	deleteResults = em.execute(&searchResults, option);
	EXPECT_EQ(deleteResults.size(), searchResults.size());
	searchResults.clear();
	deleteResults.clear();
}

TEST(EmployeeManagerTest2, DeletePhoneMidNumberTest) {
	EmployeeManager em;
	map<int, Employee> searchResults;
	map<int, Employee> deleteResults;

	initEmployeeData(em);

	Option option = { COMMAND::SCH, OPTION1::NONE, OPTION2::MID_NUMBER, Employee(), COLUMN::PHONENUM, "7914", COLUMN::NONE, string() };
	searchResults = em.search(option);
	option.cmd = COMMAND::DEL;
	deleteResults = em.execute(&searchResults, option);
	EXPECT_EQ(deleteResults.size(), searchResults.size());
	EXPECT_EQ(deleteResults.size(), searchResults.size());
	searchResults.clear();
	deleteResults.clear();
}

TEST(EmployeeManagerTest2, DeletePhoneLastNumberTest) {
	EmployeeManager em;
	map<int, Employee> searchResults;
	map<int, Employee> deleteResults;

	initEmployeeData(em);

	Option option = { COMMAND::SCH, OPTION1::NONE, OPTION2::LAST_NUMBER, Employee(), COLUMN::PHONENUM, "4054", COLUMN::NONE, string() };
	searchResults = em.search(option);
	option.cmd = COMMAND::DEL;
	deleteResults = em.execute(&searchResults, option);
	EXPECT_EQ(deleteResults.size(), searchResults.size());
	EXPECT_EQ(deleteResults.size(), searchResults.size());
	searchResults.clear();
	deleteResults.clear();
}

TEST(EmployeeManagerTest2, DeleteBirthYearTest) {
	EmployeeManager em;
	map<int, Employee> searchResults;
	map<int, Employee> deleteResults;

	initEmployeeData(em);

	Option option = { COMMAND::SCH, OPTION1::NONE, OPTION2::YEAR, Employee(), COLUMN::BIRTHDAY, "1966", COLUMN::NONE, string() };
	searchResults = em.search(option);
	option.cmd = COMMAND::DEL;
	deleteResults = em.execute(&searchResults, option);
	EXPECT_EQ(deleteResults.size(), searchResults.size());
	EXPECT_EQ(deleteResults.size(), searchResults.size());
	searchResults.clear();
	deleteResults.clear();
}

TEST(EmployeeManagerTest2, DeleteBirthMonthTest) {
	EmployeeManager em;
	map<int, Employee> searchResults;
	map<int, Employee> deleteResults;

	initEmployeeData(em);

	Option option = { COMMAND::SCH, OPTION1::NONE, OPTION2::MONTH, Employee(), COLUMN::BIRTHDAY, "02", COLUMN::NONE, string() };
	searchResults = em.search(option);
	option.cmd = COMMAND::DEL;
	deleteResults = em.execute(&searchResults, option);
	EXPECT_EQ(deleteResults.size(), searchResults.size());
	EXPECT_EQ(deleteResults.size(), searchResults.size());
	searchResults.clear();
	deleteResults.clear();
}

TEST(EmployeeManagerTest2, DeleteBirthDayTest) {
	EmployeeManager em;
	map<int, Employee> searchResults;
	map<int, Employee> deleteResults;

	initEmployeeData(em);

	Option option = { COMMAND::SCH, OPTION1::NONE, OPTION2::DAY, Employee(), COLUMN::BIRTHDAY, "30", COLUMN::NONE, string() };
	searchResults = em.search(option);
	option.cmd = COMMAND::DEL;
	deleteResults = em.execute(&searchResults, option);
	EXPECT_EQ(deleteResults.size(), searchResults.size());
	EXPECT_EQ(deleteResults.size(), searchResults.size());
	searchResults.clear();
	deleteResults.clear();
}