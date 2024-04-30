#include "boxymatrix.h"

boxymatrix::boxymatrix()
{

}
number boxymatrix::Determinant(int size, number **Arr)
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
            ArrChange[i][j]=Arr[j][i];

        }
    }
    number det = 1.0;
    number modul;
    for (int i = 0; i < size; i++) {
        int k = i;
        for (int j = i + 1; j < size; j++)
            if (modul.modul(ArrChange[j][i]) > modul.modul(ArrChange[k][i]))
                k = j;

        if (modul.modul(ArrChange[k][i]) < 1e-9) {
            det = 0.0;
            break;
        }

        swap(ArrChange[i], ArrChange[k]);
        if (i != k)
            det = det *(-1.0);

        for (int j = i + 1; j < size; j++)
            ArrChange[i][j] = ArrChange[i][j] / ArrChange[i][i];

        for (int j = 0; j < size; j++) {
            if (j == i || modul.modul(ArrChange[j][i]) < 1e-9)
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
