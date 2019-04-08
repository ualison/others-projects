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


Celula *Meio_lista(Celula *lst){
Celula *pro = lst->seg->seg, *p;

for(p =lst->seg; p != NULL; p = p->seg){
   pro = pro->seg;
    if(pro->seg == NULL)
     return p;

}
}

Celula *Fim_lista(Celula *lst){
Celula*p;

for(p =lst->seg; p != NULL; p = p->seg){
    if(p->seg == NULL)
       return p;
}
}

Celula * Busca_bin_lista(int x, Celula *lst){
   Celula *e = lst->seg, *m, *d = Fim_lista(lst);

   while (e != NULL) {
    m = Meio_lista(e->seg);
    if(m->conteudo < x)e = m;
    else d = m;

 e = e->seg;
}
return d;
}


int main(){
Celula *aux = malloc(sizeof(Celula));
aux->seg = NULL;
insere(6, aux);
insere(9, aux);
insere(3, aux);
insere(1, aux);
insere(2, aux);
insere(8, aux);


imprima(Busca_bin_lista(2,aux));
//imprima(Meio_lista(aux));
//imprima(Fim_lista(aux));



}

