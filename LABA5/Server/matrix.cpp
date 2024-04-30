#include "matrix.h"
#include <iostream>
#include "number.h"
#include <vector>
using namespace std;


Matrix::Matrix() {

    lines=3;
    columns=3;
    Arr = new number*[lines];
    for(int i = 0; i < 1; i++)
    {
        Arr[i] = new number[columns];
    }
    for(int i = 0; i < lines; i++)
    {
        Arr[i] = new number[columns];
    }
    for (int i=0;i<lines;i++)
    {
        for (int j=0;j<columns;j++)
        {
            Arr[i][j]=(number) rand() / 10;
        }
    }
}
number** Matrix::GetArr(){
    return Arr;
}
int Matrix::GetLines(){
    return lines;
}

int Matrix::GetColumns(){
    return columns;
}




int Matrix::RankMatrix(int lines, int columns)
{
    typedef int mat[lines][columns];
    mat a;
    int rank = lines;
    for (int i = 0; i < lines; i++){
        if (!a[i][i]){
            int j;
            for (j = i+1; j < lines && !a[j][i]; j++)
                if (j == lines){
                    rank--;
                    continue;
                }
            else
                for (int k = i; k < columns; k++){
                    bool t = a[i][k];
                    a[i][k] = a[j][k];
                    a[j][k] = t;
                }
        }
        for (int j = i+1; j < lines; j++){
            if (a[j][i]){
                for (int k = i; k < columns; k++)
                    a[j][k] = a[j][k] - a[i][k];
            }
        }
    }
    return rank;
}



void Matrix::TransponedMatrix(int lines,int columns,number **Arr)
{
    number temp = 0;
    for(int i = 0; i < lines; i++) {
        for(int j = i+1; j < columns; j++) {

            temp = Arr[i][j];
            Arr[i][j] = Arr[j][i];
            Arr[j][i] = temp;

        }
    }
}


void Matrix::SetSize(int lines,int columns)
{
    number** newArr = new number*[lines];
    for(int i = 0; i < lines; i++)
    {
        newArr[i] = new number[columns];
    }
    this->lines = lines;
    this->columns = columns;
    delete[] Arr;
    Arr = newArr;

}


Matrix::~Matrix(){
    for(int i=0;i<lines;i++)
    {
       delete[] Arr[i];
    }
    delete[] Arr;
}
