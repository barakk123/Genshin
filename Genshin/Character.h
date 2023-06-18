// Barak Daniel 205436959
// Progject name: Genshin
// Date: 06/01/2023

#ifndef Character_H
#define Character_H

#include <iostream>
#include <cstring>

enum type
{
    Anemo,Pyro,Cryo,Hydro,Electro,Geo,Dendro
};

enum weaponType
{
    Sword,Polearm,Catalyst,Claymore,Bow
};

class Character
{
private:
protected:
    char* name;
    char* location;
    type element;
    weaponType weapon;
    char* equippedWeapon;
    int stars;

public:
    Character(char* name, int stars, type element, weaponType weapon, char* location, char* equippedWeapon);
    Character();
    virtual ~Character();
    char* setNameNull();
    char* getName();
    std::string getLocation();
    type getElement();
    const char* getElement2();
    weaponType getWeapon();
    char* getEquippedWeapon();
    virtual char* getEquippedWeapon2();
    void setEquippedWeapon(char* equippedWeapon);
    int getStars();
    virtual void printCharacter() ;
    virtual int Attack();
};

#endif