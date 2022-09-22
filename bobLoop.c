#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern char specialSecret[10];
extern void flag(int flag);
extern int enterDatabase();
void decrypt(char *enc, char *key);
void decryptMe();

int bobLoop()
{
    char userInput;
    system("clear");

    while(1)
    {
        puts("/** Password Man - Bob **/");
        puts("Here's your daily login flag!");
        flag(1);
        printf("\nPlease choose from the following options:");
        puts("\n\ta - access database\n\tq - quit\n\n");
        printf("$- ");
        scanf("%c", &userInput);
        while(getchar() != '\n');

        switch(userInput)
        {
            case 'd':
                decryptMe();
                system("clear");
                break;
            case 'a':
                enterDatabase();
                system("clear");
                break;
            case 'q':
                return(0);
                break;
            default:
                system("clear");
                puts("INVALID ARGUMENT!");
                break;
        }
    }
    return(0);
}

void decryptMe()
{
    char *userInput;
    userInput = (char *)malloc(32);

    system("clear");
    puts("/** Bob's Secret File Zone **/");
    puts("I hear he used a pad one time to write down a key flag");
    printf("Enter the password to continue...\n$- ");
    scanf("%s", userInput);
    while(getchar() != '\n');
    decrypt(specialSecret, userInput);

    free(userInput);
    return;
}

void decrypt(char *enc, char *key)
{
    if(strlen(enc) != strlen(key))
    {
        printf("ERROR: Key is incorrect length\n");
        puts("Press enter to return to main menu...");
        getchar();
        return;
    }

    char outArr[10];

    for(int i = 0; i < 10; i++)
    {
        enc[i] = toupper(enc[i]);
        key[i] = toupper(key[i]);

        int tmp = (((int)enc[i]) - 65) - (((int)key[i]) - 65);
        if(tmp < 0)
            outArr[i] = (char)((26 - abs(tmp)) + 65);
        else
            outArr[i] = (char)((tmp % 26) + 65);
    }

    for(int i = 0; i < 10; i++)
        putchar(outArr[i]);
    putchar('\n');
    puts("Press enter to continue...");
    getchar();

    return;
}