#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>

//#include"C:\Users\199930\source\repos\study\lab4\lab4.2\lab_1.2.c"

int* get_simples(int count);

int main()
{
	int count;
	while (1)
	{
		scanf("%d", &count);
		printf("\n");
		free(get_simples(count));
	}

	return 0;
}

int* get_simples(int count)
{
	char* simple_numbers;
	int* result;
	int number_of_simples = count - 2;
	int i = 0;
	int j = 0;

	simple_numbers = malloc(sizeof(char) * (count - 2));

	/*if (simple_numbers == NULL)
	{
		printf("\nsimple_numbers = NULL!!!");
		exit(5);
	}*/

	for (i = 0; i < count - 2; i++)
	{
		simple_numbers[i] = 1;
	}

	i = 2;
	for (j = i * i; j <= count - 1; j += i)
	{
		//printf("%d: %d\n", j, simple_numbers[j - 2]);
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
			//printf("%d: %d\n", j, simple_numbers[j - 2]);
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

	/*printf("simple_numbers:\n");
	for (i = 0; i < count - 2; i++)
	{
		printf("%d: %d\n", i + 2, simple_numbers[i]);
	}
	printf("\n");*/
	/*printf("result:\n");
	for (i = 0; i < number_of_simples; i++)
	{
		printf("%d: %d\n", i, result[i]);
	}*/

	/*int help_test = (count - 2) / 10;
	for (i = 0; i < count - 2; i++)
	{
		if (i % help_test == 0) 
		{
			printf("\nWorking. Current number = %d.\n", i + 2);
		}
		if (simple_numbers[i] == is_simple(i + 2))
		{
			//printf("%d is fine.\n", i + 2);			
		}
		else
		{
			printf("%d is wrong!!!\n", i + 2);
		}
	}*/

	free(simple_numbers);

	return result;
}