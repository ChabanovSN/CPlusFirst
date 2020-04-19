#include"fraction.h"
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
int main(){
    setlocale(LC_ALL,"RUS");
    task1();

    return 0;
}
