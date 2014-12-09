//  bstree.h
//  BSTree class header used for bstree_test.cpp
//  CS311 HW6
//  Lonny Strunk, Samuel George
//  12/6/14
//

#ifndef bstree_h
#define bstree_h

#include <cstdlib>
#include <algorithm>

// struct LLNode (created by Prof. Hartman for CS 331, Assignment #5)
// Linked List node, with client-specified value type
// Invariants:
//     Either next_ is NULL, or next_ points to an LLNode,
//      allocated with new, owned by *this.
// This struct, and it's member functions, are exception-neutral
template <typename ValueType>
struct Node {
    ValueType _key;  // Data for this node
    Node * _right;   // Ptr to right node, or NULL if none
    Node * _left;   // Ptr to left node, or NULL if none
    
    // 1- & 2-param ctor
    // Requirement on Types: copy constructor
    // Pre:
    //     theNext, if passed, is either NULL,
    //      or else it points to an LLNode, allocated with new,
    //      with ownership transferred to *this.
    // Post:
    //     data_ == theData.
    //     If next_ passed, then next_ == theNext.
    //      otherwise, next_ is NULL.
    //	Strong exception guarantee
    explicit Node(const ValueType & theKey,Node * theNext = NULL, Node * theNext2 = NULL):_key(theKey), _right(theNext), _left(theNext2)
    {}
    
    // dctor
    // Requirement on Types: none
    // Pre: None.
    // Post: None. (next_ delete'd)
    // No-Throw exception guarantee
    ~Node()
    { delete _right; delete _left;}
    
    Node<ValueType> * copy(Node<ValueType> * r);     //copies one node to *this;

};


template <typename ValueType>
class BSTree
{
public:
    typedef std::size_t size_type;
    
    BSTree();
    BSTree(const BSTree<ValueType> & other);
    BSTree & operator=(BSTree<ValueType> rhs);
    ~BSTree();
    
    size_type size() const;
    bool empty() const;
    void clear();
    bool retrieve(ValueType key) const;
    bool insert(ValueType key);
    template <typename OutputIter>
    void preorderTraverse(OutputIter iter) const;
    template <typename OutputIter>
    void inorderTraverse(OutputIter iter) const;
    template <typename OutputIter>
    void postorderTraverse(OutputIter iter) const;
    
    Node<ValueType> * & find(ValueType key) const; //used for retrieval and insert functions
    
private:
    Node<ValueType> * _root;
    size_type _size;
};

template <typename T>
BSTree<T>::BSTree()
{
    _root = nullptr;
    _size = 0;
}

template <typename T>
BSTree<T>::BSTree(const BSTree<T> & other)
{
    _size = other._size;
    _root->copy(other._root);
}

template <typename T>
BSTree<T> & BSTree<T>::operator=(BSTree<T> rhs)
{
    std::swap(_size, rhs._size);
    std::swap(_root, rhs._root);
    return *this;
}

template <typename T>
BSTree<T>::~BSTree()
{
    //delete _root;
}

template <typename T>
std::size_t BSTree<T>::size() const
{
    return _size;
}

template <typename T>
bool BSTree<T>::empty() const
{
    if (_size == 0) {
        return true;
    }
    return false;
}

template <typename T>
void BSTree<T>::clear()
{
    BSTree<T> temp;
    std::swap(_size, temp._size);
    std::swap(_root, temp._root);
}

template <typename T>
bool BSTree<T>::retrieve(T key) const
{
    if(find(key) == nullptr)
    {
        return false;
    }
    else
        return true;
}

template <typename T>
bool BSTree<T>::insert(T key)
{
    return true;
}
template <typename T>
template <typename OutputIter>
void BSTree<T>::preorderTraverse(OutputIter iter) const
{
    if(_root == nullptr)
        return;
    *iter++ = _root->_key;
    preorderTraverse(iter);
    preorderTraverse(iter);
}

template <typename T>
template <typename OutputIter>
void BSTree<T>::inorderTraverse(OutputIter iter) const
{
    if(_root == nullptr)
        return;
    inorderTraverse(iter);
    *iter++ - _root->_key;
    inorderTraverse(iter);
}

template <typename T>
template <typename OutputIter>
void BSTree<T>::postorderTraverse(OutputIter iter) const
{
    if(_root == nullptr)
        return;
    postorderTraverse(iter);
    *iter++ - _root->_key;
    postorderTraverse(iter);
}

template <typename T>
Node<T> * Node<T>::copy(Node<T> * r)
{
    if (r != nullptr) {
        Node<T> * newNode = new Node<T>(r->_key);
        newNode->_right = copy(r->_right);
        newNode->_left = copy(r->_left);
        return newNode;
    }
    else {
        return nullptr;
    }
}

template <typename T>
Node<T> * & BSTree<T>::find(T key) const
{
    Node<T> * walker = _root;
    while (walker != nullptr)
    {
        if (walker->_key == key) {
            return walker;
        }
        if (key < walker->_key)
        {
            walker = walker->_left;
        }
        else // (key > walker->_key)
        {
            walker = walker->_right;
        }
    }
    return walker;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}







#endif
