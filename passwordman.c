#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char defaultUser[32] = "bob";
char defaultPass[32] = {0x7f,0x64,0x7f,0x6a,0x67,0x67,0x72,0x54,0x65,0x64,0x7f,0x54,0x6a,0x54,0x7b,0x6a,0x78,0x78,0x7c,0x64,0x79,0x6f};

char staticUser[32];
char staticPass[32];

char currentUser[32] = "";

char XOR[12] = "12345678901";
char interestingString[12] = {0x58, 0x53, 0x5e, 0x52, 0x59, 0x57, 0x50, 0x53, 0x5c, 0x49};

char specialSecret[10] = "QMRQLGLYYP";


int check;

extern int bobLoop();

extern int userLoop(void);

void encrypt(void){                         // take user input, XOR it and store it in the data section.
    for (int i=0;i<strlen(staticPass);i++){
        char temp = staticPass[i] ^ 11;
        staticPass[i] = temp;
    }
}

int passCheck(char *passP){                 // XOR password and check against password 'hash' stored in the data section.
    char temp[32];
    for (int i=0; i<strlen(passP); i++){
        temp[i] = passP[i] ^ 11;
    }
    int pass1 = strcmp(temp, defaultPass);
    int pass2 = strcmp(temp, staticPass);
    if (pass1 == 0){
        return pass1;
    }else{
        return pass2;
    }
}

int createLogin(){
    do{
        printf("Username: ");           // set username and password for first time, store in the data section
        fgets(staticUser, 32, stdin);
        staticUser[strcspn(staticUser, "\n")] = 0;

        if(!strcmp(staticUser, "q"))
        {
            system("clear");
            exit(0);
        }

        printf("Password: ");
        fgets(staticPass, 32, stdin);
        staticPass[strcspn(staticPass, "\n")] = 0;
        
    }while (strlen(staticUser)==1 || strlen(staticPass)==1);
    
    encrypt();                      // XOR password and store.
    printf("%s\n", staticPass);               // print XOR'd password. (debug)
    
    printf("Success. Please login.\n\n");
}

void flag(int flag){
    int *loopNums;
    int size;
    int nums1[] = {123,100,114,97,103,111,110,95,100,101,98,117,103,103,101,114,95,103,111,95,98,114,114,114,125};
    switch(flag){
        case 1:
            loopNums = nums1;
            size = sizeof(nums1) / sizeof(nums1[0]);
    }
    for(int i = 0; i < size; i++){
        printf("%c", (char) loopNums[i]);
    }
    printf("\n");
}

int login(void){
    
    printf("\nPlease enter your credentials, or press q to quit\n\n");

    char username[32];
    char password[32]; 

    char *userP = username;
    char *passP = password;

    printf("Username: ");       // get user credentials for login
    fgets(userP, 32, stdin);
    userP[strcspn(userP, "\n")] = 0;

    if(!strcmp(userP, "q"))
    {
        system("clear");
        exit(0);
    }

    printf("Password: ");
    fgets(passP, 32, stdin);
    passP[strcspn(passP, "\n")] = 0;

    if ( passCheck(passP) == 0 && strcmp(userP, defaultUser) == 0 ){        // logic for logging in correct person
        printf("Login successful. Hello, %s.\n", defaultUser);
        flag(1);
        strncpy(currentUser, defaultUser, 4);

    }else if ( passCheck(passP) == 0 && strcmp(userP, staticUser) == 0 ){
        strncpy(currentUser, userP, sizeof(userP));
        
    }else{
        printf("\nUsername or password incorrect. Please try again.\n");
        puts("Press enter to continue...");
        getchar();
        system("clear");
        return 1;
    }
    return 0;
}
    
int main(int argc, char *argv[]){
    int check;
    
    char *staticUser = staticUser;
    char *staticPass = staticPass;

    printf("Welcome to simple password manager...\n\n");
    printf("No users in database!\nPlease create new account, or press q to quit\n\n");
    createLogin();
    while(1)
    {
        system("clear");
        puts("/** MAIN MENU **/");                      // main loop, shows basic menu and allows for moving
        do{                                             // backwards and forwards in the program.
            check = login();
        }while (check != 0);

        if (strcmp(currentUser, defaultUser) == 0){
            printf("bob stuff\n");
            bobLoop();
        }else{
            userLoop();
            printf("other stuff\n");
        }
    }
}


