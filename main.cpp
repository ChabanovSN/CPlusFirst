#include"fraction.h"
#include "phonebook.h"
/*Задание 1.
Реализуйте класс Дробь.
*/
void task1(){
    Fraction f1,f2;
    char op;
     cin>>f1>>f2; // можно вносить данные через оператор ввода.
     cout<<"Введите арифметическую операцию + - / *"<<endl;cin>>op;
     switch (op) {
     case'+':
          cout<<"Сложение: "<<(f1+f2);
         break;
     case'-':
           cout<<"Вычетание: "<<(f1-f2);
         break;
     case'/':
         cout<<"Деление:   "<<(f1/f2);
         break;
     case'*':
           cout<<"Умнoжение: "<<(f1*f2);
         break;
     default:
         cout<<"Не верный оператор"<<endl;
     }
}
/*
 * Создайте приложение «Телефонная книга».
*/
void task2(){
    PhoneBook p; // создание телефоной книги
    p.addPerson(); // добавить 2 абонента
    p.addPerson();
    p.getAll(); // показать список
    Person * person = p.findForName(); // найти по имени
    if(person){
        cout<<*person<<endl; // вывод на печать найденого абоне6нта
        p.deleteForName(*person); // удаление найденного абонента

    }
    cout<<"После поиска и удаления"<<endl;
    p.getAll(); //вывод всех ( проверка результат после удаления )
}
int main(){
    setlocale(LC_ALL,"RUS");
   task1(); // первая задача
   task2();  // и вторая
    return 0;
}
