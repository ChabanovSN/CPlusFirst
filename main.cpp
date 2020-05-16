#include<iostream>
#include"Queue.h"

using namespace std;
void play(){
    Queue<char> q1;
    Queue<char> q2;
    Queue<char> q3;
      q1.setCircleSize(5);
q1.push('+'); q1.push('*'); q1.push('%'); q1.push('$'); q1.push('@');
      q2.setCircleSize(5);
q2.push('+'); q2.push('*'); q2.push('%'); q2.push('$'); q2.push('@');
      q3.setCircleSize(5);
q3.push('+'); q3.push('*'); q3.push('%'); q3.push('$'); q3.push('@');
int j = rand()%18, jj = rand()%25, jjj = rand()%15;
     for(int i =0;i<j;i++) q1.push(i);
     for(int i =0;i<jj;i++) q2.push(i);
     for(int i =0;i<jjj;i++) q3.push(i);
 int score = 0;
     cout<<"[ "<<q1.front()<<" : "<<q2.front()<<" : "<<q3.front()<<" ]"<<endl;

      if(q1.front() == q2.front() || q2.front() == q3.front())
        score = (int)q1.front() * 2;
       if(q1.front() == q2.front() && q1.front() == q3.front())
        score = (int)q1.front() * 3;
 if(score)cout<<" Вы выиграли "<<score<< " чяво то там.."<<endl;
 else cout<<" Не повезло, давай ещё!?"<<endl;

}
int main()
{
    srand(time(NULL));
    cout<<"Нажмите Enter для вращения барабана"<<endl;
    while(1){
        cin.get();
        play();
    }

    return 0;
}
