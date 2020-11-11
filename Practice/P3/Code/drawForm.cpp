#include "drawForm.h"
#include "mainForm.h"

drawForm::drawForm()
{
    setWindowTitle("Graph");
    setFixedSize(800, 655);
    btnAct = new QPushButton("Draw", this);
    btnAct -> setGeometry(5, 5, 80, 30);
    //connect(btnAct, SIGNAL(clicked()), this, SLOT(getdata()));
    connect(btnAct, SIGNAL(clicked()), this, SLOT(repaint()));
    zero = new QLabel("0", this);
    zero -> setGeometry(3, 636, 8, 12);
    zero -> setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    zero -> setStyleSheet("font: 9pt;");
    ord = new QLabel("Atomic weight", this);
    ord -> setGeometry(25, 45, 90, 18);
    ord -> setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ord -> setStyleSheet("font: 9pt;");
    abs = new QLabel("Number", this);
    abs -> setGeometry(740, 610, 55, 18);
    abs -> setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    abs -> setStyleSheet("font: 9pt;");
}

void drawForm::paintEvent(QPaintEvent *event)
{
    getdata();
    Q_UNUSED(event);
    QPainter painter(this);
    QPen pen1(Qt::black, 2, Qt::SolidLine);
    painter.setPen(pen1);
    painter.drawLine(15, 639, 15, 50);
    painter.drawLine(15, 50, 20, 55);
    painter.drawLine(15, 50, 10, 55);
    painter.drawLine(15, 639, 784, 639);
    painter.drawLine(784, 639, 779, 634);
    painter.drawLine(784, 639, 779, 644);
    QPen pen2(Qt::red, 2, Qt::SolidLine);
    QPen pen3(Qt::red, 6, Qt::SolidLine);
    if (amount > 1)
    {
        painter.setPen(pen3);
        painter.drawPoint(15+6*source[0].number.toDouble(),
                          639-2*source[0].weight.toDouble());
        for (int i = 0; i < amount - 1; i++)
        {
            painter.setPen(pen2);
            painter.drawLine(15+6*source[i].number.toDouble(),
                         639-2*source[i].weight.toDouble(),
                         15+6*source[i+1].number.toDouble(),
                         639-2*source[i+1].weight.toDouble());
            painter.setPen(pen3);
            painter.drawPoint(15+6*source[i+1].number.toDouble(),
                              639-2*source[i+1].weight.toDouble());
        }
    }
}

void drawForm::getdata()
{
    tableFile *res = new tableFile;
    int i = 0;
    while (res -> readElem())
    {
        source[i] = res -> buf;
        i++;
    }
    amount = i;

    for (int j = 0; j < amount - 1; j++)
        for (int k = 0; k < amount - 1 - j; k++)
            if (source[k].number.toDouble() > source[k+1].number.toDouble())
            {
                elem *temp = new elem;
                *temp = source[k];
                source[k] = source[k+1];
                source[k+1] = *temp;
                delete temp;
            }
    delete res;
}
