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
    ui->tableWidget->setRowCount(3);
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
    if(ui->r_mode->isChecked()||ui->c_mode->isChecked()||ui->i_mode->isChecked())
    {
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
    }else{
    ui->output->setText(text);
    }

}
void Interface::on_DataMatrixShow_pressed()
{
    if(ui->r_mode->isChecked()){
    QString msg;
        msg << QString().setNum(R_MODE);
        msg << QString().setNum(VALUE_REQUEST);
    for (int col = 0,row=0; col < ui->tableWidget->columnCount(); col++) {
        QTableWidgetItem* item = ui->tableWidget->item(row, col);
        msg<<QString().setNum(item->data(Qt::EditRole).toInt());
        ++row;
        QTableWidgetItem* item2 = ui->tableWidget->item(row, col);
        msg<<QString().setNum(item2->data(Qt::EditRole).toInt());
        --row;
        if(col==((ui->tableWidget->columnCount())-1)&&(row!=((ui->tableWidget->rowCount()))-2)){
            row+=2;
            col=-1;
        }
    }

    emit request(msg);
    }
    else if(ui->c_mode->isChecked()){
    QString msg;
    msg << QString().setNum(C_MODE);
    msg << QString().setNum(VALUE_REQUEST);
    for(int row=0;row<ui->tableWidget->rowCount();row++){
        for(int col=0;col<(ui->tableWidget->columnCount());col++){
            QTableWidgetItem* item = ui->tableWidget->item(row, col);
            msg<<QString().setNum(item->data(Qt::EditRole).toInt());
        }

    }

    emit request(msg);
    }
    else{
    QString msg;
    msg << QString().setNum(I_MODE);
    msg << QString().setNum(VALUE_REQUEST);
    for(int row=0;row<ui->tableWidget->rowCount();row++){
        for(int col=0;col<ui->tableWidget->columnCount();col++){
            QTableWidgetItem* item = ui->tableWidget->item(row, col);
            msg<<QString().setNum(item->data(Qt::EditRole).toInt());
        }

    }

    emit request(msg);
    }
}
void Interface::on_Transponed_pressed()
{   QString msg;
    if(ui->r_mode->isChecked()){
    msg << QString().setNum(R_MODE);
    msg << QString().setNum(TRANSPONED_REQUEST);
    }else if(ui->c_mode->isChecked()){
    msg << QString().setNum(C_MODE);
    msg << QString().setNum(TRANSPONED_REQUEST);
    }else{
    msg << QString().setNum(I_MODE);
    msg << QString().setNum(TRANSPONED_REQUEST);
    }

    emit request(msg);
}


void Interface::on_Rang_pressed()
{   QString msg;
    if(ui->r_mode->isChecked()){
    msg << QString().setNum(R_MODE);
    msg << QString().setNum(RANG_REQUEST);
    }else if(ui->c_mode->isChecked()){
    msg << QString().setNum(C_MODE);
    msg << QString().setNum(RANG_REQUEST);
    }else{
    msg << QString().setNum(I_MODE);
    msg << QString().setNum(RANG_REQUEST);
    }


    emit request(msg);
}


void Interface::on_Determenant_pressed()
{   QString msg;

    if(ui->r_mode->isChecked()){
    msg << QString().setNum(R_MODE);
    msg << QString().setNum(DETERMINANT_REQUEST);
    }else if(ui->c_mode->isChecked()){
    msg << QString().setNum(C_MODE);
    msg << QString().setNum(DETERMINANT_REQUEST);
    }else{
    msg << QString().setNum(I_MODE);
    msg << QString().setNum(DETERMINANT_REQUEST);
    }
    emit request(msg);
}




void Interface::on_SizeChange_pressed()
{
    QString msg;
    if(ui->r_mode->isChecked()){
    ui->tableWidget->setRowCount((ui->Cols->text().toInt()*2));
    ui->tableWidget->setColumnCount(ui->Rows->text().toInt());
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(QString::number(1));
            ui->tableWidget->setItem(row,col,item);
        }
    }
    msg << QString().setNum(R_MODE);
    msg << QString().setNum(SIZE_MATRIX);
    msg << QString().setNum((ui->tableWidget->rowCount()/2));
    msg << QString().setNum(ui->tableWidget->columnCount());
    }
    else if(ui->c_mode->isChecked()){
    ui->tableWidget->setRowCount((ui->Cols->text().toInt()));
    ui->tableWidget->setColumnCount(ui->Rows->text().toInt()*2);
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(QString::number(1));
            ui->tableWidget->setItem(row,col,item);
        }
    }
    msg << QString().setNum(C_MODE);
    msg << QString().setNum(SIZE_MATRIX);
    msg << QString().setNum((ui->tableWidget->rowCount()));
    msg << QString().setNum(ui->tableWidget->columnCount()/2);
    }
    else{
    ui->tableWidget->setRowCount(ui->Cols->text().toInt());
    ui->tableWidget->setColumnCount(ui->Rows->text().toInt());
    for (int row = 0; row <ui->tableWidget->rowCount() ; ++row) {
        for (int col = 0; col <ui->tableWidget->columnCount() ; ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(QString::number(1));
            ui->tableWidget->setItem(row,col,item);
        }
    }
    msg << QString().setNum(I_MODE);
    msg << QString().setNum(SIZE_MATRIX);
    msg << QString().setNum((ui->tableWidget->rowCount()));
    msg << QString().setNum(ui->tableWidget->columnCount());
    }

    emit request(msg);
}


void Interface::on_pushButton_pressed()
{   QString msg;
    if(ui->r_mode->isChecked()){
        ui->tableWidget->setRowCount(6);
        ui->tableWidget->setColumnCount(3);
        for (int row = 0,temp=1; row < ui->tableWidget->rowCount(); ++row) {
            for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
                QTableWidgetItem* item = new QTableWidgetItem(QString::number(temp));
                ui->tableWidget->setItem(row,col,item);
                temp++;
            }
        }
        msg << QString().setNum(R_MODE);
    }
    else if(ui->c_mode->isChecked()){
        ui->tableWidget->setRowCount(3);
        ui->tableWidget->setColumnCount(6);
        for (int row = 0,temp=1; row < ui->tableWidget->rowCount(); ++row) {
            for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
                QTableWidgetItem* item = new QTableWidgetItem(QString::number(temp));
                ui->tableWidget->setItem(row,col,item);
                temp++;
            }
        }
        msg << QString().setNum(C_MODE);
    }
    else{
        ui->tableWidget->setRowCount(3);
        ui->tableWidget->setColumnCount(3);
        for (int row = 0,temp=1; row < ui->tableWidget->rowCount(); ++row) {
            for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
                QTableWidgetItem* item = new QTableWidgetItem(QString::number(temp));
                ui->tableWidget->setItem(row,col,item);
                temp++;
            }
        }
        msg << QString().setNum(I_MODE);
    }

    emit request(msg);
}

