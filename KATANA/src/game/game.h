#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "../player/player.h"
#include <random>
#include <algorithm>
#include <sstream>
#include <cstdlib>

class Game
{
private:
    std::vector<Role*>* roles;
    std::vector<Character*>* characters;
    std::vector<Card*> cards;
    std::vector<Card*> discards;
    std::vector<Player*> players;
    int nbPlayers;

    int indexActualPlayer;

    std::string userInputStr;
    int userInputInt;

public:
    Game();

    void init();
    void initNbPlayers();
    void initRoles();
    void initCharacters();
    void initCards();
    void initPlayers();

    void showTurnCards();
    void start();
    void turn();
    void recoverCards();
    void recoverHP();
    void pickCard(Player* player, int nbCard);
    void play();
    void attack();
    int calculateDistance(Player* player);
    void discardCard(Player* player, Card* card);
};

#endif // GAME_H
