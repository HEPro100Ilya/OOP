#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include"application.h"
#include "rational.h"
#include "complex.h"
#include <vector>
using namespace std;
template<class number>
class Matrix
{
    number **Arr;
    int rows;
    int cols;
public:

    Matrix();
    number** GetArr();
    int GetRows();
    int GetCols();
    void SetSize(int rows,int cols);
    int RankMatrix();
    void TransponedMatrix();
    friend Application;
    ~Matrix();
};
template <class number>
Matrix<number>::Matrix() {

    rows=3;
    cols=3;
    Arr = new number*[rows];
    for(int i = 0; i < 1; i++)
    {
        Arr[i] = new number[cols];
    }
    for(int i = 0; i < rows; i++)
    {
        Arr[i] = new number[cols];
    }
    for (int i=0;i<rows;i++)
    {
        for (int j=0;j<cols;j++)
        {
            Arr[i][j]=(number) rand() / 10;
        }
    }
}
template<class number>
number** Matrix<number>::GetArr(){
    return Arr;
}
template<class number>
int Matrix<number>::GetRows(){
    return rows;
}
template<class number>
int Matrix<number>::GetCols(){
    return cols;
}
double abs(Rational c){
    double t = c.abs(c);
    return t;
}
double abs(complex c){
    double t = c.abs(c);
    return t;
}
template<class number>
int Matrix<number>::RankMatrix(){
    number** ArrChange = new number*[rows];
    for (int i = 0; i < rows; i++)
    {
        ArrChange[i] = new number[cols];
        for (int j = 0; j < cols; j++)
        {
            ArrChange[i][j] = Arr[i][j];
        }
    }
    const double EPS = 1E-9;
    int rank = max(rows,cols);
    vector<char> line_used (cols);
    for (int i=0; i<rows; ++i) {
        int j;
        for (j=0; j<cols; ++j)
            if (!line_used[j] && abs(ArrChange[j][i]) > EPS)
                break;
        if (j == cols)
            --rank;
        else {
            line_used[j] = true;
            for (int p=i+1; p<rows; ++p)
                ArrChange[j][p] =ArrChange[j][p] / ArrChange[j][i];
            for (int k=0; k<cols; ++k)
                if (k != j && abs(ArrChange[k][i]) > EPS)
                    for (int p=i+1; p<rows; ++p)
                       ArrChange[k][p] =ArrChange[k][p] - ArrChange[j][p] * ArrChange[k][i];
        }
    }
    for(int i=0;i<rows;i++)
    {
        delete[] ArrChange[i];
    }
    delete[] ArrChange;

    return rank;
}

template<class number>
void Matrix<number>::TransponedMatrix()
{
    number temp = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = i+1; j < cols; j++) {

            temp = Arr[i][j];
            Arr[i][j] = Arr[j][i];
            Arr[j][i] = temp;

        }
    }
}
template<class number>
void Matrix<number>::SetSize(int rows,int cols)
{
    number** newArr = new number*[rows];
    for(int i = 0; i < rows; i++)
    {
        newArr[i] = new number[cols];
    }
    this->rows = rows;
    this->cols = cols;
    delete[] Arr;
    Arr = newArr;

}
template<class number>
Matrix<number>::~Matrix(){
    for(int i=0;i<rows;i++)
    {
        delete[] Arr[i];
    }
    delete[] Arr;
}

#endif // MATRIX_H
