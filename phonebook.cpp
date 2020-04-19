#include "phonebook.h"

void PhoneBook::getAll()
{   cout<<"Количество абонентов: "<<personList.size()<<endl;
    for(size_t i = 0; i<personList.size();i++)
        cout<<*personList[i];
}
void PhoneBook::addPerson(){
    personList.push_back(new Person);

}
string PhoneBook::reverseToString(char * ch){
    string str(ch);
    return str;
}
void PhoneBook::deleteForName(Person &person){
    string deleteFirstName(person.getFirstName());
    string deleteLasttName(person.getLastName());
    string deletePatronymic(person.getPatronymic());
    for(size_t i = 0; i<personList.size();i++){
        if((reverseToString(personList[i]->getFirstName())== deleteFirstName) &&
           (reverseToString(personList[i]->getLastName())== deleteLasttName) &&
           (reverseToString(personList[i]->getPatronymic())== deletePatronymic)){
            personList.erase(personList.begin()+i);
        }

    }

}
Person * PhoneBook::findForName(){
    vector<Person *> list;
    string str ="";
    cout<<" Поиск по имени:"<<endl;
    getline(cin,str);
    for(size_t i = 0; i<personList.size();i++){
        string data(personList[i]->getFirstName());
        if(data== str){
            list.push_back(personList[i]);
        }
    }
    str="";
    if(list.size())
        cout<<"Количество совпадений: "<<list.size()<<endl;
    else{
        cout<<"Совпадений не выявленно: "<<endl;
        return nullptr;
    }
    cout<<"поиск по отчеству:"<<endl;
    getline(cin,str);
    for(size_t i = 0; i<list.size();i++){
        string data(personList[i]->getPatronymic());
        if(data != str){
            list.erase(list.begin()+i);
        }
    }
    if(list.size())
        cout<<"Количество совпадений: "<<list.size()<<endl;
    else{
        cout<<"Совпадений не выявленно: "<<endl;
        return nullptr;
    }
    cout<<"Поиск по фамилии: "<<endl;
    getline(cin,str);
    for(size_t i = 0; i<list.size();i++){
        string data(personList[i]->getLastName());
        if(data != str){
            list.erase(list.begin()+i);
        }
    }
    if(list.size())
        cout<<"Количество совпадений: "<<list.size()<<endl;
    else{
        cout<<"Совпадений не выявленно: "<<endl;
        return nullptr;
    }

    if(list.size()==1)return  list[0];
    else {
        cout<<"В списке более одного совпадения: "<<endl;
        for(auto p: list)cout<<*p;
        return list[0];

    }
}

