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
    coeffPtr = new int[1];
    coeffPtr[0] = 0;
}

Poly::Poly(int c)
{
    coeffPtr = new int[1];
    coeffPtr[0] = c;
}

Poly::Poly(int c, int p)
{
    coeffPtr = new int[p + 1];

    for (int i = 0; i < p; i++)
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

int Poly::getCoeff() const
{
    return 0;
}

void Poly::setCoeff(int c, int p) const
{

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
