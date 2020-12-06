#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

// Node representation
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

int wordLoadedCount = 0;

bool check(const char *word)
{
    int index = hash(word);

    for (node *tmp = table[index]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(word, tmp->word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int index = 26;
    int fletter = (int)word[0];

    if (fletter >= 65 && fletter <= 90)
    {
        index = fletter - 65;
    }
    else if (fletter >= 97 && fletter <= 122)
    {
        index = fletter - 97;
    }

    if (index == 26)
    {
        printf("We could not hash %s.\n", word);
        return -1;
    }

    return index;
}

bool load(const char *dictionary)
{

    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        unload();
        return false;
    }

    char storedWord[LENGTH + 1];

    while(fscanf(file, "%s", storedWord) != EOF)
    {
        node *newNode = malloc(sizeof(node));

        if (newNode == NULL)
        {
            printf("Your program ran out of memory\n");
            return false;
        }
        strcpy(newNode->word, storedWord);
        newNode->next = NULL;

        wordLoadedCount++;

        int index = hash(storedWord);

        if (table[index] == NULL)
        {
            table[index] = newNode;
            newNode->next = NULL;
        }

        else if (table[index] != NULL)
        {

            newNode->next = table[index];
            table[index] = newNode;

        }


    }
    fclose(file);

    return true;
}

unsigned int size(void)
{

    if (wordLoadedCount >= 1)
    {
        return wordLoadedCount;
    }
    return 0;
}
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
        node *tmp = table[i]->next;
        free(table[i]);
        table[i] = tmp;
        }

        if (table[i] != NULL)
        {
            printf("Something went wrong while freeing memory in unload() function.\n");
            return false;
        }
    }
    return true;

}
