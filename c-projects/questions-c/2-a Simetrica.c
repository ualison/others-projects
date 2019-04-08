#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matriz_transposta(int m, int n, int mat[m][n], int matTrans[n][m]){

int i, j;

for(i= 0; i<m;i++)
   for(j = 0; j<n; j++)
      matTrans[j][i] = mat[i][j];

}

int matriz_simetrica(int n, int mat[n][n]){
	int i, j, a[n][n];
	matriz_transposta(n,n,mat,a);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j]!=mat[i][j])
				return 0;
	return 1;
}

int main(){
int mtest [][2] = {{0,2},{2,0}};
int res = matriz_simetrica(2,mtest);

if(res == 1)
    printf("e simetrica");
else
    printf("nao e simetrica");
}
