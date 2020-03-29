#ifndef HUMAN_H
#define HUMAN_H
#include<iostream>
using namespace std;
enum SEX{MALE=1,FAMALE=0};
struct Man{
    string firstName;
    string lastName;
    int age;
    SEX gander;

};

void inputData(Man * man);
void outputData(const Man &man);
#endif // HUMAN_H
