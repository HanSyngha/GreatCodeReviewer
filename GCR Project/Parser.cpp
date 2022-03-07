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

void Parser::request_add(const vector<string>& tokens) {
	map<int, Employee> results;
	Employee employee;
	employee.init(tokens[4], tokens[5], tokens[6], tokens[7], tokens[8], tokens[9]);
	AddOption option = AddOption(employee);

	//add
	employManager_.execute(&results, &option);
}

string Parser::request_del(const vector<string>& tokens) {
	string return_str;
	map<int, Employee>* recived_value;
	DelOption option = DelOption(tokens[4], tokens[5], tokens[2]);
	option.fillOption1(tokens[1]);

	//search
	recived_value = employManager_.search(&option);

	//execute with searched results
	employManager_.execute(recived_value, &option);
	
	return_str = make_return_str(recived_value, &option);
	return return_str;
}

string Parser::request_search(const vector<string>& tokens) {
	string return_str;
	map<int, Employee>* recived_value;
	SchOption option = SchOption(tokens[4], tokens[5], tokens[2]);
	option.fillOption1(tokens[1]);

	//search
	recived_value = employManager_.search(&option);

	return_str = make_return_str(recived_value, &option);
	return return_str;
}

string Parser::request_mod(const vector<string>& tokens) {
	string return_str;
	map<int, Employee>* recived_value;
	ModOption option = ModOption(tokens[4], tokens[5], tokens[6], tokens[7], tokens[2]);
	option.fillOption1(tokens[1]);

	//search
	recived_value = employManager_.search(&option);
	//execute with searched results
	employManager_.execute(recived_value, &option);
	
	return_str = make_return_str(recived_value, &option);
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

string Parser::make_return_str(const map<int, Employee>* recived_value, Option* option)
{
	string cmdString = option->getStringFromOptionCommand();
	if ((*recived_value).size() == 0) {
		return cmdString + ",NONE";
	}

	if (option->getOption1() == Option::OPTION1::NONE) {
		return cmdString + "," + to_string((*recived_value).size());
	}

	string return_str;
	int count = 0;
	for (auto iter = (*recived_value).begin(); iter != (*recived_value).end() && count < 5; iter++) {
		if(iter != (*recived_value).begin())
			return_str += "\n";
		return_str += cmdString + "," + (iter)->second.EmpNo_ + "," + (iter)->second.Name_ + "," + (iter)->second.Career_level_ + "," + (iter)->second.Phone_number_ + "," + (iter)->second.BirthDay_ + "," + (iter)->second.Certi_;
		count++;
	}

	return return_str;
}

string Parser::parse(const string input_txt)
{
	string return_str, recived_str;
	
	vector<string> tokens;
	Option::stringTokenize(tokens, input_txt, ',');

	recived_str = request_management(tokens);
	
	return recived_str;
}
