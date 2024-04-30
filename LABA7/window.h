#ifndef VIEWER_H
#define VIEWER_H

#include <QWidget>
#include <QFileDialog>
#include <QToolButton>
#include "draw.h"

class TWindow : public QWidget
{
    Q_OBJECT
    TDraw graphWindow;

public:
    TWindow(TDraw, QWidget *parent = 0);
    ~TWindow();

public slots:
    void browse();

protected:
    void paintEvent(QPaintEvent*);
};

#endif // VIEWER_H
