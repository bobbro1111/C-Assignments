#include <stdio.h>
#include <string.h>
#define PROMPT "\nLet's calculate some factorals!\nRemember to keep it under 21! \nHow many should we calculate? (q to quit):\n"
int main(void) {	

	long long factoral, current = 1, i; //Required data type to process to 19 integers (without errors)
	printf("Bobby Brown Homework 5\n");
	printf(PROMPT);
	while (scanf(" %lld", &factoral)>0) {  //While loop that tests input for integers or invalid character
		for (i=1; i <= factoral; i++) { //For loop that will produce factoral
			printf("\n%lld", current*= i) ; //Printf command with factoral calculation to be effecient
		}
	printf(PROMPT);
	current = 1; //Resets after every factoral calc loop to reset calculation
	}	
	printf("\nThanks for using!");
	return 0;             
}

//Bobby Brown Homework 5
//
//Let's calculate some factorals!
//Remember to keep it under 21!
//How many should we calculate? (q to quit):
//20
//
//1
//2
//6
//24
//120
//720
//5040
//40320
//362880
//3628800
//39916800
//479001600
//6227020800
//87178291200
//1307674368000
//20922789888000
//355687428096000
//6402373705728000
//121645100408832000
//2432902008176640000
//Let's calculate some factorals!
//Remember to keep it under 21!
//How many should we calculate? (q to quit):
//q
//
//Thanks for using!
//--------------------------------
//Process exited after 8.254 seconds with return value 0
//Press any key to continue . . .
