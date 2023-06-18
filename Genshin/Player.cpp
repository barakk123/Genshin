// Barak Daniel 205436959
// Progject name: Genshin
// Date: 06/01/2023


#include "Player.h"
#include <iostream>
#include <cstring>


Player::Player(char* userName)
{
    this->userName = new char[20];
    strcpy(this->userName, userName);
    for(int i = 0; i < 4; i++)
    {
        activeCharacters[i] = NULL;
    }
    dataCharacters = new Character*[1];
    numOfDataCharacters = 0;
}

Player::~Player()
{
    delete[] userName;
    for(int i = 0; i < 4; i++)
    {
        delete activeCharacters[i];
    }
    delete[] dataCharacters;
}

char* Player::getUserName()
{
    return userName;
}

void Player::setActiveCharacter(Character* activeCharacter, int index)
{
    activeCharacters[index] = activeCharacter;
}

Character* Player::getActiveCharacter(int index)
{
    return activeCharacters[index];
}

char* Player::getActiveCharacterName(int index)
{
    return activeCharacters[index]->getName();
}

void Player::setDataCharacter(Character* dataCharacter)
{
    Character **newdatachars = new Character*[numOfDataCharacters+1];
    if(newdatachars == NULL)
    {
        std::cout << "Error: Memory allocation failed." << std::endl;
        exit(1);
    }
    for(int i = 0; i < numOfDataCharacters; i++)
    {
        newdatachars[i] = dataCharacters[i];
    }
    delete[] dataCharacters;
    dataCharacters = newdatachars;
    newdatachars[numOfDataCharacters] = dataCharacter;

    numOfDataCharacters++;
}

int Player::getNumOfDataCharacters()
{
    return numOfDataCharacters;
}

void Player::setNumOfDataCharacters(int numOfDataCharacters)
{
    this->numOfDataCharacters = numOfDataCharacters;
}

int Player::addOneNumDataCharacters()
{
    return numOfDataCharacters++;
}

Character* Player::getDataCharacter(int index)
{
    return dataCharacters[index];
}
Character* Player::getDataCharacter()
{
    return *dataCharacters;
}

void Player::printPlayer()
{
    std::cout << std::endl;
    std::cout << "Player: " << userName << std::endl;
    std::cout << "Active Characters: " << std::endl;
    std::cout << "------------------" << std::endl;

    if(activeCharacters[0]==NULL&&activeCharacters[1]==NULL&&activeCharacters[2]==NULL&&activeCharacters[3]==NULL)
    {
        std::cout << "No Characters yet." << std::endl;
        std::cout << std::endl;   
    }
    else
    {
        for(int i = 0; i < 4; i++)
        {
            if(activeCharacters[i] != NULL)
            {
                activeCharacters[i]->printCharacter();
                std::cout << std::endl;
            }
        }
    }
    std::cout << "Data Characters: " << std::endl;
    std::cout << "------------------" << std::endl;
    for(int i = 0; i < numOfDataCharacters; i++)
    {
        dataCharacters[i]->printCharacter();
        std::cout << std::endl;   
    }
}

void Player::printDataCharacters()
{
    std::cout << "Data Characters: " << std::endl;
    std::cout << "------------------" << std::endl;
    for(int i = 0; i < numOfDataCharacters; i++)
    {
        dataCharacters[i]->printCharacter();
        std::cout << std::endl;   
    }
}

void Player::printActiveCharacters()
{
    std::cout << std::endl;
    std::cout << "Active Characters: " << std::endl;
    std::cout << "------------------" << std::endl;

    if(activeCharacters[0]==NULL&&activeCharacters[1]==NULL&&activeCharacters[2]==NULL&&activeCharacters[3]==NULL)
    {
        std::cout << "No Characters yet." << std::endl;
        std::cout << std::endl;   
    }
    else
    {
        for(int i = 0; i < 4; i++)
        {
            if(activeCharacters[i] != NULL)
            {
                activeCharacters[i]->printCharacter();
                std::cout << std::endl;
            }
        }
    }
}

int Player::printActiveCharactersEvaluate()
{
    if(activeCharacters[0]==NULL&&activeCharacters[1]==NULL&&activeCharacters[2]==NULL&&activeCharacters[3]==NULL)
    {
        std::cout << "No Characters yet." << std::endl;
        std::cout << std::endl;  
        return 1; 
    }
    else
    {
        for(int i = 0; i < 4; i++)
        {
            if(activeCharacters[i] != NULL)
            {
                std::cout << activeCharacters[i]->getName() <<"";

                if(activeCharacters[i]->getWeapon() == 0)
                std::cout << " swing swiftly the sword" << std::endl;
                else if(activeCharacters[i]->getWeapon() == 1)
                std::cout << " agile with polearm" << std::endl;
                else if(activeCharacters[i]->getWeapon() == 2)
                std::cout << " cast spells with catalyst" << std::endl;
                else if(activeCharacters[i]->getWeapon() == 3)
                std::cout << " swing the heavy claymore" << std::endl;
                else if(activeCharacters[i]->getWeapon() == 4)
                std::cout << " shot from afar with the bow" << std::endl;
            }
        }
    }
    return 0;
}

