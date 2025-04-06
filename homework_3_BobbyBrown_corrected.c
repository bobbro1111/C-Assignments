//Homework 4 Bobby Brown

#include <stdio.h>
#include <string.h>
int main(void) {	
	char chr[25]="a";
	int height, remainder;
	printf("Bobby Brown Homework 4 OPTION 2\n");
	
	
	while (*chr!='q') {
		printf("What is your name and height in inches? (q to quit):\n");
		scanf(" %24s %d", &chr, &height); //Entry to either exit or continue loop (q in first entry exits)
		if (*chr=='q') {
			break;
		}
		printf("Well %s, you are %d feet and %2d inches tall!\n", chr, height/12, height%12);
	}
	printf("Goodbye :)");
	return 0;             
}

//Bobby Brown Homework 4 OPTION 2
//What is your name and height in inches? (q to quit):
//Bobby
//70
//Well Bobby, you are 5 feet and 10 inches tall!
//What is your name and height in inches? (q to quit):
//Doofenshmirtz
//25
//Well Doofenshmirtz, you are 2 feet and  1 inches tall!
//What is your name and height in inches? (q to quit):
//q
//q
//Goodbye :)
//--------------------------------
//Process exited after 98.5 seconds with return value 0
//Press any key to continue . . .

