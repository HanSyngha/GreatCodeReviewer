#include "EmployeeManager.h"

using namespace std;

EmployeeResult* EmployeeNumSearcher::search(ISchOption* schOption) const {
	pResults_->clear();

	int keyVal = Employee::makeKeyValueFromString(schOption->getSearchData());
	if ((*pEmployees_).count(keyVal)) {
		(pResults_->entity)[keyVal] = (*pEmployees_)[keyVal];
		pResults_->increase();
	}

	return pResults_;
}

EmployeeResult* NameSearcher::search(ISchOption* schOption) const {
	pResults_->clear();
	
	for (auto& employee : (*pEmployees_)) {
		if (schOption->getSearchData() == getOption2String(employee.second.Name_, schOption->getOption2())) {
			if (ISchOption::isLimitOverCount(pResults_->count) == false)
				(pResults_->entity)[employee.first] = employee.second;
			pResults_->increase();
		}
	}

	return pResults_;
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

EmployeeResult* ClSearcher::search(ISchOption* schOption) const {
	pResults_->clear();

	for (auto& employee : (*pEmployees_)) {
		if (schOption->getSearchData() == employee.second.Career_level_) {
			if (ISchOption::isLimitOverCount(pResults_->count) == false)
				(pResults_->entity)[employee.first] = employee.second;
			pResults_->increase();
		}
	}

	return pResults_;
}

EmployeeResult* PhoneNumSearcher::search(ISchOption* schOption) const {
	pResults_->clear();

	for (auto& employee : (*pEmployees_)) {
		if (schOption->getSearchData() == getOption2String(employee.second.Phone_number_, schOption->getOption2())) {
			if (ISchOption::isLimitOverCount(pResults_->count) == false)
				(pResults_->entity)[employee.first] = employee.second;
			pResults_->increase();
		}
	}

	return pResults_;
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

EmployeeResult* BirthdaySearcher::search(ISchOption* schOption) const {
	pResults_->clear();

	for (auto& employee : (*pEmployees_)) {
		if (schOption->getSearchData() == getOption2String(employee.second.BirthDay_, schOption->getOption2())) {
			if (ISchOption::isLimitOverCount(pResults_->count) == false)
				(pResults_->entity)[employee.first] = employee.second;
			pResults_->increase();
		}
	}

	return pResults_;
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

EmployeeResult* CertiSearcher::search(ISchOption* schOption) const {
	pResults_->clear();

	for (auto& employee : (*pEmployees_)) {
		if (schOption->getSearchData() == employee.second.Certi_) {
			if (ISchOption::isLimitOverCount(pResults_->count) == false)
				(pResults_->entity)[employee.first] = employee.second;
			pResults_->increase();
		}
	}

	return pResults_;
}

FactorySearcher::FactorySearcher(std::map<int, Employee>* pEmployees, EmployeeResult* pResults) {
	pEmployeeNumSearcher_ = new EmployeeNumSearcher(pEmployees, pResults);
	pNameSearcher_ = new NameSearcher(pEmployees, pResults);
	pClSearcher_ = new ClSearcher(pEmployees, pResults);
	pPhoneNumSearcher_ = new PhoneNumSearcher(pEmployees, pResults);
	pBirthdaySearcher_ = new BirthdaySearcher(pEmployees, pResults);
	pCertiSearcher_ = new CertiSearcher(pEmployees, pResults);
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

Searcher* FactorySearcher::getConcreteSearcher(ISchOption* schOption) const {
	Searcher* pSearcher;
	
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

void AddExecutor::execute(const EmployeeResult* pSearchResult, Option* option) {
	AddOption* addOption = (AddOption*)option;
	int key = Employee::makeKeyValueFromString(addOption->getEmployee()->EmpNo_);

	if (pSearchResult->count != 0) {
		throw runtime_error("ERROR:: Data already exists!");
		return;
	}	
	(*pEmployees_)[key] = *addOption->getEmployee();
}

void DeleteExecutor::execute(const EmployeeResult* pSearchResult, Option* option) {
	for (const auto& employee : (pSearchResult->entity)) {
		(*pEmployees_).erase(employee.first);
	}
}

void ModifyExecutor::execute(const EmployeeResult* pSearchResult, Option* option) {
	ModOption* modOption = (ModOption*)option;
	for (const auto& employee : (pSearchResult->entity)) {
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

EmployeeResult* EmployeeManager::search(ISchOption* schOption) {
	Searcher* pSearcher = m_SearcherFactory->getConcreteSearcher(schOption);
	if (pSearcher == nullptr)
		throw runtime_error("ERROR:: Proper Searcher not found!!");

	return pSearcher->search(schOption);
}

void EmployeeManager::execute(const EmployeeResult* searchRecords, Option* option) {
	Executor* pExecutor = m_ExecutorFactory->getConcreteExecutor(option);
	if (pExecutor == nullptr)
		throw runtime_error("ERROR:: Proper Executor not found!!");

	pExecutor->execute(searchRecords, option);
}