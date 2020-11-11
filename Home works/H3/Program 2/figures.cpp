#include "figures.h"

void figure::drawing(QPainter *canvas, double n)
{
    //abstract
}

void square::drawing(QPainter *canvas, double n)
{
    int b[4][2];
    for (int i = 0; i < 4; i++)
    {
        b[i][0] = 900+round(180*(-1)*cos(n+i*M_PI/2));
        b[i][1] = 300+round(180*sin(n+i*M_PI/2));
    }
    for (int i = 0; i < 4; i++)
        canvas->drawLine(b[i][0], b[i][1], b[(i+1)%4][0], b[(i+1)%4][1]);
}

void circle::drawing(QPainter *canvas, double n)
{
    int b;
    b = -(n*180*16/M_PI);
    canvas->drawPie(1350, 150, 300, 300, b, 16*270);
}

void archi::drawing(QPainter *canvas, double n)
{
    int b[6][3];
    b[0][0] = 300;
    b[0][1] = 300;
    b[4][0] = 300;
    b[4][1] = 300;
    for (int i = 1; i < 4; i++)
    {
        if (i == 2)
        {
          b[i][0] = 300+round(sqrt(1800)*cos(n-((i+1)-2)*M_PI/4));
          b[i][1] = 300+round(sqrt(1800)*sin(n-((i+1)-2)*M_PI/4));
        }
        else
        {
          b[i][0] = 300 + round(30*cos(n-((i+1)-2)*M_PI/4));
          b[i][1] = 300 + round(30*sin(n-((i+1)-2)*M_PI/4));
        }
    }
    b[5][0] = b[1][0];
    b[5][1] = b[1][1];
    for (int i = 0; i < 6; i++)
        b[i][2] = 16*90*((i+1)%4)-(n*180*16/M_PI);
    for(int i = 0; i < 6; i++)
        canvas->drawArc(b[i][0]-30*(i+1), b[i][1]-30*(i+1), 60*(i+1), 60*(i+1), b[i][2], 16*90);
}
