#include <QApplication>
#include "window.h"
#include "draw.h"
#include "graph.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TGraph graph;
    TDraw graphWindow(graph);
    TWindow appWindow(graphWindow);
    appWindow.show();

    return a.exec();
}
