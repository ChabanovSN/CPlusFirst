#include "person.h"

Person::Person()
{
    setFirstName()
            .setLastName()
            .setPatronymic()
            .setAddGender()
            .setAge()
            .setMobPhone()
            .setHomePhone();
}

Person& Person::setFirstName(){
    cout<<"Имя: "<<endl;
   firstName= putStringInCharArray();
    return *this;
}
char * Person::getFirstName(){
 return firstName;
}

Person& Person::setLastName(){
    cout<<"Фамилия: "<<endl;
   lastName= putStringInCharArray();
    return *this;
}
char * Person::getLastName(){
    return lastName;
}
Person& Person::setPatronymic(){
    cout<<"Отчество: "<<endl;
   patronymic= putStringInCharArray();
    return *this;
}
char * Person::getPatronymic(){
   return patronymic;
}

Person& Person::setHomePhone(){
   cout<<"Домашний телефон: "<<endl;
   homePhone=putStringInCharArray();
    return *this;
}
char * Person::getHomePhone(){
    return homePhone;
}
Person& Person::setMobPhone(){
   cout<<"Мобильный телефон: "<<endl;
   mobPhone=putStringInCharArray();
    return *this;
}
char * Person::getMobPhone(){
    return mobPhone;
}
Person& Person::setAge(){
   cout<<"Возраст: "<<endl;
   int a;cin>>a;
   if(a>0) age=a;
    return *this;
}
int Person::getAge(){
    return age;
}
Person& Person::setAddGender(){
   cout<<"Пол: "<<endl;
   gender=putStringInCharArray();
    return *this;
}
char * Person::getAddGender(){
    return gender;
}
char * Person::putStringInCharArray(){
     getline(cin,getInfo);

  if(!getInfo.empty()){
       char * ch = new char[getInfo.size()+1];
     size_t i = 0;
     for(;i<getInfo.size();i++)
         ch[i]=getInfo[i];
     ch[i]='\0';
      getInfo="";
      return ch;
     }else{
       char * ch = new char[2];
       ch[0]='-';ch[1]='\0';
       return ch;
     }
}

void Person::Print(){
    cout<<*this;
}
ostream& operator<< (ostream &out, const Person &person){
      out<<"ФИО : "<<person.firstName<<" "<<person.patronymic<<" "<<person.lastName
        <<"\nВозраст: "<<person.age
        <<"\nПол :"<<person.gender<<"\nМобильный телефон: "<<person.mobPhone
        <<"\nДомашний телефон : "<<person.homePhone
        <<endl
        <<"---------------------------------------------"<<endl;
     return out;
 }
