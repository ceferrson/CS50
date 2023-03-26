#include <cs50.h>
#include <stdio.h>

int main(void)
{

int arr[] = {2,9,5,3,7,1};
int smallOne = 0;
int bigOne = 0;

     for (int i = 0; i < 6; i++) // for compare one element
     {
         for (int j = i+1; j < 6; j++)// for compare one element through array
         {
             if (arr[i] > arr[j])
             {
                 smallOne = arr[j];
                 bigOne = arr[i];
                 arr[i] = smallOne;
                 arr[j] = bigOne;
             }

         }

     }

printf("%i %i %i %i %i %i\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);

}
