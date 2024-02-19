#include "character.h"

Character::Character(CharacterType type, int maxHP) : type(type), maxHP(maxHP) {}

CharacterType Character::getCharacterType() const
{
    return this->type;
}

std::string Character::getCharacterName() const
{
    switch (this->type)
    {
    case CharacterType::HANZO:
        return "HANZO";
    case CharacterType::USHIWAKA:
        return "USHIWAKA";
    case CharacterType::CHIYOME:
        return "CHIYOME";
    case CharacterType::HIDEYOSHI:
        return "HIDEYOSHI";
    case CharacterType::GINCHIYO:
        return "GINCHIYO";
    case CharacterType::GOEMON:
        return "GOEMON";
    case CharacterType::NOBUNAGA:
        return "NOBUNAGA";
    case CharacterType::TOMOE:
        return "TOMOE";
    case CharacterType::IEYASU:
        return "IEYASU";
    case CharacterType::BENKEI:
        return "BENKEI";
    case CharacterType::MUSASHI:
        return "MUSASHI";
    case CharacterType::KOJIRO:
        return "KOJIRO";
    default:
        return "Inconnu";
    }
}

int Character::getMaxHP() const
{
    return this->maxHP;
}