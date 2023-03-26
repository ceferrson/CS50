#include <cs50.h>
#include <stdio.h>

int main(void)
{

int arr[] = {2,9,5,3,7,1};
int firstOne = 0;
int secondOne = 0;

   for (int i = 0; i < 5; i++) // for repeating n-1 time
    {
        for (int j = 0; j < 5; j++) // compare neighboor pairs
        {
            if (arr[j] > arr[j+1])
            {
                firstOne = arr[j];
                secondOne = arr[j+1];
                arr[j]= secondOne;
                arr[j+1] = firstOne;
            }

        }

    }
    printf("%i %i %i %i %i %i\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);

}

