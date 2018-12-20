//
// Created by sin_een on 12/20/18.
//

#ifndef EX1VM_MATRIX3D_H
#define EX1VM_MATRIX3D_H
#include <iostream>
#include "Vector3D.h"

using namespace std;

/**
 *
 */

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
    Matrix3D(double x1, double x2, double x3, double x4, double x5, double x6, double x7, double x8, double x9):
            firstRow(Vector3D(x1, x2, x3)), secondRow(Vector3D(x4, x5, x6)), thirdRow(Vector3D(x7, x8, x9)){}
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
     *  constructor from another matrix3D
     * @param second the second 3D Matrix
     */
    Matrix3D(const Matrix3D& second);

    /**
     * addes two matrixes
     * @param other a second matrix
     * @return the matrix of this class
     */
    Matrix3D& operator+=(const Matrix3D &other);

    /**
     * subtracts two matrixes  and puts the vlaues  on teh matrix in the class
     * @param other a second matrix
     * @return the matrix of the class
     */
    Matrix3D& operator-=(const Matrix3D &other);

    /**
     * multiplications two matrixes  and puts the vlaues  on teh matrix in the class
     * @param other a second matrix
     * @return the matrix of the class
     */
    Matrix3D& operator*=(const Matrix3D &other);

    /**
     * addes the object of this class to other adn makes a new matrix and returns that
     * @param other another matrix3D
     */
    Matrix3D operator+(const Matrix3D &other);

    /**
     * subtracts the object of this class to other adn makes a new matrix and returns that
     * @param other another matrix3D
     */
    Matrix3D operator-(const Matrix3D &other);

    /**
     * multiplication the object of this class to other adn makes a new matrix and returns that
     * @param other another matrix3D
     */
    Matrix3D operator*(const Matrix3D &other);

    /**
     * @param number a double number
     * @return multiplications of the matrix with the number and returns the object
     */
    Matrix3D& operator*=(double number);

    /**
     * @param number a double number
     * @return multiplications of the matrix with the number and returns the object
     */
    Matrix3D& operator/=(double number);

    /**
     * @param vector a vectro of type VECTOR 3D
     * @return a vector 3d that is a multiplication of the matrix and the vector
     */
    Vector3D operator*(const Vector3D vector);

    /**
     * recieves matrix from stdin
     * @param mat a matrix
     * @return reads the values from the input and puts it in mat
     */
    friend istream &operator>>(istream &is, Matrix3D &mat);

    /**
     * @param os the output stream
     * @param mat a matrix 3D
     * @return reads what we have matrix into the os
     */
    friend ostream &operator<<(ostream &os, const Matrix3D &mat);

    /**
     * @param mat a matrix3D
     * @return uplouds teh matrix in the object of teh class
     */
    Matrix3D &operator=(const Matrix3D &mat);

    /**
     * @param index number of index we want
     * @return a refrence that is in the palce of the index
     */
    Vector3D& operator[](int index);

    /**
     *
      * @param index number of index we want
     * @return a value that is in the palce of the index
     */
    Vector3D operator[](int index) const;

    /**
     *
     * @param index numebr of row we want
     * @return teh row of number index
     */
    Vector3D row(short index) const;

    /**
     * @param index numebr of colum we want
     * @return teh colum of number index
     */
    Vector3D column(short index) const;

    /**
     * the trace of teh matrix
     * @return sum of values in diagonal
     */
    double trace() const;

    /**
     *
     * @return teh determinants of the matrix
     */
    double determinant() const;
};

#endif //EX1VM_MATRIX3D_H
