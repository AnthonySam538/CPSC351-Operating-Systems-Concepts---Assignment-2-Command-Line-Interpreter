# CPSC351 Operating Systems Concepts - Assignment 2: Command Line Interpreter
This shell supports the following commands:
* dir
* help
* vol
* path
* tracklist
* notepad
* echo
* color
* ping
* exit
* quit
When the user types in a command, a thread is created to execute it.

## Known issue(s):
The rest of the program doesn't wait for a thread to finish executing its command before proceeding.
