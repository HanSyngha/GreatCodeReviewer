#include <string>
using namespace std;

struct Employee {
	string EmpNo;
	string Name;
	string Career_level;
	string Phone_number;
	string PhoneMid;
	string PhoneLast;
	string BirthYear;
	string BirthMonth;
	string BirthDay;
	string Certi;

	static int makeKeyValue();
};
