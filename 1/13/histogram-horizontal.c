#include <stdio.h>

// Print a histogram of the lengths of words in input.
main()
{
  int c, i, cur_word_length, word_length[30];
  cur_word_length = 0;
  for(i = 0; i < 30; i++){
    word_length[i] = 0;
  }

  while((c = getchar()) != EOF){
    //check if c is a letter
    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)){ // upper and lower bounds for ASCII A-Z and a-z
      cur_word_length++;
    }else if(cur_word_length > 0){
      word_length[cur_word_length]++;
      cur_word_length = 0;
    }
  }

  printf("Y-axis = word length; X-axis = occurrences of words of that length\n");
  for(i = 1; i < 30; i++){
    if(word_length[i] > 0){ // don't show if no words occurred for this length
      printf("%3d) ", i);
      int z;
      for(z = 0; z < word_length[i]; z ++){
        printf("|");
      }
      printf("\n");
    }
  }
}
