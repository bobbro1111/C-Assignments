//Bobby Brown Homework 11
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ALWAYS "Bobby Brown Homework 11\n"
#include <stdio.h>
#define STLEN 10
int main(void) {
	printf(ALWAYS);
   char words[STLEN];
   char *pc = words;
   puts("Enter strings (empty line to quit):");
   while (fgets(words, STLEN, stdin)!=NULL
                          && *pc!='\n') {
      while (*pc!='\n' && *pc!='\0') pc++;
      if (*pc=='\n')
         *pc = '\0';
      else // must have words[i] == '\0'
         while (getchar()!='\n') ;
      puts(words);
   }
   puts("done");
   return 0;
}
