#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Employee.h"
#include "Option.h"

class Searcher {
public:
	Searcher(std::map<int, Employee>* pEmployees, std::map<int, Employee>* pResults) 
		: pEmployees_(pEmployees), pResults_(pResults) {}
	virtual ~Searcher() {}
	virtual std::map<int, Employee>* search(ISchOption* schOption) const = 0;

protected:
	std::map<int, Employee>* pEmployees_;
	std::map<int, Employee>* pResults_;
};

class EmployeeNumSearcher : public Searcher {
public:
	EmployeeNumSearcher(std::map<int, Employee>* pEmployees, std::map<int, Employee>* pResults)
		: Searcher(pEmployees, pResults) {}

private:
	virtual std::map<int, Employee>* search(ISchOption* schOption) const override;
};

class NameSearcher : public Searcher {
public:
	NameSearcher(std::map<int, Employee>* pEmployees, std::map<int, Employee>* pResults)
		: Searcher(pEmployees, pResults) {}

private:
	virtual std::map<int, Employee>* search(ISchOption* schOption) const override;
	std::string getOption2String(const std::string& name, const Option::OPTION2 option) const;
};

class ClSearcher : public Searcher {
public:
	ClSearcher(std::map<int, Employee>* pEmployees, std::map<int, Employee>* pResults)
		: Searcher(pEmployees, pResults) {}

private:
	virtual std::map<int, Employee>* search(ISchOption* schOption) const override;
};

class PhoneNumSearcher : public Searcher {
public:
	PhoneNumSearcher(std::map<int, Employee>* pEmployees, std::map<int, Employee>* pResults)
		: Searcher(pEmployees, pResults) {}

private:
	virtual std::map<int, Employee>* search(ISchOption* schOption) const override;
	std::string getOption2String(const std::string& name, const Option::OPTION2 option) const;
};

class BirthdaySearcher : public Searcher {
public:
	BirthdaySearcher(std::map<int, Employee>* pEmployees, std::map<int, Employee>* pResults)
		: Searcher(pEmployees, pResults) {}

private:
	virtual std::map<int, Employee>* search(ISchOption* schOption) const override;
	std::string getOption2String(const std::string& name, const Option::OPTION2 option) const;
};

class CertiSearcher : public Searcher {
public:
	CertiSearcher(std::map<int, Employee>* pEmployees, std::map<int, Employee>* pResults)
		: Searcher(pEmployees, pResults) {}

private:
	virtual std::map<int, Employee>* search(ISchOption* schOption) const override;
};

class IFactorySearcher {
public:
	virtual ~IFactorySearcher() {}
	virtual Searcher* getConcreteSearcher(ISchOption* option) const = 0;
};

class FactorySearcher : public IFactorySearcher {
public:
	FactorySearcher(std::map<int, Employee>* pEmployees, std::map<int, Employee>* pResults);
	~FactorySearcher();

private:
	virtual Searcher* getConcreteSearcher(ISchOption* option) const override;

private:
	Searcher* pEmployeeNumSearcher_;
	Searcher* pNameSearcher_;
	Searcher* pClSearcher_;
	Searcher* pPhoneNumSearcher_;
	Searcher* pBirthdaySearcher_;
	Searcher* pCertiSearcher_;
};

class Executor {
public:
	Executor(std::map<int, Employee>* pEmployees) : pEmployees_(pEmployees) {};
	virtual ~Executor() {};
	virtual void execute(const std::map<int, Employee>* pSearchResult, Option* option) = 0;

protected:
	std::map<int, Employee>* pEmployees_;
};

class AddExecutor : public Executor {
public:
	AddExecutor(std::map<int, Employee>* pEmployees) : Executor(pEmployees) {};
	virtual void execute(const std::map<int, Employee>* pSearchResult, Option* option) override;
};

class DeleteExecutor : public Executor {
public:
	DeleteExecutor(std::map<int, Employee>* pEmployees) : Executor(pEmployees) {};
	virtual void execute(const std::map<int, Employee>* pSearchResult, Option* option) override;
};

class ModifyExecutor : public Executor {
public:
	ModifyExecutor(std::map<int, Employee>* pEmployees) : Executor(pEmployees) {};
	virtual void execute(const std::map<int, Employee>* pSearchResult, Option* option) override;
};

class IFactoryExecutor {
public:
	virtual ~IFactoryExecutor() {};
	virtual Executor* getConcreteExecutor(Option* option) = 0;
};

class FactoryExecutor : public IFactoryExecutor {
public:
	FactoryExecutor(std::map<int, Employee>* pEmployees);
	~FactoryExecutor();
	Executor* getConcreteExecutor(Option* option) override;

protected:
	Executor* m_pAddExecutor_;
	Executor* m_pDelExecutor_;
	Executor* m_pModExecutor_;
};

class EmployeeManager {
public:
	EmployeeManager() : m_Employees(), m_Results() {
		m_SearcherFactory = new FactorySearcher(&m_Employees, &m_Results);
		m_ExecutorFactory = new FactoryExecutor(&m_Employees);
	}
	~EmployeeManager() {
		m_Employees.clear();
		m_Results.clear();

		if (m_SearcherFactory) delete m_SearcherFactory;
		if (m_ExecutorFactory) delete m_ExecutorFactory;
	}
	std::map<int, Employee>* search(ISchOption* schOption);
	void execute(const std::map<int, Employee>* searchRecords, Option* option);

private:
	std::map<int, Employee> m_Employees;
	std::map<int, Employee> m_Results;

	IFactorySearcher* m_SearcherFactory;
	IFactoryExecutor* m_ExecutorFactory;
};