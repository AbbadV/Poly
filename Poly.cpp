// --------------------- poly.cpp -----------------------------------------
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

using namespace std;


// --------------------- Overloaded >> -----------------------------------------
// Takes two ints entered from console
// Sets the first to coeff and the 2nd to power
// Calls setCoeff() to insert into correct Poly object
// --------------------------------------------------------------
istream &operator>>(istream &inStream, Poly &sourceCoeff)
{
    int coeff;
    int power;

    while (true)
    {
        inStream >> coeff >> power;

        if ((coeff == -1) && (power == -1))
        {
            break;
        }

        sourceCoeff.setCoeff(coeff, power);
    }

    return inStream;
}

// --------------------- Overloaded << -----------------------------------------
// Outputs the polynomial in print form to the console
// If the array is empty then 0 is returned
// --------------------------------------------------------------
ostream &operator<<(ostream &outStream, const Poly &sourcePoly)
{
    bool allZeroes = true;

        for (int i = sourcePoly.size - 1; i >= 0; i--)
        {
            if (sourcePoly.coeffPtr[i] != 0)
            {
                allZeroes = false;

                outStream << " ";

                if (sourcePoly.coeffPtr[i] > 0)
                {
                    outStream << "+";
                }

                outStream << sourcePoly.coeffPtr[i];

                if (i != 0 && i != 1)
                {
                    outStream << "x^" << i;
                }

                if (i == 1)
                {
                    outStream << "x";
                }
            }
        }

    if (allZeroes == false)
    {
        return outStream;
    }
    else
    {
        return outStream << "0";
    }
}

// --------------------- Default Constructor -----------------------------------------
// Takes no parameters and creates a Poly object
// Array size set to 1 and value set to 0
// --------------------------------------------------------------
Poly::Poly()
{
    size = 1;
    coeffPtr = new int[size];
    coeffPtr[0] = 0;
}

// --------------------- Constructor int -----------------------------------------
// Overloaded constructor takes one parameter and creates a Poly object
// Array size set to 1 and value set to coeff passed in
// --------------------------------------------------------------
Poly::Poly(int coeff)
{
    size = 1;
    coeffPtr = new int[size];
    coeffPtr[0] = coeff;
}

// --------------------- Constructor int int -----------------------------------------
// Overloaded constructor takes two parameters and creates a Poly object
// Array size set to power + 1 and the coefficient value in the last index
// --------------------------------------------------------------
Poly::Poly(int coeff, int power)
{
    size = power + 1;
    coeffPtr = new int[size];

    for (int i = 0; i < size ; i++)
    {
        coeffPtr[i] = 0;
    }

    coeffPtr[power] = coeff;
}

// --------------------- Copy Constructor -----------------------------------------
// Creates a deep copy of the source Poly object passed in
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
int Poly::getCoeff(int power) const
{
    if ((power >= 0) && (power < size))
    {
        return coeffPtr[power];
    }
    else
    {
        return 0;
    }
}

// --------------------- setCoeff -----------------------------------------
// Set coeff passed in to the array index represented by power
// If power is out of array range then a new array is dynamically
// allocated and the coeff is assigned to correct index
// --------------------------------------------------------------
void Poly::setCoeff(int coeff, int power)
{
    if (power >= 0)
    {
        if (power < size)
        {
            coeffPtr[power] = coeff;
        }
        else
        {
            int *tempArr = new int[power + 1];

            for (int i = 0; i < size; i++)
            {
                tempArr[i] = coeffPtr[i];
            }

            for (int j = size; j < power + 1; j++)
            {
                tempArr[j] = 0;
            }

            tempArr[power] = coeff;

            delete[] coeffPtr;
            coeffPtr = NULL;
            coeffPtr = tempArr;
            tempArr = NULL;
            size = power + 1;
        }
    }
}

// --------------------- Overloaded + -----------------------------------------
// Adds two different polynomials together
// Returns the sum in a Poly object
// --------------------------------------------------------------
Poly Poly::operator+(const Poly &rhs) const
{
    if (this->size > rhs.size)
    {
        Poly polySum(0, this->size);

        for (int i = 0; i < this->size; i++)
        {
            polySum.coeffPtr[i] = this->coeffPtr[i];
        }

        for (int i = 0; i < rhs.size; i++)
        {
            polySum.coeffPtr[i] += rhs.coeffPtr[i];
        }

        return polySum;
    }
    else
    {
        Poly polySum(0, rhs.size);

        for (int i = 0; i < rhs.size; i++)
        {
            polySum.coeffPtr[i] = rhs.coeffPtr[i];
        }

        for (int i = 0; i < this->size; i++)
        {
            polySum.coeffPtr[i] += this->coeffPtr[i];
        }

        return polySum;
    }
}

// --------------------- Overloaded - ----------------------------------------
// Subtracts one polynomial from another
// Returns the difference in a Poly object
// --------------------------------------------------------------
Poly Poly::operator-(const Poly &rhs) const
{
    if (this->size > rhs.size)
    {
        Poly polyDif(0, this->size);

        for (int i = 0; i < this->size; i++)
        {
            polyDif.coeffPtr[i] = this->coeffPtr[i];
        }

        for (int i = 0; i < rhs.size; i++)
        {
            polyDif.coeffPtr[i] -= rhs.coeffPtr[i];
        }

        return polyDif;
    }
    else
    {
        Poly polyDif(0, rhs.size);

        for (int i = 0; i < this->size; i++)
        {
            polyDif.coeffPtr[i] = this->coeffPtr[i];
        }

        for (int i = 0; i < rhs.size; i++)
        {
            polyDif.coeffPtr[i] -= rhs.coeffPtr[i];
        }

        return polyDif;
    }
}

// --------------------- Overloaded * -----------------------------------------
// Multiplies two different polynomials together
// Returns the product in a Poly object
// --------------------------------------------------------------
Poly Poly::operator*(const Poly &rhs) const
{
    int tempSize;
    tempSize = (this->size + rhs.size - 2);

    Poly tempArr(0, tempSize);

        for (int i = 0; i < this->size; i++)
        {
            if (this->coeffPtr[i] != 0)
            {
                for (int j = 0; j < rhs.size; j++)
                {
                    tempArr.coeffPtr[i + j] += (this->coeffPtr[i] * rhs.coeffPtr[j]);
                }
            }
        }

    return tempArr;
}

// --------------------- Overloaded += -----------------------------------------
// Adds two different polynomials together
// Assigns the sum to the Poly object to the left of assignment
// --------------------------------------------------------------
Poly& Poly::operator+=(const Poly &rhs)
{
    *this = *this + rhs;
    return *this;
}

// --------------------- Overloaded -= -----------------------------------------
// Subtracts one from polynomial from another
// Assigns the difference to the Poly object to the left of assignment
// --------------------------------------------------------------
Poly& Poly::operator-=(const Poly &rhs)
{
    *this = *this - rhs;
    return *this;
}

// --------------------- Overloaded *= -----------------------------------------
// Multiplies two different polynomials
// Assigns the product to the Poly object to the left of assignment
// --------------------------------------------------------------
Poly& Poly::operator*=(const Poly &rhs)
{
    *this = *this * rhs;
    return *this;
}

// --------------------- Overloaded == -----------------------------------------
// Checks if two Poly objects contain identical polynomials
// Returns true if they are and false if they aren't
// --------------------------------------------------------------
bool Poly::operator==(const Poly &rhs) const
{
    if (size == rhs.size)
    {
        for (int i = 0; i < size; i++)
        {
            if (coeffPtr[i] != rhs.coeffPtr[i])
            {
                return false;
            }
        }

        return true;
    }
    else
    {
        int bigArr;
        int smallArr;

        if (size < rhs.size)
        {
            smallArr = size;
            bigArr = rhs.size;

            for (int i = 0; i < smallArr; i++)
            {
                if (coeffPtr[i] != rhs.coeffPtr[i])
                {
                    return false;
                }
            }

            for (int j = smallArr; j < bigArr; j++)
            {
                if (rhs.coeffPtr != 0)
                {
                    return false;
                }
            }

            return true;
        }
        else
        {
            bigArr = size;
            smallArr = rhs.size;

            for (int i = 0; i < smallArr; i++)
            {
                if (coeffPtr[i] != rhs.coeffPtr[i])
                {
                    return false;
                }
            }

            for (int j = smallArr; j < bigArr; j++)
            {
                if (coeffPtr != 0)
                {
                    return false;
                }
            }

            return true;
        }
    }
}

// --------------------- operator!= -----------------------------------------
// Checks if two Poly objects contain different polynomials
// Returns true if they are and false if they aren't
// --------------------------------------------------------------
bool Poly::operator!=(const Poly &rhs) const
{
    return !(*this == rhs);
}

// --------------------- operator= -----------------------------------------
// Assigns the right Poly to the left Poly of the assignment operator
// --------------------------------------------------------------
Poly& Poly::operator=(const Poly &rhs)
{
    if (this->coeffPtr == rhs.coeffPtr)
    {
        return *this;
    }

    if (this->size < rhs.size)
    {
        delete[] this->coeffPtr;
        coeffPtr = NULL;
        this->size = rhs.size;
        this->coeffPtr = new int[this->size];

        for (int i = 0; i < this->size; i++)
        {
            this->coeffPtr[i] = rhs.coeffPtr[i];
        }
    }

    if (this->size > rhs.size)
    {
        for (int i = 0; i < this->size; i++)
        {
            this->coeffPtr[i] = 0;
        }

        for (int j = 0; j < rhs.size; j++)
        {
            this->coeffPtr[j] = rhs.coeffPtr[j];
        }
    }

    if (this->size == rhs.size)
    {
        for (int k = 0; k < this->size; k++)
        {
            this->coeffPtr[k] = rhs.coeffPtr[k];
        }
    }

    return *this;
}