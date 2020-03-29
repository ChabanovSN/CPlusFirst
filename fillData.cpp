#include<human.h>

void inputData(Man * man){
    cout<<"Введите  имя"<<endl;
    cin>>man->firstName;
    cout<<"Введите фамилию"<<endl;
    cin>>man->lastName;
    cout<<"Введите возраст"<<endl;
    cin>>man->age;
    cout<<"Введите 1 (если пол мужской) 2 (если пол женский)"<<endl;
    int s = 0;
    cin>>s;
    if(s==1)man->gander=MALE;
    else man->gander=FAMALE;

}
