#include "groupstudent.h"

GroupStudent::GroupStudent()
{
   createName()
   .createNumber()
   .createYear();
}
GroupStudent::~GroupStudent(){
 for (int i = 0; i <(int) group.size(); ++i)
     delete group[i];
cout<<"Диструктор группы студентов"<<endl;
}

GroupStudent& GroupStudent::createName(){
    cout<<"Введите название группы:"<<endl;
    string str="";
    getline(cin,str);
    name=str;
    return *this;
}
GroupStudent& GroupStudent::createNumber(){
    cout<<"Введите номер группы:"<<endl;
    int str=0;
    cin>>str;
    cin.clear();
    cin.ignore(255,'\n');// так как cin общий  из за *this строку надо учистить
    number=str;
    return *this;
}

GroupStudent& GroupStudent::createYear(){
    cout<<"Введите год формирвания группы:"<<endl;
    string str="";
    getline(cin,str);
    year=str;
    return *this;
}

void GroupStudent::addStudent(){
      cout<<"Зачисление студента:"<<endl;
      group.push_back(new Student());
      cout<<"Студент зачислен: "<<endl;

}
void GroupStudent::printGroup(){
     cout << "Количество студентов: "<<group.size()<<endl;
    for( auto &st : group){
     st->print();
    }

}
ostream& operator<<(ostream& os, const GroupStudent& gp){
    os<<"Название группы: "<<gp.name<<" номер: "<<gp.number<<" год: "<<gp.year
    << "\n Cписок студентов: "<<endl;
    return os;
}


