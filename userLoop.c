#include <stdio.h>
#include <stdlib.h>

extern char staticUser[32];

int userLoop(void){
    system("clear");
    printf("/** Welcome, %s", staticUser);

    printf(" **/\n");
    puts("Press enter to return to main menu... ");
    getchar();
    return(0);
}