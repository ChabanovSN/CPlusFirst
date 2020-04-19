#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include<vector>
#include "person.h"
using namespace std;


class PhoneBook
{
private:
  vector<Person *> personList;
  string reverseToString(char *);// перевод обратно в стринг так как их легче сравнивать
public:    
    void getAll();
    Person * findForName();
    void deleteForName(Person&);
    void addPerson();
    ~PhoneBook(){
        for(size_t i = 0; i<personList.size();i++)
            delete personList[i];
    }
};

#endif // PHONEBOOK_H
