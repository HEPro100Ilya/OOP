#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include "QString"
using namespace std;
class complex
{
    double re,im;
    static QChar SEPARATOR;
public:
    complex();
    complex(const int&);
    complex(const QByteArray& arr);
    int GetA();
    int GetB();
    complex operator*(complex);
    complex operator+(complex);
    complex operator-(complex);
    complex operator/(complex);
    double abs(complex&);
    bool operator==(complex);
    bool operator!=(complex);
    friend ostream& operator<<(ostream&,complex);
    friend istream& operator>>(istream&,complex&);
    friend QString& operator<<(QString&,complex&);
    friend QByteArray& operator>>(QByteArray&,complex&);
    static void setSeparator(QChar);
};

#endif // COMPLEX_H
