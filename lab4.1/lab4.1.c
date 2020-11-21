#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int lenght_of_array = 0;
	double* numbers = NULL;

	scanf("%d", &lenght_of_array);
	numbers = malloc(sizeof(double) * lenght_of_array);

	for (int i = 0; i < lenght_of_array; i++)
	{
		scanf("%lf", &numbers[i]);
	}

	if (lenght_of_array == 0)
	{
		printf("Array is empty.");
	}
	else
	{
		for (int i = 0; i < lenght_of_array; i++)
		{
			printf("%lf ", numbers[i]);
		}
		
	}
	printf("\n");

	free(numbers);
	
	return 0;
}