#include "pch.h"
#include "../GCR Project/EmployeeManager.h"
#include "../GCR Project/EmployeeManager.cpp"

using namespace std;

void initEmployManager(EmployeeManager& employeeManager) {
	map<int, Employee> emptyResult;
	Option option = { COMMAND::ADD, OPTION1::NONE, OPTION2::NONE, { "85125741", "FBAH RTIJ", "CL1", "010-8900-1478", "19780228", "ADV" }, COLUMN::NONE, string(), COLUMN::NONE, string() };
	employeeManager.execute(&emptyResult, option);

	option.employee = { "13009524", "Hyeonmin Seo", "CL3", "010-8463-5536", "19870319", "PRO" };
	employeeManager.execute(&emptyResult, option);

	option.employee = { "13009500", "Hyeonmia Seo", "CL1", "010-8463-5516", "19881129", "ADV" };
	employeeManager.execute(&emptyResult, option);

	option.employee = { "13009521", "Hyeonmib Eeo", "CL2", "010-8463-5526", "19890130", "EXP" };
	employeeManager.execute(&emptyResult, option);

	option.employee = { "13009522", "Hyeonmic Leo", "CL3", "010-8443-5536", "19810719", "PRO" };
	employeeManager.execute(&emptyResult, option);

	option.employee = { "13009523", "Hyeonmid Aeo", "CL4", "010-8453-5536", "19820911", "ADV" };
	employeeManager.execute(&emptyResult, option);
}

TEST(EmployeeManagerHMTest, AddTest) {
	EmployeeManager employeeManager;
	map<int, Employee> results;

	Option option = { COMMAND::ADD, OPTION1::NONE, OPTION2::NONE, { "13009524", "Hyeonmin Seo", "CL3", "010-8463-5536", "19870319", "PRO" }, COLUMN::NONE, string(), COLUMN::NONE, string() };
	employeeManager.execute(&results, option);

	Option option2 = { COMMAND::SCH, OPTION1::NONE, OPTION2::NONE, Employee(), COLUMN::EMPLOYEENUM, "13009524", COLUMN::NONE, string() };
	results = employeeManager.search(option2);
	EXPECT_EQ(1, results.size());
	results.clear();
	
	option.employee = { "13009521", "Hyeonmib Eeo", "CL2", "010-8463-5526", "19890130", "EXP" };
	employeeManager.execute(&results, option);
	
	option2.searchData = "13009521";
	results = employeeManager.search(option2);
	EXPECT_EQ(1, results.size());
	results.clear();	
}

TEST(EmployeeManagerHMTest, ModifyByFirstNameTest) 
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);
	
	std::map<int, Employee> result;

	Option option1 = { COMMAND::MOD, OPTION1::NONE, OPTION2::FIRST_NAME, Employee(), COLUMN::NAME, "Hyeonmin", COLUMN::PHONENUM, "010-8463-5516" };
	result = employeeManager.execute(&employeeManager.search(option1), option1);
	result.clear();
	
	Option option2 = { COMMAND::SCH, OPTION1::NONE, OPTION2::LAST_NUMBER, Employee(), COLUMN::PHONENUM, "5516", COLUMN::NONE, string() };
	result = employeeManager.search(option2);
	EXPECT_EQ(2, result.size());
}

TEST(EmployeeManagerHMTest, ModifyByLastNameTest) 
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);

	std::map<int, Employee> result;

	Option option1 = { COMMAND::MOD, OPTION1::NONE, OPTION2::LAST_NAME, Employee(), COLUMN::NAME, "Seo", COLUMN::CL, "CL4" };
	result = employeeManager.execute(&employeeManager.search(option1), option1);
	result.clear();
	
	Option option2 = { COMMAND::SCH, OPTION1::NONE, OPTION2::NONE, Employee(), COLUMN::CL, "CL4", COLUMN::NONE, string() };
	result = employeeManager.search(option2);
	EXPECT_EQ(3, result.size());
}

TEST(EmployeeManagerHMTest, ModifyByPhoneMidNumberTest) 
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);

	std::map<int, Employee> result;

	Option option1 = { COMMAND::MOD, OPTION1::NONE, OPTION2::MID_NUMBER, Employee(), COLUMN::PHONENUM, "8443", COLUMN::BIRTHDAY, "19691130" };
	result = employeeManager.execute(&employeeManager.search(option1), option1);
	result.clear();

	Option option2 = { COMMAND::SCH, OPTION1::NONE, OPTION2::DAY, Employee(), COLUMN::BIRTHDAY, "30", COLUMN::NONE, string() };
	result = employeeManager.search(option2);
	EXPECT_EQ(2, result.size());
}

TEST(EmployeeManagerHMTest, ModifyByPhoneLastNumberTest) 
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);

	std::map<int, Employee> result;

	Option option1 = { COMMAND::MOD, OPTION1::NONE, OPTION2::LAST_NUMBER, Employee(), COLUMN::PHONENUM, "5516", COLUMN::BIRTHDAY, "19900420" };
	result = employeeManager.execute(&employeeManager.search(option1), option1);
	result.clear();

	Option option2 = { COMMAND::SCH, OPTION1::NONE, OPTION2::YEAR, Employee(), COLUMN::BIRTHDAY, "1990", COLUMN::NONE, string() };
	result = employeeManager.search(option2);
	EXPECT_EQ(1, result.size());
}

TEST(EmployeeManagerHMTest, ModifyByBirthYearTest) 
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);
	
	std::map<int, Employee> result;

	Option option1 = { COMMAND::MOD, OPTION1::NONE, OPTION2::YEAR, Employee(), COLUMN::BIRTHDAY, "1987", COLUMN::BIRTHDAY, "19970402" };
	result = employeeManager.execute(&employeeManager.search(option1), option1);
	result.clear();

	Option option2 = { COMMAND::SCH, OPTION1::NONE, OPTION2::MONTH, Employee(), COLUMN::BIRTHDAY, "04", COLUMN::NONE, string() };
	result = employeeManager.search(option2);
	EXPECT_EQ(1, result.size());
}
TEST(EmployeeManagerHMTest, ModifyByBirthMonthTest)
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);
	
	std::map<int, Employee> result;

	Option option1 = { COMMAND::MOD, OPTION1::NONE, OPTION2::MONTH, Employee(), COLUMN::BIRTHDAY, "11", COLUMN::BIRTHDAY, "19770819" };
	result = employeeManager.execute(&employeeManager.search(option1), option1);
	result.clear();

	Option option2 = { COMMAND::SCH, OPTION1::NONE, OPTION2::DAY, Employee(), COLUMN::BIRTHDAY, "19", COLUMN::NONE, string() };
	result = employeeManager.search(option2);
	EXPECT_EQ(3, result.size());
}

TEST(EmployeeManagerHMTest, ModifyByBirthDayTest)
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);

	std::map<int, Employee> result;

	Option option1 = { COMMAND::MOD, OPTION1::NONE, OPTION2::DAY, Employee(), COLUMN::BIRTHDAY, "19", COLUMN::NAME, "Hyeonmin Koe" };
	result = employeeManager.execute(&employeeManager.search(option1), option1);
	result.clear();

	Option option2 = { COMMAND::SCH, OPTION1::NONE, OPTION2::FIRST_NAME, Employee(), COLUMN::NAME, "Hyeonmin", COLUMN::NONE, string() };
	result = employeeManager.search(option2);
	EXPECT_EQ(2, result.size());
}

