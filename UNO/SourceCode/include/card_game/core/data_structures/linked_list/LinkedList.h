//
// Created by cristian on 2/16/26.
//

#ifndef SOURCECODE_LINKEDLIST_H
#define SOURCECODE_LINKEDLIST_H

#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>

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

    void addAt(const T& value, const int position)
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

    void addFirst(const T& value)
    {
        SimpleNode<T>* node = new SimpleNode<T>(value);

        node->setNext(head_);
        head_ = node;

        size_++;
    }

    void addLast(const T& value)
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

    T removeFirst()
    {
        if (head_ == nullptr)
            throw std::logic_error("List is empty");

        SimpleNode<T>* node = head_;
        T value = node->value();

        head_ = node->next();
        delete node;

        size_--;

        return value;
    }

    T removeLast()
    {
        if (head_ == nullptr)
            throw std::logic_error("List is empty");

        if (head_->next() == nullptr)
        {
            T value = head_->value();
            delete head_;
            head_ = nullptr;
            --size_;

            return value;
        }

        SimpleNode<T>* current = head_;
        while (current->next()->next() != nullptr)
        {
            current = current->next();
        }

        SimpleNode<T>* last = current->next();
        T value = last->value();

        delete last;
        current->setNext(nullptr);

        --size_;
        return value;
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

    void disorder()
    {
        if (size_ <= 1) return;

        std::vector<T> elements;
        elements.reserve(size_);

        SimpleNode<T>* current = head_;
        while (current != nullptr)
        {
            elements.push_back(current->value());
            current = current->next();
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::shuffle(elements.begin(), elements.end(), gen);

        current = head_;
        int index = 0;

        while (current != nullptr)
        {
            current->setValue(elements[index]);
            current = current->next();
            ++index;
        }
    }

    SimpleNode<T>* getHead() const
    {
        return head_;
    }

    SimpleNode<T>* getTail() const
    {
        if (!head_) return nullptr;

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
