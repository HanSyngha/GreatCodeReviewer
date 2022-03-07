#pragma once
#include "Employee.h"
#include "vector"
#include <sstream>

using namespace std;

class Option {
public:
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

public:
	Option() :
		cmd_(COMMAND::NONE),
		op1_(OPTION1::NONE),
		op2_(OPTION2::NONE)
	{}

	static void stringTokenize(vector<string>& tokens, const std::string& orgString, const char delimiter) {
		istringstream sstring(orgString);
		string token;

		while (getline(sstring, token, delimiter)) {
			tokens.push_back(token);
		}
	}

	void fillOptionCommand(string token);
	void fillOption1(string token);
	//void fillColumn(string token, bool isSearch);
	virtual	void fillOption2(string token) = 0;
	//void fillSearchData(string token);
	//void fillChangeData(string token);
	string getStringFromOptionCommand(void);

	bool isAddCommand() { return cmd_ == COMMAND::ADD; }
	COMMAND getCommand() { return cmd_; }

	OPTION1 getOption1() { return op1_; }
	OPTION2 getOption2() { return op2_; }


protected:
	COMMAND cmd_;
	OPTION1 op1_;
	OPTION2 op2_;
};

class AddOption : public Option {
public:
	AddOption(string token1, string token2, Employee& employee) {
		cmd_ = COMMAND::ADD;
		fillOption1(token1);
		fillOption2(token2);
		employee_ = employee;
	}
	virtual void fillOption2(string token) { op2_ = OPTION2::NONE; }
	Employee* getEmployee() { return &employee_; }
private:
	//For ADD only
	Employee employee_;
};

class ISchOption : public Option {
public:
	string getSearchData() { return searchData_; }
	COLUMN getSearchColumn() { return searchColumn_; }
	virtual void fillOption2(string token) override;
	void fillSearchData(string token) { searchData_ = token; }
	void fillColumn(string token, bool isSearch);
protected:
	//For DEL,SCH,MOD
	COLUMN searchColumn_;
	string searchData_;
	//For MOD only
	COLUMN changeColumn_;
};

class SchOption : public ISchOption {
public:
	SchOption(string token1, string token2, string search_column, string search_data) {
		cmd_ = COMMAND::SCH;
		fillOption1(token1);
		fillColumn(search_column, true);
		fillOption2(token2);
		fillSearchData(search_data);
	}
};

class ModOption : public ISchOption {
public:
	ModOption(string token1, string token2, string search_column, string search_data, string target_column, string target_data) {
		cmd_ = COMMAND::MOD;
		fillOption1(token1);
		fillColumn(search_column, true);
		fillOption2(token2);
		fillSearchData(search_data);
		fillColumn(target_column, false);
		fillChangeData(target_data);
	}

	void fillChangeData(string token) {	changeData_ = token; }
	COLUMN getChangeColumn() { return changeColumn_; }
	string getChangeData() { return changeData_; }
private:
	//For MOD only
	std::string changeData_;
};

class DelOption : public ISchOption {
public:
	DelOption(string token1, string token2, string search_column, string search_data) {
		cmd_ = COMMAND::DEL;
		fillOption1(token1);
		fillColumn(search_column, true);
		fillOption2(token2);
		fillSearchData(search_data);
	}
};