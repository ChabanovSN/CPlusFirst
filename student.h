#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
using namespace std;

class Student
{
private:
string firstName;
string lastName;
string address;
int age;

string checkInput(string field); // проверка что бы строка не была пустая
public:
     Student();
    ~Student();
    void setFirstName();
    string getFirstName();
    void setLastName();
    string getLastName();
    void setAddressName();
    string getAddressName();
    void setAge();
    int getAge();
    void print();

};

#endif // STUDENT_H
