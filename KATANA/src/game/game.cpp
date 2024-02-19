#include "game.h"

Game::Game()
{
    this->roles = new std::vector<Role*>();
    this->characters = new std::vector<Character*>();
    this->cards = std::vector<Card*>();
    this->discards = std::vector<Card*>();
    this->players = std::vector<Player*>();
    this->indexActualPlayer = 0;
    this->userInputStr = "";
    this->userInputInt = -1;
}

// print l'ordre des joueurs
void Game::init()
{
    this->initNbPlayers();
    this->initRoles();
    this->initCharacters();
    this->initCards();
    this->initPlayers();
}

void Game::initNbPlayers()
{
    while (true)
    {
        try
        {
            std::cout << "Enter the number of players (4 to 7): ";
            std::getline(std::cin, this->userInputStr);

            std::stringstream stream(this->userInputStr);

            if (!(stream >> this->userInputInt) || this->userInputInt < 4 || this->userInputInt > 7)
            {
                throw std::invalid_argument("Invalid input");
            }

            break;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

    }

    this->nbPlayers = this->userInputInt;
}

void Game::initRoles()
{
    this->roles->push_back(new Shogun);
    this->roles->push_back(new Samurai);

    std::vector<Role*>* ninjas = new std::vector<Role*>();
    ninjas->push_back(new NinjaOne);
    ninjas->push_back(new NinjaTwo);
    ninjas->push_back(new NinjaThree);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(ninjas->begin(), ninjas->end(), g);

    for (int i = 0; i < 2; i++)
    {
        this->roles->push_back(ninjas->back());
        ninjas->pop_back();
    }

    switch (this->nbPlayers)
    {
    case 5:
        this->roles->push_back(new Ronin);
        break;

    case 6:
        this->roles->push_back(new Ronin);
        this->roles->push_back(ninjas->back());
        ninjas->pop_back();
        break;
    case 7:
        this->roles->push_back(new Ronin);
        this->roles->push_back(ninjas->back());
        ninjas->pop_back();
        this->roles->push_back(new Samurai);
        break;
    default:
        break;
    }

    delete ninjas;

    std::shuffle(this->roles->begin(), this->roles->end(), g);
}

void Game::initCharacters()
{
    this->characters->push_back(new Hanzo);
    this->characters->push_back(new Ushiwaka);
    this->characters->push_back(new Chiyome);
    this->characters->push_back(new Hideyoshi);
    this->characters->push_back(new Ginchyo);
    this->characters->push_back(new Goemon);
    this->characters->push_back(new Nobunaga);
    this->characters->push_back(new Tomoe);
    this->characters->push_back(new Ieyasu);
    this->characters->push_back(new Benkei);
    this->characters->push_back(new Musashi);
    this->characters->push_back(new Kojiro);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(this->characters->begin(), this->characters->end(), g);
}

void Game::initCards()
{
    int* nbCopy = new int[25] {
        NB_COPY_CRI_DE_GUERRE,
            NB_COPY_DAIMYO,
            NB_COPY_DIVERSION,
            NB_COPY_GEISHA,
            NB_COPY_MEDITATION,
            NB_COPY_PARADE,
            NB_COPY_CEREMONIE_DU_THE,
            NB_COPY_JU_JITSU,
            NB_COPY_ATTAQUE_RAPIDE,
            NB_COPY_CODE_DU_BUSHIDO,
            NB_COPY_ARMURE,
            NB_COPY_CONCENTRATION,
            NB_COPY_NODACHI,
            NB_COPY_NAGINATA,
            NB_COPY_NAGAYARI,
            NB_COPY_TANEGASHIMA,
            NB_COPY_DAIKYU,
            NB_COPY_BO,
            NB_COPY_KUSARIGAMA,
            NB_COPY_KATANA,
            NB_COPY_SHURIKEN,
            NB_COPY_KANABO,
            NB_COPY_BOKKEN,
            NB_COPY_KISERU,
            NB_COPY_WAKIZASHI
        };

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < nbCopy[i]; j++) {
            switch (i) {
            case 0:
                this->cards.push_back(new CriDeGuerre);
                break;
            case 1:
                this->cards.push_back(new Daimyo);
                break;
            case 2:
                this->cards.push_back(new Diversion);
                break;
            case 3:
                this->cards.push_back(new Geisha);
                break;
            case 4:
                this->cards.push_back(new Meditation);
                break;
            case 5:
                this->cards.push_back(new Parade);
                break;
            case 6:
                this->cards.push_back(new CeremonieDuThe);
                break;
            case 7:
                this->cards.push_back(new JuJitsu);
                break;
            case 8:
                this->cards.push_back(new AttaqueRapide);
                break;
            case 9:
                this->cards.push_back(new CodeDuBushido);
                break;
            case 10:
                this->cards.push_back(new Armure);
                break;
            case 11:
                this->cards.push_back(new Concentration);
                break;
            case 12:
                this->cards.push_back(new Nodachi);
                break;
            case 13:
                this->cards.push_back(new Naginata);
                break;
            case 14:
                this->cards.push_back(new Nagayari);
                break;
            case 15:
                this->cards.push_back(new Tanegashima);
                break;
            case 16:
                this->cards.push_back(new Daikyu);
                break;
            case 17:
                this->cards.push_back(new Bo);
                break;
            case 18:
                this->cards.push_back(new Kusarigama);
                break;
            case 19:
                this->cards.push_back(new Katana);
                break;
            case 20:
                this->cards.push_back(new Shuriken);
                break;
            case 21:
                this->cards.push_back(new Kanabo);
                break;
            case 22:
                this->cards.push_back(new Bokken);
                break;
            case 23:
                this->cards.push_back(new Kiseru);
                break;
            case 24:
                this->cards.push_back(new Wakizashi);
                break;
            }
        }
    }

    delete[] nbCopy;

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(this->cards.begin(), this->cards.end(), g);
}

void Game::initPlayers()
{
    for (int i = 0; i < this->nbPlayers; i++) {
        this->players.push_back(new Player(*this->roles->back(), *this->characters->back()));
        this->roles->pop_back();
        this->characters->pop_back();

        std::cout << "Enter the pseudo of player " << i + 1 << ": ";
        std::cin >> this->userInputStr;

        this->players.at(i)->setPseudo(this->userInputStr);
    }
    delete this->roles;

    for (std::vector<Character*>::iterator it = this->characters->begin(); it != this->characters->end(); it++) {
        delete* it;
    }
    delete this->characters;

    int indexShogun = -1;
    for (int i = 0; i < this->nbPlayers; i++) {
        if (this->players.at(i)->getRole().getRoleType() == RoleType::SHOGUN) {
            indexShogun = i;
            break;
        }
    }

    std::rotate(this->players.begin(), this->players.begin() + indexShogun, this->players.end());

    int nbCard;
    for (int i = 0; i < this->nbPlayers; i++) {
        switch (i) {
        case 0:
            nbCard = 4;
            break;
        case 1:
        case 2:
            nbCard = 5;
            break;
        case 3:
        case 4:
            nbCard = 6;
            break;
        case 5:
        case 6:
            nbCard = 7;
            break;
        default:
            break;
        }

        for (int j = 0; j < nbCard; j++) {
            this->players.at(i)->getHand()->push_back(this->cards.back());
            this->cards.pop_back();
        }
    }

    for (std::vector<Player*>::iterator it = this->players.begin(); it != this->players.end(); ++it) {
        if ((*it)->getRole().getRoleType() == RoleType::SHOGUN) {
            (*it)->honorPoints = 5;
        }
        else if (this->nbPlayers < 6) {
            (*it)->honorPoints = 3;
        }
        else {
            (*it)->honorPoints = 4;
        }
    }
}

void Game::showTurnCards()
{
    for (std::vector<Player*>::size_type i = 0; i < this->players.size(); i++)
    {
        std::cout << i << ". " << this->players.at(i)->getPseudo();
        if (i == 0) {
            std::cout << " (Shogun)";
        }
        std::cout << std::endl;
    }

    while (true)
    {
        try
        {
            std::cout << "Have you finished (y/n) ? ";
            std::cin >> this->userInputStr;

            if (this->userInputStr != "y" && this->userInputStr != "n")
            {
                throw std::invalid_argument("Invalid input");
            }

            if (this->userInputStr == "y")
            {
                break;
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    system("clear");

    int i = 0;
    while (i < this->nbPlayers) {
        std::cout << this->players.at(i)->getPseudo() << " is " << this->players.at(i)->getRole().getRoleName() << " and has " << this->players.at(i)->getCharacter().getCharacterName() << std::endl;
        std::cout << "His hand is: " << this->players.at(i)->getHand()->size() << std::endl;
        for (std::vector<Card*>::iterator it = this->players.at(i)->getHand()->begin(); it != this->players.at(i)->getHand()->end(); it++)
        {
            std::cout << (*it)->getCardName() << std::endl;
        }

        while (true)
        {
            try
            {
                std::cout << "Have you finished (y/n) ? ";
                std::cin >> this->userInputStr;

                if (this->userInputStr != "y" && this->userInputStr != "n")
                {
                    throw std::invalid_argument("Invalid input");
                }

                break;
            }
            catch (const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }

        if (this->userInputStr == "y")
        {
            i++;
        }

        system("clear");
    }
}

void Game::start()
{
    this->showTurnCards();

    while (true)
    {
        this->turn();
        system("clear");
    }
}

void Game::turn()
{
    Player* player = this->players.at(this->indexActualPlayer);
    std::cout << "Turning " << player->getPseudo() << std::endl;
    this->recoverHP();
    this->pickCard(player, 2);
    this->play();

    std::cout << "Discard cards" << std::endl;
    while (player->getHand()->size() > 7)
    {
        for (std::vector<Card*>::size_type i = 0; i < player->getHand()->size(); i++)
        {
            std::cout << i + 1 << ". " << player->getHand()->at(i)->getCardName() << std::endl;
        }

        while (true)
        {
            try
            {
                std::cout << "Enter the index of the card you want to discard: ";
                std::getline(std::cin, this->userInputStr);

                std::stringstream stream(this->userInputStr);

                if (!(stream >> this->userInputInt) || this->userInputInt < 1 || this->userInputInt > static_cast<int>(player->getHand()->size()))
                {
                    throw std::invalid_argument("Invalid input");
                }

                break;
            }
            catch (const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }

        this->discardCard(player, player->getHand()->at(this->userInputInt - 1));

    }
    this->indexActualPlayer = (this->indexActualPlayer + 1) % this->nbPlayers;
}

void Game::recoverCards()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(this->discards.begin(), this->discards.end(), g);

    for (std::vector<Card*>::iterator it = this->discards.begin(); it != this->discards.end(); it++)
    {
        this->cards.push_back(*it);
    }
    this->discards.clear();

    for (std::vector<Player*>::iterator it = this->players.begin(); it != this->players.end(); it++)
    {
        (*it)->honorPoints--;
    }
}

void Game::recoverHP()
{
    Player* player = this->players.at(this->indexActualPlayer);
    if (player->HP <= 0)
    {
        player->HP = player->getCharacter().getMaxHP();
    }
}

void Game::pickCard(Player* player, int nbCard)
{
    for (int i = 0; i < nbCard; i++)
    {
        if (this->cards.empty())
        {
            this->recoverCards();
        }
        player->getHand()->push_back(this->cards.back());
        this->cards.pop_back();
    }
}

void Game::play()
{
    while (true)
    {
        try
        {
            std::cout << "Enter the action you want to do (1. Attack, 2. Other): ";
            std::getline(std::cin, this->userInputStr);

            std::stringstream stream(this->userInputStr);

            if (!(stream >> this->userInputInt) || this->userInputInt < 1 || this->userInputInt > 2)
            {
                throw std::invalid_argument("Invalid input");
            }

            break;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    if (this->userInputInt == 1)
    {
        std::cout << "Attack!" << std::endl;
        this->attack();
    }
    else
    {
        std::cout << "Other action" << std::endl;
    }
}

void Game::attack()
{
    Player* player = this->players.at(this->indexActualPlayer);
    std::vector<int>* weapons = new std::vector<int>();
    std::vector<int>* playersIndex = new std::vector<int>();

    for (std::vector<Card*>::size_type i = 0; i < player->getHand()->size(); i++)
    {
        Card* card = player->getHand()->at(i);
        if (card->getCardType() == CardType::WEAPON)
        {
            Weapon* weapon = dynamic_cast<Weapon*>(card);
            std::cout << i + 1 << ". " << weapon->getCardName() << " dmg = " << weapon->getDamage() << std::endl;
            for (std::vector<Player*>::iterator it = this->players.begin(); it != this->players.end(); it++)
            {
                if ((*it) != player && this->calculateDistance((*it)) <= weapon->getRange()) {
                    std::cout << "    > " << (*it)->getPseudo() << std::endl;
                }
            }
            weapons->push_back(i + 1);
        }
    }

    if (weapons->size() > 0) {
        while (true)
        {
            try
            {
                std::cout << "Enter the index of the weapon you want to use: ";
                std::getline(std::cin, this->userInputStr);

                std::stringstream stream(this->userInputStr);

                if (!(stream >> this->userInputInt) || std::find(weapons->begin(), weapons->end(), this->userInputInt) == weapons->end())
                {
                    throw std::invalid_argument("Invalid input");
                }

                break;
            }
            catch (const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }

        weapons->clear();
        delete weapons;
        system("clear");

        int indexWeapon = this->userInputInt - 1;
        Weapon* weapon = dynamic_cast<Weapon*>(player->getHand()->at(indexWeapon));

        for (std::vector<Player*>::size_type i = 0; i < this->players.size(); i++)
        {
            if (this->calculateDistance(this->players.at(i)) <= weapon->getRange() && this->players.at(i) != player && !this->players.at(i)->Down())
            {
                playersIndex->push_back(i + 1);
            }
        }

        std::cout << "Players you can attack:" << std::endl;
        for (std::vector<int>::iterator it = playersIndex->begin(); it != playersIndex->end(); it++)
        {
            std::cout << (*it) << ". " << this->players.at((*it) - 1)->getPseudo() << std::endl;
        }

        while (true)
        {
            try
            {
                std::cout << "Enter the index of the player you want to attack: ";
                std::getline(std::cin, this->userInputStr);

                std::stringstream stream(this->userInputStr);

                if (!(stream >> this->userInputInt) || std::find(playersIndex->begin(), playersIndex->end(), this->userInputInt) == playersIndex->end())
                {
                    throw std::invalid_argument("Invalid input");
                }

                break;
            }
            catch (const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }

        playersIndex->clear();
        delete playersIndex;
        system("clear");

        Player* playerTarget = this->players.at(this->userInputInt - 1);
        std::cout << "Player " << playerTarget->getPseudo() << " has " << playerTarget->HP << "HP before" << std::endl;

        if (playerTarget->Block()) {
            std::cout << "Player " << playerTarget->getPseudo() << " can block" << std::endl;

            while (true)
            {
                try
                {
                    std::cout << "Do you want to use a parade (y/n) ? ";
                    std::getline(std::cin, this->userInputStr);

                    if (this->userInputStr != "y" && this->userInputStr != "n")
                    {
                        throw std::invalid_argument("Invalid input");
                    }

                    break;
                }
                catch (const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }

            if (this->userInputStr == "y")
            {
                for (std::vector<Card*>::size_type i = 0; i < playerTarget->getHand()->size(); i++)
                {
                    if (playerTarget->getHand()->at(i)->getCardType() == CardType::ACTION)
                    {
                        Action* action = dynamic_cast<Action*>(playerTarget->getHand()->at(i));
                        if (action->getActionType() == ActionType::PARADE)
                        {
                            this->discardCard(playerTarget, playerTarget->getHand()->at(i));
                            break;
                        }
                    }
                }
            }
            else
            {
                playerTarget->HP -= weapon->getDamage();
            }
        }
        else {
            playerTarget->HP -= weapon->getDamage();
        }

        std::cout << "Player " << playerTarget->getPseudo() << " has " << playerTarget->HP << "HP after attack" << std::endl;
        this->discardCard(player, player->getHand()->at(indexWeapon));
    }
    else
    {
        std::cout << "You don't have any weapon" << std::endl;
    }

    system("clear");
}

int Game::calculateDistance(Player* player)
{
    bool findPlayerTarget = false;
    int distanceClockwise = 0;

    std::vector<Player*>::size_type indexDifferenceClockwise = this->indexActualPlayer - (this->players.begin() - this->players.begin());
    for (std::vector<Player*>::size_type i = indexDifferenceClockwise + 1; i < this->players.size(); i++)
    {
        if (!this->players.at(i)->Down())
        {
            distanceClockwise++;
            if (this->players.at(i) == player)
            {
                findPlayerTarget = true;
                break;
            }
        }
    }

    if (!findPlayerTarget)
    {
        indexDifferenceClockwise = std::distance(this->players.begin(), this->players.begin() + this->indexActualPlayer);
        for (std::vector<Player*>::size_type i = 0; i < indexDifferenceClockwise; i++)
        {
            if (!this->players.at(i)->Down())
            {
                distanceClockwise++;
                if (this->players.at(i) == player)
                {
                    findPlayerTarget = true;
                    break;
                }
            }
        }
    }

    findPlayerTarget = false;
    int distanceCounterClockwise = 0;

    std::vector<Player*>::size_type indexDifferenceCounterClockwise = std::distance(this->players.begin(), this->players.begin() + this->indexActualPlayer);
    for (std::vector<Player*>::size_type i = indexDifferenceCounterClockwise - 1; i < this->players.size(); i--)
    {
        if (!this->players.at(i)->Down())
        {
            distanceCounterClockwise++;
            if (this->players.at(i) == player)
            {
                findPlayerTarget = true;
                break;
            }
        }
    }

    if (!findPlayerTarget)
    {
        indexDifferenceCounterClockwise = this->indexActualPlayer - std::distance(this->players.begin(), this->players.end());
        for (std::vector<Player*>::size_type i = this->players.size() - 1; i > indexDifferenceCounterClockwise; i--)
        {
            if (!this->players.at(i)->Down())
            {
                distanceCounterClockwise++;
                if (this->players.at(i) == player)
                {
                    findPlayerTarget = true;
                    break;
                }
            }
        }
    }

    return std::min(distanceClockwise, distanceCounterClockwise);
}

void Game::discardCard(Player* player, Card* card)
{
    this->discards.push_back(card);
    player->getHand()->erase(std::remove(player->getHand()->begin(), player->getHand()->end(), card), player->getHand()->end());
}