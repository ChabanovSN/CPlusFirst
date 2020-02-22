#include <iostream>
#include<cstring>
#include<cctype>
using namespace std;

void task1(void);
void task2(void);
void task3(void);
void task4(void);
void task5(void);
void task5_1(char *);

int main(){
      setlocale(LC_ALL,"RUS");
    task1();// 1я задача
    task2();// 2я задача
    task3();// 3я задача
    task4();// 4я задача
    task5();// 5я задача
    return 0;
}

//1.Пользователь вводит строку с клавиатуры в массив. Необходимо проверить,
//сколько элементов массива теперь занято и сколько свободно.

void task1(void){
    cout<<"1я задача"<<endl;

    char str[50];
     cout<<"Введите строку"<<endl;
     cin>>str;
     cout<<"Строка заняла "<<strlen(str) +1 // плюс один на '\0'
       <<" элементов массива, свободно "<<
       50 - (strlen(str) +1)<<endl;

}
//2. Дана строка символов. Заменить в ней все пробелы на табуляции.
void task2(void){
     cout<<"2я задача"<<endl;

   char str[] ="one two three four";
    cout<< "Before: "<<str<<endl;
   for(int i = 0; i <sizeof str; i++)
       if(str[i]==' ')str[i]='\t';
    cout<< "After : "<<str<<endl;
}
//3. Дана строка символов. Определить количество букв, цифр и остальных символов, присутствующих в строке.

void task3(void){
     cout<<"3я задача"<<endl;

   char str[] ="one_1 two-2 three^3 four: 4";
   cout<<"Строка для анализа: "<<str<<endl;
    int letter =0, digit = 0;
    for(int i = 0; i <sizeof str; i++){
        if(isdigit(str[i])) digit++;
        if(isalpha(str[i])) letter++;
    }
    cout<<"букаФФ: "<<letter
         <<"\nЦифр: "<<digit
         <<"\nОстальные символы: "<< ((sizeof str )-1 - digit - letter)
         <<endl;
}
//4. Подсчитать количество слов во введенном предложении.

void task4(void){
     cout<<"4я задача"<<endl;

   char str[] =" 1 two 3 \t \t four 5 ";
   cout<<"Строка для анализа: "<<str<<endl;
    int words =0;
    int start =0;
     while(isspace(str[start++])); // убираем пробелы спереди

    int stop  =sizeof str;
     while(isspace(str[--stop])); //убираем пробелы сзади

    for(int i = start; i <= stop;){
         while(!isspace(str[i++])); /// пропускаем все кроме пробелов и табуляции
            words++; // сработает после букв
         while(isspace(str[i++])); /// убераем если пробелов и табуляций больше чем одна

    }
    cout<<"Слов: "<<words<<endl;
}
//5. Дана строка символов. Необходимо проверить является ли эта строка палиндромом.
void task5(){
    char str1[] ="abcdTdcba";
    task5_1(str1);
    char str2[] ="abtdTdhhba";
     task5_1(str2);
}
void task5_1(char * str){
     cout<<"5я задача"<<endl;
   cout<<"Строка для анализа: "<<str<<endl;
   bool poldr = 0;
    for(int i = 0, j =strlen(str)-1; i <j; i++,j--){
        if(str[i] !=str[j]){ // в одном цикле сравниваем первый и последний сивмол
            poldr =1; break;
        }
  }
    if(poldr){
        cout<<str<<" Не палиндромом"<<endl;
    }else
        cout<<str<<" Палиндромом"<<endl;

}
