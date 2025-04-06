//Bobby Brown Homework 13
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ALWAYS "Bobby Brown Homework 13\n"
#define P1 "Enter between 2-10 channels (q or 0 to quit):\n"
double dRand(void);
int Setup(int *pnChan, int *pnPt);
int CollectData(int nChan, int nPt, double Data[][nPt]);
int WriteBinary(int nChan, int nPt, double Data[][nPt], const char * pfname);
int ReadBinary(int nChan, int nPt, double Data[][nPt], const char * pfname);
int AvgData(int nChan, int nPt, double Data[][nPt], double Avg[]);
int Results(int nChan, double Avg[]);
int get_choice(void);
int get_first(void);
int main(void) {
	printf(ALWAYS);
	FILE * fp;
	srand((unsigned int) time(0)); //Seeds for random numbers
	int Col, Chan;
	int size;
	long MemSize;	
	char * pfname = "H12.xxx"; //The file we will be using

	while (Setup(&Chan, &Col)!=-1) {
		MemSize = sizeof(double)*Chan*Col;
   		double (*pData)[Col] = (double (*)[Col]) malloc(MemSize); //Allocates memory block //Find size of memory block
		double (*pArr)[Col] = (double (*)[Col]) malloc(MemSize);
		double Avg[Chan];
		if (pData!=NULL) { //checks if memory was allocated
			CollectData(Chan, Col, pData);
			if (WriteBinary(Chan, Col, pData, pfname)==0)
				if (ReadBinary(Chan, Col, pArr, pfname)==0) {				
					AvgData(Chan, Col, pArr, Avg);
					Results(Chan, Avg);
				}
			free(pData);
			free(pArr);
		} else {
			printf("\nMemory allocation failed...\n");
			printf("Try with fewer channels or data points?\n");
		}

	}

	
	return 0;
}

double dRand(void) { // returns a random number between 0.0 and 10.0
 return rand()*(10.0/RAND_MAX);
}

int Setup(int *pnChan, int *pnPt) { //Menu selecting chan/data points
	int temp=-1, input=1;
	char c;
	printf(P1);
	scanf("%d", &input); //Check for channel input
	if (input>1 && input<11) {
		*pnChan=input;
		c=get_choice(); //Prints menu and takes data points
		
		if (c=='a') { 
			*pnPt=2048;
			temp=0;			
		}
		if (c=='b') { 
			*pnPt=4096; 
			temp=0;
		}
		if (c=='c') {		
			*pnPt=8192;
			temp=0;
		}
	}
	return temp;
}

//Takes 2D array and fills with random numbers
int CollectData(int nChan, int nPt, double Data[][nPt]) { 
	int r,c;
	if (Data !=NULL) { 
		for (r=0; r<nChan; r++)
			for (c=0; c<nPt; c++)
				(Data[r][c])=dRand();
	} else {
		return 1;
	} 
	return 1;	

}

//Menu for data points
int get_choice(void) {
	int ch;
	printf("\nEnter the letter for amount of points\n");
	printf("a. 2048         b. 4096\n");
	printf("c. 8192         q. quit  \n");
	ch=get_first();
	return ch;
}

int get_first(void){
	int ch;
	while ((ch = getchar())=='\n'); // discard any leading \n characters & read next character.
	while (getchar() != '\n') ;     // skip rest of line.
	return tolower(ch);
}

//Copies data from array to file (Returns 1 if fails
int WriteBinary(int nChan, int nPt, double Data[][nPt], const char * pfname) {
	int r,c;
	//Opens file and copies Channels and Datapoints as int
	FILE * fp = fopen(pfname,"wb");
	fwrite(&nChan, sizeof(int), 1, fp);
	fwrite(&nPt, sizeof(int), 1, fp);	
	if (Data !=NULL) { 
		for (r=0; r<nChan; r++)
			for (c=0; c<nPt; c++)
				fwrite(&Data[r][c], sizeof(double), 1, fp);
	} else {
		printf("Problem writing data!\n");
		return 1;
	}
	fclose(fp);	
	return 0;
}

//Copies data from fill and puts in array (Returns 1 if fails)
int ReadBinary(int nChan, int nPt, double Data[][nPt], const char * pfname) {
	int r,c;
	int chan, col;
	FILE * fp = fopen(pfname,"rb");
	fread(&chan, sizeof(int), 1, fp); 
	fread(&col, sizeof(int), 1, fp);
	//Ensures Channel and Data points are correct	
	if (Data !=NULL && chan==nChan && col==nPt) { 
		for (r=0; r<nChan; r++)
			for (c=0; c<nPt; c++)
				fread(&Data[r][c], sizeof(double), 1, fp);
	} else {
		printf("Problem copying data!\n");
		return 1;
	}
	fclose(fp);	
	return 0;
}

//Find average of data points in a Channel
int AvgData(int nChan, int nPt, double Data[][nPt], double Avg[]) {
	double total = 0;
	int r,c;
	if (Avg[nChan]!='\0') {
		for (r=0; r<nChan; r++) {
			for (c=0; c<nPt; c++) {		
				total+=Data[r][c];
			}
			Avg[r]=(total/nPt);
			total = 0; //Need to reset every loop	
		}
	} else {
		printf("Failure finding averages!\n");		
		return 1;
	}
}

//Displays channel averages
int Results(int nChan, double Avg[]) {
	int r=0;
	if (Avg[nChan]!='\0') {
		for (r=0; r<nChan; r++)
			printf("Channel %d has average %f\n", r+1, Avg[r]);
	} else {
		printf("Failed to print results!\n");
		return 1;
	}
	return 0;
}

//Bobby Brown Homework 13
//Enter between 2-10 channels (q or 0 to quit):
//10
//
//Enter the letter for amount of points
//a. 2048         b. 4096
//c. 8192         q. quit
//c
//Channel 1 has average 4.981072
//Channel 2 has average 5.012469
//Channel 3 has average 4.986487
//Channel 4 has average 4.984924
//Channel 5 has average 4.971152
//Channel 6 has average 5.062363
//Channel 7 has average 5.018075
//Channel 8 has average 5.000642
//Channel 9 has average 4.988091
//Channel 10 has average 4.954789
//Enter between 2-10 channels (q or 0 to quit):
//2
//
//Enter the letter for amount of points
//a. 2048         b. 4096
//c. 8192         q. quit
//a
//Channel 1 has average 4.960978
//Channel 2 has average 4.973713
//Enter between 2-10 channels (q or 0 to quit):
//q
//
//--------------------------------
//Process exited after 11.88 seconds with return value 0
//Press any key to continue . . .
