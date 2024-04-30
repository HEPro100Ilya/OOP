#include "window.h"

TWindow::TWindow(TStateGraph window, QWidget *parent) : QWidget(parent)
{
    stateGraph = window;
    setFixedSize(1080, 720);
    QToolButton* fileButton = new QToolButton(this);
    fileButton->setGeometry(5, 5, 100, 30);
    fileButton->setText("Выбери граф");
    connect(fileButton, SIGNAL(clicked()), this, SLOT(browse()));
    QLabel* explanation = new QLabel(this);
    explanation->setGeometry(450, 10, 490, 30);
    explanation->setText("ЛКМ - налево, ПКМ - направо");
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
        this->stateGraph = TStateGraph(graph);
        repaint();
    }
    else
        return;
}

void TWindow::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)  stateGraph.onClickedEvent(false);
    if (event->button() == Qt::RightButton) stateGraph.onClickedEvent(true);
    update();
}

void TWindow::paintEvent(QPaintEvent*)
{
    QPainter p;
    p.begin(this);
    stateGraph.draw(&p, QRect(10, 10, 1070, 710));
    p.end();
}
