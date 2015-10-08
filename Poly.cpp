//
// Created by Shyawn Karim on 10/6/15.
//

#include "Poly.h"


istream &operator>>(istream &inStream, Poly &poly)
{
    return <#initializer#>;
}

ostream &operator<<(ostream &outStream, const Poly &poly)
{
    return <#initializer#>;
}

Poly::Poly()
{
    size = 1;
    coeffPtr = new int[size];
    coeffPtr[0] = 0;
}

Poly::Poly(int c)
{
    size = 1;
    coeffPtr = new int[size];
    coeffPtr[0] = c;
}

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

Poly::Poly(const Poly &source)
{

}

Poly::~Poly()
{

}

int Poly::getCoeff(int c) const
{
    return 0;
}

void Poly::setCoeff(int c, int p) const
{

}

int Poly::getSize() const
{
    return 0;
}

Poly Poly::operator+(const Poly &rhs) const
{
    return Poly();
}

Poly Poly::operator-(const Poly &rhs) const
{
    return Poly();
}

Poly Poly::operator*(const Poly &rhs) const
{
    return Poly();
}

Poly Poly::operator+=(const Poly &rhs)
{
    return Poly();
}

Poly Poly::operator-=(const Poly &rhs)
{
    return Poly();
}

Poly Poly::operator*=(const Poly &rhs)
{
    return Poly();
}

bool Poly::operator==(const Poly &rhs) const
{
    return false;
}

bool Poly::operator!=(const Poly &rhs) const
{
    return false;
}

void Poly::operator=(const Poly &rhs)
{

}