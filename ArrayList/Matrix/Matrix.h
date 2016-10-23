// 15.01.2016
// Write the ADT Matrix
// The class offers three operations on integer matrices:
//      transpose(), + and *
// In addition, it is possible to read and write matrices using << and >>

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

using namespace std;

class Matrix
{
    public:
        Matrix(int rows, int cols); //constructor
        ~Matrix(); //destructor
        Matrix transpose();
        friend istream& operator >> (istream& ins, Matrix& m);
        friend ostream& operator << (ostream& outs, const Matrix& m);
        friend Matrix operator + (const Matrix &l, const Matrix &r);
        friend Matrix operator * (const Matrix &l, const Matrix &r);

    private:
        int **arr;
        int Rows;
        int Columns;

};

#endif // MATRIX_H
