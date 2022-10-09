#include <stdio.h>

int main(){
    printf("----------------\n");
    printf("CALCULO DE TEMPO\n");
    printf("----------------\n");

    float minutos;
    float horas;

    printf("Quantas horas voce precisa converter?\n");
    scanf("%f", &horas);

    minutos= horas*60;
    printf("Voce tem %.2f minutos", minutos);

    return 0;
}