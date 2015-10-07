//
// Created by Shyawn Karim on 10/6/15.
//

#include "Poly.h"

using namespace std;

::Poly::istream &operator>>(::Poly::istream &inStream, Poly &poly)
{
    return <#initializer#>;
}

::Poly::ostream &operator<<(::Poly::ostream &outStream, const Poly &poly)
{
    return <#initializer#>;
}

Poly::Poly()
{

}

Poly::Poly(int coeff)
{

}

Poly::Poly(int coeff, int power)
{

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

void Poly::setCoeff(int coeff, int power) const
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
