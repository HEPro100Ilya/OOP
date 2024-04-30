#include "application.h"
#include "common.h"
#include "boxymatrix.h"
#include "QDataStream"
namespace global {
    Matrix matrix;
boxymatrix bxmatrix;
}
using namespace global;
Application::Application(int argc, char *argv[])
    : QCoreApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000,
                        QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);

    connect(comm,SIGNAL(recieved(QByteArray)),this,SLOT(recieve(QByteArray)));
}
void Application::recieve(QByteArray msg)
{
    QString answer, s;
    Rational m[matrix.GetLines()*matrix.GetColumns()];
    for(int i=0;i<(matrix.GetLines()*matrix.GetColumns());i++){
        msg>>m[i];
    }
    int pos = msg.indexOf(separator);
    int t = msg.left(pos).toInt();

    switch (t)
    {
    case SIZE_MATRIX:{
        matrix.SetSize(m[0].GetA(),m[0].GetB());
    }break;

    case VALUE_REQUEST:{
        for(int i=0,temp=0;i<matrix.GetLines();i++){
            for(int j=0;j<matrix.GetColumns();j++){
                matrix.Arr[i][j]=m[temp];
                temp++;
            }

        }
        for(int i=0;i<matrix.GetLines();i++){
            for(int j=0;j<matrix.GetColumns();j++){
                s<<matrix.Arr[i][j];
                s+=" ";
            }
            s+="\n";
        }
        answer<<QString().setNum(VALUE_ANSWER);
        answer += s;}
        break;
    case PRINT_CLASSIC_REQUEST:{
        for(int i=0;i<matrix.GetLines();i++){
            for(int j=0;j<matrix.GetColumns();j++){
                s<<matrix.Arr[i][j];
                s+=" ";
            }
            s+="\n";
        }
        answer<<QString().setNum(PRINT_ANSWER)<<s;}
        break;
    case DETERMINANT_REQUEST:{
        if(matrix.GetLines()==matrix.GetColumns()){
        number a=(bxmatrix.Determinant(matrix.GetLines(),matrix.GetArr()));
        s.setNum(a.x);

        answer<<QString().setNum(DETERMINANT_ANSWER)<<s;
        }else{
        s<<"Error! This matrix not square!";
        answer<<QString().setNum(DETERMINANT_ANSWER)<<s;
        }

    }break;
    case RANG_REQUEST:{
        s.setNum(matrix.RankMatrix(matrix.GetLines(),matrix.GetColumns()));
        answer<<QString().setNum(RANG_ANSWER)<<s;
    }
        break;
    case TRANSPONED_REQUEST:{
        matrix.TransponedMatrix(matrix.GetLines(),matrix.GetColumns(),matrix.GetArr());
        for(int i=0;i<matrix.GetLines();i++){
            for(int j=0;j<matrix.GetColumns();j++){
                s<<matrix.Arr[i][j];
                s+=" ";
            }
            s+="\n";
        }
        answer<<QString().setNum(TRANSPONED_ANSWER)<<s;}
        break;
    default: return;
    }
    comm->send(QByteArray().append(answer));
}
