#include "Option.h"

using namespace std;

void Option::fillOptionCommand(string token) {
	if (token == "ADD") cmd_ = COMMAND::ADD;
	else if (token == "DEL") cmd_ = COMMAND::DEL;
	else if (token == "SCH") cmd_ = COMMAND::SCH;
	else if (token == "MOD") cmd_ = COMMAND::MOD;
	else throw runtime_error("ERROR:: invalid COMMAND!");
}

void Option::fillOption1(string token) {
	if (token == "-p") op1_ = OPTION1::P;
	else op1_ = OPTION1::NONE;
}

void ISchOption::fillOption2(string token) {
	if (token == "-f") {
		op2_ = OPTION2::FIRST_NAME;
	}
	else if (token == "-l") {
		if (searchColumn_ == COLUMN::PHONENUM) op2_ = OPTION2::LAST_NUMBER;
		else if (searchColumn_ == COLUMN::NAME) op2_ = OPTION2::LAST_NAME;
		else throw runtime_error("ERROR:: no matching column type!!");
	}
	else if (token == "-m") {
		if (searchColumn_ == COLUMN::PHONENUM) op2_ = OPTION2::MID_NUMBER;
		else if (searchColumn_ == COLUMN::BIRTHDAY) op2_ = OPTION2::MONTH;
		else throw runtime_error("ERROR:: no matching column type!!");
	}
	else if (token == "-y") {
		op2_ = OPTION2::YEAR;
	}
	else if (token == "-d") {
		op2_ = OPTION2::DAY;
	}
	else if (token == " ") {
		op2_ = OPTION2::NONE;
	}
	else {
		throw runtime_error("ERROR:: invalid option string!!");
	}
}

void ISchOption::fillColumn(string token, bool isSearch) {
	if (token == "employeeNum") {
		if (isSearch) searchColumn_ = COLUMN::EMPLOYEENUM;
		else changeColumn_ = COLUMN::EMPLOYEENUM;
	}
	else if (token == "name") {
		if (isSearch) searchColumn_ = COLUMN::NAME;
		else changeColumn_ = COLUMN::NAME;
	}
	else if (token == "cl") {
		if (isSearch) searchColumn_ = COLUMN::CL;
		else changeColumn_ = COLUMN::CL;
	}
	else if (token == "phoneNum") {
		if (isSearch) searchColumn_ = COLUMN::PHONENUM;
		else changeColumn_ = COLUMN::PHONENUM;
	}
	else if (token == "birthday") {
		if (isSearch) searchColumn_ = COLUMN::BIRTHDAY;
		else changeColumn_ = COLUMN::BIRTHDAY;
	}
	else if (token == "certi") {
		if (isSearch) searchColumn_ = COLUMN::CERTI;
		else changeColumn_ = COLUMN::CERTI;
	}
	else {
		throw runtime_error("ERROD:: column token is invalid!!");
	}
}

string Option::getStringFromOptionCommand(void) {
	switch (cmd_) {
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
