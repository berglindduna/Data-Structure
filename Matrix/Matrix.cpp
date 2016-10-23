// 15.01.2016

#include "Matrix.h"

Matrix:: Matrix(int rows, int cols )
{
    Rows = rows;
    Columns = cols;
    arr = new int *[Rows];

    // Create the array
    for (int i = 0; i < Rows; i++)
        arr[i] = new int[Columns];

    // Initialize the array
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Columns; j++)
            arr[i][j] = 0;
    }
}

Matrix:: ~Matrix()
{
    if (arr != NULL) {

        for (int i = 0; i < Rows; i++)
            delete [] arr[i];

        delete [] arr;
    }
}

Matrix Matrix:: transpose()
{
    Matrix transp(Columns, Rows);

    for (int i = 0; i < Columns; i++)
    {
        for (int j = 0; j < Rows; j++)
            transp.arr[i][j] = arr[j][i];
    }

    return transp;
}

istream& operator >> (istream& ins, Matrix& m)
{
    for (int i = 0; i < m.Rows; i++)
    {
        for (int j = 0; j < m.Columns; j++)
            ins >> m.arr[i][j];
    }

    return ins;
}

ostream& operator << (ostream& outs, const Matrix& m)
{
    for (int i = 0; i < m.Rows; i++)
    {
        for (int j = 0; j < m.Columns; j++)
            outs << m.arr[i][j] << " ";

        outs << endl;
    }

    return outs;
}

Matrix operator + (const Matrix &l, const Matrix &r)
{
    Matrix sum(l.Rows, l.Columns);
    for (int i = 0; i < sum.Rows; i++)
    {
        for (int j = 0; j < sum.Columns; j++)
            sum.arr[i][j] = l.arr[i][j] + r.arr[i][j];
    }

    return sum;
}

Matrix operator * (const Matrix &l, const Matrix &r)
{
    Matrix ret(l.Rows, r.Columns);
    int tmp;

    for (int i = 0; i < ret.Rows; i++)
    {
        for (int j = 0; j < ret.Columns; j++)
        {
            tmp = 0;

            for (int k = 0; k < l.Columns; k++)
                tmp += l.arr[i][k] * r.arr[k][j];

            ret.arr[i][j] = tmp;
        }
    }

    return ret;
}
