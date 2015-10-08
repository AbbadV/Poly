// --------------------- Poly.cpp -----------------------------------------
//
// Shyawn Karim, CSS 343
// Created:         October 6, 2015
// Last Modified:   October 10, 2015
// --------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------
// Notes:
// --------------------------------------------------------------

#include "Poly.h"


// --------------------- operator>> -----------------------------------------
//
// --------------------------------------------------------------
istream &operator>>(istream &inStream, Poly &poly)
{
    return <#initializer#>;
}

// --------------------- operator<< -----------------------------------------
//
// --------------------------------------------------------------
ostream &operator<<(ostream &outStream, const Poly &poly)
{
    return <#initializer#>;
}

// --------------------- Default Constructor -----------------------------------------
// Takes no parameters, creates Poly object with size 1 and value set to 0
// --------------------------------------------------------------
Poly::Poly()
{
    size = 1;
    coeffPtr = new int[size];
    coeffPtr[0] = 0;
}

// --------------------- Constructor int -----------------------------------------
// Overloaded constructor takes one parameter. Creates a Poly object with
// array size 1 and sets that value to the coefficent parameter
// --------------------------------------------------------------
Poly::Poly(int c)
{
    size = 1;
    coeffPtr = new int[size];
    coeffPtr[0] = c;
}

// --------------------- Constructor int int -----------------------------------------
// Overloaded constructor takes two parameters. Creates a Poly object with
// array size set to power + 1 and the coefficient value in the last index
// --------------------------------------------------------------
Poly::Poly(int c, int p)
{
    size = p + 1;
    coeffPtr = new int[size];

    for (int i = 0; i < size ; i++)
    {
        coeffPtr[i] = 0;
    }

    coeffPtr[p] = c;
}

// --------------------- Copy Constructor -----------------------------------------
// Creates a deep copy of the Poly object passed in
// --------------------------------------------------------------
Poly::Poly(const Poly &source)
{
    size = source.size;
    coeffPtr = new int[size];

    for (int i = 0; i < size; i++)
    {
        coeffPtr[i] = source.coeffPtr[i];
    }
}

// --------------------- Destructor -----------------------------------------
// Deletes coeffPtr and sets it NULL
// --------------------------------------------------------------
Poly::~Poly()
{
    delete[] coeffPtr;
    coeffPtr = NULL;
}

// --------------------- getCoeff -----------------------------------------
// Returns the coefficient at chosen index (power)
// Returns 0 if index is out of range
// --------------------------------------------------------------
int Poly::getCoeff(int p) const
{
    if ((p >= 0) && (p < size))
    {
        return coeffPtr[p];
    }
    else
    {
        return 0;
    }
}

// --------------------- setCoeff -----------------------------------------
// Adds an additional coefficient to an already established poly array
// If new coefficient has a power greater than largest array index a new
// array is dynamically allocated and all coefficients are transferred
// to the new array
// --------------------------------------------------------------
void Poly::setCoeff(int c, int p)
{
    if (p >= 0)
    {
        if (p < size)
        {
            coeffPtr[p] = c;
        }
        else
        {
            int *tempArr = new int[p + 1];

            for (int i = 0; i < size; i++)
            {
                tempArr[i] = coeffPtr[i];
            }

            for (int j = size; j < p + 1; j++)
            {
                tempArr[j] = 0;
            }

            delete[] coeffPtr;
            coeffPtr = NULL;
            coeffPtr = tempArr;
            delete[] tempArr;
            tempArr = NULL;
            size = p +1;
        }
    }
}

// --------------------- getSize -----------------------------------------
// Returns the size of the array
// --------------------------------------------------------------
int Poly::getSize() const
{
    return size;
}

// --------------------- operator+ -----------------------------------------
// DONE
// --------------------------------------------------------------
Poly Poly::operator+(const Poly &rhs) const
{
    if (size > rhs.size)
    {
        Poly polySum;
        polySum = *this->coeffPtr;

        for (int i = 0; i > rhs.size; i++)
        {
            polySum.coeffPtr[i] = (coeffPtr[i] + rhs.coeffPtr[i]);
        }

        return polySum;
    }
    else
    {
        Poly polySum;
        polySum = *rhs.coeffPtr;

        for (int i = 0; i < size; i++)
        {
            polySum.coeffPtr[i] = (coeffPtr[i] + rhs.coeffPtr[i]);
        }

        return polySum;
    }
}

// --------------------- operator- ----------------------------------------
//
// --------------------------------------------------------------
Poly Poly::operator-(const Poly &rhs) const
{
    return Poly();
}

// --------------------- operator* -----------------------------------------
// WORKING
// --------------------------------------------------------------
Poly Poly::operator*(const Poly &rhs) const
{
    int tempSize;
    tempSize = size + rhs.size - 1;

    Poly tempArr;

    for ()

    return tempArr;
}

// --------------------- operator+= -----------------------------------------
//
// --------------------------------------------------------------
Poly Poly::operator+=(const Poly &rhs)
{
    return Poly();
}

// --------------------- operator-= -----------------------------------------
//
// --------------------------------------------------------------
Poly Poly::operator-=(const Poly &rhs)
{
    return Poly();
}

// --------------------- operator*= -----------------------------------------
//
// --------------------------------------------------------------
Poly Poly::operator*=(const Poly &rhs)
{
    return Poly();
}

// --------------------- operator== -----------------------------------------
//
// --------------------------------------------------------------
bool Poly::operator==(const Poly &rhs) const
{
    return false;
}

// --------------------- operator!= -----------------------------------------
//
// --------------------------------------------------------------
bool Poly::operator!=(const Poly &rhs) const
{
    return false;
}

// --------------------- operator= -----------------------------------------
//
// --------------------------------------------------------------
void Poly::operator=(const Poly &rhs)
{

}