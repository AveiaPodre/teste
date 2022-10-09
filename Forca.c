#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Forca.h"

/*declaração de variáveis globais
char palavra[20];
char chutes[26];
int chutesDados=0;
*/
void abertura(){
    printf("*********************\n");
    printf("*   JOGO DA FORCA   *\n");
    printf("*********************\n");
}
void novoChute(char chutes[26], int* chutesDados){
    char chute;
    printf("Qual o seu chute?\n");
    scanf(" %c", &chute);
    chutes[(*chutesDados)]=chute;
    (*chutesDados)++;
}
int jaChutou(char letra, char chutes[26], int chutesDados){
    int achou=0;
    for(int j=0; j<chutesDados; j++){
        if(chutes[j]==letra){
            achou=1;
            break;
        }
    }
    return achou;
}
void desenhaForca(char palavra[TAMANHO_PALAVRA], char chutes[26], int chutesDados){
    for(int i=0; i<strlen(palavra); i++){
        int achou = jaChutou(palavra[i], chutes, chutesDados);
        if(!achou){
            printf("_ ");
        }
        else{
            printf("%c ", palavra[i]);
        }
    }
    printf(" \n");
}
void escolhePalavra(char palavra[TAMANHO_PALAVRA]){
    FILE* f;

    f = fopen("Palavras.txt", "r");
    if(f==0){
        printf("Desculpe, banco de dados não disponivel.\n\n");
        exit(1); 
    }

    int qqtPalavras;
    fscanf(f, "%d", &qqtPalavras);

    srand(time(0));
    int random = rand() % qqtPalavras;

    for(int i=0;i<= random; i++){
        fscanf(f, "%s", palavra);
    }
    fclose(f);
}
int enforcou(char palavra[TAMANHO_PALAVRA],char chutes[26],int chutesDados){
    int erros = 0;
    for(int i=0; i<chutesDados; i++){
        int existe = 0;
        for(int j=0; j<strlen(palavra); j++){
            if(chutes[i]==palavra[j]){
                existe=1;  
                break; 
            }
        }
        if(!existe){
            erros++;
        }
    }
    return erros>=5;
}
int ganhou(char palavra[TAMANHO_PALAVRA], char chutes[26], int chutesDados){
    for(int i=0; i<strlen(palavra); i++){
        if(!jaChutou(palavra[i], chutes, chutesDados)){
            return 0;
        }
    }
    return 1;
}
void adicionaPalavra(){
    char quer;

    printf("Voce deseja adicionar uma nova palavra ao jogo?(S/N)\n");
    scanf(" %c", &quer);
    if (quer == 'S'){
        char novaPalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra a ser adicionada?");
        scanf("%s", novaPalavra);

        FILE* f;

        f = fopen("palavras.txt", "r+");
        if(f==0){
            printf("Desculpe, banco de dados não disponivel.\n\n");
            exit(1); 
        }
        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novaPalavra);

        fclose(f);
    }
}

int main(){
    char palavra[TAMANHO_PALAVRA];

    char chutes[26];
    int chutesDados=0;

    escolhePalavra(palavra);
    abertura();

    do{
        desenhaForca(palavra, chutes, chutesDados);
        novoChute(chutes, &chutesDados);

    }while(!ganhou(palavra, chutes, chutesDados) && !enforcou(palavra, chutes, chutesDados));
    if(enforcou(palavra, chutes, chutesDados)){
        printf("Voce perdeu, acabaram as suas tentativas!\n");
        printf("A palavra secreta era %s\n", palavra);
    }
    else{
        printf("Parabens, voce acertou a palavra secreta %s!\n", palavra);
    }
    adicionaPalavra();
}