#include "pch.h"
#include "../GCR Project/EmployeeManager.h"
#include "../GCR Project/EmployeeManager.cpp"


void initEmployManager(EmployeeManager& employeeManager) {
	employeeManager.Add({ "13009524", "Hyeonmin Seo", "CL3", "010-8463-5536", "8463", "5536", "87", "03", "19", "Pro" });
	employeeManager.Add({ "13009500", "Hyeonmia Seo", "CL1", "010-8463-5516", "8463", "5516", "88", "11", "29", "Adv" });
	employeeManager.Add({ "13009521", "Hyeonmib Eeo", "CL2", "010-8463-5526", "8463", "5526", "89", "01", "30", "Exp" });
	employeeManager.Add({ "13009522", "Hyeonmic Leo", "CL3", "010-8443-5536", "8443", "5536", "81", "07", "19", "Pro" });
	employeeManager.Add({ "13009523", "Hyeonmid Aeo", "CL4", "010-8453-5536", "8453", "5536", "82", "09", "11", "Adv" });
}

TEST(EmployeeManagerHMTest, AddTest) {
	EmployeeManager employeeManager;
	EXPECT_EQ(0, employeeManager.GetEmployeeSize());	
	employeeManager.Add({ "13009524", "Hyeonmin Seo", "CL3", "010-8463-5536", "8463", "5536", "87", "03", "19", "Pro" });
	EXPECT_EQ(1, employeeManager.GetEmployeeSize());
	employeeManager.Add({ "13009521", "Hyeonmib Eeo", "CL2", "010-8463-5526", "8463", "5526", "89", "01", "30", "Exp" });	
	EXPECT_EQ(2, employeeManager.GetEmployeeSize());
}

TEST(EmployeeManagerHMTest, ModifyByFirstNameTest) 
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);
	
	std::map<int, Employee> result;
	
	employeeManager.ModifyByFirstName("FirstName", "Hyeonmin", "MidNumber", "8453");
	result = employeeManager.SearchByPhoneMidNumber("", "8453");
	EXPECT_EQ(2, result.size());

}

TEST(EmployeeManagerHMTest, ModifyByLastNameTest) 
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);

	std::map<int, Employee> result;

	employeeManager.ModifyByLastName("LastName", "Seo", "LastNumber", "5526");
	result = employeeManager.SearchByPhoneLastNumber("", "5526");

	EXPECT_EQ(3, result.size());
}

TEST(EmployeeManagerHMTest, ModifyByPhoneMidNumberTest) 
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);

	std::map<int, Employee> result;

	employeeManager.ModifyByPhoneMidNumber("PhoneMidNumber", "8443", "BirthDay", "30");
	result = employeeManager.SearchByBirthDay("BirthDay", "30");
	
	EXPECT_EQ(2, result.size());
}

TEST(EmployeeManagerHMTest, ModifyByPhoneLastNumberTest) 
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);

	std::map<int, Employee> result;

	employeeManager.ModifyByPhoneLastNumber("PhoneLastNumber", "5516", "BirthYear", "90");
	result = employeeManager.SearchByBirthYear("BirthYear", "90");
	EXPECT_EQ(1, result.size());
}

TEST(EmployeeManagerHMTest, ModifyByBirthYearTest) 
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);
	
	std::map<int, Employee> result;

	employeeManager.ModifyByBirthYear("BirthYear", "87", "BirthMonth", "04");
	result = employeeManager.SearchByBirthMonth("BirthMonth", "04");

	EXPECT_EQ(1, result.size());
}
TEST(EmployeeManagerHMTest, ModifyByBirthMonthTest)
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);
	
	std::map<int, Employee> result;

	employeeManager.ModifyByBirthMonth("BirthMonth", "11", "BirthDay", "19");
	result = employeeManager.SearchByBirthDay("BirthDay", "19");

	EXPECT_EQ(3, result.size());
}

TEST(EmployeeManagerHMTest, ModifyByBirthDayTest)
{
	EmployeeManager employeeManager;
	initEmployManager(employeeManager);

	std::map<int, Employee> result;

	employeeManager.ModifyByBirthDay("BirthDay", "19", "FirstName", "Hyeonmin");
	result = employeeManager.SearchByFirstName("FirstName", "Hyeonmin");

	EXPECT_EQ(2, result.size());
}

