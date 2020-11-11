#include "mainForm.h"

Window::Window()
{
    setWindowTitle("Mendel table");
    btnAdd = new QPushButton("Add", this);
    btnDel = new QPushButton("Del", this);
    btnShow = new QPushButton("Show", this);
    btnDraw = new QPushButton("Draw", this);
    QGridLayout *layout = new QGridLayout;
    layout -> addWidget(btnAdd, 0, 0);
    layout -> addWidget(btnDel, 0, 1);
    layout -> addWidget(btnShow, 1, 0, 1, 2);
    layout -> addWidget(btnDraw, 2, 0, 1, 2);
    setLayout(layout);
    setFixedSize(400, 150);
    connect(btnAdd, SIGNAL(clicked()),this,SLOT(showAdd()));
    connect(btnShow, SIGNAL(clicked()), this, SLOT(showShow()));
    connect(btnDel, SIGNAL(clicked()), this, SLOT(showDel()));
    connect(btnDraw, SIGNAL(clicked()), this, SLOT(showDraw()));
}

void Window::showAdd()
{
    winAdd.show();
}

void Window::showShow()
{
    winShow.makeclear();
    winShow.show();
}

void Window::showDel()
{
    winDel.show();
}

void Window::showDraw()
{
    winDraw.show();
    winDraw.getdata();
}
