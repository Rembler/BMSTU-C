#ifndef MAINFORM_H
#define MAINFORM_H
//#include <QtGui>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "addForm.h"
#include "delForm.h"
#include "showForm.h"
#include "drawForm.h"

class Window : public QWidget
{
    Q_OBJECT
    QPushButton *btnAdd, *btnDel, *btnShow, *btnDraw;
    addForm winAdd;
    delForm winDel;
    showForm winShow;
    drawForm winDraw;
public:
    Window();
public slots:
    void showAdd();
    void showDel();
    void showShow();
    void showDraw();
};

#endif // MAINFORM_H
