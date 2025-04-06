//Bobby Brown Homework 11
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALWAYS "Bobby Brown Homework 11\n"
#define ENTERCHAR "Enter a character to search for:\n"
#define ENTERSTRING "\nEnter strings (empty line to quit):"
#include <stdio.h>
#define STLEN 41
#define CHLEN 1
int get_ch(void); 
int get_first(void);
int CharIsAt(char * pStr, char ch, int loc[], int mLoc);
int main(void) {
	printf(ALWAYS);
	char words[STLEN], ch;
	char *pc = words;
	int loca[STLEN], cia, i;
	//uses fgets for string input and prevents buffer overflows
	while (printf(ENTERSTRING), fgets(words, STLEN, stdin)!=NULL
                        	&& *pc!='\n' && *pc!='\0') {
    	while (*pc!='\n' && *pc!='\0') pc++;
    	if (*pc=='\n')
        	*pc = '\0';
    	else 
    		while (getchar()!='\n');
 		pc = words; //Resets pc to orignal address   		
    	//Gets character and prevents buffer overflow	
    	printf(ENTERCHAR);
    	if (ch=get_first(), ch!=EOF || ch!='\0' ) {
			cia = CharIsAt(words, ch, loca, STLEN);	//Calls function and stores in cia
			//Outputs data to command window
			printf("\nString entered:\n");		
		    puts(words);
		    printf("\nCharacter entered:");
		    putchar(ch);
		    printf("\n\n%c is found in your string %d times!\n", ch, cia);
		    printf("\n%c is found in positions: ", ch);
		    for (i=0; i<cia ; i++) //Prints our positions
		    	printf(" %d", loca[i]+1); 	    		
		}
	}
	puts("done");
		
	return 0;
}
//Uses pointers to search string for character stored in ch
//Uses i to calculate position in pStr
int CharIsAt(char * pStr, char ch, int loc[], int mLoc) {
	int *ploc=loc, c, i=0;
	while (*pStr !='\0') {
		if (*pStr==ch) {
			*ploc=i;
			c++;
			ploc++;
		}
		pStr++;
		i++;
	}
	return c;
}
//Function used for inputing char
int get_first(void){
	int ch;
	while ((ch = getchar())=='\n')
		printf("Enter a valid character!"); // discard any leading \n characters & read next character.
	while (getchar() != '\n') ;     // skip rest of line.
	return ch;
}

//Bobby Brown Homework 11
//
//Enter strings (empty line to quit):Took 12 hours of fiddling to get this
//Enter a character to search for:
//o
//
//String entered:
//Took 12 hours of fiddling to get this
//
//Character entered:o
//
//o is found in your string 5 times!
//
//o is found in positions:  2 3 10 15 28
//Enter strings (empty line to quit):
//done
//
//--------------------------------
//Process exited after 46.3 seconds with return value 0
//Press any key to continue . . .
