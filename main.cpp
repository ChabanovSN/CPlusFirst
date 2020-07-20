#include <iostream>
#include"Auto.h"
#include"Functors.h"
using namespace std;
vector<int> v={16,5,3,4,7,9,4,2,7,87,62,13,25,1};

void task1(){
    cout<<"Машины в автосалоне"<<endl;
    AutoSalon salon;
    salon.AddCar(new Auto("C",2000,1.6,500.0));
    salon.AddCar(new Auto("B",2002,1.5,200.0));
    salon.AddCar(new Auto("A",2001,1.8,300.0));
    salon.show();
    cout<<" Сортировка по модели"<<endl;
    salon.sortAutoByName();
    salon.show();
    cout<<" Сортировка по году выпуска"<<endl;
    salon.sortAutoByYear();
    salon.show();
    Auto * car = new Auto("B",2002,1.5,200.0);
    salon.findCar(car) ? (cout<< "Машина найдина\n" ): (cout<<"Машины не найдина\n");
    salon. deleteCar(car) ? (cout<< "Машина удалена\n" ): (cout<<"Машины не найдина\n");
    salon.show();
}

void task2(){
 Show show; Min mn;Max mx; SortingDes srtDes;
 SortingAsc srtAs; Incrise inc;Decrise dec;
 deleteElm dElm;
cout<<" Минимальное значение "<<mn(v)<<endl;

cout<<" Максимальное значение "<<mx(v)<<endl;
show(v);
cout<<"Сортировка по убыванию "<<endl;
sort(v.begin(),v.end(),srtDes);
show(v);
cout<<"Сортировка по Возрастанию "<<endl;
sort(v.begin(),v.end(),srtAs);
show(v);
cout<<"Удалить все 4 "<<endl;
dElm(v,4);
show(v);
cout<<"Увеличить на 5 "<<endl;
inc(v,5);
show(v);
cout<<"Уменьшить на 6 "<<endl;
dec(v,6);
show(v);

}

int main()
{
  //task1();
    task2();
return 0;
}
