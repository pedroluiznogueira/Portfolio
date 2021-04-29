#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int getnum_letters(string text);
int getnum_words(string text);
int getnum_sentences(string text);
int calculate_grade(int num_letters, int num_sentences, int num_words);
void printgrade_level(int grade_level);

int main(void)
{
    int num_letters, num_sentences, num_words, grade_level;
    string texto;

    texto = get_string("Text: ");
    num_letters = getnum_letters(texto);
    num_sentences = getnum_sentences(texto);
    num_words = getnum_words(texto);
    grade_level = calculate_grade(num_letters, num_sentences, num_words);
    
    printgrade_level(grade_level);
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
    float L = (num_letters / (float) num_words) * 100;
    float S = (num_sentences / (float) num_words) * 100;

    return floor(0.0588 * L - 0.296 * S - 15.8);
}

void printgrade_level(int grade_level)
{
    if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade_level <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade_level);
    }
}





