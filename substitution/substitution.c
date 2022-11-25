#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    // CHECK IF ARGUMENTS EXIST
    if (argc != 2)
    {
        printf("\n=====! give only 1 argument !=====\n");
        return 1;
    }

    // DECLARE OUR KEY AND ORIGINAL ALPHABET ARRAYS
    char key[26] = "YTNSHKVEFXRBAUQZCLWDMIPGJO";
    char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // STORE OUR ARGUMENT IN A VARIABLE
    char plaintext[strlen(argv[1])];
    stpcpy(plaintext, argv[1]);
    char plain_to_upper[strlen(plaintext)];

    // TURN ARGUMENT TO UPPERCASE
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        plain_to_upper[i] = toupper(plaintext[i]);
    }

    // PRINT WHAT WE HAVE TO THE SCREEN
    printf("\n");
    printf("===== plain: %s \n===== key: %s \n", plain_to_upper, key);
    printf("\n");

    // CHECK PLACE IN ALPHABET FOR EACH LETTER
    int corresponding[strlen(plaintext)];
    int num = 0;

    while (num < strlen(plaintext))
    {
        for (int i = 0, n = strlen(alphabet); i < n; i++)
        {
            if (plain_to_upper[num] == alphabet[i])
            {
                corresponding[num] = i;
                num = num + 1;
            }
        }
    }

    // RETURN A STRING WITH CORRESPONDING NUMBERS
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%i ", corresponding[i]);
    }

    num = 0;
    char crypto[strlen(plaintext)];

    // SWITCH NUMBERS FOR LETTERS FROM KEY
    printf("\n");
    printf("\n");
    printf("===== crypted message: ");

    while (num < strlen(plaintext))
    {
        crypto[num] = key[corresponding[num]];
        printf("%c", crypto[num]);
        num = num + 1;
    }

    printf("\n");
    printf("\n");
}