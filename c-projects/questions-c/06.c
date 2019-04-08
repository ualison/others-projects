#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*Esta função recebe um vetor vet[r..p] e dois inteiros p = 0 e r>=1
 * e rearranja de modo que valores negarivos fiquem a esquerda e positivos
 * à direita, devole a posição j entre [p..j − 1] ≤0 e v[j..r] > 0 */
int rearranjar_vetor(int vet[], int p, int r){

int i, fim = r-1, aux, j = r/2, k;

for(i = 0; i < j; i++){
   if(vet[i] > 0 && vet[fim] <= 0){
    aux = vet[i];
    vet[i] = vet[fim];
    vet[fim] = aux;}

    else if(vet[i] <= 0 && vet[fim] <= 0){
    aux = vet[i+1];
    vet[i+1] = vet[fim];
    vet[fim] = aux; }

    else if(vet[i] > 0 && vet[fim] > 0){
    aux = vet[i];
    vet[i] = vet[fim-1];
    vet[fim-1] = aux;}
fim--;
}
for(k = 0; k < r; k++)/* Usado apenas para conferir o vetor*/
printf("%d  ", vet[k]);

return vet[j];
}

int main(){
int v[] = {9,-1,2,-5,7,4,-2,7,5,6,7,6,5,6,-1,-8,8,-5};

printf("\n   %d", rearranjar_vetor(v, 0, 18));
}
