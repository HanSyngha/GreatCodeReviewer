#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Employee {
	void init(string EmpNo, string Name, string Career_level, string Phone_number, string Birthday, string Certi) {
		EmpNo_ = EmpNo;
		Name_ = Name;
		Career_level_ = Career_level;
		Phone_number_ = Phone_number;
		BirthDay_ = Birthday;
		Certi_ = Certi;
	}

	std::string EmpNo_;
	std::string Name_;
	std::string Career_level_;
	std::string Phone_number_;
	std::string BirthDay_;
	std::string Certi_;

	static int makeKeyValueFromString(const std::string& employeeNum) {
		int frontNum = std::stoi(employeeNum.substr(0, 1));
		if (frontNum >= 6 && frontNum <= 9) {
			return std::stoi("19" + employeeNum);
		}

		return std::stoi("20" + employeeNum);
	}
};