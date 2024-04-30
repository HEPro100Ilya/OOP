#include "interface.h"
#include "QLabel"
#include "ui_interface.h"
#include "common.h"
namespace global {

}
using namespace global;
Interface::Interface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Interface)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(6);
    ui->tableWidget->setColumnCount(3);
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(QString::number(1));
            ui->tableWidget->setItem(row,col,item);
        }
    }
}

Interface::~Interface()
{
    delete ui;
}
void Interface::answer(QString msg)
{
    QString text;
    int p = msg.indexOf(separator);
    int t = msg.left(p).toInt();
    msg = msg.mid(p+1,msg.length()-p-2);
    switch (t)
    {
    case VALUE_ANSWER:{
        text += msg;
        ui->output->setText(text);}
        break;
    case PRINT_ANSWER:{

        text += msg;
        ui->output->setText(text);}
        break;
    case TRANSPONED_ANSWER:{
        text += msg;
        ui->output->setText(text);}
        break;
    case RANG_ANSWER:{
        text += msg;
        ui->Rang_2->setText(text);}
        break;
    case DETERMINANT_ANSWER:{
        text += msg;
        ui->Det->setText(text);}
        break;
    default: break;
    }
}
void Interface::on_DataMatrixShow_pressed()
{   QString msg;
    for (int col = 0,row=0; col < ui->tableWidget->columnCount(); col++) {
        QTableWidgetItem* item = ui->tableWidget->item(row, col);
        msg<<QString().setNum(item->data(Qt::EditRole).toInt());
        ++row;
        QTableWidgetItem* item2 = ui->tableWidget->item(row, col);
        msg<<QString().setNum(item2->data(Qt::EditRole).toInt());
        --row;
        if(col==((ui->tableWidget->columnCount())-1)&&(row!=(ui->tableWidget->rowCount())-2)){
            row+=2;
            col=-1;
        }
    }
    msg << QString().setNum(VALUE_REQUEST);
    emit request(msg);
}
void Interface::on_ShowMatrix_pressed(){
    QString msg;
    msg << QString().setNum(PRINT_CLASSIC_REQUEST);
    emit request(msg);
}
void Interface::on_Transponed_pressed()
{   QString msg;
    msg << QString().setNum(TRANSPONED_REQUEST);
    emit request(msg);
}


void Interface::on_Rang_pressed()
{   QString msg;
    msg << QString().setNum(RANG_REQUEST);
    emit request(msg);
}


void Interface::on_Determenant_pressed()
{   QString msg;
    msg << QString().setNum(DETERMINANT_REQUEST);
    emit request(msg);
}




void Interface::on_SizeChange_pressed()
{
    ui->tableWidget->setRowCount((ui->Rows->text().toInt()*2));
    ui->tableWidget->setColumnCount(ui->Cols->text().toInt());
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(QString::number(1));
            ui->tableWidget->setItem(row,col,item);
        }
    }
    QString msg;
    msg << QString().setNum((ui->tableWidget->rowCount()/2));
    msg << QString().setNum(ui->tableWidget->columnCount());
    msg << QString().setNum(SIZE_MATRIX);
    emit request(msg);
}

