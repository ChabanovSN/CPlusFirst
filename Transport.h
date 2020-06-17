#ifndef TRANSPORT_H
#define TRANSPORT_H
#include<iostream>
#include<string.h>
using namespace std;
enum gear{Auto,Mech}; // тип коробки передач
class Transport{
    float speed=0, weight=0;
    string category_of_rights, type;
public:
    Transport(float s,float w, string c , string t):
        speed(s),weight(w),category_of_rights(c),type(t){}
    void print(){
        cout<<"Тип транспорта: "<<type<<"\nСкорость: "<<
              speed<<" Вес: "<<weight<<
              " Категория: "<<category_of_rights <<endl;
    }
};
class Velo: public Transport{
    int quantity_speed = 0; //сколько скроростей
    string type_frame = "";//тип рамы
public:
    Velo():Transport(25,30,string("A0"),"Велосипед"){}
    Velo& setQuantitySpeed (int n){
        quantity_speed = n;
        return *this;
    }
    Velo& setTypeFrame (string str){
        type_frame=str;
        return *this;
    }
    void print(){
        Transport::print();
        cout<<"Количество скоростей: "<<quantity_speed
           <<" Тип рамы: "<<type_frame<<endl<<endl;
    }
};
class Moto: public Transport{
public:
    Moto():Transport(250,90,string("A"),"Мотоцикл"){}
};
class Auto: public Transport{
    gear g = Mech; // коробка
public:
    Auto(float speed,float weight, const char *cat,const char *t):
        Transport(speed,weight,cat,t){}
   void setGear(gear g){
       Auto::g=g;
    }
   void print(){
       Transport::print();
       cout<<"Коробка передач: ";
       (g== gear::Mech)?(cout<<"Механика \n"):(cout<<"Автомат\n");
   }
};
class Car:public Auto{
public:
    Car():Auto(250,900,"В","Легковой автомобиль"){}
};
class Lorry: public Auto{
    int wheels = 4;
    float carrying = 8;
public:
    Lorry():Auto(140,3500,"C","Грузовой автомобиль"){}
    void print(){
        Auto::print();
        cout<<"Количество колес: "<<wheels
           <<" Грузоподъёмность: "<<carrying<<" тонн"<<endl<<endl;
    }
    Lorry& setWheels(int n){
        wheels=n;
        return  *this;
    }
    Lorry& setCarrying(float n){
        carrying=n;
        return  *this;
    }
};

#endif // TRANSPORT_H
