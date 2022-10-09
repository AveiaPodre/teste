#include <stdio.h>

void calcula(int* a){
    (*a)++;
    printf("calcula %d %d\n", *a, a);
}

int main(){
    int c=10;
    printf("main %d %d\n", c, &c);
    calcula(&c);
    printf("main %d %d\n", c, &c);
}