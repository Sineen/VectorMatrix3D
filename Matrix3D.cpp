//
// Created by sin_een on 12/20/18.
//

#include "Matrix3D.h"

Matrix3D::Matrix3D(double *array)
{
    this->firstRow(Vector3D(array[0], array[1], array[2]);
    this->secondRow(Vector3D(array[3], array[4], array[5]);
    this->firstRow(Vector3D(array[6], array[7], array[8]);
}

Matrix3D::Matrix3D(double (*coordinates)[3])
{
    this->firstRow(Vector3D(coordinates[0][0], coordinates[0][1], coordinates[0][2]);
    this->secondRow(Vector3D(coordinates[1][0], coordinates[1][1], coordinates[1][2]);
    this->firstRow(Vector3D(coordinates[2][0], coordinates[2][1], coordinates[2][2]);
}

Matrix3D::Matrix3D(Vector3D& firstVector, Vector3D& secondVector, Vector3D& thirdVector)
{
    this->firstRow = firstVector;
    this->secondRow = secondVector;
    this->thirdRow = thirdVector;
}

Matrix3D::Matrix3D(Matrix3D& second)
{
    this->firstRow(second.firstRow);
    this->secondRow(second.secondRow);
    this->thirdRow(second.thirdRow);
}


Matrix3D& Matrix3D::operator+=(Matrix3D &other)
{
    this->firstRow+=other.firstRow;
    this->secondRow+=other.secondRow;
    this->thirdRow+=other.thirdRow;
    return *this;
}


Matrix3D& Matrix3D::operator-=(Matrix3D &other)
{
    this->firstRow-=other.firstRow;
    this->secondRow-=other.secondRow;
    this->thirdRow-=other.thirdRow;
    return *this;
}

Matrix3D& Matrix3D::operator=*(Matrix3D &other)
{
    return *Matrix3D(this*other);
}

Matrix3D Matrix3D::operator+(Matrix3D &other)
{
    return Matrix3D(this->firstRow + number, this,secondRow + number, this->thirdRow + number);

//    double mul[3][3];
//    for (int i = 0; i < 3; i ++)
//    {
//        for (int j = 0; j < 3; j ++)
//        {
//            mul[i][j] = this[i][j]+transposed[i][j];
//        }
//    }
//    return Matrix3D(mul);
}

Matrix3D Matrix3D::operator-(Matrix3D &other)
{
    return Matrix3D(this->firstRow - number, this,secondRow - number, this->thirdRow - number);
//    double mul[3][3];
//    for (int i = 0; i < 3; i ++)
//    {
//        for (int j = 0; j < 3; j ++)
//        {
//            mul[i][j] = this[i][j]-transposed[i][j];
//        }
//    }
//    return Matrix3D(mul);
}

Matrix3D Matrix3D::operator*(Matrix3D &other)
{
    double mul[3][3];
    Vector3D firstColume = Vector3D(other.firstRow[0], other.secondRow[0], other.thirdRow[0]);
    Vector3D secondColume = Vector3D(other.firstRow[1], other.secondRow[1], other.thirdRow[1]);
    Vector3D thirdColume = Vector3D(other.firstRow[2], other.secondRow[2], other.thirdRow[2]);
    Matrix3D transposed(firstColume,secondColume, thirdColume);
    for (int i = 0; i < 3; i ++)
    {
        for (int j = 0; j < 3; j ++)
        {
            mul[i][j] = this[i]*transposed[j];
        }
    }
    return Matrix3D(mul);
}


Matrix3D& Matrix3D::operator*=(double number)
{
    this->firstRow*=number;
    this,secondRow*=number;
    this->thirdRow*=number;
}

Matrix3D& Matrix3D::operator/=(double number)
{
    this->firstRow/=number;
    this,secondRow/=number;
    this->thirdRow/=number;
}


