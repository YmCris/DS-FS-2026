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
/*FILO First in last out
 * Ingres in the start
 * Last
 */
class Stack
{
public:
    Stack(LinkedList<T>& list) :
        list_(list)
    {
    }

    // PUBLIC API
    void push(const T& value)
    {
        list_.addFirst(value);
    }

    T pop()
    {//Change
        if (isEmpty()) throw std::logic_error("Stack is empty");

        return list_.removeFirst();
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
    LinkedList<T>& list_;
};

#endif //SOURCECODE_STACK_H
