#include <QString>
#include <vector>

using namespace std;

template <class number>
class TMatrix
{
protected:
    int dim = 4;
    vector<vector<number>> defaultMatrix = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};

public:
    number getElement(int, int);
    number getDimension();

    void setElement(number, int, int);
    void setDimension(int);
};

template <class number>
number TMatrix<number>::getElement(int i, int j)
{
    return defaultMatrix[i][j];
}

template <class number>
number TMatrix<number>::getDimension()
{
    return this->n;
}

template <class number>
void TMatrix<number>::setElement(number el, int i, int j)
{
    defaultMatrix[i][j] = el;
}

template <class number>
void TMatrix<number>::setDimension(int d1)
{
    this->dim = d1;
    defaultMatrix.resize(d1);
    for (int i = 0; i < d1; i++) defaultMatrix[i].resize(d1);
}
