//
// Created by cristian on 2/17/26.
//

#ifndef SOURCECODE_CIRCULARLIST_H
#define SOURCECODE_CIRCULARLIST_H
#include "../double_linked_list/DoubleLinkedList.h"


/**
* The CircularList class header is the class responsible for 
* 
* @author YmCris
* @since 2/17/26
*/

template <typename T>
class CircularDoubleLinkedList
{
public:
    // LIFETIME
    CircularDoubleLinkedList() = default;

    CircularDoubleLinkedList(const CircularDoubleLinkedList&) = delete;
    CircularDoubleLinkedList& operator=(const CircularDoubleLinkedList&)
    = delete;

    ~CircularDoubleLinkedList()
    {
        clear();
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

    DoubleNode<T>* getHead() const
    {
        return head_;
    }

    DoubleNode<T>* getTail() const
    {
        if (isEmpty()) return nullptr;
        return head_->prev();
    }

    void addFirst(const T& value)
    {
        DoubleNode<T>* node = new DoubleNode<T>(value);

        if (isEmpty())
        {
            head_ = node;
            node->setNext(node);
            node->setPrev(node);
        }
        else
        {
            DoubleNode<T>* tail = head_->prev();

            node->setNext(head_);
            node->setPrev(tail);

            head_->setPrev(node);
            tail->setNext(node);

            head_ = node;
        }

        size_++;
    }

    void addLast(T& value)
    {
        if (isEmpty())
        {
            addFirst(value);
            return;
        }

        DoubleNode<T>* node = new DoubleNode<T>(value);
        DoubleNode<T>* tail = head_->prev();

        node->setNext(head_);
        node->setPrev(tail);

        tail->setNext(node);
        head_->setPrev(node);

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

        DoubleNode<T>* current = getAt(position);
        DoubleNode<T>* prev = current->prev();

        DoubleNode<T>* node = new DoubleNode<T>(value);

        node->setNext(current);
        node->setPrev(prev);

        prev->setNext(node);
        current->setPrev(node);

        size_++;
    }

    void removeFirst()
    {
        if (isEmpty()) return;

        if (size_ == 1)
        {
            delete head_;
            head_ = nullptr;
            size_ = 0;
            return;
        }

        DoubleNode<T>* tail = head_->prev();
        DoubleNode<T>* temp = head_;

        head_ = head_->next();

        head_->setPrev(tail);
        tail->setNext(head_);

        delete temp;
        size_--;
    }

    void removeLast()
    {
        if (isEmpty()) return;

        if (size_ == 1)
        {
            removeFirst();
            return;
        }

        DoubleNode<T>* tail = head_->prev();
        DoubleNode<T>* newTail = tail->prev();

        newTail->setNext(head_);
        head_->setPrev(newTail);

        delete tail;
        size_--;
    }

    void removeAt(const int position)
    {
        validateAccess(position);

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

        DoubleNode<T>* current = getAt(position);
        DoubleNode<T>* prev = current->prev();
        DoubleNode<T>* next = current->next();

        prev->setNext(next);
        next->setPrev(prev);

        delete current;
        size_--;
    }

    DoubleNode<T>* getAt(const int position) const
    {
        validateAccess(position);

        DoubleNode<T>* current;

        if (position < size_ / 2)
        {
            current = head_;
            for (int i = 0; i < position; ++i)
            {
                current = current->next();
            }
        }
        else
        {
            current = head_->prev();
            for (int i = size_ - 1; i > position; --i)
            {
                current = current->prev();
            }
        }

        return current;
    }

    void clear()
    {
        if (isEmpty()) return;

        DoubleNode<T>* current = head_->next();

        while (current != head_)
        {
            DoubleNode<T>* temp = current;
            current = current->next();
            delete temp;
        }

        delete head_;
        head_ = nullptr;
        size_ = 0;
    }

private:
    void validateInsert(const int position) const
    {
        if (position < 0 || position > size_)
            throw std::out_of_range("Invalid position to add: "+std::to_string(position));
    }

    void validateAccess(const int position) const
    {
        if (position < 0 || position >= size_)
            throw std::out_of_range("Invalid position to access: "+std::to_string(position));
    }

    DoubleNode<T>* head_ = nullptr;
    int size_ = 0;
};


#endif //SOURCECODE_CIRCULARLIST_H
