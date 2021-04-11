#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[])
{
	if (argc != 2)
	{
		printf("Usage: ./caesar key\n");
		return 1;
	}

	for (int k = 0; k < strlen(argv[1]); k++)
	{
		if (isalpha(argv[1][k]))
		{
			printf("Usage: ./caesar key\n");
			return 1;
		}
	}

	int k = atoi(argv[1]) % 26; // if k > 26, store the division remainder instead
	string plain_text = get_string("plain_text: ");

	printf("ciphertext: ");

	for (int i = 0; i < strlen(plain_text); i++)
	{
		if (!isalpha(plain_text[i]))
		{
			printf("%c", plain_text[i]);
			continue;
		}

		int ascii_offset = isupper(plain_text[i]) ? 65 : 97;

		int pi = plain_text[i] - ascii_offset;
		int ci = (pi + k) % 26;

		printf("%c", ci + ascii_offset );
	}

	printf("\n");
	return 0;
}