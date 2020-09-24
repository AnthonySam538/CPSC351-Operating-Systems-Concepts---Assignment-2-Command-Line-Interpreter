// cs351_assignment2_anthony_sam.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Copyright (c) Anthony Sam 9/24/2020

#include <iostream>
#include <string>
#include <stdlib.h>     /* system, NULL, EXIT_FAILURE */

int main()
{
    std::string userInput;

    std::cout << "Welcome to myShell!\n\n";

    while (true)
    {
        std::cout << "Enter a command: ";
        std::getline(std::cin, userInput);
        system(&userInput[0]);
        if (userInput == "exit")
            return 0;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
