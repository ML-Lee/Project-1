/***************************
Project 
Allan Vang & Mail Lee Lee


***************************/

#include <iostream>
#include "Character.h"
#include <string>
#include <limits>

using namespace std;

int main()
{
    Character Player;
    string myName, myGender, mySpecies;


    cout << "Enter your name [16 max characters]: " << endl;
    getline(cin, myName);

    cout << "\n\nEnter your gender: " << endl;
    cout << "1. Male" << endl
         << "2. Female" << endl;

    cin >> myGender;


    cout << "\n\nSelect your species: \n"
        << "--------------------\n\n";
    
    cout << "1. Human" << endl
         << "2. Elf" << endl
         << "3. Dwarf" << endl
         << "4. Vampire" << endl
         << "5. Werewolf" << endl;

    cin >> mySpecies;

    Player.setCharacter(myName, myGender, mySpecies); 

    cout << "\n\nYour build:\n\n"
        << Player.getName() << ", "
        << Player.getGender() << ", "
        << Player.getSpecies() << endl; 
    


  

}

