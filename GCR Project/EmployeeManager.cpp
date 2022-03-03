#include "EmployeeManager.h"

//[Add]
void EmployeeManager::Add(const Employee& employee) {
	m_Employees[Employee::makeKeyValueFromString(employee.EmpNo)] = employee;
}

int EmployeeManager::GetEmployeeSize() {
	return (int)m_Employees.size();
}



//[Modify]
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

//[Delelte]
std::map<int, Employee> EmployeeManager::DeleteByFirstName(std::string column, std::string value) {

	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::DeleteByLastName(std::string column, std::string value) {

	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::DeleteByPhoneMidNumber(std::string column, std::string value) {

	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::DeleteByPhoneLastNumber(std::string column, std::string value) {

	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::DeleteByBirthYear(std::string column, std::string value) {

	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::DeleteByBirthMonth(std::string column, std::string value) {

	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::DeleteByBirthDay(std::string column, std::string value) {

	return std::map<int, Employee>();
}

//[Search]
std::map<int, Employee> EmployeeManager::SearchByFirstName(std::string column, std::string value) {

	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::SearchByLastName(std::string column, std::string value) {

	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::SearchByPhoneMidNumber(std::string column, std::string value) {

	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::SearchByPhoneLastNumber(std::string column, std::string value) {

	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::SearchByBirthYear(std::string column, std::string value) {

	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::SearchByBirthMonth(std::string column, std::string value) {

	return std::map<int, Employee>();
}
std::map<int, Employee> EmployeeManager::SearchByBirthDay(std::string column, std::string value) {

	return std::map<int, Employee>();
}