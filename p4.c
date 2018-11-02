/* P4.c */
/* Kevin Vinícius Franco */
/* 11811EEL007 */
#include <stdio.h>

int ackermann(int m, int n){
	if(m == 0)
		return n + 1; 
	else if(m > 0 && n == 0)
		ackermann(m - 1, 1);
	else if(m > 0 && n > 0)
		ackermann(m - 1, ackermann(m, n - 1));
}

int main(){
	int x, y;
	printf("Digite m e n, respectivamente: ");
	scanf("%d%d", &x,&y);
	printf("Resultado: %d", ackermann(x,y));
	return 0;
}

