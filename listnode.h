#ifndef LISTNODE_H
#define LISTNODE_H
#include<node.h>
#include<pass.h>

template< typename NODETYPE >
class ListNode
{
public:
    ListNode(){}
    ~ListNode();
    void insertNode( const NODETYPE & );
    void print() const;
    NODETYPE findNode( const NODETYPE & );
    NODETYPE deleteNode( const NODETYPE & );
    NODETYPE popNode();
    bool isEmpty() const;
    int size() const;
    void clear();
private:
    Node< NODETYPE > *firstPtr=0; // указатель на первый узел
    Node< NODETYPE > *lastPtr=0; // указатель на последний узел
    int lenght = 0;
};

// список пуст?
template< typename NODETYPE >
bool ListNode< NODETYPE >::isEmpty() const
{
    return firstPtr == 0;
} // конец ф

template< typename NODETYPE >
NODETYPE ListNode< NODETYPE >::popNode(){
     Pass p;
    if ( isEmpty() ) // список пуст
    {
        cout<< "The list is empty\n\n";

        return   p;
    } // конец if
    p = firstPtr->data;
     if(firstPtr->next !=0 ){
         firstPtr=firstPtr->next;
         lenght--;
     }
//     if(firstPtr==lastPtr){
//         firstPtr=lastPtr = 0;
//         lenght = 0;
//     }
    return  p;
}
template< typename NODETYPE >
NODETYPE ListNode< NODETYPE >::deleteNode(const NODETYPE &value){
    if ( isEmpty() ) // список пуст
    {
        cout<< "The list is empty\n\n";
        Pass p;
        return   p;
    } // конец if

    Node< NODETYPE > *currentPtr= firstPtr ,  *prevPtr= firstPtr;
    while ( currentPtr != 0 ) // получить данные элемента
    {  Pass p = currentPtr->data;

       if(p.getPass()==value.getPass() && p.getSite() == value.getSite()){
           if(currentPtr == firstPtr){
               firstPtr = firstPtr->next;
           }
           else if(currentPtr != lastPtr){

               prevPtr->next = currentPtr->next;
           }else{
               Pass p = prevPtr->data;
               cout<<"fff "<<p.getSite()<<endl;
              lastPtr = prevPtr;
              prevPtr->next=0;
           }
           lenght--;
           return p;
       }
       if(prevPtr != currentPtr)prevPtr = prevPtr->next; //отставание на 1 указатель
        currentPtr = currentPtr->next;
    } // конец while
    Pass p;
    return   p;
}

template< typename NODETYPE >
NODETYPE ListNode< NODETYPE >::findNode(const NODETYPE &value){
    if ( isEmpty() ) // список пуст
    {
        cout<< "The list is empty\n\n";
        Pass p;
        return   p;
    } // конец if

    Node< NODETYPE > *currentPtr = firstPtr;
    while ( currentPtr != 0 ) // получить данные элемента
    {  Pass p = currentPtr->data;
       if(p.getPass()==value.getPass() && p.getSite() == value.getSite())
           return p;
        currentPtr = currentPtr->next;
    } // конец while
    Pass p;
    return   p;
}

template< typename NODETYPE >
void ListNode< NODETYPE >::insertNode(const NODETYPE &value){
    Node< NODETYPE > *newPtr = new Node< NODETYPE >( value );; // новый узел
    lenght++;
    if ( isEmpty() ) // список пуст
        firstPtr = lastPtr = newPtr; // список имеет всего один узел
    else // список не пуст
    {
        lastPtr->next = newPtr; // обновить бывший последний узел
        lastPtr = newPtr; // новый последний узел
    } // конец else
}
// сервисная функция, вызываемая insertNode; принимает указатель

template< typename NODETYPE >
void ListNode< NODETYPE >::print() const{

    if ( isEmpty() ) // список пуст
    {
        cout<< "The list is empty\n\n";
        return;
    } // конец if

    Node< NODETYPE > *currentPtr = firstPtr;

    cout<<right;
    cout.width(10);
    cout << "Site: ";

    while ( currentPtr != 0 ) // получить данные элемента
    {  Pass p = currentPtr->data;
        cout.width(10);
        cout<< p.getSite() << " | ";
        currentPtr = currentPtr->next;
    } // конец while

    cout <<endl;
    cout.width(10);
    currentPtr = firstPtr;
    std::cout<<std::right;
    cout << "Password: ";

    while ( currentPtr != 0 ) // получить данные элемента
    {  Pass p = currentPtr->data;

        cout.width(10);
        cout << p.getPass() << " | ";
        currentPtr = currentPtr->next;
    } // конец while

    cout <<endl;
}
template< typename NODETYPE >
ListNode< NODETYPE >::~ListNode()
{
    if ( ! isEmpty() ) // список не пуст
    {

        Node< NODETYPE > *currentPtr = firstPtr;
        Node< NODETYPE > *tempPtr;

        while ( currentPtr != 0 ) // удалить оставшиеся узлы
        {
            tempPtr = currentPtr;
            currentPtr = currentPtr->next;
            delete tempPtr;
        } // конец while
    } // конец if

} // конец деструкора List

template< typename NODETYPE >
int ListNode<NODETYPE>::size() const{
    return lenght;
}
template< typename NODETYPE >
void ListNode<NODETYPE>::clear(){
    if ( ! isEmpty() ) // список не пуст
    {

        Node< NODETYPE > *currentPtr = firstPtr;
        Node< NODETYPE > *tempPtr;

        while ( currentPtr != 0 ) // удалить оставшиеся узлы
        {
            tempPtr = currentPtr;
            currentPtr = currentPtr->next;
            delete tempPtr;
        } // конец while
        lenght=0;
        firstPtr=lastPtr = 0;
    } // конец if

}
#endif // LISTNODE_H
