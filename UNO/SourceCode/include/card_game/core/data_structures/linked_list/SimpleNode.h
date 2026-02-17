//
// Created by cristian on 2/16/26.
//

#ifndef SOURCECODE_SIMPLENODE_H
#define SOURCECODE_SIMPLENODE_H
#include <utility>


/**
* The SimpleNode class header is the class responsible for 
* 
* @author YmCris
* @since 2/16/26
*/
template <typename T>
class SimpleNode
{
public:
    // LIFETIME
    explicit SimpleNode(T value, SimpleNode<T>* next = nullptr) :
        next_(next),
        value_(std::move(value))
    {
    }

    // PUBLIC API
    SimpleNode<T>* next()
    {
        return next_;
    }

    T& value()
    {
        return value_;
    }

    void setNext(SimpleNode<T>* next)
    {
        this->next_ = next;
    }

    void setValue(T value)
    {
        value_ = std::move(value);
    }

private:
    // DATA MEMBERS
    SimpleNode<T>* next_ = nullptr;
    T value_;
};


#endif //SOURCECODE_SIMPLENODE_H
