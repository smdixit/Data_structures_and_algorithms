/*
* factorial_resursion.c : Defines the entry point for the console application.
*/
#define FACTORIAL_RECURSION_C

#include "stdio.h"

static int fact(int n);
static int fact_tail(int n, int a);

int main(int argc, char* argv[])
{
	int num;
	int result;
	char c;

	c = *argv[1];

	do{
		printf("Enter an integer. -5 to quit\n");
		scanf("%d", &num);
		if(c == 't')
			result = fact_tail(num, 1);
		else
			result = fact(num);
		printf("result= %d\n", result);
	}while(num != -5);

	return 0;
}

int fact(int n)
{
	if(n < 0)
		return -1;
	else if((n == 0) || (n == 1))
		return 1;
	else
		return n*fact(n-1);
}

int fact_tail(int n, int a)
{
	if(n < 0)
		return -1;
	else if((n == 0) || (n == 1))
		return a;
	else
		a = fact_tail(n-1, a);

	return a*n;
}