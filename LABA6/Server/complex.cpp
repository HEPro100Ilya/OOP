#include <complex.h>
#include <iostream>
#include <math.h>
#include "common.h"
QChar complex::SEPARATOR = separator;
complex::complex()
{

}
complex::complex(const int& r)
{
    re=r;
    im = 0;
}
complex::complex(const QByteArray& arr)
{
    int p = arr.indexOf(complex::SEPARATOR);
    re = arr.left(p).toDouble();
    im = arr.right(arr.length()-p-1).toDouble();
}
QByteArray& operator>>(QByteArray& arr, complex& c)
{
    int p = arr.indexOf(separator);
    p = arr.indexOf(separator,p+1);
    if (p > 0)
    {
        c = complex(arr.left(p));
        arr = arr.right(arr.length()-p-1);
    }
    return arr;
}
ostream& operator<<(ostream& os ,complex c){
    if(c.im<0){
        os<<c.re<<c.im<<"i";
        return os;
    }
    os<<c.re<<"+"<<c.im<<"i";
    return os;
}
istream& operator>>(istream& is ,complex& c){
    is>>c.re>>c.im;
    return is;
}
complex complex::operator*(complex c){
    complex t;
    t.re=re*c.re-im*c.im;
    t.im=re*c.im+im*c.re;
    return t;
}
complex complex::operator+(complex c){
    complex t;
    t.re=re+c.re;
    t.im=im+c.im;
    return t;
}
complex complex::operator-(complex c){
    complex t;
    t.re=re-c.re;
    t.im=im-c.im;
    return t;
}
complex complex::operator/(complex c){
    complex t;
    t.re=(c.re*re+c.im*im)/(re*re+im*im);
    t.im=(re*c.im-c.re*im)/(re*re+im*im);
    return t;
}
double complex::abs(complex& c){
    double t = sqrt( c.re * c.re + c.im * c.im );
    return t;
}
bool complex::operator==(complex c){
    return (re == c.re&&im==c.im);
}
bool complex::operator!=(complex c){
    return (re != c.re&&im!=c.im);
}
QString& operator<<(QString& os ,complex& c){
    if(c.im<0){
        os+=QString().setNum(c.re);
        os+=QString().setNum(c.im);
        os+="i";
        return os;
    }
    os+=QString().setNum(c.re);
    os+="+";
    os+=QString().setNum(c.im);
    os+="i";
    return os;
}
int complex::GetA(){
    return re;
}
int complex::GetB(){
    return im;
}
void complex::setSeparator(QChar ch)
{
    SEPARATOR = ch;
}
