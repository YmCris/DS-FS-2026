//
// Created by cristian on 2/23/26.
//

#include "../../../include/card_game/infrastructure/options/Options.h"

#include <iostream>

// PUBLIC API

void Options::showOptions()
{
    std::cout << R"(

                                    ┌---------------------------------------------------------------------┐
                                    ¦                                                                     ¦
                                    ¦                                                                     ¦
                                    ¦      ___    ____     ____   ___    ___    _   _   _____   ____      ¦
                                    ¦     / _ \  |  _ \   / ___| |_ _|  / _ \  | \ | | | ____| / ___|     ¦
                                    ¦    | | | | | |_) | | |      | |  | | | | |  \| | |  _|   \___ \     ¦
                                    ¦    | |_| | |  __/  | |___   | |  | |_| | | |\  | | |___   ___) |    ¦
                                    ¦     \___/  |_|      \____| |___|  \___/  |_| \_| |_____| |____/     ¦
                                    ¦                                                                     ¦
                                    ¦                                                                     ¦
                                    ¦                                                                     ¦
                                    ¦                                                                     ¦
                                    ¦  Jugadores:                                                         ¦
                                    ¦  Modo:                        FLIP (1) | NORMAL (2)                 ¦
                                    ¦  Acumulación (+2):             SI (1) | NO (2)                      ¦
                                    ¦  Acumulación (+4):             SI (1) | NO (2)                      ¦
                                    ¦  Retar:                        SI (1) | NO (2)                      ¦
                                    ¦  Robar:                        LÍMITE (1) | SIN LÍMITE (2)          ¦
                                    ¦  Ganar con carta negra:        SI (1) | NO (2)                      ¦
                                    ¦                                                                     ¦
                                    ¦  Ejemplo: 10,2,1,1,2,1,2                                            ¦
                                    ¦                                                                     ¦
                                    └---------------------------------------------------------------------┘

)";
}
