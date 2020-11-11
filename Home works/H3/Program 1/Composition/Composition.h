#include <string>
using namespace std;

class exam
{
protected:
	string name;
	int mark;
public:
	void print();
	void init(string args, int argi);
	void retake(int argi);
	string getname();
	int getmark();
};

class book
{
protected:
	int number;
	string surname;
	int amount;
	exam exams[5];
public:
	void massinit(int argi3, string args2, int argi1, string args1[], int argi2[]);
	void massprint();
	void cretake(string args, int argi);
	double average();
	string red();
};