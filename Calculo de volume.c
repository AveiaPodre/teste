#include <stdio.h>
#include <math.h>

int main(){
    printf("-----------------\n");
    printf("CALCULO DE VOLUME\n");
    printf("-----------------\n");

    int processo;
    float volume;
    float raio;
    float altura;

    printf("De qual forma geometrica voce deseja saber o volume?\n");
    printf("[1]Esfera\n");
    printf("[2]Cone\n");
    printf("[3]Cilindro\n");
    scanf("%d", &processo);

    switch(processo){
        case 1:
        printf("Qual o raio da esfera?\n");
        scanf("%f", &raio);
        volume= (4*3.14*pow(raio,3))/3;
        printf("O volume da esfera e de %.2f\n", volume);
        break;

        case 2:
        printf("Qual o raio do cone?\n");
        scanf("%f", &raio);
        printf("Qual a altura do cone?\n");
        scanf("%f", &altura);
        volume= (3.14*pow(raio,2)*altura)/3;
        printf("O volume do cone e de %.2f\n", volume);
        break;

        case 3:
        printf("Qual o raio do cilindro?\n");
        scanf("%f", &raio);
        printf("Qual a altura do cilindro?\n");
        scanf("%f", &altura);
        volume= (3.14*pow(raio,2)*altura);
        printf("O volume do cilindro e de %.2f\n", volume);
        break;

        default:
        printf("Resposta invalida\n");
        break;
    }
    return 0;
}