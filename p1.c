/* P1.c */
/* Kevin Vinicius Franco */
/* 11811EEL007 */
#include <stdio.h>

int main(){
    int estado = 0, i, estado_if;
    char bits[256];
    printf("Digite a sequencia binaria: ");
    scanf("%s", bits);
    for(i = 0; bits[i] != '\0'; i++){
        if(estado == 0)
            estado_if = bits[i] == '0' ? 0 : 1;
        else if(estado == 1)
            estado_if = bits[i] == '0' ? 2 : 0;
        else
            estado_if = bits[i] == '0' ? 1 : 2;
        estado = estado_if;
    }
    if(estado == 0)
        printf("%s eh multiplo de 3",bits);
    else
        printf("%s nao eh multiplo de 3",bits);
    return 0;
}
