/* P1.c */
/* Kevin Vinicius Franco */
/* 11811EEL007 */
#include <stdio.h>

int main(){
    int estado = 0, i;
    char bits[256];
    printf("Digite a sequencia binaria: ");
    scanf("%s", bits);
    for(i = 0; bits[i] != '\0'; i++){
        if(estado == 0)
            estado = bits[i] == '0' ? 0 : 1;
        else if(estado == 1)
            estado = bits[i] == '0' ? 2 : 0;
        else
            estado = bits[i] == '0' ? 1 : 2;
    }
    printf("%s %s", bits, estado == 0 ? "eh multiplo de 3" : "nao eh multiplo de 3");
    return 0;
}
