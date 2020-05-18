#ifndef LISTNODE_H
#define LISTNODE_H

// Опережающее объявление класса List необходимо, чтобы List
// можно было использовать в объявлении дружественности в строке 13
 template< typename NODETYPE >
 class List;

 template< typename NODETYPE >
 class ListNode
 {
 friend class List< NODETYPE >; // сделать List другом

 public:
 ListNode( const NODETYPE & ); // конструктор
 ListNode(const NODETYPE &,const int pri = 0);
 NODETYPE getData() const; // возвратить данные в узле
 int getPrior() const;// возврат приоретета
 private:
 NODETYPE data; // данные
 int      prioir=0;

 ListNode< NODETYPE > *nextPtr ; // следующий узел в списке
 }; // конец класса ListNode
 // конструктор
 template< typename NODETYPE >
 ListNode< NODETYPE >::ListNode( const NODETYPE &info )
 : data( info ), nextPtr( 0 )
 {
 // пустое тело
 } // конец конструктора ListNode
 template< typename NODETYPE >
 ListNode< NODETYPE >::ListNode( const NODETYPE &info,const int pri)
 : data( info ), nextPtr( 0 ),prioir(pri)
 {
 // пустое тело
 } // конец конструктора ListNode


 // возвратить копию данных в узле
 template< typename NODETYPE >
 NODETYPE ListNode< NODETYPE >::getData() const
 {
 return data;
 } // конец функции getData
 template< typename NODETYPE >
 int ListNode< NODETYPE >::getPrior() const
 {
     return prioir;
 }
#endif // LISTNODE_H

