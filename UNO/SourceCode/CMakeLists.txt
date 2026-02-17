cmake_minimum_required(VERSION 3.26)
project(SourceCode)

set(CMAKE_CXX_STANDARD 23)

add_executable(SourceCode src/main.cpp
        src/domain/card/Card.cpp
        include/card_game/domain/card/Card.h
        include/card_game/core/enums/Cards/CardColor.h
        include/card_game/core/enums/Cards/CardValue.h
        src/core/data_structures/DataStructure.cpp
        include/card_game/core/data_structures/DataStructure.h
        include/card_game/core/data_structures/linked_list/SimpleNode.h
        include/card_game/core/data_structures/linked_list/LinkedList.h
        src/core/exceptions/LinkedListException.cpp
        include/card_game/core/data_structures/double_linked_list/DoubleNode.h
        include/card_game/core/data_structures/double_linked_list/DoubleLinkedList.h
        include/card_game/core/data_structures/circular_list/CircularList.h
        include/card_game/core/data_structures/stack/Stack.h
)
