#ifndef PERMANENT_H
#define PERMANENT_H

#include "../card.h"

enum class PermanentType {
    ATTAQUE_RAPIDE,
    CODE_DU_BUSHIDO,
    ARMURE,
    CONCENTRATION
};

class Permanent : public Card {
private:
    PermanentType type;

public:
    Permanent(PermanentType type);
    PermanentType getPermanentType() const;
    std::string getCardName() override;
};

#endif // PERMANENT_H