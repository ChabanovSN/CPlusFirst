#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "ListNode.h" // определение класса ListNode
using namespace std;
template< typename NODETYPE >
class List
{
public:
    // конструктор по умолчанию
    // template< typename NODETYPE >
    List()
        : firstPtr( 0 ), lastPtr( 0 )
    {
        // пустое тело
    } // конец конструктора List

    ~List(); // деструктор
    void insertAtFront( const NODETYPE & );
    void insertAtBack( const NODETYPE & );
    bool removeFromFront();
    bool removeFromBack();
    NODETYPE front() const;
    NODETYPE back() const;
    bool isEmpty() const;
    void print() const;
    int size() const;
    void setCircle(int l){
        circleSize =l;
    }
private:
    ListNode< NODETYPE > *firstPtr; // указатель на первый узел
    ListNode< NODETYPE > *lastPtr; // указатель на последний узел
    int lenght = 0; // размер
    int circleSize = 0;

    // сервисная функция для выделения памяти нового узла
    ListNode< NODETYPE > *getNewNode( const NODETYPE & );
}; // конец класса List
// деструктор
template< typename NODETYPE >
List< NODETYPE >::~List()
{
    if ( ! isEmpty() ) // список не пуст
    {

        ListNode< NODETYPE > *currentPtr = firstPtr;
        ListNode< NODETYPE > *tempPtr;

        while ( currentPtr != 0 ) // удалить оставшиеся узлы
        {
            tempPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
            delete tempPtr;
        } // конец while
    } // конец if

} // конец деструкора List
// вставить узел в начало списка
template< typename NODETYPE >
void List< NODETYPE >::insertAtFront( const NODETYPE &value )
{
    ListNode< NODETYPE > *newPtr = getNewNode( value ); // новый узел
    lenght++;
    if ( isEmpty() ) // список пуст
        firstPtr = lastPtr = newPtr; // список имеет всего один узел
    else // List is not empty
    {
        firstPtr=lastPtr;
        firstPtr->data=value;

    } // конец else

}// конец функции insertAtFront

// вставить узел в начало списка
template< typename NODETYPE >
void List< NODETYPE >::insertAtBack( const NODETYPE &value )
{
    ListNode< NODETYPE > *newPtr = getNewNode( value ); // новый узел

    if ( isEmpty() ){ // список пуст
        firstPtr = lastPtr = newPtr;
        lenght++;
    }// список имеет всего один узел
    else // список не пуст
    {  if(circleSize)
              if(lenght >=circleSize){
            ListNode< NODETYPE > *tempPtr = firstPtr;
            firstPtr = tempPtr->nextPtr;
            lastPtr->nextPtr = newPtr; // обновить бывший последний узел
             newPtr->data = tempPtr->data;
            lastPtr = newPtr; // новый последний узел
             }else{
                  lenght++;
                  lastPtr->nextPtr = newPtr; // обновить бывший последний узел
                  lastPtr = newPtr; // новый последний узел
        }else {
            lenght++;
            lastPtr->nextPtr = newPtr; // обновить бывший последний узел
            lastPtr = newPtr; // новый последний узел
        }
    }
    // конец else
} // конец функции insertAtBack
template< typename NODETYPE >
NODETYPE List< NODETYPE >::front() const{
    return firstPtr->data;
}
// удалить узел из начала списка
template< typename NODETYPE >
bool List< NODETYPE >::removeFromFront()
{
    if ( isEmpty()) // список пуст
        return false; // неудачное удаление
    else
    {
        ListNode< NODETYPE > *tempPtr = firstPtr; // для удаления
        lenght--;
        if ( firstPtr == lastPtr )
            firstPtr = lastPtr =0; // после удаления узлов нет
        else
            firstPtr = firstPtr->nextPtr; // направить на бывший 2-й узел
        delete tempPtr; // освободить удаленный первый узел
        return true; // удачное удаление
    } // конец else
} // конец функции removeFromFront

template< typename NODETYPE >
NODETYPE List< NODETYPE >::back() const{
    return  lastPtr->data;
}
// удалить узел из конца списка
template< typename NODETYPE >
bool List< NODETYPE >::removeFromBack()
{
    if ( isEmpty()) // список пуст
        return false; // неудачное удаление
    else
    {
        ListNode< NODETYPE > *tempPtr = lastPtr; // для удаления
        lenght--;
        if ( firstPtr == lastPtr ) //в списке один элемент
            firstPtr = lastPtr =0; // после удаления узлов нет
        else
        {
            ListNode< NODETYPE > *currentPtr = firstPtr;

            // locate second-to-last element
            while ( currentPtr->nextPtr != lastPtr )
                currentPtr = currentPtr->nextPtr; // перейти к следующему

            lastPtr = currentPtr; // удалить последний узел
            currentPtr->nextPtr =0; // теперь это последний узел
        } // конец else

        delete tempPtr; // освободить бывший последний узел
        return true; // удачное удаление
    } // конец else
} // конец функции removeFromBack

// список пуст?
template< typename NODETYPE >
bool List< NODETYPE >::isEmpty() const
{
    return lenght == 0;
} // конец функции isEmpty

// возвратить указатель на вновь выделенный узел
template< typename NODETYPE >
ListNode< NODETYPE > *List< NODETYPE >::getNewNode(const NODETYPE &value )
{
    return new ListNode< NODETYPE >( value );
} // конец функции getNewNode

// вывести содержимое списка
template< typename NODETYPE >
void List< NODETYPE >::print() const
{
    if ( isEmpty() ) // список пуст
    {
        cout<< "The list is empty\n\n";
        return;
    } // конец if

    ListNode< NODETYPE > *currentPtr = firstPtr;

    cout << "The list is: ";

    while ( currentPtr != 0 ) // получить данные элемента
    {
        cout << currentPtr->data << ' ' ;
        currentPtr = currentPtr->nextPtr;
    } // конец while

    cout << "\n\n";
} // конец функции print
template< typename NODETYPE >
int List< NODETYPE >::size() const{
    return lenght;
}

#endif // LIST_H
