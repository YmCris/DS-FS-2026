//
// Created by cristian on 2/17/26.
//

#ifndef SOURCECODE_STACK_H
#define SOURCECODE_STACK_H

#include "../linked_list/LinkedList.h"

/**
* The Stack class header is the class responsible for 
* 
* @author YmCris
* @since 2/17/26
*/
template <typename T>
class Stack
{
public:
    // PUBLIC API
    void push(const T& value)
    {
        list_.addFirst(value);
    }

    void pop()
    {
        if (isEmpty()) throw std::logic_error("Stack is empty");

        list_.removeFirst();
    }

    T& peek()
    {
        if (isEmpty()) throw std::logic_error("Stack is empty");

        return list_.getHead()->value();
    }

    [[nodiscard]] bool isEmpty() const
    {
        return list_.isEmpty();
    }

    [[nodiscard]] int size() const
    {
        return list_.getSize();
    }

private:
    // DATA MEMBERS
    LinkedList<T> list_;
};

#endif //SOURCECODE_STACK_H
