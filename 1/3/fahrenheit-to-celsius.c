#include <stdio.h>

/*print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 */
main()
{
  float fahr, celsius;
  float lower, upper, step;

  lower = 0; /* lower limit of temerature scale */
  upper = 300; /* upper limmit */
  step = 20; /* step size */

  fahr = lower;
  printf("%10s %10s\n", "Fahrenheit", "Celsius");
  while(fahr <= upper){
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%10.0f %10.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}
