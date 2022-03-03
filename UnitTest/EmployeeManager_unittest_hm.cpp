#include "pch.h"
#include "../GCR Project/EmployeeManager.h"
#include "../GCR Project/EmployeeManager.cpp"

TEST(EmployeeManagerHMTest, AddTest) {
	EmployeeManager employeeManager;
	EXPECT_EQ(0, employeeManager.GetEmployeeSize());
	Employee employee1, employee2;
	employee1.EmpNo = "13009524";
	employee2.EmpNo = "98009520";
	employeeManager.Add(employee1);
	EXPECT_EQ(1, employeeManager.GetEmployeeSize());
	employeeManager.Add(employee2);
	EXPECT_EQ(2, employeeManager.GetEmployeeSize());
}