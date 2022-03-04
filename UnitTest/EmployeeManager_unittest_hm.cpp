#include "pch.h"
#include "../GCR Project/EmployeeManager.h"
#include "../GCR Project/EmployeeManager.cpp"


void initEmployManager(EmployeeManager& employeeManager) {
	employeeManager.Add({ "13009524", "Hyeonmin Seo", "CL3", "010-8463-5536", "19870319", "PRO" });
	employeeManager.Add({ "13009500", "Hyeonmia Seo", "CL1", "010-8463-5516", "19881129", "ADV" });
	employeeManager.Add({ "13009521", "Hyeonmib Eeo", "CL2", "010-8463-5526", "19890130", "EXP" });
	employeeManager.Add({ "13009522", "Hyeonmic Leo", "CL3", "010-8443-5536", "19810719", "PRO" });
	employeeManager.Add({ "13009523", "Hyeonmid Aeo", "CL4", "010-8453-5536", "19820911", "ADV" });
}

TEST(EmployeeManagerHMTest, AddTest) {
	EmployeeManager employeeManager;
	EXPECT_EQ(0, employeeManager.GetEmployeeSize());	
	employeeManager.Add({ "13009524", "Hyeonmin Seo", "CL3", "010-8463-5536", "19870319", "PRO" });
	EXPECT_EQ(1, employeeManager.GetEmployeeSize());
	employeeManager.Add({ "13009521", "Hyeonmib Eeo", "CL2", "010-8463-5526", "19890130", "EXP" });	
	EXPECT_EQ(2, employeeManager.GetEmployeeSize());
}

TEST(EmployeeManagerHMTest, ModifyByFirstNameTest) 
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);
	
	std::map<int, Employee> result;
	
	employeeManager.ModifyByFirstName("FirstName", "Hyeonmin", "phoneNum", "010-8463-5516");
	result = employeeManager.SearchByPhoneLastNumber("", "5516");
	EXPECT_EQ(2, result.size());

}

TEST(EmployeeManagerHMTest, ModifyByLastNameTest) 
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);

	std::map<int, Employee> result;

	employeeManager.ModifyByLastName("LastName", "Seo", "cl", "CL4");
	result = employeeManager.SearchWithNoOption("cl", "CL4");

	EXPECT_EQ(3, result.size());
}

TEST(EmployeeManagerHMTest, ModifyByPhoneMidNumberTest) 
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);

	std::map<int, Employee> result;

	employeeManager.ModifyByPhoneMidNumber("PhoneMidNumber", "8443", "birthday", "19691130");
	result = employeeManager.SearchByBirthDay("birthday", "30");
	
	EXPECT_EQ(2, result.size());
}

TEST(EmployeeManagerHMTest, ModifyByPhoneLastNumberTest) 
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);

	std::map<int, Employee> result;

	employeeManager.ModifyByPhoneLastNumber("PhoneLastNumber", "5516", "birthday", "19900420");
	result = employeeManager.SearchByBirthYear("BirthYear", "1990");
	EXPECT_EQ(1, result.size());
}

TEST(EmployeeManagerHMTest, ModifyByBirthYearTest) 
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);
	
	std::map<int, Employee> result;

	employeeManager.ModifyByBirthYear("BirthYear", "1987", "birthday", "19970402");
	result = employeeManager.SearchByBirthMonth("BirthMonth", "04");

	EXPECT_EQ(1, result.size());
}
TEST(EmployeeManagerHMTest, ModifyByBirthMonthTest)
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);
	
	std::map<int, Employee> result;

	employeeManager.ModifyByBirthMonth("BirthMonth", "11", "birthday", "19770819");
	result = employeeManager.SearchByBirthDay("BirthDay", "19");

	EXPECT_EQ(3, result.size());
}

TEST(EmployeeManagerHMTest, ModifyByBirthDayTest)
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);

	std::map<int, Employee> result;

	employeeManager.ModifyByBirthDay("BirthDay", "19", "name", "Hyeonmin Koe");
	result = employeeManager.SearchByFirstName("FirstName", "Hyeonmin");

	EXPECT_EQ(2, result.size());
}

