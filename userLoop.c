#include <stdio.h>
#include <stdlib.h>

extern char staticUser[32];

int userLoop(void)
{
    char userInput;

    while(1)
    {
        system("clear");
        printf("/** Welcome, %s **/\n", staticUser);
        printf("\nPlease choose from the following options:");
        puts("\n\tf - print something\n\tq - quit\n\n");
        printf("$- ");
        scanf("%c", &userInput);
        while(getchar() != '\n');

        switch(userInput)
        {
            case 'f':
                puts("{my_first_flag}");
                puts("Press enter to continue...");
                getchar();
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