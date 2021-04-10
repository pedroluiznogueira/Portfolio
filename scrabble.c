#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

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
	// Creates a for loop, so it can sum poins for each char based on the it's ascii value
	int sum_points = 0;
	for (int i = 0; i < strlen(word); i++)
	{
		if (isalpha(word[i])) // that function takes as input an integer and has an integer as output aswell, it verify if the char is actually a char and return it's ascii value
		{
			int letter = toupper(word[i]) - 'A';
			sum_points += POINTS[letter];
		}
	}
    return sum_points;
}