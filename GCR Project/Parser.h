#pragma once
#include "EmployeeManager.h"
#include "Employee.h"
#include <vector>
#include <iostream>
using namespace std;

class Parser{
public:
	Parser() {
		EM = EmployeeManager();
	}
	string request_management(const vector<string> tokens);
	string request_del(const vector<string> tokens);
	string request_search(const vector<string> tokens);
	string request_mod(const vector<string> tokens);
	string make_return_str(const string reviced_str);
	string parse(const string input_txt);
	void request_add(const vector<string> tokens);
private:
	EmployeeManager EM;
};