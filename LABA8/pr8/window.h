#ifndef VIEWER_H
#define VIEWER_H

#include "stategraph.h"

#include <QWidget>
#include <QFileDialog>
#include <QToolButton>
#include <QMouseEvent>
#include <QLabel>

class TWindow : public QWidget
{
    Q_OBJECT
    TStateGraph stateGraph;

public:
    TWindow(TStateGraph, QWidget *parent = 0);
    ~TWindow();

public slots:
    void browse();

protected:
    void mousePressEvent(QMouseEvent*);
    void paintEvent(QPaintEvent*);
};

#endif
