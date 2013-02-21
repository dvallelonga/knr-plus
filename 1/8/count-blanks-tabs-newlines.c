#include <stdio.h>

/* count blanks, tabs and new lines */
main()
{
  int c, nb = 0, nt = 0, nl = 0;
  printf("%s\n", "Count number of blanks, tabs and new lines until a 'z' charecter is entered");

  //while((c = getchar()) != EOF){
  while((c = getchar()) != 'z'){
    if(c == ' '){
      ++nb;
    }else if(c == '\t'){
      ++nt;
    }else if(c == '\n'){
      ++nl;
    }
  }
  printf("blank count: %d\ntab count: %d\nline count: %d\n", nb, nt, nl);
}
