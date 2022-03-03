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
	std::string searchColumn; // �̰� string���� ����, �ƴϸ� ���ǵ� enum������������ Parser�� ������Ѵ�.
	std::string searchData;
	//For MOD only
	std::string changeColumn; // �̰� string���� ����, �ƴϸ� ���ǵ� enum������������ Parser�� ������Ѵ�.
	std::string changeData;	
};

std::vector<std::string> stringTokenizer(const std::string & orgString, const char delimiter);