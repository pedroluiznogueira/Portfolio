#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int getnum_letters(string text);
int getnum_words(string text);
int getnum_sentences(string text);
int calculate_grade(int num_letters, int num_sentences, int num_words);

int main(void)
{
    int num_letters, num_sentences, num_words, grade_level;
    string texto;

    texto = get_string("Text: ");
    num_letters = getnum_letters(texto);
    num_sentences = getnum_sentences(texto);
    num_words = getnum_words(texto);
    grade_level = calculate_grade(num_letters, num_sentences, num_words);

    if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade_level);
    }

}

int getnum_letters(string text)
{
    int sum = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] != ' ' && text[i] != '.' && text[i] != '!' && text[i] != '?' && text[i] != '\0')
        {
            sum = sum + 1;
        }
    }
    return sum;
}

int getnum_words(string text)
{
    int sum = 0;

    for (int i = 0; i <= strlen(text); i++)
    {
        if (text[i] == ' ' || text[i] == '\0')
        {
            sum = sum + 1;
        }
    }
    return sum;
}

int getnum_sentences(string text)
{
    int sum = 0;

    for (int i = 0; i <= strlen(text); i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sum = sum + 1;
        }
    }
    return sum;
}

int calculate_grade(int num_letters, int num_sentences, int num_words)
{
    int L, S;

    L = round(num_letters / num_words) * 100;
    S = round(num_sentences / num_words) * 100;

    return round(0.0588 * L - 0.296 * S - 15.8);
}






