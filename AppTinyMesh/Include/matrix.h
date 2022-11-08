#ifndef MATRIX_H
#define MATRIX_H

#include "mathematics.h"

class Matrix
{

private:
    double tab[3][3];

public:
    Matrix();
    Matrix(double a,double b,double c,
           double d,double e,double f,
           double g,double h,double i);
    ~Matrix();
    void affichage();

    Matrix operator+(const Matrix &mat);
    Matrix operator-(const Matrix &mat);
    Matrix operator*(const double scal);
    Matrix operator*(const Matrix m);

    double determinant() ;
    Matrix ajustement();
    Matrix rotation_X(int theta);
    Matrix rotation_Y(int theta);
    Matrix rotation_Z(int theta);
    Matrix homotheties(Matrix m, int x, int y, int z);
    Matrix transpose();
    Matrix inverse();
};

#endif // MATRIX_H
