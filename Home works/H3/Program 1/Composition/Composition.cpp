#include <iostream>
#include "Composition.h"
using namespace std;

void exam::retake(int argi)
{
	mark = argi;
}

void exam::init(string args, int argi)
{
	name = args;
	mark = argi;
}

void exam::print()
{
	cout << "Subject and mark: " << name << " - " << mark << endl;
}

int exam::getmark()
{
	return mark;
}

string exam::getname()
{
	return name;
}

void book::massinit(int argi3, string args2, int argi1, string args1[], int argi2[])
{
	number = argi3;
	surname = args2;
	amount = argi1;
	for (int i = 0; i < amount; i++)
		exams[i].init(args1[i], argi2[i]);
}

void book::massprint()
{
	cout << "Surname and number of student book: " << surname << " " << number << endl;
	cout << "Amount of subject: " << amount << endl;
	cout << "Subjects and marks:" << endl;
	for (int i = 0; i < amount; i++)
		cout << exams[i].getname() << " - " << exams[i].getmark() << endl;
}

void book::cretake(string args, int argi)
{
	for (int i = 0; i < amount; i++)
		if (exams[i].getname() == args)
			exams[i].retake(argi);
}

double book::average()
{
	double rez = 0;
	for (int i = 0; i < amount; i++)
		rez += exams[i].getmark();
	rez /= amount;
	return rez;
}

string book::red()
{
	double fives = 0, threes = 0;
	for (int i = 0; i < amount; i++)
	{
		if (exams[i].getmark() == 5)
			fives++;
		if (exams[i].getmark() == 3)
			threes++;
	}
	if ((threes > 0) or (fives / amount < 0.75))
		return "No";
	else
		return "Yes";
}

int main()
{
	book me;
	cout << "Enter your surname and number of record book" << endl;
	string gets1, gets2[10];
	int geti1, geti2[10], geti3;
	cin >> gets1 >> geti1;
	cout << "Enter amount of exams you have had" << endl;
	cin >> geti3;
	cout << "Enter subject name and your mark per it" << endl;
	for (int i = 0; i < geti3; i++)
		cin >> gets2[i] >> geti2[i];
	me.massinit(geti1, gets1, geti3, gets2, geti2);
	int code = 0;
	while (code != 5)
	{
		cout << "Choose one of the following actions:" << endl;
		cout << " 1 - show info" << endl;
		cout << " 2 - retake exam" << endl;
		cout << " 3 - show average mark" << endl;
		cout << " 4 - is it possible to get a red diploma?" << endl;
		cout << " 5 - exit" << endl;
		cin >> code;
		switch (code)
		{
		case 1:
			me.massprint();
			break;
		case 2:
			cout << "Enter subject name and new mark" << endl;
			cin >> gets1 >> geti1;
			me.cretake(gets1, geti1);
			cout << "Mark was changed" << endl;
			break;
		case 3:
			cout << "Average mark: " << me.average() << endl;
			break;
		case 4:
			cout << me.red() << endl;
			break;
		}
	}
}