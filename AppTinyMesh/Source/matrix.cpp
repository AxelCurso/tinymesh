#include "matrix.h"
#include "math.h"
#include <iostream>
using namespace std;

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
        cout << endl;
   }
}

Matrix Matrix::operator+(const Matrix& mat){
    Matrix mat2;
    for (int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            mat2.tab[i][j]=this->tab[i][j]+mat.tab[i][j];
        }
    }
    return mat2;
}

Matrix Matrix::operator-(const Matrix &mat){
    Matrix mat3;
    for (int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            mat3.tab[x][y]=this->tab[x][y]-(mat.tab[x][y]);
              }
    }
    return mat3;
}

Matrix Matrix::operator*(const double scal){
    Matrix mat4;
    for (int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            mat4.tab[x][y]=this->tab[x][y]*scal;
              }
    }
    return mat4;
}

Matrix Matrix::operator*(const Matrix m){
    Matrix mat5;
    mat5.tab[0][0] = this->tab[0][0]*m.tab[0][0] + this->tab[0][1]*m.tab[1][0] + this->tab[0][2]*m.tab[2][0];
    mat5.tab[0][1] = this->tab[0][0]*m.tab[0][1] + this->tab[0][1]*m.tab[1][1] + this->tab[0][2]*m.tab[2][1];
    mat5.tab[0][2] = this->tab[0][0]*m.tab[0][2] + this->tab[0][1]*m.tab[1][2] + this->tab[0][2]*m.tab[2][2];
    mat5.tab[1][0] = this->tab[1][0]*m.tab[0][0] + this->tab[1][1]*m.tab[1][0] + this->tab[1][2]*m.tab[2][0];
    mat5.tab[1][1] = this->tab[1][0]*m.tab[0][1] + this->tab[1][1]*m.tab[1][1] + this->tab[1][2]*m.tab[2][1];
    mat5.tab[1][2] = this->tab[1][0]*m.tab[0][2] + this->tab[1][1]*m.tab[1][2] + this->tab[1][2]*m.tab[2][2];
    mat5.tab[2][0] = this->tab[2][0]*m.tab[0][0] + this->tab[2][1]*m.tab[1][0] + this->tab[2][2]*m.tab[2][0];
    mat5.tab[2][1] = this->tab[2][0]*m.tab[0][1] + this->tab[2][1]*m.tab[1][1] + this->tab[2][2]*m.tab[2][1];
    mat5.tab[2][2] = this->tab[2][0]*m.tab[0][2] + this->tab[2][1]*m.tab[1][2] + this->tab[2][2]*m.tab[2][2];

    return mat5;
}

/*
 * |a b c|
 * |d e f|
 * |g h i|
*/
double Matrix::determinant() {
    double l,n,o,p,q,r;

    l = this->tab[0][0]*this->tab[1][1]*this->tab[2][2]; // a*e*i
    n = this->tab[0][1]*this->tab[1][2]*this->tab[2][0]; // b*f*g
    o = this->tab[0][2]*this->tab[1][0]*this->tab[2][1]; // c*d*h

    p = this->tab[0][2]*this->tab[1][1]*this->tab[2][0]; // c*e*g
    q = this->tab[0][1]*this->tab[1][0]*this->tab[2][2]; // b*d*i
    r = this->tab[0][0]*this->tab[1][2]*this->tab[2][1]; // a*f*h

    return l+n+o-p-q-r;
}

Matrix Matrix::ajustement(){
    Matrix ma;
    ma.tab[0][1]=this->tab[0][1]*-1;
    ma.tab[1][0]=this->tab[1][0]*-1;
    ma.tab[1][2]=this->tab[1][2]*-1;
    ma.tab[2][1]=this->tab[2][1]*-1;
    return ma;
}

//Tourne l'axe Y vers l'axe Z
Matrix Matrix::rotation_X(int theta){
    Matrix m2;
    m2.tab[0][0]=1;m2.tab[0][1]=0;m2.tab[0][2]=0;
    m2.tab[1][0]=0;m2.tab[1][1]=cos(theta);m2.tab[1][2]=-sin(theta);
    m2.tab[2][0]=0;m2.tab[2][1]=sin(theta);m2.tab[2][2]=cos(theta);
    return m2;
}

//Tourne l'axe Z vers l'axe X
Matrix Matrix::rotation_Y(int theta){
    Matrix m2;
    m2.tab[0][0]=cos(theta);m2.tab[0][1]=0;m2.tab[0][2]=sin(theta);
    m2.tab[1][0]=0;m2.tab[1][1]=1;m2.tab[1][2]=0;
    m2.tab[2][0]=-sin(theta);m2.tab[2][1]=0;m2.tab[2][2]=cos(theta);
    return m2;
}

//Tourne l'axe X vers l'axe Y
Matrix Matrix::rotation_Z(int theta){
    Matrix m2;
    m2.tab[0][0]=cos(theta);m2.tab[0][1]=-sin(theta);m2.tab[0][2]=0;
    m2.tab[1][0]=sin(theta);m2.tab[1][1]=cos(theta);m2.tab[1][2]=0;
    m2.tab[2][0]=0;m2.tab[2][1]=0;m2.tab[2][2]=1;
    return m2;
}


/*
 * |a b c|   | x |
 * |d e f| * | y |
 * |g h i|   | z |
*/

Matrix Matrix::homotheties(Matrix m, int x, int y, int z) {


    return m;
}

Matrix Matrix::transpose(){
    Matrix m;
    m.tab[0][0]=this->tab[0][0];m.tab[1][0]=this->tab[0][1];m.tab[2][0]=this->tab[0][2];
    m.tab[0][1]=this->tab[1][0];m.tab[1][1]=this->tab[1][1];m.tab[2][1]=this->tab[1][2];
    m.tab[0][2]=this->tab[2][0];m.tab[1][2]=this->tab[2][1];m.tab[2][2]=this->tab[2][2];
    return m;
}

Matrix Matrix::inverse(){
    Matrix m2;
    int det = this->determinant();
    if(det!=0){

        Matrix tmp;
        m2=this->transpose();
        //décomposition de m2 en sous matrice 2x2 et calcul de tout les DET
        tmp.tab[0][0] = m2.tab[1][1]*m2.tab[2][2]-(m2.tab[2][1]*m2.tab[1][2]);
        tmp.tab[0][1] = m2.tab[1][0]*m2.tab[2][2]-(m2.tab[2][0]*m2.tab[1][2]);
        tmp.tab[0][2] = m2.tab[1][0]*m2.tab[2][1]-(m2.tab[2][0]*m2.tab[1][1]);
        tmp.tab[1][0] = m2.tab[0][1]*m2.tab[0][0]-(m2.tab[2][1]*m2.tab[0][2]); //
        tmp.tab[1][1] = m2.tab[1][0]*m2.tab[2][2]-(m2.tab[2][0]*m2.tab[0][2]);
        tmp.tab[1][2] = m2.tab[0][0]*m2.tab[2][1]-(m2.tab[2][0]*m2.tab[0][1]);
        tmp.tab[2][0] = m2.tab[0][1]*m2.tab[1][2]-(m2.tab[1][1]*m2.tab[0][2]);
        tmp.tab[2][1] = m2.tab[0][0]*m2.tab[1][2]-(m2.tab[1][0]*m2.tab[0][2]);
        tmp.tab[2][2] = m2.tab[0][0]*m2.tab[1][1]-(m2.tab[1][0]*m2.tab[0][1]);
        //tmp = tmp.ajustement();
        //tmp.affichage();
        Matrix mInverse;
        for(int i = 0; i<3;i++){
            for (int j = 0; j<3;j++){
                mInverse.tab[i][j] = tmp.tab[i][j]/det;
            }
        }
        return mInverse;
    }

    return m2;
}
