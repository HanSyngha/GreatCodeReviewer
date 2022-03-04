#include "common.h"
#include <vector>

class Parser{
public:
	string request_management(const vector<string> tokens);
	void request_add(const vector<string> tokens);
	string request_del(const vector<string> tokens);
	string request_search(const vector<string> tokens);
	string request_mod(const vector<string> tokens);
	string make_return_str(const string reviced_str);
	string parse(const string input_txt);
	int parse_cmd(const string cmd);
};

vector<string> split_birth(const string birth);