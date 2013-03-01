#include <stdio.h>

#define ASCII_LOWER_BOUND 32
#define ASCII_UPPER_BOUND 127

// Print a histogram of the frequency of individual characters in input.
main()
{
  int c, i, char_counts[ASCII_UPPER_BOUND + 1];
  for(i = 0; i <= ASCII_UPPER_BOUND; i++){
    char_counts[i] = 0;
  }

  // tally character counts
  while((c = getchar()) != EOF){
    if(c >= ASCII_LOWER_BOUND && c <= ASCII_UPPER_BOUND){ // make sure char is within range of our array bounds
      char_counts[c]++;
    }
  }

  // find out what the highest occurrence was so we know how tall to make our columns
  int highest_occurrence = 0;
  for(i = ASCII_LOWER_BOUND; i <= ASCII_UPPER_BOUND; i++){
    if(char_counts[i] > highest_occurrence){
      highest_occurrence = char_counts[i];
    }
  }

  // print the histogram
  int row, col;
  printf("\n");
  for(row = highest_occurrence; row > 0; row--){
    printf("%3d)  ", row);
    char char_to_print;
    for(col = ASCII_LOWER_BOUND; col <= ASCII_UPPER_BOUND; col++){
      if(char_counts[col] >= row){
        char_to_print = '#';
      }else{
        char_to_print = ' ';
      }
      printf("%c ", char_to_print);
    }
    printf("\n");
  }
  printf("%6s", " ");
  for(col = ASCII_LOWER_BOUND; col <= ASCII_UPPER_BOUND; col++){
    printf("%c|", col);
  }
  printf("\n");
  printf("X-axis = ASCII character; Y-axis = frequency of that character in input.\n\n");
}
