//
// Created by sin_een on 12/20/18.
//

#ifndef EX1VM_MATRIX3D_H
#define EX1VM_MATRIX3D_H
#include <iostream>
#include "Vector3D.h"

using namespace std;

class Matrix3D
{
private:
    Vector3D firstRow;
    Vector3D secondRow;
    Vector3D thirdRow;

public:

    Matrix3D():firstRow(Vector3D()),
               secondRow(Vector3D()),
               thirdRow(Vector3D()){}

    Matrix3D(double number):
            firstRow(Vector3D(number, 0, 0)),
            secondRow(Vector3D(0, number, 0)),
            thirdRow(Vector3D(0, 0, number)){}

    Matrix3D(double x1, double x2, double x3,
            double x4, double x5, double x6,
            double x7, double x8, double x9):
            firstRow(Vector3D(x1, x2, x3)),
            secondRow(Vector3D(x4, x5, x6)),
            thirdRow(Vector3D(x7, x8, x9)){}

    Matrix3D(double array[9]);

    Matrix3D(double coordinates[3][3]);

    Matrix3D(Vector3D& firstVector, Vector3D& secondVector, Vector3D& thirdVector);

    Matrix3D(Matrix3D& second);

    Matrix3D& operator+=(Matrix3D &other);

    Matrix3D& operator-=(Matrix3D &other);

    Matrix3D& operator=*(Matrix3D &other);

    Matrix3D operator+(Matrix3D &other);

    Matrix3D operator-(Matrix3D &other);

    Matrix3D operator*(Matrix3D &other);

    Matrix3D& operator*=(double number);

    Matrix3D& operator/=(double number);




};

#endif //EX1VM_MATRIX3D_H
