#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <map>

class student
{
private:
	struct student_record
	{
		std::string roll_no;
		int age;
		float cgpa;
	};

	std::map<std::string, int> result;
	student_record data;

public:
	void set_roll_no(std::string roll);
	std::string get_roll_no() const;
	void set_age(int age);
	int get_age() const;
};

#endif