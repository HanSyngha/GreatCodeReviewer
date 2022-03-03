#include "EmployeeManager.h"

#include <iostream>
#include <sstream>
#include <vector>

//[Add]
void EmployeeManager::Add(const Employee& employee) {

}

std::map<int, Employee> EmployeeManager::ModifyWithNoOption(std::string column, std::string value, std::string tagetValue)
{
	return std::map<int, Employee>();
}

//[Modify]
std::map<int, Employee> EmployeeManager::ModifyByFirstName(std::string column, std::string value, std::string tagetValue) {
	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::ModifyByLastName(std::string column, std::string value, std::string tagetValue) {
	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::ModifyByPhoneMidNumber(std::string column, std::string value, std::string tagetValue) {

	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::ModifyByPhoneLastNumber(std::string column, std::string value, std::string tagetValue) {

	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::ModifyByBirthYear(std::string column, std::string value, std::string tagetValue) {

	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::ModifyByBirthMonth(std::string column, std::string value, std::string tagetValue) {

	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::ModifyByBirthDay(std::string column, std::string value, std::string tagetValue) {

	return std::map<int, Employee>();
}

//TODO: parser�� �ʿ��� �۾��ϵ�, common����?
std::vector<std::string> splitString(const std::string& orgString, const char delimiter) {
	std::vector<std::string> tokens;
	std::istringstream strStream(orgString);
	std::string token;

	while (getline(strStream, token, delimiter)) {
		tokens.push_back(token);
	}

	return tokens;
}
//TODO: column�� parser�� ��� �Ѱ���� �ϳ�?
//[Delelte]
std::map<int, Employee> EmployeeManager::DeleteWithNoOption(std::string column, std::string value)
{
	clearResults();
	//TODO: refactoring �ʿ�
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
	//TODO: column�� ������ ����.
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
	//TODO: column�� ������ ����.
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
	//TODO: column�� ������ ����.
	clearResults();

	for (auto& dbInfo : m_Employees) {
		std::vector<std::string> tokens = splitString(dbInfo.second.Phone_number, '-');	//PhoneLast, PhoneMid�� �ֱ� �ϴ�.
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
	//TODO: column�� ������ ����.
	clearResults();

	for (auto& dbInfo : m_Employees) {
		std::vector<std::string> tokens = splitString(dbInfo.second.Phone_number, '-');	//PhoneLast, PhoneMid�� �ֱ� �ϴ�.
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
	//TODO: column�� ������ ����.
	clearResults();

	for (auto& dbInfo : m_Employees) {
		if (dbInfo.second.BirthYear == value) {
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
	//TODO: column�� ������ ����.
	clearResults();

	for (auto& dbInfo : m_Employees) {
		if (dbInfo.second.BirthMonth == value) {
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
	//TODO: column�� ������ ����.
	clearResults();

	for (auto& dbInfo : m_Employees) {
		if (dbInfo.second.BirthDay == value) {
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
	//TODO: refactoring �ʿ�
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
	//TODO: column�� ������ ����.
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
	//TODO: column�� ������ ����.
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
	//TODO: column�� ������ ����.
	clearResults();

	for (auto& dbInfo : m_Employees) {
		std::vector<std::string> tokens = splitString(dbInfo.second.Phone_number, '-');	//PhoneLast, PhoneMid�� �ֱ� �ϴ�.
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
	//TODO: column�� ������ ����.
	clearResults();

	for (auto& dbInfo : m_Employees) {
		std::vector<std::string> tokens = splitString(dbInfo.second.Phone_number, '-');	//PhoneLast, PhoneMid�� �ֱ� �ϴ�.
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
	//TODO: column�� ������ ����.
	clearResults();

	for (auto& dbInfo : m_Employees) {
		if (dbInfo.second.BirthYear == value) {
			m_Results[dbInfo.first] = dbInfo.second;
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::SearchByBirthMonth(std::string column, std::string value) {
	//TODO: column�� ������ ����.
	clearResults();

	for (auto& dbInfo : m_Employees) {
		if (dbInfo.second.BirthMonth == value) {
			m_Results[dbInfo.first] = dbInfo.second;
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}
std::map<int, Employee> EmployeeManager::SearchByBirthDay(std::string column, std::string value) {
	//TODO: column�� ������ ����.
	clearResults();

	for (auto& dbInfo : m_Employees) {
		if (dbInfo.second.BirthDay == value) {
			m_Results[dbInfo.first] = dbInfo.second;
		}
		else {
			//TODO: throw invalid operation
		}
	}
	return m_Results;
}


