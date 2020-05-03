#include "time_.h"
#include <cassert>
#include<iomanip>
Time::Time(int h,int m,int s)
{
    assert(h>0 || h < 24);// отказ в создании объекта вслучаее выхода за рамки
    assert(m>0 || m < 60);
    assert(s>0 || s < 60);
    hour=h,min=m,sec=s;
}

bool Time::operator==(Time &t2){

    if(hour != t2.hour) return false;
    else{
        if(min !=t2.min) return false;
        else{
            if(sec !=t2.sec) return false;
        }
    }
    return true;
}


Time  Time::operator+(Time &t2){
    Time newTime;
    if((sec+t2.sec) >=60){
        newTime.sec = (sec+t2.sec)%60;
        newTime.min = (sec+t2.sec)/60;
    }else
        newTime.sec =sec+t2.sec;

    if((min+t2.min+newTime.min) >= 60){
        newTime.hour = (min+t2.min+newTime.min)/60;
        newTime.min = (min+t2.min+newTime.min)%60;
    }else
        newTime.min += min+t2.min;

    if((hour + t2.hour + newTime.hour) >= 23){
        newTime.hour = (hour + t2.hour + newTime.hour)%24;

    }else
        newTime.hour += hour + t2.hour;

    return newTime;
}

Time  Time::operator-(Time &t2){
    Time newTime;
    if((sec-t2.sec) <0){
        newTime.sec = 60  - ((sec-t2.sec)*(-1));
        --min;
        if(min<0){
            min=59;
            hour--;
            if(hour<0)hour=23;
        }
    }else
        newTime.sec =sec-t2.sec;

    if((min-t2.min) < 0){
        newTime.min = 60 - (min-t2.min) * (-1);
        hour--;
        if(hour<0)hour=23;

    }else
        newTime.min += min-t2.min;

    if((hour - t2.hour) < 0){
        newTime.hour = (hour - t2.hour)* (-1) - 1 ;
    }else
        newTime.hour = hour - t2.hour;

    return newTime;
}
void Time::fromRusToUsa(){
    if(hour>12){
        hour -=12;
        form="(pm)";
    }else
        form="(am)";
}

void Time::fromUsaToRus(){
    if(form=="(pm)")hour +=12;
    form="";
}

istream& operator>> (istream &in, Time &t){
    cout<<" Введите час "<<endl;
    int i; in>>i;
    while(i<0 || i>24 ){
        cout<<"Час должен быть от 0 до 24, повтор попытки"<<endl;
        in>>i;
    }
    t.hour=i;

    cout<<" Введите минуты "<<endl;
    in>>i;
    while(i<0 || i>60 ){
        cout<<"Минуты должен быть от 0 до 60, повтор попытки"<<endl;
        in>>i;
    }
    t.min=i;
    cout<<" Введите секунды "<<endl;
    in>>i;
    while(i<0 || i>60 ){
        cout<<"секунды должен быть от 0 до 60, повтор попытки"<<endl;
        in>>i;
    }
    t.sec=i;

    return in;
}
ostream& operator<< (ostream &out, const Time &t){
    out.fill('0');
    out<<t.form<<setw(2)<<t.hour<<":"<<setw(2)<<t.min<<":"<<setw(2)<<t.sec<<endl;
    return out;
}
