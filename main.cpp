#include<iostream>
#include"Queue.h"

using namespace std;   
int main()
{
   Queue<int> q;
   cout<<"Создание очереди из 5 элементов"<<endl;
   for(int i=0; i<5;i++)
     q.push(i);
     q.print();
     cout<<"Для демонстрации 2-х связанного списка, выведение"
       <<" напечать списка в обратном нарпавлении"<<endl;
     q.printBack();
    return 0;
}
