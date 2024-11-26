#include "listStudent.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZEARR(x) (sizeof(&x) / sizeof(x[0]))

#define TITLE "Is filled in List Student\n"
#define INSTRUCTION "Mode: Random Fill/Manual Fill\nPress button R or M\n"
#define RANDOM 1
#define MANUAL 2
#define YES 3
#define NO 4

enum Gender
{
	Man, Woman
};
int sizeGender = 2;

enum NameLesson
{
	Mathematics, Literature, Physics, Chemistry
};
int sizeNameLesson = 4;

int Class[] =
{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int GradeLesson[] =
{ 1, 2, 3, 4, 5 };

typedef struct
{
	char *lastName;
	char *name;
	char *middleName;
	enum Gender gender;
	int class;
	enum NameLesson nameLesson;
	int gradeLesson;
} itemStudent;

int countJournalStudent = 0;
itemStudent *journalStudent;

void printConsoleJournalStudent(itemStudent *journalStudent, int count);
void randomFullJournalStudent(int count);
void manualFullJournalStudent(int count);
char* pressButton(int *sizeStr);
int validationButton();

void listStudent()
{
	printf(TITLE);
	printf(INSTRUCTION);

	int temp = validationButton();
	if (temp == RANDOM)
	{
		countJournalStudent = 10;
		randomFullJournalStudent(countJournalStudent);
		printConsoleJournalStudent(journalStudent, countJournalStudent);
	}
	else if (temp == MANUAL)
	{
		countJournalStudent = 1;
		manualFullJournalStudent(countJournalStudent);
	}
	else
	{
		printf("End Task.");
	}
}

int validationButton()
{
	char *randomChoice =
	{ "R" };
	int randomResult;

	char *manualChoice =
	{ "M" };
	int manualResult;

	char *yesChoice =
	{ "Y" };
	int yesResult;

	char *noChoice =
	{ "N" };
	int noResult;

	char *str = pressButton(malloc(*randomChoice * sizeof(char)));

	randomResult = strcmp(str, randomChoice);
	manualResult = strcmp(str, manualChoice);
	yesResult = strcmp(str, yesChoice);
	noResult = strcmp(str, noChoice);
	free(str);

	if (randomResult == 0)
	{
		return RANDOM;
	}
	else if (manualResult == 0)
	{
		return MANUAL;
	}
	else if (yesResult == 0)
	{
		return YES;
	}
	else if (noResult == 0)
	{
		return NO;
	}
	return 0;
}

char* pressButton(int *sizeStr)
{
	if (*sizeStr == 0)
	{
		*sizeStr = 1;
	}

	char *pressButton = (char*) malloc(*sizeStr * sizeof(char));
	scanf("%s", pressButton);
	printf("press -> %s\n", pressButton);
	return pressButton;
}

void randomFullJournalStudent(int count)
{
	journalStudent = (itemStudent*) malloc(count * sizeof(itemStudent));
	char tempStr[250];
	int sizeStr;
	char *strLastName = "LastName";
	char *strName = "Name";
	char *strMiddleName = "MiddleName";

	srand(time(0));
	for (int i = 0; i < count; i++)
	{
		sizeStr = sprintf(tempStr, "%s%d", strLastName, i);
		journalStudent[i].lastName = (char*) malloc(sizeStr * sizeof(char));
		strcpy(journalStudent[i].lastName, tempStr);

		sizeStr = sprintf(tempStr, "%s%d", strName, i);
		journalStudent[i].name = (char*) malloc(sizeStr * sizeof(char));
		strcpy(journalStudent[i].name, tempStr);

		sizeStr = sprintf(tempStr, "%s%d", strMiddleName, i);
		journalStudent[i].middleName = (char*) malloc(sizeStr * sizeof(char));
		strcpy(journalStudent[i].middleName, tempStr);

		journalStudent[i].gender = rand() % sizeGender;
		journalStudent[i].class = rand() % (sizeof(Class) / sizeof(Class[0]))
				+ 1;
		journalStudent[i].nameLesson = rand() % sizeNameLesson;
		journalStudent[i].gradeLesson = rand()
				% (sizeof(GradeLesson) / sizeof(GradeLesson[0])) + 1;
	}
}

void manualFullJournalStudent(int count)
{
	int tempRezult;
	char *tempStr =
	{ "I" };
	int sizeStr;
	int sizeArr;
	int isCheck = 1;
	int decimalPressButton;

	printf("Add Student? Y/N\n");
	tempRezult = validationButton();

	if (tempRezult == YES)
	{
		if (journalStudent == NULL)
		{
			journalStudent = (itemStudent*) malloc(
					(count) * sizeof(itemStudent));
		}
		else
		{
			journalStudent = (itemStudent*) realloc(journalStudent,
					count * sizeof(itemStudent));
		}


		printf("LastName student?\n");
		char *strLastName = pressButton(malloc(1 * sizeof(char)));
		sizeStr = SIZEARR(strLastName);
		journalStudent[count - 1].lastName = (char*) malloc(
				sizeStr * sizeof(char));
		strcpy(journalStudent[count - 1].lastName, strLastName);
		free(strLastName);

		printf("Name student?\n");
		char *strName = pressButton(malloc(*tempStr * sizeof(char)));
		sizeStr = SIZEARR(strName);
		journalStudent[count - 1].name = (char*) malloc(sizeStr * sizeof(char));
		strcpy(journalStudent[count - 1].name, strName);
		free(strName);

		printf("MiddleName student?\n");
		char *strMiddleName = pressButton(malloc(*tempStr * sizeof(char)));
		sizeStr = SIZEARR(strMiddleName);
		journalStudent[count - 1].middleName = (char*) malloc(
				sizeStr * sizeof(char));
		strcpy(journalStudent[count - 1].middleName, strMiddleName);
		free(strMiddleName);

		while (isCheck)
		{
			printf("Gender student?\nMan->press 0, Woman->press 1\n");
			scanf("%d", &decimalPressButton);
			if (decimalPressButton == Man)
			{
				journalStudent[count - 1].gender = Man;
				isCheck = 0;
			}
			else if (decimalPressButton == Woman)
			{
				journalStudent[count - 1].gender = Woman;
				isCheck = 0;
			}
			else
			{
				isCheck = 1;
				printf("error press button!\n");
			}
		}

		isCheck = 1;
		while (isCheck)
		{
			sizeArr = sizeof(Class) / sizeof(Class[0]);

			printf("Class student?\n1...10 ->press 1...10\n");
			scanf("%d", &decimalPressButton);

			for (int i = 0; i < sizeArr; i++)
			{
				if (decimalPressButton == Class[i])
				{
					journalStudent[count - 1].class = Class[i];
					isCheck = 0;
				}
			}

			if (isCheck == 1)
			{
				printf("error press button!\n");
			}
		}

		isCheck = 1;
		while (isCheck)
		{
			printf(
					"NameLesson?\nMathematics->press 0, Literature->press 1, Physics->press 2, Chemistry->press 3\n");
			scanf("%d", &decimalPressButton);
			switch (decimalPressButton)
			{
			case Mathematics:
				journalStudent[count - 1].nameLesson = Mathematics;
				isCheck = 0;
				break;
			case Literature:
				journalStudent[count - 1].nameLesson = Literature;
				isCheck = 0;
				break;
			case Physics:
				journalStudent[count - 1].nameLesson = Physics;
				isCheck = 0;
				break;
			case Chemistry:
				journalStudent[count - 1].nameLesson = Chemistry;
				isCheck = 0;
				break;

			default:
				isCheck = 1;
				printf("error press button!\n");
				break;
			}
		}

		isCheck = 1;
		while (isCheck)
		{
			sizeArr = sizeof(GradeLesson) / sizeof(GradeLesson[0]);

			printf("GradeLesson?\n1...5 ->press 0...5\n");
			scanf("%d", &decimalPressButton);

			for (int i = 0; i < sizeArr; i++)
			{
				if (decimalPressButton == Class[i])
				{
					journalStudent[count - 1].gradeLesson = GradeLesson[i];
					isCheck = 0;
				}
			}

			if (isCheck == 1)
			{
				printf("error press button!\n");
			}
		}

		count++;
		manualFullJournalStudent(count);
	}
	else if (tempRezult == NO)
	{
		printConsoleJournalStudent(journalStudent, count);
	}
	else
	{
		printf("error press button!\n");
		manualFullJournalStudent(count);
	}
}

void printConsoleJournalStudent(itemStudent *journalStudent, int count)
{
	printf("\n");
	char strGender[20];
	char strLesson[20];

	for (int j = 0; j < count; j++)
	{
		switch (journalStudent[j].gender)
		{
		case Man:
			sprintf(strGender, "Man");
			break;
		case Woman:
			sprintf(strGender, "Woman");
			break;
		default:
			break;
		}

		switch (journalStudent[j].nameLesson)
		{
		case Mathematics:
			sprintf(strLesson, "Mathematics");
			break;
		case Literature:
			sprintf(strLesson, "Literature");
			break;
		case Physics:
			sprintf(strLesson, "Physics");
			break;
		case Chemistry:
			sprintf(strLesson, "Chemistry");
			break;
		default:
			break;
		}

		printf("%s %s %s\n", journalStudent[j].lastName, journalStudent[j].name,
				journalStudent[j].middleName);

		printf("Gender->%s Class->%d Lesson->%s GradeLesson->%d\n\n", strGender,
				journalStudent[j].class, strLesson,
				journalStudent[j].gradeLesson);
	}
}

