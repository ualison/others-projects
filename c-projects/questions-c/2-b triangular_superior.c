#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int triangular_superior(int n, int mat [][n]){
int i, j;

for(i= 0; i<n;i++)
   for(j = 0; j<n; j++)
   if(i>j && mat[i][j]!=0)
   return 0 ;

   return 1;
}


int main(){
int mtest [][3] = {{1,4,0},{0,0,5},{1,0,3}};
int res = triangular_superior(3,mtest);

if(res == 1)
    printf("e triangular superior");
else
    printf("nao e triangular superior");
}
