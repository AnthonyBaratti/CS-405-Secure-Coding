//////////////////////////////////////////////////////////////////////////////////////////////////////
// Anthony J. Baratti
// CS-405 Secure Coding
// Professor R. Kraya
// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
// The purpose of this program is to restrict user input to 20 characters
// to prevent buffer overflow.
// *NOTE the characters are restricted to 20, but this includes
//  the null-terminated, so only 19 characters are saved. This can be changed
//  by increasing MAX_USER_INPUT to 21
///////////////////////////////////////////////////////////////////////////////////////////////////////

#define MAX_USER_INPUT 20 //Maximum Characters allowed for user input

#include <iomanip>
#include <iostream>
#include <string>
#include <limits>

int main()
{
	std::cout << "Buffer Overflow Example" << std::endl;

  // TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
  //  even though it is a constant and the compiler buffer overflow checks are on.
  //  You need to modify this method to prevent buffer overflow without changing the account_number
  //  variable, and its position in the declaration. It must always be directly before the variable used for input.
  //  You must notify the user if they entered too much data.

  const std::string account_number = "CharlieBrown42";


  /////////////////////////////////////////////////
  // REF:
  // GeeksforGeeks. (2025). Getline string in C++. Geeksforgeeks.org.
  // https://www.geeksforgeeks.org/getline-string-c/
  //
  // This reference shows the use of limiting character input and automatically
  // truncating it to the limit. However, this is MAX_USER_INPUT -1 
  // (for the null-terminated character). If we truly want the user to
  // be able to enter a 20 char string, we need to set the value to 21.
  //////////////////////////////////////////////////

  char user_input[MAX_USER_INPUT]; //Limits user input to 20 characters
  std::cout << "Enter a value: ";

  //gets user input but restricts characters to MAX_USER_INPUT value and truncates the rest
  std::cin.getline(user_input, MAX_USER_INPUT);

  /////////////////////////////////////////////////
  // REF:
  // Alex, (2025, Jan 29). 9.5 -- std::cin and handling invalid input. LearnC++. 
  // https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
  //
  // This reference shows how to determine if the buffer was filled,
  // allowing us to produce error/message handling for the system or user.
  // Clears the input flag and buffer.
  /////////////////////////////////////////////////

  if (!std::cin) { //If a previous extraction failed (in the case of an overflow prevention)
	  //Inform user of truncation
	  std::cout << std::endl << "ATTENTION!" << std::endl;
	  std::cout << "Buffer overflow occured, input trimmed to 19 characters" << std::endl; //19 because null-terminated character.

	  //Handles the failure by clearing the input and resetting flag
	  std::cin.clear();

	  //Clears the rest of the buffer to maximum string length
	  //(rather than a specific set number such as 10,000)
	  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }


  std::cout << "You entered: " << user_input << std::endl;
  std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
