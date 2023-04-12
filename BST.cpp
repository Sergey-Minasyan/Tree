#include "BST.hpp"

template<typename T>
BST<T>::BST()
    :root(nullptr)
{}

template<typename T>
void BST<T>::inorder(void (*visit)(T&), Node<T>* treeptr)
{
    if (treeptr !- nullptr)
    {
        inorder(visit, treeptr->getLeftChild());
        T data = treeptr->getData();
        visit(data);
        inorder(visit, treeptr->getRightChild());
    }
}

template<typename T>
void BST<T>::preorder(void (*visit)(T&), Node<T>* treeptr)
{
    T data = treeptr->getData();
    visit(data);
    preorder(visit, treeptr->getLeftChild());
    preorder(visit, treeptr->getRightChild());
}

template<typename T>
void BST<T>::postorder(void (*visit)(T&), Node<T>* treeptr)
{
    preorder(visit, treeptr->getLeftChild());
    preorder(visit, treeptr->getRightChild());
    T data = treeptr->getData();
    visit(data);
}

template<typename T>
void BST<T>::inorder(void (*visit)(T&))
{
    inorder(visit, root);
}

template<typename T>
void BST<T>::postorder(void (*visit)(T&))
{
    postorder(visit, root);
}

template<typename T>
void BST<T>::preorder(void (*visit)(T&))
{
    preorder(visit, root);
}

template<typename T>
Node<T>* BST<T>::search(const T data, Node<T>* treeptr)
{
    if (treeptr == nullptr || treeptr->data == data)
        return treeptr;
    if (data < treeptr->data)
        return search(data, treeptr->getLeftChild());
    else
        return search(data, treeptr->getRightChild());
}

template<typename T>
Node<T>* BST<T>::search(const T data)
{
    search(data, root);
}

template<typename T>
Node<T>* BST<T>::min(Node<T>* treeptr)
{
    while (treeptr->getLeftChild() != nullptr)
        treeptr = treeptr->left;
    return treeptr;
}

template<typename T>
Node<T>* BST<T>::max(Node<T>* treeptr)
{
    while (treeptr->getRightChild() != nullptr)
        treeptr = treeptr->right;
    return treeptr;
}

template<typename T>
Node<T>* BST<T>::min()
{
    min(root);
}

template<typename T>
Node<T>* BST<T>::max()
{
    max(root);
}

template<typename T>
void BST<T>::insert(Node<T>* treeptr, Node<T>* ins)
{
    if (treeptr == nullptr)
    {
        treeptr = ins;
        return;
    }
    while (treeptr != nullptr)
    {
        if (ins->getData() < treeptr->getData())
            treeptr = treeptr->left;
        else
            treeptr = treeptr->right;
    }
    if (ins->getData() < treeptr->getData())
        treeptr->setLeftChild(ins);
    else
        treeptr->setRightChild(ins);
}

template<typename T>
void BST<T>::insert(Node<T>* a)
{
    insert(root, a);
}