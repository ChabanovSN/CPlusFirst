#ifndef PASSPORT_H
#define PASSPORT_H
#include<iostream>
#include<iomanip>
using namespace std;
/*
1.Создайте класс Passport (паспорт) и с помощью механизма наследования,
реализуйтекласс ForeignPassport (загранпаспорт) производный от
Passport. Напомним, что загранпаспорт содержит помимо паспортных
данных, также данные о визах, номер загранпаспорта.
*/
class ForeignPassport;
struct Date
{ int day=0;
  int manth=0;
  int year = 0;
    Date(){};
    Date( int d,int m, int y){day=d,manth=m,year=y;}
    string getDate(){
        return to_string(day)+":" +to_string(manth)+":"+to_string(year)+"г.";
    }
     friend std::ostream& operator<< (std::ostream &out, const Date &d);
};
class Passport{
 string firtName;
 string midleName;
 string lastName;
 Date birthDay;
 string location;
public:
     Passport(){
        setFirstName().setMidletName()
         .setLastName().setBirthDay()
         .setLocation();
    };
    Passport& setFirstName(){
       cout<<"Имя: "<<endl;
       cin>>firtName;
       return  *this;
    }
    Passport& setMidletName(){
       cout<<"Отчество: "<<endl;
       cin>>midleName;
       return  *this;
    }
    Passport& setLastName(){
       cout<<"Фамилия: "<<endl;
       cin>>lastName;
       return  *this;
    }
    Passport& setLocation(){
       cout<<"Прописка: "<<endl;
       cin>>location;
       return  *this;
    }
    Passport& setBirthDay(){
       cout<<"Дата рождения; день: "<<endl;
       cin>>birthDay.day;
       cout<<"Дата рождения; месяц: "<<endl;
       cin>>birthDay.manth;
       cout<<"Дата рождения; год: "<<endl;
       cin>>birthDay.year;
       return  *this;
    }

    string getFirstName(){
       return firtName;
    }
    string getMidletName(){
      return midleName;
    }
   string getLastName(){
       return lastName;
    }
    string getLocation(){
      return location;
    }
    string getBirthDay(){
         return  birthDay.getDate();
    }

    friend std::ostream& operator<< (std::ostream &out, const ForeignPassport &p);
    friend std::ostream& operator<< (std::ostream &out, const Passport &p);

};

class ForeignPassport: public Passport{
    int number;
    string viza;
 public:
    ForeignPassport():Passport(){
        setNumber().setViza();
    }
    ForeignPassport& setNumber(){
        cout<<"Номер загран паспорта"<<endl;
        cin>>number;
        return  *this;
    }
    ForeignPassport& setViza(){
        cout<<"Куда виза: "<<endl;
        cin>>viza;
        return  *this;
    }
      friend std::ostream& operator<< (std::ostream &out, const ForeignPassport &f);
};

std::ostream& operator<< (std::ostream &out, const Date &d){
    out<<"Дата рождения: "<<out.width(2)<<d.day<<":"
    <<out.width(2)<<d.manth<<":"<<d.year<<"г.\n";
    return out;
}
std::ostream& operator<< (std::ostream &out, const Passport &p){
    out<<"ФИО "<<p.lastName<<"\n"<<p.firtName<<" "<<p.midleName<<endl
      <<p.birthDay<<"\nМесто прописки "<<p.location;
    return out;
}
std::ostream& operator<< (std::ostream &out, const ForeignPassport &p){
    out<<(Passport)p
     <<"Номер загран паспорта: "<<p.number<<" Визу в: "<<p.viza;
    return out;
}
#endif // PASSPORT_H
