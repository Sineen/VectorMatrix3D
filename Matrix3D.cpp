//
// Created by sin_een on 12/20/18.
//

#include "Matrix3D.h"

/**
 * constructor wit an array of 9 doubles
 */
Matrix3D::Matrix3D(const double *array)
{
    this->firstRow = (Vector3D(array[0], array[1], array[2]));
    this->secondRow = (Vector3D(array[3], array[4], array[5]));
    this->thirdRow = (Vector3D(array[6], array[7], array[8]));
}

/**
 * constructor from matrix of doubles 3 x3
 */
Matrix3D::Matrix3D(const double (*coordinates)[3])
{
    this->firstRow = (Vector3D(coordinates[0][0], coordinates[0][1], coordinates[0][2]));
    this->secondRow = (Vector3D(coordinates[1][0], coordinates[1][1], coordinates[1][2]));
    this->thirdRow = (Vector3D(coordinates[2][0], coordinates[2][1], coordinates[2][2]));
}

/**
 *
 * @param firstVector a vector 3d would be first row
 * @param secondVector  a vector 3d would be second row
 * @param thirdVector a vector 3d would be tird row
 */
Matrix3D::Matrix3D(const Vector3D& firstVector, const Vector3D& secondVector, const Vector3D& thirdVector)
{
    this->firstRow = firstVector;
    this->secondRow = secondVector;
    this->thirdRow = thirdVector;
}

/**
 *  constructor from another matrix3D
 * @param second the second 3D Matrix
 */
Matrix3D::Matrix3D(const Matrix3D& second)
{
    this->firstRow = Vector3D(second.firstRow);
    this->secondRow = Vector3D(second.secondRow);
    this->thirdRow = Vector3D(second.thirdRow);
}

/**
 * addes two matrixes
 * @param other a second matrix
 * @return the matrix of this class
 */
Matrix3D& Matrix3D::operator+=(const Matrix3D &other)
{
    this->firstRow += other.firstRow;
    this->secondRow += other.secondRow;
    this->thirdRow += other.thirdRow;
    return *this;
}


/**
 * subtracts two matrixes  and puts the vlaues  on teh matrix in the class
 * @param other a second matrix
 * @return the matrix of the class
 */
Matrix3D& Matrix3D::operator-=(const Matrix3D &other)
{
    this->firstRow -= other.firstRow;
    this->secondRow -= other.secondRow;
    this->thirdRow -= other.thirdRow;
    return *this;
}

/**
 * multiplications two matrixes  and puts the vlaues  on teh matrix in the class
 * @param other a second matrix
 * @return the matrix of the class
 */
Matrix3D& Matrix3D::operator*=(const Matrix3D &other)
{
    *this = Matrix3D(this->operator*(other));
    return *this;
}


/**
 * addes the object of this class to other adn makes a new matrix and returns that
 * @param other another matrix3D
 */
Matrix3D Matrix3D::operator+(const Matrix3D &other)
{
    return Matrix3D((this->firstRow + other.firstRow),
                    (this->secondRow + other.secondRow),
                    (this->thirdRow + other.thirdRow));
}

/**
 * subtracts the object of this class to other adn makes a new matrix and returns that
 * @param other another matrix3D
 */
Matrix3D Matrix3D::operator-(const Matrix3D &other)
{
     return Matrix3D(this->firstRow - other.firstRow,
                    this->secondRow - other.secondRow,
                    this->thirdRow - other.thirdRow);

}

/**
 * multiplication the object of this class to other adn makes a new matrix and returns that
 * @param other another matrix3D
 */
Matrix3D Matrix3D::operator*(const Matrix3D &other)
{
    double mul[3][3];
    Vector3D firstColume = other.column(0);
    Vector3D secondColume = other.column(1);
    Vector3D thirdColume = other.column(2);
    Matrix3D transposed(firstColume, secondColume, thirdColume);
    for (int i = 0; i < 3; i ++)
    {
        for (int j = 0; j < 3; j ++)
        {
            mul[i][j] = (*this)[i]*transposed[j];
        }
    }
    return Matrix3D(mul);
}

/**
 * @param number a double number
 * @return multiplications of the matrix with the number and returns the object
 */
Matrix3D& Matrix3D::operator*=(double number)
{
    this->firstRow *= number;
    this->secondRow *= number;
    this->thirdRow *= number;
    return *this;
}

/**
 * @param number a double number
 * @return multiplications of the matrix with the number and returns the object
 */
Matrix3D& Matrix3D::operator/=(double number)
{
    if (!number)
    {
        cerr << "cants divide by zero";
        exit(-1);
    }
    this->firstRow /= number;
    this->secondRow /= number;
    this->thirdRow /= number;
    return *this;
}


/**
 * @param vector a vectro of type VECTOR 3D
 * @return a vector 3d that is a multiplication of the matrix and the vector
 */
Vector3D Matrix3D::operator*(const Vector3D vector)
{
    return Vector3D(this->firstRow*vector, this->secondRow*vector, this->thirdRow*vector);
}

/**
 * @param is an input stream
 * @param mat a matrix
 * @return reads the values from the input and puts it in mat
 */
istream &operator>>(istream &is, Matrix3D &mat)
{
    for ( int i = 0; i < 3; i++)
    {
        is >> mat[i];
    }
    return is;
}

/**
 * @param os the output stream
 * @param mat a matrix 3D
 * @return reads what we have matrix into the os
 */
ostream &operator<<(ostream &os, const Matrix3D &mat)
{
    os << mat[0] << "\n"  << mat[1] << "\n" << mat[2];
    return os;
}


/**
 * @param mat a matrix3D
 * @return uplouds teh matrix in the object of teh class
 */
Matrix3D &Matrix3D::operator=(const Matrix3D &mat)
{
    this->firstRow = mat[0];
    this->secondRow = mat[1];
    this->thirdRow = mat[2];
    return *this;
}


/**
 * @param index number of index we want
 * @return a refrence that is in the palce of the index
 */
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
    else if (index == 2)    /**
     *
     * @param vector
     * @return
     */

    {
        return this->thirdRow;
    }
    else
    {
        cerr << "index out of bounderies";
        exit(1);
    }
}

/**
 *
  * @param index number of index we want
 * @return a value that is in the palce of the index
 */
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
        exit(1);
    }
}

/**
 *
 * @param index numebr of row we want
 * @return teh row of number index
 */
Vector3D Matrix3D::row(short index) const
{
    if (index >= 0 & index < 3)
    {
        return (*this)[index];
    }
    else
    {
        cerr <<  "index out of bounderies ";
        exit(1);
    }
}


/**
 * @param index numebr of colum we want
 * @return teh colum of number index
 */
Vector3D Matrix3D::column(short index) const
{
    return Vector3D(this->firstRow[index], this->secondRow[index], this->thirdRow[index]);
}

/**
 * the trace of teh matrix
 * @return sum of values in diagonal
 */
double Matrix3D::trace() const
{
    return (this->firstRow[0] + this->secondRow[1] + this->thirdRow[2]);
}

/**
 *
 * @return teh determinants of the matrix
 */
double Matrix3D::determinant() const
{
    double X = this->firstRow[0] * this->secondRow[1] * this->thirdRow[2];
    double Y = this->firstRow[1] * this->secondRow[2] * this->thirdRow[0];
    double Z = this->firstRow[2] * this->secondRow[0] * this->thirdRow[1];
    double C = this->firstRow[2] * this->secondRow[1] * this->thirdRow[0];
    double D = this->firstRow[1] * this->secondRow[0] * this->thirdRow[2];
    double F = this->firstRow[0] * this->secondRow[2] * this->thirdRow[1];
    return X + Y + Z - C - D - F;
}





