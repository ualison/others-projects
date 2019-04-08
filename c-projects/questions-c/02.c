#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cel{
 int conteudo;
 struct cel *seg;
}Celula;


void insere(int y, Celula *p){
Celula *nova;
nova = malloc(sizeof(Celula));
nova->conteudo = y;
nova->seg = p->seg;
p->seg = nova;
}

void imprima(Celula *lst){
Celula* p;
for(p =lst; p != NULL; p = p->seg)
    printf("%d \n",p->conteudo);
}

int Verifica_menor2(Celula *lst){
Celula* p;
int menor = lst->conteudo;

for(p =lst; p != NULL; p = p->seg)
    if(p->conteudo < menor)
       menor = p->conteudo;

return menor;
}

/* Esta função recebe uma lista encadeada lst com cabeça
 * e retorna retorna a célula que contiver o menor valor de lst*/
Celula* Verifica_menor(Celula *lst){
Celula* p, *aux = lst->seg;

for(p =lst->seg; p != NULL; p = p->seg)
    if(p->conteudo < aux->conteudo)
          aux = p;

return aux;
}


/* Esta função recebe uma lista encadeada lst com cabeça
 * e outra lista encadeada aux apontando para lst->seg e
 * devolve a célula de conteudo minido de lst*/
Celula* Verifica_menor_recursiva(Celula *lst, Celula *aux){

if(lst->seg == NULL)
    return aux;

if(lst->seg->conteudo < aux->conteudo)
    aux = lst->seg;

return Verifica_menor_recursiva(lst->seg, aux);
}

int main(){

Celula *aux = malloc(sizeof(Celula));
aux->seg = NULL;
insere(3, aux);
insere(2, aux);
insere(4, aux);
insere(9, aux);
insere(5, aux);
insere(1, aux);

printf("%d", Verifica_menor(aux)->conteudo);

//imprima(Verifica_menor_recursiva(aux));
Celula* aux2 = aux->seg;
printf("%d", Verifica_menor_recursiva(aux, aux2)->conteudo);
}


