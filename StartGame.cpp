#include "StartGame.h"
#include "MenuOptions.h"
#include "Character.h"
#include "ValidInputs.h"
#include "BTNODE.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <fstream>


using namespace std;

void startGame()
{	
    clearScreen();
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

        int charGender = validuserNum(); //Input gender type 

        switch (charGender)
        {
        case 1: 
            myGender = "Male";
        case 2:
            myGender = "Female";
        default://defaults to male if errors occur
            myGender = "Male";

        }

        cout << "\n\nSelect your species: \n"
            << "--------------------\n\n";

        cout << "1. Human" << endl
             << "2. Elf" << endl
             << "3. Dwarf" << endl
             << "4. Vampire" << endl
             << "5. Werewolf" << endl << endl
             << "(Enter number 1-5)\n" << endl;

        int selectSpecies = validSpecies(1,5);
        
        switch (selectSpecies)
        {
            case 1:
                mySpecies = "Human";
                break;
            case 2:
                mySpecies = "Elf";
                break;
            case 3:
                mySpecies = "Dwarf";
                break;
            case 4:
                mySpecies = "Vampire";
                break;
            case 5:
                mySpecies = "Werewolf";
                break;
            default: //defaults to human if errors occur
                mySpecies = "Human";
                break;
        }

        Player.setCharacter(myName, myGender, mySpecies);

        cout << "\n\nYour Character:\n\n"
            << Player.getName() << ", "
            << Player.getGender() << ", "
            << Player.getSpecies() << endl;

        cout << "\nConfirm your Character? (y/n)\n";

        char confirmChar = validCharacter();
        
            
        if (confirmChar == 'y')
        {
            test = 'y';
        }
        else if (confirmChar == 'n')
        {
            clearScreen();
            test = 'n';
            cin.clear();//discard the input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (test == 'n');

    BTNODE game;
    game.buildFlowchart(); //builds binary tree

    /*******************************************
    TEST that can print nodes in order
    cout << "In Order Traversal: ";
    game.printInOrder(game.root);
    *******************************************/

    clearScreen();//Clears screen of past text

    ///////////Queen Request for aid///////////
    traverseGame(game.root);

    int usefireStone = 0;
    int useshardBark = 0;
    int stoneStillness = 0;

    int mirelingsEncounter = 0;

    int helpQueen = validuserNum();
    switch (helpQueen)//Queen request for aid
    {
        case 1://Accept queen's request
            clearScreen();
            traverseGame(game.root->left);// Face off enemy serpents
            usefireStone = validuserNum(); 
            break;
        case 2://Don't help queen
            clearScreen();
            traverseGame(game.root->right);//Face off enemy enemy thornbeasts
            useshardBark = validuserNum(); 
            break;
        default:
            cout << "System error, exiting game.\n";
                return; //exit function
    }

    /////////////Accept Queen's Request////////////////
    if (usefireStone == 1)//Used fire stone to defeat serpents
    {
        clearScreen();
        traverseGame(game.root->left->left);
        int helpSyphls = validuserNum();

        switch (helpSyphls)//Syphls request water
        {

            case 1:
                clearScreen();//Used water stone
                traverseGame(game.root->left->left->left);//Best Ending A
                break;
            case 2:
                clearScreen();//don't use water stone
                traverseGame(game.root->left->left->right);//Neutral Ending B
                break;
            default:
                cout << "System error, exiting game.\n";
                return; //exit function


        }
    }
    
    if (usefireStone == 2) //Did not use fire stone to defeat serpent
    {
        clearScreen();
        traverseGame(game.root->left->right); //Syphls request aid
        int helpSyphls = validuserNum();

        switch (helpSyphls)//Syphls request water
        {
            case 1:
                clearScreen();//Used water stone
                traverseGame(game.root->left->right->left); //Neutral Ending B
                break;
            case 2:
                clearScreen();//don't use water stone
                traverseGame(game.root->left->right->right);//Bad Ending A
                break;
            default:
                cout << "System error, exiting game.\n";
                return; //exit function

        }
    }

    /////////////////Deny Queen's Request//////////////////
  
    if (useshardBark == 1) //Used Shard of Bark
    {
        clearScreen();
        traverseGame(game.root->right->left);
        mirelingsEncounter = validuserNum();//Encountered mirelings

        switch (mirelingsEncounter)
        {
            case 1:
                clearScreen();//Used Stone of Stillness
                traverseGame(game.root->right->left->left);//Best Ending B
                break;
            case 2:
                clearScreen();//Sip Water of Flow
                traverseGame(game.root->right->left->right);//Neutral Ending B
                break;
            default:
                cout << "System error, exiting game.\n";
                return; //exit function
        }
    }

    if (useshardBark == 2)//Used Dew of Roots
    {
        clearScreen();
        traverseGame(game.root->right->right);
        mirelingsEncounter = validuserNum();//Encountered mirelings
        switch (mirelingsEncounter)
        {
            case 1:
                clearScreen();;//Used Stone of Stillness
                traverseGame(game.root->right->right->left);//Neutral Ending B
                break;
            case 2:
                clearScreen();//Sip Water of Flow
                traverseGame(game.root->right->right->right);//Worst Ending A
                break;
            default:
                cout << "System error, exiting game.\n";
                return; //exit function
        }
    }


}

void traverseGame(BTNODE* node)
{
    if (node == nullptr)
    {
        return; // if node is empty, leave
    }

    if (node->action) //if there is an action function
    {
        node->action(); //run it
    }
}



//Function that reads script.txt
void scriptRead(int scriptStart, int scriptEnd)
{

    ifstream file("script.txt"); //Reads from script.txt

    if (!file)
    {
        cout << "File could not be open.\n";
       
    }
    int start = scriptStart;
    int end = scriptEnd;
    string line;

    //Read lines between start and end
    int lineNumber = 1; //starting point

    while (getline(file, line))
    {
        //If lineNumber is between starting  and ending lines, print
        if (lineNumber >= start && lineNumber <= end)
        {
            cout << line << endl;
        }
        lineNumber++;
    }

    file.close(); // close file

}

