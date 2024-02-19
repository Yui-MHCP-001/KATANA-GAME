#ifndef CARD_H
#define CARD_H
 
#include <string>

enum class CardType
{
    ACTION,
    PERMANENT,
    WEAPON
};

class Card
{
private:
    CardType type;

public:
    Card(CardType type);
    CardType getCardType() const;
    std::string getCardTypeName() const;
    virtual std::string getCardName();
};

#endif // CARD_H