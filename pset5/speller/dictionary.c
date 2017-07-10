/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dictionary.h"

// global variable root
struct nod

// global variable word counter
int dictionaryWordCounter;
bool unloadHelp(struct node *lowerNode);

// create a new node that is setup = malloc(sizeof(node). this one just shows visually what malloc(sizeof(node)) does.
struct node *getNode(void)
{
    // create a new note
    node *newNode = malloc(sizeof(struct node));
    
    // once you created a new new, set the word value to false and set all children to NULL
    if (newNode)
    {
        newNode -> is_word = false;
        for (int i = 0; i < 27; i++)
        {
            newNode -> children[i] = NULL;
        }
    }
    else 
    {
        free(newNode);
        return 0;
    }
    return newNode;
}



/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // helper letterNumber
    int letterNumber;
    
    // create a copy of the root location
    node *helperNode = root;
    
    // go through the total length of the word, 1 character at the time.
    for (int i = 0, lenwrd = strlen(word); i < lenwrd; i++)
    {
        /* 
        check the value of character and assign a number, e.g. 'a' / 'A' = 0, 'b'/'B' = 1...
        if apostrhopy is used give it number 26 directly.
        */
        if (isalpha(word[i]))
        {
            if (isupper(word[i]))
            {
                letterNumber = word[i] - 'A';
            }
            else
            {
                letterNumber = word[i] - 'a';
            }
        }
        else if (word[i] == '\'')
        {
            letterNumber = 26;
        }
        else
        {
            return false;
        }
        
        // if node has no child with the current letter then return false
        if (helperNode -> children[letterNumber] == NULL)
        {
            return false;
        }
        else
        {
            //if there is a children with the letter then make it the new starting point for the loop to continue.
            helperNode = helperNode -> children[letterNumber];
        }
    }
    
    /* 
    once gone through the whole letters of the word and swopped each time the starting node, check now if the current not on the last letter has a is_word assigned to true,
    if yes, say that this word is in the dictionary.
    */
    
    if (helperNode -> is_word)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // create helper word char that is long enough that it holds 1 word at the time.
    char word[LENGTH];
    
    // create helper function that helps on the current letter number
    int letterNumber;
    
    // open file
    FILE *inptr = fopen(dictionary, "r");
    
    // check if file opens.
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictionary);
        return false;
    }
    
    // create a node (see above how)
    root = getNode();
    
    // if node doesn't get create create error
    if (root == NULL)
    {
        return false;
    }
    
    // go through the input file and scan each word
    while (fscanf(inptr, "%s", word) != EOF)
    {
        // copy the root path to the new Arch path
        node *newArch = root;
    
        // for each letter in the word
        for (int i = 0, wrdlen = strlen(word); i < wrdlen; i++)
        {
            // check if it is a letter
            if (isalpha(word[i]))
            {
                // check if it upper or lower case
                if (isupper(word[i]))
                {
                    // create an index number, in which A=0, B=1...Z=25
                    letterNumber = word[i] - 'A';
                }
                else
                {
                    // create an index number, in which a=0, b=1...z=25
                    letterNumber = word[i] - 'a';
                }
            }
            // if not letter check it is an apostrophy
            else if (word[i] == '\'')
            {
                // create an index number, in which '=26
                letterNumber = 26;
            }
            else
            {
                return false;
            }
            
            // if the new arch path has no child with the index number that relates to the letter of the word scanned
            if (newArch -> children[letterNumber] == NULL)
            {
                // create a new node -> see above how
                newArch -> children[letterNumber] = getNode();
                if (newArch -> children[letterNumber] == NULL)
                {
                    printf("Can't create children note");
                    free(newArch);
                    return false;
                }
            }
            
            // then move down the new arch by assigning the newly created arch index as starting point
            newArch = newArch -> children[letterNumber];
        }
        // once done set the new arch as word
        newArch -> is_word = true;
        
        // every time a new word has been created, count up on the global word counter
        dictionaryWordCounter++;
    }
    return true;
    
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // return global word counter
    if (dictionaryWordCounter > 0)
    {
        return dictionaryWordCounter;
    }
    else
    {
        return 0;
    }
        
}


/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // copy root to a new placeholder node
    node *empty = root;
    
    // load the helper function below.
    unloadHelp(empty)
    return true;
    
}

bool unloadHelp(struct node *lowerNode)
{
    // load the current node and go through all their children arches
    for (int i=0; i < 27; i++)
    {
        /* if a arch is not null, not the last bottom of the arch, restart this process with the next level and test again.
        once all the brances do return Null, free the current node and move back up the list
        */
        if (lowerNode -> children[i] != NULL)
        {
            unloadHelp(lowerNode ->children[i]);
        }
    }
    free(lowerNode);
    return true;
}