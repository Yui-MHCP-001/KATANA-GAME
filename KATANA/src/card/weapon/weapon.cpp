#include "weapon.h"

Weapon::Weapon(WeaponType type, int damage, int range) : Card(CardType::WEAPON), type(type), damage(damage), range(range) {}

WeaponType Weapon::getWeaponType() const
{
    return this->type;
}

std::string Weapon::getCardName()
{
    switch (this->type)
    {
    case WeaponType::NODACHI:
        return "Nodachi";
    case WeaponType::NAGINATA:
        return "Naginata";
    case WeaponType::NAGAYARI:
        return "Nagayari";
    case WeaponType::TANEGASHIMA:
        return "Tanegashima";
    case WeaponType::DAIKYU:
        return "Daikyu";
    case WeaponType::BO:
        return "Bo";
    case WeaponType::KUSARIGAMA:
        return "Kusarigama";
    case WeaponType::KATANA:
        return "Katana";
    case WeaponType::SHURIKEN:
        return "Shuriken";
    case WeaponType::KANABO:
        return "Kanabo";
    case WeaponType::BOKKEN:
        return "Bokken";
    case WeaponType::KISERU:
        return "Kiseru";
    case WeaponType::WAKIZASHI:
        return "Wakizashi";
    default:
        return "Inconnu";
    }
}

int Weapon::getDamage() const
{
    return this->damage;
}

int Weapon::getRange() const
{
    return this->range;
}