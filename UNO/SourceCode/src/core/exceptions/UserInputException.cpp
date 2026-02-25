//
// Created by cristian on 2/23/26.
//

#include <stdexcept>

class UserInputException : public std::logic_error
{
public:
    explicit UserInputException(const std::string& message)
        : std::logic_error(message)
    {
    }
};
