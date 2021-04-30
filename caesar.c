#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int TOTAL = 26;

int NUM_TABELA[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
char POINTS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char ALPHA[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main(int argc, string argv[])
{
    int cipher;

    if (argc != 2 || atoi(argv[1]) <= 0)
    {
        printf("Erro\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Erro\n");
            return 1;
        }

    }

    string word = get_string("Plain text: ");
    int key = atoi(argv[1]);


    for (int i = 0; i < strlen(word); i++)
    {
        if (islower(word[i]))
        {
            for (int j = 0; j < TOTAL; j++)
            {
                if (word[j] == ALPHA[j])
                {
                    cipher = (NUM_TABELA[j] + key) % 26;
                    word[i] = ALPHA[cipher];
                }
            }
        }
        else if (isupper(word[i]))
        {
            for (int j = 0; j < TOTAL; j++)
            {
                if (word[j] == ALPHA[j])
                {
                    cipher = (NUM_TABELA[j] + key) % 26;
                    word[i] = POINTS[cipher];
                }
            }
        }

    }
    printf("%s\n", word);
}




















