#pragma once
#include <string>
#include <iostream>
#include <vector>

#include "Employee.h"

using namespace std;

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
	MOD,
};

struct Option {
	COMMAND cmd;
	OPTION1 op1;
	OPTION2 op2;
	//For ADD only
	Employee employee;
	//For DEL,SCH,MOD
	std::string searchColumn; // 이걸 string으로 할지, 아니면 정의된 enum등으로할지는 Parser와 맞춰야한다.
	std::string searchData;
	//For MOD only
	std::string changeColumn; // 이걸 string으로 할지, 아니면 정의된 enum등으로할지는 Parser와 맞춰야한다.
	std::string changeData;	
};

std::vector<std::string> stringTokenizer(const std::string & orgString, const char delimiter);