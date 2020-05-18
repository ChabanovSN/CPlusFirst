#include<iostream>
#include"QueuePrior.h"
#include <thread>
using namespace std;
class Client{
public:
     string name="";
     int prior=0; // приоритет
    Client(string n,int p):name(n),prior(p){}
    friend ostream& operator<< (ostream &out, const Client &t);
};
ostream& operator<< (ostream &out, const Client &c){
    return  out<<"Клиент: "<<c.name<<" приоритет: "<<c.prior<<endl;
}
class Statictic{
public:
    Client client;
    time_t givemetime;
    Statictic(Client c):client(c){
     givemetime = time(NULL);
    }
   friend ostream& operator<< (ostream &out, const Statictic &st);
};
ostream& operator<< (ostream &out, Statictic &st){
    return  out<<st.client<<"Время отправки на печать: "<< ctime(&st.givemetime);
}
int main()
{
     Client c1("c1",2), c2("c2",1),c3("c3",3),c4("c4",3);
     Client c5("c5",2),c6("c6",1);
     Client   c7("c3",3),c8("c4",3);
    QueuePrior<Client> q;
    q.push(c1, c1.prior);    q.push(c2, c2.prior);
    q.push(c3, c3.prior);    q.push(c4, c4.prior);
    q.push(c5, c5.prior);    q.push(c6, c6.prior);
    q.push(c7, c7.prior);   q.push(c8, c8.prior);
 cout<<"Очередь сортированная по приорету"<<endl;
    q.print();

   QueuePrior<Statictic> qs; // отдельная очередь для статистики
  cout<<"Статистика печати"<<endl;
   int l = q.size();
   for(int i = 0; i<l;i++){
      Client c = q.front();
      q.pop();
      this_thread::sleep_for(1s);
      Statictic st(c);
      qs.push(st,i);
  }
   qs.print();
    return 0;
}
