#include <stdio.h>

main()
{
  printf("1) hello, world\b");
  printf("\n");
  printf("2) hello, mars\a");
  printf("\n");
  printf("3) ab\bcd");
  printf("\n");
  printf("4) abcde\b\b\bfghij");
  printf("\n");
  printf("\\a: \a\n");
//  printf("\\c: \c\n");  //results in error
//  printf("\\d: \d\n");  //results in error
  printf("\\e: \e\n");
  printf("\\f: \f\n");
  printf("\\g: \g\n");
  printf("stuff before \\f break. \fstuff after \\f break\n");

  printf("hello, end\n");
}
