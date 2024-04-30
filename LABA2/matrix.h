#ifndef TMATRIX_H
#define TMATRIX_H

#include "number.h"
#include <iostream>

class Matrix {
private:
    int size=3;
    number **data;

public:
    Matrix(); // конструктор по умолчанию
    ~Matrix(); // деструктор
    number** Getdata();
    int GetSize();
    number determinant(number**data); // метод для расчета определителя матрицы
    void transpose(int size, number**data); // метод для формирования транспонированной матрицы
    int rank(int size, number**data); // метод для расчета ранга матрицы
    void display(int size, number**data); // метод для вывода матрицы в консоль
    void enterMatrix(int size, number **data); //метод для ввода значений матрицы
};



#endif // TAPPLICATION_H
