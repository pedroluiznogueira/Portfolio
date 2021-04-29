#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int num_letters(string texto);
int num_words(string texto);
int num_sentences(string texto);

int main(void)
{
    int total_words, total_letters, total_sentences, grade, L, S;
    string text;
    text = get_string("Text: ");

    total_words = num_words(text);
    total_letters = num_letters(text);
    total_sentences = num_sentences(text);

    L = round(total_letters / 100);
    S = round(total_sentences / 100);
    grade = round(0.0588 * L - 0.296 * S - 15.8);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

}

int num_letters(string texto)
{
    int sum = 0;

    for (int i = 0; i < strlen(texto); i++)
    {
        if (texto[i] != ' ' && texto[i] != '.' && texto[i] != '!' && texto[i] != '?' && texto[i] != '\0')
        {
            sum = sum + 1;
        }
    }
    return sum;
}

int num_words(string texto)
{
    int sum = 0;

    for (int i = 0; i <= strlen(texto); i++)
    {
        if (texto[i] == ' ' || texto[i] == '\0')
        {
            sum = sum + 1;
        }
    }
    return sum;
}

int num_sentences(string texto)
{
    int sum = 0;

    for (int i = 0; i <= strlen(texto); i++)
    {
        if (texto[i] == '!' || texto[i] == '?' || texto[i] == '.')
        {
            sum = sum + 1;
        }
    }
    return sum;
}
