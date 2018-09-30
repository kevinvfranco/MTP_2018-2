/* P2.c */
/* Kevin Vinicius Franco */
/* 11811EEL007 */
#include <stdio.h>

int decimal_to(int numeros[], int numero, int cont, int divisor){
    int quociente = 1;
    for(cont = 0; quociente != 0; cont++){
        numeros[cont] = numero%divisor;
        quociente = numero/divisor;
        numero = numero/divisor;
    }
    cont--;
    return cont;
}

int to_decimal(char bits[], int numeros[], int numero, int cont, int base){
    int j, k, potencia;
    cont--;
    for(j = cont; j >= 0; j--){
		potencia = 1;
		for(k = cont; k > j; k--)
			potencia *= base;
		numeros[j] = numeros[j]*potencia;
	}
	for(j = 0; j <= cont; j++)
        numero = numero + numeros[j];
	sprintf(bits, "%d", numero);
	return numero;
}

int string_vetor(char bits[], int numeros[], int cont){
    for(cont = 0; bits[cont] != '\0'; cont++){
        if(bits[cont] == '0')
            numeros[cont] = 0;
        else if(bits[cont] == '1')
            numeros[cont] = 1;
        else if(bits[cont] == '2')
            numeros[cont] = 2;
        else if(bits[cont] == '3')
            numeros[cont] = 3;
        else if(bits[cont] == '4')
            numeros[cont] = 4;
        else if(bits[cont] == '5')
            numeros[cont] = 5;
        else if(bits[cont] == '6')
            numeros[cont] = 6;
        else if(bits[cont] == '7')
            numeros[cont] = 7;
        else if(bits[cont] == '8')
            numeros[cont] = 8;
        else if(bits[cont] == '9')
            numeros[cont] = 9;
        else if(bits[cont] == 'A' || bits[cont] == 'a')
            numeros[cont] = 10;
        else if(bits[cont] == 'B' || bits[cont] == 'b')
            numeros[cont] = 11;
        else if(bits[cont] == 'C' || bits[cont] == 'c')
            numeros[cont] = 12;
        else if(bits[cont] == 'D' || bits[cont] == 'd')
            numeros[cont] = 13;
        else if(bits[cont] == 'E' || bits[cont] == 'e')
            numeros[cont] = 14;
        else
            numeros[cont] = 15;
    }
    return cont;
}

int vetor_string(char bits[], int numeros[], int cont){
    int k, j;
    for(j = cont, k = 0; j >= 0; j--, k++){
        if(numeros[j] == 0)
            bits[k] = 48;
        else if(numeros[j] == 1)
            bits[k] = 49;
        else if(numeros[j] == 2)
            bits[k] = 50;
        else if(numeros[j] == 3)
            bits[k] = 51;
        else if(numeros[j] == 4)
            bits[k] = 52;
        else if(numeros[j] == 5)
            bits[k] = 53;
        else if(numeros[j] == 6)
            bits[k] = 54;
        else if(numeros[j] == 7)
            bits[k] = 55;
        else if(numeros[j] == 8)
            bits[k] = 56;
        else if(numeros[j] == 9)
            bits[k] = 57;
        else if(numeros[j] == 10)
            bits[k] = 'A';
        else if(numeros[j] == 11)
            bits[k] = 'B';
        else if(numeros[j] == 12)
            bits[k] = 'C';
        else if(numeros[j] == 13)
            bits[k] = 'D';
        else if(numeros[j] == 14)
            bits[k] = 'E';
        else
            bits[k] = 'F';
    }
    bits[k] = '\0';
    return cont;
}

int main(){
	int numero, opcao, numeros[255], cont;
	char bits[256];
	printf("\nEscolha uma das opções: \n 1. Binário para Decimal \n 2. Binário para Hexadecimal");
	printf("\n 3. Hexadecimal para Decimal \n 4. Hexadecimal para Binário \n 5. Decimal para Binário");
	printf("\n 6. Decimal para Hexadecimal \n 7. Octal para Decimal \n 8. Decimal para Octal");
	printf("\n Digite qualquer outro valor para sair do programa");
	do{
		cont = 0; numero = 0;
		printf("\nOpção: ");
		scanf("%d",&opcao); getchar();
		switch(opcao){
		case 1:
			printf("Informe um número binário: ");
			scanf("%s", bits);
			cont = string_vetor(bits, numeros, cont);
			numero = to_decimal(bits, numeros, numero, cont, 2);
			printf("\n	O número em decimal é: %s \n", bits);
			break;
		case 2:
			printf("Informe um número binário: ");
			scanf("%s", bits);
			cont = string_vetor(bits, numeros, cont);
			numero = to_decimal(bits, numeros, numero, cont, 2);
			cont = decimal_to(numeros, numero, cont, 16);
			cont = vetor_string(bits, numeros, cont);
			printf("\n	O número em hexadecimal é: %s \n", bits);
			break;
		case 3:
			printf("Informe um número hexadecimal: ");
			scanf("%s", bits);
			cont = string_vetor(bits, numeros, cont);
			numero = to_decimal(bits, numeros, numero, cont, 16);
			printf("\n	O número em decimal é: %s \n", bits);
			break;
		case 4:
			printf("Informe um número hexadecimal: ");
			scanf("%s", bits);
			cont = string_vetor(bits, numeros, cont);
			numero = to_decimal(bits, numeros, numero, cont, 16);
			cont = decimal_to(numeros, numero, cont, 2);
			cont = vetor_string(bits, numeros, cont);
			printf("\n	O número em binário é: %s \n", bits);
			break;
		case 5:
			printf("Informe um número decimal: ");
			scanf("%d", &numero);
            cont = decimal_to(numeros, numero, cont, 2);
            cont = vetor_string(bits, numeros, cont);
			printf("\n	O número em binário é: %s \n", bits);
			break;
		case 6:
			printf("Informe um número decimal: ");
			scanf("%d", &numero);
            cont = decimal_to(numeros, numero, cont, 16);
            cont = vetor_string(bits, numeros, cont);
			printf("\n	O número em hexadecimal é: %s \n", bits);
			break;
		case 7:
			printf("Informe um número octal: ");
			scanf("%s", bits);
			cont = string_vetor(bits, numeros, cont);
			numero = to_decimal(bits, numeros, numero, cont, 8);
			printf("\n	O número em decimal é: %s \n", bits);
			break;
		case 8:
			printf("Informe um número decimal: ");
			scanf("%d", &numero);
			cont = decimal_to(numeros, numero, cont, 8);
			cont = vetor_string(bits, numeros, cont);
			printf("\n	O número em octal é: %s \n", bits);
			break;
		default:
			return 0;
		}
	}while(opcao >= 1 && opcao <=8);
}