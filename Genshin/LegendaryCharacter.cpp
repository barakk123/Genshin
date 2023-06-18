// Barak Daniel 205436959
// Progject name: Genshin
// Date: 06/01/2023

#include "LegendaryCharacter.h"
#include <iostream>
#include <string.h>

/*LegendaryCharacter::LegendaryCharacter(char* name, int stars, type element, weaponType weapon, char* location, char* equippedWeapon) : Character(name, stars, element, weapon, location, equippedWeapon)
{
    this->signatureWeapon = new char[50];
    strcpy(this->signatureWeapon, signatureWeapon);
}*/
LegendaryCharacter::LegendaryCharacter()
{
    signatureWeapon = new char[50];
    strcpy(signatureWeapon, "No signature weapon");
}

LegendaryCharacter::~LegendaryCharacter()
{
    delete[] signatureWeapon;
}

char* LegendaryCharacter::getSignatureWeapon2()
{
    return signatureWeapon;
}

void LegendaryCharacter::setSignatureWeapon(char* signatureWeapon)
{
    this->signatureWeapon = new char[50];
    strcpy(this->signatureWeapon, signatureWeapon);
}


