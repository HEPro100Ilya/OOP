#ifndef DRAW_H
#define DRAW_H

#include "graph.h"

#include <QPainter>

class TDraw
{
protected:
    TGraph Graph;

public:
    TDraw();
    TDraw(TGraph);
    void draw(QPainter*, QRect);
    void drawLines(QPointF*, QPainter*, int, int, qreal);
    bool isConnected(int, int);
};

#endif // DRAW_H
