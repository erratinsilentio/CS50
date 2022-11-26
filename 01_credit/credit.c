#include <stdio.h>
#include <math.h>

int main(void)
{
    long num;
    int size = 0;
    int doubles;
    int rest;

    // get number
    printf("\n");
    printf("enter credit card number: ");
    printf("\n");
    printf("\n");

    scanf("%li", &num);

    long n = num;

    // check size
    while (n > 0)
    {
        n = n / 10;
        size++;
    }

    printf("\n");
    printf("size: %i \n", size);
    printf("\n");

    // check if number is valid

    if (size < 13 && size > 16)
    {
        printf("\n");
        printf("credit card number invalid!\n");
        return 0;
    }

    // make new array to store first half of values
    int arr[size / 2];
    int second_arr[size / 2];
    int power = 1;
    int first_half = 0;
    int second_half = 0;

    printf("first half of numbers: \n");

    for (int i = 0; i < 8; i++)
    {
        arr[i] = (long int)((num % (long int)pow(10, power + 1)) / (long int)pow(10, power)) * 2;
        first_half = first_half + (arr[i] % 10) + (arr[i] / 10);
        power = power + 2;
        printf("%i ", arr[i]);
    }

    printf("\n");
    printf("\n");

    printf("first half: %i \n", first_half);
    printf("\n");

    // make second array
    printf("second half of numbers: \n");

    power = 1;

    for (int i = 0; i < 8; i++)
    {
        second_arr[i] = (long int)((num % (long int)pow(10, power)) / (long int)pow(10, power - 1));
        second_half = second_half + second_arr[i];
        power = power + 2;
        printf("%i ", second_arr[i]);
    }

    printf("\n");
    printf("second half sum: %i \n", second_half);

    int sum = first_half + second_half;

    if (sum % 10 == 0)
    {
        printf("SUCCESS! Number is valid");
    }
    else
    {
        printf("ERROR! Number not valid!");
    }
}
