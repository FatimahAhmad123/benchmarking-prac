#include <gtest/gtest.h>
#include "../include/student.h"
#include "../include/whitelist.hpp"

TEST(StudentTest, TestRollNo)
{
	student s;
	s.set_roll_no("A002");
	EXPECT_EQ("A002", s.get_roll_no());
}

TEST(StudentTest, TestAge)
{
	student s;
	s.set_age(22);
	EXPECT_EQ(22, s.get_age());
}

TEST(WhitelistTest, TestAddToWhitelist)
{
	whitelist w;
	student s;
	s.set_roll_no("A002");
	s.set_age(22);

	w.addToWhitelist("Bob", s);

	EXPECT_TRUE(w.isStudentPresent("Bob"));
}

TEST(WhitelistTest, TestGetStudentData)
{
	whitelist w;
	student s;
	s.set_roll_no("A002");
	s.set_age(22);

	w.addToWhitelist("Bob", s);

	student *ptr = w.getStudentData("Bob");

	EXPECT_EQ("A002", ptr->get_roll_no());
	EXPECT_EQ(22, ptr->get_age());
}
