#ifndef LIBRARYH_H
#define LIBRARYH_H
#include <iostream>
#include<cstring>
using namespace std;
//Задание 2:
//Разработайте программу «Библиотека».
//Создайте структуру «Книга» (название, автор, издательство, жанр).
//Создайте массив из 10 книг.

struct Book
{   string title;
    string auther;
    string publishingHouse;
    string genre;
    void printBook(){
        cout<<"Название: "<<title;
        cout<<" автор: "<<auther;
        cout<<" издательство: "<<publishingHouse;
        cout<<" жанре: "<<genre<<endl;

    }
    Book(){}
    Book(string t, string a, string p, string g):
    title(t),auther(a),publishingHouse(p),genre(g){}
};
#endif // LIBRARYH_H
