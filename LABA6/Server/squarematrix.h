#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H
#include "matrix.h"
template <class number>
class SquareMatrix:public Matrix<number>
{
public:
    SquareMatrix();
    friend Application;
    number DetSquareM(int size,number **Arr);
};
template <class number>
SquareMatrix<number>::SquareMatrix()
{

}
template <class number>
number SquareMatrix<number>::DetSquareM(int size,number **Arr)
{
    number** ArrChange = new number*[size];
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
    number det = 1.0;
    for (int i = 0; i < size; i++) {
        int k = i;
        for (int j = i + 1; j < size; j++)
            if (abs(ArrChange[j][i]) > abs(ArrChange[k][i]))
                k = j;

        if (abs(ArrChange[k][i]) < 1e-9) {
            det = 0.0;
            break;
        }

        swap(ArrChange[i], ArrChange[k]);
        if (i != k)
            det = det *(-1.0);

        for (int j = i + 1; j < size; j++)
            ArrChange[i][j] = ArrChange[i][j] / ArrChange[i][i];

        for (int j = 0; j < size; j++) {
            if (j == i || abs(ArrChange[j][i]) < 1e-9)
                continue;

            for (int k = i + 1; k < size; k++)
                ArrChange[j][k] = ArrChange[j][k] - ArrChange[i][k] * ArrChange[j][i];
        }
    }

    for (int i = 0; i < size; i++)
        det = det * ArrChange[i][i];
    for(int i=0;i<size;i++)
    {
        delete[] ArrChange[i];
    }
    delete[] ArrChange;
    return det;
}
#endif // SQUAREMATRIX_H
