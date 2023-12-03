#include <iostream>
#include <vector>
#include "whitelist.hpp"
using namespace std;

void whitelist::addToWhitelist(string name, student student)
{
	student_data_list.reserve(16);
	student_data_list.push_back(student);
	student_record[name] = &student_data_list.back();
}

bool whitelist::isStudentPresent(string name)
{
	return student_record.find(name) != student_record.end();
}

student *whitelist::getStudentData(string name)
{
	if (isStudentPresent(name))
	{
		return student_record[name];
	}
	else
	{
		return nullptr;
	}
}
