#pragma once

namespace basics
{

template<typename T>
struct Node
{
    T* Data;
    Node* Next;
};

template<typename T>
struct DNode
{
    T* Data;
    DNode* Next;
    DNode* prev;
};

template<typename T>
class SingleList
{
    SingleList()
    {

    }

    Node* InsertHead(const T& value)
    {

    }

    Node* InsertBack(const T& value)
    {

    }

    Node* Insert(Node* prev, const T& value)
    {

    }

    Node* Search(const T& vlaue)
    {

    }

    Node* Delete(Node* prev)
    {

    }

private:
    Node<T>* head_;
};

template<typename T>
class CycleList
{
    CycleList()
    {

    }

    Node* InsertHead(const T& value)
    {

    }

    Node* InsertBack(const T& value)
    {

    }

    Node* Insert(Node* pre, const T& value)
    {

    }

    Node* Search(const T& vlaue)
    {

    }

    Node* Delete(Node* pre)
    {

    }

private:
    Node<T>* head_;
    Node<T>* tail_;
};

template<typename T>
class DoubleList
{
    DoubleList()
    {

    }

    DNode* InsertHead(const T& value)
    {

    }

    DNode* InsertBack(const T& value)
    {

    }

    DNode* Insert(DNode* pre, const T& value)
    {

    }

    DNode* Search(const T& vlaue)
    {

    }

    DNode* Delete(DNode* pre)
    {

    }

private:
    DNode<T>* head_;
    DNode<T>* tail_;
};

} // namespace basics