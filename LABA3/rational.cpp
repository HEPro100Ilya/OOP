#include "rational.h"
#include <iostream>
#include <math.h>
#include <cmath>
Rational::Rational()
{

}
Rational::Rational(const double& A){
    a=A;
    b=1;
    x=a/b;
}
Rational::Rational(double A,double B){
    a=A;
    b=B;
    x=a/b;
}
ostream& operator<<(ostream& os ,Rational c){
    if(c.b>0){
        if((fmod(c.a,c.b)==0.0)||(fmod(c.b,c.a)==0.0)){
            if(c.a>c.b){
                c.a=c.a/c.b;
                c.b=1;
            }
            if(c.a<c.b){
                c.b=c.b/c.a;
                c.a=1;
            }
        }
        if((fmod(c.a,c.b)!=0.0)||(fmod(c.b,c.a)!=0.0)){
            if((c.a>c.b)&&(fmod(c.a,(c.a-c.b))==0)&&(fmod(c.b,(c.a-c.b))==0)){
                double nod=c.a-c.b;
                c.a=c.a/nod;
                c.b=c.b/nod;
            }
            if((c.a<c.b)&&(fmod(c.a,(c.b-c.a))==0)&&(fmod(c.b,(c.b-c.a))==0)){
                double nod=c.b-c.a;
                c.a=c.a/nod;
                c.b=c.b/nod;
            }
        }
        os<<c.a<<"/"<<c.b;
        return os;
    }
    else{
        os<<"Err number";
        return os;
    }
}
istream& operator>>(istream& is ,Rational& c){
    is>>c.a>>c.b;
    return is;
}
QString& operator<<(QString& s,Rational& c){
    if(c.b>0){
        if((fmod(c.a,c.b)==0.0)||(fmod(c.b,c.a)==0.0)){
            if(c.a==c.b){
                c.a=1;
                c.b=1;
            }
            if(c.a>0){
            if(c.a>c.b){
                c.a=c.a/c.b;
                c.b=1;
            }
            if(c.a<c.b){
                c.b=c.b/c.a;
                c.a=1;
            }
            }else{
            if(c.a<c.b){
                if(fmod(c.b,c.a)==0.0){
                int temp=c.b/(-c.a);
                c.a=c.a/temp;
                c.b=c.b/temp;
                }
                if(fmod(c.b,c.a)!=0.0){
                int temp=(-c.a)/c.b;
                c.a=c.a/temp;
                c.b=c.b/temp;
                }

            }
            }
        }
        if((fmod(c.a,c.b)!=0.0)||(fmod(c.b,c.a)!=0.0)){
            if((c.a>c.b)&&(fmod(c.a,(c.a-c.b))==0)&&(fmod(c.b,(c.a-c.b))==0)){
                double nod=c.a-c.b;
                c.a=c.a/nod;
                c.b=c.b/nod;
            }
            if((c.a<c.b)&&(fmod(c.a,(c.b-c.a))==0)&&(fmod(c.b,(c.b-c.a))==0)){
                double nod=c.b-c.a;
                c.a=c.a/nod;
                c.b=c.b/nod;
            }
        }
        s+=QString().setNum(c.a);
        s+="/";
        s+=QString().setNum(c.b);
        return s;
    }
    else{
        s+="Err number";
        return s;
    }

}

Rational Rational::operator*(Rational c){
    Rational t;
    t.a=a*c.a;
    t.b=b*c.b;
    t.x=t.a/t.b;
    return t.x;
}
Rational Rational::operator+(Rational c){
    Rational t;
    t.a=a*c.b+c.a*b;
    t.b=b*c.b;
    t.x=t.a/t.b;
    return t.x;
}
Rational Rational::operator-(Rational c){
    Rational t;
    t.a=a*c.b-c.a*b;
    t.b=b*c.b;
    t.x=t.a/t.b;
    return t.x;
}
Rational Rational::operator/(Rational c){
    Rational t;
    t.a=a*c.b;
    t.b=b*c.a;
    t.x=t.a/t.b;
    return t.x;
}
double Rational::modul(Rational& c){
    double t = sqrt((c.a * c.a) / (c.b * c.b));
    return t;
}
