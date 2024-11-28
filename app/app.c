#include <stdio.h>
#include <stdlib.h>

#define TASK 3 // 1, 2, 3

#if TASK == 1
#include "listStudent.h"

#elif TASK == 2
#include "listBook.h"

#elif TASK == 3
#include "listWork.h"

#endif

int main()
{
	printf("Start DZ11\n");

#if TASK == 1
	listStudent();
#elif TASK == 2
	listBook();
#elif TASK == 3
	listWork();
#endif

	return 0;
}
