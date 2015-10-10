// --------------------------------------------------------------
//
//
//
//
// --------------------------------------------------------------
//
// --------------------------------------------------------------
//
// --------------------------------------------------------------

#ifndef POLY_POLY_H
#define POLY_POLY_H


#include <iostream>


class Poly
{
    friend std::istream& operator>>(std::istream &inStream, Poly &);
    friend std::ostream& operator<<(std::ostream &outStream, const Poly &);

public:
    Poly();
    Poly(int coeff);
    Poly(int coeff, int power);
    Poly(const Poly &source);
    ~Poly();

    int getCoeff(int power) const;
    void setCoeff(int coeff, int power);

//    int getSize() const;

    Poly operator+(const Poly &rhs) const;
    Poly operator-(const Poly &rhs) const;
    Poly operator*(const Poly &rhs) const;

    Poly& operator+=(const Poly &rhs);
    Poly& operator-=(const Poly &rhs);
    Poly& operator*=(const Poly &rhs);

    bool operator==(const Poly &rhs) const;
    bool operator!=(const Poly &rhs) const;
    Poly& operator=(const Poly &rhs);

private:
    int* coeffPtr;
    int size;
};


#endif //POLY_POLY_H
