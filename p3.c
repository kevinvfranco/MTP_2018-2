/* P3.c */
/* Kevin Vinícius Franco */
/* 11811EEL007 */
#include <stdio.h>

int main(){
	char numero[256];
	int i, cum = 0, num;
	printf("Informe uma sequência de caracteres: ");
	scanf("%s", numero);
	for(i = 0; numero[i] != '\0'; i++){
		if(numero[i] > 47 && numero[i] < 58){
			num = numero[i] - 48;
			cum = cum*10 + num;
		}
	}
	printf("\nO número é: %d", cum);
	return 0;
}