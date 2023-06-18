// Barak Daniel 205436959
// Progject name: Genshin
// Date: 06/01/2023
// To compile: g++ -o Main main.cpp Player.cpp Character.cpp LegendaryCharacter.cpp EpicCharacter.cpp
// To run: ./Main

// Updated: 15/06/2023 - I  only changed the comments up here to upload it as an example of a small C++ project that I made about half a year ago.
// Everything found here reflected my knowledge in the first year of the degree and of course does not reflect my current skills or knowledge
//*****-----------------------------------*****


#include "Player.h"
#include <iostream>
#include <cstring>
#include <string>
#include <map>

int numOfActiveCharacters=0;
void menu();
void addCharacter(Player* player);
void editWeapon(Player* player);
void editActiveTeam(Player* player);
void evaluateTeam(Player* player);
int main()
{
    char name[20];
    std::cout << "Enter your name: ";
    std::cin.getline(name, 20);
  
    Player* player = new Player(name);
    if(player->getUserName() == NULL)
    {
        std::cout << "Error: Player name is NULL" << std::endl;
        return 0;
    }
    
    while (true)
    {
        int choice;
        menu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            //add a character to the dataCharacters
            addCharacter(player);

            break;
        case 2:
            //edit weapon to character (by name)
            editWeapon(player);
            break;
        case 3:
            //edit active team (user choose who to swap) then print the bonuses of the team
            editActiveTeam(player);
            numOfActiveCharacters++;
            if(numOfActiveCharacters>=4)
            {
                numOfActiveCharacters=4;
            }
            std::cout << std::endl;
            evaluateTeam(player);
            break;
        case 4:
            //evaluate team
            evaluateTeam(player);
            break;
        case 5:
            //exit
            std::cout << "Goodbye!" << std::endl;
            delete player;
            return 0;
            
        /*case 6: //To make life easier just remove the /* here and /* from the menu() function
            //print player
            player->printPlayer();
            break;
        case 7:
            //print data characters
            player->printDataCharacters();
            break;
        case 8:
            //print active characters
            player->printActiveCharacters();
            break;*/
        default:
            std::cout << "Invalid choice!" << std::endl;
            break;
        }
    }
}

void menu()
{
    std::cout << std::endl;
    std::cout << "Menu: " << std::endl;
    std::cout << "1. Add a character to the dataCharacters" << std::endl;
    std::cout << "2. Edit weapon to character (by name)" << std::endl;
    std::cout << "3. Edit active team (user choose who to swap)" << std::endl;
    std::cout << "4. Evaluate team" << std::endl;
    std::cout << "5. Exit" << std::endl;
    /*std::cout << "6. Print player" << std::endl;
    std::cout << "7. Print data characters" << std::endl;
    std::cout << "8. Print active characters" << std::endl;*/
}

void addCharacter(Player* player)
{
    char charName[20];
    std::cout << "Enter the name of the character: ";
    std::cin.getline(charName, 20);

    int rarity;
    std::cout << "Enter the rarity of the character: ";
    std::cin >> rarity;
    std::cin.ignore();

    type type;
    int typeChoice;
    std::cout << "Enter the element of the character: \n";
    std::cout << "1. Anemo" << std::endl;
    std::cout << "2. Pyro" << std::endl;
    std::cout << "3. Cryo" << std::endl;
    std::cout << "4. Hydro" << std::endl;
    std::cout << "5. Electro" << std::endl;
    std::cout << "6. Geo" << std::endl;
    std::cout << "7. Dendro" << std::endl;
    std::cin >> typeChoice;
    std::cin.ignore();
    switch (typeChoice)
    {
        case 1:
            type = type::Anemo;
            break;
        case 2:
            type = type::Pyro;
            break;
        case 3:
            type = type::Cryo;
            break;
        case 4:
            type = type::Hydro;
            break;
        case 5:
            type = type::Electro;
            break;
        case 6:
            type = type::Geo;
            break;
        case 7:
            type = type::Dendro;
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
            break;
    }

    weaponType weaponType;
    int weaponTypeChoice;
    std::cout << "Enter the weapon type of the character: \n";
    std::cout << "1. Sword" << std::endl;
    std::cout << "2. Polearm" << std::endl;
    std::cout << "3. Catalyst" << std::endl;
    std::cout << "4. Claymore" << std::endl;
    std::cout << "5. Bow" << std::endl;
    std::cin >> weaponTypeChoice;
    std::cin.ignore();
    switch (weaponTypeChoice)
    {
        case 1:
            weaponType = weaponType::Sword;
            break;
        case 2:
            weaponType = weaponType::Polearm;
            break;
        case 3:
            weaponType = weaponType::Catalyst;
            break;
        case 4:
            weaponType = weaponType::Claymore;
            break;
        case 5: 
            weaponType = weaponType::Bow;
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
            break;
    }

    char location[40];
    std::cout << "Enter the location of the character: ";
    std::cin.getline(location, 40);

    char weaponName[50];
    std::cout << "Enter the name of the weapon: ";
    std::cin.getline(weaponName, 50);
    
    if(rarity == 5)
    {
        char signatureWeaponName[50];
        std::cout << "Enter the name of the signature weapon: ";
        std::cin.getline(signatureWeaponName, 50);
        Character* temp = new LegendaryCharacter(charName, rarity, type, weaponType, location, weaponName, signatureWeaponName);
        player->setDataCharacter(temp);
    }
    else
    {
        Character* temp = new EpicCharacter(charName, rarity, type, weaponType, location ,weaponName);
        player->setDataCharacter(temp);
    }
}

void editWeapon(Player* player)
{
    if(player->getNumOfDataCharacters() == 0)
    {
        std::cout << "No characters in data!" << std::endl;
        return;
    }
    char charName[40];
    std::cout << "Enter the name of the character: ";
    std::cin.getline(charName, 40);

    for (int i = 0; i < player->getNumOfDataCharacters(); i++)
    {
        if (strcmp(charName, player->getDataCharacter(i)->getName()) == 0)
        {
            std::cout << "Character name: " << player->getDataCharacter(i)->getName() << std::endl;
            std::cout << "Equipped Weapon: " << player->getDataCharacter(i)->getEquippedWeapon() << std::endl;
            char weaponName[50];
            std::cout << "Enter new name: ";
            std::cin.getline(weaponName, 50);
            player->getDataCharacter(i)->setEquippedWeapon(weaponName);
            std::cout << std::endl;
            std::cout << "Weapon name successfully changed to: " << player->getDataCharacter(i)->getEquippedWeapon() << std::endl; 
        }
    }
}

void editActiveTeam(Player* player)
{
    if(player->getNumOfDataCharacters() == 0)
    {
        std::cout << "No characters in data!" << std::endl;
        return;
    }
    std::cout << "Active Team:" << std::endl;
    
    for (int i = 0; i < 4; i++)
    {
        if(player->getActiveCharacter(i) != NULL)
        {
            std::cout << i + 1 << ". " << player->getActiveCharacterName(i) << std::endl;
        }
        else
        {
            std::cout << i + 1 << ". " << "Empty" << std::endl;
        }
    }

    std::cout << std::endl;
    int choice;
    std::cout << "Choose a character from team: ";
    std::cin >> choice;
    std::cin.ignore();
    if(player->getActiveCharacter(choice-1) != NULL)
    {
        std::cout << "You chose to swap character "<< player->getActiveCharacterName(choice-1) << std::endl;
    }
    else
    {
        std::cout << "You chose to add a character in an empty spot" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Data Characters:" << std::endl;
    
    
    for (int k = 0; k < player->getNumOfDataCharacters(); k++)
    {
        std::cout << k + 1 << ". " << player->getDataCharacter(k)->getName() << std::endl;
    }

    std::cout << std::endl;
    int choice2;
    std::cout << "Choose a character from data: ";
    std::cin >> choice2;
    std::cin.ignore();
    if(player->getDataCharacter(choice2-1) == NULL)
    {
        std::cout << "Invalid choice!" << std::endl;
        
    }
    Character* character1 = player->getDataCharacter(choice2-1);
    player->setActiveCharacter(character1, choice-1);
    std::cout << "You chose character " << player->getDataCharacter(choice2-1)->getName() << " from database" << std::endl;
    std::cout << "Changes successfully saved" << std::endl;   
}

void evaluateTeam(Player* player)
{ 
    //prints each character name (in the team) and the sentence that describes the weapon type.
    if(player->printActiveCharactersEvaluate()==1)
    {
        return;
    }
    std::cout << std::endl;

    //check if there is a signature weapon equipped on any of the characters in the team.
    for (int i = 0; i < 4; i++)
    {
        if (player->getActiveCharacter(i) != NULL)
        {
            if(player->getActiveCharacter(i)->getStars() == 5)
            {
                if (strcmp(player->getActiveCharacter(i)->getEquippedWeapon(), player->getActiveCharacter(i)->getEquippedWeapon2()) == 0)//here we actually check if the signature weapon is equipped
                {
                    std::cout << player->getActiveCharacter(i)->getName() << " has a Signature Weapon equipped! Double damage!" << std::endl;
                }
            }
        }
    }
    std::cout << std::endl;

    //check for same element characters
    std::map<const char*, int> my_map = {
        
    };

    for(int i = 0; i < numOfActiveCharacters; i++)
    {
        if(player->getActiveCharacter(i) != NULL)
        {
            const char* element3 = player->getActiveCharacter(i)->getElement2();
            //first check if the element is in the map
            if(my_map.find(element3) != my_map.end())
            {
                //if it is in the map, increment the value
                my_map[element3]++;
            }
            else
            {
                //if it is not in the map, add it to the map
                my_map[element3] = 1;
            }
        }
    }
    //now we have a map with the elements and the number of characters of that element
    //we can iterate through the map and check if the value is greater than 1
    for (auto it = my_map.begin(); it != my_map.end(); ++it)
    {
        if(it->second > 1)
        {
            std::cout << it->second << " characters are " << it->first << " elements:" << std::endl;
            std::cout << "adding " << (it->second ) * 10 << "% " << it->first << " power" << std::endl;
        }
    }
    std::cout << std::endl;

    //check for same location characters
    std::map<std::string, int> my_map_location = {
        
    };

    for(int i = 0; i < numOfActiveCharacters; i++)
    {
        if(player->getActiveCharacter(i) != NULL)
        {
            std::string location3 = player->getActiveCharacter(i)->getLocation();
            //first check if the element is in the map
            if(my_map_location.find(location3) != my_map_location.end())
            {
                //if it is in the map, increment the value
                my_map_location[location3]++;
            }
            else
            {
                //if it is not in the map, add it to the map
                my_map_location[location3] = 1;
            }

        }
    }
    //now we have a map with the locations and the number of characters of that location
    //we can iterate through the map and check if the value is greater than 1
    for (auto it2 = my_map_location.begin(); it2 != my_map_location.end(); ++it2)
    {
        if(it2->second > 1)
        {
            std::cout << it2->second << " characters from the same location: " << it2->first<< std::endl;
            std::cout << "adding " << (it2->second ) * 10 << "%c coordination" << std::endl;
        }
    }
    std::cout << std::endl;

    //check for elemental reactions
    if (numOfActiveCharacters > 1)
    {
        int counter0 = 0;
        int counter1 = 0;
        int counter2 = 0;
        int counter3 = 0;
        int counter4 = 0;
        int counter5 = 0;
        int counter6 = 0;
        std::cout << std::endl
        << "Elemental Reactions:" << std::endl;
        for (int i = 0; i < numOfActiveCharacters; i++)
        {
            if(player->getActiveCharacter(i)->getElement() == 0)
                counter0++;
            if(player->getActiveCharacter(i)->getElement() == 1)
                counter1++;
            if(player->getActiveCharacter(i)->getElement() == 2)
                counter2++;
            if(player->getActiveCharacter(i)->getElement() == 3)
                counter3++;
            if(player->getActiveCharacter(i)->getElement() == 4)
                counter4++;
            if(player->getActiveCharacter(i)->getElement() == 5)
                counter5++;
            if(player->getActiveCharacter(i)->getElement() == 6)
                counter6++;
        }
                if (counter0 > 0 && counter2 > 0)
                    std::cout << "- Blizzard" << std::endl;
                if (counter1 > 0 && counter6 > 0)
                    std::cout << "- Burn" << std::endl;
                if (counter5 > 0 && (counter1 > 0 || counter2 > 0 || counter3 > 0 || counter4 > 0))
                    std::cout << "- Crystalize" << std::endl;
                if (counter5 > 0 && counter0 > 0)
                    std::cout << "- Dust" << std::endl;
                if (counter3 > 0 && counter4 > 0)
                    std::cout << "- Electro-Charged" << std::endl;
                if (counter2 > 0 && counter3 > 0)
                    std::cout << "- Frozen" << std::endl;
                if (counter5 > 0 && counter1 > 0)
                    std::cout << "- Magma" << std::endl;
                if (counter1 > 0 && counter2 > 0)
                    std::cout << "- Melt" << std::endl;
                if (counter5 > 0 && counter3 > 0)
                    std::cout << "- Mud" << std::endl;
                if (counter1 > 0 && counter4 > 0)
                    std::cout << "- Overloaded" << std::endl;
                if (counter3 > 0 && counter6 > 0)
                    std::cout << "- Poison" << std::endl;
                if (counter5 > 0 && counter2 > 0)
                    std::cout << "- Shatter" << std::endl;
                if (counter2 > 0 && counter4 > 0)
                    std::cout << "- Superconduct" << std::endl;
                if (counter0 > 0 && (counter1 > 0 || counter2 > 0 || counter3 > 0 || counter4 > 0))
                    std::cout << "- Swirl" << std::endl;
                if (counter5 > 0 && counter6 > 0)
                    std::cout << "- Thorn" << std::endl;
                if (counter1 > 0 && counter3 > 0)
                    std::cout << "- Vaporize" << std::endl;
            }
}   