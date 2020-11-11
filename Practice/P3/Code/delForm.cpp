#include "delForm.h"
#include "mainForm.h"
#include <QFormLayout>
#include <QString>

delForm::delForm()
{
    setWindowTitle("Delete element");
    QFormLayout *layout = new QFormLayout;
    name = new QLabel("Name", this);
    nameEdit = new QLineEdit("", this);
    btnAct = new QPushButton("Delete", this);
    layout -> addRow(name, nameEdit);
    layout -> addRow(btnAct);
    setLayout(layout);
    setFixedSize(350, 100);
    connect(btnAct, SIGNAL(clicked()), this, SLOT(delElement()));
}

void delForm::delElement()
{
    if (nameEdit -> text() != "")
    {
        tableFile table;
        int i = 0;
        bool flag = false;
        while (table.readElem())
        {
            if (table.buf.name != nameEdit -> text())
            {
                source[i] = table.buf;
                i++;
            }
            else
                flag = true;
        }
        amount = i;
        if (flag)
        {
            table.delFile();
            for (int j = 0; j < amount; j++)
                table.addElem(source[j]);
            nameEdit -> clear();
        }
    }
}
