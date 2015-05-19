/*
* test_factorial_resursion.c : Defines the entry point for the console application. Procedure for test.
*/


#include "stdio.h"
#include "factorial_recursion.h"

static void interactive(void);

int main(int argc, char* argv[])
{
	int num;
	int result;
	char c;

	c = *argv[1];

	switch(c)
	{
		case '1':
			interactive();
			break;

		case '2':




	return 0;
}

static void interactive(void)
{
	do{
			printf("Enter an integer. -5 to quit\n");
			scanf("%d", &num);
			if(c == 't')
				result = fact_tail(num, 1);
			else
				result = fact(num);
			printf("result= %d\n", result);
		}while(num != -5);
}