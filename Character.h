#pragma once
#include <string>
#include <iostream>

using namespace std;

class Character
{
private:
	string Name;
	string Gender;
	string Species;


public:
	Character(); //default constructor
	Character(string charName, string charGender, string charSpecies); //constructor
	void setCharacter(string &charName, string &charGender, string &charSpecies); //Setter Function

	//Accessors/Getter functions
	string getName();
	string getGender();
	string getSpecies();

};
