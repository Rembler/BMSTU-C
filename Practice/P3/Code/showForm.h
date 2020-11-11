#ifndef SHOWFORM_H
#define SHOWFORM_H
#include "tableFile.h"
#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QLabel>

class showForm:public QWidget
{
    Q_OBJECT
    QTableWidget *table;
    QPushButton *btnShowAll, *btnShowC, *btnShowS, *btnShowI;
    QLineEdit *lineI;
public:
    showForm();
    elem source[10];
    int amount;
    void makeclear();
    void fulfill();
public slots:
    void showAll();
    void showSemiCond();
    void showIns();
    void showCond();
};

#endif // SHOWFORM_H
