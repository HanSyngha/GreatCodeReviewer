#include "pch.h"
#include <vector>
#include "../GCR Project/EmployeeManager.h"
#include "../GCR Project/Employee.h"

using namespace std;

void initEmployeeData(EmployeeManager& em) {
	em.Add({ "85125741", "FBAH RTIJ", "CL1", "010-8900-1478", "19780228", "ADV" });
	em.Add({ "08117441", "BMU MPOSXU", "CL3", "010-2703-3153", "20010215", "ADV" });
	em.Add({ "10127115", "KBU MHU", "CL3", "010-3284-4054", "19660814", "ADV" });
	em.Add({ "12117017", "LFIS JJIVL", "CL1", "010-7914-4067", "20120812", "PRO" });
	em.Add({ "11125777", "TKOQKIS HC", "CL1", "010-6734-2289", "19991001", "PRO" });
	em.Add({ "11109136", "QKAHCEX LTODDO", "CL4", "010-2627-8566", "19640130", "PRO" });
	em.Add({ "05101762", "VCUHLE HMU", "CL4", "010-3988-9289", "20030819", "PRO" });
}

TEST(EmployeeManagerTest2, SearchNoOptionTest) {
	EmployeeManager em;
	map<int, Employee> results;

	initEmployeeData(em);

	//EmployeeNum search
	results = em.SearchWithNoOption("empNo", "11125777");
	EXPECT_EQ(1, results.size());
	results.clear();

	//CL search
	results = em.SearchWithNoOption("cl", "CL4");
	EXPECT_EQ(2, results.size());
	results.clear();

	//Add CL4
	em.Add({ "20091154", "LFIS AEDLW", "CL4", "010-6681-1104", "20081113", "ADV" });
	results = em.SearchWithNoOption("cl", "CL4");
	EXPECT_EQ(3, results.size());
	results.clear();

	//Certi search
	results = em.SearchWithNoOption("certi", "PRO");
	EXPECT_EQ(4, results.size());
	results.clear();
}

TEST(EmployeeManagerTest2, SearchFirstNameTest) {
	EmployeeManager em;
	map<int, Employee> results;

	initEmployeeData(em);

	results = em.SearchByFirstName("name", "LFIS");
	EXPECT_EQ(1, results.size());
	results.clear();

	//Add
	em.Add({ "20091154", "LFIS AEDLW", "CL2", "010-6681-1104", "20081113", "ADV" });
	results = em.SearchByFirstName("name", "LFIS");
	EXPECT_EQ(2, results.size());
	results.clear();

	//Modify
	em.ModifyByFirstName("name", "LFIS", "cl", "CL3");
	results = em.SearchByFirstName("name", "LFIS");
	EXPECT_EQ(2, results.size());
	results.clear();

	results = em.SearchByFirstName("name", "TKOQKIS");
	EXPECT_EQ(1, results.size());
	results.clear();

	//Delete
	em.DeleteByFirstName("name", "TKOQKIS");
	results = em.SearchByFirstName("name", "TKOQKIS");
	EXPECT_EQ(0, results.size());
	results.clear();
}

TEST(EmployeeManagerTest2, SearchLastNameTest) {
	EmployeeManager em;
	map<int, Employee> results;

	initEmployeeData(em);

	results = em.SearchByLastName("name", "MPOSXU");
	EXPECT_EQ(1, results.size());
	results.clear();

	//Add
	em.Add({ "20091154", "QKAHCEX MPOSXU", "CL4", "010-1978-6651", "20100111", "PRO" });
	results = em.SearchByLastName("name", "MPOSXU");
	EXPECT_EQ(2, results.size());
	results.clear();

	//Modify
	em.ModifyByLastName("name", "MPOSXU", "cl", "CL4");
	results = em.SearchByLastName("name", "MPOSXU");
	EXPECT_EQ(2, results.size());
	results.clear();

	results = em.SearchByLastName("name", "MPOSXU");
	EXPECT_EQ(2, results.size());
	results.clear();

	results = em.SearchByLastName("name", "RTIJ");
	EXPECT_EQ(1, results.size());
	results.clear();

	//Delete
	em.DeleteByLastName("name", "RTIJ");
	results = em.SearchByLastName("name", "RTIJ");
	EXPECT_EQ(0, results.size());
	results.clear();
}

TEST(EmployeeManagerTest2, SearchPhoneMiddleNumberTest) {
	EmployeeManager em;
	map<int, Employee> results;

	initEmployeeData(em);

	results = em.SearchByPhoneMidNumber("phone_number", "7914");
	EXPECT_EQ(1, results.size());
	results.clear();

	//Add
	em.Add({ "20091154", "LFIS AEDLW", "CL2", "010-7914-2808", "20110925", "PRO" });
	results = em.SearchByPhoneMidNumber("phone_number", "7914");
	EXPECT_EQ(2, results.size());
	results.clear();

	//Modify
	em.ModifyByPhoneMidNumber("phone_number", "7914", "certi", "ADV");
	results = em.SearchByPhoneMidNumber("phone_number", "7914");
	EXPECT_EQ(2, results.size());
	results.clear();

	//Delete
	em.DeleteByPhoneMidNumber("phone_number", "7914");
	results = em.SearchByPhoneMidNumber("phone_number", "7914");
	EXPECT_EQ(0, results.size());
	results.clear();
}

TEST(EmployeeManagerTest2, SearchPhoneLastNumberTest) {
	EmployeeManager em;
	map<int, Employee> results;

	initEmployeeData(em);

	results = em.SearchByPhoneLastNumber("phone_number", "8566");
	EXPECT_EQ(1, results.size());
	results.clear();

	//Add
	em.Add({ "20091154", "LFIS AEDLW", "CL2", "010-7914-8566", "20110925", "PRO" });
	results = em.SearchByPhoneLastNumber("phone_number", "8566");
	EXPECT_EQ(2, results.size());
	results.clear();

	//Modify
	em.ModifyByPhoneLastNumber("phone_number", "8566", "certi", "ADV");
	results = em.SearchByPhoneLastNumber("phone_number", "8566");
	EXPECT_EQ(2, results.size());
	results.clear();

	//Delete
	em.DeleteByPhoneLastNumber("phone_number", "8566");
	results = em.SearchByPhoneLastNumber("phone_number", "8566");
	EXPECT_EQ(0, results.size());
	results.clear();
}

TEST(EmployeeManagerTest2, SearchBirthYearTest) {
	EmployeeManager em;
	map<int, Employee> results;

	initEmployeeData(em);

	results = em.SearchByBirthYear("birthday", "2012");
	EXPECT_EQ(1, results.size());
	results.clear();

	//Add
	em.Add({ "20091154", "LFIS AEDLW", "CL2", "010-7914-8566", "20120925", "PRO" });
	results = em.SearchByBirthYear("birthday", "2012");
	EXPECT_EQ(2, results.size());
	results.clear();

	//Modify
	em.ModifyByBirthYear("birthDay", "2012", "name", "ERGY DFEH");
	results = em.SearchByBirthYear("birthday", "2012");
	EXPECT_EQ(2, results.size());
	results.clear();

	//Delete
	em.DeleteByBirthYear("birthDay", "2012");
	results = em.SearchByBirthYear("birthDay", "2012");
	EXPECT_EQ(0, results.size());
	results.clear();
}

TEST(EmployeeManagerTest2, SearchBirthMonthTest) {
	EmployeeManager em;
	map<int, Employee> results;

	initEmployeeData(em);

	results = em.SearchByBirthMonth("birthDay", "02");
	EXPECT_EQ(2, results.size());
	results.clear();

	//Add
	em.Add({ "20091154", "LFIS AEDLW", "CL2", "010-7914-8566", "20120225", "PRO" });
	results = em.SearchByBirthMonth("birthDay", "02");
	EXPECT_EQ(3, results.size());
	results.clear();

	//Modify
	em.ModifyByBirthMonth("birthDay", "02", "name", "QWRY DHUJ");
	results = em.SearchByBirthMonth("birthDay", "02");
	EXPECT_EQ(3, results.size());
	results.clear();

	results = em.SearchByBirthMonth("birthDay", "08");
	EXPECT_EQ(3, results.size());
	results.clear();

	//Delete
	em.DeleteByBirthMonth("birthday", "08");
	results = em.SearchByBirthMonth("birthDay", "08");
	EXPECT_EQ(0, results.size());
	results.clear();
}

TEST(EmployeeManagerTest2, SearchBirthDayTest) {
	EmployeeManager em;
	map<int, Employee> results;

	initEmployeeData(em);

	results = em.SearchByBirthDay("birthDay", "15");
	EXPECT_EQ(1, results.size());
	results.clear();

	//Add
	em.Add({ "20091154", "LFIS AEDLW", "CL2", "010-7914-8566", "20120215", "PRO" });
	results = em.SearchByBirthDay("birthDay", "15");
	EXPECT_EQ(2, results.size());
	results.clear();

	//Modify
	em.ModifyByBirthDay("birthDay", "15", "cl", "CL2");
	results = em.SearchByBirthDay("birthDay", "15");
	EXPECT_EQ(2, results.size());
	results.clear();

	results = em.SearchByBirthDay("birthDay", "12");
	EXPECT_EQ(1, results.size());
	results.clear();

	//Delete
	em.DeleteByBirthDay("birthDay", "12");
	results = em.SearchByBirthDay("birthDay", "12");
	EXPECT_EQ(0, results.size());
	results.clear();
}

TEST(EmployeeManagerTest2, DeleteNoOptionTest) {
	EmployeeManager em;
	map<int, Employee> searchResults;
	map<int, Employee> deleteResults;

	initEmployeeData(em);

	//EmployeeNum delete
	searchResults = em.SearchWithNoOption("employeeNum", "10127115");
	deleteResults = em.DeleteWithNoOption("employeeNum", "10127115");

	EXPECT_EQ(deleteResults.size(), searchResults.size());

	searchResults.clear();
	deleteResults.clear();

	//CL delete
	searchResults = em.SearchWithNoOption("cl", "CL3");
	deleteResults = em.DeleteWithNoOption("cl", "CL3");

	EXPECT_EQ(deleteResults.size(), searchResults.size());

	searchResults.clear();
	deleteResults.clear();

	//Certi delete
	searchResults = em.SearchWithNoOption("certi", "PRO");
	deleteResults = em.DeleteWithNoOption("certi", "PRO");

	EXPECT_EQ(deleteResults.size(), searchResults.size());

	searchResults.clear();
	deleteResults.clear();
}

TEST(EmployeeManagerTest2, DeleteFirstNameTest) {
	EmployeeManager em;
	map<int, Employee> searchResults;
	map<int, Employee> deleteResults;

	initEmployeeData(em);

	searchResults = em.SearchByFirstName("name", "LFIS");
	deleteResults = em.DeleteByFirstName("name", "LFIS");

	EXPECT_EQ(deleteResults.size(), searchResults.size());
	
	searchResults.clear();
	deleteResults.clear();	
}

TEST(EmployeeManagerTest2, DeleteLastNameTest) {
	EmployeeManager em;
	map<int, Employee> searchResults;
	map<int, Employee> deleteResults;

	initEmployeeData(em);

	searchResults = em.SearchByLastName("name", "LTODDO");
	deleteResults = em.DeleteByLastName("name", "LTODDO");

	EXPECT_EQ(deleteResults.size(), searchResults.size());

	searchResults.clear();
	deleteResults.clear();
}

TEST(EmployeeManagerTest2, DeletePhoneMidNumberTest) {
	EmployeeManager em;
	map<int, Employee> searchResults;
	map<int, Employee> deleteResults;

	initEmployeeData(em);

	searchResults = em.SearchByPhoneMidNumber("phone_number", "7914");
	deleteResults = em.DeleteByPhoneMidNumber("phone_number", "7914");

	EXPECT_EQ(deleteResults.size(), searchResults.size());

	searchResults.clear();
	deleteResults.clear();
}

TEST(EmployeeManagerTest2, DeletePhoneLastNumberTest) {
	EmployeeManager em;
	map<int, Employee> searchResults;
	map<int, Employee> deleteResults;

	initEmployeeData(em);

	searchResults = em.SearchByPhoneLastNumber("phone_number", "4054");
	deleteResults = em.DeleteByPhoneLastNumber("phone_number", "4054");

	EXPECT_EQ(deleteResults.size(), searchResults.size());

	searchResults.clear();
	deleteResults.clear();
}

TEST(EmployeeManagerTest2, DeleteBirthYearTest) {
	EmployeeManager em;
	map<int, Employee> searchResults;
	map<int, Employee> deleteResults;

	initEmployeeData(em);

	searchResults = em.SearchByBirthYear("birthday", "1966");
	deleteResults = em.DeleteByBirthYear("birthday", "1966");

	EXPECT_EQ(deleteResults.size(), searchResults.size());

	searchResults.clear();
	deleteResults.clear();
}

TEST(EmployeeManagerTest2, DeleteBirthMonthTest) {
	EmployeeManager em;
	map<int, Employee> searchResults;
	map<int, Employee> deleteResults;

	initEmployeeData(em);

	searchResults = em.SearchByBirthMonth("birthday", "02");
	deleteResults = em.DeleteByBirthMonth("birthday", "02");

	EXPECT_EQ(deleteResults.size(), searchResults.size());

	searchResults.clear();
	deleteResults.clear();
}

TEST(EmployeeManagerTest2, DeleteBirthDayTest) {
	EmployeeManager em;
	map<int, Employee> searchResults;
	map<int, Employee> deleteResults;

	initEmployeeData(em);

	searchResults = em.SearchByBirthDay("birthday", "30");
	deleteResults = em.DeleteByBirthDay("birthday", "30");

	EXPECT_EQ(deleteResults.size(), searchResults.size());

	searchResults.clear();
	deleteResults.clear();
}