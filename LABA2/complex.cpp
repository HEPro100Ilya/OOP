#include <complex.h>
#include<iostream>
#include <math.h>

complex::complex()
{

}

complex::complex(const int& r)
{
    re = r;
    im = 0;
}

complex complex::operator* (complex c )
{
    complex t;
    t.re = re*c.re - im*c.im;
    t.im = re*c.im + im*c.re;
    return t;
}

complex complex::operator+ (complex c )
{
    complex t;
    t.re = re + c.re;
    t.im = im + c.im;
    return t;
}

complex complex::operator- (complex c )
{
    complex t;
    t.re = re - c.re;
    t.im = im - c.im;
    return t;
}

complex complex::operator/(complex c )
{
    complex t;
    t.re = (c.re*re+c.im*im) / (re*re+im*im);
    t.im = (re*c.im-c.re*im) / (re*re+im*im);
    return t;
}

double complex::modul(complex& c )
{
    double t = sqrt( c.re * c.re + c.im * c.im );
    return t;
}

ostream& operator<<(ostream& os,complex c )
{
    if(c.im<0){
            os<<c.re<<c.im<<"i";
            return os;
        }
        os<<c.re<<"+"<<c.im<<"i";
        return os;
}

istream& operator>>(istream& is,complex& c )
{
    is>>c.re>>c.im;
    return is;
}
