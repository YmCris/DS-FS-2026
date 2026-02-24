//
// Created by cristian on 2/23/26.
//

#ifndef SOURCECODE_DATAINPUT_H
#define SOURCECODE_DATAINPUT_H
#include <string>
#include <vector>


/**
* The DataInput class header is the class responsible for 
* 
* @author YmCris
* @since 2/23/26
*/
class DataInput
{
public:
    // PUBLIC API
    int requestInteger();
    std::string requestString();
    bool integerToBoolean(int integer);
    void waitForEnter();

    std::vector<int> requestOptions(std::string input);

};


#endif //SOURCECODE_DATAINPUT_H
