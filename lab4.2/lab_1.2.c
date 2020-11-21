#include <stdio.h>
#include <math.h>

int is_simple(int number);

int is_simple(int number)
{
    if (number <= 1)
    {
        printf("Number less than 2. Can't be simple or composite number.\n");

        return -1;
    }
    else
    {
        for (int i = 2; i <= (int)sqrt((double)number); i++)
        {
            if (number % i == 0)
            {
                return 0;
            }
        }
    }

    return 1;
}
