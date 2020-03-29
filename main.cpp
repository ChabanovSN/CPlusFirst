#include<human.h>
int main(){

    setlocale(LC_ALL,"RUS");
    Man *man = new Man();
    inputData(man);
    outputData(*man);
    return 0;
}
