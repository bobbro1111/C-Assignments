//Bobby Brown Homework 7
#include <stdio.h>
#include <ctype.h>
#define ALWAYS "Bobby Brown Homework 7\n"
#define FIRST "\nEnter the first number:"
#define SECOND "\nEnter the second number:"
int get_choice(void); //Functions I shamelessly ripped from getChoice3
int get_first(void); //These were much more efficient then what I had originally
float get_number(void); //Gets input from user and checks if input is a number
float add(float a, float b); //addition function
float subtract(float a, float b); //subtraction function
float multiply(float a, float b); //multiplication function
float divide(float a, float b); //division function
int main(void) {
	char ans;
	double num1, num2;
	printf(ALWAYS);
	while ((ans=get_choice())!='q') { //Get user input for menu
		printf(FIRST);
		num1 = get_number();
		printf(SECOND);
		num2 = get_number();
		if (ans=='a') { //I used if statements so the loop won't need ans to change to stop from becoming infinite
			printf("%g plus %g = %g", num1, num2, add(num1, num2));  			
		}
		if (ans=='s') { //Checks user inputs to see which function they would like
			printf("%g minus %g = %g", num1, num2, subtract(num1, num2)); //prints computation of inputs
		}
		if (ans=='m') {		
			printf("%g multiplied by %g = %g", num1, num2, multiply(num1, num2));
		}
		if (ans=='d') {
			while (num1==0) { //Makes user input new first number if entered 0
				printf("\nCannot divide zero, try again");
				printf("\nEnter a new first number: ");
				num1 = get_number();
			}
			while (num2==0) { //Makes uers input new second number if entered 0
				printf("\nCannot divide by zero, try again");
				printf("\nEnter a new second number: ");
				num2 = get_number();				
			}
			printf("%g divided by %g = %g", num1, num2, divide(num1, num2));
		}
		ans = '\n'; //changes loop condition so it must repeat
	}
	return 0;
}

// Prompts user for input.
int get_choice(void) {
	int ch;
	printf("\nEnter the letter of your choice:\n");
	printf("a. add         s. subtract\n");
	printf("m. multiple    d. divide  \n");
	printf("q. quit\n");
	while ( ( (ch=get_first())!='a' && (ch!='s') && (ch!='m') && (ch!='d') && (ch!='q'))) {
		printf("Please respond with a, s, m, d, or q to quit.\n");
	}
	return ch;
}
// Reads input and discards extra characters
int get_first(void){
	int ch;
	while ((ch = getchar())=='\n'); // discard any leading \n characters & read next character.
	while (getchar() != '\n') ;     // skip rest of line.
	return tolower(ch);
}
//retreives an input and checks if number
float get_number(void) { 
	int ch; 
	float num;

	while ((scanf("%f", &num) != 1))	{
		while ((ch = getchar()) != '\n') // echo user input and clear stream
			putchar(ch);
		printf(" is not a number.\n");
		printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
	}
	return num;
}

//adds 2 inputs and returns result
float add(float a, float b) { //add two inputs
	a+=b;
	return a;
}
//subtracts two inputs and returns results
float subtract(float a, float b) { //subtract two inputs
	a-=b;
	return a;
}
//multiples 2 inputs and returns results
float multiply(float a, float b) { //multiply two inputs
	a*=b;
	return a;
}
//divides 2 inputs and returns results
float divide(float a, float b) { //divides two inputs
	a/=b;
	return a;
}

//Bobby Brown Homework 7
//
//Enter the letter of your choice:
//a. add         s. subtract
//m. multiple    d. divide
//q. quit
//d
//
//Enter the first number:178
//
//Enter the second number:0
//
//Cannot divide by zero, try again
//Enter a new second number: 9
//178 divided by 9 = 19.7778
//Enter the letter of your choice:
//a. add         s. subtract
//m. multiple    d. divide
//q. quit
//m
//
//Enter the first number:12E2
//
//Enter the second number:8
//1200 multiplied by 8 = 9600
//Enter the letter of your choice:
//a. add         s. subtract
//m. multiple    d. divide
//q. quit
//q
//
//--------------------------------
//Process exited after 25.32 seconds with return value 0
//Press any key to continue . . .

