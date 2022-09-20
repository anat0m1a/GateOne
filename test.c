#include <stdio.h>
#include <stdlib.h>

int main(void){
    char str[17] = "hidden_functions";
    int number[17];
    char a;
    for (int i=0; i<17; i++){
        a = str[i];
        number[i]= a;
        printf("%d. %d\n",i , number[i]);
    }
    for (int i = 0; i < 16; i++){
        printf("%d", number[i]);
    }
}