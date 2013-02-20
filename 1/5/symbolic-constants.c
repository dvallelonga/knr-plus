#include <stdio.h>

#define LOWER 0 /* lower limit of table */
#define UPPER 300 /* upper limit */
#define STEP 20 /* step size */

/* Print Fahrenheit-Celsius table in reverse, from 300 to 0. */
main()
{
  int fahr;
  printf("--SYMBOLIC CONSTANTS VERSION--\n");
  printf("%10s %10s\n", "Fahrenheit", "Celsius");
  for(fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP){
    printf("%10d %10.1f\n", fahr, (5.0/9.0)*(fahr-32));
  }
}
