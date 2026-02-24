cmake_minimum_required(VERSION 3.26)
project(SourceCode)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined -fno-omit-frame-pointer -g")

add_executable(SourceCode src/main.cpp
        src/domain/card/Card.cpp
        include/card_game/domain/card/Card.h
        include/card_game/core/enums/cards/CardColor.h
        include/card_game/core/enums/cards/CardValue.h
        src/core/data_structures/DataStructure.cpp
        include/card_game/core/data_structures/DataStructure.h
        include/card_game/core/data_structures/linked_list/SimpleNode.h
        include/card_game/core/data_structures/linked_list/LinkedList.h
        src/core/exceptions/LinkedListException.cpp
        include/card_game/core/data_structures/double_linked_list/DoubleNode.h
        include/card_game/core/data_structures/double_linked_list/DoubleLinkedList.h
        include/card_game/core/data_structures/circular_list/CircularList.h
        include/card_game/core/data_structures/stack/Stack.h
        src/domain/deck/Deck.cpp
        include/card_game/domain/deck/Deck.h
        include/card_game/core/enums/cards/CardsLimit.h
        src/application/card_creator/CardCreator.cpp
        include/card_game/application/card_creator/CardCreator.h
        src/application/shuffle/Shuffle.cpp
        include/card_game/application/shuffle/Shuffle.h
        src/domain/player/Player.cpp
        include/card_game/domain/player/Player.h
        src/domain/player/Player.cpp
        src/application/match/MatchConfig.cpp
        include/card_game/application/match/MatchConfig.h
        src/application/match/Match.cpp
        include/card_game/application/match/Match.h
        src/infrastructure/menu/Menu.cpp
        include/card_game/infrastructure/menu/Menu.h
        src/infrastructure/options/Options.cpp
        include/card_game/infrastructure/options/Options.h
        src/infrastructure/game/Game.cpp
        include/card_game/infrastructure/game/Game.h
)
