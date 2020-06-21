#include<iostream>
#include"Passport.h"
#include"Picture.h"
using namespace std;

int main(){
    ForeignPassport f; // Загранпаспорт
    cout<<f<<endl;
  /////
    Picture p;
    p.showPicture();
    return  0;
}
