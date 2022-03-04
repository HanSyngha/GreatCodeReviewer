#pragma once
#include <iostream>
#include <string>
using std::string;

struct Employee {

	std::string EmpNo;
	std::string Name;
	std::string Career_level;
	std::string Phone_number;
	std::string BirthDay;
	std::string Certi;

	static int makeKeyValueFromString(const std::string& employeeNum) {
		if (employeeNum.front() == '6' || employeeNum.front() == '7' || employeeNum.front() == '8' || employeeNum.front() == '9') {
			return(std::stoi("19" + employeeNum));
		}

		return std::stoi("20" + employeeNum);
	}
};