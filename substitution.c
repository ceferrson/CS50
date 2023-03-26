#include <cs50.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //checking argc
    if (argc !=2)

    {
        printf("Usage: substitution key\n");
        return 1;
    }

//checking validty of  argv/ part1

    if (strlen(argv[1])!=26)
    {
        printf("Substitution key must contain 26 character\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]) ; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Substitution key must be contained by only alphabetic characters\n");
            return 1;
        }

    }

//checking similitary of argv

    for (int j = 0; j < strlen(argv[1]); j++)
    {
        for( int k = 26 ; k >j ; k--)
        {
            if((argv[1][j]) == (argv[1][k]))
            {
                printf("substitution key shouldn't be contained the same characther\n");
                return 1;
            }

            if((argv[1][j]) ==(tolower(argv[1][k])))
            {
                printf("substitution key shouldn't be contained the same characther\n");
                return 1;
            }

            if((argv[1][j]) == (toupper(argv[1][k])))
            {
                printf("substitution key shouldn't be contained the same characther\n");
                return 1;
            }
        }
    }
    // it's will be used for findn nth term of plaintext
    string alphabet ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // it's used to simplfy using argv in equations
    string key  = argv[1];
    // prompt user for plaintext
    string plaintext = get_string("Plaintext: ");
    //printf ciphertext at all
    printf("ciphertext: ");

    for(int n = 0; n < strlen(plaintext); n++)
    {
        if(isalpha(plaintext[n]))// be sure ciphertext process will happen for only alphabetic characters of plaintext
        {
            if(islower(plaintext[n]))
            {
                printf("%c", (tolower(alphabet[plaintext[n]-97]) + tolower(key[plaintext[n]-97])) - tolower(alphabet[plaintext[n]-97]));
            }

           if(!islower(plaintext[n]))
           {
               printf("%c", (alphabet[plaintext[n]- 65]) + (toupper(key[plaintext[n]- 65])) - alphabet[plaintext[n]-65]);
           }
        }

        else// be sure that nonalphabetic characters are not affected by ciphertext process
        {
            printf("%c", plaintext[n]);
        }
    }

    printf("\n");
}
