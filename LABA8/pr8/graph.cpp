#include "graph.h"
#include <QDebug>

TGraph::TGraph(){}

int TGraph::getElement(int i, int j)
{
    return this->adjMatrix.getElement(i, j);
}

int TGraph::getDim()
{
    return this->dim;
}

void TGraph::setGraph(QString f)
{
    QFile file(f);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);

    this->dim = in.readLine().toInt();
    this->adjMatrix.setDimension(this->dim);
    QStringList matr = in.readLine().split(" "), matr2;
    int count = 0;
    for (int i = 0; i < this->dim; i++)
    {
        for (int j = 0; j < this->dim; j++)
        {
            this->adjMatrix.setElement(matr[count].toInt(), i, j);
            count++;
        }
    }
    file.close();
}
