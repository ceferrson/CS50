#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
bool only_digits(string s);

int main(int argc, string argv[])
{


//check for command line argument(argc equal 2)
 if (argc != 2)

{
    printf("Usage: ./caesar key\n");

    return 1;
}

//checking argv is only digit

bool key = only_digits(argv[1]);

if(key != true)
{
    return 1;
}


//convert argv from string to integer

     int k = atoi(argv[1]);

//prompt user for plaintext
     string plaintext = get_string("Plaintext: ");

//print ciphertext
   printf("Ciphertext: ");

//make ciphertext character uppercase letter of plaintext
    for (int j = 0; j < strlen(plaintext); j++)

    {

    if (isupper(plaintext[j]))

    {

     printf("%c", (plaintext[j] - 65 + k) % 26 + 65);

    }
// make ciphertext character lowercase character of plaintext
    else if (islower(plaintext[j]))

    {
        printf("%c", (plaintext[j] - 97 + k) % 26 + 97);
    }
// if plaintext's character is not letter don't do anything on it, keep its initial version
    else
    {
        printf("%c", plaintext[j]);
    }

}

printf("\n");
return 0;
}


//use own-function for checking argv is digit
bool only_digits(string s)
{
    string key = s;

for (int i = 0; i < strlen(key); i++)

{
    if (!isdigit(key[i]))
    {
        return false;
    }
}
return true;
}



