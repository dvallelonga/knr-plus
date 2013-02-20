#include <stdio.h>

/*print Celsius-Fahrenheit table for celsius = 0, 20, ..., 300 */
main()
{
  float fahr, celsius;
  float lower, upper, step;

  lower = 0; /* lower limit of temerature scale */
  upper = 300; /* upper limmit */
  step = 20; /* step size */

  celsius = lower;
  printf("%10s %12s\n", "Celsius", "Fahrenheit");
  while(celsius <= upper){
    fahr = celsius * (9.0/5.0) + 32.0;
    printf("%10.0f %12.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
