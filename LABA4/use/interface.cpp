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
    msg << ui->Chislit00->text() << ui->Znam00->text();
    msg << ui->Chislit01->text() << ui->Znam01->text();
    msg << ui->Chislit02->text() << ui->Znam02->text();
    msg << ui->Chislit11->text() << ui->Znam11->text();
    msg << ui->Chislit21->text() << ui->Znam21->text();
    msg << ui->Chislit20->text() << ui->Znam20->text();
    msg << ui->Chislit10->text() << ui->Znam10->text();
    msg << ui->Chislit12->text() << ui->Znam12->text();
    msg << ui->Chislit22->text() << ui->Znam22->text();
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



