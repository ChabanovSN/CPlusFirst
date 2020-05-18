#ifndef QUEUE_H
#define QUEUE_H
#include "List.h" // определение класса List

 template< typename STACKTYPE >
 class QueuePrior : private List< STACKTYPE >
 {
 public:
 // push вызывает функцию insertAtFront класса List
 void push( const STACKTYPE &data, const int prior = 1 )
 {

 List< STACKTYPE >::insertBetween(data,prior );
 } // конец функции push
STACKTYPE front(){
    return  List< STACKTYPE >::front();
}
 // pop вызывает функцию removeFromFront класса List
 bool pop()
 {
 return List< STACKTYPE >::removeFromFront();
 } // конец функции pop

 // isStackEmpty вызывает функцию isEmpty класса List
 bool isEmpty() const
 {
 return List< STACKTYPE >::isEmpty() ;
 } // конец функции isStackEmpty

 // printStack вызывает функцию print класса List
 void print() const
 {
 List< STACKTYPE >::print ();
 } // конец функции print
 int size() const{
     return List< STACKTYPE >::size();
 }

 }; // конец класса QueuePrior


#endif // QUEUE_H
