//Bobby Brown Homework 14
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ALWAYS "Bobby Brown Homework 14\n"

struct n { //Name structure
	char f[15];
	char l[15];
};

struct info { //Structure that has all info
	int SSN;
	struct n names;
};

int main(void) {
	printf(ALWAYS);
	struct info array[5] = { 
    	{ 123456789, {"Chester", "skrukkefylla"} },
    	{ 888888547, {"Sarah", "Humblethorn"} },
    	{ 656585859, {"Sue","Potato"} },
    	{ 748554741, {"Hofter","Smellen"} },
		{ 568974125, {"Avløp","Klump"} }
	};
	int i;
				
	for (i=0; i < 5; i++) {	
		printf("%d -- ", array[i].SSN);
		printf("%s, %s\n", array[i].names.l, array[i].names.f);
	}
	return 0;
}

//Bobby Brown Homework 14
//123456789 -- Skrukkefylla, Chester
//888888547 -- Humblethorn, Sarah
//656585859 -- Potato, Sue
//748554741 -- Smellen, Hofter
//568974125 -- Klump, Avl°p
//
//--------------------------------
//Process exited after 0.02248 seconds with return value 0
//Press any key to continue . . .
