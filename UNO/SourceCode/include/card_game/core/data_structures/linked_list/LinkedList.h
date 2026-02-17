//
// Created by cristian on 2/16/26.
//

#ifndef SOURCECODE_LINKEDLIST_H
#define SOURCECODE_LINKEDLIST_H

#include <stdexcept>

#include "SimpleNode.h"

/**
* The LinkedList class header is the class responsible for be the simple linked list of the program
* 
* @author YmCris
* @since 2/16/26
*/
template <typename T>
class LinkedList
{
public:
    // LIFETIME
    explicit LinkedList(T value);

    // PUBLIC API
    bool isEmpty()
    {
        return head_==nullptr;
    }

    int getSize()
    {
        return size_;
    }

    void addAt(T value, int position)
    {
        if (position==0)
        {
            addFirst(value);
            return;
        }
        if (position==size_-1)
        {
            addLast(value);
            return;
        }
        outOfRange();
    }

    void addFirst(T value)
    {
        SimpleNode<T> node = new SimpleNode<T>(value);
        this->head_= node;
    }

    void addLast(T value)
    {
        SimpleNode<T> node = new SimpleNode<T>(value);
        SimpleNode<T> temp = head_;
        while (temp!=nullptr)
        {
            temp = temp.next();
        }
    }

    void removeAt(int position){}
    void removeFirst(){}
    void removeLast(){}

    SimpleNode<T>* getAt(int position){}
    SimpleNode<T>* getTail(){}
    SimpleNode<T>* getHead(){}
    T getContent(SimpleNode<T> node){}

private:
    // HELPER METHODS
    void outOfRange(const int& position) const
    {
        if (position<0 || position> size_)
        {
            throw std::out_of_range("You have to select a number grater or equals than 0 and less than "+size_);
        }
    }

    // DATA MEMBERS
    SimpleNode<T>* head_;
    int size_;
};


#endif //SOURCECODE_LINKEDLIST_H