#pragma once
#include "EmployeeManager.h"
#include "Employee.h"
#include <vector>
#include <iostream>
using namespace std;

class Parser{
public:
	string request_management(const vector<string>& tokens);
	string request_del(const vector<string>& tokens);
	string request_search(const vector<string>& tokens);
	string request_mod(const vector<string>& tokens);
	string make_return_str(const map<int, Employee> recived_value, Option* option);
	string parse(const string input_txt);

	void request_add(const vector<string>& tokens);
	void check_input_format(const Employee new_employee);

private:
	EmployeeManager employManager_;
};

enum Format
{
	EmpNo_Length = 8,
	Name_chunk = 2,
	Phonenumber_chunk = 3,
	Birthday_Length = 8
};