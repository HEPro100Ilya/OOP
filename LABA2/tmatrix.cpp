#include "matrix.h"
#include <iostream>
#include <vector>
#include <number.h>

using namespace std;

Matrix::Matrix() {
    data = new number*[size];
    for (int i = 0; i < size; i++) {
        data[i] = new number[size];
    }

}

Matrix::~Matrix() {
    for (int i = 0; i < size; i++) {
        delete[] data[i];
    }
    delete[] data;
}

number** Matrix::Getdata(){
    return data;
}
int Matrix::GetSize(){
    return size;
}

void Matrix::enterMatrix(int size,number **Arr)
{
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            cin>>Arr[i][j];
        }
    }
}


number Matrix::determinant(number**data) {
   return data[0][0]*data[1][1]*data[2][2]+data[0][2]*data[1][0]*data[2][1]+data[0][1]*data[1][2]*data[2][0]-data[0][2]*data[1][1]*data[2][0]-data[0][0]*data[1][2]*data[2][1]-data[0][1]*data[1][0]*data[2][2];

}

void Matrix::transpose(int size, number**data) {
    {
       number T_mat=0;
       for(int i=0;i<size-1;i++)
       {
                    for(int j=0;j<size-1;j++)
                    {

                T_mat=data[i][j+1];
                data[i][j+1]=data[i+1][j];
                data[i+1][j]=T_mat;

                    }
       }
       T_mat=data[1][1];
       data[1][1]=data[0][2];
       data[0][2]=T_mat;
       for(int i=0;i<size;i++)
       {
                    for(int j=0;j<size;j++)
                    {
                cout<<data[i][j]<<" ";

                    }
                    cout<<endl;
       }
    }

    // реализация формирования транспонированной матрицы
}


int Matrix::rank(int size, number**data)
{
    const double EPS = 1E-9;
       number** DataChange = new number*[size];
       for(int i = 0; i < 1; i++)
       {
            DataChange[i] = new number[size];
       }
       for(int i = 0; i < size; i++)
       {
            DataChange[i] = new number[size];
       }
       for (int i=0;i<size;i++)
       {
            for (int j=0;j<size;j++)
            {
                DataChange[i][j]=data[i][j];

            }
       }
       int rank = size;
       vector<char> line_used (size);
       number modul;
       for (int i=0; i<size; ++i) {
            int j;
            for (j=0; j<size; ++j)
                if (!line_used[j] && modul.modul(DataChange[j][i]) > EPS)
                    break;
            if (j == size)
                --rank;
            else {
                line_used[j] = true;
                for (int p=i+1; p<size; ++p)
                    DataChange[j][p] / DataChange[j][i];
                for (int k=0; k<size; ++k)
                    if (k != j && modul.modul (DataChange[k][i]) > EPS)
                        for (int p=i+1; p<size; ++p)
                            DataChange[k][p] =DataChange[k][p]- DataChange[j][p] * DataChange[k][i];
                    }
       }
       for(int i=0;i<size;i++)
       {
                    delete[] DataChange[i];
       }
       delete[] DataChange;
       return rank;

    // реалиация расчета ранга матрицы
}


void Matrix::display(int size, number**data) {
    {
            cout << "Output of matrix elements: " << endl;
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j)
                {
                    cout << data[i][j] << " ";
                }
                cout <<endl;
            }
        }
    // реализация вывода значений матрицы
}




