#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

const int TOTAL = 26;

int NUM_TABELA[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
char LET_TABELAU[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char LET_TABELAL[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

string cypher_text(string plainText, int cypher, int key);

int main(int argc, string argv[])
{
    
    int key, cypher;
    string plainText;

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

    plainText = get_string("Plain text: ");
    
    key = atoi(argv[1]);
    
    for (int i = 0; i < strlen(plainText); i++)
    {
        if (isalpha(islower(plainText[i])))
        {
            for (int j = 0; j < TOTAL; j++)
            {
                if (plainText[i] == LET_TABELAL[j])
                {
                    cypher = ( NUM_TABELA[i] + key ) % 26;
                }
             }
             plainText[i] = LET_TABELAL[cypher];        
            
        }
        
        else if (isalpha(isupper(plainText[i])))
        {
            for (int j = 0; j < TOTAL; j++)
            {
                if (plainText[i] == LET_TABELAU[j])
                {;
                    cypher = ( NUM_TABELA[i] + key ) % 26;
                }
            }
            plainText[i] = LET_TABELAU[cypher];
        }
        
    }
    printf("%s", plainText);
    
}




















