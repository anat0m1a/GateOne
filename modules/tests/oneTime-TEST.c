#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void crypt(char *enc, char *key, char *sel);
void errorHandler();

int main(int argc, char *argv[])
{
    if(argc != 4)
        errorHandler();

    char *enc = argv[1], *key = argv[2], *sel = argv[3];

    if(*sel == '1' || *sel == '2')
        crypt(enc, key, sel);
    else
        errorHandler();

    return(0);
}

void crypt(char *enc, char *key, char *sel)
{
    // THIS NEEDS COMPLETING
    return;
}

void errorHandler()
{
        puts("ARGUMENT ERROR");
        exit(1);
}
