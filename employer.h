#ifndef EMPLOYER_H
#define EMPLOYER_H
#include<iostream>
using namespace std;
class Employer{
protected:
    string status="";
    string name ="";
public:
    virtual void Print()=0;
};
class President: public Employer{

public:
    President(string name)
    {   this->name = name;
        status ="сам себе хозяин";
    }
    void Print(){
        cout<<"Кто таков?: "<<status<<endl;
        cout<<"Президент : "<<name<<endl;
    }

};
class Manager: public Employer{
public:
    Manager(string name){
        this->name = name;
        status ="личный лакей хозяина";
    }
    void Print(){
        cout<<"Кто таков?: "<<status<<endl;
        cout<<"Менаджер: "<<name<<endl;
    }

};
class Worker: public Employer{
public:
    Worker(string name){
        this->name = name;
        status ="челядь";
    }
    void Print(){
        cout<<"Кто таков?: "<<status<<endl;
        cout<<"Рабочий : "<<name<<endl;
    }

};
#endif // EMPLOYER_H
