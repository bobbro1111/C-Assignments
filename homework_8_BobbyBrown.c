//Bobby Brown Homework 8
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ALWAYS "Bobby Brown Homework 8\n"
#define NSIZE1 4
#define NSIZE2 8
void FillArray(double vs[], int nVals);
double dAvg(double vs[], int nVals);
double dMax(double vs[], int nVals);
int main(void) {
	int i;
	double avg1, avg2, avgBoth, max1, max2, maxBoth, set1[NSIZE1], set2[NSIZE2];
	printf(ALWAYS);
	srand((unsigned int) time(0)); //Intilizes random numbers for rand()
	FillArray(set1, NSIZE1); //Fills array set1 with random nums
	FillArray(set2, NSIZE2); //Fills array set2 with random nums
	avg1 = dAvg(set1, NSIZE1); 
	avg2 = dAvg(set2, NSIZE2);
	avgBoth = avg2-avg1; //Finds avg of both arrays
	max1 = dMax(set1, NSIZE1); 
	max2 = dMax(set2, NSIZE2);
	(max1 > max2) ? (maxBoth = max1-max2) : (maxBoth = max2-max1); //Sets maxBoth to difference of the two maximums
	printf("Data Set Analysis:\n");
	printf("Number of Datasets: 2\n");
	printf("Set #1: %d items\n", NSIZE1);
	printf("Set #2: %d items\n", NSIZE2);
	printf("Set #1: AVG= %.3f", avg1);
	for (i=0; i < NSIZE1; i++) //Prints out array set1
		printf (" %.3f", set1[i]);
	printf("\nSet #2: AVG= %.3f", avg2);
	for (i=0; i < NSIZE2; i++) //Prints out array set2
		printf (" %.3f", set2[i]);
	printf("\nSet#1-Set#2: AVG=%.3f MAX=%.3f", avgBoth, maxBoth); //Prints avg and max of both arrays
	return 0;
}

void FillArray(double vs[], int nVals) { //Fills arrays with random numbers
	int i=0;
	for (;i < nVals; i++)
		vs[i] = rand()*10.0/RAND_MAX;
}

double dAvg(double vs[], int nVals) { //Finds the average of the array
	double total = 0;
	int i=0;
	for (;i < nVals; i++) {
		total += vs[i] ;
	}
	return total / nVals; //returns result of total
}

double dMax(double vs[], int nVals) { //Finds the maximum number of the array
	double temp=0;
	int i=0;
	for (;i < nVals; i++)
		if (vs[i] > temp)
			temp = vs[i];
	return temp; //Maximum number is stored in temp
}

//Bobby Brown Homework 8
//Data Set Analysis:
//Number of Datasets: 2
//Set #1: 4 items
//Set #2: 8 items
//Set #1: AVG= 3.624 4.409 2.548 1.578 5.962
//Set #2: AVG= 3.933 7.953 2.848 1.650 1.516 7.895 1.433 5.999 2.166
//Set#1-Set#2: AVG=0.308 MAX=1.991
//--------------------------------
//Process exited after 0.02116 seconds with return value 0
//Press any key to continue . . .
