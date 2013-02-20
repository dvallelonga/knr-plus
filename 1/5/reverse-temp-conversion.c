#include <stdio.h>

/* Print Fahrenheit-Celsius table in reverse, from 300 to 0. */
main()
{
  int fahr;
  printf("%10s %10s\n", "Fahrenheit", "Celsius");
  for(fahr = 300; fahr >= 0; fahr = fahr - 20){
    printf("%10d %10.1f\n", fahr, (5.0/9.0)*(fahr-32));
  }
}
