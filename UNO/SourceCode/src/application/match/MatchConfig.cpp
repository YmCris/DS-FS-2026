//
// Created by cristian on 2/22/26.
//

#include "../../../include/card_game/application/match/MatchConfig.h"

// LIFETIME
MatchConfig::MatchConfig(bool flip, bool multiTwoResponse,
                         bool multiFourResponse, bool challenge,
                         bool multiSteal, bool winWithBlack) :
    flip_(flip),
    multiTwoResponse_(multiTwoResponse),
    multiFourResponse_(multiFourResponse),
    challenge_(challenge),
    multiSteal_(multiSteal),
    winWithBlack_(winWithBlack)
{
}

// PUBLIC API
bool MatchConfig::flip() const
{
    return flip_;
}

bool MatchConfig::multiTwoResponse() const
{
    return multiTwoResponse_;
}

bool MatchConfig::multiFourResponse() const
{
    return multiFourResponse_;
}

bool MatchConfig::challenge() const
{
    return challenge_;
}

bool MatchConfig::multiSteal() const
{
    return multiSteal_;
}

bool MatchConfig::winWithBlack() const
{
    return winWithBlack_;
}
