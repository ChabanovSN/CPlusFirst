#include <iostream>
#include "Train.h"
using namespace std;



int main()
{  int n;string str;
   TrainStation ts;
   ts.addTrain();ts.addTrain();
   ts.showAll();
   cout<<"Введите  номер поезда для поиска"<<endl;cin>>n;
   ts.findTrain(n);
   cout<<"Введите  станцию назначения для поиска"<<endl;cin>>str;
   ts.findTrain(str);
    return 0;
}
