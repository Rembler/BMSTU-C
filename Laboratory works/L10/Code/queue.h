#include <iostream>
#include <QTextEdit>
#include <string>
using namespace std;

class Queue
{
protected:
	string content[20];
	int length;
	bool existence;
public:
	Queue()
	{
		length = 0;
		existence = false;
	}
    void add(QString arg);
	void rem();
	void remall();
	void print(QTextEdit &textEdit);
};

class AdvQueue :public Queue
{
public:
	void sort();
};
