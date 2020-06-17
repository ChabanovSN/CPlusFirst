#include<iostream>
#include"Transport.h"
using namespace std;
int main(){
   Velo v;
   v.setQuantitySpeed(25).setTypeFrame("Универсал");
   Moto m;
   Car c;
   c.setGear(gear::Auto);
   Lorry l; // грузовик
   l.setWheels(8).setCarrying(9.5);

   v.print(); m.print();c.print();l.print();
    return  0;
}
