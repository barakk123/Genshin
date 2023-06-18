// Barak Daniel 205436959
// Progject name: Genshin
// Date: 06/01/2023

#ifndef LegendaryCharacter_H
#define LegendaryCharacter_H

#include "Character.h"
#include <iostream>
#include <cstring>


class LegendaryCharacter : public Character
{
private:
    char* signatureWeapon;
public:
    LegendaryCharacter(char* name, int stars, type element, weaponType weapon, char* location, char* equippedWeapon, char* signatureWeapon) : Character(name, stars, element, weapon, location, equippedWeapon)
{
    this->signatureWeapon = new char[50];
    strcpy(this->signatureWeapon, signatureWeapon);
};
    LegendaryCharacter();
    ~LegendaryCharacter();
    char* getSignatureWeapon2();
    void setSignatureWeapon(char* signatureWeapon);
    virtual void printCharacter()
    {
        std::cout << "Legendary Character!" << std::endl;
        Character::printCharacter();
        std::cout << "Signature weapon: " << signatureWeapon << std::endl;
    };
    virtual char* getEquippedWeapon2()
    {
        return signatureWeapon;
    };

};

#endif