#include<iostream>
#include<listnode.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<fstream>
using namespace std;
void writeFile( ListNode<Pass> &l);
ListNode<Pass> readFile();
int main(){

    ListNode<Pass> l;
    l.insertNode(Pass("vk","123"));
    l.insertNode(Pass("ok","h12334"));
    l.insertNode(Pass("mail.ru","12334"));
    l.insertNode(Pass("google.com","h12334"));
    l.insertNode(Pass("github","h12334"));
    l.print();
    cout<<endl;cout<<"Поиск, удаление и вставка в конец"<<endl;
    Pass p = l.findNode( Pass("mail.ru","12334"));
    cout<<endl<<p.getSite()<<" "<<  p.getPass()<<endl;
    l.deleteNode(p);
   // l.print();
    l.insertNode(p);

    cout<<"Записать в файл и очиска списка"<<endl;
    writeFile(l);

    ListNode<Pass> ll= readFile();
    ll.print();
    return 0;
}


ListNode<Pass> readFile(){
    ListNode<Pass> l;
    // конструктор ifstream открывает файл
    ifstream in("./db/pass.date", ios::binary );

    // если ifstream не смог открыть файл, выйти из программы
    if ( !in )
    {
        cerr << "File could not be opened" << endl;
        exit( 1 );
    } // конец if



    Pass p;
    while ( !in.eof()){
        in.read((char*)&p,sizeof(p));
        l.insertNode(p);
    }
    l.deleteNode(p); //  почемуто читает 2 раза последнию строку из файла..
    in.close();
    return l;
}

void writeFile( ListNode<Pass> &l){
    // Creating a directory
    mkdir("db", 0777);


    ofstream out( "./db/pass.date", ios::binary );

    // если ofstream не смог открыть файл, выйти из программы
    if ( !out )
    {
        cerr << "File could not be opened." << endl;
        exit( 1 );
    }


    int len =  l.size();

    for ( int i = 0; i < len; i++ ){
        Pass pass = l.popNode();
        out.write( reinterpret_cast<const char *>(&pass),
                   sizeof( pass ) );
    }

    out.close();

}


