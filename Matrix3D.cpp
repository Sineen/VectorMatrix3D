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


