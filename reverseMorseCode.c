#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
* Performs the look in the map of codes
*/
char getAscii(char letter[])
{
    // Morse code representation for A - Z
    const char* code[] = {".-", "-...", "-.-.",
      "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
      "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",
      "-..-", "-.--", "--.."};

    char ch = '\0';

    // Lookup
    int index = 0;
    for (; index < 26; index++)
    {
        if (strcmp(letter, code[index]) == 0)
        {
            ch = (65 + index);
            break;
        }
    }

    return ch == '\0' ? '?' : ch;
}

/**
* Takes in a morse coded input and reverse it back to message
*/
void reverseMorseCode(char input[])
{
    char* ptr = input;
    while (*ptr != '\0')
    {
        char *word = ptr;
        char letter[5];
        int counter = 0;
        memset(letter, '\0', sizeof(letter));

        if (*ptr == 32)
        {
            printf("%c", *ptr);
            ptr++;
        }
        else
        {
            while (*word != 32 && *word != '\0')
            {
                letter[counter++] = *word;
                word ++;
            }

        printf("%c", getAscii(letter));

        // Already increment for space
        ptr = word;
        ptr++;
        }
        }

}

int main()
{

    char input[512];
    memset(input, '\0', sizeof(input));

    printf("Enter the sequence: \n");
    fgets(input, 512,stdin);

    size_t len = strlen(input);
    input[len - 1] = '\0';

    reverseMorseCode(input);
    printf("\n");
    return 0;
}

