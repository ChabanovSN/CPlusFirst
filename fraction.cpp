#include "fraction.h"
 #include <cassert>
Fraction::Fraction():
numerator(0),denominator(1)
{}

Fraction::Fraction(int numerator,int denominator)
{
   assert(denominator!=0); // знаменатель не может быть нулем
   this->numerator = numerator;
   this->denominator = denominator;

}
void ::Fraction::NOD(){
    int a = numerator;
    int b = denominator;
    while(a !=0 && b != 0){
        if(a>b) a %=b;
        else b %=a;
    }
    numerator /=(a+b);
    denominator /=(a+b);
}
Fraction Fraction:: operator+(Fraction fr2){
    int commDen = denominator * fr2.denominator;
     numerator *=fr2.denominator;
     fr2.numerator *=denominator;
     numerator +=fr2.numerator;
     denominator = commDen;
     NOD();
     return Fraction(numerator,denominator);
 }
Fraction Fraction:: operator-(Fraction fr2){
    int commDen = denominator * fr2.denominator;
     numerator *=fr2.denominator;
     fr2.numerator *=denominator;
     numerator -=fr2.numerator;
     denominator = commDen;
     NOD();
     return Fraction(numerator,denominator);

 }
Fraction Fraction:: operator*(Fraction &fr2){
     numerator *=fr2.numerator;
     denominator *=fr2.denominator;
      NOD();
     return Fraction(numerator,denominator);
 }
Fraction Fraction:: operator/(Fraction &fr2){
     numerator *=fr2.denominator;
     denominator +=fr2.numerator;
     NOD();
     return Fraction(numerator,denominator);
 }
 ostream& operator<< (ostream &out, const Fraction &fr){

      if(fr.numerator==0)return out<<"0"<<endl;
      if(fr.denominator==1)return out<<fr.numerator<<endl;
      if(fr.numerator == fr.denominator)return out<<"1"<<endl;

      if(fr.numerator>fr.denominator)
          return out<<(fr.numerator/fr.denominator)<<" и "
                   <<(fr.numerator%fr.denominator)
                   <<"/"<<fr.denominator<<endl;
    out<<fr.numerator<<"/"<<fr.denominator<<endl;
    return out;
 }

 istream& operator>> (istream &in, Fraction &fr){
     cout<<"Введите числитель:"<<endl;
     in>>fr.numerator;
     cout<<"Введите знаменатель:"<<endl;
     int d = 0;in>>d;
     while(d==0){
         cout<<"Знаменатель не должен быть равен нулю:"<<endl;
         in>>d;
          cout<<"Введите знаменатель:"<<endl;
     }
     fr.denominator = d;
     return in;
 }

