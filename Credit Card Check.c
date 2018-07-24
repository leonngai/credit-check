//this program prompts the user for a credit card number and reports if the input is a valid AMEX, MASTERCARD or VISA card number

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    int temp, sum, sum_one = 0, sum_two = 0;
    int m,n;
    char name[100];
    char product[100];
    long long number = get_long_long("Number: ");
    sprintf(name, "%lld", number);

    if (strlen(name) % 2 == 0)
    {
        m = 1;
        n = 0;
    }
    else
    {
        m = 0;
        n = 1;
    }

//check if card is AMEX

    if (strlen(name) == 15 && name[0] == '3' && (name[1] == '4' || name[1] == '7'))
    {
        for (int i = m; i < strlen(name); i = i + 2)
        {
            temp = name[i] - 48;
            sum_two = sum_two + temp;
        }

        for (int i = n; i < strlen(name); i = i + 2)
        {
            temp = (name[i] - 48) * 2;
            sprintf(product, "%i", temp);

            for (int j = 0; j < strlen(product); j++)
            {
                temp = product[j] - 48;
                sum_one = sum_one + temp;
            }
        }

        sum = sum_one + sum_two;

        if (sum % 10 == 0)
        {
            printf("AMEX\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }

//check if card is MASTERCARD

    else if (strlen(name) == 16 && name[0] == '5' && (name[1] == '1' || name[1] == '2' || name[1] == '3' || name[1] == '4'
             || name[1] == '5'))
    {
        for (int i = m; i < strlen(name); i = i + 2)
        {
            temp = name[i] - 48;
            sum_two = sum_two + temp;
        }

        for (int i = n; i < strlen(name); i = i + 2)
        {
            temp = (name[i] - 48) * 2;
            sprintf(product, "%i", temp);

            for (int j = 0; j < strlen(product); j++)
            {
                temp = product[j] - 48;
                sum_one = sum_one + temp;
            }
        }

        sum = sum_one + sum_two;

        if (sum % 10 == 0)
        {
            printf("MASTERCARD\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }

//check if card is VISA

    else if ((strlen(name) == 13 || strlen(name) == 16) && name[0] == '4')
    {
        for (int i = m; i < strlen(name); i = i + 2)
        {
            temp = name[i] - 48;
            sum_two = sum_two + temp;
        }

        for (int i = n; i < strlen(name); i = i + 2)
        {
            temp = (name[i] - 48) * 2;
            sprintf(product, "%i", temp);

            for (int j = 0; j < strlen(product); j++)
            {
                temp = product[j] - 48;
                sum_one = sum_one + temp;
            }
        }

        sum = sum_one + sum_two;

        if (sum % 10 == 0)
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}


