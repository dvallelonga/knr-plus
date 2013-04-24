#include <stdio.h>

#define MAXLINE 10 /* maximum input line length */

int readline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
main()
{
  int len; // current line length
  int segLen; // length of current line segment
  int max; // maximum length seen so far
  char seg[MAXLINE]; // segment of line currently being read in
  char front[MAXLINE]; // front of the current line (0 - MAXLINE)
  char longest[MAXLINE]; // longest line saved here

  max = 0;
  len = 0;
  while((segLen = readline(seg, MAXLINE)) > 0){
    printf("seg: \"%s\"\n", seg);
    printf("segLen: %d\n", segLen);
    printf("seg[segLen-1]: \"%c\"\n", seg[segLen-1]);

    if(len == 0){
      copy(front, seg);
    }
    len += segLen;
    if(seg[segLen-1] == '\n'){
      printf("*** Reached end of line.\n");
      if(len > max){
        printf("\t CUR: max: %d, len: %d... Setting max to %d\n", max, len, len);
        max = len;
        printf("\t SET. max: %d, len:%d\n", max, len);
        copy(longest, front);
      }
      len = 0;
      printf("\t len reset to 0. len: %d, max: %d\n", len, max);
    }
    printf("-------------\n");
  }
  printf("### Loop finished. max = %d\n", max);
  if(max > 0){ // there was a line
    printf("\t Longest line length: %d\n", max);
    printf("\t First %d characters of longest line: %s\n", (MAXLINE - 1), longest);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
  int i;
  i = 0;
  while((to[i] = from[i]) != '\0')
    ++i;
}
