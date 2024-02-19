#ifndef WEAPON_H
#define WEAPON_H

#include "../card.h"

enum class WeaponType {
    NODACHI,
    NAGINATA,
    NAGAYARI,
    TANEGASHIMA,
    DAIKYU,
    BO,
    KUSARIGAMA,
    KATANA,
    SHURIKEN,
    KANABO,
    BOKKEN,
    KISERU,
    WAKIZASHI
};

class Weapon : public Card {
private:
    WeaponType type;
    int damage;
    int range;

public:
    Weapon(WeaponType type, int damage, int range);
    WeaponType getWeaponType() const;
    std::string getCardName() override;
    int getDamage() const;
    int getRange() const;
};

#endif // WEAPON_H