#ifndef ACTION_H
#define ACTION_H

#include "../card.h"

enum class ActionType
{
    CRI_DE_GUERRE,
    DAIMYO,
    DIVERSION,
    GEISHA,
    MEDITATION,
    PARADE,
    CEREMONIE_DU_THE,
    JU_JITSU
};

class Action : public Card {
private:
    ActionType type;

public:
    Action(ActionType type);
    ActionType getActionType() const;
    std::string getCardName() override;
};

#endif // ACTION_H