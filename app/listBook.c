#include "listBook.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TITLE1 "Is find in List Book\n"
#define INSTRUCTION1 "Mode: Find book in base\n"

typedef struct
{
	char *lastName;
	char *name;
	char *middleName;
} itemAvtor;

typedef struct
{
	//xxx-x-xxx-xxxxx-x
	int grupCod1[3];
	int grupCod2[1];
	int grupCod3[3];
	int grupCod4[5];
	int grupCod5[1];
} itemISBN;

typedef struct
{
	itemAvtor *avtor;
	char *titleBook;
	itemISBN isbn;
	char* yeaRelease;
} itemBook;

int count = 10;
itemAvtor *collectionAvtor;
itemISBN *nomerISBN;
itemBook *journalBook;

void randomFullStruct(int count);

void listBook()
{
	printf(TITLE1);
	printf(INSTRUCTION1);

	randomFullStruct(count);

}

void randomFullStruct(int count)
{
	journalBook = (itemBook*) malloc(count * sizeof(itemBook));
	char tempStr[250];
	int sizeStr;
	char *strTitleBook = "TitleBook";
	//char *strName = "Name";
	//char *strMiddleName = "MiddleName";

	srand(time(0));
	for (int i = 0; i < count; i++)
	{
		sizeStr = sprintf(tempStr, "%s%d", strTitleBook, i);
		journalBook[i].titleBook = (char*) malloc(sizeStr * sizeof(char));
		strcpy(journalBook[i].titleBook, tempStr);

		//journalStudent[i].gender = rand() % sizeGender;
		//journalStudent[i].class = rand() % (sizeof(Class) / sizeof(Class[0])) + 1;
		//journalStudent[i].nameLesson = rand() % sizeNameLesson;
		//journalStudent[i].gradeLesson = rand() % (sizeof(GradeLesson) / sizeof(GradeLesson[0])) + 1;
	}
}

