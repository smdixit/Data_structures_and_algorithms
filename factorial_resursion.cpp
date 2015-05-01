// factorial_resursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"

static int fact(int n);

int _tmain(int argc, _TCHAR* argv[])
{
	int num;
	int result;

	do{
		printf("Enter an integer. -5 to quit\n");
		scanf("%d", &num);
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