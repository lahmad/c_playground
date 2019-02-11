#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT 256

/**
* This function converts the input string to characters and then
* then call the toupper and map to code.
*/

void morseCode(char input[])
{
  // Morse code representation for A - Z
  const char* code[] = {".-", "-...", "-.-.",
      "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
      "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",
      "-..-", "-.--", "--.."};

  char *ptr = input;
  while (*ptr != '\0')
  {
    char ch = *ptr;
    int ascii = toupper(ch);
    if (ascii == 32)
    {
      printf("%c  ", ch);
    }

    // Ascii from A - Z
    else if (ascii >= 65 && ascii <= 90)
    {
      int index = abs(ascii - 65);
      printf("%s ", code[index]);
    }
    else
    {
        // Non alpha and non space
        printf("?");
    }
    ptr++;
  }
  printf("\n");
}

int main()
{
  char input[MAX_INPUT];
  printf("Enter the sentence to be converted:\n");
  fgets(input, MAX_INPUT, stdin);

  // Set the null terminator
  size_t len = strlen(input);
  input[len - 1] = '\0';

  // function to show morse morse code
  morseCode(input);
  return 0;
}
