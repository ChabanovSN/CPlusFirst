
#include<human.h>

void outputData(const Man &man){
    cout<<"Имя: "<<man.firstName
       <<"\nФамилия: "<<man.lastName
      <<"\nВозраст: "<<man.age
     <<"\nПол:"<<(man.gander==1? "мужской":"женский" )<<endl;

}


