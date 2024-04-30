#ifndef DRAW_H
#define DRAW_H

#include <QPainter>
#include "graph.h"

class TDraw
{
    TGraph Graph;

public:
    TDraw();
    TDraw(TGraph);
    void draw(QPainter*, QRect, QColor);
    void drawLines(QPointF*, QPainter*, int i, int j, qreal);
    bool isConnected(int i, int j);
};

#endif // DRAW_H
