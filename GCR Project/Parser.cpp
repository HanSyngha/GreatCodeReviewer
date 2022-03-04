#include "Parser.h"
#include "common.h"
#include "EmployeeManager.h"
#include "Employee.h"
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> splitString(const string& orgString, const char delimiter) {
	vector<string> tokens;
	istringstream strStream(orgString);
	string token;

	while (getline(strStream, token, delimiter)) {
		tokens.push_back(token);
	}

	return tokens;
}

vector<string> split_birth(const string birth) {
	vector<string> tokens;
	string year = "0000";
	string month = "00";
	string day = "00";

	for (int idx = 0; idx < 4; idx++)
		year[idx] = birth[idx];
	tokens.push_back(year);

	for (int idx = 0; idx < 2; idx++)
		month[idx] = birth[4 + idx];
	tokens.push_back(month);

	for (int idx = 0; idx < 2; idx++)
		day[idx] = birth[6 + idx];
	tokens.push_back(day);
	
	return tokens;
}

string Parser::request_add(const vector<string> tokens) {

	vector<string> split_phone_number = splitString(tokens[7], '-');
	vector<string> split_birthday = split_birth(tokens[8]);

	struct Employee new_employee;
	new_employee.EmpNo = tokens[4];
	new_employee.Name = tokens[5];
	new_employee.Career_level = tokens[6];
	new_employee.Phone_number = tokens[7];
	new_employee.PhoneMid = split_phone_number[1];
	new_employee.PhoneLast = split_phone_number[2];
	new_employee.BirthYear = split_birthday[0];
	new_employee.BirthMonth = split_birthday[1];
	new_employee.BirthDay = split_birthday[2];
	new_employee.Career_level = tokens[9];

	EmployeeManager employee;
	void Add(const Employee & employee);
	
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
		return request_add(tokens);
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
	
	vector<string> tokens = splitString(input_txt, ',');

	recived_str = request_management(tokens);
	
	return_str = make_return_str(recived_str);
	
	return return_str;
}
