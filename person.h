#ifndef PERSON_H
#define PERSON_H
#include<iostream>
using namespace std;

class Person
{
private:  // указатели для динамической памяти (требование задачи)
char * firstName  = 0;
char * lastName   = 0;
char * patronymic = 0;// отчество
char * homePhone  = 0;
char * jobPhone   = 0;
char * mobPhone   = 0;
char * additInfo  = 0; // доп информация
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
     Person& setJobPhone();
     char * getJobPhone();
     Person& setMobPhone();
     char * getMobPhone();
     Person& setAdditInfo();
     char * getAdditInfo();
     friend ostream& operator<< (ostream &out, const Person &person);
    ~Person(){
         delete firstName;
         delete lastName;
         delete patronymic;// отчество
         delete homePhone;
         delete jobPhone;
         delete mobPhone;
         delete additInfo ;
    }
};

#endif // PERSON_H
