#include "Parser.h"
#include "common.h"

#include <vector>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

void Parser::check_input_format(const Employee new_employee) {
	//EmpNo
	if (new_employee.EmpNo.length() != EmpNo_Length)
		throw runtime_error("[Error] Input Format Error: Employee Number\n");
	//Name
	if (stringTokenize(new_employee.Name,' ').size() != Name_chunk)
		throw runtime_error("[Error] Input Format Error: Name\n");
	//Career_Level
	if (new_employee.Career_level != "CL1" &&
		new_employee.Career_level != "CL2" && 
		new_employee.Career_level != "CL3" &&
		new_employee.Career_level != "CL4")
		throw runtime_error("[Error] Input Format Error: Career Level\n");
	//Phone_number
	if (new_employee.Phone_number.length() != Phonenumber_Length)
		throw runtime_error("[Error] Input Format Error: Phone Number\n");
	//BirthDay
	if (new_employee.BirthDay.length() != Birthday_Length)
		throw runtime_error("[Error] Input Format Error: BirthDay\n");
	//Certi
	if(new_employee.Certi != "ADV" && new_employee.Certi != "PRO")
		throw runtime_error("[Error] Input Format Error: Certi\n");
}

void Parser::request_add(const vector<string> tokens) {

	Employee new_employee;
	new_employee.EmpNo = tokens[4];
	new_employee.Name = tokens[5];
	new_employee.Career_level = tokens[6];
	new_employee.Phone_number = tokens[7];
	new_employee.BirthDay = tokens[8];
	new_employee.Certi = tokens[9];

	check_input_format(new_employee);

	map<int, Employee> emptyResult;
	employManager_.execute(&emptyResult, { COMMAND::ADD, OPTION1::NONE, OPTION2::NONE, new_employee, COLUMN::NONE, "", COLUMN::NONE, "" });
}

string Parser::request_del(const vector<string> tokens) {
	string return_str;
	map<int, Employee> recived_value;
	Option option;

	fillOptionCommand(option, tokens[0]);
	fillOption1(option, tokens[1]);
	fillColumn(option, tokens[4], true);
	fillOption2(option, tokens[2]);
	fillSearchData(option, tokens[5]);

	//search
	recived_value = employManager_.search(option);

	//execute with searched results
	employManager_.execute(&recived_value, option);
	
	return_str = make_return_str(recived_value, option);
	return return_str;
}

string Parser::request_search(const vector<string> tokens) {
	string return_str;
	map<int, Employee> recived_value;
	Option option;

	fillOptionCommand(option, tokens[0]);
	fillOption1(option, tokens[1]);
	fillColumn(option, tokens[4], true);
	fillOption2(option, tokens[2]);
	fillSearchData(option, tokens[5]);

	//search
	recived_value = employManager_.search(option);

	return_str = make_return_str(recived_value, option);
	return return_str;
}

string Parser::request_mod(const vector<string> tokens) {
	string return_str;
	map<int, Employee> recived_value;

	Option option;

	fillOptionCommand(option, tokens[0]);
	fillOption1(option, tokens[1]);
	fillColumn(option, tokens[4], true);
	fillOption2(option, tokens[2]);
	fillSearchData(option, tokens[5]);
	fillColumn(option, tokens[6], false);
	fillChangeData(option, tokens[7]);

	//search
	recived_value = employManager_.search(option);
	//execute with searched results
	employManager_.execute(&recived_value, option);
	
	return_str = make_return_str(recived_value, option);
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

string Parser::make_return_str(const map<int, Employee> recived_value, const Option& option)
{
	string cmdString = getStringFromOptionCommand(option);
	if (recived_value.size() == 0) {
		return cmdString + ",NONE";
	}

	if (option.op1 == OPTION1::NONE) {
		return cmdString + "," + to_string(recived_value.size());
	}

	string return_str;
	int count = 0;
	for (auto iter = recived_value.begin(); iter != recived_value.end() && count < 5; iter++) {
		if(iter != recived_value.begin())
			return_str += "\n";
		return_str += cmdString + "," + (iter)->second.EmpNo + "," + (iter)->second.Name + "," + (iter)->second.Career_level + "," + (iter)->second.Phone_number + "," + (iter)->second.BirthDay + "," + (iter)->second.Certi;
		count++;
	}

	return return_str;
}

string Parser::parse(const string input_txt)
{
	string return_str, recived_str;
	
	vector<string> tokens = stringTokenize(input_txt, ',');

	recived_str = request_management(tokens);
	
	return recived_str;
}
