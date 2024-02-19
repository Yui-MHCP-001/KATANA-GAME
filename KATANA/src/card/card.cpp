#include "card.h"

Card::Card(CardType type) : type(type) {}

CardType Card::getCardType() const
{
    return this->type;
}

std::string Card::getCardTypeName() const
{
    switch (this->type)
    {
    case CardType::ACTION:
        return "Action";
    case CardType::PERMANENT:
        return "Permanent";
    case CardType::WEAPON:
        return "Arme";
    default:
        return "Inconnu";
    }
}

std::string Card::getCardName()
{
    return "Inconnu";
}