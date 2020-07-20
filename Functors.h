#ifndef FUNCTORS_H
#define FUNCTORS_H
//2. В контейнере типа vector хранится набор целых чисел.
//Создайте функторы для решения следующих задач:







#include <iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
class Min{//2.1 Поиск минимального значения;
public:
    int operator()(vector<int> v){
        if(v.size()){
            int mn=v[0];
            for(int e: v)
                if(e<mn)mn=e;
            return mn;
        }else
            return 0;
    }
};
class Max{//2.2 Поиск максимального значения;
public:
    int operator()(vector<int> v){
        if(v.size()){
            int mx=v[0];
            for(int e: v)
                if(e>mx)mx=e;
            return mx;
        }else
            return 0;
    }
};
class Show{
public:
    void operator()(vector<int> v){
        if(v.size()){
            for(int e: v)
                cout<<e<<" ";
            cout<<endl;
        }}
};
class SortingDes{//2.3 Сортировка данных по убыванию;
public:
    bool operator()(int a,int b ){
        return  a>b;
    }
};
class SortingAsc{//2.4 Сортировка данных по возрастанию;
public:
    bool operator()(int a,int b ){
        return  a<b;
    }
};
class Incrise{//2.5 Увеличение значений в контейнере на заданную константу;
public:
    void operator()(vector<int>& v, int e){
        if(v.size()){
            for(size_t i = 0; i<v.size();i++ )
                v[i] +=e;
        }
    }
};
class Decrise{//2.6 Уменьшение значений в контейнере на заданную константу;
public:
    void operator()(vector<int>& v, int e){
        if(v.size()){
            for(size_t i = 0; i<v.size();i++ )
                v[i] -=e;
        }
    }
};
class deleteElm{//2.7 Удаление элементов из контейнера равных искомомузначению.
public:
    void operator()(vector<int>& v, int e){
        if(v.size()){

            vector<int>::iterator it=v.begin();
            while(it <v.end()){
                it = find(it,v.end(),e);
                if(it <v.end())
                    it= v.erase(it);

            }
        }
    }
};
#endif // FUNCTORS_H
