#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// o usuário vai digitar ceaser <key>, na linha de comando.
//  o programa vai pedir em looping o comando certo(ceaser 10) e após, pedir a frase.
// em seguida o sistema vai somar o valor digitado pra tabela ascii

int main(int argc, string argv[2])
{
    if (argc != 2)
    {
        printf("Usage: ./caeser key\n");
        return 1; // goood, work!!!
    }
    int key = atoi(argv[1]) % 26;

    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    string word = get_string("plaintext: ");

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (islower(word[i]))
        {
            word[i] = (word[i] - 'a' + key) % 26 + 'a';
        }
        else if (isupper(word[i]))
        {
            word[i] = (word[i] - 'A' + key) % 26 + 'A';
        }
    }
    printf("ciphertext: %s\n", word);
}
