// MATRIX

// Self include
#include "matrix.h"

#include <iostream>

Matrix::Matrix(){
   for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            tab[i][j]=3;
        }
   }
}

Matrix::Matrix(double a,double b,double c,
               double d,double e,double f,
               double g,double h,double i){
   tab[0][0]=a; tab[0][1]=b; tab[0][2]=c;
   tab[1][0]=d; tab[1][1]=e; tab[1][2]=f;
   tab[2][0]=g; tab[2][1]=h; tab[2][2]=i;
}

Matrix::~Matrix(){}

void Matrix::affichage() {
   for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            std::cout << tab[i][j] << " ";
        }
        std::cout << std::endl;
   }
}

Matrix Matrix::operator+(const Matrix& mat){
    Matrix res;

    for (int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            res.tab[i][j]=this->tab[i][j]+mat.tab[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator-(const Matrix &mat){
    Matrix res;

    for (int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            res.tab[x][y]=this->tab[x][y]-(mat.tab[x][y]);
              }
    }
    return res;
}

Matrix Matrix::operator*(const double scal){
    Matrix res;

    for (int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            res.tab[x][y]=this->tab[x][y]*scal;
              }
    }
    return res;
}

Matrix Matrix::operator*(const Matrix m){
    Matrix res;

    res.tab[0][0] = this->tab[0][0]*m.tab[0][0] + this->tab[0][1]*m.tab[1][0] + this->tab[0][2]*m.tab[2][0];
    res.tab[0][1] = this->tab[0][0]*m.tab[0][1] + this->tab[0][1]*m.tab[1][1] + this->tab[0][2]*m.tab[2][1];
    res.tab[0][2] = this->tab[0][0]*m.tab[0][2] + this->tab[0][1]*m.tab[1][2] + this->tab[0][2]*m.tab[2][2];
    res.tab[1][0] = this->tab[1][0]*m.tab[0][0] + this->tab[1][1]*m.tab[1][0] + this->tab[1][2]*m.tab[2][0];
    res.tab[1][1] = this->tab[1][0]*m.tab[0][1] + this->tab[1][1]*m.tab[1][1] + this->tab[1][2]*m.tab[2][1];
    res.tab[1][2] = this->tab[1][0]*m.tab[0][2] + this->tab[1][1]*m.tab[1][2] + this->tab[1][2]*m.tab[2][2];
    res.tab[2][0] = this->tab[2][0]*m.tab[0][0] + this->tab[2][1]*m.tab[1][0] + this->tab[2][2]*m.tab[2][0];
    res.tab[2][1] = this->tab[2][0]*m.tab[0][1] + this->tab[2][1]*m.tab[1][1] + this->tab[2][2]*m.tab[2][1];
    res.tab[2][2] = this->tab[2][0]*m.tab[0][2] + this->tab[2][1]*m.tab[1][2] + this->tab[2][2]*m.tab[2][2];

    return res;
}

/*
 * |a b c|
 * |d e f|
 * |g h i|
*/
double Matrix::determinant() {
    double aei, bfg, cdh, ceg, bdi, afh;

    aei = this->tab[0][0]*this->tab[1][1]*this->tab[2][2];
    bfg = this->tab[0][1]*this->tab[1][2]*this->tab[2][0];
    cdh = this->tab[0][2]*this->tab[1][0]*this->tab[2][1];

    ceg = this->tab[0][2]*this->tab[1][1]*this->tab[2][0];
    bdi = this->tab[0][1]*this->tab[1][0]*this->tab[2][2];
    afh = this->tab[0][0]*this->tab[1][2]*this->tab[2][1];

    return aei + bfg + cdh - ceg - bdi - afh;
}

Matrix Matrix::ajustement(){
    Matrix res;

    res.tab[0][1]=this->tab[0][1]*-1;
    res.tab[1][0]=this->tab[1][0]*-1;
    res.tab[1][2]=this->tab[1][2]*-1;
    res.tab[2][1]=this->tab[2][1]*-1;
    return res;
}

//Tourne l'axe Y vers l'axe Z
Matrix Matrix::rotation_X(int theta){
    Matrix res;

    res.tab[0][0]=1;
    res.tab[0][1]=0;
    res.tab[0][2]=0;

    res.tab[1][0]=0;
    res.tab[1][1]=cos(theta);
    res.tab[1][2]=-sin(theta);

    res.tab[2][0]=0;
    res.tab[2][1]=sin(theta);
    res.tab[2][2]=cos(theta);
    return res;
}

//Tourne l'axe Z vers l'axe X
Matrix Matrix::rotation_Y(int theta){
    Matrix res;

    res.tab[0][0]=cos(theta);
    res.tab[0][1]=0;
    res.tab[0][2]=sin(theta);

    res.tab[1][0]=0;
    res.tab[1][1]=1;
    res.tab[1][2]=0;

    res.tab[2][0]=-sin(theta);
    res.tab[2][1]=0;
    res.tab[2][2]=cos(theta);
    return res;
}

//Tourne l'axe X vers l'axe Y
Matrix Matrix::rotation_Z(int theta){
    Matrix res;

    res.tab[0][0]=cos(theta);
    res.tab[0][1]=-sin(theta);
    res.tab[0][2]=0;

    res.tab[1][0]=sin(theta);
    res.tab[1][1]=cos(theta);
    res.tab[1][2]=0;

    res.tab[2][0]=0;res.tab[2][1]=0;res.tab[2][2]=1;
    return res;
}


/*
 * |a b c|   | x |
 * |d e f| * | y |
 * |g h i|   | z |
*/

Matrix Matrix::homotheties(Matrix m, int x, int y, int z) {
    Matrix tmp(x, 0, 0, 0, y, 0, 0, 0, z);

    return m*tmp;
}

Matrix Matrix::transpose(){
    Matrix res;
    res.tab[0][0]=this->tab[0][0];
    res.tab[0][1]=this->tab[1][0];
    res.tab[0][2]=this->tab[2][0];;

    res.tab[1][0]=this->tab[0][1];
    res.tab[1][1]=this->tab[1][1];
    res.tab[1][2]=this->tab[2][1];

    res.tab[2][0]=this->tab[0][2];
    res.tab[2][1]=this->tab[1][2];
    res.tab[2][2]=this->tab[2][2];
    return res;
}

Matrix Matrix::inverse(){
    Matrix res;
    int det = this->determinant();
    if(det!=0){

        Matrix tmp;
        res=this->transpose();
        //décomposition de m2 en sous matrice 2x2 et calcul de tout les DET
        tmp.tab[0][0] = res.tab[1][1]*res.tab[2][2]-(res.tab[2][1]*res.tab[1][2]);
        tmp.tab[0][1] = res.tab[1][0]*res.tab[2][2]-(res.tab[2][0]*res.tab[1][2]);
        tmp.tab[0][2] = res.tab[1][0]*res.tab[2][1]-(res.tab[2][0]*res.tab[1][1]);
        tmp.tab[1][0] = res.tab[0][1]*res.tab[0][0]-(res.tab[2][1]*res.tab[0][2]);
        tmp.tab[1][1] = res.tab[1][0]*res.tab[2][2]-(res.tab[2][0]*res.tab[0][2]);
        tmp.tab[1][2] = res.tab[0][0]*res.tab[2][1]-(res.tab[2][0]*res.tab[0][1]);
        tmp.tab[2][0] = res.tab[0][1]*res.tab[1][2]-(res.tab[1][1]*res.tab[0][2]);
        tmp.tab[2][1] = res.tab[0][0]*res.tab[1][2]-(res.tab[1][0]*res.tab[0][2]);
        tmp.tab[2][2] = res.tab[0][0]*res.tab[1][1]-(res.tab[1][0]*res.tab[0][1]);

        Matrix mInverse;
        for(int i = 0; i<3;i++){
            for (int j = 0; j<3;j++){
                mInverse.tab[i][j] = tmp.tab[i][j]/det;
            }
        }
        return mInverse;
    }

    return res;
}
