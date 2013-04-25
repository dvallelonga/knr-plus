#include <stdio.h>

#define MAXLINE 10 /* maximum input line length */

int readline(char line[], int maxline);

/* print the longest input line */
main()
{
  int segLen; // length of current line segment
  char seg[MAXLINE]; // segment of line currently being read in
  int midLineRead; // (0=false, 1=true) whether the currently read-in line is a part of a longer line

  midLineRead = 0;
  while((segLen = readline(seg, MAXLINE)) > 0){
    if(segLen >= (MAXLINE - 1) || midLineRead == 1){
      printf("%s", seg);
      midLineRead = 1;
    }
    if(seg[segLen-1] == '\n'){
      midLineRead = 0;
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

