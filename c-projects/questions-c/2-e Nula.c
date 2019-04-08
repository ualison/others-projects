#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifica_nula(int n, int m, int mat [m][n]){
int i, j;

for(i= 0; i<m;i++)
   for(j = 0; j<n; j++)
    if(mat[i][j]!=0)
    return 0;

   return 1;

}

int main(){
int matriz [][2] = {{0,0},{0,0}};
int res;

res = verifica_nula(2,2 ,matriz);

if(res == 1)
    printf("e nula");
else
    printf("nao nula");


}
