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
	vector<string> phone_chunk = stringTokenize(new_employee.Phone_number,'-');
	if (phone_chunk.size() != Phonenumber_chunk)
		throw runtime_error("[Error] Input Format Error: Phone Number\n");
	for(auto chunk:phone_chunk)
		for(auto num:chunk)
			if (num > '9' || num < '0')
				throw runtime_error("[Error] Input Format Error: Phone Number\n");

	//BirthDay
	if (new_employee.BirthDay.length() != Birthday_Length)
		throw runtime_error("[Error] Input Format Error: BirthDay\n");

	for(auto num : new_employee.BirthDay)
		if(num > '9' || num < '0')
			throw runtime_error("[Error] Input Format Error: BirthDay\n");
	//Certi
	if(new_employee.Certi != "ADV" &&
		new_employee.Certi != "PRO" &&
		new_employee.Certi != "EX")
		throw runtime_error("[Error] Input Format Error: Certi\n");
}

void Parser::request_add(const vector<string>& tokens) {
	map<int, Employee> results;
	employManager_.execute(&results, { COMMAND::ADD, OPTION1::NONE, OPTION2::NONE, { tokens[4], tokens[5], tokens[6], tokens[7], tokens[8], tokens[9] }, COLUMN::NONE, "", COLUMN::NONE, "" });
}

string Parser::request_del(const vector<string>& tokens) {
	string return_str;
	map<int, Employee> recived_value;
	Option option;

	fillOptionCommand(option, tokens[0]);
	fillOption1(option, tokens[1]);
	fillColumn(option, tokens[4], true);
	fillOption2(option, tokens[2]);
	fillData(option, tokens[5], true);

	//search
	recived_value = employManager_.search(option);

	//execute with searched results
	employManager_.execute(&recived_value, option);
	
	return_str = make_return_str(recived_value, option);
	return return_str;
}

string Parser::request_search(const vector<string>& tokens) {
	string return_str;
	map<int, Employee> recived_value;
	Option option;

	fillOptionCommand(option, tokens[0]);
	fillOption1(option, tokens[1]);
	fillColumn(option, tokens[4], true);
	fillOption2(option, tokens[2]);
	fillData(option, tokens[5], true);

	//search
	recived_value = employManager_.search(option);

	return_str = make_return_str(recived_value, option);
	return return_str;
}

string Parser::request_mod(const vector<string>& tokens) {
	string return_str;
	map<int, Employee> recived_value;

	Option option;

	fillOptionCommand(option, tokens[0]);
	fillOption1(option, tokens[1]);
	fillColumn(option, tokens[4], true);
	fillOption2(option, tokens[2]);
	fillData(option, tokens[5], true);
	fillColumn(option, tokens[6], false);
	fillData(option, tokens[7], false);

	//search
	recived_value = employManager_.search(option);
	//execute with searched results
	employManager_.execute(&recived_value, option);
	
	return_str = make_return_str(recived_value, option);
	return return_str;
}

string Parser::request_management(const vector<string>& tokens) {
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
	
	vector<string> tokens;
	stringTokenize(tokens, input_txt, ',');

	recived_str = request_management(tokens);
	
	return recived_str;
}
