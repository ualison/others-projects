#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 long fat (int n){
    int i,f = 1;
    for(i = 1;i <= n;i++){
        f *= i;
    }
    return f;
    }
    int main(void){
        int n,i,j,y = 1;
        printf("digite a altura do triangulo \n");
        scanf("%d",&n);
            int v[(n+2)*(n+1)/2],x = 0;
        for(i = 0;i <= n;i++){
                printf("%d",i);
            for(j = 0;j <= n;j++){
                if(i >= j){
                v[x] = (fat(i))/(fat(i-j)*fat(j));
                 printf(" %d ",v[x]);
                x++;

        }
            if(x == (y + y*y)/2){
            printf("\n");
                y++;
            }
        }
    }
}
