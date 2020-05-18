#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "ListNode.h" // определение класса ListNode
using std::cout;
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
    void insertAtFront( const NODETYPE &, const int pri = 0);
    void insertAtBack( const NODETYPE &, const int pri = 0);
    void insertBetween( const NODETYPE &, const int pri = 0);
    bool removeFromFront();
    bool removeFromBack();
    NODETYPE front() const;
    NODETYPE back() const;
    bool isEmpty() const;
    void print() const;
    int size() const;
private:
    ListNode< NODETYPE > *firstPtr; // указатель на первый узел
    ListNode< NODETYPE > *lastPtr; // указатель на последний узел
    int lenght = 0; // размер
    // сервисная функция для выделения памяти нового узла
    ListNode< NODETYPE > *getNewNode( const NODETYPE &, const int pri = 0 );
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
void List< NODETYPE >::insertBetween( const NODETYPE &value, const int pri){


    if ( isEmpty() ) insertAtFront(value,pri);
    else if(lenght==1){
        if(firstPtr->prioir < pri)
            insertAtBack(value,pri);
        else
            insertAtFront(value,pri);
    }
    else
    {

        ListNode< NODETYPE > *newPtr = getNewNode( value,pri ); // новый узел
        lenght++;
        ListNode< NODETYPE > *currentPtr1 = firstPtr;
        ListNode< NODETYPE > *currentPtr2 = firstPtr;

        while ( currentPtr2->nextPtr != 0 ){
            currentPtr2 = currentPtr2->nextPtr; // перейти к следующему
            if(newPtr->prioir < currentPtr2->prioir){
                currentPtr1->nextPtr = newPtr;
                newPtr->nextPtr=currentPtr2;
                return;
            }
            if(currentPtr2 !=lastPtr)
                currentPtr1 = currentPtr2;
        }

        if(lastPtr->prioir < pri){
            lenght--;
            insertAtBack(value,pri);
        }
        else if(currentPtr1 != firstPtr){

            currentPtr1->nextPtr = newPtr;
            newPtr->nextPtr      = lastPtr;
        }


    }
}

template< typename NODETYPE >
void List< NODETYPE >::insertAtFront( const NODETYPE &value, const int pri)
{
    ListNode< NODETYPE > *newPtr = getNewNode( value,pri ); // новый узел
    lenght++;
    if ( isEmpty() ) // список пуст
        firstPtr = lastPtr = newPtr; // список имеет всего один узел
    else // List is not empty
    {
        newPtr->nextPtr = firstPtr; // новый указывает на предыдущий
        firstPtr = newPtr; // направить firstPtr на новый узел
    } // конец else
} // конец функции insertAtFront

// вставить узел в начало списка
template< typename NODETYPE >
void List< NODETYPE >::insertAtBack( const NODETYPE &value , const int pri )
{
    ListNode< NODETYPE > *newPtr = getNewNode( value,pri ); // новый узел
    lenght++;
    if ( isEmpty() ) // список пуст
        firstPtr = lastPtr = newPtr; // список имеет всего один узел
    else // список не пуст
    {
        lastPtr->nextPtr = newPtr; // обновить бывший последний узел
        lastPtr = newPtr; // новый последний узел
    } // конец else
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
    return firstPtr == 0;
} // конец функции isEmpty

// возвратить указатель на вновь выделенный узел
template< typename NODETYPE >
ListNode< NODETYPE > *List< NODETYPE >::getNewNode(const NODETYPE &value, const int pri)
{
    return new ListNode< NODETYPE >( value,pri );
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

    cout << "The list is:\n ";

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
