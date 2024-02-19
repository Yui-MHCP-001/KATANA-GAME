#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "../includes/initRoles.h"
#include "../includes/initCharacters.h"
#include "../includes/initCards.h"

class Player
{
private:
    std::string pseudo;
    Role& role;
    Character& character;
    std::vector<Card*>* hand;

public:
    int HP;
    int honorPoints;

    Player(Role& role, Character& character);
    void setPseudo(std::string pseudo);
    std::string getPseudo() const;
    Role& getRole() const;
    Character& getCharacter() const;
    std::vector<Card*>* getHand() const;

    bool Down() const;
    bool Block() const;
};

#endif // PLAYER_H