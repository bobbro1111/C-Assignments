#define ASSIGNMENT "HW #16: Bobby Brown \n"
// This version terminates input when an input string is too long.
//#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TSIZE 101 // Size of title string
#define ASIZE 51  // Size of author string
#define YSIZE 6   // Size of year string--include space for '\n' and '\0'.
#define FSIZE 51  // Size for the filename.
#define TEXTINPUT "HW15Data.txt" // Text input filename.
#define BINARYFILE "HW15Binary.zzz" // Binary filename.

struct stbook {
	char title[TSIZE], author[ASIZE], year[YSIZE];
};
typedef struct stbook tstItem;  // tstItem is a type structure containing book info.
typedef struct stNode {
	tstItem Item;
	struct stNode *pNext;
} tstNode;                	// tstNode is a structure containg item and the pointer next.
typedef tstNode *tpstNode;  // tpstNode type is a pointer to a Node.
tpstNode   AppendAfter(const tpstNode *pCur, const tstItem *pItem);  // Appends 1 node.
tpstNode   AppendFromTextFile(tpstNode *pHead);   // Appends multiple nodes from text file.
   // If pHead==NULL, it is set to pointer to the first node added.
   // The return value is the pointer to the last node added.
tpstNode AppendFromBinaryFile(tpstNode *pHead); //Uses fread to import binary
void		ClearLine(void);  // Clears input buffer through '\n'.
unsigned	CountRecords(const tpstNode *pHead);  // Counts the number of nodes.
tpstNode	GetRecordNum(const tpstNode *pHead, unsigned n, tstItem * pItem);
int 		HasAnEnter(char * pstr);			// Checks string for a \n.
void		InitializeList(tpstNode *pHead);    // Clears & initializes list.
tpstNode	ListEnd(const tpstNode *pCur);   	// Returns ptr to last node in a list. 
int		Menu(void);  							// Prompts for and returns selection.
void 		ListAllRecords(const tpstNode *pHead);  // Prints all the records in the list.
void 		PrintRecord(const tpstNode *pHead);  // Prompts for record #, and prints record.
void 		WriteBinaryFile(const tpstNode *pHead,
				char Filename[], int Fsize);  // Writes data to a binary file
tpstNode	AddEntry(tpstNode *pCur);			//Adds Book Entry	
int get_first(void);		
FILE * 	UseFileWr(char *pFilename, int nLen);

int main(void){	
	tpstNode pList = NULL;  // plist is a pointer to the head of the list.
	char WrFilename[FSIZE] = BINARYFILE;
	int ch = 0;
	fputs(ASSIGNMENT,stdout);
	while ((ch=Menu())!='q') {
		switch (ch) {
			case 'i': InitializeList(&pList);  // Initialize list, clearing any existing list.
						break;
			case 'a': AppendFromTextFile(&pList);  // Sets pList if it was NULL,
						break;
			case 'b': AppendFromBinaryFile(&pList);
						break;			
			case 'p': PrintRecord(&pList);  // Prompts for record #, and prints record.
						break;
			case 'l': ListAllRecords(&pList);  // Prints all the records in the list.
						break;
			case 'w': WriteBinaryFile(&pList,WrFilename,FSIZE);	// Writes data to a binary file.	 
						break;
			case 'e': AddEntry(&pList);
		}
	}
	InitializeList(&pList);  // Initializes list, freeing any allocated memory.
	return 0;
}

tpstNode AppendAfter(const tpstNode *pCur, const tstItem *pItem) {
	tpstNode pNew;
	pNew = malloc(sizeof(tstNode));
	if (pNew) {
		pNew->Item = *pItem;
		if (*pCur) {
			pNew->pNext = (*pCur)->pNext;
			(*pCur)->pNext = pNew;
		} else {
			pNew->pNext = NULL;
		}
	}
#ifdef DEBUG
	printf("AppendAfter pNew=%p\n",pNew);
#endif
	return pNew;	
}

tpstNode AppendFromTextFile(tpstNode *pHead) {
	tstItem item;
	unsigned int Count=0;
	tpstNode pCur = ListEnd(pHead); // Find last node in current list
	FILE * fp = fopen(TEXTINPUT,"r");
	if (fp) {
		while ((fgets(item.title,TSIZE,fp)) && (fgets(item.author,ASIZE,fp)) && (fgets(item.year,YSIZE,fp)) ) {
#ifdef DEBUG
			printf("%s  %s  %s",item.title,item.author,item.year);
#endif
			if ( HasAnEnter(item.title) && HasAnEnter(item.author) && HasAnEnter(item.year) ){
				pCur = AppendAfter(&pCur,&item);
				if (pCur) {
					Count++;
					if (*pHead==NULL) *pHead = pCur;
				} else {
					printf("** Memory allocation failed **\n");
					break;
				}
			} else {
				printf("** File input line was too long, aborting operation **\n" 
						"   Book info read is:\n");
				printf("%s%s%s\n",item.title,item.author,item.year);	
				break;
			}
		}
		fclose(fp);
		printf("Appended %u records from %s.\n",Count,TEXTINPUT);
	} else printf("** Failed to open %s. **\n",TEXTINPUT);
	return pCur;
}
//Similar to AppendFromTextFile but uses fread instead of fgets
tpstNode AppendFromBinaryFile(tpstNode *pHead) {
	tstItem item;
	unsigned int Count=0;
	tpstNode pCur = ListEnd(pHead); // Find last node in current list
	FILE * fp = fopen(BINARYFILE,"rb");
	if (fp) {
		while ((fread(item.title,TSIZE,1,fp)) && (fread(item.author,ASIZE,1,fp)) && (fread(item.year,YSIZE,1,fp)) ) {
#ifdef DEBUG
			printf("%s  %s  %s",item.title,item.author,item.year);
#endif
			if ( HasAnEnter(item.title) && HasAnEnter(item.author) && HasAnEnter(item.year) ){
				pCur = AppendAfter(&pCur,&item);
				if (pCur) {
					Count++;
					if (*pHead==NULL) *pHead = pCur;
				} else {
					printf("** Memory allocation failed **\n");
					break;
				}
			} else {
				printf("** File input line was too long, aborting operation **\n" 
						"   Book info read is:\n");
				printf("%s%s%s\n",item.title,item.author,item.year);	
				break;
			}
		}
		fclose(fp);
		printf("Appended %u records from %s.\n",Count,BINARYFILE);
	} else printf("** Failed to open %s. **\n",BINARYFILE);
	return pCur;
}

//Utlizes HW15-Book1 functions to add entries
tpstNode AddEntry(tpstNode *pHead) { 
	tstItem item;
	tpstNode pCur = ListEnd(pHead);
	int ch='y';
	
	while (ch=='y') {				
		puts("Enter title:");
		fgets(item.title,TSIZE,stdin);				
		puts("Enter author:");
		fgets(item.author,ASIZE,stdin);
		puts("Enter year:");
		fgets(item.year,YSIZE,stdin);
		puts("Enter another title? Y or N");
		if ( HasAnEnter(item.title) && HasAnEnter(item.author) && HasAnEnter(item.year) ){
				pCur = AppendAfter(&pCur,&item);
				if (pCur) {
					if (*pHead==NULL) *pHead = pCur;
				} else {
					printf("** Memory allocation failed **\n");
					break;
				}
			} else {
				printf("** Input line was too long, aborting operation **\n" 
						"   Book info read is:\n");
				printf("%s%s%s\n",item.title,item.author,item.year);	
				break;
			}		
		ch=get_first();
	}
	return pCur;
} 

int get_first(void){
	int ch;
	while ((ch = getchar())=='\n'); // discard any leading \n characters & read next character.
	while (getchar() != '\n') ;     // skip rest of line.
	return tolower(ch);
}

void ClearLine(void) {
	while (getchar()!='\n') ;
}

unsigned CountRecords(const tpstNode *pHead) {
	unsigned i;
	tpstNode ptmp=*pHead;
	if (ptmp)
		for (i=1; (ptmp->pNext); i++)
			ptmp = ptmp->pNext;
	else i = 0;
#ifdef DEBUG
	printf("CountRecords = %u\n",i);
#endif
	return i;
}

tpstNode GetRecordNum(const tpstNode *pHead, unsigned n, tstItem *pItem) {
	tpstNode pCur = *pHead;
	unsigned i;
	for (i=1; (i<n) && (pCur); i++)
		pCur = pCur->pNext;
	if (pCur)
		*pItem = pCur->Item;
	return pCur;
}	

int HasAnEnter(char * pstr) {
	while ((*pstr!='\0') && (*pstr!='\n')) 
		pstr++;
	return *pstr=='\n';
}
	
void InitializeList(tpstNode *pHead) {
	tpstNode ptmp;
#ifdef DEBUG
	printf("Initialize: %p  ",*pHead);
#endif
	while (*pHead) {
		ptmp = (*pHead)->pNext; //Need the () so that the * applies to pHead and not to pNext.
		free(*pHead);
		*pHead = ptmp;
	}
#ifdef DEBUG
	printf(" %p\n",*pHead);
#endif
	fputs("Initialization completed\n",stdout);
}

// Prints all the records in the list.
void ListAllRecords(const tpstNode *pHead){
	unsigned nRec;
	tpstNode pCur;
	if ((pCur = *pHead)) {  // This is an assignment.
		for (nRec=0; (pCur); ){
			printf("\nContents of record #%u are: \n  %s  %s  %s",++nRec,
				pCur->Item.title, pCur->Item.author, pCur->Item.year);
			pCur = pCur->pNext;
		}
	} else printf("\nNo records available to print.\n");	
}

tpstNode ListEnd(const tpstNode *pCur) { // Finds end of the list.
	tpstNode ptmp=*pCur;
	if (ptmp)
		while (ptmp->pNext)
			ptmp = ptmp->pNext;
	return ptmp;
}

int Menu(void) {
	char * pPrompt = "\nSelect operation from following list:\n" 
						" i) Initialize   a) Append         L) List\n"
						" p) Print        w) Write b File   e) Add Entry\n"
						" b) Append Binary                  q) quit\n"
						" Enter selection:  ";
	char * pChars = "ailpqweb";
	int ch=0;
	fputs(pPrompt,stdout);
	while (strchr(pChars,ch=tolower(getchar()))==NULL)	{
		ClearLine();
		fputs(pPrompt,stdout);
	}
	ClearLine();
	return ch;
}

// Prompts for record # to be printed and prints record.
void PrintRecord(const tpstNode *pHead) {
	unsigned nRec, nMax;
	tstItem PrintItem;
	tpstNode pCur=NULL;
	nMax = CountRecords(pHead);
	if (nMax>0) {
		printf("Enter record # to print (1-%u):  ",nMax);
		if ( (scanf("%u",&nRec)) && (nRec>0 && nRec<=nMax))
			pCur = GetRecordNum(pHead,nRec,&PrintItem);
		else
			fputs("** Invalid input--aborting operation **\n",stdout);
		if (pCur)
			printf("\nContents of record #%u are: \n  %s  %s  %s",nRec,
				pCur->Item.title, pCur->Item.author, pCur->Item.year);
		ClearLine();
	} else fputs("\nNo records available to print.\n",stdout);
}

void WriteBinaryFile(const tpstNode *pHead, char Filename[], int Fsize) { 
	unsigned int Count=0;
	tpstNode pCur=*pHead;
	FILE *fp;
	if ((fp=UseFileWr(Filename,Fsize))) {
		while ((pCur) && (fwrite(&pCur->Item,sizeof(tstItem),1,fp)==1)) { // Write out title, author, & year.
			Count++;
			pCur = pCur->pNext;
		}
		fclose(fp);
		printf("Wrote %u records to %s.\n",Count,Filename);
	} else printf("** Failed to open %s. **\n",Filename);
}

// Returns file pointer for writing or NULL.
FILE * UseFileWr(char *pFilename, int nLen) {
	FILE *fp;
	char *pc, *pChars="acoq", ch='c';
	char *pPrompt = "File %s exists.  Do you want to:\n Append to the file,\n"
			" Overwrite the file,\n Change the filename,\n or Quit?\n"
			" Enter an 'a', 'c', 'o', or 'q': ";
	while ((ch=='c') && (fp = fopen(pFilename,"r"))) {
		if (fp) 
			fclose(fp);
		printf(pPrompt,pFilename);
		while (strchr(pChars,ch=tolower(getchar()))==NULL)	{
			ClearLine();
			printf(pPrompt,pFilename);
		}
		ClearLine();
		if (ch=='c') {
			fputs("Enter new file with extension: ",stdout);
			pFilename = fgets(pFilename,nLen,stdin);
			for (pc=pFilename; (*pc!='\0') && (*pc!='\n'); pc++); 
			if (*pc=='\n') *pc='\0';
			else
				while (getchar()!='\n'); // clear buffer.
		}
	}
	// Do not open file if user chose 'q' to quit.
	return (ch!='q') ? fopen(pFilename,"wb"): NULL;
}


//HW #16: Bobby Brown
//
//Select operation from following list:
// i) Initialize   a) Append         L) List
// p) Print        w) Write b File   e) Add Entry
// b) Append Binary                  q) quit
// Enter selection:  i
//Initialization completed
//
//Select operation from following list:
// i) Initialize   a) Append         L) List
// p) Print        w) Write b File   e) Add Entry
// b) Append Binary                  q) quit
// Enter selection:  a
//Appended 14 records from HW15Data.txt.
//
//Select operation from following list:
// i) Initialize   a) Append         L) List
// p) Print        w) Write b File   e) Add Entry
// b) Append Binary                  q) quit
// Enter selection:  e
//Enter title:
//123
//Enter author:
//123
//Enter year:
//123
//Enter another title? Y or N
//n
//
//Select operation from following list:
// i) Initialize   a) Append         L) List
// p) Print        w) Write b File   e) Add Entry
// b) Append Binary                  q) quit
// Enter selection:  w
//File HW15Binary.zzz exists.  Do you want to:
// Append to the file,
// Overwrite the file,
// Change the filename,
// or Quit?
// Enter an 'a', 'c', 'o', or 'q': o
//Wrote 15 records to HW15Binary.zzz.
//
//Select operation from following list:
// i) Initialize   a) Append         L) List
// p) Print        w) Write b File   e) Add Entry
// b) Append Binary                  q) quit
// Enter selection:  b
//Appended 15 records from HW15Binary.zzz.
//
//Select operation from following list:
// i) Initialize   a) Append         L) List
// p) Print        w) Write b File   e) Add Entry
// b) Append Binary                  q) quit
// Enter selection:  p
//Enter record # to print (1-30):  30\
//
//Contents of record #30 are:
//  123
//  123
//  123
//
//Select operation from following list:
// i) Initialize   a) Append         L) List
// p) Print        w) Write b File   e) Add Entry
// b) Append Binary                  q) quit
// Enter selection:
