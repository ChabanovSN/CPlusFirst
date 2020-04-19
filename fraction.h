#ifndef FRACTION_H
#define FRACTION_H
#include<iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction();
    Fraction(int,int);
    friend ostream& operator<< (ostream &out, const Fraction &fr);
    friend istream& operator>> (istream &in, Fraction &fr);
    Fraction operator+(Fraction fr2);
    Fraction operator-(Fraction fr2);
    Fraction operator*(Fraction &fr2);
    Fraction operator/(Fraction &fr2);
    void NOD();
};

#endif // FRACTION_H
