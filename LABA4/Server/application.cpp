#include "application.h"
#include "common.h"
#include "matrix.h"
namespace global {
    Matrix matrix;
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
    Rational a,b,c,d,e,f,g,i,j;

    msg>>a>>b>>c>>d>>e>>f>>g>>i>>j;
    int pos = msg.indexOf(separator);
    int t = msg.left(pos).toInt();
    switch (t)
    {
    case VALUE_REQUEST:{
        matrix.Arr[0][0]=a;
        matrix.Arr[1][0]=b;
        matrix.Arr[2][0]=c;
        matrix.Arr[1][1]=d;
        matrix.Arr[1][2]=e;
        matrix.Arr[0][2]=f;
        matrix.Arr[0][1]=g;
        matrix.Arr[2][1]=i;
        matrix.Arr[2][2]=j;
        for(int i=0;i<matrix.GetSize();i++){
            for(int j=0;j<matrix.GetSize();j++){
                s<<matrix.Arr[i][j];
                s+=" ";
            }
            s+="\n";
        }
        answer<<QString().setNum(VALUE_ANSWER);
        answer += s;}
        break;
    case PRINT_CLASSIC_REQUEST:{
        for(int i=0;i<matrix.GetSize();i++){
            for(int j=0;j<matrix.GetSize();j++){
                s<<matrix.Arr[i][j];
                s+=" ";
            }
            s+="\n";
        }
        answer<<QString().setNum(PRINT_ANSWER)<<s;}
        break;
    case DETERMINANT_REQUEST:{
        number a=(matrix.DetMatrix(matrix.GetArr()));
        s.setNum(a.x);
        answer<<QString().setNum(DETERMINANT_ANSWER)<<s;}
        break;
    case RANG_REQUEST:{
        s.setNum(matrix.RankMatrix(matrix.GetSize(),matrix.GetArr()));
        answer<<QString().setNum(RANG_ANSWER)<<s;
    }
        break;
    case TRANSPONED_REQUEST:{
        matrix.TransponedMatrix(matrix.GetSize(),matrix.GetArr());
        for(int i=0;i<matrix.GetSize();i++){
            for(int j=0;j<matrix.GetSize();j++){
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
