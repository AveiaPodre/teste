#include <stdio.h>
#include <string.h>

int main(){
    char vitu[20];
    printf("O que o vitu eh?");
    scanf(" %s", vitu);
    if(strcmp(vitu, "careca")){
        printf("Tome crackudo\n");
    }
    return 0;
}