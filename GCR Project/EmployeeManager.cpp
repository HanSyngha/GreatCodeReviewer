#include "EmployeeManager.h"

using namespace std;

map<int, Employee> EmployeeNumSearcher::search(const Option& option) const {
	std::map<int, Employee> results;

	int keyVal = Employee::makeKeyValueFromString(option.searchData);
	if ((*pEmployees_).count(keyVal)) {
		results[keyVal] = (*pEmployees_)[keyVal];
	}

	return results;
}

map<int, Employee> NameSearcher::search(const Option& option) const {
	map<int, Employee> results;

	for (auto& employee : (*pEmployees_)) {
		if (option.searchData == getOption2String(employee.second.Name, option.op2)) {
			results[employee.first] = employee.second;
		}
	}

	return results;
}

string NameSearcher::getOption2String(const string& name, const OPTION2 option) const {
	if (option == OPTION2::NONE) {
		return name;
	}

	vector<string> tokens = stringTokenize(name, ' ');
	if (tokens.size() != 2) {
		throw std::runtime_error("ERROR:: invalid name format!");
	}

	if (option == OPTION2::FIRST_NAME) {
		return tokens[0];
	}
	else if (option == OPTION2::LAST_NAME) {
		return tokens[1];
	}
	else {
		throw std::runtime_error("ERROR:: invalid option!!");
	}
}

map<int, Employee> ClSearcher::search(const Option& option) const {
	map<int, Employee> results;

	for (auto& employee : (*pEmployees_)) {
		if (option.searchData == employee.second.Career_level) {
			results[employee.first] = employee.second;
		}
	}

	return results;
}

map<int, Employee> PhoneNumSearcher::search(const Option& option) const {
	map<int, Employee> results;

	for (auto& employee : (*pEmployees_)) {
		if (option.searchData == getOption2String(employee.second.Phone_number, option.op2)) {
			results[employee.first] = employee.second;
		}
	}

	return results;
}

string PhoneNumSearcher::getOption2String(const string& name, const OPTION2 option) const {
	if (option == OPTION2::NONE) {
		return name;
	}

	vector<std::string> tokens = stringTokenize(name, '-');
	if (tokens.size() != 3) {
		throw std::runtime_error("ERROR:: invalid phone number format!");
	}

	if (option == OPTION2::MID_NUMBER) {
		return tokens[1];
	}
	else if (option == OPTION2::LAST_NUMBER) {
		return tokens[2];
	}
	else {
		throw std::runtime_error("ERROR:: invalid option!!");
	}
}

map<int, Employee> BirthdaySearcher::search(const Option& option) const {
	map<int, Employee> results;

	for (auto& employee : (*pEmployees_)) {
		if (option.searchData == getOption2String(employee.second.BirthDay, option.op2)) {
			results[employee.first] = employee.second;
		}
	}

	return results;
}

string BirthdaySearcher::getOption2String(const string& name, const OPTION2 option) const {
	if (option == OPTION2::NONE) {
		return name;
	}

	if (name.length() != 8) {
		throw std::runtime_error("ERROR:: invalid birthday format!");
	}

	if (option == OPTION2::YEAR) {
		return name.substr(0, 4);
	}
	else if (option == OPTION2::MONTH) {
		return name.substr(4, 2);
	}
	else if (option == OPTION2::DAY) {
		return name.substr(6, 2);
	}
	else {
		throw std::runtime_error("ERROR:: invalid option!!");
	}
}

map<int, Employee> CertiSearcher::search(const Option& option) const {
	map<int, Employee> results;

	for (auto& employee : (*pEmployees_)) {
		if (option.searchData == employee.second.Certi) {
			results[employee.first] = employee.second;
		}
	}

	return results;
}

FactorySearcher::FactorySearcher(std::map<int, Employee>* pEmployees) {
	pEmployeeNumSearcher_ = new EmployeeNumSearcher(pEmployees);
	pNameSearcher_ = new NameSearcher(pEmployees);
	pClSearcher_ = new ClSearcher(pEmployees);
	pPhoneNumSearcher_ = new PhoneNumSearcher(pEmployees);
	pBirthdaySearcher_ = new BirthdaySearcher(pEmployees);
	pCertiSearcher_ = new CertiSearcher(pEmployees);
}
FactorySearcher::~FactorySearcher() {
	if (pEmployeeNumSearcher_) {
		delete pEmployeeNumSearcher_;
	}
	if (pNameSearcher_) {
		delete pNameSearcher_;
	}
	if (pClSearcher_) {
		delete pClSearcher_;
	}
	if (pPhoneNumSearcher_) {
		delete pPhoneNumSearcher_;
	}
	if (pBirthdaySearcher_) {
		delete pBirthdaySearcher_;
	}
	if (pCertiSearcher_) {
		delete pCertiSearcher_;
	}
}

Searcher* FactorySearcher::getConcreteSearcher(const Option& option) const {
	Searcher* pSearcher;

	if (option.cmd == COMMAND::ADD) {
		return pEmployeeNumSearcher_;
	} 
	switch (option.searchColumn) {
	case COLUMN::EMPLOYEENUM:
		pSearcher = pEmployeeNumSearcher_;
		break;
	case COLUMN::NAME:
		pSearcher = pNameSearcher_;
		break;
	case COLUMN::CL:
		pSearcher = pClSearcher_;
		break;
	case COLUMN::PHONENUM:
		pSearcher = pPhoneNumSearcher_;
		break;
	case COLUMN::BIRTHDAY:
		pSearcher = pBirthdaySearcher_;
		break;
	case COLUMN::CERTI:
		pSearcher = pCertiSearcher_;
		break;
	default:
		throw std::runtime_error("ERROR:: Invalid column name?");
	}

	return pSearcher;
}

map<int, Employee> AddExecutor::execute(const map<int, Employee>* pSearchResult, const Option& option) {
	map<int, Employee> results;
	int key = Employee::makeKeyValueFromString(option.employee.EmpNo);

	if (pSearchResult->size() != 0) {
		throw runtime_error("ERROR:: Data already exists!");
		return results;
	}	
	(*pEmployees_)[key] = option.employee;
	results[key] = option.employee;

	return results;
}

map<int, Employee> DeleteExecutor::execute(const map<int, Employee>* pSearchResult, const Option& option) {
	map<int, Employee> results;

	for (const auto& employee : (*pSearchResult)) {
		results[employee.first] = employee.second;
		(*pEmployees_).erase(employee.first);
	}
	return results;
}

map<int, Employee> ModifyExecutor::execute(const std::map<int, Employee>* pSearchResult, const Option& option) {
	map<int, Employee> results;
	for (const auto& employee : (*pSearchResult)) {
		results[employee.first] = employee.second;

		switch (option.changeColumn) {
		case COLUMN::NAME:
			(*pEmployees_)[employee.first].Name = option.changeData;
			break;
		case COLUMN::CL:
			(*pEmployees_)[employee.first].Career_level = option.changeData;
			break;
		case COLUMN::PHONENUM:
			(*pEmployees_)[employee.first].Phone_number = option.changeData;
			break;
		case COLUMN::BIRTHDAY:
			(*pEmployees_)[employee.first].BirthDay = option.changeData;
			break;
		case COLUMN::CERTI:
			(*pEmployees_)[employee.first].Certi = option.changeData;
			break;
		default:
			throw runtime_error("ERROR:: change column type is invalid!!");
		}
	}
	return results;
}

FactoryExecutor::FactoryExecutor(std::map<int, Employee>* pEmployees) {
	m_pAddExecutor_ = new AddExecutor(pEmployees);
	m_pDelExecutor_ = new DeleteExecutor(pEmployees);
	m_pModExecutor_ = new ModifyExecutor(pEmployees);
};
FactoryExecutor::~FactoryExecutor() {
	if (m_pAddExecutor_) {
		delete m_pAddExecutor_;
	}
	if (m_pDelExecutor_) {
		delete m_pDelExecutor_;
	}
	if (m_pModExecutor_) {
		delete m_pModExecutor_;
	}
}
Executor* FactoryExecutor::getConcreteExecutor(const Option& option) {
	Executor* pExecutor = nullptr;
	switch (option.cmd)
	{
	case COMMAND::ADD:
		pExecutor = m_pAddExecutor_;
		break;
	case COMMAND::DEL:
		pExecutor = m_pDelExecutor_;
		break;
	case COMMAND::MOD:
		pExecutor = m_pModExecutor_;
		break;
	}
	return pExecutor;
};

map<int, Employee> EmployeeManager::search(const Option& option) {
	clearResults();
	Searcher* pSearcher = m_SearcherFactory->getConcreteSearcher(option);
	if (pSearcher == nullptr)
		throw runtime_error("ERROR:: Proper Searcher not found!!");

	m_Results = pSearcher->search(option);

	return m_Results;
}

map<int, Employee> EmployeeManager::execute(const std::map<int, Employee>* searchRecords, const Option& option) {
	clearResults();
	Executor* pExecutor = m_ExecutorFactory->getConcreteExecutor(option);
	if (pExecutor == nullptr)
		throw runtime_error("ERROR:: Proper Executor not found!!");

	m_Results = pExecutor->execute(searchRecords, option);

	return m_Results;
}