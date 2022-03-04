#pragma once
#include <iostream>
#include <string>
#include <map>
#include "Employee.h"


class EmployeeManager {
public:
	~EmployeeManager() {
		m_Employees.clear();
		m_Results.clear();
	}

	int GetEmployeeSize(void);
	void Add(const Employee& employee);
	void Modify(Employee& employee, std::string column, std::string value);

	std::map<int, Employee> ModifyWithNoOption(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue);
	std::map<int, Employee> ModifyByFirstName(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue);
	std::map<int, Employee> ModifyByLastName(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue);
	std::map<int, Employee> ModifyByPhoneMidNumber(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue);
	std::map<int, Employee> ModifyByPhoneLastNumber(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue);
	std::map<int, Employee> ModifyByBirthYear(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue);
	std::map<int, Employee> ModifyByBirthMonth(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue);
	std::map<int, Employee> ModifyByBirthDay(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue);
	
	std::map<int, Employee> DeleteWithNoOption(std::string column, std::string value);
	std::map<int, Employee> DeleteByFirstName(std::string column, std::string value);
	std::map<int, Employee> DeleteByLastName(std::string column, std::string value);
	std::map<int, Employee> DeleteByPhoneMidNumber(std::string column, std::string value);
	std::map<int, Employee> DeleteByPhoneLastNumber(std::string column, std::string value);
	std::map<int, Employee> DeleteByBirthYear(std::string column, std::string value);
	std::map<int, Employee> DeleteByBirthMonth(std::string column, std::string value);
	std::map<int, Employee> DeleteByBirthDay(std::string column, std::string value);

	std::map<int, Employee> SearchWithNoOption(std::string column, std::string value);
	std::map<int, Employee> SearchByFirstName(std::string column, std::string value);
	std::map<int, Employee> SearchByLastName(std::string column, std::string value);
	std::map<int, Employee> SearchByPhoneMidNumber(std::string column, std::string value);
	std::map<int, Employee> SearchByPhoneLastNumber(std::string column, std::string value);
	std::map<int, Employee> SearchByBirthYear(std::string column, std::string value);
	std::map<int, Employee> SearchByBirthMonth(std::string column, std::string value);
	std::map<int, Employee> SearchByBirthDay(std::string column, std::string value);

private:
	void clearResults() { m_Results.clear(); };

	std::map<int, Employee> m_Employees;
	std::map<int, Employee> m_Results;
};