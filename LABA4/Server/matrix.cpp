#include "matrix.h"
#include <iostream>
#include "number.h"
#include <vector>
using namespace std;


Matrix::Matrix() {
    Arr = new number*[size];
    for(int i = 0; i < 1; i++)
    {
        Arr[i] = new number[size];
    }
    for(int i = 0; i < size; i++)
    {
        Arr[i] = new number[size];
    }
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            Arr[i][j]=(number) rand() / 10;

        }
    }
}
number** Matrix::GetArr(){
    return Arr;
}
int Matrix::GetSize(){
    return size;
}
void Matrix::ShowMatrix(int size,number **Arr)
{   cout<<endl<<"Matrix: "<<endl;
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            cout<<Arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void Matrix::EnterMatrix(int size,number **Arr)
{
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            cin>>Arr[i][j];
        }
    }
}
number Matrix::DetMatrix(number **Arr){
    return Arr[0][0]*Arr[1][1]*Arr[2][2]+Arr[0][2]*Arr[1][0]*Arr[2][1]+Arr[0][1]*Arr[1][2]*Arr[2][0]-Arr[0][2]*Arr[1][1]*Arr[2][0]-Arr[0][0]*Arr[1][2]*Arr[2][1]-Arr[0][1]*Arr[1][0]*Arr[2][2];;
}
int Matrix::RankMatrix(int size,number **Arr){
    const double EPS = 1E-9;
    number** ArrChange = new number*[size];
    for(int i = 0; i < 1; i++)
    {
        ArrChange[i] = new number[size];
    }
    for(int i = 0; i < size; i++)
    {
        ArrChange[i] = new number[size];
    }
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            ArrChange[i][j]=Arr[i][j];

        }
    }
    int rank = size;
    vector<char> line_used (size);
    number modul;
    for (int i=0; i<size; ++i) {
        int j;
        for (j=0; j<size; ++j)
            if (!line_used[j] && modul.modul(ArrChange[j][i]) > EPS)
                break;
        if (j == size)
            --rank;
        else {
            line_used[j] = true;
            for (int p=i+1; p<size; ++p)
                ArrChange[j][p] = ArrChange[j][p]/ArrChange[j][i];
            for (int k=0; k<size; ++k)
                if (k != j && modul.modul(ArrChange[k][i]) > EPS)
                    for (int p=i+1; p<size; ++p)
                        ArrChange[k][p] =ArrChange[k][p]- ArrChange[j][p] * ArrChange[k][i];
        }
    }
    for(int i=0;i<size;i++)
    {
        delete[] ArrChange[i];
    }
    delete[] ArrChange;
    return rank;
}
void Matrix::TransponedMatrix(int size,number **Arr)
{
    number k=0;
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1;j++)
        {

            k=Arr[i][j+1];
            Arr[i][j+1]=Arr[i+1][j];
            Arr[i+1][j]=k;

        }
    }
    k=Arr[1][1];
    Arr[1][1]=Arr[0][2];
    Arr[0][2]=k;
    //   for(int i=0;i<size;i++)
    //   {
    //                for(int j=0;j<size;j++)
    //                {
    //            cout<<Arr[i][j]<<" ";

    //                }
    //                cout<<endl;
    //   }
}

Matrix::~Matrix(){
    for(int i=0;i<size;i++)
    {
        delete[] Arr[i];
    }
    delete[] Arr;
}
