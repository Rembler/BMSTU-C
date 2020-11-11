#include "graph.h"
#include "queue.h"
#include <QDialog>
using namespace std;

AdvQueue que;

FormDialog::FormDialog(QWidget* parent):QDialog(parent)
{
    setupUi(this);
    connect(pushButton, SIGNAL(clicked()),this,SLOT(adder()));
    connect(pushButton_2, SIGNAL(clicked()),this,SLOT(remover()));
    connect(pushButton_3, SIGNAL(clicked()),this,SLOT(allremover()));
    connect(pushButton_4, SIGNAL(clicked()),this,SLOT(sorter()));
};

void FormDialog::adder()
{
    if (lineEdit -> text() != "")
    {
        que.add(lineEdit->text());
        lineEdit->clear();
        que.print(*textEdit);
        lineEdit->setFocus();
    }
};

void FormDialog::remover()
{
    que.rem();
    que.print(*textEdit);
    lineEdit->setFocus();
};

void FormDialog::sorter()
{
    que.sort();
    que.print(*textEdit);
    lineEdit->setFocus();
};

void FormDialog::allremover()
{
    que.remall();
    textEdit->clear();
    lineEdit->setFocus();
};
