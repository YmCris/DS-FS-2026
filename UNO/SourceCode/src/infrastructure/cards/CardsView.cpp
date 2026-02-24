//
// Created by cristian on 2/24/26.
//

#include "../../../include/card_game/infrastructure/cards/CardsView.h"

#include <iostream>

// PUBLIC API
void CardsView::showRoof()
{
    std::cout << R"(┌---------------------------------------------┐
)";
}

void CardsView::showFloor()
{
    std::cout << R"(├---------------------------------------------┤
¦ Seleccione una carta:                	      ¦
└---------------------------------------------┘
)";
}
