//
// Created by sin_een on 12/20/18.
//
#ifndef EX1_VECTOR3D_H
#define EX1_VECTOR3D_H

#include <iostream>
#include <cmath>

using namespace std;

/**
 *
 */

class Vector3D
{

private:
    /**
     * This class represents 3D vector, with 3 coordinates of type double.
     */

    typedef struct Vector
    {
        double cordX;
        double cordY;
        double cordZ;
    } Vector;

    Vector vector;
    Vector* V = &vector;

public:
    /**
     * Constructor that initializes the Vector to 0.
     */
    Vector3D();

    /**
     * Constructor that initializes the Vector to the given coordinates.
     */
    Vector3D(double x, double y, double z);

    /**
     * Constructor that initializes the Vector tho the given coordinates passed in array of 3.
     */
    Vector3D(const double coordinates[3]);

    /**
     * Copy Constructor, copies the values of coordinates of other vector to the current vector.
     */
    Vector3D(const Vector3D& other);


    /**
     * @param second Vector3D vector represents outer second vector.
     * @return Vector3D that represents the addition of the current vector and the second vector.
     */
    Vector3D operator+(const Vector3D& second) ;

    /**
     * @param second Vector3D vector represents outer second vector.
     * @return Vector3D that represents the subtraction of the current vector and the second vector.
     */
    Vector3D operator-(const Vector3D& second);

    /**
     * @param second Vector3D vector represents outer second vector.
     * @return Vector3D that represents the addition of the current vector and the second vector,
     * and saves the result to the current vector.
     */
    Vector3D& operator+=(const Vector3D& second);

    /**
     * @param second Vector3D vector represents outer second vector.
     * @return Vector3D that represents the subtraction of the current vector and the second vector, and
     * saves the result to the current vector.
     */
    Vector3D& operator-=(const Vector3D& second);

    /**
     * @param number represents a number.
     * @return the result of addition with number and current vector and saves it to current vector.
     */
    Vector3D& operator+=(const double number);

    /**
    * @param number represents a number
    * @return the result of subtraction with number and current vector and saves it to current vector.
    */
    Vector3D& operator-=(const double number);

    /**
     * @return vector that represents the negation of the current vector.
     */
    Vector3D operator -();

    /**
     * @param number represents a number
     * @return vector that is the product of the current vector multiplied by scalar
     */
    Vector3D operator*(const double number);

    /**
    * @param number represents a number
    * @return vector that is the product of the current vector divided by scalar
    */
    Vector3D operator/(const double number);

    /**
    * @param vector represents a vector
    * @param number represents a number
    * @return vector that is the product of vector multiplied by scalar
    */
    friend Vector3D operator*(const double number, const Vector3D& vector);

    /**
     * @param number represents a number
     * @return vector that is the product of the current vector multiplied by scalar, and
     * save the result in the current vector.
     */
    Vector3D& operator*=(const double number);

    /**
     * @param number represents a number
     * @return vector that is the product of the current vector divided by scalar, and
     * save the result in the current vector.
     */
    Vector3D& operator/=(const double number);

    /**
     * @param second represents a second vector
     * @return the distance between the the current vector and second vector.
     */
    double operator|(const Vector3D& second) const;

    /**
     * @param second represents a second vector
     * @return the Scalar product of the the current vector and the other.
     */
    double operator*(const Vector3D& second);

    /**
     * @param second represents a second vector
     * @return the angel in radians between the current vector and the second.
     */
    double operator^(Vector3D second);

    /**
     * recieves vector from stdin
     * @param is object of istream
     * @param vec vector to be recieved
     * @return is  object after sending the vector to the cin function
     */
    friend istream& operator>>(istream& is, Vector3D& vec);

    /**
     * prints vector to stdout
     * @param os object of ostream
     * @param vec vector to be printed
     * @return os object after sending the vector to the cout function
     */
    friend ostream& operator<<(ostream& os, const Vector3D& vec);

    /**
     * @param other represents a vector.
     * @return returns the result of the assignment of other to the current vector,
     * and saves the result to the current vector.
     */
    Vector3D& operator=(const Vector3D& other);


    /**
     * @param index represents natural number in range [1, 3]
     * @return reference to the corresponding coordinate
     */
    double& operator[](int index);

    /**
     * @param index represents natural number in range [1, 3]
     * @return corresponding coordinate's value
     */
    double operator[](int index) const;

    /**
     * @return the norma of the current vector
     */
    double norm() const;

    /**
     * @return the dist of the current vector from vector 0.
     */
    double dist(Vector3D vec);

};

#endif //EX1_VECTOR3D_H
