//Bobby Brown Homework 15
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define ALWAYS "Bobby Brown Homework 15\n"
#define TSIZE 45 //size of arrays
#define YEAR 6
#define ERROR "Please intialize memory before selecting option!"
int get_choice(void);
int get_first(void);
char * s_gets(char * st, int n);
struct record { //Size of 104 bytes in current config
	char title[TSIZE];
	char author[TSIZE];
	char year[YEAR];
	struct record * next;
};


int main(void) {
	printf(ALWAYS);
	FILE *fpHW15 = fopen("HW15Data.txt", "r");
	if(fpHW15 == NULL) {
		perror("Error opening HW15Data.txt!");
	}
	FILE *fp = fopen("HW15Binary.xxx", "a+b"); //MUST BE CHANGED TO AMMEND AFTER DEBUG//MUST BE CHANGED TO AMMEND AFTER DEBUG//MUST BE CHANGED TO AMMEND AFTER DEBUG//MUST BE CHANGED TO AMMEND AFTER DEBUG
	char ch='a', input[TSIZE]; 
	int initialize, total, temp, i=0;
	struct record * head = NULL;
	struct record * prev, * current, * start;
	while ((ch = get_choice()) != 'q') {
		
		//Initialize list
		if (ch=='a') { 
			puts("Initializing list!");
			current = (struct record *) malloc(sizeof(struct record));			
			if (head==NULL) {
				head = current;
			} else {
				puts("Deleting current list!");
				while (head != NULL) {
					current = head;
					head = current->next;
					free(current);
				}
			}
			initialize=1; //Ensures initialization before allowing other options
			total=0;
			puts("DONE!");
			start = current;
		}
		
		//Appends txt to list 
		if (ch=='b') { 
			if (initialize==1) {
				prev = current;								
				while (fgets(input, TSIZE, fpHW15)!=NULL ) {			
					strcpy(current->title, input);
					fgets(input, TSIZE, fpHW15);
					strcpy(current->author, input);
					fgets(input, YEAR, fpHW15);
					strcpy(current->year, input);
					
					total++; //total number of records
					current = current->next;
					current = (struct record *) malloc(sizeof(struct record));	
				}
						 
			} else {
				puts("You are not initialized!");
			}
			current = prev;			
		}

		//Copy list to Binary file	 
		if (ch=='c') {	
			if (initialize==1) {
				total--;
				fwrite(start, (sizeof(struct record)-8), total, fp);				
			}
		}
		
		if (ch=='d') { //Print record info (Convert into function after works)			
			if (head == NULL) {
				puts("Error: No data entered!");
			} else {
				printf("There are %d records\n", total);
			}
			puts("Which record would you like to view?");
			scanf("%d", &temp);
			while (getchar() != '\n') ;     // skip rest of line.
			if (temp<total) {
				current = head;
				while (i<temp) {
					i++; 
					current = current->next;	
				}
				printf("Title: %s \nAuthor:%s \nYear: %s\n",
				current->title, current->author, current->year);

			} else {
				puts("Record does not exist");
			
			}
			current = prev; //Prevents overwriting data
		}
		
	//Add entry	NEXT WEEKS ASSIGNMENT	
//		if (ch=='e') { 
//			if (initialize==1) {
//				puts("Enter title:");
//				while (s_gets(input, TSIZE) != NULL && input[0] != '\0') {
//					current = (struct record *) malloc(sizeof(struct record));
//					if (head == NULL)
//						head = current;
//					else
//						prev->next = current; //Prevents overwriting data
//					current->next = NULL;				
//					strcpy(current->title, input);
//					puts("Enter author:");
//					s_gets(input, TSIZE);
//					strcpy(current->author, input);
//					puts("Enter year:");
//					s_gets(input, YEAR);
//					strcpy(current->year, input);
//					prev = current;	
//					puts("Enter another title or press ENTER");
//					total++; //total number of records
//				}
//			} else {
//			puts(ERROR);
//			}
//		}
		if ((ch<'a') && (ch!='q'))
			puts("Please enter a valid option");
	}
	//free memory
	current = head;
	while (head != NULL) {
		current = head;
		head = current->next;
		free(current);
	}
	fclose(fpHW15);
	fclose(fp);


return 0;	
}



//Menu for data points
int get_choice(void) {
	int ch;
	puts("Please select an option:");
	puts("a. Initialize list           b. Append data");
	puts("c. Copy list to binary file  d. Print record info  ");
	puts("e. Add book entry            q. Quit program");
	ch=get_first();
	return ch;
}

int get_first(void){
	int ch;
	while ((ch = getchar())=='\n'); // discard any leading \n characters & read next character.
	while (getchar() != '\n') ;     // skip rest of line.
	return tolower(ch);
}

//Receives input for entry into list
char * s_gets(char * st, int n) { 
	char * ret_val;
	char * find;
	
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;	
	}
	return ret_val;
}

//while (fscanf(fpHW15, "%s", input)==1) {
//					current = (struct record *) malloc(sizeof(struct record));
//					if (head == NULL)
//						head = current;
//					else
//						prev->next = current; //Prevents overwriting data
//					current->next = NULL;				
//					strcpy(current->title, input);
//					fgets(input, 45, stdin);
//					strcpy(current->author, input);
//					fscanf(fpHW15, "%s", input);
//					strcpy(current->year, input);
//					prev = current;	
//					total++; //total number of records
//				}




