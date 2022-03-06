#include "common.h"

#include <sstream>

using namespace std;

vector<string> stringTokenize(const std::string& orgString, const char delimiter) {
	vector<string> tokens;
	istringstream sstring(orgString);
	string token;

	while (getline(sstring, token, delimiter)) {
		tokens.push_back(token);
	}

	return tokens;
}

void fillOptionCommand(Option& option, string token) {
	if (token == "ADD") option.cmd = COMMAND::ADD;
	else if (token == "DEL") option.cmd = COMMAND::DEL;
	else if (token == "SCH") option.cmd = COMMAND::SCH;
	else if (token == "MOD") option.cmd = COMMAND::MOD;
	else throw runtime_error("ERROR:: invalid COMMAND!");
}

void fillOption1(Option& option, string token) {
	if (token == "-p") option.op1 = OPTION1::P;
	else option.op1 = OPTION1::NONE;
}

void fillOption2(Option& option, string token) {
	if (token == "-f") {
		option.op2 = OPTION2::FIRST_NAME;
	}
	else if (token == "-l") {
		if (option.searchColumn == COLUMN::PHONENUM) option.op2 = OPTION2::LAST_NUMBER;
		else if (option.searchColumn == COLUMN::NAME) option.op2 = OPTION2::LAST_NAME;
		else throw runtime_error("ERROR:: no matching column type!!");
	}
	else if (token == "-m") {
		if (option.searchColumn == COLUMN::PHONENUM) option.op2 = OPTION2::MID_NUMBER;
		else if (option.searchColumn == COLUMN::BIRTHDAY) option.op2 = OPTION2::MONTH;
		else throw runtime_error("ERROR:: no matching column type!!");
	}
	else if (token == "-y") {
		option.op2 = OPTION2::YEAR;
	}
	else if (token == "-d") {
		option.op2 = OPTION2::DAY;
	}
	else if (token == " ") {
		option.op2 = OPTION2::NONE;
	}
	else {
		throw runtime_error("ERROR:: invalid option string!!");
	}
}

void fillColumn(Option& option, string token, bool isSearch) {
	if (token == "employeeNum") {
		if (isSearch) option.searchColumn = COLUMN::EMPLOYEENUM;
		else option.changeColumn = COLUMN::EMPLOYEENUM;
	}
	else if (token == "name") {
		if (isSearch) option.searchColumn = COLUMN::NAME;
		else option.changeColumn = COLUMN::NAME;
	}
	else if (token == "cl") {
		if (isSearch) option.searchColumn = COLUMN::CL;
		else option.changeColumn = COLUMN::CL;
	}
	else if (token == "phoneNum") {
		if (isSearch) option.searchColumn = COLUMN::PHONENUM;
		else option.changeColumn = COLUMN::PHONENUM;
	}
	else if (token == "birthday") {
		if (isSearch) option.searchColumn = COLUMN::BIRTHDAY;
		else option.changeColumn = COLUMN::BIRTHDAY;
	}
	else if (token == "certi") {
		if (isSearch) option.searchColumn = COLUMN::CERTI;
		else option.changeColumn = COLUMN::CERTI;
	}
	else {
		throw runtime_error("ERROD:: column token is invalid!!");
	}
}

void fillSearchData(Option& option, string token) {
	option.searchData = token;
}

void fillChangeData(Option& option, string token) {
	option.changeData = token;
}

string getStringFromOptionCommand(const Option& option) {
	switch (option.cmd) {
	case COMMAND::ADD:
		return "ADD";
	case COMMAND::DEL:
		return "DEL";
	case COMMAND::SCH:
		return "SCH";
	case COMMAND::MOD:
		return "MOD";
	default:
		throw runtime_error("ERROR:: NONE case could not hit here!");
	}
}