#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    //Amanhã vejo isso, preciso ler alguns livros pra ter mais prior técnico
    // Open the memory card
    FILE *carta = fopen(argv[1], "r");

    if(carta == NULL)
    {
        printf("Cold not open file.\n");
        return 1;
    }

    uint8_t buffer[BLOCK_SIZE]; //LEMBRAR DISSO SE DER ERROOOOO!!
    FILE *img = NULL;

    int img_count = 0;

    char filename[8];
    // While there's still data left to read from the memory card
    while (fread(buffer, 1, BLOCK_SIZE, carta) == BLOCK_SIZE)
    {
        //puxar o jpeg do começo
        if(buffer[0] == 0xff &&
           buffer[1] == 0xd8 &&
           buffer[2] == 0xff &&
          (buffer[3] & 0xf0) == 0xe0)
        {
            if(img != NULL)
            {
                fclose(img);
            }
            sprintf(filename, "%03d.jpg", img_count);

            img = fopen(filename, "w");

            img_count++;
        }
        //agr vai
        if(img != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }

    }
            //fecha tudo
        if(img != NULL)
        {
            fclose(img);
        }
        fclose(carta);

        return 0;
        // Create JPEGs from the data


}
