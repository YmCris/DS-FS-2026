cmake_minimum_required(VERSION 3.26)
project(SourceCode)

set(CMAKE_CXX_STANDARD 23)

add_executable(SourceCode src/main.cpp
        src/domain/card/Card.cpp
        include/card_game/domain/card/Card.h
        include/card_game/core/enums/Cards/CardColor.h
        include/card_game/core/enums/Cards/CardValue.h
)
