#pragma once
#include <iostream>
#include <string>

struct Employee {

	std::string employeeNum;
	std::string name;
	std::string cl;
	std::string phoneNum;
	std::string birthday;
	std::string certi;

	static int makeKeyValueFromString(const std::string& employeeNum) {
		int frontNum = std::stoi(employeeNum.substr(0, 1));
		if (frontNum >= 6 && frontNum <= 9) {
			return std::stoi("19" + employeeNum);
		}

		return std::stoi("20" + employeeNum);
	}
};