#include "Parser.h"
#include <vector>
#include <sstream>
#include <iostream>
#include <map>

#define NOOPTION 0
#define FIRSTNAME 1
#define LASTNAME 2
#define MIDNUMBER 3
#define LASTNUMBER 4
#define YEAR 5
#define MONTH 6
#define DAY 7

using namespace std;

bool check_value_type(const string value) {
	if (value[0] == '0')
		return false;
	else
		return true;
}

int get_search_option(const string column, const string option) {
	if (!option.compare("-f")) {
		return FIRSTNAME;
	}
	else if (!option.compare("-l")) {
		if (column == "name") return LASTNAME;
		else return LASTNUMBER;
	}
	else if (!option.compare("-m")) {
		if (column == "birthday") return MONTH;
		else return MIDNUMBER;
	}
	else if (!option.compare("-y"))
		return YEAR;
	else if (!option.compare("-d"))
		return DAY;
	else
		return NOOPTION;
}

bool check_print_option(const string option) {
	if (!option.compare("-p"))
		return true;
	else
		return false;
}

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
	new_employee.Certi = tokens[9];
	
	employeemanager.Add(new_employee);
}

string Parser::request_del(const vector<string> tokens) {
	string return_str;
	string command = tokens[0];
	map<int, Employee> recived_value;
	bool print_option = check_print_option(tokens[1]);
	string column = tokens[4];
	int search_option = get_search_option(column, tokens[2]);
	string value = tokens[5];


	switch (search_option)
	{
	case NOOPTION:
		recived_value = employeemanager.DeleteWithNoOption(column, value);
		cout << recived_value.size() << endl;
		break;
	case FIRSTNAME:
		recived_value = employeemanager.DeleteByFirstName(column, value);
		break;
	case LASTNAME:
		recived_value = employeemanager.DeleteByLastName(column, value);
		break;
	case MIDNUMBER:
		recived_value = employeemanager.DeleteByPhoneMidNumber(column, value);
		break;
	case LASTNUMBER:
		recived_value = employeemanager.DeleteByPhoneLastNumber(column, value);
		break;
	case YEAR:
		recived_value = employeemanager.DeleteByBirthYear(column, value);
		break;
	case MONTH:
		recived_value = employeemanager.DeleteByBirthMonth(column, value);
		break;
	case DAY:
		recived_value = employeemanager.DeleteByBirthDay(column, value);
		break;
	default:
		break;
	}
	
	return_str = make_return_str(recived_value, command, print_option);
	return return_str;
}

string Parser::request_search(const vector<string> tokens) {
	string return_str;
	string command = tokens[0];
	map<int, Employee> recived_value;
	bool print_option = check_print_option(tokens[1]);
	string column = tokens[4];
	int search_option = get_search_option(column, tokens[2]);
	string value = tokens[5];

	switch (search_option)
	{
	case NOOPTION:
		recived_value = employeemanager.SearchWithNoOption(column, value);
		break;
	case FIRSTNAME:
		recived_value = employeemanager.SearchByFirstName(column, value);
		break;
	case LASTNAME:
		recived_value = employeemanager.SearchByLastName(column, value);
		break;
	case MIDNUMBER:
		recived_value = employeemanager.SearchByPhoneMidNumber(column, value);
		break;
	case LASTNUMBER:
		recived_value = employeemanager.DeleteByPhoneLastNumber(column, value);
		break;
	case YEAR:
		recived_value = employeemanager.SearchByBirthYear(column, value);
		break;
	case MONTH:
		recived_value = employeemanager.SearchByBirthMonth(column, value);
		break;
	case DAY:
		recived_value = employeemanager.SearchByBirthDay(column, value);
		break;
	default:
		break;
	}

	return_str = make_return_str(recived_value, command, print_option);
	return return_str;
}

string Parser::request_mod(const vector<string> tokens) {
	string return_str;
	string command = tokens[0];
	map<int, Employee> recived_value;
	bool print_option = check_print_option(tokens[1]);
	string search_column = tokens[4];
	int search_option = get_search_option(search_column, tokens[2]);
	string search_value = tokens[5];
	string target_column = tokens[6];
	string target_value = tokens[7];

	switch (search_option)
	{
	case NOOPTION:
		recived_value = employeemanager.ModifyWithNoOption(search_column, search_value,target_column,target_value);
		break;
	case FIRSTNAME:
		recived_value = employeemanager.ModifyByFirstName(search_column, search_value,target_column,target_value);
		break;
	case LASTNAME:
		recived_value = employeemanager.ModifyByLastName(search_column, search_value, target_column, target_value);
		break;
	case MIDNUMBER:
		recived_value = employeemanager.ModifyByPhoneMidNumber(search_column, search_value,target_column,target_value);
		break;
	case LASTNUMBER:
		recived_value = employeemanager.ModifyByPhoneLastNumber(search_column, search_value, target_column, target_value);
		break;	
	case YEAR:
		recived_value = employeemanager.ModifyByBirthYear(search_column, search_value,target_column,target_value);
		break;
	case MONTH:
		recived_value = employeemanager.ModifyByBirthMonth(search_column, search_value,target_column,target_value);
		break;
	case DAY:
		recived_value = employeemanager.ModifyByBirthDay(search_column, search_value,target_column,target_value);
		break;
	default:
		break;
	}

	return_str = make_return_str(recived_value, command, print_option);
	return return_str;
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
	
	return string();
}

string Parser::make_return_str(const map<int, Employee> recived_value, string command, bool print_option)
{
	if (recived_value.size() == 0) {
		return command + ",NONE";
	}

	if (!print_option) {
		return command + "," + to_string(recived_value.size());
	}

	string return_str;
	int count = 0;
	for (auto iter = recived_value.begin(); iter != recived_value.end() && count < 5; iter++) {
		if(iter != recived_value.begin())
			return_str += "\n";
		return_str += command + "," + (iter)->second.EmpNo + "," + (iter)->second.Name + "," + (iter)->second.Career_level + "," + (iter)->second.Phone_number + "," + (iter)->second.BirthDay + "," + (iter)->second.Certi;
		count++;
	}

	return return_str;
}

string Parser::parse(const string input_txt)
{
	string return_str, recived_str;
	
	vector<string> tokens = p_splitString(input_txt, ',');

	recived_str = request_management(tokens);
	
	return recived_str;
}
