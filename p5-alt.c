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

float soma(float *numeros, int tam) {
    int res;
    if(tam < 50)
        return (*numeros) + soma(numeros+1, tam+1);
    else
        return 0;
}

float produto(float *numeros, int tam) {
    if(tam < 49)
        return (*numeros) * produto(numeros+1, tam+1);
    else
        return *numeros;
}

int main(){
     LCG random;
     semente(&random,123456);
     int opc;
     float numeros[50];
     gera_numeros(numeros, 50, 0.5, 1.5, &random);
     do{
        printf("Escolha uma opção:\n 1 - Somatório\n 2 - Produtório\nOpção: ");
        scanf("%d",&opc); getchar();
     }while(opc != 1 && opc != 2);
     if(opc == 1)
        printf("Resultado: %f",soma(numeros, 0));
     else
        printf("Resultado: %f", produto(numeros, 0));
     return 0;
}
