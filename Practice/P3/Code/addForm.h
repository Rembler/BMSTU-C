#ifndef ADDFORM_H
#define ADDFORM_H
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class addForm : public QWidget
{
    Q_OBJECT
    QLabel *number, *name, *weight, *conduct;
    QLineEdit *numEdit, *nameEdit,
              *weiEdit, *condEdit;
    QPushButton *btnAct;
public:
    addForm();
public slots:
    void addElement();
};

#endif // ADDFORM_H
