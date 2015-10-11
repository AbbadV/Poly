// --------------------- poly.h -----------------------------------------
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

#ifndef POLY_POLY_H
#define POLY_POLY_H


#include <iostream>


class Poly
{
    // Overloaded >> operator
    // Takes two ints that represent the coefficient and power
    // and sets them into the correct array position
    friend std::istream& operator>>(std::istream &inStream, Poly &sourceCoeff);

    // Overloaded << operator
    // Displays the complete polynomial in print view
    friend std::ostream& operator<<(std::ostream &outStream, const Poly &SourcePoly);

public:
    // Constructors and Destructor
    Poly();
    Poly(int coeff);
    Poly(int coeff, int power);
    Poly(const Poly &source);
    ~Poly();

    // Getter and Setter
    int getCoeff(int power) const;
    void setCoeff(int coeff, int power);

    // Binary arithmetic operators
    Poly operator+(const Poly &rhs) const;
    Poly operator-(const Poly &rhs) const;
    Poly operator*(const Poly &rhs) const;

    // Compound assignment operators
    Poly& operator+=(const Poly &rhs);
    Poly& operator-=(const Poly &rhs);
    Poly& operator*=(const Poly &rhs);

    // Comparison operators
    bool operator==(const Poly &rhs) const;
    bool operator!=(const Poly &rhs) const;

    // Assignment operator
    Poly& operator=(const Poly &rhs);

private:
    int* coeffPtr;  // Pointer to array
    int size;   // Size of array
};


#endif //POLY_POLY_H
