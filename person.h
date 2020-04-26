#ifndef PERSON_H
#define PERSON_H
#include<iostream>
using namespace std;

class Person
{
private:
char * firstName  = 0;
char * lastName   = 0;
char * patronymic = 0;// отчество
char * homePhone  = 0;
int age = 0;
char * mobPhone   = 0;
char * gender  = 0; // пол
string getInfo=""; // получает из вводы нужную строку
char *  putStringInCharArray();// переводит объект getInfo в массив char нужной длины (данные о человеке)
public:
     Person();
     Person& setFirstName();
     char * getFirstName();
     Person& setLastName();
     char * getLastName();
     Person& setPatronymic();
     char * getPatronymic();
     Person& setHomePhone();
     char * getHomePhone();
     Person& setAge();
     int getAge();
     Person& setMobPhone();
     char * getMobPhone();
     Person& setAddGender();
     char * getAddGender();
     void Print();
     friend ostream& operator<< (ostream &out, const Person &person);
    ~Person(){
         delete firstName;
         delete lastName;
         delete patronymic;// отчество
         delete homePhone;        
         delete mobPhone;
         delete gender ;
    }
};

#endif // PERSON_H
