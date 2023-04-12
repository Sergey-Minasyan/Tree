#pragma once
#include "Node.hpp"
#include <iostream>

template<typename T>
class BST
{
private:
    void    postorder(void (*visit)(T), Node<T>* treeptr);
    void    preorder(void (*visit)(T), Node<T>* treeptr);
    void    inorder(void (*visit)(T), Node<T>* treeptr);
    Node<T>* search(const T data, Node<T>* treeptr);
    Node<T>* min(Node<T>* treeptr);
    Node<T>* max(Node<T>* treeptr);
    Node<T>* insert(Node<T>* treeptr, T value);
    Node<T>* succesoor(Node<T>* treeptr);
public:
    T getRootData();
    BST();
    void postorder(void (*visit)(T));
    void preorder(void (*visit)(T));
    void inorder(void (*visit)(T));
    Node<T>* search(const T data);
    Node<T>* min();
    Node<T>* max();
    void insert(T value);


private:
    Node<T>* root;
};

template<typename T>
T BST<T>::getRootData()
{
    return root->getData();
}

template<typename T>
BST<T>::BST()
    :root(nullptr)
{}

template<typename T>
void BST<T>::inorder(void (*visit)(T), Node<T>* treeptr)
{
    if (treeptr == nullptr)
        return;
    inorder(visit, treeptr->getLeftChild());
    T data = treeptr->getData();
    visit(data);
    inorder(visit, treeptr->getRightChild());
}

template<typename T>
void BST<T>::preorder(void (*visit)(T), Node<T>* treeptr)
{
    if (treeptr == nullptr)
        return;
    T data = treeptr->getData();
    std::cout << data << ' ';
    preorder(visit, treeptr->getLeftChild());
    preorder(visit, treeptr->getRightChild());
}

template<typename T>
void BST<T>::postorder(void (*visit)(T), Node<T>* treeptr)
{
    if (treeptr == nullptr)
        return;
    preorder(visit, treeptr->getLeftChild());
    preorder(visit, treeptr->getRightChild());
    T data = treeptr->getData();
    std::cout << data << ' ';
}

template<typename T>
void BST<T>::inorder(void (*visit)(T))
{
    inorder(visit, root);
}

template<typename T>
void BST<T>::postorder(void (*visit)(T))
{
    postorder(visit, root);
}

template<typename T>
void BST<T>::preorder(void (*visit)(T))
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
        treeptr = treeptr->getLeftChild();
    return treeptr;
}

template<typename T>
Node<T>* BST<T>::max(Node<T>* treeptr)
{
    while (treeptr->getRightChild() != nullptr)
        treeptr = treeptr->getRightChild();
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
Node<T>* BST<T>::insert(Node<T>* treeptr, T value)
{
    if (treeptr == nullptr)
    {
        treeptr = new Node<T>(value);
    }
    else
    {
        if (treeptr->getData() > value)
            treeptr->setLeftChild(insert(treeptr->getLeftChild(), value));
        else
            treeptr->setRightChild(insert(treeptr->getRightChild(), value));
    }
    return treeptr;
}

template<typename T>
void BST<T>::insert(T value)
{
    root = insert(root, value);
}

template<typename T>
Node<T>* BST<T>::succesoor(Node<T>* treeptr)
{
    if (treeptr->getRightChild() != nullptr)
        return min(treeptr->getRightChild());

}