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
// DONE
// --------------------------------------------------------------
Poly::Poly()
{
    size = 1;
    coeffPtr = new int[size];
    coeffPtr[0] = 0;
}

// --------------------- Constructor int -----------------------------------------
// DONE
// --------------------------------------------------------------
Poly::Poly(int c)
{
    size = 1;
    coeffPtr = new int[size];
    coeffPtr[0] = c;
}

// --------------------- Constructor int int -----------------------------------------
// DONE
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
// DONE
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
// CAUTION
// --------------------------------------------------------------
Poly::~Poly()
{
    delete[] coeffPtr;
    //coeffPtr = NULL;
}

// --------------------- getCoeff -----------------------------------------
// DONE
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
// CAUTION
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
            //coeffPtr = NULL;
            coeffPtr = tempArr;
            delete[] tempArr;
            //tempArr = NULL;
            size = p +1;
        }
    }
}

// --------------------- getSize -----------------------------------------
// returns the size of the array
// --------------------------------------------------------------
int Poly::getSize() const
{
    return size;
}

// --------------------- operator+ -----------------------------------------
//
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
//
// --------------------------------------------------------------
Poly Poly::operator*(const Poly &rhs) const
{
    return Poly();
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