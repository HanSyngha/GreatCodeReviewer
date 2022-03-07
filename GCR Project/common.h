#pragma once
#include <string>
#include <iostream>
#include <vector>

#include "Employee.h"

enum class OPTION1 {
	NONE = 0, 
	P,
};

enum class OPTION2 { 
	NONE = 0,
	FIRST_NAME,
	LAST_NAME,
	MID_NUMBER,
	LAST_NUMBER,
	YEAR, 
	MONTH, 
	DAY,
};

enum class COMMAND { 
	NONE = 0,
	ADD,
	DEL,
	SCH,
	MOD
};

enum class COLUMN {
	NONE = 0,
	EMPLOYEENUM,
	NAME,
	CL,
	PHONENUM,
	BIRTHDAY,
	CERTI,
};

struct Option {
	COMMAND cmd;
	OPTION1 op1;
	OPTION2 op2;
	//For ADD only
	Employee employee;
	//For DEL,SCH,MOD
	COLUMN searchColumn;
	std::string searchData;
	//For MOD only
	COLUMN changeColumn;
	std::string changeData;	
};

std::vector<std::string> stringTokenize(const std::string & orgString, const char delimiter);
void fillOptionCommand(Option& option, std::string token);
void fillOption1(Option& option, std::string token);
void fillOption2(Option& option, std::string token);
void fillColumn(Option& option, std::string token, bool isSearch);
void fillSearchData(Option& option, std::string token);
void fillChangeData(Option& option, std::string token);
std::string getStringFromOptionCommand(const Option& option);