#include "window.h"

TWindow::TWindow(TDraw window, QWidget *parent) : QWidget(parent)
{
    graphWindow = window;
    setFixedSize(700, 700);
    QToolButton* chooseButton = new QToolButton(this);
    chooseButton->setGeometry(5, 5, 100, 30);
    chooseButton->setText("Выбери граф");
    connect(chooseButton, SIGNAL(clicked()), this, SLOT(browse()));
}

TWindow::~TWindow(){}

void TWindow::browse()
{
    QString fileName = "";
    fileName = QFileDialog::getOpenFileName(this, ("Open File"), "../Graph files", ("Graph (*grp)"));
    if (fileName != "")
    {
        TGraph graph;
        graph.setGraph(fileName);
        this->graphWindow = TDraw(graph);
        repaint();
    }
    else return;
}

void TWindow::paintEvent(QPaintEvent*)
{
    QPainter p;
    p.begin(this);
    graphWindow.draw(&p, QRect(10, 10, 700, 700), Qt::white);
    p.end();
}
