#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cel{
 int conteudo;
 struct cel *seg;
}Celula;

void imprima(Celula *lst){
Celula* p;
for(p =lst; p != NULL; p = p->seg)
    printf("%d \n",p->conteudo);
}

void insere(int y, Celula *p){
Celula *nova;
nova = malloc(sizeof(Celula));
nova->conteudo = y;
nova->seg = p->seg;
p->seg = nova;
}

void Insercao(int n, int vet[]){
int i, j, x;

for(j =1; j<n;j++){
    x = vet[j];
    for(i = j-1; i >= 0 && vet[i]>x; i--)
        vet[i+1] = vet[i];
    vet[i+1] = x;
}
}
/* Esta função rearranja a lista encadeada lst com cabeça
 * em ordem crescente*/
void Insercao_lista(Celula * lst){
Celula *a, *b, *c, *d;
c = lst;
while(c->seg != NULL){
    a = lst;
  while(a->seg->conteudo < c->seg->conteudo) a = a->seg;
  if(a == c)
    c = c->seg;
  else{
    b = a->seg;
    d = c->seg;
    a->seg = d;
    c->seg = d->seg;
    d->seg = b;
    }
   }
  }


int main(){

Celula *aux = malloc(sizeof(Celula));
aux->seg = NULL;
insere(2, aux);
insere(1, aux);


//imprima(aux->seg);
Insercao_lista(aux);
imprima(aux->seg);
/*
int vetor[] = {7,2,5,4};
Insercao(4, vetor);
int n;
for(n =0; n<4;n++)
printf("%d", vetor[n]);
*/

}
