#include <stdio.h>
#include <math.h>

typedef struct{
    float x;
    float y;
} tponto;

typedef struct{
    tponto z[3];
} ttrian;

void distancia(ttrian t){
    for(int i=0; i<3; i++){
        for(int j=i+1; j<3; j++){
            printf("Distancia entre os pontos %d %d: %f:\n", i+1, j+1, sqrt(pow((t.z[i].x - t.z[j].x),2)+pow((t.z[i].y - t.z[j].y),2)));
        }
    }
}

int main(){
    ttrian t;
    for(int i=0; i<3; i++){
        printf("Digite as coordenadas do ponto %d:", i+1);
        scanf("%f %f", &t.z[i].x, &t.z[i].y);
    }
    for(int i=0; i<3; i++){
        printf("Ponto %d:\n", i+1);
        printf("(%.2f,%.2f)\n", t.z[i].x, t.z[i].y);
    }
    distancia(t);
}