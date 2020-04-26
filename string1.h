#ifndef STRING_H
#define STRING_H
#include<iostream>
using namespace std;
class String
{
    char *str = 0;
    int length = 0;
    template<class T> // шаблон что бы рабоать с указателем и массив
    int getLength(T * st); // для определения длинны входящего массива чаров
public:
   int size(){ // для внешнего использования в циклах и т.д.
       return length;
   }

      String();
      String(char[]);
      String(String& str);
     ~String(){
      //  cout<<"Dectructor"<<endl;
        //delete str; // вот здесь проблема диструктор
        //срабатывает раньше чем я успеваю передать объект в cout
     }
       String operator+(const String &str2);
       String operator=(const char[]); // присвоение для массива чаров
       String operator=(const String& st);// присвоение для класс String
    friend std::ostream& operator<< (std::ostream &out, const String &str);
    friend std::istream& operator>> (std::istream& is,  String &str);
};

#endif // STRING_H
