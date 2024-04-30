#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include "QString"
using namespace std;

class Rational
{  double a,b,x;

public:
    Rational();
    Rational(const double&);
    Rational(double,double);
    Rational operator*(Rational);
    Rational operator+(Rational);
    Rational operator-(Rational);
    Rational operator/(Rational);
    double modul(Rational&);
    friend ostream& operator<<(ostream&,Rational);
    friend istream& operator>>(istream&,Rational&);
    friend QString& operator<<(QString&,Rational&);
};

#endif // RATIONAL_H
