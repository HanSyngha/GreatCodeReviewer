#include "pch.h"
#include "../GCR Project/EmployeeManager.h"
#include "../GCR Project/EmployeeManager.cpp"
#include "../GCR Project/Employee.h"
#include "../GCR Project/Option.h"

using namespace std;

void initEmployManager(EmployeeManager& employeeManager) {
	map<int, Employee> emptyResult;
	Employee employee;
	employee.init("85125741", "FBAH RTIJ", "CL1", "010-8900-1478", "19780228", "ADV");
	AddOption option = AddOption(employee);
	employeeManager.execute(&emptyResult, &option);

	employee.init("13009524", "Hyeonmin Seo", "CL3", "010-8463-5536", "19870319", "PRO");
	option = AddOption(employee);
	employeeManager.execute(&emptyResult, &option);

	employee.init("13009500", "Hyeonmia Seo", "CL1", "010-8463-5516", "19881129", "ADV");
	option = AddOption(employee);
	employeeManager.execute(&emptyResult, &option);

	employee.init("13009521", "Hyeonmib Eeo", "CL2", "010-8463-5526", "19890130", "EXP");
	option = AddOption(employee);
	employeeManager.execute(&emptyResult, &option);

	employee.init("13009522", "Hyeonmic Leo", "CL3", "010-8443-5536", "19810719", "PRO");
	option = AddOption(employee);
	employeeManager.execute(&emptyResult, &option);

	employee.init("13009523", "Hyeonmid Aeo", "CL4", "010-8453-5536", "19820911", "ADV");
	option = AddOption(employee);
	employeeManager.execute(&emptyResult, &option);
}

TEST(EmployeeManagerHMTest, AddTest) {
	EmployeeManager employeeManager;
	map<int, Employee> results;
	Employee employee;
	employee.init("13009524", "Hyeonmin Seo", "CL3", "010-8463-5536", "19870319", "PRO");
	AddOption option = AddOption(employee);
	employeeManager.execute(&results, &option);

	SchOption option2 = SchOption("employeeNum", "13009524");
	results = employeeManager.search(&option2);
	EXPECT_EQ(1, results.size());
	results.clear();
	
	employee.init("13009521", "Hyeonmib Eeo", "CL2", "010-8463-5526", "19890130", "EXP");
	option = AddOption(employee);
	employeeManager.execute(&results, &option);
	
	option2.fillSearchData("13009521");
	results = employeeManager.search(&option2);
	EXPECT_EQ(1, results.size());
	results.clear();	
}


TEST(EmployeeManagerHMTest, ModifyByFirstNameTest)
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);

	std::map<int, Employee> result;

	ModOption modOption = ModOption("name", "Hyeonmin", "phoneNum", "010-8463-5516", "-f");
	result = employeeManager.search(&modOption);
	employeeManager.execute(&result, &modOption);
	result.clear();

	SchOption schOption = SchOption("phoneNum", "5516", "-l");
	result = employeeManager.search(&schOption);

	EXPECT_EQ(2, result.size());
}

TEST(EmployeeManagerHMTest, ModifyByLastNameTest)
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);

	std::map<int, Employee> result;

	ModOption modOption = ModOption("name", "Seo", "cl", "CL4", "-l");
	result = employeeManager.search(&modOption);
	employeeManager.execute(&result, &modOption);
	result.clear();

	SchOption schOption = SchOption("cl", "CL4");
	result = employeeManager.search(&schOption);

	EXPECT_EQ(3, result.size());
}

TEST(EmployeeManagerHMTest, ModifyByPhoneMidNumberTest)
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);

	std::map<int, Employee> result;

	ModOption modOption = ModOption("phoneNum", "8443", "birthday", "19691130", "-m");
	result = employeeManager.search(&modOption);
	employeeManager.execute(&result, &modOption);
	result.clear();

	SchOption schOption = SchOption("birthday", "30", "-d");
	result = employeeManager.search(&schOption);

	EXPECT_EQ(2, result.size());
}

TEST(EmployeeManagerHMTest, ModifyByPhoneLastNumberTest)
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);

	std::map<int, Employee> result;

	ModOption modOption = ModOption("phoneNum", "5516", "birthday", "19900420", "-l");
	result = employeeManager.search(&modOption);
	employeeManager.execute(&result, &modOption);
	result.clear();

	SchOption schOption = SchOption("birthday", "1990", "-y");
	result = employeeManager.search(&schOption);

	EXPECT_EQ(1, result.size());
}

TEST(EmployeeManagerHMTest, ModifyByBirthYearTest)
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);

	std::map<int, Employee> result;

	ModOption modOption = ModOption("birthday", "1987", "birthday", "19970402", "-y");
	result = employeeManager.search(&modOption);
	employeeManager.execute(&result, &modOption);
	result.clear();

	SchOption schOption = SchOption("birthday", "04", "-m");
	result = employeeManager.search(&schOption);

	EXPECT_EQ(1, result.size());
}
TEST(EmployeeManagerHMTest, ModifyByBirthMonthTest)
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);

	std::map<int, Employee> result;

	ModOption modOption = ModOption("birthday", "11", "birthday", "19770819", "-m");
	result = employeeManager.search(&modOption);
	employeeManager.execute(&result, &modOption);
	result.clear();

	SchOption schOption = SchOption("birthday", "19", "-d");
	result = employeeManager.search(&schOption);
	EXPECT_EQ(3, result.size());
}

TEST(EmployeeManagerHMTest, ModifyByBirthDayTest)
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);

	std::map<int, Employee> result;

	ModOption modOption = ModOption("birthday", "19", "name", "Hyeonmin Koe", "-d");
	result = employeeManager.search(&modOption);
	employeeManager.execute(&result, &modOption);
	result.clear();

	SchOption schOption = SchOption("name", "Hyeonmin", "-f");
	result = employeeManager.search(&schOption);

	EXPECT_EQ(2, result.size());
}