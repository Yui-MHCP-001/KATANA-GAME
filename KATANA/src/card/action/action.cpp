#include "action.h"

Action::Action(ActionType type) : Card(CardType::ACTION), type(type) {}

ActionType Action::getActionType() const
{
    return this->type;
}

std::string Action::getCardName()
{
    switch (this->type)
    {
    case ActionType::CRI_DE_GUERRE:
        return "CRIDEGUERRE";
    case ActionType::DAIMYO:
        return "DAIMYO";
    case ActionType::DIVERSION:
        return "DIVERSION";
    case ActionType::GEISHA:
        return "GEISHA";
    case ActionType::MEDITATION:
        return "MEDITATION";
    case ActionType::PARADE:
        return "PARADE";
    case ActionType::CEREMONIE_DU_THE:
        return "CEREMONIEDUTHE";
    case ActionType::JU_JITSU:
        return "JUJITSU";
    default:
        return "Inconnu";
    }
}