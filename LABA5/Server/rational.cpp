#include "rational.h"
#include <iostream>
#include <math.h>
#include <cmath>
#include "common.h"
QChar Rational::SEPARATOR = separator;

Rational::Rational()
{

}
Rational::Rational(const int& A){
    a=A;
    b=1;

}
Rational::Rational(int A,int B){
    a=A;
    b=B;
}
int Rational::GetA(){
    return a;
}
int Rational::GetB(){
    return b;
}
ostream& operator<<(ostream& os ,Rational& c){
    if(c.b>0){
        if(((c.a%c.b)==0)||((c.b%c.a)==0)){
            if(c.a>c.b){
                c.a=c.a/c.b;
                c.b=1;
            }
            if(c.a<c.b){
                c.b=c.b/c.a;
                c.a=1;
            }
        }
        if(((c.a%c.b)!=0)||((c.b%c.a)!=0)){
            if((c.a>c.b)&&((c.a%(c.a-c.b))==0)&&((c.b%(c.a-c.b))==0)){
                int nod=c.a-c.b;
                c.a=c.a/nod;
                c.b=c.b/nod;
            }
            if((c.a<c.b)&&((c.a%(c.b-c.a))==0)&&((c.b%(c.b-c.a))==0)){
                int nod=c.b-c.a;
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
        if(((c.a%c.b)==0)||((c.b%c.a)==0)) {
            if(c.a==c.b){
                c.a=1;
                c.b=1;
            }
            else if(c.a>0){
                if(c.a>c.b){
                    c.a=c.a/c.b;
                    c.b=1;
                }
                if(c.a<c.b){
                    c.b=c.b/c.a;
                    c.a=1;
                }
            }
            else{
                if(c.a<c.b){
                    if((c.b%c.a)==0){
                        int temp=c.b+c.a;
                        c.a=c.a/temp;
                        c.b=c.b/temp;
                    }
                    if((c.b%c.a)!=0){
                        int temp=c.b+c.a;
                        c.a=c.a/(-temp);
                        c.b=c.b/(-temp);
                    }

                }
            }
        }
        if(((c.a%c.b)!=0)||((c.b%c.a)!=0)){
            if((c.a>c.b)&&((c.a%(c.a-c.b))==0)&&((c.b%(c.a-c.b))==0)){
                int nod=c.a-c.b;
                c.a=c.a/nod;
                c.b=c.b/nod;
            }
            if((c.a<c.b)&&((c.a%(c.b-c.a))==0)&&((c.b%(c.b-c.a))==0)){
                int nod=c.b-c.a;
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
    t.x=(double)t.a/(double)t.b;
    return t;
}
Rational Rational::operator+(Rational c){
    Rational t;
    t.a=a*c.b+c.a*b;
    t.b=b*c.b;
    t.x=(double)t.a/(double)t.b;
    return t;
}
Rational Rational::operator-(Rational c){
    Rational t;
    t.a=a*c.b-c.a*b;
    t.b=b*c.b;
    t.x=(double)t.a/(double)t.b;
    return t;
}
Rational Rational::operator/(Rational c){
    Rational t;
    t.a=a*c.b;
    t.b=b*c.a;
    t.x=(double)t.a/(double)t.b;
    return t;

}

bool Rational::operator!=(Rational c){
    return x != c.x;
}
double Rational::modul(Rational& c){
    double t = (double)sqrt((c.a * c.a) / (double)(c.b * c.b));
    return t;
}
Rational::Rational(const QByteArray& arr)
{
    int p = arr.indexOf(Rational::SEPARATOR);
    a = arr.left(p).toInt();
    b = arr.right(arr.length()-p-1).toInt();
}

QByteArray& operator>>(QByteArray& arr, Rational& c)
{
    int p = arr.indexOf(Rational::SEPARATOR);
    p = arr.indexOf(Rational::SEPARATOR,p+1);
    if (p > 0)
    {
        c = Rational(arr.left(p));
        arr = arr.right(arr.length()-p-1);
    }
    return arr;
}
void Rational::setSeparator(QChar ch)
{
    SEPARATOR = ch;
}
