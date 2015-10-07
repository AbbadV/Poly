//
// Created by Shyawn Karim on 10/6/15.
//

#ifndef POLY_POLY_H
#define POLY_POLY_H


class Poly
{
    friend istream& operator>>(istream &inStream, Poly &);
    friend ostream& operator<<(ostream &outStream, const Poly &);

public:
    Poly();
    Poly(int);
    Poly(int, int);
    Poly(const Poly &);
    ~Poly();

    int getCoeff() const;
    void setCoeff(int, int) const;

    Poly operator+(const Poly &) const;
    Poly operator-(const Poly &) const;
    Poly operator*(const Poly &) const;

    Poly operator+=(const Poly &);
    Poly operator-=(const Poly &);
    Poly operator*=(const Poly &);

    bool operator==(const Poly &) const;
    bool operator!=(const Poly &) const;
    void operator=(const Poly &);

private:

};


#endif //POLY_POLY_H
