//
// Created by cristian on 2/22/26.
//

#ifndef SOURCECODE_MATCHCONFIG_H
#define SOURCECODE_MATCHCONFIG_H


/**
* The MatchConfig class header is the class responsible for 
* 
* @author YmCris
* @since 2/22/26
*/
class MatchConfig
{
public:
    // LIFETIME
    MatchConfig(int players, bool flip, bool multiTwoResponse,
                bool multiFourResponse, bool challenge, bool multiSteal,
                bool winWithBlack
    );

    // PUBLIC API
    [[nodiscard]] int players() const;
    [[nodiscard]] bool flip() const;
    [[nodiscard]] bool multiTwoResponse() const;
    [[nodiscard]] bool multiFourResponse() const;
    [[nodiscard]] bool challenge() const;
    [[nodiscard]] bool multiSteal() const;
    [[nodiscard]] bool winWithBlack() const;

private:
    // DATA MEMBERS
    int players_;
    bool flip_;

    /*RULES*/
    bool multiTwoResponse_;
    bool multiFourResponse_;
    bool challenge_;
    bool multiSteal_;
    bool winWithBlack_;
};


#endif //SOURCECODE_MATCHCONFIG_H
