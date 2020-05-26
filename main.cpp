#include<iostream>
#include"List.h"
using namespace std;
void menu(){
    List<int> l;
    int n = 0,d,pos=0;
    while(1){
        cout<<"Введите 1 для вставки, 2 для удаления, 3 для поиска"<<endl;cin>>n;
        switch (n) {
        case 1:
            cout<<"Введите цифру и позицию для всавки"<<endl;
            cin>>d>>pos;
            l.insertAt(d,pos);
            break;
        case 2:
            cout<<"Введите  позицию для удаления"<<endl;
            cin>>pos;
            l.remove(pos);
            break;
        case 3:
            cout<<"Введите  элемент для поиска"<<endl;
            cin>>d;
            pos = l.find(d);
            if(pos == -1) cout<<"Элемент не найден"<<endl;
            else cout<<"Элемент находится в позиции "<< pos<<endl;

            break;
        }

        l.print();
    }
}

int main()
{
    menu();
    return 0;
}

