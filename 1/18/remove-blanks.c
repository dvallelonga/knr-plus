#include <stdio.h>

#define MAXLINE 100 /* maximum input line length */

int readline(char line[], int maxline);

/* Remove trailing blanks and tabs from each line of input, and delete entirely blank lines */
main()
{
  int len; // length of current line 
  char line[MAXLINE]; // line currently being read in

  while((len = readline(line, MAXLINE)) > 0){
    printf("BEFORE (%d): \"%s\"\n", len, line);
    if(line[0] != '\n'){ // skip blank lines
      int lastIndex = len-1; // last non-newline char
      int c;
      if(line[len-1] == '\n'){
        lastIndex--;
      }
      for(; (c = line[lastIndex]) == ' ' || c == '\t'; --lastIndex){}
      if(lastIndex >= 0){ // only want lines that contain a non-blank/tab character
        // put the \n back in if line originally ended with one.
        if(line[len-1] == '\n'){
          line[lastIndex+1] = '\n';
          lastIndex++;
        }
        line[lastIndex+1] = '\0'; // give line a new termination after last non-blank/tab character
        printf("AFTER (%d): \"%s\"\n", lastIndex+1, line);
      }
    }
  }
  return 0;
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

