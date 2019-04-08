#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifica_identidade(int n, int mat [][n]){
int i, j;

for(i= 0; i<m;i++)
   for(j = 0; j<n; j++)
   if(i==j && mat[i][j]!=1)
        return 0;
   }else if( i!=j && mat[i][j]!=0)
        return 0;

        return 1;

   }
