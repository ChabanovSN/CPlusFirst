#include<iostream>
#include"employer.h"
#include"shape.h"
using namespace std;
void Task1(){
    Employer * employers[]= {new President("Сергей Николаевич"),
                             new Manager("Шурик"),
                             new Worker("Петрович")};
    for(auto e : employers) e->Print();  
}
void Task2(){
    Shape * shapes[]={
        new Rectangle(2,3),
        new Circle(2.5),
        new Right_triangle(4,3),
        new Trapezoid(5,4,2.5)};
    for(auto s :shapes)s->print();

}

int main(){
//Task1();
Task2();
    return  0;
}
