#ifndef PICTURE_H
#define PICTURE_H
#include <iostream>
using namespace std;
//класс "точка"
class Point {
    int X;int Y;//кооординаты
public:
    Point() {X = Y = 0;}//конструктор
    void SetPoint(int iX, int iY) {X = iX;Y = iY;    } //установка координат
    void Show() {//демонстрация координат
        cout << "----------------------------\n\n";
        cout << X << "\t" << Y << "\n\n";
        cout << "----------------------------\n\n";}
};
class Figura {//класс фигура
    Point* obj;//агрегация точки(координаты углов)
    int count;//количество углов
public:
    Figura() {count = 0; obj = NULL;}//конструктор
    void CreateFigura(int ct) {//создание фигуры
        //if (ct < 3) exit(0);//если углов меньше трех — это не фигура
        count = ct;//инициализация количества углов
        obj = new Point[count];//выдделение памяти под массив точек
        //if (!obj) exit(0);
        int tempX, tempY;//установка координат точек
        for (int i = 0; i < count; i++) {
            cout << "Set X\n";
            cin >> tempX;
            cout << "Set Y\n";
            cin >> tempY;
            obj[i].SetPoint(tempX, tempY);
        }
    }
    void ShowFigura() {    //показ фигуры
        cout << "----------------------------\n\n";
        cout << "\nPoints "<<count<<"\n";
        for (int i = 0; i < count; i++) {obj[i].Show();}
    }    //если фигура была очистить память
    ~Figura() {if (obj != NULL) delete[]obj;}
};
class Picture{
  const static int SIZE = 3;
  Figura figures[SIZE]; // картина из 3 фигур
public:
  Picture(){
      for(int i = 0; i <SIZE;i++){
          Figura f;
          f.CreateFigura(i+SIZE); // создние отделной фигуры
          figures[i]=f;
      }
  }
  void showPicture(){
      for(int i = 0; i <SIZE;i++){
          figures[i].ShowFigura(); // отрисовка
      }
  }

};

#endif // PICTURE_H
