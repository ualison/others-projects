#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int esta_contida(int m, int a[][m],int n, int b[][n]){
int oi, oj, i, j;

for(oi=0;oi+m<=n;oi++)
for(oj=0;oj+m<=n;oj++){
    int cont =0;
    for(i=oi;i<oi+m;i++)
        for(j=oj;j<oj+m;j++)
           for(j=oj;j<oj+m;j++)
            if(b[i][j] == a[i-oi][j-oj])
            cont++;
    if(cont==m*m)
        return 1;
}
return 0;
}

int main(){
int matriz1 [][3] = {{0,3,3},{4,7,7},{3,2,7}};
int matriz2 [][2] = {{2,3},{7,0}};
int res = esta_contida(3,matriz1,2,matriz2);

if(res == 1)
    printf("e esta contida");
else
    printf("nao esta contida");
}
