#define TAMANHO_PALAVRA 20
void abertura();
void novoChute(char chutes[26], int* chutesDados);
int jaChutou(char letra, char chutes[26], int chutesDados);
void desenhaForca(char palavra[20], char chutes[26], int chutesDados);
void escolhePalavra(char palavra[20]);
int enforcou(char palavra[20],char chutes[26],int chutesDados);
int ganhou(char palavra[20], char chutes[26], int chutesDados);