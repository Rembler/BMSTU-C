#ifndef DRAW_H
#define DRAW_H
#include <QDialog>
#include <ui_draw.h>
#include <QPainter>
#include <QTimer>

class Form:public QDialog, public Ui::Draw
{
    Q_OBJECT
public:
    Form(QWidget* parent = 0);
protected:
    QTimer *timer;
    QPainter painter;
private slots:
    void paintEvent(QPaintEvent *event);
};
#endif
