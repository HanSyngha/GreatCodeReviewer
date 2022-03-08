#include "Parser.h"
#include "Option.h"

#include <vector>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

void Parser::check_input_format(const Employee new_employee) {
	//EmpNo
	if (new_employee.EmpNo_.length() != EmpNo_Length)
		throw runtime_error("[Error] Input Format Error: Employee Number\n");

	//Name
	vector<string> tokens;
	Option::stringTokenize(tokens, new_employee.Name_, ' ');
	if (tokens.size() != Name_chunk)
		throw runtime_error("[Error] Input Format Error: Name\n");

	//Career_Level
	if (new_employee.Career_level_ != "CL1" &&
		new_employee.Career_level_ != "CL2" && 
		new_employee.Career_level_ != "CL3" &&
		new_employee.Career_level_ != "CL4")
		throw runtime_error("[Error] Input Format Error: Career Level\n");

	//Phone_number
	vector<string> phone_chunk;
	Option::stringTokenize(phone_chunk, new_employee.Phone_number_,'-');
	if (phone_chunk.size() != Phonenumber_chunk)
		throw runtime_error("[Error] Input Format Error: Phone Number\n");
	for(auto chunk:phone_chunk)
		for(auto num:chunk)
			if (num > '9' || num < '0')
				throw runtime_error("[Error] Input Format Error: Phone Number\n");

	//BirthDay
	if (new_employee.BirthDay_.length() != Birthday_Length)
		throw runtime_error("[Error] Input Format Error: BirthDay\n");

	for(auto num : new_employee.BirthDay_)
		if(num > '9' || num < '0')
			throw runtime_error("[Error] Input Format Error: BirthDay\n");
	//Certi
	if(new_employee.Certi_ != "ADV" &&
		new_employee.Certi_ != "PRO" &&
		new_employee.Certi_ != "EX")
		throw runtime_error("[Error] Input Format Error: Certi\n");
}

void Parser::request_add(string& return_str, const vector<string>& tokens) {

	Employee employee;
	employee.init(tokens[4], tokens[5], tokens[6], tokens[7], tokens[8], tokens[9]);
	AddOption option = AddOption(employee);

	//add
	employManager_.execute(nullptr, &option);
	return_str = "";
}

void Parser::request_del(string& return_str, const vector<string>& tokens) {
	EmployeeResult* recived_value;
	DelOption option = DelOption(tokens[4], tokens[5], tokens[2]);
	option.fillOption1(tokens[1]);

	//search
	recived_value = employManager_.search(&option);

	//execute with searched results
	employManager_.execute(recived_value, &option);
	
	make_return_str(return_str, recived_value, &option);
}

void Parser::request_search(string& return_str, const vector<string>& tokens) {
	EmployeeResult* recived_value;
	SchOption option = SchOption(tokens[4], tokens[5], tokens[2]);
	option.fillOption1(tokens[1]);

	//search
	recived_value = employManager_.search(&option);

	make_return_str(return_str, recived_value, &option);
}

void Parser::request_mod(string& return_str, const vector<string>& tokens) {
	EmployeeResult* recived_value;
	ModOption option = ModOption(tokens[4], tokens[5], tokens[6], tokens[7], tokens[2]);
	option.fillOption1(tokens[1]);

	//search
	recived_value = employManager_.search(&option);
	//execute with searched results
	employManager_.execute(recived_value, &option);
	
	make_return_str(return_str, recived_value, &option);
}

void Parser::request_management(string& return_str, const vector<string>& tokens) {
	if (!tokens[0].compare("ADD"))
		request_add(return_str, tokens);
	else if (!tokens[0].compare("DEL")) 
		request_del(return_str, tokens);
	else if (!tokens[0].compare("SCH"))
		request_search(return_str, tokens);
	else if (!tokens[0].compare("MOD"))
		request_mod(return_str, tokens);
}

void Parser::make_return_str(string& return_str, const EmployeeResult* recived_value, Option* option)
{
	string cmdString = option->getStringFromOptionCommand();
	DBG_ASSERT(recived_value->count > Option::LimitCount || recived_value->count == recived_value->entity.size());
	if (recived_value->count == 0) {
		return_str = cmdString + ",NONE";
		return;
	}

	if (option->getOption1() == Option::OPTION1::NONE) {
		return_str = cmdString + "," + to_string(recived_value->count);
		return;
	}

	int count = 0;
	return_str = "";
	for (auto iter = (recived_value->entity).begin(); iter != (recived_value->entity).end() && count < Option::LimitCount; iter++) {
		if(iter != (recived_value->entity).begin())
			return_str += "\n";
		return_str += cmdString + "," + (iter)->second.EmpNo_ + "," + (iter)->second.Name_ + "," + (iter)->second.Career_level_ + "," + (iter)->second.Phone_number_ + "," + (iter)->second.BirthDay_ + "," + (iter)->second.Certi_;
		count++;
	}
}

void Parser::parse(string& return_str, const string input_txt)
{	
	vector<string> tokens;
	Option::stringTokenize(tokens, input_txt, ',');

	request_management(return_str, tokens);
}
