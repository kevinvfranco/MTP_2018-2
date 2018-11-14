/* P6.c */
/* Kevin Vinícius Franco */
/* 11811EEL007 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef
    struct ponto{double x,y;}
ponto;

ponto * gerar_pontos(int N) {
    ponto * coordenadas = (ponto *) calloc(N,sizeof(ponto));
    int i;
    for(i = 0; i < N; i++){
        coordenadas[i].x = cos(i*2.0*M_PI/(N-1));
        coordenadas[i].y = sin(i*2.0*M_PI/(N-1));
    }
    return coordenadas;
}

void mostrar_pontos(ponto * p_ini, ponto * p_fim) {
    if(p_ini < p_fim) {
        printf("x: %.3lf, y: %.3lf\n", p_ini->x, p_ini->y);
        mostrar_pontos(p_ini+1, p_fim);
    }
}

int main(){
    unsigned int N;
    ponto *coordenadas;
    printf("Digite o número de pontos: ");
    scanf("%u", &N); getchar();
    coordenadas = gerar_pontos(N);
    mostrar_pontos(coordenadas, coordenadas + N);
    free(coordenadas);
    return 0;
}