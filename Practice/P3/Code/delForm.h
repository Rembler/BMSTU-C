#ifndef DELFORM_H
#define DELFORM_H
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "tableFile.h"

class delForm : public QWidget
{
    Q_OBJECT
    QLabel *name;
    QLineEdit *nameEdit;
    QPushButton *btnAct;
    elem source[10];
    int amount;
public:
    delForm();
public slots:
    void delElement();
};

#endif // DELFORM_H
