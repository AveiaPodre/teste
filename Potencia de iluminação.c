#include <stdio.h>
#include <math.h>

int main(){
    printf("----------------------\n");
    printf("POTENCIA DE ILUMINACAO\n");
    printf("----------------------\n");

    float largura, comprimento;
    float area;
    float potencia;

    printf("Indique a largura e o comprimento do comodo(em metros)\n");
    scanf("%f %f", &largura, &comprimento);
    area= largura*comprimento;
    potencia= area*18;

    printf("O comodo tem uma area de %.2fmetros quadrados\n", area);
    printf("A potencia necessaria para ilumina-lo completamente e de %.2fW", potencia);

    return 0;
}