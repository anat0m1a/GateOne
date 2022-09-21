#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void decrypt(char *enc, char *key)
{
    if(strlen(enc) != strlen(key))
    {
        printf("ERROR: Key is incorrect length");
        return;
    }

    char outArr[10];

    for(int i = 0; i < 9; i++)
    {
        enc[i] = toupper(enc[i]);
        key[i] = toupper(key[i]);

        int tmp = (((int)enc[i]) - 65) - (((int)key[i]) - 65);
        if(tmp < 0)
            outArr[i] = (char)((26 - abs(tmp)) + 65);
        else
            outArr[i] = (char)((tmp % 26) + 65);
    }

    printf("Nice one!\nFlag: ");
    for(int i = 0; i < 9; i++)
        putchar(outArr[i])
    putchar('\n')

    return;
}
