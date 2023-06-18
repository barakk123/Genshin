// Barak Daniel 205436959
// Progject name: Genshin
// Date: 06/01/2023

#ifndef EpicCharacter_H
#define EpicCharacter_H

#include "Character.h"

class EpicCharacter : public Character
{
public:
    EpicCharacter(char* name, int stars, type element, weaponType weapon, char* location, char* equippedWeapon) :
        Character(name, stars, element, weapon, location, equippedWeapon) {};
    EpicCharacter();
    virtual void printCharacter()
    {
        std::cout << "Epic Character!" << std::endl;
        Character::printCharacter();
    };
    ~EpicCharacter();
};


#endif