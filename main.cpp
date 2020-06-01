#include<iostream>
#include<Tree.h>
using namespace std;

int main(){
   srand(time(0));
    Tree<int> t;
    for(int i =0 ; i<10;i++)
        t.insertNode(rand()%20+1);
    t.inOrderTraversal();
     int f;
    cout<<"\nПоиск элемента, введите элемент для поиска"<<endl;cin>>f;
    if(t.findNode(f))
        cout<<"Элемент "<<f<<" есть в дереве"<<endl;
    else
        cout<<"Нет элемента "<<f<<" в дереве"<<endl;
    cout<<"Максимальный элемент:  "<<t.getMax()<<endl;
    return 0;
}
