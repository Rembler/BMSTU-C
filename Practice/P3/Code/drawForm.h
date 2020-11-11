#ifndef DRAWFORM_H
#define DRAWFORM_H
#include <QWidget>
#include <QPainter>
#include <QPushButton>
#include <QLabel>
#include "tableFile.h"

class drawForm:public QWidget
{
    Q_OBJECT
public:
    drawForm();
    void getdata();
protected:
    elem source[10];
    int amount;
    QPainter painter;
    QPushButton *btnAct;
    QLabel *zero, *ord, *abs;
private slots:
    void paintEvent(QPaintEvent *event);

};

#endif // DRAWFORM_H
