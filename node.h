#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;
// {Pass date; list *next})
// операжающее объявление класса Tree
template< typename NODETYPE >
class ListNode;

 template< typename NODETYPE >
 class Node{
     friend class ListNode< NODETYPE >;
     public:
     // конструктор
     Node( const NODETYPE &d ):data(d){}
     // воэратить копию данных узла
     NODETYPE getData() const
     {
     return data;
     }
     private:
     Node< NODETYPE > *next=0;
     NODETYPE data;

};
#endif // NODE_H
