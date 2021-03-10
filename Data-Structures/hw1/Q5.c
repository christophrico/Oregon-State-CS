/* CS261- Assignment 1 - Q.5*/
/* Name: Christopher Rico
 * Date: 9/30/17
 * Solution description: Program that gets a string from the user, then converts
                        it to StIcKy CaPs
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch)
{
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch)
{
     return ch-'A'+'a';
}

void sticky(char* word)
{
     /*Convert to sticky caps */
     /*Odd letters become upper */
     for(int i = 0; i < strlen(word)-1; i++)
     {
      if(i % 2 != 0)
      {
        if (word[i] >= 'A' && word[i] <= 'Z')
            word[i] = toLowerCase(word[i]);
      }

      else
      {
        if(word[i] >= 'a' && word[i] <= 'z')
            word[i] = toUpperCase(word[i]);
      }
    }
}

int main()
{
  char userString[256];
  /*Read word from the keyboard using scanf*/
  printf("Input a word to be converted to sticky caps.\n");
  scanf("%s", userString);

  /*Call sticky*/
  sticky(userString);

  /*Print the new word*/
  printf("%s\n", userString);

    return 0;
}
