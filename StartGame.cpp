#include "StartGame.h"
#include "MenuOptions.h"
#include "Character.h"
#include "ValidInputs.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

void startGame()
{	
    ///////////////CREATE A CHARACTER/////////////////
    char test;
    do { //Program loops if user does not confirm character

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

        cout << "\n\nYour Character:\n\n"
            << Player.getName() << ", "
            << Player.getGender() << ", "
            << Player.getSpecies() << endl;

        cout << "\nConfirm your Character? (y/n) or \"q\" to quit.\n";

        char confirmChar = validCharacter();
        
        if (confirmChar == 'q')
        {
            cout << "\nExiting Game\n";
            break;
        }
        else if (confirmChar == 'y')
        {
            test = 'y';
        }
        else
        {
            test = 'n';
            cin.clear();//discard the input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
      

    } while (test == 'n');

    
}

