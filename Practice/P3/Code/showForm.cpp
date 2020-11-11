#include "showForm.h"
#include "mainForm.h"

showForm::showForm()
{
    setWindowTitle("Requested data");
    btnShowAll = new QPushButton("Show info about all elements", this);
    btnShowC = new QPushButton("Show info about all conductors \nin increasing order of atomic weight", this);
    btnShowS = new QPushButton("Show names and numbers of all \nsemiconductors", this);
    btnShowI = new QPushButton("Show names of all insulators \nwhose atomic weight does not \nexceed this value", this);
    table = new QTableWidget(10, 4, this);
    lineI = new QLineEdit("", this);
    QStringList strlist;
    strlist << "Number" << "Name" << "Atomic weight" << "Conductivity";
    table -> setHorizontalHeaderLabels(strlist);
    QGridLayout *layout = new QGridLayout;
    layout -> addWidget(btnShowAll, 0, 0);
    layout -> addWidget(btnShowC, 1, 0);
    layout -> addWidget(btnShowS, 2, 0);
    layout -> addWidget(btnShowI, 3, 0);
    layout -> addWidget(lineI, 4, 0);
    layout -> addWidget(table, 0, 1, 5, 1);
    setLayout(layout);
    setFixedSize(1096,521);
    connect(btnShowAll, SIGNAL(clicked()), this, SLOT(showAll()));
    connect(btnShowS, SIGNAL(clicked()), this, SLOT(showSemiCond()));
    connect(btnShowI, SIGNAL(clicked()), this, SLOT(showIns()));
    connect(btnShowC, SIGNAL(clicked()), this, SLOT(showCond()));
}

void showForm::fulfill()
{
    tableFile res;
    int i = 0;
    while (res.readElem())
    {
        source[i] = res.buf;
        i++;
    }
    amount = i;
}

void showForm::makeclear()
{
    table -> clearContents();
}

void showForm::showAll()
{
    fulfill();
    makeclear();
    QTableWidgetItem *item;
    for (int i = 0; i < amount; i++)
        for (int j = 0; j < 4; j++)
        {
            item = new QTableWidgetItem();
            item -> setFlags(Qt::NoItemFlags);
            switch (j)
            {
            case 0:
                item -> setText(source[i].number);
                break;
            case 1:
                item -> setText(source[i].name);
                break;
            case 2:
                item -> setText(source[i].weight);
                break;
            case 3:
                item -> setText(source[i].conduct);
                break;
            }
            table -> setItem(i, j, item);
    }
}

void showForm::showSemiCond()
{
    fulfill();
    makeclear();
    QTableWidgetItem *item;
    int row = 0;
    for (int i = 0; i < amount; i++)
        if (source[i].conduct == "Semiconductor")
        {
            item = new QTableWidgetItem();
            item -> setFlags(Qt::NoItemFlags);
            item -> setText(source[i].name);
            table -> setItem(row, 1, item);
            item = new QTableWidgetItem();
            item -> setFlags(Qt::NoItemFlags);
            item -> setText(source[i].weight);
            table -> setItem(row, 2, item);
            row++;
        }
}

void showForm::showIns()
{
    if (lineI -> text() != "")
    {
        fulfill();
        makeclear();
        QTableWidgetItem *item;
        int row = 0;
        for (int i = 0; i < amount; i++)
            if ((source[i].weight.toDouble() <= (lineI -> text()).toDouble())
               && (source[i].conduct == "Insulator"))
            {
                item = new QTableWidgetItem();
                item -> setFlags(Qt::NoItemFlags);
                item -> setText(source[i].name);
                table -> setItem(row, 1, item);
                row++;
            }
    }
}

void showForm::showCond()
{
    fulfill();
    makeclear();
    elem conds[10];
    int row = 0;
    for (int i = 0; i < amount; i++)
        if (source[i].conduct == "Conductor")
        {
            conds[row] = source[i];
            row++;
        }
    elem temp;
    for (int i = 0; i < row - 1; i++)
        for (int j = 0; j < row - 1 - i; j++)
            if (conds[j].weight.toDouble() > conds[j+1].weight.toDouble())
            {
                temp = conds[j];
                conds[j] = conds[j+1];
                conds[j+1] = temp;
            }
    QTableWidgetItem *item;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < 4; j++)
        {
            item = new QTableWidgetItem();
            item -> setFlags(Qt::NoItemFlags);
            switch (j)
            {
            case 0:
                item -> setText(conds[i].number);
                break;
            case 1:
                item -> setText(conds[i].name);
                break;
            case 2:
                item -> setText(conds[i].weight);
                break;
            case 3:
                item -> setText(conds[i].conduct);
                break;
            }
            table -> setItem(i, j, item);
        }
}
