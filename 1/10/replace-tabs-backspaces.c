#include <stdio.h>

/* use 'z' instead of EOF so we hava a way
   of exiting from user input in terminal */
#define EXIT_CONDITION 'z'

/* replace tabs, backspaces and backslahes with \t, \b, \\ */
main()
{
  int input, output;
  while((input = getchar()) != EXIT_CONDITION){
    if(input == '\t'){
      putchar('\\');
      //output = 't';
      putchar('t');
    }else if(input == '\b'){
      putchar('\\');
      //output = 'b';
      putchar('b');
    }else if(input == '\\'){
      putchar('\\');
      //output = '\\';
      putchar('\\');
    }else{
      //output = input;
      putchar(input);
    }
    //putchar(output);
    
  }
}
