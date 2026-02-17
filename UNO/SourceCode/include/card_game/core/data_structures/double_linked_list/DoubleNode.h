//
// Created by cristian on 2/17/26.
//

#ifndef SOURCECODE_DOUBLENODE_H
#define SOURCECODE_DOUBLENODE_H
#include <utility>


/**
* The DoubleNode class header is the class responsible for be a double node
* 
* @author YmCris
* @since 2/17/26
*/
template <typename T>
class DoubleNode
{
public:
    // LIFETIME
    explicit DoubleNode(
        T value,
        DoubleNode<T>* next = nullptr,
        DoubleNode<T>* prev = nullptr
    ) :
        next_(next),
        prev_(prev),
        value_(std::move(value))
    {
    }

    // PUBLIC API
    DoubleNode<T>* next()
    {
        return next_;
    }

    DoubleNode<T>* prev()
    {
        return prev_;
    }

    T& value()
    {
        return value_;
    }

    void setNext(DoubleNode<T>* next)
    {
        next_ = next;
    }

    void setPrev(DoubleNode<T>* prev)
    {
        prev_ = prev;
    }

    void setValue(T value)
    {
        value_ = std::move(value);
    }

private:
    // DATA MEMBERS
    DoubleNode<T>* next_ = nullptr;
    DoubleNode<T>* prev_ = nullptr;
    T value_;
};


#endif //SOURCECODE_DOUBLENODE_H
