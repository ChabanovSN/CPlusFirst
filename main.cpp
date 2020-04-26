#include "person.h"
#include "string1.h"
#include<iostream>
using namespace std;
/*Задание 1.
1. Разработать класс Person, который содержит соответствующие члены для хранения
*/
void task1(){
    Person p;
    p.Print();
}
/*
 Разработать класс String
*/
void task2(){
 String str; // конструктор по умолчанию
  cout<<"Введите строку"<<endl;
  cin>>str; // перегруженный оператор ввода
  cout<<str<<" str длина:"<<str.size()<<endl;
  str = "hi"; // перегруженный оператор присвоение для массива чаров
  cout<<str<<" str длина:"<<str.size()<<endl;
  String str2(str); //конструктор копирования
  cout<<str2<<" str2 длина:"<<str2.size()<<endl;
  char *p = "Array of chars";
  String  str3(p);  // конструктор с массивоми чаров
   cout<<str3<<" str3 длина:"<<str3.size()<<endl;
   String str4 ;
   str4 = str2+str3; // конкотация
   cout<<str4<<" str4 длина:"<<str4.size()<<endl;
}
int main(){
    setlocale(LC_ALL,"RUS");
   //task1(); // первая задача
   task2();  // и вторая
    return 0;
}
