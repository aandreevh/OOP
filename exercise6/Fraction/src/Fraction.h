#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

class Fraction{

    int a,b;

public:

    Fraction();
    Fraction(int a,int b);
    Fraction(const Fraction&);
    ///~Fraction()

    Fraction& operator=(const Fraction&);
    Fraction& operator+=(const Fraction&);
    Fraction& operator-=(const Fraction&);
    Fraction& operator*=(const Fraction&);
    Fraction& operator/=(const Fraction&);

    Fraction operator+(const Fraction&) const;
    Fraction operator-(const Fraction&) const;
    Fraction operator-() const;
    Fraction operator*(const Fraction&) const;
    Fraction operator/(const Fraction&) const;

    friend ostream& operator<<(ostream&, const Fraction&);
    friend istream& operator>>(istream&, Fraction&);


    int getNumerator() const;
    void setNumerator(int);

    int getDenominator() const;
    void setDenominator(int);


};
#endif