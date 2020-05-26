#include<iostream>
#include"Queue.h"

using namespace std;
class Taksy{
public:
    int places=20;
    Taksy(int n = 0){// если остановка конечная то конструктор без параметров
                      // и соответсвенно места все свободные = 20
        if(n !=0)
         places = 1 + rand()%20; //мест в маршрутке от 1 до 20
     }
    friend ostream& operator<< (ostream &out, const Taksy &t);
};
ostream& operator<< (ostream &out, const Taksy &t){
    return  out<<"Свободных мест: "<<t.places<<endl;
}
int waiting(int t,int p){ // функция расчета среднего времени
    int time=0;
    Queue<int> diffTime;
    while(t-p >0){
      t -=p;
      diffTime.push(t);
    }
    int sizeQ = diffTime.size();
    while(!diffTime.isEmpty()){
        time +=diffTime.front();
        diffTime.pop();
    }
    return time/sizeQ;
}
void calcTimeForTaksy(int n){

    int time_pass = 2; // среднее время между появлениями пассажиров мин.
    int time_taksy= 160; //среднее время между   появлениями маршруток(изначально завышено) мин.
    int N = 15; // максимум допустивое число людей на остановке
      Queue<int> q_pass;
    int count = 0;
    while(count != 10){ // если 10 маршруток подряд забрали достаточное кол-во пассажиров,
                          //завершаем  расчет

          for(int i = 0;i<time_taksy/time_pass;i++)q_pass.push(1); // люди становятся в очередь

          if(q_pass.size() >N){// если в перерыве между маршрутками набралось больше людей ем нужно
                               // сократим время между маршрутками и очистии очередь
           for(int i = 0;i<time_taksy/time_pass;i++)q_pass.pop();
              time_taksy--;
              count = 0;
              continue;
          }else ++count;

          Taksy taksy(n); // подъезд маршрутки консруктор по-умалчанию
                         //для конечной остановке 20 свободных мест
                     // любая цифра отличная от нуля в конструкторе делает маршрутрку частично заполненной
          cout<<taksy<<" Людей на остановке: "<<q_pass.size()<<endl;
         int a =0;
          while(taksy.places && q_pass.size()){
              if(!q_pass.isEmpty() && taksy.places>0){
                taksy.places -=q_pass.front(); // посадка в маршрутку
                ++a;
                q_pass.pop();
              }else{
                  break;
              }

          }
          cout<<"В маршрутку село "<<a<<endl;a=0;
    }
cout<<"среднее время пребывание человека"
     <<" на остановке "<<waiting(time_taksy,time_pass)<<" минут"<<endl;
cout<<"Оптимальное время между маршрутками "<<time_taksy<<" минут"<<endl;
}
int main()
{
    srand(time(NULL));
   calcTimeForTaksy(1);
    return 0;
}
