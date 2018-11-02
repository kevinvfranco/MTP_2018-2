/* P5.c */
/* Kevin Vinícius Franco */
/* 11811EEL007 */
#include <stdio.h>

typedef
    unsigned long long int
Bytes8;
typedef
    struct LCG{Bytes8 a, c, m, rand_max, atual;}
LCG;

double lcg_rand_01(LCG * r);
void semente(LCG * r, Bytes8 seed);
Bytes8 lcg_rand(LCG * r);
double lcg_rand_01(LCG * r);
void gera_numeros(float * vetor, int tam, float min, float max, LCG * r);


void semente(LCG * r, Bytes8 seed){
    r->a = 0x5DEECE66DULL;
    r->c = 11ULL;
    r->m = (1ULL << 48);
    r->rand_max = r->m - 1;
    r->atual = seed;
}

Bytes8 lcg_rand(LCG * r){
    r->atual = (r->a * r->atual + r->c) % r->m;
    return r->atual;
}

double lcg_rand_01(LCG * r){
    return ((double) lcg_rand(r))/(r->rand_max);
}

void gera_numeros(float * vetor, int tam, float min, float max, LCG * r){
    int i;
    for(i = 0; i < tam; i++)
        vetor[i] = (max-min)*lcg_rand_01(r) + min;
}

float soma(float *inicio_vetor, float *fim_vetor) {
    return (*fim_vetor) + ((fim_vetor == inicio_vetor) ? 0 : soma(inicio_vetor, fim_vetor-1));
}

float produto(float *inicio_vetor, float *fim_vetor) {
    return (*fim_vetor) * ((fim_vetor == inicio_vetor) ? 1 : produto(inicio_vetor, fim_vetor-1));
}

int main(){
     int opc, tamanho;
	 float numeros[50];
	 LCG random;
     semente(&random,123456);
     gera_numeros(numeros, 50, 0.5, 1.5, &random);
	 tamanho = sizeof(numeros)/sizeof(int);
     float *primeiro = numeros, *ultimo = numeros+tamanho-1;
     do{
        printf("Escolha uma opção:\n 1 - Somatório\n 2 - Produtório\nOpção: ");
        scanf("%d",&opc); getchar();
     }while(opc != 1 && opc != 2);
     if(opc == 1)
        printf("Resultado: %f",soma(primeiro, ultimo));
     else
        printf("Resultado: %f", produto(primeiro, ultimo));
     return 0;
}