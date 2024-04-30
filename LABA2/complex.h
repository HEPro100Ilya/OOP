#ifndef COMPLEX_H
#define COMPLEX_H

#include<iostream>

using namespace std;

class complex
{
    double re,im;
public:
    complex();
    complex(const int&);

    complex operator* (complex);
    complex operator+ (complex);
    complex operator- (complex);
    complex operator/(complex);

    double modul(complex&);

    friend ostream& operator<<(ostream&,complex);
    friend istream& operator>>(istream&,complex&);
};


#endif // COMPLEX_H
