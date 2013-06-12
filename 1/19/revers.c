#include <stdio.h>

#define MAXLINE 100 /* maximum input line length */

int readline(char line[], int maxline);
void reverse(char line[], int len);

/* reverse input, one line at a time */
main()
{
  int len; // length of current line 
  char line[MAXLINE]; // line currently being read in

  while((len = readline(line, MAXLINE)) > 0){
    printf("BEFORE (%d): \"%s\"\n", len, line);
    reverse(line, len);
    printf("AFTER: \"%s\"\n", line);
  }
  return 0;
}

/* revers a character string */
void reverse(char line[], int len){
    int leftIndex, rightIndex;
    char temp;
    int EOL = len-2; // End Of Line marker. -2 so we don't read in the /n character at the end.

    for(leftIndex = 0, rightIndex=EOL; leftIndex < rightIndex; leftIndex++, rightIndex--){
      //printf("leftIndex: %d, rightIndex: %d\n", leftIndex, rightIndex);
      //printf("line[%d]: %c, line[%d]: %c\n", leftIndex, line[leftIndex], rightIndex, line[rightIndex]);
      temp = line[rightIndex];
      //printf("temp: %c\n", temp);
      line[rightIndex] = line[leftIndex];
      line[leftIndex] = temp;
      printf("PROGRESS: \"%s\"\n", line);
    }
}

/* getline: read a line into s, return length */
int readline(char s[], int lim)
{
  int c, i;
  for(i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i){
    s[i] = c;
  }
  if(c == '\n'){
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

