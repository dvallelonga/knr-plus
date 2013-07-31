#include <stdio.h>

#define MAXLINE 100 /* maximum input line length */
#define COLUMNS_PER_TABSTOP 3

int readline(char line[], int lim);
void detab(char from[], char to[]);
int tabsInLine(char line[]);

// Replace tabs in the input with the proper number of blanks to space to the next tab stop
main(){
  int len; // length of current line 
  char line[MAXLINE]; // line currently being read in

  //read a line
  while((len = readline(line, MAXLINE)) > 0){
    printf("line: %s\n", line);
    printf("line size: %ld\n", sizeof(line));
    printf("line len: %d\n", len);

    //count tabs in line
    int numTabs = tabsInLine(line);
    printf("numTabs: %d\n", numTabs);

    // Determine the longest possible length of the detabbed line, given the number of tabs it contains.
    int detabbedLen = len - numTabs + (COLUMNS_PER_TABSTOP * numTabs); 
    printf("detabbedLen: %d\n", detabbedLen);

    char detabbedLine[detabbedLen]; // copy of line, w/ tabs replaced by spaces
    printf("detabbedLine size: %ld\n", sizeof(detabbedLine));

    //replace tabs in line w/ spacesPerTab
    detab(line, detabbedLine);
    printf("DETABBED LINE:\n");
    printf("%s\n", detabbedLine);

    //print line
    printf("\n");
  }

  return 0;
}

/* readline: read a line into s, return length */
int readline(char s[], int lim){
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

int tabsInLine(char line[]){
  int i, tabCount = 0;
  for(i=0; line[i] != '\0'; i++){
    if(line[i] == '\t'){
      printf("  found tab at index: %d\n", i);
      tabCount++;
    }
  }
  printf("  returning tabCount: %d\n", tabCount);
  return tabCount;
}

void detab(char original[], char detabbed[]){
  printf("detab()\n");
  int origIndex, detabIndex;
  int spacesToNearestTabStop;
  for(origIndex=0, detabIndex=0; original[origIndex] != '\0'; origIndex++){
    if(original[origIndex] == '\t'){
      spacesToNearestTabStop = COLUMNS_PER_TABSTOP - (detabIndex % COLUMNS_PER_TABSTOP);
      printf("  detabIndex: %d\n", detabIndex);
      printf("  spacesToNearestTabStop: %d\n", spacesToNearestTabStop);
      int nextTabStopIndex = detabIndex + spacesToNearestTabStop;
      while(detabIndex < nextTabStopIndex){
        detabbed[detabIndex] = ' ';
        detabIndex++;
      } 
    }else{
      detabbed[detabIndex] = original[origIndex];
      detabIndex++;
    }
  }
  detabbed[detabIndex] = '\0';
}


