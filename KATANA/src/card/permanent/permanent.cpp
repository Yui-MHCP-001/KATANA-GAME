#include "permanent.h"

Permanent::Permanent(PermanentType type) : Card(CardType::PERMANENT), type(type) {}

PermanentType Permanent::getPermanentType() const
{
    return this->type;
}

std::string Permanent::getCardName()
{
    switch (this->type)
    {
    case PermanentType::ATTAQUE_RAPIDE:
        return "Attaque rapide";
    case PermanentType::CODE_DU_BUSHIDO:
        return "Code du Bushido";
    case PermanentType::ARMURE:
        return "Armure";
    case PermanentType::CONCENTRATION:
        return "Concentration";
    default:
        return "Inconnu";
    }
}