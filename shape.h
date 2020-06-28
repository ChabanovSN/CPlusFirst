#ifndef SHAPE_H
#define SHAPE_H
#include<iostream>
#include<math.h>
using namespace std;
class Shape{
 protected:
    string name;
  public:
   virtual float square() = 0;
   virtual void print(){
        cout<<name<<" имеет площадь = ";
    }
};
class Rectangle: public Shape{
  float width;
  float hight;
  public:
  Rectangle(float width,float hight){
      name ="Прямоугольник";
      this->width = width;
      this->hight = hight;
  }
  float square(){
      return width*hight;
  }
  void print(){
      Shape::print();
      cout<<square()<<endl;
  }
};
class Circle:public Shape{
    float radius;
 public:
    Circle(float r){
        name="Круг";
        radius=r;}
    float square(){
        return M_PI*radius*radius;
    }
    void print(){
        Shape::print();
        cout<<square()<<endl;
    }
};
class Right_triangle:public Rectangle{
  public:
    Right_triangle(float width,float hight):
        Rectangle(width,hight){
        name="Прямоугольный треугольник";
    }
    float square(){
        return Rectangle::square()/2;
    }
};
class Trapezoid: public Shape{
    float baseA;
    float baseB;
    float hight;
 public:
    Trapezoid(float baseA, float baseB, float hight){
        name="Трапеция";
        this->baseA=baseA;
        this->baseB=baseB;
        this->hight=hight;
    }
    float square(){//(a+b)h/2
        return (baseA+baseB)*hight/2;
    }
    void print(){
        Shape::print();
        cout<<square()<<endl;
    }
};
#endif // SHAPE_H
