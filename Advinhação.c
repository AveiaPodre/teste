#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#define NUMERO_DE_TENTATIVAS 5

int main(){
    //cabeçalho
    printf("-------------------------------------\n");
    printf("BEM VINDO AO NOSSO JOGO DE ADVINHACAO\n");
    printf("-------------------------------------\n");

    srand(time(0));
    int numero= rand() % 100;
    int chute;
    int acertou = 0;
    int i = 1;
    double pontos = 100;
    double pontosPerdidos;

    //for(int i=1; i<=NUMERO_DE_TENTATIVAS; i++){} para loop com repetições predeterminadas
    //while(1){} para loop infinito(para com break)
    while(acertou==0){
        printf("Tentativa %d\n", i);
        printf("Qual e o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if(chute<0){
            printf("Voce nao pode chutar numeros negativos, tente de novo! \n");
            printf("-----------------------------------------------------------\n");
            continue;
        }
        else if(chute==numero){
            printf("Parabens, voce acertou\n");
            printf("-----------------------------------------------------------\n");
            acertou = 1;
        }
        else if(chute>numero){
            printf("Seu chute foi maior do que o numero secreto, tente de novo!\n");
            printf("-----------------------------------------------------------\n");
            i++;
            //pontosPerdidos=(chute-numero)/2.0;
            //pontos=pontos-pontosPerdidos;
        }
        else if(chute<numero){
            printf("Seu chute foi menor do que o numero secreto, tente de novo!\n");
            printf("-----------------------------------------------------------\n");
            i++;
            //pontosPerdidos=(numero-chute)/2.0;
            //pontos=pontos-pontosPerdidos;
        }
        pontosPerdidos=abs(numero-chute)/(double)2;
        pontos=pontos-pontosPerdidos;
    }
    if(pontos<0){
        pontos=0;
    }

    printf("O numero secreto era %d\n", numero);
    printf("Voce precisou de %d tentativas para acertar o numero secreto!\n", i);
    printf("Voce fez %.1f pontos!\n", pontos);
    printf("Fim de jogo!\n");
    printf("-----------------------------------------------------------\n");
}