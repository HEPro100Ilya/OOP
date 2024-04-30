#include <QApplication>
#include "window.h"
#include "stategraph.h"
#include "graph.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TGraph graph;
    TStateGraph stateGraph(graph);
    TWindow window(stateGraph);
    window.show();

    return a.exec();
}
