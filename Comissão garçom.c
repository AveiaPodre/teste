#include <stdio.h>

int main(){
    printf("-------------------\n");
    printf("CALCULO DE COMISSAO\n");
    printf("-------------------\n");

    float consumo;
    printf("Quanto foi o valor consumido pela mesa?\n");
    scanf("%f", &consumo);

    float comissao=consumo/10;
    printf("A comissao do garcom e de R$ %.2f\n", comissao);

    return 0;
}