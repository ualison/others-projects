#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void produto_matriz(int m, int n, int mat[m][n], int vet[n], int res[n]){
	int i, j;
	for(i=0;i<n;i++){
           int soma=0;
		for(j=0;j<n;j++)
        soma += mat[i][j] * vet[j];
		res[i] = soma;
	}
}

int main(){
       int i, j;
       int matriz [3][3] = {{2,2,2},{3,3,3},{1,2,3}};
       int vetor[] = {2,3,4};
       int result[3];
   produto_matriz(3,3,matriz, vetor, result);

   for(i=0;i<3;i++)
       printf("%d  ", result[i]);
   }
