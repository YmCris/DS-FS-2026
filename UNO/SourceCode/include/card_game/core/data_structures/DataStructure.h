//
// Created by cristian on 2/15/26.
//

#ifndef SOURCECODE_DATASTRUCTURE_H
#define SOURCECODE_DATASTRUCTURE_H


/**
* The DataStructure class header is the class responsible for 
* 
* @author YmCris
* @since 2/15/26
*/
template <typename T>
class DataStructure
{
public:
    // LIFETIME
    virtual ~DataStructure() = default;

    // PUBLIC API
    virtual void sort() = 0;
    virtual bool search(const T& element) = 0;
};


#endif //SOURCECODE_DATASTRUCTURE_H
