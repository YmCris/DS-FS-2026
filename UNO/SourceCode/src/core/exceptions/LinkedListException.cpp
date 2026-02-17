//
// Created by cristian on 16/02/26.
//

#include <stdexcept>

class LinkedListException : public std::logic_error{
    public:
    explicit LinkedListException(const std::string& message)
        : std::logic_error(message){}
};
