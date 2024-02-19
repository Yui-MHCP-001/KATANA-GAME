#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

enum class CharacterType
{
    HANZO,
    USHIWAKA,
    CHIYOME,
    HIDEYOSHI,
    GINCHIYO,
    GOEMON,
    NOBUNAGA,
    TOMOE,
    IEYASU,
    BENKEI,
    MUSASHI,
    KOJIRO
};

class Character
{
private:
    CharacterType type;
    int maxHP;

public:
    Character(CharacterType type, int maxHP);
    CharacterType getCharacterType() const;
    std::string getCharacterName() const;
    int getMaxHP() const;
};

#endif // CHARACTER_H
