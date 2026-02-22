//
// Created by cristian on 2/17/26.
//

#ifndef SOURCECODE_DOUBLELINKEDLIST_H
#define SOURCECODE_DOUBLELINKEDLIST_H

#include <stdexcept>
#include "DoubleNode.h"

/**
* The DoubleLinkedList class header is the class responsible for 
* 
* @author YmCris
* @since 2/17/26
*/
template <typename T>
class DoubleLinkedList
{
public:
    // LIFETIME
    DoubleLinkedList() = default;

    DoubleLinkedList(const DoubleLinkedList&) = delete;
    DoubleLinkedList& operator=(const DoubleLinkedList&) = delete;

    explicit DoubleLinkedList(T value)
    {
        addFirst(value);
    }

    ~DoubleLinkedList()
    {
        DoubleNode<T>* current = head_;
        while (current != nullptr)
        {
            DoubleNode<T>* temp = current;
            current = current->next();
            delete temp;
        }
    }

    // PUBLIC API
    [[nodiscard]] bool isEmpty() const
    {
        return size_ == 0;
    }

    [[nodiscard]] int getSize() const
    {
        return size_;
    }

    void addFirst(T& value)
    {
        DoubleNode<T>* node = new DoubleNode<T>(value);

        if (isEmpty())
        {
            head_ = node;
            tail_ = node;
        }
        else
        {
            node->setNext(head_);
            head_->setPrev(node);
            head_ = node;
        }

        size_++;
    }

    void addLast(T& value)
    {
        DoubleNode<T>* node = new DoubleNode<T>(value);

        if (isEmpty())
        {
            head_ = node;
            tail_ = node;
        }
        else
        {
            node->setPrev(tail_);
            tail_->setNext(node);
            tail_ = node;
        }

        size_++;
    }

    void addAt(T& value, const int position)
    {
        validateInsert(position);

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

        DoubleNode<T>* node = new DoubleNode<T>(value);
        DoubleNode<T>* current = getAt(position);
        DoubleNode<T>* prev = current->prev();

        node->setNext(current);
        node->setPrev(prev);

        prev->setNext(node);
        current->setPrev(node);

        size_++;
    }

    T removeFirst()
    {
        if (isEmpty()) throw std::logic_error("List is empty");

        DoubleNode<T>* temp = head_;
        T value = std::move(temp->value());

        if (size_ == 1)
        {
            head_ = nullptr;
            tail_ = nullptr;
        }
        else
        {
            head_ = head_->next();
            head_->setPrev(nullptr);
        }

        delete temp;
        --size_;

        return value;
    }

    T removeLast()
    {
        if (isEmpty()) throw std::logic_error("List is empty");

        DoubleNode<T>* temp = tail_;
        T value = std::move(temp->value());

        if (size_ == 1)
        {
            head_ = nullptr;
            tail_ = nullptr;
        }
        else
        {
            tail_ = tail_->prev();
            tail_->setNext(nullptr);
        }

        delete temp;
        size_--;

        return value;
    }

    T removeAt(const int position)
    {
        validateAccess(position);

        if (position == 0)
        {
            return removeFirst();
        }

        if (position == size_ - 1)
        {
            return removeLast();
        }

        DoubleNode<T>* current = getAt(position);
        T value = std::move(current->value());

        DoubleNode<T>* prev = current->prev();
        DoubleNode<T>* next = current->next();

        prev->setNext(next);
        next->setPrev(prev);

        delete current;
        size_--;

        return value;
    }

    DoubleNode<T>* getAt(const int position) const
    {
        validateAccess(position);

        if (position < size_ / 2)
        {
            DoubleNode<T>* current = head_;
            for (int i = 0; i < position; ++i)
            {
                current = current->next();
            }
            return current;
        }

        DoubleNode<T>* current = tail_;
        for (int i = size_ - 1; i > position; --i)
        {
            current = current->prev();
        }
        return current;
    }

    DoubleNode<T>* getHead() const
    {
        return head_;
    }

    DoubleNode<T>* getTail() const
    {
        return tail_;
    }

protected:
    void validateInsert(const int position) const
    {
        if (position < 0 || position > size_)
            throw std::out_of_range("Invalid position to add");
    }

    void validateAccess(const int position) const
    {
        if (position < 0 || position >= size_)
            throw std::out_of_range("Invalid position");
    }

    DoubleNode<T>* head_ = nullptr;
    DoubleNode<T>* tail_ = nullptr;
    int size_ = 0;
};

#endif //SOURCECODE_DOUBLELINKEDLIST_H
