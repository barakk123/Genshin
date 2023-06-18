// Barak Daniel 205436959
// Progject name: Genshin
// Date: 06/01/2023


#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Character.h"
#include "LegendaryCharacter.h"
#include "EpicCharacter.h"


class Player
{
    private:
        char* userName;
        Character* activeCharacters[4];
        Character** dataCharacters;
        int numOfDataCharacters=0;
    public:
        Player(char* userName);
        ~Player();
        char* getUserName();
        void setActiveCharacter(Character* activeCharacter, int index);
        Character* getActiveCharacter(int index);
        char* getActiveCharacterName(int index);
        void setDataCharacter(Character* dataCharacter);
        Character* getDataCharacter(int index);
        Character* getDataCharacter();
        void printPlayer();
        void printDataCharacters();
        void printActiveCharacters();
        int printActiveCharactersEvaluate();
        void setNumOfDataCharacters(int numOfDataCharacters);
        int getNumOfDataCharacters();
        int addOneNumDataCharacters();
};
#endif 