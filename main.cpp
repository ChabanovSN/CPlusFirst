#include "automobileh.h"
#include "libraryh.h"
void task1(); // структура "automobileh.h"
void task2();//структура "libraryh.h"
void task3(); // структура "automobileh.h"
void task4(); // структура "automobileh.h"

template<class D>
void findCarDigit(D a, Car cars[],const int N); // поиск машины по цифрам  номера 4е задание
template<class L>
void findCarLetter(L a, Car cars[],const int N); // поиск машины по буквам номера 4е задание
int main(){
    setlocale(LC_ALL,"RUS");
    task1();
    task2();
    task3();
    task4();
    return 0;
}
//Задание 1:
//Реализовать структуру «Автомобиль» (длина, клиренс (высота посадки),
//объем двигателя, мощность двигателя, диаметр колес, цвет, тип коробки передач).
//Создайте функции для задания значений, отображения значений, поиска значений.
void task1(){
    cout<<"Задача 1:"<<endl;
    Automobile masda;
    masda.createCar();
    masda.toString();
    masda.find();
}
//Задание 2:
//Разработайте программу «Библиотека».
//Создайте структуру «Книга» (название, автор, издательство, жанр).
//Создайте массив из 10 книг.
void task2(){
     cout<<"Задача 2:"<<endl;
     Book books[10];
      books[0]={"Book # 1","Vasya Pupkin","Dom Knigy","Horror"};
      books[1]={"Book # 2","Vasya Pupkin","Dom Knigy","not Horror"};
      books[2]={"Book # 3","Vasya Pupkin","Dom Knigy","Fantasy"};
      books[3]={"Book # 4","Vasya Pupkin","Dom Knigy","novel"};
      books[4]={"Book # 5","Vasya Pupkin","Dom Knigy","dump"};
      books[5]={"Book # 6","Vasya Pupkin","Dom Knigy","trush"};
      books[6]={"Book # 7","Vasya Pupkin","Dom Knigy","documentary"};
      books[7]={"Book # 8","Vasya Pupkin","Dom Knigy","news"};
      books[8]={"Book # 9","Vasya Pupkin","Dom Knigy","bla-bla-bla"};
      books[9]={"Book # 10","Vasya Pupkin","Dom Knigy","forcast"};

      for(int i = 0;i<10;i++)
          books[i].printBook();


}
//Задание 3:
//Реализовать структуру «Машина» (цвет, модель, номер).
//Номер машины может представлять из себя или пятизначный номер или слово до 8 символов.
//Рекомендации: номер реализовать как объединение.
void task3(){
     cout<<"Задача 3:"<<endl;
    Car c1;
    c1.creat();
    c1.print();
    Car c2;
    c2.creat();
    c2.print();
}
//*Задание 4:
//Создать массив из 10 экземпляров структуры «Машина»
//и реализовать для него следующие функции:
// Редактировать машину
// Печать всех машин
// Поиск машины по номеру
void task4(){
     cout<<"Задача 4:"<<endl;
     const int N =10;
     Car cars[N];
     cars[0]={"Red","Volga",0};
     cars[0].numCar.numS= (char (*))"a123bfRU";
     cars[1]={"Blue","Volga",0};
     cars[1].numCar.numS= (char (*))"a999bfRU";
     cars[2]={"Green","Volga",0};
     cars[2].numCar.numS= (char (*))"a33bfRU";
     cars[3]={"Red","Volga",1};
     cars[3].numCar.numD= 12345;
     cars[4]={"Red","Volga",1};
     cars[4].numCar.numD= 54321;
     cars[5]={"Dark","Volga",0};
     cars[5].numCar.numS= (char (*))"a777tfRU";
     cars[6]={"Red","Volga",0};
     cars[6].numCar.numS= (char (*))"a666ttRU";
     cars[7]={"Red","Volga",0};
     cars[7].numCar.numS= (char (*))"a123bfRU";
     cars[8]={"Red","Volga",1};
     cars[8].numCar.numD= 99999;
     cars[9]={"Red","Volga",1};
     cars[9].numCar.numD= 11111;
// Печать всех машин
     for(int i = 0; i<N;i++)
         cars[i].print();

    // Поиск машины по номеру
   // если это засунуть в одну функцию то на лету юнион не переопределятеся...
    findCarDigit( 11111,cars,N); // поиск по цифрам

    findCarLetter( "a123bfRU",cars,N);// поиск по буквам

    // Редактировать машину

      cars[9].correct(); // меняем номер на цифры 33333
     findCarDigit( 33333,cars,N);
}
template<class L>
void findCarLetter(L a, Car cars[], const int N){
    for(int i = 0; i<N;i++){
            if(cars[i].numCar.numS == (char (*)) a){
                cout<<"Мы нашли вашу машину"<<endl;
                cars[i].print();
                return;
            }
        }
     cout<<"У нас нет вашей машины"<<endl;


}
template<class D>
void findCarDigit(D a, Car cars[],const int N){
    for(int i = 0; i<N;i++){
        if(cars[i].unittype==1)
            if(cars[i].numCar.numD == (int) a){
                  cout<<"Мы нашли вашу машину"<<endl;
                cars[i].print();
                return;
            }
        }
     cout<<"У нас нет вашей машины"<<endl;
}

