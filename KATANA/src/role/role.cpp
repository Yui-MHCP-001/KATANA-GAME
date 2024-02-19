#include "role.h"

Role::Role(RoleType type, int level) : type(type), level(level) {}

RoleType Role::getRoleType() const
{
    return this->type;
}

std::string Role::getRoleName() const
{
    switch (this->type)
    {
    case RoleType::SHOGUN:
        return "Shogun";
    case RoleType::SAMURAI:
        return "Samurai";
    case RoleType::NINJA:
        return "Ninja lv" + std::to_string(this->level);
    case RoleType::RONIN:
        return "Ronin";
    default:
        return "Inconnu";
    }
}