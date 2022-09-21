#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void crypt(char *enc, char *key, char *sel);
void errorHandler();

int main(int argc, char *argv[])
{
    if(argc != 4)
        errorHandler();

    char *enc = argv[1], *key = argv[2], *sel = argv[3];
    if(strlen(enc) != strlen(key))
        errorHandler();

    if(*sel == '1' || *sel == '2')
        crypt(enc, key, sel);
    else
        errorHandler();

    return(0);
}

void crypt(char *enc, char *key, char *sel)
{
    static int arrSize;
    arrSize = strlen(enc);
    char outArr[arrSize];
    
    for(int i = 0; i < arrSize; i++)
    {
        enc[i] = toupper(enc[i]);
        key[i] = toupper(key[i]);

        if(*sel == '1')
            outArr[i] = ((((((int)enc[i]) - 65) + (((int)key[i]) - 65)) % 26) + 65);
        else
        {
            int tmp = (((int)enc[i]) - 65) - (((int)key[i]) - 65);
            if(tmp < 0)
                outArr[i] = (char)((26 - abs(tmp)) + 65);
            else
                outArr[i] = (char)((tmp % 26) + 65);
        }
    }

    for(int i = 0; i < arrSize; i++)
        putchar(outArr[i]);
    putchar('\n');

    return;
}

void errorHandler()
{
        puts("ARGUMENT ERROR");
        exit(1);
}
