#include "EmployeeManager.h"

#include <iostream>
#include <sstream>
#include <vector>

//[Add]
void EmployeeManager::Add(const Employee& employee) {
	m_Employees[Employee::makeKeyValueFromString(employee.EmpNo)] = employee;
}

int EmployeeManager::GetEmployeeSize() {
	return (int)m_Employees.size();
}

//[Modify]
std::map<int, Employee> EmployeeManager::ModifyWithNoOption(std::string column, std::string value, std::string tagetValue)
{
	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::ModifyByFirstName(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue) {
	
	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::ModifyByLastName(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue) {
	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::ModifyByPhoneMidNumber(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue) {

	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::ModifyByPhoneLastNumber(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue) {

	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::ModifyByBirthYear(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue) {

	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::ModifyByBirthMonth(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue) {

	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::ModifyByBirthDay(std::string targetColumn, std::string targetValue, std::string changeColumn, std::string changeValue) {

	return std::map<int, Employee>();
}

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
//TODO: column을 parser가 어떻게 넘겨줘야 하나?
//[Delelte]
std::map<int, Employee> EmployeeManager::DeleteWithNoOption(std::string column, std::string value)
{
	clearResults();
	//TODO: refactoring 필요
	for (auto& dbInfo : m_Employees) {
		if ((column == "empNo" && dbInfo.second.EmpNo == value) ||
			(column == "cl" && dbInfo.second.Career_level == value) ||
			(column == "certi" && dbInfo.second.Certi == value)) {
			m_Results[dbInfo.first] = dbInfo.second;
			m_Employees.erase(dbInfo.first);
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results; //copy values
}
std::map<int, Employee> EmployeeManager::DeleteByFirstName(std::string column, std::string value) {
	//TODO: column을 쓸일이 없다.
	clearResults();
	
	for (auto& dbInfo : m_Employees) {
		std::vector<std::string> tokens = splitString(dbInfo.second.Name, ' ');
		if (tokens[0] == value) {
			m_Results[dbInfo.first] = dbInfo.second;
			m_Employees.erase(dbInfo.first);
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::DeleteByLastName(std::string column, std::string value) {
	//TODO: column을 쓸일이 없다.
	clearResults();

	for (auto& dbInfo : m_Employees) {
		std::vector<std::string> tokens = splitString(dbInfo.second.Name, ' ');
		if (tokens[1] == value) {
			m_Results[dbInfo.first] = dbInfo.second;
			m_Employees.erase(dbInfo.first);
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::DeleteByPhoneMidNumber(std::string column, std::string value) {
	//TODO: column을 쓸일이 없다.
	clearResults();

	for (auto& dbInfo : m_Employees) {
		std::vector<std::string> tokens = splitString(dbInfo.second.Phone_number, '-');	//PhoneLast, PhoneMid도 있긴 하다.
		if (tokens[1] == value) {
			m_Results[dbInfo.first] = dbInfo.second;
			m_Employees.erase(dbInfo.first);
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::DeleteByPhoneLastNumber(std::string column, std::string value) {
	//TODO: column을 쓸일이 없다.
	clearResults();

	for (auto& dbInfo : m_Employees) {
		std::vector<std::string> tokens = splitString(dbInfo.second.Phone_number, '-');	//PhoneLast, PhoneMid도 있긴 하다.
		if (tokens[2] == value) {
			m_Results[dbInfo.first] = dbInfo.second;
			m_Employees.erase(dbInfo.first);
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::DeleteByBirthYear(std::string column, std::string value) {
	//TODO: column을 쓸일이 없다.
	clearResults();

	for (auto& dbInfo : m_Employees) {
		if (dbInfo.second.BirthDay.substr(0,3) == value) {
			m_Results[dbInfo.first] = dbInfo.second;
			m_Employees.erase(dbInfo.first);
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::DeleteByBirthMonth(std::string column, std::string value) {
	//TODO: column을 쓸일이 없다.
	clearResults();

	for (auto& dbInfo : m_Employees) {
		if (dbInfo.second.BirthDay.substr(4, 6) == value) {
			m_Results[dbInfo.first] = dbInfo.second;
			m_Employees.erase(dbInfo.first);
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::DeleteByBirthDay(std::string column, std::string value) {
	//TODO: column을 쓸일이 없다.
	clearResults();

	for (auto& dbInfo : m_Employees) {
		if (dbInfo.second.BirthDay.substr(7, 9) == value) {
			m_Results[dbInfo.first] = dbInfo.second;
			m_Employees.erase(dbInfo.first);
		}
		else {
			//TODO: throw invalid operation
		}
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
		if (dbInfo.second.BirthDay.substr(0, 3) == value) {
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
		if (dbInfo.second.BirthDay.substr(4, 6) == value) {
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
		if (dbInfo.second.BirthDay.substr(7, 9) == value) {
			m_Results[dbInfo.first] = dbInfo.second;
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}


