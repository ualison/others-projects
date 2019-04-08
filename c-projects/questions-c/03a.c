#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* Esta função recebe um vetor vet[0..n-1] de tamanho n>=1 e
 * devolve uma posição i quando vet[i] == i, se tal posição
 * não existir devolve -1 */

int retorna_i(int vet[], int n){

int e, i, d;

e =-1; d = n;

while(e < d-1){
    i = (e + d)/2;
    if(vet[i] == i) return i;
    if(vet[i] < i) e = i;
    else d = i;
    }
return -1;
}


int main(){

int vetor[] = {-1,0,1,2,3,4,6};

printf("%d", retorna_i(vetor,7));
}
