#include "interface.h"
#include "ui_interface.h"
#include "matrix.h"
#include "QLabel"
namespace global {
Matrix matrix;
}
using namespace global;
Interface::Interface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Interface)
{
    ui->setupUi(this);

}

Interface::~Interface()
{
    delete ui;
}

void Interface::on_DataMatrixShow_pressed()
{
    number a(ui->Chislit00->text().toDouble(),ui->Znam00->text().toDouble());
    number b(ui->Chislit10->text().toDouble(),ui->Znam10->text().toDouble());
    number c(ui->Chislit20->text().toDouble(),ui->Znam20->text().toDouble());
    number d(ui->Chislit11->text().toDouble(),ui->Znam11->text().toDouble());
    number e(ui->Chislit12->text().toDouble(),ui->Znam12->text().toDouble());
    number f(ui->Chislit02->text().toDouble(),ui->Znam02->text().toDouble());
    number g(ui->Chislit01->text().toDouble(),ui->Znam01->text().toDouble());
    number i(ui->Chislit21->text().toDouble(),ui->Znam21->text().toDouble());
    number j(ui->Chislit22->text().toDouble(),ui->Znam22->text().toDouble());
    matrix.Arr[0][0]=a;
    matrix.Arr[1][0]=g;
    matrix.Arr[2][0]=f;
    matrix.Arr[1][1]=d;
    matrix.Arr[1][2]=i;
    matrix.Arr[0][2]=c;
    matrix.Arr[0][1]=b;
    matrix.Arr[2][1]=e;
    matrix.Arr[2][2]=j;
    QString s;
    for(int i=0;i<matrix.GetSize();i++){
        for(int j=0;j<matrix.GetSize();j++){
           s<<matrix.Arr[i][j];
            s+=" ";
      }
        s+="\n";
   }
   ui->output->setText(s);
}
void Interface::on_ShowMatrix_pressed(){
   QString s;
   for(int i=0;i<matrix.GetSize();i++){
        for(int j=0;j<matrix.GetSize();j++){
            s<<matrix.Arr[i][j];
            s+=" ";
        }
        s+="\n";
   }
   ui->output->setText(s);
}
void Interface::on_Transponed_pressed()
{
   matrix.TransponedMatrix(matrix.GetSize(),matrix.GetArr());
   on_ShowMatrix_pressed();
}


void Interface::on_Rang_pressed()
{
    QString d;
    d.setNum(matrix.RankMatrix(matrix.GetSize(),matrix.GetArr()));
    ui->Rang_2->setText(d);
}


void Interface::on_Determenant_pressed()
{

    QString b;
    number a=matrix.DetMatrix(matrix.GetArr());
    b<<a;
    ui->Det->setText(b);
}




