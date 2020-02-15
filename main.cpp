

#include <iostream>
using namespace std;
void task33_1();// первая задача
void task34_1();// вторая задача
void fillArr(int *, int, int, int);
void print(int *, int);
void sw(int *,int *);
int main() {
   task33_1();
   task34_1();
    return 0;
}
//33.1 Дан массив целых чисел. Воспользовавшись указателями,
//поменяйте местами элементы массива с четными и нечетными индексами
//(т.е. те элементы массива, которые стоят на четных местах,
// поменяйте с элементами, которые стоят на нечетных местах).
void task33_1(){
    cout<<"Task 33.1"<<endl;
    const int N = 10; int arr[N];
   fillArr(arr,N, 20, 20); print(arr,N);
   for(int* pt =arr; pt<arr +N; pt +=2)
       sw(pt, pt+1);
    print(arr,N);
}
void sw(int * a,int * b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


//34.1 Создать динамический массив, заполнить его случайными (-20 до 20) значениями, после этого:
//Разложить положительные и отрицательные элементы по разным массивам, а исходный массив удалить.
void task34_1(){
     cout<<"Task 34.1"<<endl;
     const int N = 20; int *arr = new int[N];
     fillArr(arr,N, 20, 41); print(arr,N);
     int posNum =0, negNum = 0;
      for(int* pt =arr; pt<arr +N; pt++)
          if(*pt >= 0) ++posNum; // считаем положит. числа
          else ++negNum;         //  считаем отриц. числа

         int *arrPos = new int[posNum]; // динамич. массив для положит. чисел
         int *arrNeg = new int[negNum]; //динамич. массив для отриц. чисел
         posNum = negNum = 0;          // обнуляем для использования в качестве индексов
         for(int* pt =arr; pt<arr +N; pt++)
             if(*pt >= 0) arrPos[posNum++] = *pt; 
             else arrNeg[negNum++] = *pt;       

         if(posNum){// проверка если массив оказался пустым
             cout<<" Positive array"<<endl;
             print(arrPos,posNum);
         }
         if(negNum){
               cout<<" Negative array"<<endl;
             print(arrNeg,negNum);
         }

         delete [] arr;
//         delete [] arrPos;   // ну этого в задании небыло....
//         delete [] arrNeg;

}


void fillArr(int *arr, int size, int from, int to){
    srand(time(NULL));
    for(int i =0; i<size;i++)
           *(arr+i)=from - rand()% to;
}
void print(int *arr, int size){
     for(int i =0; i<size;i++)
          cout<< *(arr+i)<<" ";
      cout<<endl;
}
