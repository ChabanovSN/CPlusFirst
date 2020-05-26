#ifndef LISTNODE_H
#define LISTNODE_H

// Опережающее объявление класса List необходимо, чтобы List
 template< typename NODETYPE >
 class List;

 template< typename NODETYPE >
 class ListNode
 {
 friend class List< NODETYPE >; // сделать List другом

 public:
 ListNode( const NODETYPE & ); // конструктор
 NODETYPE getData() const; // возвратить данные в узле
 private:
 NODETYPE data; // данные

 ListNode< NODETYPE > *nextPtr; // следующий узел в списке
 }; // конец класса ListNode
 // конструктор
 template< typename NODETYPE >
 ListNode< NODETYPE >::ListNode( const NODETYPE &info )
 : data( info ), nextPtr( 0 )
 {
 // пустое тело
 } // конец конструктора ListNode
 // возвратить копию данных в узле
 template< typename NODETYPE >
 NODETYPE ListNode< NODETYPE >::getData() const
 {
 return data;
 } // конец функции getData

#endif // LISTNODE_H

