#include <stdio.h>

// Print input, one word per line.
main()
{
  int c;
  while((c = getchar()) != EOF){
    if(c != ' '){
      putchar(c);
    }else{
      putchar('\n');
    }
  }
}
