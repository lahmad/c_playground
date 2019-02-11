
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int validSequence(char sequence[])
{
    int len = strlen(sequence);
    int isValid = 1;
    if (len != 8)
    {
        return 0;
    }

    char *ptr = sequence;
    while (*ptr != '\0')
    {
        char ch = *ptr;
        if (ch != 48 && ch != 49)
        {
            isValid = -1;
            break;
        }
        ptr++;
    }

    return isValid;
}

void flipBits(char sequence[])
{
    char *ptr = sequence;
    while (*ptr != '\0')
    {
        *ptr = *ptr == '0' ? '1' : '0';
        ptr++;
    }
}

void add(char seqOne[], char seqTwo[], char result[])
{
    // Loop through the end
    char *ptr = &result[7];
    int len = strlen(seqOne);
    int carry = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        char seq = seqOne[i];
        char a = seqTwo[i];

        if (seqOne[i] == '0' && seqTwo[i] == '0')
        {
            if (carry == 0)
            {
                *ptr = '0';
            }
            else
            {
                *ptr = '1';
                carry = 0;
            }
        }
        else if ( (seqOne[i] == '1' && seqTwo[i] == '0') || (seqOne[i] == '0' && seqTwo[i] == '1'))
        {
            if (carry == 0)
            {
                *ptr = '1';
            }
            else
            {
                *ptr = '1';
                carry = 1;
            }
        }
        else  if (seqOne[i] == '1' && seqTwo[i] == '1')
        {

            if (carry == 0)
            {
                *ptr = '0';
            }
            else
            {
                *ptr = '1';
            }
            carry = 1;
        }
        ptr--;
    }
}


int getDecimal(char sequence[])
{
    // Check for the first char if 0 +ve number
    char *ptr = sequence;
    char negative[9];

    int sign = 0;

    if (*ptr == '1')
    {
        sign = 1;
        char addition[9];
        memset(addition, '\0', sizeof(addition));

        char result[9];
        memset(result, '0', sizeof(result));
        result[8] = '\0';
        strncpy(negative, sequence, strlen(sequence));
        flipBits(negative);
        int len = strlen(negative);
        negative[8]= '\0';

        addition[0] =  addition[1] = addition[2] = addition[3] = addition[4] = addition[5] = addition[6] ='0';
        addition[7] = '1';

        // Addition with 1
        add(negative, addition, result);
        ptr = result;
    }

    // Loop through the characters and calculate the number
    ptr++;
    int count = 1;
    int number = 0;
    while (*ptr != '\0')
    {
        char ch = *ptr;
        if (ch == '1')
        {
            if (count == 1)
            {
                number += 64;
            }
            else if (count == 2)
            {
                number += 32;
            }
            else if (count == 3)
            {
                number += 16;
            }
            else if (count == 4)
            {
                number += 8;
            }
            else if (count == 5)
            {
                number += 4;
            }
            else if (count == 6)
            {
                number += 2;
            }
            else if (count == 7)
            {
                number += 1;
            }
        }
        count++;
        ptr++;
    }
    return sign == 1 ? (- 1 * number) : number;
}

void display(char sequence[])
{
    printf("\t");
    int len = strlen(sequence);
    for (int i = 0; i < len; i++)
    {
        printf("%c", sequence[i]);
    }

    printf(" (%d)\n", getDecimal(sequence));
}

int main()
{
    char seqOne[9];
    char seqTwo[9];

    printf("Enter the 1st 8 bit sequence: ");
    scanf("%s", &seqOne);

    printf("Enter the 2nd 8 bit sequence: ");
    scanf("%s", &seqTwo);

    if (validSequence(seqOne) && validSequence(seqTwo))
    {
        display(seqOne);
        display(seqTwo);
        printf("\t------------\n");

        char result[9];
        memset(result, '0', sizeof(result));
        result[8] = '\0';

        add(seqOne, seqTwo, result);

        if (seqOne[0] == seqTwo[0] && seqOne[0] != result[0])
        {
            printf("OVERFLOW DETECTED\n");
            return 0;
        }

        printf("\t%s (%d)\n", result, getDecimal(result));
    }
    else
    {
        printf("You must enter two 8-bits valid string sequences\n");
    }

    return 0;
}
