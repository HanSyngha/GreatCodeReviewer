#pragma once
#include <iostream>
#include <string>
using std::string;

struct Employee {
	string EmpNo;
	string Name;
	string FirstName;
	string LastName;
	string Career_level;
	string Phone_number;
	string PhoneMid;
	string PhoneLast;
	string BirthYear;
	string BirthMonth;
	string BirthDay;
	string Certi;
	Employee() {}
	Employee(string empNo, string name, string career_level, string phone_number, string phoneMid, 
		string phoneLast, string birthYear, string birthMonth, string birthDay, string certi) :
		EmpNo(empNo), Name(name), Career_level(career_level), Phone_number(phone_number), PhoneMid(phoneMid),
		PhoneLast(phoneLast), BirthYear(birthYear), BirthMonth(birthMonth), BirthDay(birthDay), Certi(certi)
	{
	}
	static int makeKeyValueFromString(const std::string& employeeNum) {
		if (employeeNum.front() == '6' || employeeNum.front() == '7' || employeeNum.front() == '8' || employeeNum.front() == '9') {
			return(std::stoi("19" + employeeNum));
		}

		return std::stoi("20" + employeeNum);
	}
};