#ifndef TIME_H
#define TIME_H
#include<iostream>
using namespace std;

class Time
{
  int hour;
  int min;
  int sec;
  string form =""; // для смены формата ыфводит на печать pm or am
public:
  Time():hour(0),min(0),sec(0){};
  Time(int h,int m,int s);
  friend ostream& operator<< (ostream &out, const Time &t);
  friend istream& operator>> (istream &in, Time &t);
  Time operator+(Time &t2);
  Time operator-(Time &t2);
  bool operator==(Time &t2);
  void fromRusToUsa();
  void fromUsaToRus();
};

#endif // TIME_H
