#ifndef GROUPSTUDENT_H
#define GROUPSTUDENT_H
#include "student.h"
#include<vector>
class GroupStudent
{
private:
string name;
int number;
string year;

GroupStudent& createName(); // GroupStudent& это для создания конвеера
GroupStudent& createNumber();
GroupStudent& createYear();

public:
vector<Student *> group;
    GroupStudent();
    ~ GroupStudent();
     void addStudent();
     void printGroup();
     friend ostream& operator<<(ostream& os, const GroupStudent& gp); // выод на печать через перегрузку метода cout
    #endif // GROUPSTUDENT_H
};

