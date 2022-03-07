#pragma once
#include "EmployeeManager.h"
#include "Employee.h"
#include <vector>
#include <iostream>
using namespace std;

class Parser{
public:
	void request_management(string& return_str, const vector<string>& tokens);
	void request_del(string& return_str, const vector<string>& tokens);
	void request_search(string& return_str, const vector<string>& tokens);
	void request_mod(string& return_str, const vector<string>& tokens);
	void make_return_str(string& return_str, const EmployeeResult* recived_value, Option* option);
	void parse(string& return_str, const string input_txt);

	void request_add(string& return_str, const vector<string>& tokens);
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