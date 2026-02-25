//
// Created by cristian on 2/24/26.
//

#include <stdexcept>

class InvalidCardException : public std::logic_error
{
public:
    explicit InvalidCardException(const std::string& message)
        : std::logic_error(message)
    {
    }
};
