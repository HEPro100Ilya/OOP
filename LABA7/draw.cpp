#include "draw.h"
#include <math.h>
#include <QDebug>

TDraw::TDraw(){};

TDraw::TDraw(TGraph graph)
{
    this->Graph = graph;
}

void TDraw::draw(QPainter* painter, QRect window, QColor color)
{
    int count = this->Graph.getDim();

    qreal pSize = 20;

    qreal centerW = 0.5 * window.width();
    qreal centerH = 0.5 * window.height();
    qreal circleR = (centerW > centerH ? centerH : centerW) - 2*pSize - 50;
    qreal gap = 2.0 * acos(-1.0)/count;

    QFont font;
    font.setFamily("Calibri");
    font.setPointSize(pSize);
    painter->setFont(font);

    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::darkGray);
    pen.setBrush(QBrush(Qt::darkGray));
    painter->setPen(pen);

    QPointF *t = new QPointF[count];
    qreal x, y;

    for (int i = 0; i < count; i++)
    {
        x = centerW + circleR*sin(i*gap);
        y = centerH - circleR*cos(i*gap);
        t[i] = QPointF(x, y);
    }

    for (int i = 0; i < count; i ++)
        for (int j = 0; j < count; j++)
            if (this->Graph.getElement(i,j) != 0)
                drawLines(t, painter, i, j, pSize);

    painter->setBrush(QBrush(Qt::white));

    for (int i = 0; i < count; i++)
    {
        painter->setPen(QPen(Qt::black));
        painter->drawEllipse(t[i], pSize, pSize);
        painter->drawText(QRectF(t[i].x()-pSize,t[i].y()-pSize, 2.0*pSize, 2.0*pSize), QString().setNum(i+1), QTextOption(Qt::AlignCenter));
    }
    delete [] t;
}

void TDraw::drawLines(QPointF *t, QPainter *p, int i, int j, qreal radius)
{
    qreal angle = 2.0 * acos(-1.0)/this->Graph.getDim();
    qreal circleX, circleY;
    if (i == j)
    {
        p->setBrush(QBrush());
        circleX = t[i].x() + radius*sin(i*angle);
        circleY = t[i].y() - radius*cos(i*angle);
        p->drawEllipse(QPointF(circleX, circleY), radius/1.25, radius/1.25);
        p->setBrush(QBrush(Qt::darkGray));
    }
    else
    {
        p->drawLine(t[i], t[j]);

        qreal k = (t[j].y() - t[i].y()) / (t[j].x() - t[i].x());

        if ((t[j].x() < t[i].x()) && t[j].y() > t[i].y())
        {
            circleX = t[j].x() + radius*cos((atan(k)));
            circleY = t[j].y() + radius*sin((atan(k)));

        }
        else if ((t[j].x() > t[i].x()) && t[j].y() > t[i].y())
        {
            circleX = t[j].x() - radius*cos(atan(k));
            circleY = t[j].y() - radius*sin(atan(k));

        }
        else if ((t[j].x() < t[i].x()) && t[j].y() < t[i].y())
        {
            circleX = t[j].x() + radius*cos(atan(k));
            circleY = t[j].y() + radius*sin(atan(k));

        }
        else if ((t[j].x() > t[i].x()) && t[j].y() < t[i].y())
        {
            circleX = t[j].x() - radius*cos(atan(k));
            circleY = t[j].y() - radius*sin(atan(k));


        }
        else if ((t[j].x() == t[i].x()) && t[j].y() < t[i].y())
        {
            circleX = t[j].x() - radius*cos(atan(k)) * 0;
            circleY = t[j].y() - radius*sin(atan(k));

        }
        else if ((t[j].x() == t[i].x()) && t[j].y() > t[i].y())
        {
            circleX = t[j].x() - radius*cos(atan(k)) * 0;
            circleY = t[j].y() - radius*sin(atan(k));

        }
        else if ((t[j].x() > t[i].x()) && t[j].y() == t[i].y())
        {
            circleX = t[j].x() - radius*cos(atan(k));
            circleY = t[j].y() - radius*sin(atan(k)) * 0;

        }
        else if ((t[j].x() < t[i].x()) && t[j].y() == t[i].y())
        {
            circleX = t[j].x() + radius*cos(atan(k));
            circleY = t[j].y() - radius*sin(atan(k)) * 0;

        }
        else
        {
            return;
        }
        p->drawEllipse(QPointF(circleX, circleY), radius/5, radius/5);
    }
}
