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
    int num_letters, num_sentences, num_words;
    string texto;

    texto = get_string("Text: ");
    num_letters = getnum_letters(texto);
    num_sentences = getnum_sentences(texto);
    num_words = getnum_words(texto);
    float grade_level = calculate_grade(num_letters, num_sentences, num_words);

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
        printf("Grade %i\n", (int) grade_level);
    }

}

int getnum_letters(string text)
{
    int sum = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (toupper(text[i]) != ' ' && toupper(text[i]) != '.' && toupper(text[i]) != '!' && toupper(text[i]) != '?' && toupper(text[i]) != '\0')
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
        if (toupper(text[i]) == ' ' || toupper(text[i]) == '\0')
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
        if (toupper(text[i]) == '!' || toupper(text[i]) == '?' || toupper(text[i]) == '.')
        {
            sum = sum + 1;
        }
    }
    return sum;
}

int calculate_grade(int num_letters, int num_sentences, int num_words)
{
    float L = (num_letters / num_words) * 100;
    float S = (num_sentences / num_words) * 100;

    return round(floor(0.0588 * L - 0.296 * S - 15.8));
}






