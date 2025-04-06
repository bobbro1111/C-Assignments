//Bobby Brown Homework 9
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ALWAYS "Bobby Brown Homework 9\n"
#define NROW 3
#define NCOL 5
double dRand(void);
double dAvg(double vs[], int v);
double dMax(double (*vs)[NCOL], int v, int b);
int main(void) {
	int r,c;
	double avg[NROW], array[NROW][NCOL], temp;
	printf(ALWAYS);
	srand((unsigned int) time(0)); //Intilizes random numbers for rand()
	
	for (r = 0;r < NROW; r++) { //Nested loop filling 2D array
		printf("Row: %d\n", r+1);
		for (c = 0;c < NCOL;c++) {
			array[r][c] = dRand(); //Fills 2D array with random number
			printf("Column: %d Value: %.3f\n", c+1, array[r][c]);
		}
		temp += avg[r] = dAvg(array[r], NCOL); //runs dAvg and stores in avg and temp
		printf("Average of row %d: %.3f\n", r+1, avg[r]);				
	}
	printf("Average value of the 2D array: %.3f\n", temp/3); 
	printf("Maximum of the 2D array: %.3f\n", dMax(array, NROW, NCOL)); //printf max of 2D array
	return 0;
}

double dRand(void) { //Returns random number
	double num = rand()*10.0/RAND_MAX;
	return num;
}

double dAvg(double vs[], int v) { //Finds the average of the array (includes row column int instead of NCOL per email instruction)
	double total = 0;
	int i;
	for (i=0;i < v; i++) {
		total += vs[i];
	}
	return total / NCOL; //returns result of total
}

double dMax(double (*vs)[NCOL], int v, int b) { //Finds the maximum number of the 2D array (included rows + column ints as per email instruction)
	double temp= vs[0][0]; //(sets temp to vs[0][0] instead of 0 per email instruction)
	int r, c;
	for (r = 0;r < v; r++) { 
		for (c = 0;c < b; c++) {
			if (vs[r][c] > temp)
				temp = vs[r][c];
		}	
	}
	return temp; //Maximum number is stored in temp
}

//Bobby Brown Homework 9
//Row: 1
//Column: 1 Value: 7.367
//Column: 2 Value: 6.767
//Column: 3 Value: 3.664
//Column: 4 Value: 3.399
//Column: 5 Value: 0.768
//Average of row 1: 4.393
//Row: 2
//Column: 1 Value: 0.399
//Column: 2 Value: 6.911
//Column: 3 Value: 4.302
//Column: 4 Value: 6.928
//Column: 5 Value: 2.909
//Average of row 2: 4.290
//Row: 3
//Column: 1 Value: 3.620
//Column: 2 Value: 9.837
//Column: 3 Value: 8.198
//Column: 4 Value: 0.879
//Column: 5 Value: 8.131
//Average of row 3: 6.133
//Average value of the 2D array: 4.939
//Maximum of the 2D array: 9.837
//
//--------------------------------
//Process exited after 0.02351 seconds with return value 0
//Press any key to continue . . .
