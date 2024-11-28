#include "listWork.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define TITLE "Executor in List Work\n"
#define INSTRUCTION "Mode: Executor work in task\n"
#define COUNTWORK 15
#define SIZEARR(ARR) (sizeof(&ARR) / sizeof(ARR[0]))

enum GenderWork
{
	Man, Woman
};
int sizeGenderWork = 2;

enum Post
{
	manager, head, secretary, accountant, worker, engineer, security, cleaner
};
int sizePost = 8;

typedef struct
{
	char *lastName;
	char *name;
	char *middleName;
	enum GenderWork gender;
	int age;
	enum Post post;
} itemWork;

typedef struct
{
	int countMan;
	int countWoman;
	int countAll;
	float averageAgeMan;
	float averageAgeWoman;
	float medianAgeMan;
	float medianAgeWoman;
	float averageAgeAll;
	float medianAgeAll;

} itemStatistic;

itemWork *journalWork;
itemStatistic itemStatisticWork;

void randomFullJournalWork(int count);
char* randomWord();
void consoleWriteWork(itemWork *journalWork, int count);
void statistic(itemWork *journalWork, int count);
float median(itemWork *journalWork, int count);
float average(int countTotal, float arg);
float* sequenceData(float *arr, int count);
float* transformArr(itemWork *journalWork, int count);
void consoleWriteStatistic(itemStatistic itemStatisticWork);

void listWork()
{
	printf(TITLE);
	printf(INSTRUCTION);

	randomFullJournalWork(COUNTWORK);
	consoleWriteWork(journalWork, COUNTWORK);

	statistic(journalWork, COUNTWORK);
	consoleWriteStatistic(itemStatisticWork);
}

void randomFullJournalWork(int count)
{
	srand(time(0));
	journalWork = (itemWork*) malloc(count * sizeof(itemWork));

	char *tempStr;
	int sizeStr;

	srand(time(0));
	for (int i = 0; i < count; i++)
	{
		tempStr = randomWord();
		sizeStr = SIZEARR(tempStr);
		journalWork[i].lastName = (char*) malloc(sizeStr * sizeof(char));
		journalWork[i].lastName = tempStr;

		tempStr = randomWord();
		sizeStr = SIZEARR(tempStr);
		journalWork[i].name = (char*) malloc(sizeStr * sizeof(char));
		journalWork[i].name = tempStr;

		tempStr = randomWord();
		sizeStr = SIZEARR(tempStr);
		journalWork[i].middleName = (char*) malloc(sizeStr * sizeof(char));
		journalWork[i].middleName = tempStr;

		journalWork[i].gender = rand() % sizeGenderWork;

		journalWork[i].age = 18 + rand() % (65 - 18);

		journalWork[i].post = rand() % sizePost;
	}
}

void consoleWriteWork(itemWork *journalWork, int count)
{
	printf("\nList Work\n");
	for (int i = 0; i < count; i++)
	{
		printf("Last: %s, ", journalWork[i].lastName);

		printf("Name: %s, ", journalWork[i].name);

		printf("Middle: %s, ", journalWork[i].middleName);

		switch (journalWork[i].gender)
		{
		case Man:
			printf("Gender: Man, ");
			break;
		case Woman:
			printf("Gender: Woman, ");
			break;
		default:
			break;
		}

		printf("Age: %d ", journalWork[i].age);

		switch (journalWork[i].post)
		{
		case manager:
			printf("Post: manager\n");
			break;
		case head:
			printf("Post: head\n");
			break;
		case secretary:
			printf("Post: secretary\n");
			break;
		case accountant:
			printf("Post: accountant\n");
			break;
		case worker:
			printf("Post: worker\n");
			break;
		case engineer:
			printf("Post: engineer\n");
			break;
		case security:
			printf("Post: security\n");
			break;
		case cleaner:
			printf("Post: cleaner\n");
			break;
		default:
			break;
		}
	}
}

//GenerWord
char* randomWord()
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

void statistic(itemWork *journalWork, int count)
{
	itemStatisticWork.countAll = count;
	float totalAgeMan, totalAgeWoman;

	for (int i = 0; i < itemStatisticWork.countAll; i++)
	{
		switch (journalWork[i].gender)
		{
		case Man:
			itemStatisticWork.countMan++;
			totalAgeMan += journalWork[i].age;
			break;
		case Woman:
			itemStatisticWork.countWoman++;
			totalAgeWoman += journalWork[i].age;
			break;
		default:
			break;
		}
	}

	itemWork *tempListMan = (itemWork*) malloc(itemStatisticWork.countMan * sizeof(itemWork));
	itemWork *tempListWoman = (itemWork*) malloc(
						itemStatisticWork.countWoman * sizeof(itemWork));

	int m=0,w=0;
	for (int i = 0; i < itemStatisticWork.countAll; i++)
	{
		switch (journalWork[i].gender)
		{
		case Man:
			tempListMan[m] = journalWork[i];
			m++;
			break;
		case Woman:
			tempListWoman[w] = journalWork[i];
			w++;
			break;
		default:
			break;
		}
	}

	itemStatisticWork.averageAgeMan = average(itemStatisticWork.countMan,
			totalAgeMan);
	itemStatisticWork.averageAgeWoman = average(itemStatisticWork.countWoman,
			totalAgeWoman);
	float totalAgeAll = totalAgeMan + totalAgeWoman;
	itemStatisticWork.averageAgeAll = average(itemStatisticWork.countAll,
			totalAgeAll);

	itemStatisticWork.medianAgeMan = median(tempListMan,
			itemStatisticWork.countMan);
	itemStatisticWork.medianAgeWoman = median(tempListWoman,
			itemStatisticWork.countWoman);
	itemStatisticWork.medianAgeAll = median(journalWork,
			itemStatisticWork.countAll);

}

float median(itemWork *journalWork, int count)
{
	float median;
	float *trArr = transformArr(journalWork, count);

	float *arr = sequenceData(trArr, count);

	if (count % 2 == 0)
	{
		median = (arr[count / 2] + arr[count / 2 + 1]) / 2;
	}
	else
	{
		median = arr[count / 2 + 1];
	}
	return median;
}

float average(int countTotal, float arg)
{
	float aver;
	aver = arg / (float) countTotal;

	return aver;
}

float* sequenceData(float *arr, int count)
{
	int temp;

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return arr;
}

float* transformArr(itemWork *journalWork, int count)
{
	float *temp = malloc(count * sizeof(float));

	for (int i = 0; i < count - 1; i++)
	{
		temp[i] = journalWork[i].age;
	}

	return temp;
}

void consoleWriteStatistic(itemStatistic itemStatisticWork)
{
	printf("\nStatistic Work\n");
	printf("All Work: %d\n", itemStatisticWork.countAll);
	printf("Man Work: %d\n", itemStatisticWork.countMan);
	printf("Woman Work: %d\n", itemStatisticWork.countWoman);
	printf("Average age:\nMan: %4.2f\tWoman: %4.2f\tAll: %4.2f\n",
			itemStatisticWork.averageAgeMan, itemStatisticWork.averageAgeWoman,
			itemStatisticWork.averageAgeAll);
	printf("Median age:\nMan: %4.2f\tWoman: %4.2f\tAll: %4.2f",
			itemStatisticWork.medianAgeMan, itemStatisticWork.medianAgeWoman,
			itemStatisticWork.medianAgeAll);

}
