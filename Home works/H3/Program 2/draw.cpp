#include "draw.h"
#include "figures.h"

archi fig;
square fig1;
circle fig2;
double n[3] = {0, 0, 0};

Form::Form(QWidget* parent):QDialog(parent)
{
    setupUi(this);
    setFixedSize(1800, 600);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(repaint()));
    timer->start(50);
}

void Form::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    for (int i = 0; i < 3; i++)
    {
        n[i] += 0.05 * pow(2,i);
        if (n[i] >= 2*M_PI)
            n[i] = 0;
    }
    QPainter painter(this);
    fig.drawing(&painter, n[1]);
    fig1.drawing(&painter, n[2]);
    fig2.drawing(&painter, n[0]);
}
