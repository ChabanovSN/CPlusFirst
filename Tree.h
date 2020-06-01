#ifndef TREE_H
#define TREE_H
#include <iostream>
//#include <new>
#include "TreeNode.h"
using namespace std;

// определение шаблона класса Tree
template< typename NODETYPE > class Tree
{
public:
    Tree(); // конструктор
    void insertNode( const NODETYPE & );
    void preOrderTraversal() const;
    void inOrderTraversal() const;
    void postOrderTraversal() const;
    bool findNode( const NODETYPE & );
    NODETYPE getSum( NODETYPE = 0) const;
    NODETYPE getMax() const;
private:
    TreeNode< NODETYPE > *rootPtr;

    // сервисные функции
    NODETYPE getMaxHelper( TreeNode< NODETYPE > * ) const;
    NODETYPE getSumHelper( TreeNode< NODETYPE > * , NODETYPE = 0) const;
    void insertNodeHelper( TreeNode< NODETYPE >**, const NODETYPE& );
    bool findNodeHelper( TreeNode< NODETYPE >**, const NODETYPE& );
    void preOrderHelper( TreeNode< NODETYPE > * ) const;
    void inOrderHelper( TreeNode< NODETYPE > * ) const;
    void postOrderHelper( TreeNode< NODETYPE > * ) const;
}; // конец класса Tree

// конструктор
template< typename NODETYPE >
Tree< NODETYPE >::Tree()
{
    rootPtr = 0; // указывает, что дерево изначально пусто
} // конец конструктора Tree

// нахождение максимума
template< typename NODETYPE>
NODETYPE Tree<NODETYPE>::getMax() const{
    return getMaxHelper(rootPtr);
}
//служебная функия нахождения максимума
template< typename NODETYPE>
NODETYPE Tree<NODETYPE>::getMaxHelper(TreeNode< NODETYPE > * ptr)const{
   if(ptr){
    if( ptr ->rightPtr !=0)
        return getMaxHelper(ptr ->rightPtr);
    else
        return   ptr->data;
   }
   else return NULL;
}

// функция поиска суммы элементов
template< typename NODETYPE>
NODETYPE Tree<NODETYPE>::getSum( NODETYPE n) const{
    return getSumHelper( rootPtr,n );
}
// служебная функция поиска элементов
template< typename NODETYPE>
NODETYPE Tree<NODETYPE>::getSumHelper(TreeNode< NODETYPE > * ptr,NODETYPE sum) const{

  if ( ptr != 0 ){
    return ptr ->data
            + getSumHelper( ptr ->leftPtr)
            + getSumHelper(ptr ->rightPtr);
  }
    else return sum;
  }
//функция поиска
template< typename NODETYPE>
bool Tree<NODETYPE>::findNode(const NODETYPE &value){
    return findNodeHelper(&rootPtr, value);
}
template< typename NODETYPE >
// служебная функция поиска
bool Tree<NODETYPE>::findNodeHelper(
        TreeNode< NODETYPE >**ptr, const NODETYPE& value){
    if(*ptr){
        if(( *ptr )->data == value)
            return true;
        else{
            if(( *ptr )->data > value)
                findNodeHelper(&( ( *ptr )->leftPtr ), value );
            else
                findNodeHelper(&( ( *ptr )->rightPtr ), value );
        }
    }else{
        cout<<"WTH"<<endl;
        return false;
    }
}
// вставить узел в дерево
template< typename NODETYPE>
void Tree< NODETYPE >::insertNode( const NODETYPE &value )
{
    insertNodeHelper( &rootPtr, value );
} // конец функции insertNode

// сервисная функция, вызываемая insertNode; принимает указатель
//на указатель, чтобы функция могла изменять значение указателя
template< typename NODETYPE >
void Tree< NODETYPE >::insertNodeHelper(
        TreeNode< NODETYPE > **ptr, const NODETYPE &value )
{
    // поддерево пусто; создать новый TreeNode, содержащий value
    if ( *ptr == 0 )
        *ptr = new TreeNode< NODETYPE >( value );
    else // поддерево не пусто
    {
        // вставляемые данные меньше, чем данные в текущем узле
        if ( value < ( *ptr )->data )
            insertNodeHelper( &( ( *ptr )->leftPtr ), value );
        else

            insertNodeHelper( &( ( *ptr )->rightPtr ), value );


    } // конец else
} // конец функции insertNodeHelper

// начать обход дерева с опережающей выборкой
template< typename NODETYPE >
void Tree< NODETYPE >::preOrderTraversal() const
{
    preOrderHelper( rootPtr );
} // конец функции preOrderTraversal

// сервисная функция для обхода дерева с опережающей выборкой
template< typename NODETYPE >
void Tree<NODETYPE>::preOrderHelper (TreeNode<NODETYPE> *ptr) const
{
    if ( ptr != 0 )
    {
        cout << ptr->data << ' '; // обработать узел
        preOrderHelper( ptr->leftPtr );

        preOrderHelper( ptr->rightPtr ); // обойти правое поддерево
    } // конец if
} // конец функции preOrderHelper

// начать обход дерева с порядковой выборкой
template< typename NODETYPE >
void Tree< NODETYPE >::inOrderTraversal() const
{
    inOrderHelper( rootPtr );
} // конец функции inOrderTraversal

// сервисная функция для обхода дерева с порядковой выборкой
template< typename NODETYPE >
void Tree<NODETYPE>:: inOrderHelper ( TreeNode<NODETYPE> *ptr ) const
{
    if ( ptr != 0 )
    { //cout<<endl;// обойти левое поддерево
        inOrderHelper( ptr->leftPtr ); // обойти левое поддерево
        cout << ptr->data << ' '; // обработать узел
        inOrderHelper( ptr->rightPtr ); // обойти правое поддерево
        //  cout<<endl;// обойти левое поддерево
    } // конец if
} // конец функции inOrderHelper

// начать обход дерева с отложенной выборкой
template< typename NODETYPE >
void Tree< NODETYPE >::postOrderTraversal() const
{
    postOrderHelper( rootPtr );
} // конец функции postOrderTraversal

// сервисная функция для обхода дерева с отложенной выборкой
template< typename NODETYPE >
void Tree< NODETYPE >::postOrderHelper( TreeNode< NODETYPE > *ptr ) const
{
    if ( ptr != 0 )
    {// cout<<' ';
        postOrderHelper( ptr->leftPtr ); // обойти левое поддерево
        // cout<<' ';
        postOrderHelper( ptr->rightPtr ); // обойти правое поддерево
        cout << ptr->data << ' '; // обработать узел
        //cout<<endl;
    } // конец if
} // конец функции postOrderHelper

#endif // TREE_H
