# CPP Bank System Management Project
## About The Project
Simple system that stores accounts details, which are:

-ID

-Name (First and Last).

-Balance.

It's only the admin mode so it's not a fully implementable system. It's only for practicing and educational purposes. Feel free to criticize my code.
## Libraries
Libraries used:

•	iostream

•	fstream

File streaming, used in importing/exporting files. “file.open()” “file.is_open()”,”file.close()”.

•	string.h

String manipulation. Used for storing full name during creating the account and also the constructor. “strcpy()”,”strcat()”

•	conio.h

To use getch(),

•	map

For using Standard Template Library (STL) map.

•	windows.h

Used in colors and repositioning menu functions.

## Files
Files included in this project are CMake/Make files and main project files like main.cpp ,account.cpp ,account.h.
account.h is the header file which includes the class, member variables and functions declarations.
account.cpp includes the body of all declared member functions.
main.cpp includes the main program and non-member functions.
## Functions
I'll split this section into two main parts
### Class Member Functions

setter(); get data from user to store it as an account in the system.

show_account(); show account details on screen.

modify(); to make changes into account details.

dep(int); deposit money into account balance.

draw(int); withdraw money from account ablance.

retacno(); to get account number/ID.
### Non-member Functions
getoxy(int,int); for menu placement.

textattr(int) for a colorful terminal screen.

create_account(); to create andd add the account in the map.

findandshowaccount(int); to find account in map based on ID number and display it.

printaccounts(); display all accounts.

addrecords(); import accounts into the map.

clearrecords(); clears the file.

programbegin(); the program loop+ the mainmenu.

