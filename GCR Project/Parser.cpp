#include "Parser.h"
#include <vector>
#include <sstream>
#include <iostream>

#define NOOPTION 0
#define FIRSTNAME 1
#define MIDNUMBER 2
#define LAST 3
#define YEAR 4
#define MONTH 5
#define DAY 6

using namespace std;

bool check_value_type(const string value) {
	if (value[0] == '0')
		return false;
	else
		return true;
}

int get_search_option(const string option) {
	if (!option.compare("-f"))
		return FIRSTNAME;
	else if (!option.compare("-l"))
		return LAST;
	else if (!option.compare("-m"))
		return MIDNUMBER;
	else if (!option.compare("-y"))
		return YEAR;
	else if (!option.compare("-m"))
		return MONTH;
	else if (!option.compare("-d"))
		return DAY;
	else
		return NOOPTION;
}

bool check_print_option(const string option) {
	if (option.compare("-p"))
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
	new_employee.Career_level = tokens[9];

	EmployeeManager employee = EmployeeManager();
	//[Bug] Link Error
	//employee.Add(new_employee);
}

string Parser::request_del(const vector<string> tokens) {
	string return_str = string();
	string recived_str = string();
	bool print_option = check_print_option(tokens[1]);
	int search_option = get_search_option(tokens[2]);
	string column = tokens[4];
	string value = tokens[5];

	switch (search_option)
	{
	case NOOPTION:
		//[Bug] Link Error
		//recived_str = EM.DeleteWithNoOption(column, value);
		break;
	case FIRSTNAME:
		//[Bug] Link Error
		//recived_str = EM.DeleteByFirstName(column, value);
		break;
	case MIDNUMBER:
		//[Bug] Link Error
		//recived_str = EM.DeleteByPhoneMidNumber(column, value);
		break;
	case LAST:
		if (check_value_type(value)) {
			//[Bug] Link Error
			//recived_str = EM.DeleteByLastName(column, value);
		}
		else {
			//[Bug] Link Error
			//recived_str = EM.DeleteByPhoneLastNumber(column, value)
		}
		break;
	case YEAR:
		//[Bug] Link Error
		//recived_str = EM.DeleteByBirthYear(column, value);
		break;
	case MONTH:
		//[Bug] Link Error
		//recived_str = EM.DeleteByBirthMonth(column, value);
		break;
	case DAY:
		//[Bug] Link Error
		//recived_str = EM.DeleteByBirthDay(column, value);
		break;
	default:
		break;
	}
	
	if (print_option)
		make_return_str(return_str);
	return return_str;
}

string Parser::request_search(const vector<string> tokens) {
	string return_str = string();
	string recived_str = string();
	bool print_option = check_print_option(tokens[1]);
	int search_option = get_search_option(tokens[2]);
	string column = tokens[4];
	string value = tokens[5];

	switch (search_option)
	{
	case NOOPTION:
		//[Bug] Link Error
		//recived_str = EM.SearchWithNoOption(column, value);
		break;
	case FIRSTNAME:
		//[Bug] Link Error
		//recived_str = EM.SearchByFirstName(column, value);
		break;
	case MIDNUMBER:
		//[Bug] Link Error
		//recived_str = EM.SearchByPhoneMidNumber(column, value);
		break;
	case LAST:
		if (check_value_type(value)) {
			//[Bug] Link Error
			//recived_str = EM.SearchByLastName(column, value);
		}
		else {
			//[Bug] Link Error
			//recived_str = EM.DeleteByPhoneLastNumber(column, value)
		}
		break;
	case YEAR:
		//[Bug] Link Error
		//recived_str = EM.SearchByBirthYear(column, value);
		break;
	case MONTH:
		//[Bug] Link Error
		//recived_str = EM.SearchByBirthMonth(column, value);
		break;
	case DAY:
		//[Bug] Link Error
		//recived_str = EM.SearchByBirthDay(column, value);
		break;
	default:
		break;
	}

	if (print_option)
		make_return_str(return_str);
	return return_str;
}

string Parser::request_mod(const vector<string> tokens) {
	string return_str = string();
	string recived_str = string();
	bool print_option = check_print_option(tokens[1]);
	int search_option = get_search_option(tokens[2]);
	string search_column = tokens[4];
	string search_value = tokens[5];
	string target_column = tokens[6];
	string target_value = tokens[7];

	switch (search_option)
	{
	case NOOPTION:
		//[Bug] Link Error
		//recived_str = EM.ModifyWithNoOption(search_column, search_value,target_column,target_value);
		break;
	case FIRSTNAME:
		//[Bug] Link Error
		//recived_str = EM.ModifyByFirstName(search_column, search_value,target_column,target_value);
		break;
	case MIDNUMBER:
		//[Bug] Link Error
		//recived_str = EM.ModifyByPhoneMidNumber(search_column, search_value,target_column,target_value);
		break;
	case LAST:
		if (check_value_type(search_value)) {
			//[Bug] Link Error
			//recived_str = EM.ModifyByLastName(search_column, search_value,target_column,target_value);
		}
		else {
			//[Bug] Link Error
			//recived_str = EM.ModifyByPhoneLastNumber(search_column, search_value,target_column,target_value);
		}
		break;
	case YEAR:
		//[Bug] Link Error
		//recived_str = EM.ModifyByBirthYear(search_column, search_value,target_column,target_value);
		break;
	case MONTH:
		//[Bug] Link Error
		//recived_str = EM.ModifyByBirthMonth(search_column, search_value,target_column,target_value);
		break;
	case DAY:
		//[Bug] Link Error
		//recived_str = EM.ModifyByBirthDay(search_column, search_value,target_column,target_value);
		break;
	default:
		break;
	}

	if (print_option)
		return_str = make_return_str(recived_str);
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
	else
		return string();
}

string Parser::make_return_str(const string reviced_str) {
	//TODO
	return string();
}

string Parser::parse(const string input_txt)
{
	string return_str, recived_str;
	
	vector<string> tokens = p_splitString(input_txt, ',');

	recived_str = request_management(tokens);
	
	return_str = make_return_str(recived_str);
	
	return string();
}
