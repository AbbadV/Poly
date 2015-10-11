// --------------------- poly.cpp -----------------------------------------
//
// Shyawn Karim, CSS 343
// Created:         October 6, 2015
// Last Modified:   October 10, 2015
// --------------------------------------------------------------
// Purpose: This class implements a representation of polynomials
// that do not have negative exponents.  Each polynomial is
// stored completely in one array. The index of the array
// represents the power and is where the corresponding coefficient
// is stored. Polynomials will be able to be changed any time and
// can be added, subtracted, or multiplied by each other.
// --------------------------------------------------------------
// Assumptions: All data will be assumed to be correct and there
// is no error handling of any kind.  Negative exponents will be
// ignored.
// --------------------------------------------------------------

#include "poly.h"

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

    while (true)    // takes in a pairs of numbers from the console
    {
        inStream >> coeff >> power; // assigns first to coeff, second to power

        if ((coeff == -1) && (power == -1)) // ends instream when both numbers are -1
        {
            break;
        }

        sourceCoeff.setCoeff(coeff, power); // assigns numbers to Poly object
    }

    return inStream;
}   // end of function

// --------------------- Overloaded << -----------------------------------------
// Outputs the polynomial in print form to the console
// If the array is empty then 0 is returned
// --------------------------------------------------------------
ostream &operator<<(ostream &outStream, const Poly &sourcePoly)
{
    bool allZeroes = true;  // check to see if polynomial is all 0s

        for (int i = sourcePoly.size - 1; i >= 0; i--)  // iterates through
            // entire array beginning with last index
        {
            if (sourcePoly.coeffPtr[i] != 0)    // check if index isn't 0
            {
                allZeroes = false;  // assigns allZeroes check to false

                outStream << " ";   // prints a space before the coefficient

                if (sourcePoly.coeffPtr[i] > 0) // check if index is greater than 0
                {
                    outStream << "+";   // prints a + before the coefficient
                }

                outStream << sourcePoly.coeffPtr[i];    // prints coefficient at index

                if (i != 0 && i != 1)   // check if power should be printed
                {
                    outStream << "x^" << i; // prints the x and power after coefficient
                }

                if (i == 1) // check if x should be printed
                {
                    outStream << "x";   // prints x after the coefficient
                }
            }
        }

    if (allZeroes == false) // check if polynomial wasn't all 0s
    {
        return outStream;   // prints polynomial in print form
    }
    else
    {
        return outStream << "0";    // prints 0 if polynomial is all zeroes
    }
}   // end of function

// --------------------- Default Constructor -----------------------------------------
// Takes no parameters and creates a Poly object
// Array size set to 1 and value set to 0
// --------------------------------------------------------------
Poly::Poly()
{
    this->size = 1;
    coeffPtr = new int[this->size];
    coeffPtr[0] = 0;
}   // end of function

// --------------------- Constructor int -----------------------------------------
// Overloaded constructor takes one parameter and creates a Poly object
// Array size set to 1 and value set to coeff passed in
// --------------------------------------------------------------
Poly::Poly(int coeff)
{
    this->size = 1;
    coeffPtr = new int[this->size];
    coeffPtr[0] = coeff;
}   // end of function

// --------------------- Constructor int int -----------------------------------------
// Overloaded constructor takes two parameters and creates a Poly object
// Array size set to power + 1 and the coefficient value in the last index
// --------------------------------------------------------------
Poly::Poly(int coeff, int power)
{
    this->size = power + 1;
    coeffPtr = new int[this->size];

    for (int i = 0; i < this->size ; i++)
    {
        coeffPtr[i] = 0;
    }

    coeffPtr[power] = coeff;
}   // end of function

// --------------------- Copy Constructor -----------------------------------------
// Creates a deep copy of the source Poly object passed in
// --------------------------------------------------------------
Poly::Poly(const Poly &source)
{
    this->size = source.size;
    coeffPtr = new int[size];

    for (int i = 0; i < this->size; i++)
    {
        coeffPtr[i] = source.coeffPtr[i];
    }
}   // end of function

// --------------------- Destructor -----------------------------------------
// Deletes coeffPtr and sets it NULL
// --------------------------------------------------------------
Poly::~Poly()
{
    delete[] coeffPtr;
    coeffPtr = NULL;
}   // end of function

// --------------------- getCoeff -----------------------------------------
// Returns the coefficient at chosen index (power)
// Returns 0 if index is out of range
// --------------------------------------------------------------
int Poly::getCoeff(int power) const
{
    if ((power >= 0) && (power < this->size)) // check if coefficient is in range
    {
        return coeffPtr[power]; // returns coefficient
    }
    else
    {
        return 0;   // returns 0 if request was not in range
    }
}   // end of function

// --------------------- setCoeff -----------------------------------------
// Set coeff passed in to the array index represented by power
// If power is out of array range then a new array is dynamically
// allocated and the coeff is assigned to correct index
// --------------------------------------------------------------
void Poly::setCoeff(int coeff, int power)
{
    if (power >= 0) // checks if requested index is positive
    {
        if (power < this->size)   // check if power is in range of array
        {
            coeffPtr[power] = coeff;    // assigns coefficient to index power
        }
        else
        {
            int *tempArr = new int[power + 1];  // creates new temp array

            for (int i = 0; i < this->size; i++)
            {
                tempArr[i] = coeffPtr[i];   // copies values from old array into temp
            }

            for (int j = this->size; j < power + 1; j++)
            {
                tempArr[j] = 0; // fill remainder of temp array indexes with 0s
            }

            tempArr[power] = coeff; // assigns coeff to correct index of temp array

            delete[] coeffPtr;  // deletes old array
            coeffPtr = NULL;    // points to NULL
            coeffPtr = tempArr; // points to temp array
            tempArr = NULL;     // temp array pointer points to NULL
            this->size = power + 1;   // reasigns size to the size of temp array
        }
    }
}   // end of function

// --------------------- Overloaded + -----------------------------------------
// Adds two different polynomials together
// Returns the sum in a Poly object
// --------------------------------------------------------------
Poly Poly::operator+(const Poly &rhs) const
{
    if (this->size > rhs.size)  // check if lhs is greater than rhs
    {
        Poly polySum(0, this->size);    // create Poly object to hold sum

        for (int i = 0; i < this->size; i++)
        {
            polySum.coeffPtr[i] = this->coeffPtr[i];    // copies all values of
                // the lhs into the new sum array
        }

        for (int i = 0; i < rhs.size; i++)
        {
            polySum.coeffPtr[i] += rhs.coeffPtr[i]; // adds rhs to sum array
        }

        return polySum; // returns the sum of the polynomials
    }
    else    // rhs is greater than lhs
    {
        Poly polySum(0, rhs.size);  // create Poly object of correct size

        for (int i = 0; i < rhs.size; i++)
        {
            polySum.coeffPtr[i] = rhs.coeffPtr[i];  // copies all values of
            // the rhs into the new sum array
        }

        for (int i = 0; i < this->size; i++)
        {
            polySum.coeffPtr[i] += this->coeffPtr[i];   // adds lhs to sum array
        }

        return polySum; // returns the sum of the polynomials
    }
}   // end of function

// --------------------- Overloaded - ----------------------------------------
// Subtracts one polynomial from another
// Returns the difference in a Poly object
// --------------------------------------------------------------
Poly Poly::operator-(const Poly &rhs) const
{
    if (this->size > rhs.size)  // check if lhs is greater than rhs
    {
        Poly polyDif(0, this->size);    // create Poly object to hold difference

        for (int i = 0; i < this->size; i++)
        {
            polyDif.coeffPtr[i] = this->coeffPtr[i];    // copies all values of
            // the lhs into the new difference array
        }

        for (int i = 0; i < rhs.size; i++)
        {
            polyDif.coeffPtr[i] -= rhs.coeffPtr[i]; // subtracts rhs from differnce array
        }

        return polyDif; // returns the difference of the polynomials
    }
    else    // rhs is greater than lhs
    {
        Poly polyDif(0, rhs.size);  // create Poly object to hold difference

        for (int i = 0; i < this->size; i++)
        {
            polyDif.coeffPtr[i] = this->coeffPtr[i];    // copies all values of
            // the rhs into the new difference array
        }

        for (int i = 0; i < rhs.size; i++)
        {
            polyDif.coeffPtr[i] -= rhs.coeffPtr[i]; // subtracts rhs from difference array
        }

        return polyDif; // returns the difference of the polynomials
    }
}   // end of function

// --------------------- Overloaded * -----------------------------------------
// Multiplies two different polynomials together
// Returns the product in a Poly object
// --------------------------------------------------------------
Poly Poly::operator*(const Poly &rhs) const
{
    int tempSize;   // creates a variable to hold the size of new array
    tempSize = (this->size + rhs.size - 2); // -2 to account for the constructor

    Poly tempArr(0, tempSize);  // creates new Poly object to hold the product

        for (int i = 0; i < this->size; i++)
        {
            if (this->coeffPtr[i] != 0) // only multiply by numbers that are't 0
            {
                for (int j = 0; j < rhs.size; j++)
                {
                    tempArr.coeffPtr[i + j] += (this->coeffPtr[i] * rhs.coeffPtr[j]);
                    // fills temp array of the new product values
                }
            }
        }

    return tempArr; // returns the product of the 2 polynomials
}   // end of function

// --------------------- Overloaded += -----------------------------------------
// Adds two different polynomials together
// Assigns the sum to the Poly object to the left of assignment
// --------------------------------------------------------------
Poly& Poly::operator+=(const Poly &rhs)
{
    *this = *this + rhs;
    return *this;
}   // end of function

// --------------------- Overloaded -= -----------------------------------------
// Subtracts one from polynomial from another
// Assigns the difference to the Poly object to the left of assignment
// --------------------------------------------------------------
Poly& Poly::operator-=(const Poly &rhs)
{
    *this = *this - rhs;
    return *this;
}   // end of function

// --------------------- Overloaded *= -----------------------------------------
// Multiplies two different polynomials
// Assigns the product to the Poly object to the left of assignment
// --------------------------------------------------------------
Poly& Poly::operator*=(const Poly &rhs)
{
    *this = *this * rhs;
    return *this;
}   // end of function

// --------------------- Overloaded == -----------------------------------------
// Checks if two Poly objects contain identical polynomials
// Returns true if they are and false if they aren't
// --------------------------------------------------------------
bool Poly::operator==(const Poly &rhs) const
{
    if (this->size == rhs.size)   // check to see if both arrays are the same size
    {
        for (int i = 0; i < this->size; i++)
        {
            if (coeffPtr[i] != rhs.coeffPtr[i]) // check if coeffs match
            {
                return false;   // polynomials are not the same
            }
        }

        return true;    // polynomials are the same
    }
    else    // polynomial arrays are not the same size
    {
        int bigArr;
        int smallArr;

        if (this->size < rhs.size)  // if rhs is bigger
        {
            smallArr = this->size;  // lhs is smaller array
            bigArr = rhs.size;  // rhs is bigger array

            for (int i = 0; i < smallArr; i++)
            {
                if (coeffPtr[i] != rhs.coeffPtr[i]) // check if coeffs match
                {
                    return false;   // polynomials are not the same
                }
            }

            for (int j = smallArr; j < bigArr; j++)
            {
                if (rhs.coeffPtr != 0)  // check if remainder of are 0s
                {
                    return false;   // polynomials are not the same
                }
            }

            return true;    // polynomials are the same
        }
        else    // lhs is bigger
        {
            smallArr = rhs.size;    // rhs is smaller array
            bigArr = this->size;    // lhs is bigger array

            for (int i = 0; i < smallArr; i++)
            {
                if (coeffPtr[i] != rhs.coeffPtr[i]) // check if coeffs match
                {
                    return false;   // polynomials are not the same
                }
            }

            for (int j = smallArr; j < bigArr; j++)
            {
                if (coeffPtr != 0)  // check if remainder are 0s
                {
                    return false;   // polynomials are not the same
                }
            }

            return true;    // polynomials are the same
        }
    }
}   // end of function

// --------------------- Overloaded != -----------------------------------------
// Checks if two Poly objects contain different polynomials
// Returns true if they are and false if they aren't
// --------------------------------------------------------------
bool Poly::operator!=(const Poly &rhs) const
{
    return !(*this == rhs); // returns the opposite of the overloaded ==
}   // end of function

// --------------------- Overloaded = -----------------------------------------
// Assigns the right Poly to the left Poly of the assignment operator
// --------------------------------------------------------------
Poly& Poly::operator=(const Poly &rhs)
{
    if (this->coeffPtr == rhs.coeffPtr) // check if lhs and rhs are identical
    {
        return *this;   // returns lhs
    }

    if (this->size < rhs.size)  // check if lhs is smaller than rhs
    {
        delete[] this->coeffPtr;    // delete lhs array
        coeffPtr = NULL;    // set lhs pointer to NULL
        this->size = rhs.size;  // sets lhs size to be the same as rhs
        this->coeffPtr = new int[this->size];   // new array created to copy into

        for (int i = 0; i < this->size; i++)
        {
            this->coeffPtr[i] = rhs.coeffPtr[i];    // copies values of rhs into new array
        }
    }

    if (this->size > rhs.size)  // check if lhs is bigger than rhs
    {
        for (int i = 0; i < this->size; i++)
        {
            this->coeffPtr[i] = 0;  // sets all lhs indexes to 0
        }

        for (int j = 0; j < rhs.size; j++)
        {
            this->coeffPtr[j] = rhs.coeffPtr[j]; // copies values of rhs into new array
        }
    }

    if (this->size == rhs.size) // check if lhs and rhs sizes are the same
    {
        for (int k = 0; k < this->size; k++)
        {
            this->coeffPtr[k] = rhs.coeffPtr[k];    // copies values of rhs into new array
        }
    }

    return *this;   // returns new array
}   // end of function