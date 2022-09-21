#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char defaultUser[32] = "bob";
char defaultPass[32] = "cbooneT{jxx|dyo";

char staticUser[32];
char staticPass[32];

char usefulNum[12] = "12345678901";
char interestingString[12] = "Y[WPPXh\\XDP";

char currentUser[32] = "";

char specialSecret[10] = "NLMLYOLYYP";

int loggedIn = 0;
int check;

extern int bobLoop();

extern int userLoop(void);

void encrypt(void){
    for (int i=0;i<strlen(staticPass);i++){
        char temp = staticPass[i] ^ 11;
        staticPass[i] = temp;
    }
}

int passCheck(char *passP){
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
        printf("Username: ");           // set usernamed and password for first time
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
    int nums1[] = {104, 105, 100, 100, 101, 110, 95, 117, 115, 101, 114, 115};
    int nums2[] = {104, 105, 100, 100, 101, 110, 95, 102, 117, 110, 99, 116, 105, 111, 110, 115};
    switch(flag){
        case 1:
            loopNums = nums1;
            size = sizeof(nums1);
        case 2:
            loopNums = nums2;
            size = sizeof(nums2);
    }
    for(int i = 0; i < size/sizeof(int); i++){
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

    if ( passCheck(passP) == 0 && strcmp(userP, defaultUser) == 0 ){        //logic for logging in correct person
        printf("Login successful. Hello, %s.\n", defaultUser);
        flag(1);
        loggedIn = 1;
        strncpy(currentUser, defaultUser, 4);

    }else if ( passCheck(passP) == 0 && strcmp(userP, staticUser) == 0 ){
        strncpy(currentUser, userP, sizeof(userP));
        
    }else{
        printf("Username or password incorrect. Please try again");
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
        puts("/** MAIN MENU **/");
        do{
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


