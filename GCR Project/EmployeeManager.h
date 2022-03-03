#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Employee.h"
#include "common.h"

/////////////////////////////////////
//// Searcher
////////////////////////////////////
class Searcher {
public:
	Searcher(std::map<int, Employee>* pEmployees) : pEmployees_(pEmployees) {}
	virtual ~Searcher() {}
	virtual std::map<int, Employee> search(const Option& option) const = 0;

protected:
	std::map<int, Employee>* pEmployees_;
};

class EmpNumSearcher : public Searcher {
public:
	EmpNumSearcher(std::map<int, Employee>* pEmployees) : Searcher(pEmployees) {}

private:
	virtual std::map<int, Employee> search(const Option& option) const override {
		map<int, Employee> results;

		int keyVal = Employee::makeKeyValueFromString(option.searchData);
		if ((*pEmployees_).count(keyVal)) {
			results[keyVal] = (*pEmployees_)[keyVal];
		}

		return results;
	}
};

class NameSearcher : public Searcher {
public:
	NameSearcher(std::map<int, Employee>* pEmployees) : Searcher(pEmployees) {}

private:
	virtual std::map<int, Employee> search(const Option& option) const override {
		map<int, Employee> results;

		for (auto& employee : (*pEmployees_)) {
			if (option.searchData == getOption2String(employee.second.Name, option.op2)) {
				results[employee.first] = employee.second;
			}
		}
		
		return results;
	}

	string getOption2String(const string& name, const OPTION2 option) const {
		if (option == OPTION2::NONE) {
			return name;
		}

		vector<string> tokens = stringTokenizer(name, ' ');
		if (tokens.size() != 2) {
			throw runtime_error("ERROR:: invalid name format!");
		}

		if (option == OPTION2::FIRST_NAME) {
			return tokens[1];
		}
		else if (option == OPTION2::LAST_NAME) {
			return tokens[0];
		}
		else {
			throw runtime_error("ERROR:: invalid option!!");
		}
	}
};

class IFactorySearcher {
public:
	virtual ~IFactorySearcher() {}
	virtual Searcher* getConcreteSearcher(const Option& option) const = 0;
};

class FactorySearcher : public IFactorySearcher {
public:
	FactorySearcher(std::map<int, Employee>* pEmployees) {
		pEmpNumSearcher_ = new EmpNumSearcher(pEmployees);
		pNameSearcher_ = new NameSearcher(pEmployees);
		//TODO: Add more
	}
	~FactorySearcher() {
		if (pEmpNumSearcher_) delete pEmpNumSearcher_;
		if (pNameSearcher_) delete pNameSearcher_;
		//TODO: Add more
	}

private:
	virtual Searcher* getConcreteSearcher(const Option& option) const override {
		if (option.cmd == COMMAND::ADD) {
			return pEmpNumSearcher_;
		}

		Searcher* pSearcher = nullptr;
		//searchColumn은 Parser와 미리 정의된 값이어야 한다.
		string searchColumn = option.searchColumn;

		if (searchColumn == "EmpNum") {
			pSearcher = pEmpNumSearcher_;
		}
		else if (searchColumn == "Name") {
			pSearcher = pNameSearcher_;
		}
		else if (searchColumn == "Career_level") {
			//TODO: Add here
		}
		else if (searchColumn == "Phone_number") {
			//TODO: Add here
		}
		else if (searchColumn == "BirthDay") {
			//TODO: Add here
		}
		else if (searchColumn == "Certi") {
			//TODO: Add here
		}
		else {
			throw runtime_error("ERROR:: Invalid column name?");
		}

		return pSearcher;
	}

private:
	Searcher* pEmpNumSearcher_;
	Searcher* pNameSearcher_;
	//TODO: Add more searcher
};

////////////////////////////////////////
//// Executor
///////////////////////////////////////
class Executor {
public:
	Executor(std::map<int, Employee>* pEmployees) : pEmployees_(pEmployees) {};
	virtual ~Executor() {};
	virtual std::map<int, Employee> execute(const std::map<int, Employee>* pSearchResult, const Option& option) = 0;

protected:
	std::map<int, Employee>* pEmployees_;
};


class AddExecutor : public Executor {
public:
	AddExecutor(std::map<int, Employee>* pEmployees) : Executor(pEmployees) {};
	std::map<int, Employee> execute(const std::map<int, Employee>* pSearchResult, const Option& option) override {
		if (pSearchResult->size() != 0) {
			throw runtime_error("ERROR:: Data already exists!");
			return std::map<int, Employee>();
		}
		std::map<int, Employee> results;
		int key = Employee::makeKeyValueFromString(option.employee.EmpNo);
		(*pEmployees_)[key] = option.employee;
		results[key] = option.employee;
	}
};

class DeleteExecutor : public Executor {
public:
	DeleteExecutor(std::map<int, Employee>* pEmployees) : Executor(pEmployees) {};
	std::map<int, Employee> execute(const std::map<int, Employee>* pSearchResult, const Option& option) override {
		std::map<int, Employee> results;
		for (const auto& employee : (*pSearchResult)) {
			results[employee.first] = employee.second;
			(*pEmployees_).erase(employee.first);
		}
		return results;
	}
};

class SearchExecutor : public Executor {
public:
	SearchExecutor(std::map<int, Employee>* pEmployees) : Executor(pEmployees) {};
	std::map<int, Employee> execute(const std::map<int, Employee>* pSearchResult, const Option& option) override {
		return std::map<int, Employee>();
	}
};

class ModifyExecutor : public Executor {
public:
	ModifyExecutor(std::map<int, Employee>* pEmployees) : Executor(pEmployees) {};
	std::map<int, Employee> execute(const std::map<int, Employee>* pSearchResult, const Option& option) override {
		std::map<int, Employee> results;
		for (const auto& employee : (*pSearchResult)) {
			results[employee.first] = employee.second;

			//changeColumn은 Parser와 미리 정의한 값이어야 한다.
			if (option.changeColumn == "name") {
				(*pEmployees_)[employee.first].Name = option.changeData;
			}
			else if (option.changeColumn == "cl") {
				(*pEmployees_)[employee.first].Career_level= option.changeData;
			}
			else if (option.changeColumn == "phoneNum") {
				(*pEmployees_)[employee.first].Phone_number = option.changeData;
			}
			/*else if (option.changeColumn == "birthday") {  //Employee의 Birthday를 나눌 필요가 있는가?
				(*pEmployees_)[employee.first].BirthDay = option.changeData;
			}*/
			else if (option.changeColumn == "certi") {
				(*pEmployees_)[employee.first].Certi = option.changeData;
			}
		}
		return results;  //사실 pSearchResult의 내용과 그대로 같다.
	}
};


class IFactoryExecutor {
public:
	virtual ~IFactoryExecutor() {};
	virtual Executor* getConcreteExecutor(const Option& option) = 0;
};

class FactoryExecutor : public IFactoryExecutor {
public:
	FactoryExecutor(std::map<int, Employee>* pEmployees) {
		m_pAddExecutor_ = new AddExecutor(pEmployees);
		m_pDelExecutor_ = new DeleteExecutor(pEmployees);
		m_pSchExecutor_ = new SearchExecutor(pEmployees);
		m_pModExecutor_ = new ModifyExecutor(pEmployees);
	};
	~FactoryExecutor() {
		if (m_pAddExecutor_) delete m_pAddExecutor_;
		if (m_pDelExecutor_) delete m_pDelExecutor_;
		if (m_pSchExecutor_) delete m_pSchExecutor_;
		if (m_pModExecutor_) delete m_pModExecutor_;
	}
	Executor* getConcreteExecutor(const Option& option) override {
		Executor* pExecutor = nullptr;
		switch (option.cmd)
		{
		case COMMAND::ADD:
			pExecutor = m_pAddExecutor_;
			break;
		case COMMAND::DEL:
			pExecutor = m_pDelExecutor_;
			break;
		case COMMAND::SCH:
			pExecutor = m_pSchExecutor_;
			break;
		case COMMAND::MOD:
			pExecutor = m_pModExecutor_;
			break;
		}
		return pExecutor;
	};

protected:
	Executor* m_pAddExecutor_;
	Executor* m_pDelExecutor_;
	Executor* m_pSchExecutor_;
	Executor* m_pModExecutor_;
};

class EmployeeManager {
public:
	EmployeeManager() : m_Employees(), m_Results() {
		m_SearcherFactory = new FactorySearcher(&m_Employees);
		m_ExecutorFactory = new FactoryExecutor(&m_Employees);
	}
	~EmployeeManager() {
		m_Employees.clear();
		m_Results.clear();

		if (m_SearcherFactory) delete m_SearcherFactory;
		if (m_ExecutorFactory) delete m_ExecutorFactory;
	}
	
	//Parser에서 아래와 같은 flow
	//
	//1. parsing 후 Option데이터를 채움 Option option; (common.h의 Option struct 참고)
	//2. EmployeeManager em;
	//3. map<int, Employee> searchResults = em.search(option);
	//4. map<int, Employee> executeResults = em.execute(searchResults, option);
	//5. executeResults를 string으로 구성하여 File에 전달

	std::map<int, Employee> search(const Option& option) {
		clearResults();

		Searcher* pSearcher = m_SearcherFactory->getConcreteSearcher(option);
		if (pSearcher == nullptr) 
			throw runtime_error("ERROR:: Proper Searcher not found!!");

		m_Results = pSearcher->search(option);
		
		return m_Results;
	}

	std::map<int, Employee> execute(const map<int, Employee>* searchRecords, const Option& option) {
		clearResults();
		Executor* pExecutor = m_ExecutorFactory->getConcreteExecutor(option);
		if (pExecutor == nullptr) 
			throw runtime_error("ERROR:: Proper Executor not found!!");

		m_Results = pExecutor->execute(searchRecords, option);

		return m_Results;
	}

private:
	void clearResults() { m_Results.clear(); };

	std::map<int, Employee> m_Employees;
	std::map<int, Employee> m_Results;  //하다보니 m_Results를 굳이 member로 할 이유를 못찾겠다...

	IFactorySearcher* m_SearcherFactory;
	IFactoryExecutor* m_ExecutorFactory;
};