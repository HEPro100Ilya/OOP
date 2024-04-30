#ifndef INTERFACE_H
#define INTERFACE_H
#include <QWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

class Interface : public QWidget
{
    Q_OBJECT

public:

    Interface(QWidget *parent = nullptr);
    ~Interface();
private slots:
    void on_DataMatrixShow_pressed();

    void on_ShowMatrix_pressed();

    void on_Transponed_pressed();

    void on_Rang_pressed();

    void on_Determenant_pressed();


private:
    Ui::Interface *ui;
};
#endif // INTERFACE_H
