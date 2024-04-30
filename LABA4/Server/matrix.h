#ifndef MATRIX_H
#define MATRIX_H
#include "number.h"
#include <iostream>
#include"application.h"
using namespace std;
class Matrix
{
    number **Arr;
    int size=3;
public:
    Matrix();
    number** GetArr();
    int GetSize();
    void ShowMatrix(int size,number **Arr);
    void EnterMatrix(int size,number **Arr);
    number DetMatrix(number **Arr);
    int RankMatrix(int size,number **Arr);
    void TransponedMatrix(int size,number **Arr);
    friend Application;
    ~Matrix();
};
#endif // MATRIX_H
