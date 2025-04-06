#include <stdio.h>
#include <limits.h>
#define SIZE 10
unsigned long long Factorial(unsigned int n);
unsigned short step4a=1, step4b=1;
int main(void) {
	int index, input[SIZE], output[SIZE], status, loops;	
	printf("Bobby Brown - Homework 6\n");
	printf("Input up to 10 integers to be calculated! (q to quit)\n");
	for (index = 0, status=1; 									
		(index < SIZE) && (status=scanf("%20d", &input[index])); index++) ; //Reads in up to 10 inputs
	loops = index; //Calculates amount of loops required before index is used elsewhere
	printf("          Input       Factorial\n");
	for (index = 0; index < loops; index++) {
		output[index] = Factorial(input[index]); //stores our factorial calc but doesn't seem necessary?
	    printf("%15d %15llu\n", input[index], Factorial(input[index])); // prints a formatted graph of input and output	    
	}
	while (Factorial((step4a+1)) <= USHRT_MAX) {
		step4a+=1;
	}
	printf("The highest value an unsigned short can hold is %d\n", USHRT_MAX);
	printf("The highest input for an unsigned short is %u and calculates: \n%u", step4a, Factorial(step4a));	
	return 0;	
	
}
unsigned long long Factorial(unsigned int n) {
	int i;
	unsigned long long tValue;
	for (i=1, tValue=1; i<= n; i++) {
		tValue *= i;
		}
	return tValue;
}

//Bobby Brown - Homework 6
//Input up to 10 integers to be calculated! (q to quit)
//1
//2
//3
//11
//14
//8
//9
//q
//          Input       Factorial
//              1               1
//              2               2
//              3               6
//             11        39916800
//             14     87178291200
//              8           40320
//              9          362880
//The highest value an unsigned short can hold is 65535
//The highest input for an unsigned short is 8 and calculates:
//40320
//--------------------------------
//Process exited after 9.12 seconds with return value 0
//Press any key to continue . . .
