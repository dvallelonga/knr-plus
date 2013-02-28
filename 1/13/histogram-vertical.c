#include <stdio.h>

// Print a histogram of the lengths of words in input.
main()
{
  int c, i, cur_word_length, word_length[21];
  cur_word_length = 0;
  for(i = 0; i < 21; i++){
    word_length[i] = 0;
  }

  // tally character counts
  while((c = getchar()) != EOF){
    //check if c is a letter
    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)){ // upper and lower bounds for ASCII A-Z and a-z
      cur_word_length++;
    }else if(cur_word_length > 0){
      word_length[cur_word_length]++;
      cur_word_length = 0;
    }
  }

  // find out what the highest occurrence was so we know how tall to make our columns
  int highest_occurrence = 0;
  for(i = 0; i < 20; i++){
    if(word_length[i] > highest_occurrence){
      highest_occurrence = word_length[i];
    }
  }

  // print the histogram
  int row, col;
  printf("\n");
  for(row = highest_occurrence; row > 0; row--){
    printf("%3d)  ", row);
    char char_to_print;
    for(col = 1; col <= 20; col++){
      if(word_length[col] >= row){
        char_to_print = '#';
      }else{
        char_to_print = ' ';
      }
      printf("%3c ", char_to_print);
    }
    printf("\n");
  }
  printf("%6s", " ");
  for(col = 1; col <= 20; col++){
    printf("%3d)", col);
  }
  printf("\n");
  printf("X-axis = word length; Y-axis = occurrences of words of that length.\n\n");
}
