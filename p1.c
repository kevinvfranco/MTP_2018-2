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
        printf("O numero digitado e multiplo de 3");
    else
        printf("O numero digitado nao e multiplo de 3");
    return 0;
}
