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

Matrix3D& Matrix3D::operator*=(Matrix3D &other)
{
    return *Matrix3D(this*other);
}

Matrix3D Matrix3D::operator+(Matrix3D &other)
{
    return Matrix3D(this->firstRow + other.firstRow,
            this,secondRow + other.secondRow,
            this->thirdRow + other.thirdRow);
}

Matrix3D Matrix3D::operator-(Matrix3D &other)
{
    return Matrix3D(this->firstRow - other.firstRow,
                    this,secondRow - other.secondRow,
                    this->thirdRow - other.thirdRow);
}

Matrix3D Matrix3D::operator*(Matrix3D &other)
{
    double mul[3][3];
    Vector3D firstColume = other.column(0);
    Vector3D secondColume = other.column(1);
    Vector3D thirdColume = other.column(2);
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
    return *this;
}

Matrix3D& Matrix3D::operator/=(double number)
{
    if (!number)
    {
        cerr << "cants divide by zero";
        return;
    }
    this->firstRow/=number;
    this,secondRow/=number;
    this->thirdRow/=number;
    return *this;
}



Vector3D Matrix3D::operator*(Vector3D vector)
{
    return Vector3D(this->firstRow*vector, this->secondRow*vector, this->thirdRow*vector);
}

istream Matrix3D::&operator>>(istream &is, Matrix3D &mat);

ostream Matrix3D::&operator<<(ostream &os, const Matrix3D &mat);

Matrix3D Matrix3D::&operator=(const Matrix3D &mat)
{
    this = Matrix3D(mat);
    return *this;
}

Vector3D& Matrix3D::operator[](int index)
{
    if (index == 0)
    {
        return this->firstRow;
    }
    else if (index == 1)
    {
        return this->secondRow;
    }
    else if (index == 2)
    {
        return this->thirdRow;
    }
    else
    {
        cerr << "index out of bounderies";
    }
}

Vector3D Matrix3D::operator[](int index) const
{
    if (index == 0)
    {
        return this->firstRow;
    }
    else if (index == 1)
    {
        return this->secondRow;
    }
    else if (index == 2)
    {
        return this->thirdRow;
    }
    else
    {
        cerr << "index out of bounderies ";
    }
}

Vector3D Matrix3D::row(short index) const
{
    if (index >= 0 & index < 3)
        return this[index];
    else
        cerr <<  "index out of bounderies ";
}

Vector3D Matrix3D::column(short index) const
{
    return Vector3D(other.firstRow[index], other.secondRow[index], other.thirdRow[index]);
}

double Matrix3D::trace() const
{
    return (this->firstRow[0] = this->secondRow[1] + this->thirdRow[2]);
}

double Matrix3D::determinant() const
{
 //TODO
}



