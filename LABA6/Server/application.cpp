#include "application.h"
#include "common.h"
#include "squarematrix.h"
#include "QDataStream"

namespace global{
Matrix<Rational> matrix;
SquareMatrix<Rational> SqMatrix;
Matrix<int>matrix2;
SquareMatrix<int> SqMatrix2;
Matrix<complex>matrix3;
SquareMatrix<complex> SqMatrix3;
}
using namespace global;

QByteArray& operator>>(QByteArray& arr, int& c)
{
    int p = arr.indexOf(separator);

    if (p > 0)
    {
        c = atoi(arr.left(p));
        arr = arr.right(arr.length()-p-1);
    }
    return arr;
}
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
    int pos = msg.indexOf(separator);
    int t,mode = msg.left(pos).toInt();
    msg = msg.right(msg.length()-pos-1);
    if(mode == R_MODE)
    {
        pos = msg.indexOf(separator);
        t = msg.left(pos).toInt();
        msg = msg.right(msg.length()-pos-1);
    Rational m[matrix.GetRows()*matrix.GetCols()];
    for(int i=0;i<(matrix.GetRows()*matrix.GetCols());i++){
        msg>>m[i];
    }


    switch (t)
    {
    case SIZE_MATRIX:{
        matrix.SetSize(m[0].GetA(),m[0].GetB());
    }break;
    case VALUE_REQUEST:{
        for(int i=0,temp=0;i<matrix.GetRows();i++){
            for(int j=0;j<matrix.GetCols();j++){
                matrix.Arr[i][j]=m[temp];
                temp++;
            }

        }
        for(int i=0;i<matrix.GetRows();i++){
            for(int j=0;j<matrix.GetCols();j++){
                s<<matrix.Arr[i][j];
                s+=" ";
            }
            s+="\n";
        }
        answer<<QString().setNum(VALUE_ANSWER);
        answer += s;}
        break;
    case DETERMINANT_REQUEST:{
        if(matrix.GetRows()==matrix.GetCols()){
        Rational a=(SqMatrix.DetSquareM(matrix.GetRows(),matrix.GetArr()));
        s.setNum(a.x);

        answer<<QString().setNum(DETERMINANT_ANSWER)<<s;
        }else{
        s<<"Error! This matrix not square!";
        answer<<QString().setNum(DETERMINANT_ANSWER)<<s;
        }

    }break;
    case RANG_REQUEST:{
        s.setNum(matrix.RankMatrix());
        answer<<QString().setNum(RANG_ANSWER)<<s;
    }
        break;
    case TRANSPONED_REQUEST:{
        matrix.TransponedMatrix();
        for(int i=0;i<matrix.GetRows();i++){
            for(int j=0;j<matrix.GetCols();j++){
                s<<matrix.Arr[i][j];
                s+=" ";
            }
            s+="\n";
        }
        answer<<QString().setNum(TRANSPONED_ANSWER)<<s;}
        break;
    default: return;
    }
    }
    else if(mode==C_MODE)
    {
    pos = msg.indexOf(separator);
    t = msg.left(pos).toInt();
    msg = msg.right(msg.length()-pos-1);
    complex m[matrix3.GetRows()*matrix3.GetCols()];
    for(int i=0;i<(matrix3.GetRows()*matrix3.GetCols());i++){
        msg>>m[i];
    }

    switch (t)
    {
    case SIZE_MATRIX:{
        matrix3.SetSize(m[0].GetA(),m[0].GetB());
    }break;
    case VALUE_REQUEST:{
        for(int i=0,temp=0;i<matrix3.GetRows();i++){
            for(int j=0;j<matrix3.GetCols();j++){
                matrix3.Arr[i][j]=m[temp];
                temp++;
            }

        }
        for(int i=0;i<matrix3.GetRows();i++){
            for(int j=0;j<matrix3.GetCols();j++){
                s<<matrix3.Arr[i][j];
                s+=" ";
            }
            s+="\n";
        }
        answer<<QString().setNum(VALUE_ANSWER);
        answer += s;}
    break;
    case DETERMINANT_REQUEST:{
        if(matrix3.GetRows()==matrix3.GetCols()){
            complex a=(SqMatrix3.DetSquareM(matrix3.GetRows(),matrix3.GetArr()));
            s<<a;

            answer<<QString().setNum(DETERMINANT_ANSWER)<<s;
        }else{
            s<<"Error! This matrix not square!";
            answer<<QString().setNum(DETERMINANT_ANSWER)<<s;
        }

    }break;
    case RANG_REQUEST:{
        s.setNum(matrix3.RankMatrix());
        answer<<QString().setNum(RANG_ANSWER)<<s;
    }
    break;
    case TRANSPONED_REQUEST:{
        matrix3.TransponedMatrix();
        for(int i=0;i<matrix3.GetRows();i++){
            for(int j=0;j<matrix3.GetCols();j++){
                s<<matrix3.Arr[i][j];
                s+=" ";
            }
            s+="\n";
        }
        answer<<QString().setNum(TRANSPONED_ANSWER)<<s;}
    break;
    default: return;
    }
    }else if(mode==I_MODE){

    pos = msg.indexOf(separator);
    t = msg.left(pos).toInt();
    msg = msg.right(msg.length()-pos-1);
    int m[matrix2.GetRows()*matrix2.GetCols()];
    for(int i=0;i<(matrix2.GetRows()*matrix2.GetCols());i++){
        msg>>m[i];
    }

    switch (t)
    {
    case SIZE_MATRIX:{
        matrix2.SetSize(m[0],m[1]);
    }break;
    case VALUE_REQUEST:{
        for(int i=0,temp=0;i<matrix2.GetRows();i++){
            for(int j=0;j<matrix2.GetCols();j++){
                matrix2.Arr[i][j]=m[temp];
                temp++;
            }

        }
        for(int i=0;i<matrix2.GetRows();i++){
            for(int j=0;j<matrix2.GetCols();j++){
                s+=QString().setNum(matrix2.Arr[i][j]);
                s+=" ";
            }
            s+="\n";
        }
        answer<<QString().setNum(VALUE_ANSWER);
        answer += s;}
    break;
    case DETERMINANT_REQUEST:{
        if(matrix2.GetRows()==matrix2.GetCols()){
            int a=(SqMatrix2.DetSquareM(matrix2.GetRows(),matrix2.GetArr()));
            s.setNum(a);
            answer<<QString().setNum(DETERMINANT_ANSWER)<<s;
        }else{
            s<<"Error! This matrix not square!";
            answer<<QString().setNum(DETERMINANT_ANSWER)<<s;
        }

    }break;
    case RANG_REQUEST:{
        s.setNum(matrix2.RankMatrix());
        answer<<QString().setNum(RANG_ANSWER)<<s;
    }
    break;
    case TRANSPONED_REQUEST:{
        matrix2.TransponedMatrix();
        for(int i=0;i<matrix2.GetRows();i++){
            for(int j=0;j<matrix2.GetCols();j++){
                s+=QString().setNum(matrix2.Arr[i][j]);
                s+=" ";
            }
            s+="\n";
        }
        answer<<QString().setNum(TRANSPONED_ANSWER)<<s;}
    break;
    default: return;
    }
    }

    else{
    s<<"err";
        answer<<QString().setNum(RANG_ANSWER)<<s;
    }
    comm->send(QByteArray().append(answer));
}
