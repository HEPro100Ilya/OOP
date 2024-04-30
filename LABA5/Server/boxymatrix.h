#ifndef BOXYMATRIX_H
#define BOXYMATRIX_H
#include "matrix.h"

class boxymatrix:public Matrix
{
public:
    boxymatrix();
    friend Application;
    number Determinant(int size, number **Arr);
};

#endif // BOXYMATRIX_H
