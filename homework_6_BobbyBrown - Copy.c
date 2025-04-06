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
	int items;
	double nVals, avg=1, avg2, avgBOTH, max, set1[NSIZE1], set2[NSIZE2];
	printf(ALWAYS);
	srand((unsigned int) time(0));
//	FillArray(double set1[], int NSIZE1);
//	FillArray(double set2[], int NSIZE2);
	printf("Data Set Analysis:\n");
	printf("Number of Datasets: 2\n");
	printf("Set #1: %d items\n", items=NSIZE1);
	printf("Set #2: %d items\n", items=NSIZE2);
	printf("Set #1: AVG= %f", avg);
//	for (int i = 0; i < NSIZE1; i++)
//		printf (" %f", set1[i]);
//	
	return 0;
}

void FillArray(double vs[], int nVals) {
	
}

double dAvg(double vs[], int nVals) {
	double total = 0;
	for (int i = 0; i < nVals; i++) {
		total += vs[i] ;
	}
	return total / nVals;
}

double dMax(double vs[], int nVals) {
	
}
