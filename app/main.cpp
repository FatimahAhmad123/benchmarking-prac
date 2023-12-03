#include <iostream>
#include <vector>
#include "whitelist.hpp"

int main()
{
	whitelist whitelist;

	vector<string> names = {"Fatimah", "Ahmad", "Bob", "David", "Charlie", "Heheh", "hahah", "Name", "Student", "Alice", "Max", "Abdullah", "Ali", "Amna", "Maryum"};
	vector<int> ages = {21, 22, 21, 21, 24, 22, 21, 18, 23, 21, 21, 22, 22, 22, 21};
	vector<string> rollNumbers = {"A001", "A002", "A003", "A004", "A005", "A006", "A007", "A008", "A009", "A010", "A011", "A012", "A013", "A014", "A015"};

	int numStudents = names.size();

	for (int i = 0; i < numStudents; ++i)
	{
		student student;
		student.set_roll_no(rollNumbers[i]);
		student.set_age(ages[i]);
		whitelist.addToWhitelist(names[i], student);
	}

	// Displaying Info for each student
	for (int i = 0; i < numStudents; ++i)
	{
		string name = names[i];
		if (whitelist.isStudentPresent(name))
		{
			student *ptr = whitelist.getStudentData(name);
			cout << "Student Info for " << name << endl;
			cout << "Roll No: " << ptr->get_roll_no() << endl;
			cout << "Age: " << ptr->get_age() << endl;
		}
		else
		{
			cout << "Student not found: " << name << endl;
		}
	}

	// Trying with a name that isn't in the map

	string randomName = "Random Person";
	cout << "Enter name of student to search: ";
	cin >> randomName;

	if (whitelist.isStudentPresent(randomName))
	{
		student *ptr = whitelist.getStudentData(randomName);
		if (ptr != nullptr)
		{
			cout << "Student Info for " << randomName << endl;
			cout << "Roll No: " << ptr->get_roll_no() << endl;
			cout << "Age: " << ptr->get_age() << endl;
		}
	}
	else
	{
		cout << "Student not found: " << randomName << endl;
	}

	return 0;
}