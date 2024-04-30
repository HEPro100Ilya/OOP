#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include "QString"
using namespace std;

class Rational
{  int a,b;
    static QChar SEPARATOR;
public:
    int GetA();
    int GetB();
    double x;
    Rational();
    Rational(const int&);
    Rational(int,int);
    Rational(const QByteArray&);

    Rational operator+(Rational);
    Rational operator*(Rational);
    Rational operator-(Rational);
    Rational operator/(Rational);
    bool operator!=(Rational);
    double modul(Rational&);

    friend ostream& operator<<(ostream&,Rational&);
    friend istream& operator>>(istream&,Rational&);

    friend QString& operator<<(QString&,Rational&);
    friend QByteArray& operator>>(QByteArray&,Rational&);

    static void setSeparator(QChar);


};

#endif // RATIONAL_H
