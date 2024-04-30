#ifndef GRAPH_H
#define GRAPH_H

#include "matrix.h"
#include <QFile>
#include <QTextStream>

class TGraph
{
    TMatrix<int> adjMatrix;
    int dim = 4;

public:
    TGraph();
    int getElement(int, int);
    int getDim();
    void setGraph(QString);
};

#endif // GRAPH_H
