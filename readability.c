#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int num_letters(string texto);
int num_words(string texto);
int num_sentences(string texto);
int grade_level(int total_letters, int total_sentences);

int main(void)
{
    int total_letters, total_words, total_sentences, grade;
    string text;
    text = get_string("Text: ");
    
    total_letters = num_letters(text);
    total_words = num_words(text);
    total_sentences = num_sentences(text);
    grade = grade_level(total_letters, total_sentences);
    
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

int grade_level(int total_letters, int total_sentences)
{
    int L, S;
    
    L = round(total_letters / 100);
    S = round(total_sentences / 100);
    
    int grade = round(0.0588 * L - 0.296 * S - 15.8);
    return grade;
    
}