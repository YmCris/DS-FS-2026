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
    LinkedList() = default;
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    explicit LinkedList(T value)
    {
        addFirst(value);
    }

    ~LinkedList()
    {
        while (head_ != nullptr)
        {
            SimpleNode<T>* temp = head_;
            head_ = head_->next();
            delete temp;
        }
    }

    // PUBLIC API
    [[nodiscard]] bool isEmpty() const
    {
        return head_ == nullptr;
    }

    [[nodiscard]] int getSize() const
    {
        return size_;
    }

    void addAt(T& value, const int position)
    {
        outOfRangeToAdd(position);

        if (position == 0)
        {
            addFirst(value);
            return;
        }
        if (position == size_)
        {
            addLast(value);
            return;
        }

        int accountant = 1;
        SimpleNode<T>* node = new SimpleNode<T>(value);
        SimpleNode<T>* prev = head_;

        while (accountant < position)
        {
            prev = prev->next();
            accountant++;
        }

        SimpleNode<T>* next = prev->next();

        prev->setNext(node);
        node->setNext(next);
        size_++;
    }

    void addFirst(T& value)
    {
        SimpleNode<T>* node = new SimpleNode<T>(value);

        node->setNext(head_);
        head_ = node;

        size_++;
    }

    void addLast(T& value)
    {
        SimpleNode<T>* node = new SimpleNode<T>(value);
        if (head_ == nullptr)
        {
            head_ = node;
        }
        else
        {
            SimpleNode<T>* temp = head_;
            while (temp->next() != nullptr)
            {
                temp = temp->next();
            }
            temp->setNext(node);
        }

        size_++;
    }

    void removeAt(const int position)
    {
        outOfRangeToAccess(position);

        if (position == 0)
        {
            removeFirst();
            return;
        }
        if (position == size_ - 1)
        {
            removeLast();
            return;
        }

        int accountant = 1;
        SimpleNode<T>* prev = head_;
        while (accountant < position)
        {
            prev = prev->next();
            accountant++;
        }

        SimpleNode<T>* post = prev->next()->next();
        SimpleNode<T>* prePost = prev->next();
        prePost->setNext(nullptr);

        delete prePost;
        prev->setNext(post);

        size_--;
    }

    void removeFirst()
    {
        SimpleNode<T>* head = head_;
        head_ = head->next();

        delete head;

        size_--;
    }

    void removeLast()
    {
        if (head_ == nullptr)
            return;

        if (head_->next() == nullptr)
        {
            delete head_;
            head_ = nullptr;
        }
        else
        {
            SimpleNode<T>* current = head_;
            while (current->next()->next() != nullptr)
                current = current->next();

            delete current->next();
            current->setNext(nullptr);
        }

        --size_;
    }


    SimpleNode<T>* getAt(const int position)
    {
        outOfRangeToAccess(position);

        if (size_ == 0) throw std::logic_error("List is empty");
        if (position == 0) return getHead();
        if (position == size_ - 1) return getTail();

        int accountant = 1;
        SimpleNode<T>* node = head_->next();
        while (accountant < position)
        {
            node = node->next();
            accountant++;
        }

        return node;
    }

    SimpleNode<T>* getHead() const
    {
        return head_;
    }

    SimpleNode<T>* getTail() const
    {
        SimpleNode<T>* temp = head_;
        while (temp->next() != nullptr)
        {
            temp = temp->next();
        }
        return temp;
    }

    T getContent(SimpleNode<T>* node) const
    {
        return node->value();
    }

private:
    // HELPER METHODS
    void outOfRangeToAdd(const int position) const
    {
        if (position < 0 || position > size_)
            throw std::out_of_range("Invalid position to add");
    }

    void outOfRangeToAccess(const int position) const
    {
        if (position < 0 || position >= size_)
            throw std::out_of_range("Invalid position");
    }

    // DATA MEMBERS
    SimpleNode<T>* head_ = nullptr;
    int size_ = 0;
};


#endif //SOURCECODE_LINKEDLIST_H
