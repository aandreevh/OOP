#include "Fraction.h"
#include <iostream>

using namespace std;


Fraction::Fraction(): Fraction(0,1) {}

Fraction::Fraction(int a, int b) {
setNumerator(a);
setDenominator(b);
}

Fraction::Fraction(const Fraction & other) {
    (*this) = other;
}

Fraction& Fraction::operator=(const Fraction & other) {

    setNumerator(other.getNumerator());
    setDenominator(other.getDenominator());

    return *this;
}

Fraction& Fraction::operator+=(const Fraction & other) {

    setNumerator(getNumerator()*other.getDenominator()+other.getNumerator()*getDenominator());
    setDenominator(getDenominator()*other.getDenominator());

    return *this;
}

Fraction& Fraction::operator-=(const Fraction& other) {

    setNumerator(getNumerator()*other.getDenominator()-other.getNumerator()*getDenominator());
    setDenominator(getDenominator()*other.getDenominator());

    return *this;
}

Fraction& Fraction::operator*=(const Fraction& other) {

    setNumerator(getNumerator()*other.getNumerator());
    setDenominator(getDenominator()*other.getDenominator());

    return *this;
}

Fraction& Fraction::operator/=(const Fraction& other) {
    //? other =0

    setNumerator(getNumerator()*other.getDenominator());
    setDenominator(getDenominator()*other.getNumerator());


    return *this;
}

Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction(*this) += other;
}

Fraction Fraction::operator-(const Fraction& other) const {
    return Fraction(*this) -= other;
}

Fraction Fraction::operator-() const {
    return Fraction(-getNumerator(),getDenominator());
}

Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(*this) *= other;
}

Fraction Fraction::operator/(const Fraction& other) const {
    return Fraction(*this) /= other;
}

int Fraction::getNumerator() const {
    return this->a;
}

void Fraction::setNumerator(int a) {
    this->a = a;
}

int Fraction::getDenominator() const {
    return this->b;
}

void Fraction::setDenominator(int b) {
    //? b=0
    this->b = b;
}

ostream& operator<<(ostream& output,const Fraction& fraction){
    output<<fraction.getNumerator()<<"/"<<fraction.getDenominator();

    return output;
}

istream& operator>>(istream& input,Fraction& fraction){
    int in;
    input>>in; fraction.setNumerator(in);
    input>>in; fraction.setDenominator(in);

    return input;
}
