//
// Created by sin_een on 12/20/18.
//

#include "Vector3D.h"


/**
 *
 */
Vector3D::Vector3D()
{
    V->cordX = 0;
    V->cordY = 0;
    V->cordZ = 0;
}

/**
 *
 * @param x
 * @param y
 * @param z
 */
Vector3D::Vector3D(double x, double y, double z)
{
    V->cordX = x;
    V->cordY = y;
    V->cordZ = z;
}

/**
 *
 * @param coordinates
 */
Vector3D::Vector3D(const double *coordinates)
{
    V->cordX = coordinates[0];
    V->cordY = coordinates[1];
    V->cordZ = coordinates[2];
}

/**
 *
 * @param other
 */
Vector3D::Vector3D(const Vector3D &other)
{
    V->cordX = other.V->cordX;
    V->cordY = other.V->cordY;
    V->cordZ = other.V->cordZ;
}

/**
 *
 * @param second
 * @return
 */
Vector3D Vector3D::operator+(const Vector3D &second)
{
    Vector3D addition(V->cordX, V->cordY, V->cordZ);
    addition.V->cordX += second.V->cordX;
    addition.V->cordY += second.V->cordY;
    addition.V->cordZ += second.V->cordZ;
    return addition;
}

/**
 *
 * @param second
 * @return
 */
Vector3D Vector3D::operator-(const Vector3D &second)
{
    Vector3D addition(V->cordX, V->cordY, V->cordZ);
    addition.V->cordX -= second.V->cordX;
    addition.V->cordY -= second.V->cordY;
    addition.V->cordZ -= second.V->cordZ;
    return addition;
}

/**
 *
 * @param second
 * @return
 */
Vector3D &Vector3D::operator+=(const Vector3D &second)
{
    V->cordX += second.V->cordX;
    V->cordY += second.V->cordY;
    V->cordZ += second.V->cordZ;
    return *this;
}

/**
 *
 * @param second
 * @return
 */
Vector3D &Vector3D::operator-=(const Vector3D &second)
{
    V->cordX -= second.V->cordX;
    V->cordY -= second.V->cordY;
    V->cordZ -= second.V->cordZ;
    return *this;
}

/**
 *
 * @param number
 * @return
 */
Vector3D &Vector3D::operator+=(const double number)
{
    V->cordX += number;
    V->cordY += number;
    V->cordZ += number;
    return *this;
}

/**
 *
 * @param number
 * @return
 */
Vector3D &Vector3D::operator-=(const double number)
{
    V->cordX -= number;
    V->cordY -= number;
    V->cordZ -= number;
    return *this;
}

/**
 *
 * @return
 */
Vector3D Vector3D::operator-()
{
    return Vector3D(V->cordX * (-1), V->cordY * (-1), V->cordZ  * (-1));
}

/**
 *
 * @param number
 * @return
 */
Vector3D Vector3D::operator*(const double number)
{
    return Vector3D(V->cordX * number, V->cordY * number, V->cordZ  * number);
}

/**
 *
 * @param number
 * @return
 */
Vector3D Vector3D::operator/(const double number)
{
    return Vector3D(V->cordX / number, V->cordY / number, V->cordZ  / number);
}

/**
 *
 * @param number
 * @param vector
 * @return
 */
Vector3D operator*(const double number, const Vector3D &vector)
{
    return Vector3D(vector.V->cordX * number, vector.V->cordY * number, vector.V->cordZ * number);
}

/**
 *
 * @param number
 * @return
 */
Vector3D &Vector3D::operator*=(const double number)
{
    V->cordX *= number;
    V->cordY *= number;
    V->cordZ *= number;
    return *this;
}

/**
 *
 * @param number
 * @return
 */
Vector3D &Vector3D::operator/=(const double number)
{
    V->cordX /= number;
    V->cordY /= number;
    V->cordZ /= number;
    return *this;
}

/**
 *
 * @param second
 * @return
 */
double Vector3D::operator|(const Vector3D &second) const
{
    double x = pow(V->cordX - second.V->cordX, 2);
    double y = pow(V->cordY - second.V->cordY, 2);
    double z = pow(V->cordZ - second.V->cordZ, 2);
    return sqrt(x + y + z);
}

/**
 *
 * @param second
 * @return
 */
double Vector3D::operator*(const Vector3D &second)
{
    double mult = V->cordX * second.V->cordX;
    mult += (V->cordY * second.V->cordY);
    mult += (V->cordZ * second.V->cordZ);
    return mult;
}

/**
 *
 * @param second
 * @return
 */
double Vector3D::operator^(Vector3D second)
{
    // check if change it with norm instead of operator|
    double vec1 = this->norm();
    double vec2 = second.norm();
    double nominator = this->operator*(second);
    if ((vec1 == 0) | (vec2 == 0))
    {
        cerr << ("Vector can not be with length 0");
    }
    return acos( nominator / ( vec1 * vec2));
}

/**
 *
 * @param is
 * @param vec
 * @return
 */
istream &operator>>(istream &is, Vector3D &vec)
{
    double arg;
    for ( int i = 0; i < 3; i++)
    {
        if ( is >> arg)
            vec[i] = arg;
    }
    return is;
}

/**
 *
 * @param os
 * @param vec
 * @return
 */
ostream &operator<<(ostream &os, const Vector3D &vec)
{
    os << vec[0] << " "  << vec[1] << " " << vec[2];
    return os;
}

/**
 *
 * @param other
 * @return
 */
Vector3D& Vector3D::operator=(const Vector3D &other)
{
    V->cordX = other.V->cordX;
    V->cordY = other.V->cordY;
    V->cordZ = other.V->cordZ;
    return *this;
}

/**
 *
 * @param index
 * @return
 */
double &Vector3D::operator[](int index)
{
    switch (index)
    {
        case 0:
            return V->cordX;
        case 1:
            return V->cordY;
        case 2:
            return V->cordZ;
        default:
            cerr << "index out of vector's boundaries";
            exit(1);
    }
}

/**
 *
 * @param index
 * @return
 */
double Vector3D::operator[](int index) const
{
    switch (index)
    {
        case 0:
            return V->cordX;
        case 1:
            return V->cordY;
        case 2:
            return V->cordZ;
        default:
            cerr << "index out of vector's boundaries";
            exit(1);
    }
}

/**
 *
 * @return
 */
double Vector3D::norm() const
{
    const Vector3D tmp;
    return this->operator|( tmp);
}

/**
 *
 * @param vec
 * @return
 */
double Vector3D::dist(Vector3D vec)
{
    return this->operator|(vec);
}










