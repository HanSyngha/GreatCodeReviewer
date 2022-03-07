#include "pch.h"
#include <vector>
#include "../GCR Project/EmployeeManager.h"
#include "../GCR Project/Employee.h"
#include "../GCR Project/Option.cpp"

using namespace std;

void initEmployeeData(EmployeeManager& em) {
	EmployeeResult emptyResult;
	emptyResult.clear();

	Employee employee;
	employee.init("85125741", "FBAH RTIJ", "CL1", "010-8900-1478", "19780228", "ADV");
	AddOption option = AddOption(employee);
	em.execute(&emptyResult, &option);

	employee.init("08117441", "BMU MPOSXU", "CL3", "010-2703-3153", "20010215", "ADV");
	option = AddOption(employee);
	em.execute(&emptyResult, &option);

	employee.init("10127115", "KBU MHU", "CL3", "010-3284-4054", "19660814", "ADV");
	option = AddOption(employee);
	em.execute(&emptyResult, &option);

	employee.init("12117017", "LFIS JJIVL", "CL1", "010-7914-4067", "20120812", "PRO");
	option = AddOption(employee);
	em.execute(&emptyResult, &option);

	employee.init("11125777", "TKOQKIS HC", "CL1", "010-6734-2289", "19991001", "PRO");
	option = AddOption(employee);
	em.execute(&emptyResult, &option);

	employee.init("11109136", "QKAHCEX LTODDO", "CL4", "010-2627-8566", "19640130", "PRO");
	option = AddOption(employee);
	em.execute(&emptyResult, &option);

	employee.init("05101762", "VCUHLE HMU", "CL4", "010-3988-9289", "20030819", "PRO");
	option = AddOption(employee);
	em.execute(&emptyResult, &option);
}

TEST(EmployeeManagerTest2, SearchNoOptionTest) {
	EmployeeManager em;
	EmployeeResult* results;

	initEmployeeData(em);

	SchOption option = SchOption("employeeNum", "11125777");

	//EmployeeNum search
	results = em.search(&option);
	EXPECT_EQ(1, (results->entity).size());

	//CL search
	option = SchOption("cl", "CL4");
	results = em.search(&option);
	EXPECT_EQ(2, (results->entity).size());

	//Add CL4
	Employee employee;
	employee.init("20091154", "LFIS AEDLW", "CL4", "010-6681-1104", "20081113", "ADV");
	AddOption option2 = AddOption(employee);
	results->clear();
	em.execute(results, &option2);
	results = em.search(&option);
	EXPECT_EQ(3, (results->entity).size());

	//Certi search
	option = SchOption("certi", "PRO");
	results = em.search(&option);
	EXPECT_EQ(4, (results->entity).size());
}

TEST(EmployeeManagerTest2, SearchFirstNameTest) {
	EmployeeManager em;
	EmployeeResult* results;

	initEmployeeData(em);

	SchOption option = SchOption("name", "LFIS", "-f");
	results = em.search(&option);
	EXPECT_EQ(1, (results->entity).size());

	//ADD 1 more first name with LFIS
	Employee employee;
	employee.init("20091154", "LFIS AEDLW", "CL2", "010-6681-1104", "20081113", "ADV");
	AddOption option2 = AddOption(employee);
	results->clear();
	em.execute(results, &option2);

	results = em.search(&option);
	EXPECT_EQ(2, (results->entity).size());

	option = SchOption("name", "TKOQKIS", "-f");
	results = em.search(&option);
	EXPECT_EQ(1, (results->entity).size());

	//Delete
	DelOption option4 = DelOption("name", "TKOQKIS", "-f");
	em.execute(em.search(&option4), &option4);

	results = em.search(&option);
	EXPECT_EQ(0, (results->entity).size());
}

TEST(EmployeeManagerTest2, SearchLastNameTest) {
	EmployeeManager em;
	EmployeeResult* results;

	initEmployeeData(em);

	SchOption schop1 = SchOption("name", "MPOSXU", "-l");
	results = em.search(&schop1);
	EXPECT_EQ(1, (results->entity).size());

	//Add
	Employee employee;
	employee.init("20091154", "QKAHCEX MPOSXU", "CL4", "010-1978-6651", "20100111", "PRO");
	AddOption addop1 = AddOption(employee);
	results->clear();
	em.execute(results, &addop1);

	results = em.search(&schop1);
	EXPECT_EQ(2, (results->entity).size());

	//Modify
	ModOption modop1 = ModOption("name", "MPOSXU", "cl", "CL4", "-l");
	em.execute(em.search(&modop1), &modop1);

	//Search again
	results = em.search(&schop1);
	EXPECT_EQ(2, (results->entity).size());

	SchOption schop2 = SchOption("name", "RTIJ", "-l");
	results = em.search(&schop2);
	EXPECT_EQ(1, (results->entity).size());

	//Delete
	DelOption delop1 = DelOption("name", "RTIJ", "-l");
	em.execute(em.search(&delop1), &delop1);

	results = em.search(&schop2);
	EXPECT_EQ(0, (results->entity).size());
}

TEST(EmployeeManagerTest2, SearchPhoneMiddleNumberTest) {
	EmployeeManager em;
	EmployeeResult* results;

	initEmployeeData(em);

	SchOption schop1 = SchOption("phoneNum", "7914", "-m");
	results = em.search(&schop1);
	EXPECT_EQ(1, (results->entity).size());

	//Add
	Employee employee;
	employee.init("20091154", "LFIS AEDLW", "CL2", "010-7914-2808", "20110925", "PRO");
	AddOption addop1 = AddOption(employee);
	results->clear();
	em.execute(results, &addop1);

	results = em.search(&schop1);
	EXPECT_EQ(2, (results->entity).size());

	//Modify
	ModOption modop1 = ModOption("phoneNum", "7914", "cl", "CL4", "-m");
	em.execute(em.search(&modop1), &modop1);

	results = em.search(&schop1);
	EXPECT_EQ(2, (results->entity).size());

	//Delete
	DelOption delop1 = DelOption("phoneNum", "7914", "-m");
	em.execute(em.search(&delop1), &delop1);

	results = em.search(&schop1);
	EXPECT_EQ(0, (results->entity).size());
}

TEST(EmployeeManagerTest2, SearchPhoneLastNumberTest) {
	EmployeeManager em;
	EmployeeResult* results;

	initEmployeeData(em);

	SchOption schop1 = SchOption("phoneNum", "8566", "-l");
	results = em.search(&schop1);
	EXPECT_EQ(1, (results->entity).size());

	//Add
	Employee employee;
	employee.init("20091154", "LFIS AEDLW", "CL2", "010-7914-8566", "20110925", "PRO");
	AddOption addop1 = AddOption(employee);
	results->clear();
	em.execute(results, &addop1);

	results = em.search(&schop1);
	EXPECT_EQ(2, (results->entity).size());

	//Modify
	ModOption modop1 = ModOption("phoneNum", "8566", "certi", "ADV", "-l");
	em.execute(em.search(&modop1), &modop1);

	results = em.search(&schop1);
	EXPECT_EQ(2, (results->entity).size());

	//Delete
	DelOption delop1 = DelOption("phoneNum", "8566", "-l");
	em.execute(em.search(&delop1), &delop1);

	results = em.search(&schop1);
	EXPECT_EQ(0, (results->entity).size());
}

TEST(EmployeeManagerTest2, SearchBirthYearTest) {
	EmployeeManager em;
	EmployeeResult* results;

	initEmployeeData(em);

	SchOption schop1 = SchOption("birthday", "2012", "-y");
	results = em.search(&schop1);
	EXPECT_EQ(1, (results->entity).size());

	//Add
	Employee employee;
	employee.init("20091154", "LFIS AEDLW", "CL2", "010-7914-8566", "20120925", "PRO");
	AddOption addop1 = AddOption(employee);
	results->clear();
	em.execute(results, &addop1);

	results = em.search(&schop1);
	EXPECT_EQ(2, (results->entity).size());

	//Modify
	ModOption modop1 = ModOption("birthday", "2012", "name", "ERGY DFEH", "-y");
	em.execute(em.search(&modop1), &modop1);

	results = em.search(&schop1);
	EXPECT_EQ(2, (results->entity).size());

	//Delete
	DelOption delop1 = DelOption("birthday", "2012", "-y");
	em.execute(em.search(&delop1), &delop1);

	results = em.search(&schop1);
	EXPECT_EQ(0, (results->entity).size());
}

TEST(EmployeeManagerTest2, SearchBirthMonthTest) {
	EmployeeManager em;
	EmployeeResult* results;

	initEmployeeData(em);

	SchOption schop1 = SchOption("birthday", "02", "-m");
	results = em.search(&schop1);
	EXPECT_EQ(2, (results->entity).size());

	//Add
	Employee employee;
	employee.init("20091154", "LFIS AEDLW", "CL2", "010-7914-8566", "20120225", "PRO");
	AddOption addop1 = AddOption(employee);
	results->clear();
	em.execute(results, &addop1);

	results = em.search(&schop1);
	EXPECT_EQ(3, (results->entity).size());

	//Modify
	ModOption modop1 = ModOption("birthday", "02", "name", "QWRY DHUJ", "-m");
	em.execute(em.search(&modop1), &modop1);

	results = em.search(&schop1);
	EXPECT_EQ(3, (results->entity).size());

	SchOption schop2 = SchOption("birthday", "08", "-m");
	results = em.search(&schop2);
	EXPECT_EQ(3, (results->entity).size());

	//Delete
	DelOption delop1 = DelOption("birthday", "08", "-m");
	em.execute(em.search(&delop1), &delop1);

	results = em.search(&schop2);
	EXPECT_EQ(0, (results->entity).size());
}

TEST(EmployeeManagerTest2, SearchBirthDayTest) {
	EmployeeManager em;
	EmployeeResult* results;

	initEmployeeData(em);

	SchOption schop1 = SchOption("birthday", "15", "-d");
	results = em.search(&schop1);
	EXPECT_EQ(1, (results->entity).size());

	//Add
	Employee employee;
	employee.init("20091154", "LFIS AEDLW", "CL2", "010-7914-8566", "20120215", "PRO");
	AddOption addop1 = AddOption(employee);
	results->clear();
	em.execute(results, &addop1);

	results = em.search(&schop1);
	EXPECT_EQ(2, (results->entity).size());

	//Modify
	ModOption modop1 = ModOption("birthday", "15", "cl", "CL2", "-d");
	em.execute(em.search(&modop1), &modop1);

	results = em.search(&schop1);
	EXPECT_EQ(2, (results->entity).size());

	SchOption schop2 = SchOption("birthday", "12", "-d");
	results = em.search(&schop2);
	EXPECT_EQ(1, (results->entity).size());

	//Delete
	DelOption delop1 = DelOption("birthday", "12", "-d");
	em.execute(em.search(&delop1), &delop1);

	results = em.search(&schop2);
	EXPECT_EQ(0, (results->entity).size());
}

TEST(EmployeeManagerTest2, DeleteNoOptionTest) {
	EmployeeManager em;
	EmployeeResult* searchResults;

	initEmployeeData(em);

	//EmployeeNum delete
	SchOption schop1 = SchOption("employeeNum", "10127115");
	searchResults = em.search(&schop1);

	EXPECT_EQ(1, (searchResults->entity).size());

	DelOption delop1 = DelOption("employeeNum", "10127115");
	em.execute(searchResults, &delop1);

	searchResults = em.search(&schop1);
	EXPECT_EQ(0, (searchResults->entity).size());

	//CL delete
	SchOption schop2 = SchOption("cl", "CL3");
	searchResults = em.search(&schop2);

	EXPECT_EQ(1, (searchResults->entity).size());

	DelOption delop2 = DelOption("cl", "CL3");
	searchResults = em.search(&delop2);
	em.execute(searchResults, &delop2);
	searchResults = em.search(&schop2);

	EXPECT_EQ(0, (searchResults->entity).size());

	//Certi delete
	SchOption schop3 = SchOption("certi", "PRO");
	searchResults = em.search(&schop3);
	
	EXPECT_EQ(4, (searchResults->entity).size());

	DelOption delop3 = DelOption("cl", "CL3");
	searchResults = em.search(&delop3);
	em.execute(searchResults, &delop3);
	searchResults = em.search(&schop3);

	EXPECT_EQ(4, (searchResults->entity).size());
}

TEST(EmployeeManagerTest2, DeleteFirstNameTest) {
	EmployeeManager em;
	EmployeeResult* searchResults;

	initEmployeeData(em);

	SchOption schop = SchOption("name", "LFIS", "-f");
	searchResults = em.search(&schop);

	EXPECT_EQ(1, (searchResults->entity).size());

	DelOption delop = DelOption("name", "LFIS", "-f");
	em.execute(searchResults, &delop);

	searchResults = em.search(&schop);
	EXPECT_EQ(0, (searchResults->entity).size());
}

TEST(EmployeeManagerTest2, DeleteLastNameTest) {
	EmployeeManager em;
	EmployeeResult* searchResults;

	initEmployeeData(em);

	SchOption schop = SchOption("name", "LTODDO", "-l");
	searchResults = em.search(&schop);

	EXPECT_EQ(1, (searchResults->entity).size());
	
	DelOption delop = DelOption("name", "LTODDO", "-l");
	em.execute(searchResults, &delop);

	searchResults = em.search(&schop);
	EXPECT_EQ(0, (searchResults->entity).size());
}

TEST(EmployeeManagerTest2, DeletePhoneMidNumberTest) {
	EmployeeManager em;
	EmployeeResult* searchResults;
	
	initEmployeeData(em);

	SchOption schop = SchOption("phoneNum", "7914", "-m");
	searchResults = em.search(&schop);

	EXPECT_EQ(1, (searchResults->entity).size());

	DelOption delop = DelOption("phoneNum", "7914", "-m");
	em.execute(searchResults, &delop);

	searchResults = em.search(&schop);
	EXPECT_EQ(0, (searchResults->entity).size());
}

TEST(EmployeeManagerTest2, DeletePhoneLastNumberTest) {
	EmployeeManager em;
	EmployeeResult* searchResults;

	initEmployeeData(em);

	SchOption schop = SchOption("phoneNum", "4054", "-l");
	searchResults = em.search(&schop);

	EXPECT_EQ(1, (searchResults->entity).size());
	
	DelOption delop = DelOption("phoneNum", "4054", "-l");
	em.execute(searchResults, &delop);
	
	searchResults = em.search(&schop);
	EXPECT_EQ(0, (searchResults->entity).size());
}

TEST(EmployeeManagerTest2, DeleteBirthYearTest) {
	EmployeeManager em;
	EmployeeResult* searchResults;

	initEmployeeData(em);

	SchOption schop = SchOption("birthday", "1966", "-y");
	searchResults = em.search(&schop);

	EXPECT_EQ(1, (searchResults->entity).size());

	DelOption delop = DelOption("birthday", "1966", "-y");
	em.execute(searchResults, &delop);

	searchResults = em.search(&schop);
	EXPECT_EQ(0, (searchResults->entity).size());
}

TEST(EmployeeManagerTest2, DeleteBirthMonthTest) {
	EmployeeManager em;
	EmployeeResult* searchResults;

	initEmployeeData(em);

	SchOption schop = SchOption("birthday", "02", "-m");
	searchResults = em.search(&schop);

	EXPECT_EQ(2, (searchResults->entity).size());

	DelOption delop = DelOption("birthday", "02", "-m");
	searchResults = em.search(&delop);
	em.execute(searchResults, &delop);

	searchResults = em.search(&schop);
	EXPECT_EQ(0, (searchResults->entity).size());
}

TEST(EmployeeManagerTest2, DeleteBirthDayTest) {
	EmployeeManager em;
	EmployeeResult* searchResults;

	initEmployeeData(em);

	SchOption schop = SchOption("birthday", "30", "-d");
	searchResults = em.search(&schop);

	EXPECT_EQ(1, (searchResults->entity).size());

	DelOption delop = DelOption("birthday", "30", "-d");
	em.execute(searchResults, &delop);

	searchResults = em.search(&schop);
	EXPECT_EQ(0, (searchResults->entity).size());
}