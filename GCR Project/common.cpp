#include "common.h"

#include <sstream>

using namespace std;

vector<string> stringTokenizer(const std::string& orgString, const char delimiter) {
	vector<string> tokens;
	istringstream sstring(orgString);
	string token;

	while (getline(sstring, token, delimiter)) {
		tokens.push_back(token);
	}

	return tokens;
}