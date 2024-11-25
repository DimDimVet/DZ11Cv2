#include <stdio.h>
#include <stdlib.h>

#define TASK 2 // 1, 2, 3

#if TASK == 1
#include "listStudent.h"

#elif TASK == 2
#include "listBook.h"

#elif TASK == 3
//void listWork();
#endif

int main()
{
	printf("Start DZ11\n");

#if TASK == 1
	listStudent();
#elif TASK == 2
	listBook();
	#elif TASK == 3
	//
	#endif

	return 0;
}
