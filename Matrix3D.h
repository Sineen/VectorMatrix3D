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

    /**
     * contsructor with all zeros
     */
    Matrix3D():firstRow(Vector3D()),
               secondRow(Vector3D()),
               thirdRow(Vector3D()){}
    /**
     * constructor with one numbe rin the diagonal
     */
    Matrix3D(double number):
            firstRow(Vector3D(number, 0, 0)),
            secondRow(Vector3D(0, number, 0)),
            thirdRow(Vector3D(0, 0, number)){}
    /**
     *constructor with 9 numbers
     */
    Matrix3D(double x1, double x2, double x3,
            double x4, double x5, double x6,
            double x7, double x8, double x9):
            firstRow(Vector3D(x1, x2, x3)),
            secondRow(Vector3D(x4, x5, x6)),
            thirdRow(Vector3D(x7, x8, x9)){}
    /**
     * constructor wit an array of 9 doubles
     */
    Matrix3D(const double array[9]);

    /**
     * constructor from matrix of doubles 3 x3
     */
    Matrix3D(const double coordinates[3][3]);

    /**
     *
     * @param firstVector a vector 3d would be first row
     * @param secondVector  a vector 3d would be second row
     * @param thirdVector a vector 3d would be tird row
     */
    Matrix3D(const Vector3D& firstVector, const Vector3D& secondVector, const Vector3D& thirdVector);

    /**
     *
     * @param second
     */
    Matrix3D(const Matrix3D& second);

    /**
     *
     * @param other
     * @return
     */
    Matrix3D& operator+=(const Matrix3D &other);

    /**
     *
     * @param other
     * @return
     */
    Matrix3D& operator-=(const Matrix3D &other);

    /**
     *
     * @param other
     * @return
     */
    Matrix3D& operator*=(const Matrix3D &other);

    /**
     *
     * @param other
     * @return
     */
    Matrix3D operator+(const Matrix3D &other);

    /**
     *
     * @param other
     * @return
     */
    Matrix3D operator-(const Matrix3D &other);

    /**
     *
     * @param other
     * @return
     */
    Matrix3D operator*(const Matrix3D &other);

    /**
     *
     * @param number
     * @return
     */
    Matrix3D& operator*=(double number);

    /**
     *
     */
    Matrix3D& operator/=(double number);

    /**
     *
     * @param vector
     * @return
     */
    Vector3D operator*(const Vector3D vector);

    /**
     *
     * @param is
     * @param mat
     * @return
     */
    friend istream &operator>>(istream &is, Matrix3D &mat);

    /**
     *
     * @param os
     * @param mat
     * @return
     */
    friend ostream &operator<<(ostream &os, const Matrix3D &mat);

    /**
     *
     * @param mat
     * @return
     */
    Matrix3D &operator=(const Matrix3D &mat);

    /**
     *
     * @param index
     * @return
     */
    Vector3D& operator[](int index);

    /**
     *
     * @param index
     * @return
     */
    Vector3D operator[](int index) const;

    /**
     *
     * @param index
     * @return
     */
    Vector3D row(short index) const;

    /**
     *
     * @param index
     * @return
     */
    Vector3D column(short index) const;

    /**
     *
     * @return
     */
    double trace() const;

    /**
     *
     * @return
     */
    double determinant() const;
};

#endif //EX1VM_MATRIX3D_H
