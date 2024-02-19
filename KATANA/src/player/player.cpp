#include "player.h"

Player::Player(Role& role, Character& character) : role(role), character(character) {
    this->pseudo = "";
    this->HP = this->character.getMaxHP();
    this->honorPoints = 0;
    this->hand = new std::vector<Card*>();
}

void Player::setPseudo(std::string pseudo)
{
    this->pseudo = pseudo;
}

std::string Player::getPseudo() const
{
    return this->pseudo;
}

Role& Player::getRole() const
{
    return this->role;
}

Character& Player::getCharacter() const
{
    return this->character;
}

std::vector<Card*>* Player::getHand() const
{
    return this->hand;
}

bool Player::Down() const
{
    return this->HP <= 0 || this->hand->empty();
}

bool Player::Block() const
{
    for (std::vector<Card*>::iterator it = this->hand->begin(); it != this->hand->end(); it++)
    {
        if ((*it)->getCardType() == CardType::ACTION)
        {
            Action* action = dynamic_cast<Action*>(*it);
            if (action->getActionType() == ActionType::PARADE)
            {
                return true;
            }
        }
    }

    return false;
}