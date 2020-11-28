#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int value;
	int is_even;
} Number;

int main()
{
	int lenght_of_array = 0;
	Number* array_of_numbers;

	scanf("%d", &lenght_of_array);
	array_of_numbers = malloc(sizeof(Number) * lenght_of_array);

	for (int i = 0; i < lenght_of_array; i++)
	{
		scanf("%d", &array_of_numbers[i].value);

		array_of_numbers[i].is_even = (array_of_numbers[i].value + 1) % 2;
		array_of_numbers[i].is_even *= array_of_numbers[i].is_even;
	}

	if (lenght_of_array == 0)
	{
		printf("Array is empty.");
	}
	else
	{
		for (int i = 0; i < lenght_of_array; i++)
		{
			printf("%d ", array_of_numbers[i].value);
			if (array_of_numbers[i].is_even)
			{
				printf("is even.\n");
			}
			else
			{
				printf("is odd.\n");
			}
		}
	}

	free(array_of_numbers);

	return 0;
}