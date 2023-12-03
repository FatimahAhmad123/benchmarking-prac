#ifndef WHITELIST_HPP
#define WHITELIST_HPP

#include <map>
#include <vector>
#include "student.h"

using namespace std;

class whitelist
{
private:
	map<std::string, student *> student_record;
	vector<student> student_data_list;

public:
	void addToWhitelist(string name, student student);
	bool isStudentPresent(string name);
	student *getStudentData(string name);
};

#endif
