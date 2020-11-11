#include <iostream>
#include "queue.h"
using namespace std;

void Queue::add(QString arg)
{
	length++;
    content[length-1] = arg.toStdString();
	existence = true;
}

void Queue::rem()
{
	if (existence)
	{
		for (int i = 0; i < length - 1;i++)
			content[i] = content[i + 1];
		content[length - 1] = "";
		length--;
		if (length == 0)
			existence = false;
	}
}

void Queue::remall()
{
	if (existence)
	{
		for (int i = 0; i < length; i++)
			content[i] = "";
		existence = false;
	}
}

void Queue::print(QTextEdit &textEdit)
{
	textEdit.clear();
	for (int i = 0; i < length; i++)
        textEdit.append(QString::fromStdString(content[i]));
}

void AdvQueue::sort()
{
    if ((existence) && (length > 1))
    {
    int j = 0;
    string buf;
	bool stop = false;
	while (!stop)
	{
		stop = true;
        for (int i = 0; i < length - 1 - j; i++)
            if (content[i] > content[i + 1])
            {
                buf = content[i];
                content[i] = content[i + 1];
                content[i + 1] = buf;
                stop = false;
            }
        j++;
    }
    stop = false;
    j = 0;
    while ((!stop) && (j < length))
    {
        if ((int)content[j][0] > 96)
            stop = true;
        j++;
    }
    for (int k = 0; k < j - 2; k++)
        for (int i = 0; i < j - 2 -k; i++)
            if (stoi(content[i]) > stoi(content[i+1]))
            {
                buf = content[i];
                content[i] = content[i + 1];
                content[i + 1] = buf;
            }
    }
}
