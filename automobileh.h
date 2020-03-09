#ifndef AUTOMOBILEH_H
#define AUTOMOBILEH_H
#include <iostream>
#include<cstring>
#include<string>
using namespace std;
//Задание 1:
//Реализовать структуру «Автомобиль» (длина, клиренс (высота посадки),
//объем двигателя, мощность двигателя, диаметр колес, цвет, тип коробки передач).
//Создайте функции для задания значений, отображения значений, поиска значений.
enum GEAR {AUTO, MECHACHICK};
struct Automobile{
    int lengthCar;
    int clearance;
    float engineDisplacement;
    int enginePower;
    float  wheelDiameter;
    string color;
    GEAR gearboxType;
    void createCar(){
        cout<<"Длина (цифра)\n"; cin>>lengthCar;
        cout<<"Клиренс (высота посадки)(цифра)\n";cin>>clearance;
        cout<<"Объем двигателя(цифра)\n";cin>>engineDisplacement;
        cout<<"Мощность двигателя(цифра)\n";cin>>enginePower;
        cout<<"Диаметр колес(цифра)\n";cin>>wheelDiameter;
        cout<<"Цвет (строка)\n";cin>>color;
        cout<<"Тип коробки передач (0 - автомат, 1 - механика)\n";
        int gear;
        cin>>gear;
        if(gear == 0)gearboxType = AUTO;
        if(gear == 1)gearboxType = MECHACHICK;
    }
    void toString(){
        cout<<"Длина: "<<lengthCar
            <<"\nКлиренс (высота посадки): "<<clearance
            <<"\nОбъем двигателя: "<<engineDisplacement
            <<"\nМощность двигателя: "<<enginePower
            <<"\nДиаметр колес: "<<wheelDiameter
            <<"\nЦвет: "<<color
            <<"\nТип коробки передач : "
            <<(!gearboxType ? "Автомат": "Механика")<<endl;
    }
    void find(){
        int item;
        cout<<" Введите  1 что бы узнать длину: "
            <<"\nВведите 2 что бы узнать клиренс (высота посадки): "
            <<"\nВведите 3  что бы узнать объем двигателя"
            <<"\nВведите 4 что бы узнать мощность двигателя"
            <<"\nВведите 5 что бы узнать диаметр колес "
            <<"\nВведите 6 что бы узнать цвет "
            <<"\nВведите 7 что бы узнать тип коробки передач\n ";cin>> item;
        switch (item) {
        case 1:
            cout<<"Длина: "<<lengthCar;
            break;
        case 2:
            cout<<"\nКлиренс (высота посадки)"<<clearance;
            break;
        case 3:
             cout <<"\nОбъем двигателя: \n"<<engineDisplacement;
            break;
        case 4:
            cout<<"\nМощность двигателя: "<<enginePower;
            break;
        case 5:
            cout<<"\nДиаметр колес: "<<wheelDiameter;
            break;
        case 6:
              cout<<"\nЦвет: "<<color;
            break;
        case 7:
            cout<<"\nТип коробки передач : "
               <<(!gearboxType ? "Автомат": "Механика");
            break;
        default:
            cout<<"Неверное значение"<<endl;
            break;
        }
      cout<<endl;
    }
};

//Задание 3:
//Реализовать структуру «Машина» (цвет, модель, номер).
//Номер машины может представлять из себя или пятизначный номер или слово до 8 символов.
//Рекомендации: номер реализовать как объединение.
union Number{
    char  * numS;
    int    numD;
};

struct Car
{
    string color;
    string model;
    int unittype;
    Number numCar;

    Car(){}
    Car( string c,string m, int u):
        color(c),model(m),unittype(u) {}
    void print(){
        if(unittype==0)
        cout<<"Цвет :"<<color<<" модель :"<<model<<" номер: "<<numCar.numS<<endl;
        else
         cout<<"Цвет :"<<color<<" модель :"<<model<<" номер: "<<numCar.numD<<endl;

    }
    void creat(){
         cout<<"Цвет :\n"; cin>>color;cout<<" модель :\n";cin>> model;
         cout<<" Типо номера 0 - строка, 1 цифры: \n";cin>>unittype;

         if(unittype==0)
         { char ch[8];
           cout<<"Номер (без пробелов)\n";
             cin>>ch;
             numCar.numS = ( char(*)) ch;
         }

         else
             cin>>numCar.numD;

    }
    void correct(){
        cout<<"Правка данных машины"<<endl;
        cout<<"Цвет правка "<<color<<endl;   cin>>color;
        cout<<" модель правка "<<model<<endl ;cin>> model;
        cout<<" Типо номера 0 - строка, 1 цифры: правка"<<unittype<<endl;;
        cin>>unittype;

        if(unittype==0)
        { char ch[8];
          cout<<"Номер (без пробелов)\n";
            cin>>ch;
            numCar.numS = ( char(*)) ch;
        }

        else
            cin>>numCar.numD;
    }

};

#endif // AUTOMOBILEH_H
