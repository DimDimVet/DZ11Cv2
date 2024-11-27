#include "listBook.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

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
	int countAvtor;
	char *titleBook;
	itemISBN isbn;
	char *yeaRelease;
} itemBook;

typedef struct
{
	char *last;
	char *name;
	char *middle;
	char *title;
	int *isbn;
	char *yea;
	itemBook *journalFindRezult;
} findTask;

int countJournalBook = 100;
int countAvtor = 0;
itemAvtor *collectionAvtor;
itemBook *journalBook;

void randomFullJournalBook(int count);
char* generateWord();
itemAvtor* randomFullAvtor();
itemISBN randomFullISBN();
char* randomFullYeaRelease();
void printConsoleJournalBook(itemBook *journalBook, int count);
void findJournalBook(itemBook *journalBook, int count, findTask findTask);
void findBook();

void listBook()
{
	printf(TITLE1);
	printf(INSTRUCTION1);

	randomFullJournalBook(countJournalBook);
	printConsoleJournalBook(journalBook, countJournalBook);
	findBook();
}

void randomFullJournalBook(int count)
{
	journalBook = (itemBook*) malloc(count * sizeof(itemBook));

	char *tempStr;
	int sizeStr;
	char *strYea;

	srand(time(0));
	for (int i = 0; i < count; i++)
	{
		//FIO
		collectionAvtor = randomFullAvtor();
		int countCollectionAvtor = (sizeof(&collectionAvtor)
				/ sizeof(collectionAvtor[0]));
		journalBook[i].countAvtor = countAvtor;
		journalBook[i].avtor = malloc(countCollectionAvtor * sizeof(itemAvtor));
		journalBook[i].avtor = collectionAvtor;

		//TitleBook
		tempStr = generateWord();
		sizeStr = (sizeof(&tempStr) / sizeof(tempStr[0]));
		journalBook[i].titleBook = (char*) malloc(sizeStr * sizeof(char));
		strcpy(journalBook[i].titleBook, tempStr);

		//ISBN
		journalBook[i].isbn = randomFullISBN();

		//YeaRelease
		strYea = randomFullYeaRelease();
		sizeStr = (sizeof(&strYea) / sizeof(strYea[0]));
		journalBook[i].yeaRelease = (char*) malloc(sizeStr * sizeof(char));
		strcpy(journalBook[i].yeaRelease, strYea);
	}
}

itemAvtor* randomFullAvtor()
{
	itemAvtor tempAvtor;
	itemAvtor *tempCollectionAvtor;
	char *tempStr;

	int sizeStr;

	int countCollectionAvtor = 1 + rand() % 3 + 1;
	tempCollectionAvtor = (itemAvtor*) malloc(
			countCollectionAvtor * sizeof(itemAvtor));
	countAvtor = countCollectionAvtor;

	for (int a = 0; a < countCollectionAvtor; a++)
	{

		tempStr = generateWord();
		sizeStr = (sizeof(&tempStr) / sizeof(tempStr[0]));
		tempAvtor.lastName = (char*) malloc(sizeStr * sizeof(char));
		strcpy(tempAvtor.lastName, tempStr);

		tempStr = generateWord();
		sizeStr = (sizeof(&tempStr) / sizeof(tempStr[0]));
		tempAvtor.name = (char*) malloc(sizeStr * sizeof(char));
		strcpy(tempAvtor.name, tempStr);

		tempStr = generateWord();
		sizeStr = (sizeof(&tempStr) / sizeof(tempStr[0]));
		tempAvtor.middleName = (char*) malloc(sizeStr * sizeof(char));
		strcpy(tempAvtor.middleName, tempStr);

		tempCollectionAvtor[a] = tempAvtor;
	}

	return tempCollectionAvtor;
}

itemISBN randomFullISBN()
{
	itemISBN tempIsbn;

	int countCod;

	countCod = (sizeof(tempIsbn.grupCod1) / sizeof(tempIsbn.grupCod1[0]));
	for (int c = 0; c < countCod; c++)
	{
		tempIsbn.grupCod1[c] = rand() % 9;
	}

	countCod = (sizeof(tempIsbn.grupCod2) / sizeof(tempIsbn.grupCod2[0]));
	for (int c = 0; c < countCod; c++)
	{
		tempIsbn.grupCod2[c] = rand() % 9;
	}

	countCod = (sizeof(tempIsbn.grupCod3) / sizeof(tempIsbn.grupCod3[0]));
	for (int c = 0; c < countCod; c++)
	{
		tempIsbn.grupCod3[c] = rand() % 9;
	}

	countCod = (sizeof(tempIsbn.grupCod4) / sizeof(tempIsbn.grupCod4[0]));
	for (int c = 0; c < countCod; c++)
	{
		tempIsbn.grupCod4[c] = rand() % 9;
	}

	countCod = (sizeof(tempIsbn.grupCod5) / sizeof(tempIsbn.grupCod5[0]));
	for (int c = 0; c < countCod; c++)
	{
		tempIsbn.grupCod5[c] = rand() % 9;
	}

	return tempIsbn;
}

char* randomFullYeaRelease()
{
	int countYear = 4;
	int tempYear[countYear];
	char *str = malloc((countYear * 3) * sizeof(char));
	;

	for (int y = 0; y < countYear; y++)
	{
		if (y == 0)
		{
			tempYear[y] = 1 + rand() % 2;
		}
		else if (y == 1 && tempYear[0] == 1)
		{
			tempYear[y] = 5 + rand() % (9 - 5);
		}
		else if (y == 1 && tempYear[0] == 2)
		{
			tempYear[y] = 0;
		}
		else
		{
			tempYear[y] = rand() % 9;
		}
	}

	sprintf(str, "%d%d%d%d", tempYear[0], tempYear[1], tempYear[2],
			tempYear[3]);

	return str;
}

void printConsoleJournalBook(itemBook *journalBook, int count)
{
	printf("\n");
	int tempCount;
	itemAvtor *tempAvtors;
	itemISBN tempIsbn;

	for (int b = 0; b < count; b++)
	{
		//FIO
		tempCount = journalBook[b].countAvtor;
		tempAvtors = journalBook[b].avtor;
		printf("Avtors:\n");
		for (int a = 0; a < tempCount; a++)
		{

			printf("Avtor %d: %s %s %s\n", a, tempAvtors[a].lastName,
					tempAvtors[a].name, tempAvtors[a].middleName);
		}

		//TitleBook
		printf("Name/Title book: %s\n", journalBook[b].titleBook);

		//ISBN
		tempIsbn = journalBook[b].isbn;
		tempCount = (sizeof(tempIsbn.grupCod1) / sizeof(tempIsbn.grupCod1[0]));
		printf("ISBN: ");
		for (int c = 0; c < tempCount; c++)
		{
			printf("%d", tempIsbn.grupCod1[c]);
		}
		printf("-");
		tempCount = (sizeof(tempIsbn.grupCod2) / sizeof(tempIsbn.grupCod2[0]));
		for (int c = 0; c < tempCount; c++)
		{
			printf("%d", tempIsbn.grupCod2[c]);
		}
		printf("-");
		tempCount = (sizeof(tempIsbn.grupCod3) / sizeof(tempIsbn.grupCod3[0]));
		for (int c = 0; c < tempCount; c++)
		{
			printf("%d", tempIsbn.grupCod3[c]);
		}
		printf("-");
		tempCount = (sizeof(tempIsbn.grupCod4) / sizeof(tempIsbn.grupCod4[0]));
		for (int c = 0; c < tempCount; c++)
		{
			printf("%d", tempIsbn.grupCod4[c]);
		}
		printf("-");
		tempCount = (sizeof(tempIsbn.grupCod5) / sizeof(tempIsbn.grupCod5[0]));
		for (int c = 0; c < tempCount; c++)
		{
			printf("%d", tempIsbn.grupCod5[c]);
		}
		printf("\n");

		//YeaRelease
		printf("Yea Release: %s\n\n", journalBook[b].yeaRelease);
	}
}

//GenerWord
char* generateWord()
{
	int wordLength = 3 + rand() % (3 - 10);
	char *word = malloc((wordLength + 1) * sizeof(char));

	for (int i = 0; i < wordLength; i++)
	{
		if (i == 0)
		{
			word[i] = 'A' + rand() % 26;
		}
		else
		{
			word[i] = 'a' + rand() % 26;
		}
	}
	word[wordLength] = '\0';

	return word;
}

//FindBook
void findBook()
{
	char str[100];
	findTask tempFindTask;
	char pressButton[25];
	printf("Find Book\n");
	printf("Avtor: Last->press 1, Name->press 2, Middle->press 3,\n");
	printf("Title book: ->press 4,\nYea release->press 5\n");

	scanf("%s", str);
	int search = strtol(str, NULL, 10);
	printf("press -> %d\n", search);

	switch (search)
	{
	case 1:
		printf("In Last:");
		scanf("%s", pressButton);
		tempFindTask.last = pressButton;
		tempFindTask.name = NULL;
		tempFindTask.middle = NULL;
		tempFindTask.title = NULL;
		tempFindTask.yea = NULL;
		break;
	case 2:
		printf("In Name:");
		scanf("%s", pressButton);
		tempFindTask.last = NULL;
		tempFindTask.name = pressButton;
		tempFindTask.middle = NULL;
		tempFindTask.title = NULL;
		tempFindTask.yea = NULL;
		break;
	case 3:
		printf("In Middle:");
		scanf("%s", pressButton);
		tempFindTask.last = NULL;
		tempFindTask.name = NULL;
		tempFindTask.middle = pressButton;
		tempFindTask.title = NULL;
		tempFindTask.yea = NULL;
		break;
	case 4:
		printf("In Title book:");
		scanf("%s", pressButton);
		tempFindTask.last = NULL;
		tempFindTask.name = NULL;
		tempFindTask.middle = NULL;
		tempFindTask.title = pressButton;
		tempFindTask.yea = NULL;
		break;
	case 5:
		printf("In Yea release:");
		scanf("%s", pressButton);
		tempFindTask.last = NULL;
		tempFindTask.name = NULL;
		tempFindTask.middle = NULL;
		tempFindTask.title = NULL;
		tempFindTask.yea = pressButton;
		break;

	default:
		printf("error press button!\n");
		findBook();
		break;
	}

	findJournalBook(journalBook, countJournalBook, tempFindTask);
}

void findJournalBook(itemBook *journalBook, int count, findTask findTask)
{
	int countFind = 0;
	int tempCount;
	itemAvtor *tempAvtors;
	findTask.journalFindRezult = (itemBook*) malloc(count * sizeof(itemBook));

	for (int b = 0; b < count; b++)
	{
		//FIO
		tempCount = journalBook[b].countAvtor;
		tempAvtors = journalBook[b].avtor;
		for (int a = 0; a < tempCount; a++)
		{
			if (findTask.last != NULL)
			{
				if (strstr(tempAvtors[a].lastName, findTask.last) != NULL)
				{
					countFind++;
					findTask.journalFindRezult[countFind - 1] = journalBook[b];
				}
			}
			else if (findTask.name != NULL)
			{

				if (strstr(tempAvtors[a].name, findTask.name) != NULL)
				{
					countFind++;
					findTask.journalFindRezult[countFind - 1] = journalBook[b];
				}
			}
			else if (findTask.middle != NULL)
			{

				if (strstr(tempAvtors[a].middleName, findTask.middle) != NULL)
				{
					countFind++;
					findTask.journalFindRezult[countFind - 1] = journalBook[b];
				}
			}
		}

		//TitleBook
		if (findTask.title != NULL)
		{

			if (strstr(journalBook[b].titleBook, findTask.title) != NULL)
			{
				countFind++;
				findTask.journalFindRezult[countFind - 1] = journalBook[b];
			}
		}

		//YeaRelease
		if (findTask.yea != NULL)
		{
			if (strstr(journalBook[b].yeaRelease, findTask.yea) != NULL)
			{
				countFind++;
				findTask.journalFindRezult[countFind - 1] = journalBook[b];
			}
		}
	}

	printConsoleJournalBook(findTask.journalFindRezult, countFind);
}

