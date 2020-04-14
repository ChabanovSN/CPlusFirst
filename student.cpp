#include "student.h"

Student::Student()
{
setFirstName();
setLastName();
setAddressName();
setAge();
}
Student::~Student(){
    cout<<"деструктор для студента "<<getFirstName()<<endl;
}
void Student::setFirstName(){
    firstName =checkInput("имя");
}
string Student::getFirstName(){
    return firstName;
}
void Student::setLastName(){
    lastName =checkInput("фамилию");
}
string Student::getLastName(){
    return lastName;
}
void Student::setAddressName(){
    address =checkInput("адресс");
}
string Student::getAddressName(){
    return address;
}
void Student::setAge(){
    int str=0;
    cout<<"Введите возраст студента"<<endl;
     cin>>str;
    while(str<=0){
           cout<<"возраст не должен  быть пустым или отрицательный"<<endl;
           cout<<"Введите возраст студента"<<endl;
           cin.clear();
           cin>>str;
    }
    age =str;
}
int Student::getAge(){
    return age;
}
string Student::checkInput(string field){
    string str="";
     cout<<"Введите "<<  field <<" студента"<<endl;
     cin>>str;
    while(str.empty()){
             cout<<"Вы ввели пустое значение"<<endl;
             cout<<"Введите "<<  field <<" студента"<<endl;
           getline(cin,str);
    }
    return str;
}
void Student::print(){
    cout<<"Имя: "<<getFirstName()<<" фамилия: "
      <<getLastName()<<"\nвозраст: "<<getAge()
      << " адрес: "<<getAddressName()<<endl;
}

