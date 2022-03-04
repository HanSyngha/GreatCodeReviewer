#include "EmployeeManager.h"

#include <iostream>
#include <sstream>
#include <vector>


//TODO: parser도 필요한 작업일듯, common으로?
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
	//TODO: refactoring 필요
	for (auto& dbInfo : m_Employees) {
		if ((targetColumn == "empNo" && dbInfo.second.EmpNo == targetValue) ||
			(targetColumn == "cl" && dbInfo.second.Career_level == targetValue) ||
			(targetColumn == "certi" && dbInfo.second.Certi == targetValue)) {
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
	//TODO: column을 쓸일이 없다.
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
	
	//TODO: column을 쓸일이 없다.
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
	//TODO: column을 쓸일이 없다.
	clearResults();

	for (auto& dbInfo : m_Employees) {
		std::vector<std::string> tokens = splitString(dbInfo.second.Phone_number, '-');	//PhoneLast, PhoneMid도 있긴 하다.
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
	//TODO: column을 쓸일이 없다.
	clearResults();

	for (auto& dbInfo : m_Employees) {
		std::vector<std::string> tokens = splitString(dbInfo.second.Phone_number, '-');	//PhoneLast, PhoneMid도 있긴 하다.
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
	//TODO: column을 쓸일이 없다.
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
	//TODO: column을 쓸일이 없다.
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
	//TODO: column을 쓸일이 없다.
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

//TODO: column을 parser가 어떻게 넘겨줘야 하나?
//[Delelte]
std::map<int, Employee> EmployeeManager::DeleteWithNoOption(std::string column, std::string value)
{
	clearResults();
	//TODO: refactoring 필요
	auto iter = m_Employees.begin();
	while (iter != m_Employees.end()) {
		if ((column == "empNo" && (*iter).second.EmpNo == value) ||
			(column == "cl" && (*iter).second.Career_level == value) ||
			(column == "certi" && (*iter).second.Certi == value)) {
			m_Results[(*iter).first] = (*iter).second;
			m_Employees.erase((*iter++).first);
			continue;
		}
		iter++;
	}
	return m_Results; //copy values
}
std::map<int, Employee> EmployeeManager::DeleteByFirstName(std::string column, std::string value) {
	//TODO: column을 쓸일이 없다.
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
	//TODO: column을 쓸일이 없다.
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
	//TODO: column을 쓸일이 없다.
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
	//TODO: column을 쓸일이 없다.
	clearResults();

	auto iter = m_Employees.begin();
	while (iter != m_Employees.end()) {
		std::vector<std::string> tokens = splitString((*iter).second.Phone_number, '-');	//PhoneLast, PhoneMid도 있긴 하다.
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
	//TODO: column을 쓸일이 없다.
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
	//TODO: column을 쓸일이 없다.
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
	//TODO: column을 쓸일이 없다.
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
	//TODO: refactoring 필요
	for (auto& dbInfo : m_Employees) {
		if ((column == "empNo" && dbInfo.second.EmpNo == value) ||
			(column == "cl" && dbInfo.second.Career_level == value) ||
			(column == "certi" && dbInfo.second.Certi == value)) {
			m_Results[dbInfo.first] = dbInfo.second;
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results; //copy values
}
std::map<int, Employee> EmployeeManager::SearchByFirstName(std::string column, std::string value) {
	//TODO: column을 쓸일이 없다.
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
	//TODO: column을 쓸일이 없다.
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
	//TODO: column을 쓸일이 없다.
	clearResults();

	for (auto& dbInfo : m_Employees) {
		std::vector<std::string> tokens = splitString(dbInfo.second.Phone_number, '-');	//PhoneLast, PhoneMid도 있긴 하다.
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
	//TODO: column을 쓸일이 없다.
	clearResults();

	for (auto& dbInfo : m_Employees) {
		std::vector<std::string> tokens = splitString(dbInfo.second.Phone_number, '-');	//PhoneLast, PhoneMid도 있긴 하다.
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
	//TODO: column을 쓸일이 없다.
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
	//TODO: column을 쓸일이 없다.
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
	//TODO: column을 쓸일이 없다.
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


