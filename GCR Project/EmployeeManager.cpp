#include "EmployeeManager.h"

using namespace std;

map<int, Employee> EmployeeNumSearcher::search(Option* option) const {
	std::map<int, Employee> results;
	ISchOption* schOption = (ISchOption*)option;

	int keyVal = Employee::makeKeyValueFromString(schOption->getSearchData());
	if ((*pEmployees_).count(keyVal)) {
		results[keyVal] = (*pEmployees_)[keyVal];
	}

	return results;
}

map<int, Employee> NameSearcher::search(Option* option) const {
	map<int, Employee> results;
	ISchOption* schOption = (ISchOption*)option;

	for (auto& employee : (*pEmployees_)) {
		if (schOption->getSearchData() == getOption2String(employee.second.Name_, schOption->getOption2())) {
			results[employee.first] = employee.second;
		}
	}

	return results;
}

string NameSearcher::getOption2String(const string& name, const Option::OPTION2 option) const {
	if (option == Option::OPTION2::NONE) {
		return name;
	}

	vector<string> tokens;
	Option::stringTokenize(tokens, name, ' ');
	if (tokens.size() != 2) {
		throw std::runtime_error("ERROR:: invalid name format!");
	}

	if (option == Option::OPTION2::FIRST_NAME) {
		return tokens[0];
	}
	else if (option == Option::OPTION2::LAST_NAME) {
		return tokens[1];
	}
	else {
		throw std::runtime_error("ERROR:: invalid option!!");
	}
}

map<int, Employee> ClSearcher::search(Option* option) const {
	map<int, Employee> results;
	ISchOption* schOption = (ISchOption*)option;

	for (auto& employee : (*pEmployees_)) {
		if (schOption->getSearchData() == employee.second.Career_level_) {
			results[employee.first] = employee.second;
		}
	}

	return results;
}

map<int, Employee> PhoneNumSearcher::search(Option* option) const {
	map<int, Employee> results;
	ISchOption* schOption = (ISchOption*)option;

	for (auto& employee : (*pEmployees_)) {
		if (schOption->getSearchData() == getOption2String(employee.second.Phone_number_, schOption->getOption2())) {
			results[employee.first] = employee.second;
		}
	}

	return results;
}

string PhoneNumSearcher::getOption2String(const string& name, const Option::OPTION2 option) const {
	if (option == Option::OPTION2::NONE) {
		return name;
	}

	vector<std::string> tokens;
	Option::stringTokenize(tokens, name, '-');
	if (tokens.size() != 3) {
		throw std::runtime_error("ERROR:: invalid phone number format!");
	}

	if (option == Option::OPTION2::MID_NUMBER) {
		return tokens[1];
	}
	else if (option == Option::OPTION2::LAST_NUMBER) {
		return tokens[2];
	}
	else {
		throw std::runtime_error("ERROR:: invalid option!!");
	}
}

map<int, Employee> BirthdaySearcher::search(Option* option) const {
	map<int, Employee> results;
	ISchOption* schOption = (ISchOption*)option;

	for (auto& employee : (*pEmployees_)) {
		if (schOption->getSearchData() == getOption2String(employee.second.BirthDay_, schOption->getOption2())) {
			results[employee.first] = employee.second;
		}
	}

	return results;
}

string BirthdaySearcher::getOption2String(const string& name, const Option::OPTION2 option) const {
	if (option == Option::OPTION2::NONE) {
		return name;
	}

	if (name.length() != 8) {
		throw std::runtime_error("ERROR:: invalid birthday format!");
	}

	if (option == Option::OPTION2::YEAR) {
		return name.substr(0, 4);
	}
	else if (option == Option::OPTION2::MONTH) {
		return name.substr(4, 2);
	}
	else if (option == Option::OPTION2::DAY) {
		return name.substr(6, 2);
	}
	else {
		throw std::runtime_error("ERROR:: invalid option!!");
	}
}

map<int, Employee> CertiSearcher::search(Option* option) const {
	map<int, Employee> results;
	ISchOption* schOption = (ISchOption*)option;

	for (auto& employee : (*pEmployees_)) {
		if (schOption->getSearchData() == employee.second.Certi_) {
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

Searcher* FactorySearcher::getConcreteSearcher(Option* option) const {
	Searcher* pSearcher;
	ISchOption* schOption = (ISchOption*)option;
	if (schOption->getCommand() == Option::COMMAND::ADD) {
		return pEmployeeNumSearcher_;
	} 
	switch (schOption->getSearchColumn()) {
	case Option::COLUMN::EMPLOYEENUM:
		pSearcher = pEmployeeNumSearcher_;
		break;
	case Option::COLUMN::NAME:
		pSearcher = pNameSearcher_;
		break;
	case Option::COLUMN::CL:
		pSearcher = pClSearcher_;
		break;
	case Option::COLUMN::PHONENUM:
		pSearcher = pPhoneNumSearcher_;
		break;
	case Option::COLUMN::BIRTHDAY:
		pSearcher = pBirthdaySearcher_;
		break;
	case Option::COLUMN::CERTI:
		pSearcher = pCertiSearcher_;
		break;
	default:
		throw std::runtime_error("ERROR:: Invalid column name?");
	}

	return pSearcher;
}

map<int, Employee> AddExecutor::execute(const map<int, Employee>* pSearchResult, Option* option) {
	map<int, Employee> results;
	AddOption* addOption = (AddOption*)option;
	int key = Employee::makeKeyValueFromString(addOption->getEmployee()->EmpNo_);

	if (pSearchResult->size() != 0) {
		throw runtime_error("ERROR:: Data already exists!");
		return results;
	}	
	(*pEmployees_)[key] = *addOption->getEmployee();
	results[key] = *addOption->getEmployee();

	return results;
}

map<int, Employee> DeleteExecutor::execute(const map<int, Employee>* pSearchResult, Option* option) {
	map<int, Employee> results;

	for (const auto& employee : (*pSearchResult)) {
		results[employee.first] = employee.second;
		(*pEmployees_).erase(employee.first);
	}
	return results;
}

map<int, Employee> ModifyExecutor::execute(const std::map<int, Employee>* pSearchResult, Option* option) {
	map<int, Employee> results;
	ModOption* modOption = (ModOption*)option;
	for (const auto& employee : (*pSearchResult)) {
		results[employee.first] = employee.second;

		switch (modOption->getChangeColumn()) {
		case Option::COLUMN::NAME:
			(*pEmployees_)[employee.first].Name_ = modOption->getChangeData();
			break;
		case Option::COLUMN::CL:
			(*pEmployees_)[employee.first].Career_level_ = modOption->getChangeData();
			break;
		case Option::COLUMN::PHONENUM:
			(*pEmployees_)[employee.first].Phone_number_ = modOption->getChangeData();
			break;
		case Option::COLUMN::BIRTHDAY:
			(*pEmployees_)[employee.first].BirthDay_ = modOption->getChangeData();
			break;
		case Option::COLUMN::CERTI:
			(*pEmployees_)[employee.first].Certi_ = modOption->getChangeData();
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
Executor* FactoryExecutor::getConcreteExecutor(Option* option) {
	Executor* pExecutor = nullptr;
	switch (option->getCommand())
	{
	case Option::COMMAND::ADD:
		pExecutor = m_pAddExecutor_;
		break;
	case Option::COMMAND::DEL:
		pExecutor = m_pDelExecutor_;
		break;
	case Option::COMMAND::MOD:
		pExecutor = m_pModExecutor_;
		break;
	}
	return pExecutor;
};

map<int, Employee> EmployeeManager::search(Option* option) {
	Searcher* pSearcher = m_SearcherFactory->getConcreteSearcher(option);
	if (pSearcher == nullptr)
		throw runtime_error("ERROR:: Proper Searcher not found!!");

	return pSearcher->search(option);
}

map<int, Employee> EmployeeManager::execute(const std::map<int, Employee>* searchRecords, Option* option) {
	Executor* pExecutor = m_ExecutorFactory->getConcreteExecutor(option);
	if (pExecutor == nullptr)
		throw runtime_error("ERROR:: Proper Executor not found!!");

	return pExecutor->execute(searchRecords, option);
}