#pragma once
#include <iostream>
#include <string>

struct Employee {

	std::string EmpNo;
	std::string Name;
	std::string Career_level;
	std::string Phone_number;
	std::string BirthDay;
	std::string Certi;

	static int makeKeyValueFromString(const std::string& employeeNum) {
		int frontNum = std::stoi(employeeNum.substr(0, 1));
		if (frontNum >= 6 && frontNum <= 9) {
			return std::stoi("19" + employeeNum);
		}

		return std::stoi("20" + employeeNum);
	}
};