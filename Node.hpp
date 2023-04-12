#pragma once
template<typename T>
class Node
{
public:
    Node();
    Node(const T& value);
    Node(const T& value, Node<T>* lp, Node<T>* rp);

    void setData(const T& value);
    T getData() const;
    bool isLeaf() const;
    Node<T>* getLeftChild() const;
    Node<T>* getRightChild() const;
    void setLeftChild(Node<T>* lp);
    void setRightChild(Node<T>* rp);
private:
    T data;
    Node<T>* left;
    Node<T>* right;
};

template<typename T>
Node<T>::Node()
    :data{ 0 }, left(nullptr), right(nullptr)
{}


template<typename T>
Node<T>::Node(const T& value)
    : data{ value }, left(nullptr), right(nullptr)
{}

template<typename T>
Node<T>::Node(const T& value, Node<T>* lp, Node<T>* rp)
    : data{ value }, left{ lp }, right{ rp }
{}

template<typename T>
void Node<T>::setData(const T& value)
{
    data = value;
}

template<typename T>
T Node<T>::getData() const
{
    return this->data;
}

template<typename T>
bool Node<T>::isLeaf() const
{
    if (this->left == nullptr && this->right == nullptr)
        return true;
    return false;
}

template<typename T>
Node<T>* Node<T>::getLeftChild() const
{
    return this->left;
}

template<typename T>
Node<T>* Node<T>::getRightChild() const
{
    return this->right;
}

template<typename T>
void Node<T>::setLeftChild(Node<T>* lp)
{
    this->left = lp;
}

template<typename T>
void Node<T>::setRightChild(Node<T>* rp)
{
    this->right = rp;
}