#ifndef MATRIX_H
#define MATRIX_H
#include "number.h"
#include <iostream>
#include"application.h"
using namespace std;
class Matrix
{
    number **Arr;
    int lines;
    int columns;
public:
    Matrix();
    number** GetArr();
    int GetLines();
    int GetColumns();
    void SwapLines(number** matrix, int line1, int line2, int columns);
    void SetSize(int lines,int columns);
    int findPivot(number** matrix, int columns, int startLines, int numLines);
    int RankMatrix(int lines,int columns);
    void TransponedMatrix(int lines,int columns,number **Arr);
    friend Application;
    ~Matrix();
};
#endif // MATRIX_H
