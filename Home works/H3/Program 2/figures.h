#ifndef FIGURES_H
#define FIGURES_H
#define _USE_MATH_DEFINES
#include <math.h>
#include <QPainter>

class figure
{
public:
    void drawing(QPainter *canvas, double n);
};

class archi:public figure
{
public:
    void drawing(QPainter *canvas, double n);
};

class square:public figure
{
public:
    void drawing(QPainter *canvas, double n);
};

class circle:public figure
{
public:
    void drawing(QPainter *canvas, double n);
};

#endif
