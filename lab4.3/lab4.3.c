#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>

int* get_simples(int count);

int main()
{
	int count;
	while (1)
	{
		printf("\nEnter number.\n");
		scanf("%d", &count);
		printf("\n");
		free(get_simples(count));
	}

	return 0;
}

int* get_simples(int count)
{
	char* simple_numbers = NULL;
	int* result = NULL;
	int number_of_simples = count - 2;
	int i = 0;
	int j = 0;

	simple_numbers = malloc(sizeof(char) * (count - 2));

	for (i = 0; i < count - 2; i++)
	{
		simple_numbers[i] = 1;
	}

	i = 2;
	for (j = i * i; j <= count - 1; j += i)
	{
		if (simple_numbers[j - 2])
		{
			simple_numbers[j - 2] = 0;
			number_of_simples--;
		}
	}

	i = 3;
	while (i * i <= count - 1)
	{
		for (j = i * i; j <= count - 1; j += 2 * i)
		{
			if (simple_numbers[j - 2])
			{
				simple_numbers[j - 2] = 0;
				number_of_simples--;
			}
		}

		i++;	
		while ((simple_numbers[i - 2] == 0) && (i < count))
		{
			i++;
		}		
	}

	result = malloc(sizeof(int) * number_of_simples);

	j = 0;
	for (i = 0; i < count - 2; i++)
	{

		if (j >= number_of_simples + 1)
		{
			printf("Error in get_simples function: number_of_simples was counted wrong.\n\n");
		}

		if ((simple_numbers[i]) && (j < number_of_simples))
		{
			result[j] = i + 2;
			j++;
		}
	}

	printf("Simple numbers:\n");
	for (i = 0; i < number_of_simples; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");

	free(simple_numbers);

	return result;
}