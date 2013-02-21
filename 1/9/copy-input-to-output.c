#include <stdio.h>

/* use 'z' instead of EOF so we have a way of
 exiting from user input in terminal */
#define EXIT_CONDITION 'z'

/* copy input to output, removing extra spaces */
main()
{
  int input, output, 
      previous; /* previous character read in */
  while((input = getchar()) != EXIT_CONDITION){
    if(previous != ' ' || input != ' '){
      putchar(input);
    }
    previous = input;
  }
}
