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

void loadLog();
void showLog();
struct mainLog *ini();

int main()
{
    loadLog();
    showLog();
    return(0);
}

void loadLog()      //Function to load file into program
{
	FILE *fh;       //Prepare load and temporary database
	struct mainLog loadme;
	
    char fileName[8] = "data.db";

    fh = fopen(fileName, "r");  //Open requested file
	
	if(!fh)         //Check file opened properly
	{
        puts("Error opening file, contact Lizzie or George");
        return;
    }
		
	while(fread(&loadme, sizeof(struct mainLog), 1, fh))    //Load into linked list
	{
		if(first == NULL)
    	{
        	first = ini();
        	current = first;
    	}   	
    	else
    	{
        	current = first;
        
        	while(current->next)
            	current = current->next;  
                 
        	new = ini();
        	current->next = new;
        	current = new;
    	}
        strcpy(current->username, loadme.username); //For some reason we have to strcpy any strings across...
        strcpy(current->password, loadme.password); //https://stackoverflow.com/questions/3860488/c-copy-string-into-a-linked-list-variable/3860496
        strcpy(current->hidden, loadme.hidden);
        current->expire = loadme.expire;

    	current->next = NULL;
	}
	fclose(fh);
    getchar();
}

struct mainLog *ini()           //Initialise a node
{
    struct mainLog *tmp;        //Malloc enough memory for the node
    tmp  = (struct mainLog *)malloc(sizeof(struct mainLog));

    return(tmp);                //Return starting address
    free(tmp);
}

void showLog()                  //Prints out nodes in succession
{
    int count = 1, menu = 1;    //Used for navigation aid
    char selection;             //Used for input

    current = first;                //Find the number of nodes in the list
    while(current->next)            //https://www.geeksforgeeks.org/find-length-of-a-linked-list-iterative-and-recursive/
    {
        current = current->next;
        menu++;
    }

    current = first;
    
    while(current)                  //Print out contents
    {
        system("clear");
        printf("Record %d/%d\n", count, menu);
        printf("Username: %s\n", current->username);
        printf("Password: %s\n", current->password);
        printf("Expires in (days): %d\n", current->expire);

        puts("Show next record?");  //User option
        printf("(N)ext/(E)xit: ");
        scanf("%c", &selection);
        while(getchar() != '\n');

        if(selection == 'N' || selection == 'n')    //Move to next menu unless last menu
        {
            if(current->next == NULL)
            {
                system("clear");
                return;
            }
            current = current->next;
            count++;
        }
        else
        {
            system("clear");
            return;
        }
    }

    system("clear");    //Close function
    return;
}