#include <iostream>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include <bits/stdc++.h>
using namespace std;
//Stack Char/
void calc();
char  StackC[80];
int CountC = 0;
void PushC(char value){ StackC[CountC++] = value;}

char PopC(){ return StackC[--CountC];}
char PeekC(){
    if (CountC != 0)
        return StackC[CountC-1];
    else
        return '\0';
}

//Stack Float/
float StackF[80];
int CountF = 0;
void PushF(float value){ StackF[CountF++]=value;}

float PopF(){ return StackF[--CountF];}
float PeekF()
{
    if (CountF == 0)return 0.0;
    return StackF[CountF];
}
//Возвращаем приоритет операции
int GetPriority(char value)
{
    if ( value == '^')
        return 4;
    if ((value == '*')||(value == '/'))
        return 3;
    if ((value == '+') || (value == '-'))
        return 2;
    if ((value =='(') || (value==')'))
        return 1;
    return 0;
}
float Calc(string str)
{
    int CountElements = str.size();
    string  digit = "";
    int digitCount = 0;

    //Чтение очередного элемента
    for (int i = 0; i < CountElements ; i++) {
        if(isdigit(str[i]) || str[i]== '.' ) // если цифра больше 10 и есть десятичные
        {  digitCount++;
            digit +=str[i];
            continue;
        }
        if(digitCount>0 ){ // перевод во фловд и сброс
            digitCount=0;
            PushF(stof(digit));
            digit="";
        }
        //если открывающееся скобка толкаем в стек
        if (str[i] == '(' ){
            PushC(str[i]);
            continue;
        }
        //Если закрывающееся скобка
        if (str[i] == ')'){
            //выталкиваем из стека все до открывающейся скобки
            while (PeekC() != '(') calc();

            PopC(); //  достаем '('
            continue;
        }
        //если в стеке операция с большим приоритетом
        if(str[i] == '+' ||str[i] == '*'||str[i] == '-'||str[i] == '/'||str[i] == '^'){
            if (GetPriority(PeekC()) >= GetPriority(str[i])&&CountC>0){
                calc();
                PushC(str[i]);
            }
            else
                PushC(str[i]);
        }
    }

    while (CountC > 0)  calc(); // добиваем остаток

    return PopF();
}


void calc(){
    float x = PopF();
    float y = PopF();
    //выполняем соотвествующую операцию и заталкиваем в стек
    char op = PopC();

    if (op == '+') PushF(y + x);
    if (op == '*') PushF(y * x);
    if (op == '/') PushF(y / x);
    if (op == '^') PushF(pow(y, x));
}

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "\t\tПриложение \"Калькулятор\"\n\n";
    cout << "Введите выражение: \n";
    //вводим строку с клавиатуры
    string str;
    getline(cin,str,'\n');
    //получаем ОПЗ
    float answer = Calc(str+" ");
    //    //выводим результат
    cout <<"Результат введенного выражения составляет: "<< answer << endl;

}
