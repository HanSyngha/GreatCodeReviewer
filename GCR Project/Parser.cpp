#include "Parser.h"
#include "common.h"
#include "EmployeeManager.h"
#include "Employee.h"
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> p_splitString(const string& orgString, const char delimiter) {
	vector<string> tokens;
	istringstream strStream(orgString);
	string token;

	while (getline(strStream, token, delimiter)) {
		tokens.push_back(token);
	}

	return tokens;
}

void Parser::request_add(const vector<string> tokens) {

	Employee new_employee;
	new_employee.EmpNo = tokens[4];
	new_employee.Name = tokens[5];
	new_employee.Career_level = tokens[6];
	new_employee.Phone_number = tokens[7];
	new_employee.BirthDay = tokens[8];
	new_employee.Career_level = tokens[9];

	EmployeeManager employee;
	employee.Add(new_employee);
}

string Parser::request_del(const vector<string> tokens) {
	string return_str;
	
	if (tokens[1].compare("-p"))
		return return_str;
	else
		return string();

}

string Parser::request_search(const vector<string> tokens) {
	string return_str;

	if (tokens[1].compare("-p"))
		return return_str;
	else
		return string();

}

string Parser::request_mod(const vector<string> tokens) {
	string return_str;

	if (tokens[1].compare("-p"))
		return return_str;
	else
		return string();
}

string Parser::request_management(const vector<string> tokens) {
	if (!tokens[0].compare("ADD"))
		request_add(tokens);
	else if (!tokens[0].compare("DEL"))
		return request_del(tokens);
	else if (!tokens[0].compare("SCH"))
		return request_search(tokens);
	else if (!tokens[0].compare("MOD"))
		return request_mod(tokens);
	else
		return string();
}

string Parser::make_return_str(const string reviced_str) {
	return string();
}

string Parser::parse(const string input_txt)
{
	string return_str,recived_str;
	
	vector<string> tokens = p_splitString(input_txt, ',');

	recived_str = request_management(tokens);
	
	return_str = make_return_str(recived_str);
	
	return return_str;
}
