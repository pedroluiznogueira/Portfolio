#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_value = hash(word);
    
    if (table[hash_value] == NULL)
    {
        return false;
    }
    else
    {
        struct node *p;
        p = table[hash_value];
        
        while (p != NULL && (strcasecmp(word, p->word) == 0))
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int lenght = strlen(word);
    unsigned int hash_value = 0;
    for (int i = 0; i < lenght; i++)
    {
        hash_value += tolower(word[i]);
        hash_value = hash_value * tolower(word[i]) % N;
    }
    return hash_value;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dict_ptr = fopen(dictionary, "r");
    if (dict_ptr == NULL)
    {
        return false;
    }
    
    char buffer[LENGTH + 1];
    
    while (fscanf(dict_ptr, "%s", buffer) != EOF)
    {
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        if (temp == NULL)
        {
            return false;
        }
        temp->next = NULL;
    
        strcpy(temp->word, buffer);
    
        int hashCode = hash(temp->word);
        
        if (table[hashCode] == NULL)
        {
            table[hashCode] = temp;
        }
        else
        {
            temp->next = table[hashCode];
            table[hashCode] = temp;
        }
    }
    fclose(dict_ptr);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int word_count = 0;
    
    for (int i = 0; i < N; i++)
    {
        struct node *p;
        p = table[i];
        if (p != NULL)
        {
            p = p->next;
            word_count++;
        }
    }
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        struct node *temp2;
        temp2 = table[i];
        struct node *temp1;
        temp1 = table[i];
        
        while (temp2 != NULL)
        {
            temp1 = temp2;
            temp2 = temp2->next;
            free(temp1);
        }
        
    }
    return true;
}
