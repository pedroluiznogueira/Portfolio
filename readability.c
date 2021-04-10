#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Declaration of all the functions used 

int getNumLetters(string text);
int getNumSentences(string text);
int getNumWords(string text);
int getGradeLevel(int numLetters, int numSentences, int numWords);
void printGradeLevel(int gradeLevel);

int main(int argc, string argv[])
{
	string text = get_string("Text: "); // Asks for a text from user
	
	// Shows the type of every output of the functions

	int numLetters = getNumLetters(text);
	int numSentences = getNumSentences(text);
	int numWords = getNumWords(text);

	int gradeLevel = getGradeLevel(numLetters, numSentences, numWords);

	printGradeLevel(gradeLevel);

}

void printGradeLevel(int gradeLevel) // Print the grade level of the text
{
	if (gradeLevel <= 1)
	{
		printf("Before Grade 1\n");
	}
	else if (gradeLevel >= 16)
	{
		printf("Grade 16+\n");
	}
	else
	{
		printf("Grade %i\n", gradeLevel );
	}
}

int getGradeLevel(int numLetters, int numSentences, int numWords) // Calculate the formula
{
	float S = (numSentences / (float)numWords) * 100;
	float L = (numLetters / (float)numWords) * 100;

	return round(0.0588 * L - 0.296 * S - 15.8);
}

int getNumLetters(string text) // Calculate the number of letters in the text
{
	int numLetters = 0;
	for (int i = 0; i < strlen(text); i++)
	{
		if (isalpha(text[i]))
		{
			numLetters += 1;

		}
	}
	return numLetters;
}

int getNumWords(string text) // Calculate the number of numbers in the text
{
	int numWords = 0;
	for (int i = 0; i < strlen(text); i++)
	{
		if (text[i] == ' ')
		{
			numWords += 1;
		}
	}
	return numWords + 1;
}

int getNumSentences(string text) // Calculate the number of sentences in the text
{
	int numSentences = 0;
	for (int i = 0; i < strlen(text); i++)
	{
		if (text[i] == '.' || text[i] == '!' || text[i] == '?')
		{
			numSentences += 1;
		}
	}
	return numSentences;
}