/* P7.c */
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
        printf("(%.3lf, %.3lf) ", p_ini->x, p_ini->y);
        mostrar_pontos(p_ini+1, p_fim);
    }
}

void grava_pontos(ponto * pini, int N) {
    FILE * arquivo;
    arquivo = fopen("pontos.dat", "wb");
    fwrite(pini, N, sizeof(ponto), arquivo);
    fclose(arquivo);
}


ponto * le_pontos(char * nome_arquivo, unsigned int * pN) {
    ponto * coordenadas = (ponto *) malloc(sizeof(ponto));
    unsigned int N = 0;
    FILE * arquivo;
    arquivo = fopen(nome_arquivo, "rb");
    while(1) {
        fread(coordenadas, 1, sizeof(ponto), arquivo);
        if(feof(arquivo)) break;
        N++;
    }
    rewind(arquivo);
    coordenadas = (ponto *) realloc(coordenadas, N*sizeof(ponto));
    fread(coordenadas, N, sizeof(ponto), arquivo);
    fclose(arquivo);
    *pN = N;
    return coordenadas;
}


int main(){
    unsigned int N, opc;
    ponto *coordenadas;
	printf("1 - Gravar arquivo; 2 - Ler arquivo: ");
    scanf("%u", &opc); getchar();
    if(opc == 2) {
        coordenadas = le_pontos("pontos.dat", &N);
        mostrar_pontos(coordenadas, coordenadas + N);
    } else {
        printf("Digite o número de pontos: ");
		scanf("%u", &N); getchar();
        coordenadas = gerar_pontos(N);
        grava_pontos(coordenadas, N);
        printf("Arquivo gravado");
    }
    free(coordenadas);
    return 0;
}
