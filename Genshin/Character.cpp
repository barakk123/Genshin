// Barak Daniel 205436959
// Progject name: Genshin
// Date: 06/01/2023

#include "Character.h"
#include <iostream>
#include <cstring>


Character::Character(char* name, int stars, type element, weaponType weapon, char* location, char* equippedWeapon)
{
    this->name = new char[20];
    strcpy(this->name, name);
    this->stars = stars;
    this->element = element;
    this->weapon = weapon;
    this->location = new char[40];
    strcpy(this->location, location);
    this->equippedWeapon = new char[50];
    strcpy(this->equippedWeapon, equippedWeapon);
}

Character::Character()
{
}

Character::~Character()
{
    delete[] name;
    delete[] location;
    delete[] equippedWeapon;
}

char* Character::getName()
{
    return name;
}

char* Character::setNameNull()
{
    this->name= NULL;
    return name;
}

std::string Character::getLocation()
{
    return location;
}

type Character::getElement()
{
    return element;
}

const char* Character::getElement2()
{
    if(element == 0)
        return "Anemo";
    else if(element == 1)
        return "Pyro";
    else if(element == 2)
        return "Cryo";
    else if(element == 3)
        return "Hydro";
    else if(element == 4)
        return "Electro";
    else if(element == 5)
        return "Geo";
    else if(element == 6)
        return "Dendro";
    else
        return "No element";
}

char* Character::getEquippedWeapon()
{
    return equippedWeapon;
}

char* Character::getEquippedWeapon2()
{
    return equippedWeapon;
}

int Character::getStars()
{
    return stars;
}

weaponType Character::getWeapon()
{
    return weapon;
}

void Character::setEquippedWeapon(char* equippedWeapon)
{
    this->equippedWeapon = new char[50];
    strcpy(this->equippedWeapon, equippedWeapon);
}

void Character::printCharacter()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Stars: " << stars << std::endl;
    if(element == 0)
        std::cout << "Element: Anemo(Wind)" << std::endl;
    else if(element == 1)
        std::cout << "Element: Pyro(Fire)" << std::endl;
    else if(element == 2)
        std::cout << "Element: Cryo(Frost)" << std::endl;
    else if(element == 3)
        std::cout << "Element: Hydro(Water)" << std::endl;
    else if(element == 4)
        std::cout << "Element: Electro(Common)" << std::endl;
    else if(element == 5)
        std::cout << "Element: Geo(Earth)" << std::endl;
    else if(element == 6)
        std::cout << "Element: Dendro(Nature)" << std::endl;

    if(weapon == 0)
        std::cout << "Weapon: Sword" << std::endl;
    else if(weapon == 1)
        std::cout << "Weapon: Polearm" << std::endl;
    else if(weapon == 2)
        std::cout << "Weapon: Catalyst" << std::endl;
    else if(weapon == 3)
        std::cout << "Weapon: Claymore" << std::endl;
    else if(weapon == 4)
        std::cout << "Weapon: Bow" << std::endl;
    std::cout << "Location: " << location << std::endl;
    std::cout << "EquippedWeapon: " << equippedWeapon << std::endl;
}

int Character::Attack()
{
    return 0;
}

