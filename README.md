# GreatCodeReviewer
삼성 CodeReview교육 Team Project G조 Repo입니다.

조원: 한승하(팀장), 박도원, 서현민, 조성현

역할별
* 조성현 : File Class, main.cpp + TDD
* 한승하 : Parser + TDD
* 서현민 : EmployeeManager Add/Modify/멤버변수, Employee Structure + TDD
* 박도원 : EmployeeManager Search/Delete + TDD

PR Ground-Rule
* 제목에 [Feature], [BugFix ], [Refactoring] 사용
* 3명 리뷰 후 merge

UML

![uml](https://user-images.githubusercontent.com/100739486/157168881-2997fedc-4e56-4afa-b4f6-fbee63374273.png)


수행 방법
* ./GCR Porject.exe input.txt output.txt

TC list 및 Test 결과 (2022-03-08 updated)
------------------------------------------------------------------------
```Running main() from c:\a\1\s\thirdparty\googletest\googletest\src\gtest_main.cc
[==========] Running 34 tests from 5 test cases.
[----------] Global test environment set-up.
[----------] 16 tests from EmployeeManagerTest2
[ RUN      ] EmployeeManagerTest2.SearchNoOptionTest
[       OK ] EmployeeManagerTest2.SearchNoOptionTest (1 ms)
[ RUN      ] EmployeeManagerTest2.SearchFirstNameTest
[       OK ] EmployeeManagerTest2.SearchFirstNameTest (3 ms)
[ RUN      ] EmployeeManagerTest2.SearchLastNameTest
[       OK ] EmployeeManagerTest2.SearchLastNameTest (4 ms)
[ RUN      ] EmployeeManagerTest2.SearchPhoneMiddleNumberTest
[       OK ] EmployeeManagerTest2.SearchPhoneMiddleNumberTest (3 ms)
[ RUN      ] EmployeeManagerTest2.SearchPhoneLastNumberTest
[       OK ] EmployeeManagerTest2.SearchPhoneLastNumberTest (3 ms)
[ RUN      ] EmployeeManagerTest2.SearchBirthYearTest
[       OK ] EmployeeManagerTest2.SearchBirthYearTest (0 ms)
[ RUN      ] EmployeeManagerTest2.SearchBirthMonthTest
[       OK ] EmployeeManagerTest2.SearchBirthMonthTest (1 ms)
[ RUN      ] EmployeeManagerTest2.SearchBirthDayTest
[       OK ] EmployeeManagerTest2.SearchBirthDayTest (1 ms)
[ RUN      ] EmployeeManagerTest2.DeleteNoOptionTest
[       OK ] EmployeeManagerTest2.DeleteNoOptionTest (1 ms)
[ RUN      ] EmployeeManagerTest2.DeleteFirstNameTest
[       OK ] EmployeeManagerTest2.DeleteFirstNameTest (1 ms)
[ RUN      ] EmployeeManagerTest2.DeleteLastNameTest
[       OK ] EmployeeManagerTest2.DeleteLastNameTest (1 ms)
[ RUN      ] EmployeeManagerTest2.DeletePhoneMidNumberTest
[       OK ] EmployeeManagerTest2.DeletePhoneMidNumberTest (0 ms)
[ RUN      ] EmployeeManagerTest2.DeletePhoneLastNumberTest
[       OK ] EmployeeManagerTest2.DeletePhoneLastNumberTest (0 ms)
[ RUN      ] EmployeeManagerTest2.DeleteBirthYearTest
[       OK ] EmployeeManagerTest2.DeleteBirthYearTest (1 ms)
[ RUN      ] EmployeeManagerTest2.DeleteBirthMonthTest
[       OK ] EmployeeManagerTest2.DeleteBirthMonthTest (2 ms)
[ RUN      ] EmployeeManagerTest2.DeleteBirthDayTest
[       OK ] EmployeeManagerTest2.DeleteBirthDayTest (0 ms)
[----------] 16 tests from EmployeeManagerTest2 (49 ms total)

[----------] 8 tests from EmployeeManagerHMTest
[ RUN      ] EmployeeManagerHMTest.AddTest
[       OK ] EmployeeManagerHMTest.AddTest (1 ms)
[ RUN      ] EmployeeManagerHMTest.ModifyByFirstNameTest
[       OK ] EmployeeManagerHMTest.ModifyByFirstNameTest (1 ms)
[ RUN      ] EmployeeManagerHMTest.ModifyByLastNameTest
[       OK ] EmployeeManagerHMTest.ModifyByLastNameTest (1 ms)
[ RUN      ] EmployeeManagerHMTest.ModifyByPhoneMidNumberTest
[       OK ] EmployeeManagerHMTest.ModifyByPhoneMidNumberTest (1 ms)
[ RUN      ] EmployeeManagerHMTest.ModifyByPhoneLastNumberTest
[       OK ] EmployeeManagerHMTest.ModifyByPhoneLastNumberTest (1 ms)
[ RUN      ] EmployeeManagerHMTest.ModifyByBirthYearTest
[       OK ] EmployeeManagerHMTest.ModifyByBirthYearTest (1 ms)
[ RUN      ] EmployeeManagerHMTest.ModifyByBirthMonthTest
[       OK ] EmployeeManagerHMTest.ModifyByBirthMonthTest (0 ms)
[ RUN      ] EmployeeManagerHMTest.ModifyByBirthDayTest
[       OK ] EmployeeManagerHMTest.ModifyByBirthDayTest (0 ms)
[----------] 8 tests from EmployeeManagerHMTest (23 ms total)

[----------] 2 tests from FileTest
[ RUN      ] FileTest.FileSelfTest1
[       OK ] FileTest.FileSelfTest1 (1 ms)
[ RUN      ] FileTest.FileCallParseTest2
[       OK ] FileTest.FileCallParseTest2 (1001 ms)
[----------] 2 tests from FileTest (1008 ms total)

[----------] 2 tests from IntegrationTest
[ RUN      ] IntegrationTest.ITScene1
[       OK ] IntegrationTest.ITScene1 (1012 ms)
[ RUN      ] IntegrationTest.ITScene2forSpeedCheck
result: SCH,25000
result: SCH,00000000,A B,CL1,010-0000-0000,19700101,PRO
SCH,00000001,BA CB,CL2,010-0001-0002,19700101,PRO
SCH,00000002,CB DC,CL3,010-0002-0003,19700101,PRO
SCH,00000003,DC ED,CL4,010-0003-0004,19700101,PRO
SCH,00000004,ED FE,CL1,010-0004-0005,19700101,PRO
result: SCH,00000026,AZ BA,CL3,010-0026-0027,19700101,PRO
SCH,00000052,AZ BA,CL1,010-0052-0053,19700101,PRO
SCH,00000078,AZ BA,CL3,010-0078-0079,19700101,PRO
SCH,00000104,AZ BA,CL1,010-0104-0105,19700101,PRO
SCH,00000130,AZ BA,CL3,010-0130-0131,19700101,PRO
result: DEL,100000
result: SCH,NONE
Time Elapsed :8
[       OK ] IntegrationTest.ITScene2forSpeedCheck (8969 ms)
[----------] 2 tests from IntegrationTest (9986 ms total)

[----------] 6 tests from ParserTest
[ RUN      ] ParserTest.ParserAdd
[       OK ] ParserTest.ParserAdd (0 ms)
[ RUN      ] ParserTest.ParserDELdefult
[       OK ] ParserTest.ParserDELdefult (0 ms)
[ RUN      ] ParserTest.ParserDELbyname
[       OK ] ParserTest.ParserDELbyname (0 ms)
[ RUN      ] ParserTest.ParserSRHdefult
[       OK ] ParserTest.ParserSRHdefult (0 ms)
[ RUN      ] ParserTest.ParserSRHNone
[       OK ] ParserTest.ParserSRHNone (0 ms)
[ RUN      ] ParserTest.ParserMOD
[       OK ] ParserTest.ParserMOD (1 ms)
[----------] 6 tests from ParserTest (9 ms total)

[----------] Global test environment tear-down
[==========] 34 tests from 5 test cases ran. (11091 ms total)
[  PASSED  ] 34 tests.```
------------------------------------------------------------------------
