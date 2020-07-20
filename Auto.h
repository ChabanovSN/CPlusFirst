#ifndef AUTO_H
#define AUTO_H
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Auto{
    string name;
    int yearOfCar;
    float engineCapacity,price;
public:
    Auto(string n,int year,float engine,float price){
        name=n;yearOfCar=year;engineCapacity=engine;this->price=price;
    }
    string getName(){return name;}
    int getYear(){return  yearOfCar;}
    float getEngineCopacity(){return engineCapacity;}
    float getPrice(){return price;}
    void show(){
        cout<<"Модель "<<name<<" год выпуска "<<yearOfCar<<"г."
           <<" объем двигателя "<<engineCapacity<<" цена "<<price<<"р."<<endl;
    }
    bool operator== (Auto &car){
        return name == car.getName() && yearOfCar==car.getYear();
    }
};

// Фнкторы для сортировки
class SortByName{ // сортировка по имени
public:
    bool  operator()( Auto * car1,  Auto *car2){
        return car1->getName()<car2->getName();
    }
};
class SortByYear{ // сортировка по году выпуску
public:
    bool operator()( Auto * car1,  Auto *car2){
        return car1->getYear()<car2->getYear();
    }
};

class AutoSalon{
    vector<Auto*> cars;

public:
    ~AutoSalon(){
        for(Auto * c: cars) delete  c;
    }
    void AddCar(){
        string name;
        int yearOfCar;
        float engineCapacity,price;
        cout<<"Модель "<<endl;cin>>name;
        cout<<"Год выпуска "<<endl;cin>>yearOfCar;
        cout<<"Объем двигателя "<<endl;cin>>engineCapacity;
        cout<<"Цена "<<endl;cin>>price;
        cars.push_back(new Auto(name,yearOfCar,engineCapacity,price));
    }
    void AddCar(Auto * car){
        cars.push_back(car);
    }
    bool findCar(Auto * car2){
        auto it = std::find_if( cars.begin(), cars.end(),
                                [&]( Auto *car1 ) { return *car1 == *car2; } );
        return    it != cars.end();
    }
    bool deleteCar(Auto * car2){
        auto it = std::find_if( cars.begin(), cars.end(),
                                [&]( Auto *car1 ) { return *car1 == *car2; } );
      if(it != cars.end()){
          cars.erase(it);
          return true;
      }else
          return  false;
    }
    void sortAutoByName(){
        SortByName srt;
        sort(cars.begin(),cars.end(),srt);
    }
    void sortAutoByYear(){
        SortByYear srt;
        sort(cars.begin(),cars.end(),srt);
    }
    void show(){for(auto e:cars)e->show();}
};

#endif // AUTO_H
