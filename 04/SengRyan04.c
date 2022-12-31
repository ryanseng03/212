/**
 * Program that collects user inputs for different data types (char, double). Inputs are then stored in seperate variables for text outputs/feedback.
 *
 * @author     Seng, Ryan
 * @assignment ICS 212 Assignment 5
 * @date       08 September 2022
 */

#include <stdio.h>
#include "getdouble.h"

int main(void){
  
  /* Collects user input/letter for the char data type.  */
  printf("Enter a letter and hit return: ");
  char letter1 = 'z';
  letter1 = getchar();
  printf("Your input was '%c' \n", letter1); // Format char using '%c'. "\n" indicates to go to the next line.

  getchar(); // Used to clear the command line to avoid errors.
  
  printf("Enter a second letter and hit return: ");
  char letter2 = 'a';
  letter2 = getchar();
  printf("Your second input was '%c' \n", letter2);

  getchar(); // Clear for the next input.
  
  /* Collection of a number in the double data type */
  printf("Enter a number and hit return: ");
  double number1 = 0.0;
  number1 = getdouble();
  printf("Your number was: %f \n", number1); // Format the double in order to print it out.
 

  printf("Enter a second number and hit return: ");
  double number2 = 0.0;
  number2 = getdouble();
  printf("Your second number was: %f \n", number2);
  
  return 0; // Use return 0 for the main function in order to signal the program's termination.
}
