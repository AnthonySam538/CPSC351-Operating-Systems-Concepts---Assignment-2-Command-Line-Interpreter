// cs351_assignment2_anthony_sam.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Anthony Sam 9/24/2020

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdlib.h>     /* system, NULL, EXIT_FAILURE */
#include <windows.h>

DWORD __stdcall executeCommand(LPVOID lpParameter)
{
    // synthesize the command together and execute it
    std::string command = ((std::string*)lpParameter)[0] + " " + ((std::string*)lpParameter)[1] + " " + ((std::string*)lpParameter)[2] + " " + ((std::string*)lpParameter)[3];
    system(&command[0]);

    // clear the array now that the command has been executed
    ((std::string*)lpParameter)[0] = "";
    ((std::string*)lpParameter)[1] = "";
    ((std::string*)lpParameter)[2] = "";
    ((std::string*)lpParameter)[3] = "";

    return 0;
}

int main()
{
    std::string userInput; // the user's input will be stored here
    std::string argument[] = {"", "", "", ""}; // the components of the user's input will be stored here
    char* pch; // used in the strtok() function
    short currentIndex; // used in filling out argument[]
    DWORD dwThreadId; // used in CreateProcess()

    std::cout << "Welcome to myShell!\n\n"; // display an introductory message

    while (true)
    {
        currentIndex = 0; // reset currentIndex

        //std::cout << "Current contents: \n" << argument[0] << std::endl << argument[1] << std::endl << argument[2] << std::endl << argument[3] << std::endl;

        std::cout << ">>> "; // signal the user that the program is ready for input
        std::getline(std::cin, userInput); // receive the user's input

        // fill the array with the user's input using the strtok() command
        pch = strtok(&userInput[0], " ");
        while (pch != nullptr)
        {
            argument[currentIndex] = pch;
            pch = strtok(nullptr, " ");
            ++currentIndex;
        }
        
        // use the user's input
        if (argument[0] == "exit" || argument[0] == "quit")
        {
            std::cout << "Now leaving myShell...";

            return 0;
        }
        else if (argument[0] == "dir" || argument[0] == "help" || argument[0] == "vol" || argument[0] == "path" || argument[0] == "tasklist" || argument[0] == "notepad" || argument[0] == "echo" || argument[0] == "color" || argument[0] == "ping")
        {
            CreateThread(
                NULL,            // default security attributes
                0,               // use default stack size
                executeCommand, // thread function name (If you want to see the function definition for executeCommand, scroll up)
                &argument,       // argument to thread function
                0,               // use default creation flags
                &dwThreadId);    // returns the thread identifier
        }
        else
            std::cout << argument[0] << " isn't a recognized command.\n";
    }
}
