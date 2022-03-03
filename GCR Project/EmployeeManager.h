#pragma once
#include <iostream>
#include <string>
#include <map>
#include "Employee.h"


class EmployeeManager {
public:
	//[Add]
	void Add(const Employee& employee);
	int GetEmployeeSize(void);

	//[Modify]
	std::map<int, Employee> ModifyByFirstName(std::string column, std::string value, std::string tagetValue);
	std::map<int, Employee> ModifyByLastName(std::string column, std::string value, std::string tagetValue);
	std::map<int, Employee> ModifyByPhoneMidNumber(std::string column, std::string value, std::string tagetValue);
	std::map<int, Employee> ModifyByPhoneLastNumber(std::string column, std::string value, std::string tagetValue);
	std::map<int, Employee> ModifyByBirthYear(std::string column, std::string value, std::string tagetValue);
	std::map<int, Employee> ModifyByBirthMonth(std::string column, std::string value, std::string tagetValue);
	std::map<int, Employee> ModifyByBirthDay(std::string column, std::string value, std::string tagetValue);

	//[Delelte]
	std::map<int, Employee> DeleteByFirstName(std::string column, std::string value);
	std::map<int, Employee> DeleteByLastName(std::string column, std::string value);
	std::map<int, Employee> DeleteByPhoneMidNumber(std::string column, std::string value);
	std::map<int, Employee> DeleteByPhoneLastNumber(std::string column, std::string value);
	std::map<int, Employee> DeleteByBirthYear(std::string column, std::string value);
	std::map<int, Employee> DeleteByBirthMonth(std::string column, std::string value);
	std::map<int, Employee> DeleteByBirthDay(std::string column, std::string value);

	//[Search]
	std::map<int, Employee> SearchByFirstName(std::string column, std::string value);
	std::map<int, Employee> SearchByLastName(std::string column, std::string value);
	std::map<int, Employee> SearchByPhoneMidNumber(std::string column, std::string value);
	std::map<int, Employee> SearchByPhoneLastNumber(std::string column, std::string value);
	std::map<int, Employee> SearchByBirthYear(std::string column, std::string value);
	std::map<int, Employee> SearchByBirthMonth(std::string column, std::string value);
	std::map<int, Employee> SearchByBirthDay(std::string column, std::string value);

private:
	//다음 result 전달을 위해 기존 결과 clear, 호출 타이밍은?
	void clearResults() { m_Results.clear(); };
	//DEL,MOD,SCH용 적용될 db의 record를 검색하는 내부함수, 이름은 일단 간단히 정함.
	std::map<int, Employee> search(std::string column, std::string value);

	std::map<int, Employee> m_Employees;
	std::map<int, Employee> m_Results;
};