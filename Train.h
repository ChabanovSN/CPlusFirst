#ifndef TRAIN_H
#define TRAIN_H
#include<iostream>
#include<vector>
using namespace  std;

class Train{
  int number;
  string destinationStation;
  string departureTime;
public:
  Train(int number,string rout, string timeDest){
      this->destinationStation=rout;
      this->number=number;
      this->departureTime=timeDest;
  }
  string getDestinationStation(){
      return destinationStation;
  }

  int getTrainNumber(){
      return  number;
  }
  void show(){
      cout<<"\nПоезд № "<<number<<" станцию назначения:"<<destinationStation
         <<"\n время отправления"<<departureTime<<endl;
  }
};
class TrainStation{
    vector<Train *> trains;
public:
    void addTrain(){
        int number;
        string destinationStation,departureTime;
        cout<<" Номер поезад"<<endl;cin>>number;
        cout<<" Станция назначения"<<endl;cin>>destinationStation;
        cout<<" Время отбытия"<<endl;cin>>departureTime;
        trains.push_back(new Train(number,destinationStation,departureTime));
    }

    void findTrain(int n){
         for(auto t: trains)
                 if(n==t->getTrainNumber()){
                     t->show();
                     return;
                 }

         cout<< "Поезд не найден"<<endl;
    }
    void findTrain(string n){
         for(auto t: trains)
                 if(n ==t->getDestinationStation()){
                     t->show();
                     return;
                 }

         cout<< "Поезд не найден"<<endl;
    }
    void showAll(){
         for(auto t: trains) t->show();
    }
    ~TrainStation(){
        for(auto t: trains) delete t;
    }
};

#endif // TRAIN_H
