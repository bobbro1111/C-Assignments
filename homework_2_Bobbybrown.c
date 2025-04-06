// Bobby Brown HW#2
#include <stdio.h>

int main(void) {
	char const Str[3]="abc";
	float cups; //Verious floating point numbers for our conversion
	float pints;
	float ounces;
	float tablespoons;
	float teaspoons;
	double a=1;
	printf("Bobby Brown HW#2\n"); //Homework number and student	
	printf("How many cups do you have?");
	
	scanf("%f", &cups); //Asking user how many cups they have
	
	pints = cups * 0.5; //Cups to pints conversion is 2 cup:1 pint
	ounces = cups * 8; // Cups to ounce conversion is 1 cup:8 ounces
	tablespoons =  cups * 16; //Cups to tablespoons conversion is 1 cup: 16 tablespoons
	teaspoons = cups * 48; //Cups to teaspoons conversion is 1 cup: 48 teaspoons
	
	printf("\n%f Cups work out to:\n", &cups); //Individual print commands so it's not an eyesore
	printf("Pints: %f \n", pints);
	printf("Ounces: %f \n", ounces);
	printf("Tablespoons: %f \n", tablespoons);
	printf("Teapsoons: %f \n", teaspoons);
	printf("%#06hx", a);
	printf("Thanks for using my conversion program... maybe don't use individuals teaspoons in your recipe :)");
	
	return 0;
}
//Bobby Brown HW#2
//How many cups do you have?5
//
//0.000000 Cups work out to:
//Pints: 2.500000
//Ounces: 40.000000
//Tablespoons: 80.000000
//Teapsoons: 240.000000
//Thanks for using my conversion program... maybe don't use individuals teaspoons
//in your recipe :)
//--------------------------------
//Process exited after 2.849 seconds with return value 0
//Press any key to continue . . .
