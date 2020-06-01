#ifndef TREENODE_H
#define TREENODE_H
// операжающее объявление класса Tree
template< typename NODETYPE > class Tree;

// определение шаблона класса TreeNode
 template< typename NODETYPE >
 class TreeNode
 {
 friend class Tree< NODETYPE >;
 public:
 // конструктор
 TreeNode( const NODETYPE &d )
 : leftPtr(0), // указатель на левое поддерево
 data( d ), // данные узла
 rightPtr( 0 ) // указатель на правое поддерево
 {
 // пустое тело
 } // конец конструктора TreeNode

 // воэратить копию данных узла
 NODETYPE getData() const
 {
 return data;
 } // конец функции getData
 private:
 TreeNode< NODETYPE > *leftPtr; // указатель на левое поддерево
 NODETYPE data;
 TreeNode< NODETYPE > *rightPtr; // указатель на правое поддерево
 }; // конец класса TreeNode
#endif // TREENODE_H
