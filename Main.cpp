/***************************
Project 
Allan Vang & Mail Lee Lee


***************************/

#include "Character.h"
#include "MenuOptions.h"
#include "ValidInputs.h"
#include "StartGame.h"
#include "BTNODE.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <limits>


using namespace std;




int main()
{
    char quitGame = 'n'; //quits game if quit = 'y';
    displayMenu();//Displays Game Menu
    
    while(quitGame != 'y')
    {
        int menuChoice = validMenuOption(1, 4); //valid inputs from 1 -4
        char playAgain;

        switch (menuChoice)
        {
        case 1: // PLAY THE GAME
            // Discards current input
            cin.ignore(numeric_limits <streamsize>::max(), '\n');
            startGame(); //Starts the game
            
            cout << "\nPlay again? (y/n)\n";
            playAgain = validCharacter();
            if (playAgain == 'y')
            {
                clearScreen();
                displayMenu();
            }
            else if (playAgain == 'n')
            {
                quitGame = 'y';
                cout << "Exiting Game\n";
            }
            
            break;
        case 2: //SEE SETTINGS
            clearScreen();
            gameSettings();

            displayMenu();//Displays Game Menu
            break;
        case 3: //SEE CREDITS
            clearScreen();
            gameCredits();
            displayMenu();
            break;
        case 4: //QUIT GAME
            clearScreen();
            quitGame = 'y';
            cout << "Exiting Game\n";
            break;
        }

    
    }
  
  


    return 0;

}


