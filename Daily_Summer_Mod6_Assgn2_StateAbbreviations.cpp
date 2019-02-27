// Daily_Summer_Mod6_Assgn2_StateAbbreviations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <iterator>

int main()
{
	// Create a map and iterator, mapping the state's full name and gov to the state's abbreviation.
	std::string abbrev;
	std::string state;
	std::map<std::string, std::string> stateMap;
	std::map<std::string, std::string>::const_iterator it;

	// Open and read from file containing state abbreviation, name, and gov information
	std::ifstream myfile;
	myfile.open("StateInitials.txt", std::ios::in);
	if (!myfile.is_open()) {
		std::cout << "File is not open." << std::endl;
	}
	while (getline(myfile, abbrev, ',')) {
		std::getline(myfile, state);
		stateMap[abbrev] = state;
	}

	// Get initials from user and make sure they are all caps.
	char c;
	std::string initials;
	int i = 0;
	int again = 1;
	std::cout << "Please enter the postal initials for any U.S. state: ";
	
	while(again == 1) {
		std::cin.get(c); // get one character at a time
		
		if (c != '\n' && i < 2) { // if it's lowercase, change to upper and store in string initials
			if (islower(c)) {
				c = toupper(c);
			}
			initials += c;
			again = 1;
			i++;
		}
		else if (c == '\n' && i == 2) { // If the user enetered exactly 2 letters, you're done and exit the loop.
			again = 0;
		}
		else if (c == '\n' && i < 2) { // To keep people from entering less than two letters
			initials.clear();
			i = 0;
			std::cout << "You must enter two letters. Try again: ";
			again = 1;
		}
		else if (c != '\n' && i == 2) { // To keep people from entering more than two lettes
			initials.clear();
			i = 0;
			while ((getchar()) != '\n');
			std::cout << "You must enter two letters. Try again: ";
			again = 1;
		}
	}

	it = stateMap.begin();
	if (stateMap.find(initials) != stateMap.end()) {
		it = stateMap.find(initials);
		std::cout << it->second << std::endl;
	}
	else std::cout << initials << "aren't the initials of a state. Sorry." << std::endl;

	std::cout << "Press any key to continue...";
	while ((getchar()) != '\n');
	return 0;
}