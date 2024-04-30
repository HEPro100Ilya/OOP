#ifndef STATEGRAPH_H
#define STATEGRAPH_H

#include "draw.h"

#include <math.h>

class TStateGraph : public TDraw
{
    int selected;

public:
    TStateGraph();
    TStateGraph(TGraph);
    void draw(QPainter*, QRect);
    void onClickedEvent(bool);
};

#endif // STATEGRAPH_H
