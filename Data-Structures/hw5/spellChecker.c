#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Loads the contents of the file into the hash map.
 * @param file
 * @param map
 */
void loadDictionary(FILE* file, HashMap* map)
{
    char* word = nextWord(file);
    
    while(word)
    {
        hashMapPut(map,word,1);
        free(word);
        word = nextWord(file);
    }

    free(word);
}



// taken from https://rosettacode.org/wiki/Levenshtein_distance#C
/* s, t: two strings; ls, lt: their respective length */
int levenshtein(const char *s, int ls, const char *t, int lt)
{
        int a, b, c;
 
        /* if either string is empty, difference is inserting all chars 
         * from the other
         */
        if (!ls) return lt;
        if (!lt) return ls;
 
        /* if last letters are the same, the difference is whatever is
         * required to edit the rest of the strings
         */
        if (s[ls] == t[ls])
                return levenshtein(s, ls - 1, t, lt - 1);
 
        /* else try:
         *      changing last letter of s to that of t; or
         *      remove last letter of s; or
         *      remove last letter of t,
         * any of which is 1 edit plus editing the rest of the strings
         */
        a = levenshtein(s, ls - 1, t, lt - 1);
        b = levenshtein(s, ls,     t, lt - 1);
        c = levenshtein(s, ls - 1, t, lt    );
 
        if (a > b) a = b;
        if (a > c) a = c;
 
        return a + 1;
}


/*Takes the word in question, searches the dictionary finding words with a low
levenstein number, then stores them in an array. Then prints the words.
*/
void getMatches(HashMap *map, const char *c)
{
    const int LIMIT = 4; // how many matches you want the spell checker to find
    const int LEV_DIST = 1; //how close you want the word matches to be. Smaller is closer.

    int numMatches = 0;
    char* matches[LIMIT];
    HashLink* link;
    int i = 0;
    int length_c = strlen(c);
    int length_key;

    //loop thru the dictionary and get three matches
    while(i < map->capacity && numMatches < LIMIT)
    {
        link = map->table[i];
        while(link != NULL && numMatches < LIMIT)
        {
            //get string length of key
            length_key = strlen(link->key);

            //if the word is a close match, add it to the matches
            if((levenshtein(link->key, length_key, c, length_c) <= LEV_DIST))
            {
                matches[numMatches] = link->key;
                numMatches++;
            }
            // go to the next link
            link = link->next;
        }

        i++;
    }

    //print the three matches
    for(int k = 0; k < LIMIT; k++)
    {
        printf("%s\n", matches[k]);
    }
}

/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    HashMap* map = hashMapNew(1000);
    
    printf("Opening Dictionary.txt\n\n");
    FILE* file = fopen("dictionary.txt", "r");
    clock_t timer = clock();
    loadDictionary(file, map);
    timer = clock() - timer;
    printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);
    
    char inputBuffer[256];
    int quit = 0;
    while (!quit)
    {
        printf("\nEnter a word or \"/quit\" to quit: ");
        scanf("%s", inputBuffer);
        
        //word is spelled correctly
        if(hashMapContainsKey(map, inputBuffer))
        {
            printf("You spelled it right! Your word is: %s\n", inputBuffer);
        }

        //user wants to quit
        else if (strcmp(inputBuffer, "/quit") == 0)
        {
            quit = 1;
        }

        //couldn't find word; get a few similar words and print them
        else
        {
            printf("Word not found in dictionary. Did you mean: \n\n");
            
            getMatches(map, inputBuffer);
        }
    }

    hashMapDelete(map);
    return 0;
}