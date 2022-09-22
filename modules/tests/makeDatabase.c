#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

struct mainLog
{
    char username[32];
    char password[256];
    char hidden[32];
    int expire;
    struct mainLog *next;
};

struct mainLog *first;
struct mainLog *current;
struct mainLog *new;

struct mainLog *ini();
void addVal();
void addEntries();
void saveLog();
void encryptXOR(char *string);

int main()
{
    addVal();
    addVal();
    addVal();
    saveLog();
    return(0);
}

struct mainLog *ini()           //Initialise a node
{
    struct mainLog *tmp;        //Malloc enough memory for the node
    tmp  = (struct mainLog *)malloc(sizeof(struct mainLog));

    return(tmp);                //Return starting address
    free(tmp);
}

void addVal()           //Add a value to the log
{
    if(first == NULL)   //Create a log if one does not exist
    {
        puts("Creating...");
        first = ini();
        current = first;
    }
    else
    {
        current = first;
        
        while(current->next)            //Find the last entry in the log
            current = current->next;
        
        new = ini();            //Add a node onto the end of the linked list
        current->next = new;
        current = new;
    }

    addEntries();               //Add the user entries 

    current->next = NULL;       //Close function actions
    system("clear");
    return;
}

void addEntries()               //Sanitise user input and add information to the log
{
    char user[32];      //Temporary buffer for validation
    char pass[32];
    char hidd[32];

    printf("Enter username: ");
    scanf("%s", user);
    while(getchar() != '\n');

    encryptXOR(user);
    strcpy(current->username, user);

    printf("Enter password: ");
    scanf("%s", pass);
    while(getchar() != '\n');
    
    encryptXOR(pass);
    strcpy(current->password, pass);

    printf("Enter hidden: ");
    scanf("%s", hidd);
    while(getchar() != '\n');
    
    encryptXOR(hidd);
    strcpy(current->hidden, hidd);

    printf("Enter days to expiry: ");
    scanf("%d", &current->expire);
    while(getchar() != '\n');

    return;
}

void saveLog()  //Save files
{
    puts("Saving...");

    char fileName[8] = "data.db";     //Character store

	FILE *fh;                   //Create a new file and save to it
	fh = fopen(fileName, "w");
    
    puts("Saving all records...");
    current = first;  								
    while(current)              //Write to file
    {
        fwrite(current, sizeof(struct mainLog), 1, fh);
        current = current->next;
    }

    fclose(fh);
}

void encryptXOR(char *string)
{
    for(int i = 0; i < strlen(string); i++)
        string[i] = string[i] ^ 0xCC;
}