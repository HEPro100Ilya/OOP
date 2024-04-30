#include "stategraph.h"

TStateGraph::TStateGraph()
{
    this->selected = 0;
}

TStateGraph::TStateGraph(TGraph graph)
{
    this->selected = 0;
    this->Graph = graph;
}

void TStateGraph::draw(QPainter* painter, QRect window)
{
    TDraw::draw(painter, window);

    qreal pSize = 20;

    qreal cw = 0.5 * window.width();
    qreal ch = 0.5 * window.height();
    qreal cr = (cw > ch ? ch : cw) - 2 * pSize - 50;
    qreal a = 2.0 * acos(-1.0) / this->Graph.getDim();
    QPointF t(cw + cr * sin(this->selected * a), ch - cr * cos(this->selected * a));
    painter->setPen(QPen(Qt::red));
    painter->setBrush(QBrush(Qt::white));
    painter->drawEllipse(t, 30, 30);

    painter->drawText(QRectF(t.x() - pSize, t.y() - pSize, 2.0 * pSize, 2.0 * pSize), QString().setNum(this->selected + 1),
                      QTextOption(Qt::AlignCenter));
}

void TStateGraph::onClickedEvent(bool direction)
{
    if (direction) this->selected++;
    else this->selected = --this->selected + this->Graph.getDim();
    this->selected = this->selected % this->Graph.getDim();
}
