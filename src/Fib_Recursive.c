/*
 ============================================================================
 Name        : Fib_Recursive.c
 Author      : cmn
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "fib_recurs_asm.h"

long long int fib_recursive(long long int n);

int main(void) {
	long long int fib_index = 0, i, fib_number = 0;

	fib_index = 10;
	puts("Fibonacci Number Generator\n");

	/* puts("Please enter no of terms you want (>0 and < 20)");
	scanf("%lld", &fib_index);		*/

	for (i = 0; (i <= fib_index) && (fib_number >=0); i++)
		{
			fib_number = fib_recursive(i);
			printf("%lld\t", fib_number);
			if (fib_number < 0)
			{
				printf ("Out of range error\n");
				break;
			}

		}

	printf("\nNow for the asm sequence:\n");

	for (i = 0; (i <= fib_index) && (fib_number >=0); i++)
	{
		fib_number = fib_recurs_asm(i);
		printf("%lld\t", fib_number);
		if (fib_number < 0)
		{
			printf ("Out of range error\n");
			break;
		}
	}

	printf("\n");


	return EXIT_SUCCESS;
}


long long int fib_recursive(long long int n)  {
    if(n == 0)
        return 0;
    else if(n == 1)
      return 1;
   else
      return fib_recursive(n - 1) + fib_recursive(n - 2);
}
