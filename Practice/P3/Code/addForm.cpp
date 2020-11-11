#include "addForm.h"
#include "tableFile.h"
#include "mainForm.h"
#include <QFormLayout>
#include <QString>

addForm::addForm()
{
    setWindowTitle("Add element");
    QFormLayout *layout = new QFormLayout;
    number = new QLabel("Number", this);
    name = new QLabel("Name", this);
    weight = new QLabel("Atomic weight", this);
    conduct = new QLabel("Conductivity", this);
    numEdit = new QLineEdit("", this);
    nameEdit = new QLineEdit("", this);
    weiEdit = new QLineEdit("", this);
    condEdit = new QLineEdit("", this);
    btnAct = new QPushButton("Add", this);
    layout -> addRow(number, numEdit);
    layout -> addRow(name, nameEdit);
    layout -> addRow(weight, weiEdit);
    layout -> addRow(conduct, condEdit);
    layout -> addRow(btnAct);
    setLayout(layout);
    setFixedSize(300, 180);
    connect(btnAct, SIGNAL(clicked()), this, SLOT(addElement()));
}

void addForm::addElement()
{
    tableFile table;
    elem a;
    a.number = numEdit -> text();
    a.name = nameEdit -> text();
    a.weight = weiEdit -> text();
    a.conduct = condEdit -> text();
    numEdit -> clear();
    nameEdit -> clear();
    weiEdit -> clear();
    condEdit -> clear();
    table.addElem(a);
}
