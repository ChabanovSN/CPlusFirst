#include "person.h"

Person::Person()
{
    setFirstName()
            .setLastName()
            .setPatronymic()
            .setMobPhone()
            .setHomePhone()
            .setJobPhone()
            .setAdditInfo();
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
Person& Person::setJobPhone(){
   cout<<"Рабочий телефон: "<<endl;
   jobPhone=putStringInCharArray();
    return *this;
}
char * Person::getJobPhone(){
    return jobPhone;
}
Person& Person::setAdditInfo(){
   cout<<"Доп. информация: "<<endl;
   additInfo=putStringInCharArray();
    return *this;
}
char * Person::getAdditInfo(){
    return additInfo;
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

ostream& operator<< (ostream &out, const Person &person){
     out<<"ФИО : "<<person.firstName<<" "<<person.patronymic<<" "
        <<person.lastName<<"\n"<<"Мобильный телефон: "<<person.mobPhone
        <<"\nДомашний телефон : "<<person.homePhone<<"\nРабочий телефон: "<<person.jobPhone
        <<"\nДоп. информация :"<<person.additInfo<<endl
        <<"---------------------------------------------"<<endl;
     return out;
 }
