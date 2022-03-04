#include "EmployeeManager.h"

#include <iostream>
#include <sstream>
#include <vector>

std::vector<std::string> splitString(const std::string& orgString, const char delimiter) {
	std::vector<std::string> tokens;
	std::istringstream strStream(orgString);
	std::string token;

	while (getline(strStream, token, delimiter)) {
		tokens.push_back(token);
	}

	return tokens;
}

//[Add]
void EmployeeManager::Add(const Employee& employee) {
	m_Employees[Employee::makeKeyValueFromString(employee.EmpNo)] = employee;
}

int EmployeeManager::GetEmployeeSize() {
	return (int)m_Employees.size();
}

//[Modify]
std::map<int, Employee> EmployeeManager::ModifyWithNoOption(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue)
{
	clearResults();

	for (auto& dbInfo : m_Employees) {
		if ((targetColumn == "employeeNum" && dbInfo.second.EmpNo == targetValue) ||
			(targetColumn == "cl" && dbInfo.second.Career_level == targetValue) ||
			(targetColumn == "certi" && dbInfo.second.Certi == targetValue) ||
			(targetColumn == "name" && dbInfo.second.Name == targetValue) ||
			(targetColumn == "phoneNum" && dbInfo.second.Phone_number == targetValue) ||
			(targetColumn == "birthday" && dbInfo.second.BirthDay == targetValue)			
			) {
			m_Results[dbInfo.first] = dbInfo.second;
			Modify(dbInfo.second, changeColumn, changeValue);
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results; //copy values
}

void EmployeeManager::Modify(Employee& employee, std::string column, std::string value) {
	if (column == "employeeNum")
		employee.EmpNo = value;
	else if (column == "name")
		employee.Name = value;
	else if (column == "cl")
		employee.Career_level = value;
	else if (column == "phoneNum")
		employee.Phone_number = value;
	else if (column == "birthday")
		employee.BirthDay = value;
	else if (column == "certi")
		employee.Certi = value;
}

std::map<int, Employee> EmployeeManager::ModifyByFirstName(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue) {
	clearResults();

	for (auto& dbInfo : m_Employees) {
		std::vector<std::string> tokens = splitString(dbInfo.second.Name, ' ');
		if (tokens[0] == targetValue) {
			m_Results[dbInfo.first] = dbInfo.second;
			Modify(dbInfo.second, changeColumn, changeValue);
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;	
}

std::map<int, Employee> EmployeeManager::ModifyByLastName(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue) {
	clearResults();

	for (auto& dbInfo : m_Employees) {
		std::vector<std::string> tokens = splitString(dbInfo.second.Name, ' ');
		if (tokens[1] == targetValue) {
			m_Results[dbInfo.first] = dbInfo.second;
			Modify(dbInfo.second, changeColumn, changeValue);
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::ModifyByPhoneMidNumber(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue) {
	clearResults();

	for (auto& dbInfo : m_Employees) {
		std::vector<std::string> tokens = splitString(dbInfo.second.Phone_number, '-');
		if (tokens[1] == targetValue) {
			m_Results[dbInfo.first] = dbInfo.second;
			Modify(dbInfo.second, changeColumn, changeValue);
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::ModifyByPhoneLastNumber(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue) {
	clearResults();

	for (auto& dbInfo : m_Employees) {
		std::vector<std::string> tokens = splitString(dbInfo.second.Phone_number, '-');
		if (tokens[2] == targetValue) {
			m_Results[dbInfo.first] = dbInfo.second;
			Modify(dbInfo.second, changeColumn, changeValue);
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::ModifyByBirthYear(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue) {
	clearResults();

	for (auto& dbInfo : m_Employees) {
		if (dbInfo.second.BirthDay.substr(0, 4) == targetValue) {
			m_Results[dbInfo.first] = dbInfo.second;
			Modify(dbInfo.second, changeColumn, changeValue);
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::ModifyByBirthMonth(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue) {
	clearResults();

	for (auto& dbInfo : m_Employees) {
		if (dbInfo.second.BirthDay.substr(4, 2) == targetValue) {
			m_Results[dbInfo.first] = dbInfo.second;
			Modify(dbInfo.second, changeColumn, changeValue);
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::ModifyByBirthDay(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue) {
	clearResults();

	for (auto& dbInfo : m_Employees) {
		if (dbInfo.second.BirthDay.substr(6, 2) == targetValue) {
			m_Results[dbInfo.first] = dbInfo.second;
			Modify(dbInfo.second, changeColumn, changeValue);
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}

//[Delelte]
std::map<int, Employee> EmployeeManager::DeleteWithNoOption(std::string column, std::string value)
{
	clearResults();

	auto iter = m_Employees.begin();
	while (iter != m_Employees.end()) {
		if ((column == "employeeNum" && (*iter).second.EmpNo == value) ||
			(column == "cl" && (*iter).second.Career_level == value) ||
			(column == "certi" && (*iter).second.Certi == value) ||
			(column == "name" && (*iter).second.Name == value) ||
			(column == "phoneNum" && (*iter).second.Phone_number == value) ||
			(column == "birthday" && (*iter).second.BirthDay == value)) {
			m_Results[(*iter).first] = (*iter).second;
			m_Employees.erase((*iter++).first);
			continue;
		}
		iter++;
	}
	return m_Results; //copy values
}
std::map<int, Employee> EmployeeManager::DeleteByFirstName(std::string column, std::string value) {
	clearResults();
	
	auto iter = m_Employees.begin();
	while (iter != m_Employees.end()) {
		std::vector<std::string> tokens = splitString((*iter).second.Name, ' ');
		if (tokens[0] == value) {
			m_Results[(*iter).first] = (*iter).second;
			m_Employees.erase((*iter++).first);
			continue;
		}
		iter++;		
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::DeleteByLastName(std::string column, std::string value) {
	clearResults();

	auto iter = m_Employees.begin();
	while (iter != m_Employees.end()) {
		std::vector<std::string> tokens = splitString((*iter).second.Name, ' ');
		if (tokens[1] == value) {
			m_Results[(*iter).first] = (*iter).second;
			m_Employees.erase((*iter++).first);
			continue;
		}
		iter++;
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::DeleteByPhoneMidNumber(std::string column, std::string value) {
	clearResults();

	auto iter = m_Employees.begin();
	while (iter != m_Employees.end()) {
		std::vector<std::string> tokens = splitString((*iter).second.Phone_number, '-');
		if (tokens[1] == value) {
			m_Results[(*iter).first] = (*iter).second;
			m_Employees.erase((*iter++).first);
			continue;
		}
		iter++;
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::DeleteByPhoneLastNumber(std::string column, std::string value) {
	clearResults();

	auto iter = m_Employees.begin();
	while (iter != m_Employees.end()) {
		std::vector<std::string> tokens = splitString((*iter).second.Phone_number, '-');
		if (tokens[2] == value) {
			m_Results[(*iter).first] = (*iter).second;
			m_Employees.erase((*iter++).first);
			continue;
		}
		iter++;
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::DeleteByBirthYear(std::string column, std::string value) {
	clearResults();

	auto iter = m_Employees.begin();
	while (iter != m_Employees.end()) {
		if ((*iter).second.BirthDay.substr(0, 4) == value) {
			m_Results[(*iter).first] = (*iter).second;
			m_Employees.erase((*iter++).first);
			continue;
		}
		iter++;
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::DeleteByBirthMonth(std::string column, std::string value) {
	clearResults();

	auto iter = m_Employees.begin();
	while (iter != m_Employees.end()) {
		if ((*iter).second.BirthDay.substr(4, 2) == value) {
			m_Results[(*iter).first] = (*iter).second;
			m_Employees.erase((*iter++).first);
			continue;
		}
		iter++;
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::DeleteByBirthDay(std::string column, std::string value) {
	clearResults();

	auto iter = m_Employees.begin();
	while (iter != m_Employees.end()) {
		if ((*iter).second.BirthDay.substr(6, 2) == value) {
			m_Results[(*iter).first] = (*iter).second;
			m_Employees.erase((*iter++).first);
			continue;
		}
		iter++;
	}
	return m_Results;
}

//[Search]
std::map<int, Employee> EmployeeManager::SearchWithNoOption(std::string column, std::string value)
{
	clearResults();

	for (auto& dbInfo : m_Employees) {
		if ((column == "employeeNum" && dbInfo.second.EmpNo == value) ||
			(column == "cl" && dbInfo.second.Career_level == value) ||
			(column == "certi" && dbInfo.second.Certi == value) ||
			(column == "name" && dbInfo.second.Name == value) ||
			(column == "phoneNum" && dbInfo.second.Phone_number == value) ||
			(column == "birthday" && dbInfo.second.BirthDay == value)) {
			m_Results[dbInfo.first] = dbInfo.second;
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results; //copy values
}
std::map<int, Employee> EmployeeManager::SearchByFirstName(std::string column, std::string value) {
	clearResults();

	for (auto& dbInfo : m_Employees) {
		std::vector<std::string> tokens = splitString(dbInfo.second.Name, ' ');
		if (tokens[0] == value) {
			m_Results[dbInfo.first] = dbInfo.second;
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::SearchByLastName(std::string column, std::string value) {
	clearResults();

	for (auto& dbInfo : m_Employees) {
		std::vector<std::string> tokens = splitString(dbInfo.second.Name, ' ');
		if (tokens[1] == value) {
			m_Results[dbInfo.first] = dbInfo.second;
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::SearchByPhoneMidNumber(std::string column, std::string value) {
	clearResults();

	for (auto& dbInfo : m_Employees) {
		std::vector<std::string> tokens = splitString(dbInfo.second.Phone_number, '-');	
		if (tokens[1] == value) {
			m_Results[dbInfo.first] = dbInfo.second;
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::SearchByPhoneLastNumber(std::string column, std::string value) {
	clearResults();

	for (auto& dbInfo : m_Employees) {
		std::vector<std::string> tokens = splitString(dbInfo.second.Phone_number, '-');
		if (tokens[2] == value) {
			m_Results[dbInfo.first] = dbInfo.second;
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::SearchByBirthYear(std::string column, std::string value) {
	clearResults();

	for (auto& dbInfo : m_Employees) {
		if (dbInfo.second.BirthDay.substr(0, 4) == value) {
			m_Results[dbInfo.first] = dbInfo.second;
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::SearchByBirthMonth(std::string column, std::string value) {
	clearResults();

	for (auto& dbInfo : m_Employees) {
		if (dbInfo.second.BirthDay.substr(4, 2) == value) {
			m_Results[dbInfo.first] = dbInfo.second;
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::SearchByBirthDay(std::string column, std::string value) {
	clearResults();

	for (auto& dbInfo : m_Employees) {
		if (dbInfo.second.BirthDay.substr(6, 2) == value) {
			m_Results[dbInfo.first] = dbInfo.second;
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}