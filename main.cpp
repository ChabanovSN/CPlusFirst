#include "groupstudent.h"
int main(){
    int count =0;
    setlocale(LC_ALL,"RUS");
    cout<<"Создание группы:"<<endl;
    GroupStudent gp;// = new GroupStudent();
     cout<<"Количесвто студентов:"<<endl;cin>>count;

     while(count--)gp.addStudent();

     cout<<gp;

     gp.printGroup();
    return 0;
}
