#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Points assigned to each letter of the alphabet

const int TOTAL = 26;
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int ALPHA[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int valid_word(string word);
int compute_score(string word);

int main(void)
{
    string word1, word2;
    int valid_1, valid_2;
    // Get input words from both players
    do
    {
        word1 = get_string("Player 1: ");
        word2 = get_string("Player 2: ");

        valid_1 = valid_word(word1);
        valid_2 = valid_word(word2);
    }
    while (valid_1 > 0 || valid_2 > 0);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int sum = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        for (int j = 0; j < TOTAL; j++)
        {
            if (toupper(word[i]) == ALPHA[j])
            {
                sum = sum + POINTS[j];
            }
        }
    }
    return sum;
}

int valid_word(string word)
{
    int val = 0;
    
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isdigit(word[i]))
        {
            val = val + 1;
        }
        else if (isspace(word[i]))
        {
            val = val + 1;
        }
    }
    return val;
}









