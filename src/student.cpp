#include <iostream>
#include "student.h"

void student::set_roll_no(std::string roll)
{
	data.roll_no = roll;
}

std::string student::get_roll_no() const
{
	return data.roll_no;
}

void student::set_age(int age)
{
	data.age = age;
}

int student::get_age() const
{
	return data.age;
}
