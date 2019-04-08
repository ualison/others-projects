#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define true 1
#define false 0

/* Struct Voos contendo número do vôo, destino e origem e um ponteiro *seg para o próximo voo*/
struct Voos{
int numVoo, destino, origem;

struct Voos *seg;

};

typedef struct Voos voo;

/* Struct aeporto contendo o código e o nome deste, e um ponteiro *prox_dest apontando para o primeiro vôo*/
struct aeroporto{

int cod;
char* nome;
struct Voos *prox_dest;

};
typedef struct aeroporto aero;

/*  Variáveis Globais necessárias ao funcionamento do programa:
*   aeroRes: será decrementado a medida que forem feitos novos cadastros de aeroportos.
*   contadorVet: será incrementado e decrementado a medida que forem feitos cadastros no vetor de structs aero vet.
*   contadorVoo: será incrementado e decrementado a medida que forem feitos cadastros de vôos.*/
int aeroRes = 100, contadorVet = 0, contadorVoo = 0;

/*  Vetor de structs do tipo aero de tamanho 100 que irá guardar todas as posições dos aeroportos cadastrados*/
aero vet[100];


/*  A função abaixo recebe um ponteiro de char(String) e um valor inteiro
*   codigo>= 1 e cadastra no vetor de structs vet[0...99] as posições
*   indicadas por  contadorVet referente a cada item da struct aero.*/
void CadastraAeroporto(char* cidade, int codigo){
      vet[contadorVet].cod = codigo;
      vet[contadorVet].nome = cidade;
      vet[contadorVet].prox_dest = NULL;
      printf("%d %s \n",vet[contadorVet].cod, vet[contadorVet].nome);
}

/* A função abaixo  percorre o vetor de structs aero vet[0..contadorVet-1] e imprime na tela  as
*  posições referente ao código vet[0..contadorVet-1].cod e o nome vet[0..contadorVet-1].nome .*/
void ImprimirAero(){

int i;
  for(i=0; i < contadorVet;i++)
       printf("CÓDIGO: %d NOME: %s \n",vet[i].cod, vet[i].nome);
  if(contadorVet <= 0)
     printf("\nVOCÊ AINDA NÃO CADASTROU UM AEROPORTO!\n \n");
}

/*  A função abaixo  recebe um numero código >=1 referente a um aeroporto
*   e retorna a posição no vetor de structs vet[0..contadorVet-1] .*/
int posicao_Aero_cod(int codigo){
int i;
for(i=0; i < contadorVet; i++)
    if(vet[i].cod == codigo)
        return i;
}

/*  A função abaixo  recebe um ponteiro de char(String) nomeAe referente ao nome
*  de um  aeroporto e retorna a posição no vetor de structs vet[0..contadorVet-1] .*/
int posicao_Aero_nome(char* nomeAe){
int i;
for(i=0; i < contadorVet; i++)
    if(vet[i].nome == nomeAe)
         return i;
}

/*  A função abaixo  recebe um numero dadoVoo >=1 referente ao cadastro de um vôo
 *  na célula voo* e retorna a posição no vetor de structs vet[0..contadorVoo-1] .*/
int posicao_Aero_voo(int dadoVoo){
int i;
for(i=0; i < contadorVoo; i++)
    if(vet[i].prox_dest->numVoo == dadoVoo)
         return i;
}

/*  A função abaixo  recebe um ponteiro de char(String) nomeAero referente ao nome de um aeroporto e verifica
*   se nomeAero existe no vetor de structs vet[0..contadorVet-1] , retorna 1 se existir e 0 se não.*/
int BuscaAeroporto(char* nomeAero){
 int i;
  for(i=0; i < contadorVet;i++)
    if(strcmp(vet[i].nome,nomeAero) == 0)
        return 1;

 return 0;

}


/*  A função abaixo  recebe um vetor de char(String) n referente ao nome de um aeroporto e verifica
*   se n existe no vetor de structs vetor de structs vet[0..contadorVet-1]  e retorna  código  referente
*   do  aeroporto  vet[0..contadorVet-1] .cod .*/
int BuscaCodAeroporto(char n[]){
 int i;
  for(i=0; i < contadorVet;i++)
    if(strcmp(vet[i].nome,n) == 0)
        return vet[i].cod;
}

/*  A função abaixo  recebe um número pos>=1 referente ao código um aeroporto e verifica
*   se n existe no vetor de structs vetor de structs aero vet[0..contadorVet-1].cod  e retorna
* o nome  referente do  aeroporto  vet[0..contadorVet-1] .nome .*/
char* BuscaNomeAeroporto(int pos){
 int i;
  for(i=0; i < contadorVet;i++)
    if(vet[i].cod == pos)
        return vet[i].nome;

 return "NÃO EXISTE AEROPORTO COM ESSE CÓDIGO!";

}


/*  A função abaixo  recebe um número nVoo>=1 referente ao vôo um aeroporto vet[0..contadorVet-1].numVoo
 *  e verifica se  existe na lista encadeada de voos o nome  referente do  aeroporto  vet[0..contadorVet-1] .nome
 *  e retorna 1 se numVoo existir ou 0 se não.*/
int verificar_voo(int nVoo){
 voo* p; int i =0;
    while( i < 100){

      for(p = vet[i].prox_dest; p!=NULL; p=p->seg)
        if( p->numVoo == nVoo)
             return true;
         i++;
     }

     return false;
}


/*  A função abaixo  recebe um número NumVoo>=1, número  codOrigem >= 1 e um número  codDestino >= 1  e
 *  verifica se codOrigem e codDestino estão cadastrado no vetor de structs aero  vet[0..99] e insere esse elementos
 *  nas posições de uma nova célula do tipo voo *y*/
void CadastraVoo(int NumVoo, int codOrigem, int codDestino){

if(BuscaAeroporto(BuscaNomeAeroporto(codOrigem)) && BuscaAeroporto(BuscaNomeAeroporto(codDestino))){/*Verifica se tanto CodOrigem e CodDestino estão cadastrados no vetor de structs aero vet[0..99]*/
 voo *y;
 y = (voo*) malloc(sizeof(voo));
 y->numVoo = NumVoo;
 y->origem = codOrigem;
 y->destino = codDestino;
 y->seg =  vet[posicao_Aero_cod(codOrigem)].prox_dest;/*Função posicao_Aero_cod retorna a posição onde se encontra codOrigem*/
vet[posicao_Aero_cod(codOrigem)].prox_dest= y;

 printf("\n \n CADASTRO REALIZADO COM SUCESSO!\n \n| VÔO: %d, ORIGEM: %s e DESTINO: %s |\n\n",y->numVoo, BuscaNomeAeroporto(y->origem), BuscaNomeAeroporto(y->destino));
 contadorVoo++;
} else
   printf("\n UM OU DOIS AEROPORTOS NÃO ESTÃO CADASTRADOS!\n \n");

}

/*  A função abaixo  recebe um número nv>=1, número representando um número de
*   um vôo do tipo voo* e percorre a célula anterior *ant e seguinte  *p->seg
*   de uma lista do tipo voo* p e retira a célula referente ao vôo nv*/
void Remove_voo(int nv){
 voo* ant = NULL;
 voo* p = vet[posicao_Aero_voo(nv)].prox_dest;/*Função posicao_Aero_voo retorna a posição onde se encontra o vôo nv em vet*/

 while(p != NULL && p->numVoo != nv){
    ant = p;
    p = p->seg;
 }


 if(p == NULL)/* Não achou, imprime a mensagem*/
    printf("\n\n O VÔO NÃO ESTÁ CADASTRADO! \n\n");


if(ant == NULL)/* Retira o elemento do inicio*/
    vet[posicao_Aero_voo(nv)].prox_dest = p->seg;
else/* Retira o elemento do meio da lista*/
    ant->seg = p->seg;

free(p);
printf("\n\n O VÔO %d FOI REMOVIDO COM SUCESSO!\n\n", nv);
contadorVoo--;
}


/*  A função abaixo  recebe um vetor de char(String) nomeA representando o nome de um aeroporto cadastrado
 *  no vetor se structs vet[0..99] percorre o voo* p e imprime na tela as posições na celula voo* p referentes
 *  ao nome do aeroporto*/
void ImprimirVoos(char nomeA[]){
voo* p; int i =0;
if(BuscaAeroporto(nomeA)==1){/* Verifica se o  nome do aeroporto existe*/
    while( i < 100){

      for(p = vet[i].prox_dest; p!=NULL; p=p->seg)
        if(BuscaCodAeroporto(nomeA) == p->origem)/* Converte o nome do aeroporto no seu respectivo código de origem*/
             printf("NumVoo: %d  Orig: %s  Dest: %s\n", p->numVoo, BuscaNomeAeroporto(p->origem), BuscaNomeAeroporto(p->destino));

         i++;
     }
}else printf("\n\n ESTE AEROPORTO NÃO ESTÁ CADASTRADO!  \n\n");

}

/*  A função abaixo  percorre o vetor de structs vet[0..99] e voo* p
*   e imprime todas as posições da célula voo* p e vet[0..99] */
void ImprimirTudo(){
voo* p; int i =0;
while( i < 100){

      for(p = vet[i].prox_dest; p!=NULL; p=p->seg)
      printf("NumVoo: %d  Orig: %s Dest: %s\n", p->numVoo, BuscaNomeAeroporto(p->origem), BuscaNomeAeroporto(p->destino));
     i++;
}
}

/*  A função abaixo  recebe um numero codOrig>=1 e codDest>=1 e voo* lst
*   imprime todas as posições os vôos em lst onde existem codOrig e codDestino
*   retorna NULL quando chegar ao fim de lst*/
voo *ProcuraVoo(int codOrig, int codDest, voo *lst){

   if(lst == NULL)
    return NULL;

     if(lst->origem == codOrig ||  lst->destino == codDest)
       printf("\n\n Vôo: %d   Origem: %s    Destino: %s \n\n", lst->numVoo, BuscaNomeAeroporto(lst->origem), BuscaNomeAeroporto(lst->destino));

  return ProcuraVoo(codOrig, codDest, lst->seg);
}


/* Funçaõ abaixo cadastra um aeroporto usando as entradas e saidas de dados*/
void CadAeroporto(){
	if(aeroRes >= 0){/*Checa se atingiu o número máximo de de aeroportos*/
   char nomeA[10];
   int codigo;

    printf("DIGITE O NOME DO AEROPORTO: ");
    scanf("%s", &nomeA);
    printf("DIGITE O CÓDIGO DO AEROPORTO: ");
    scanf("%d", &codigo);
    CadastraAeroporto(nomeA, codigo);
    contadorVet++;
    aeroRes--;
    system("cls");
    main();}else{
    	printf("\n\nVOCÊ ATINGIU O NÚMERO MÁXIMO DE CADASTROS DE AEROPORTOS!\n\n");
	}
}

/* A funçaõ abaixo chama a função ImprimirAero() e imprime todos os aeroportos cadastrados*/
void ImpAero(){

    ImprimirAero();
    system("pause");
    system("cls");
    main();
}

/* Funçaõ abaixo cadastra um vôo usando as entradas e saidas de dados*/
void CadVoo(){

   int nVoo, orig, dest;
    printf("DIGITE O NÚMERO DO VÔO: ");
    scanf("%d", &nVoo);
    if(verificar_voo(nVoo) == false){/*Verifica se o número do vôo já existe*/

    printf("DIGITE O CÓDIGO DO AEROPORTO DE ORIGEM: ");
    scanf("%d", &orig);
    printf("DIGITE O CÓDIGO DO AEROPORTO DE DESTINO: ");
    scanf("%d", &dest);

    if(orig != dest){/*Checa se a Origem e o Destino são diferentes, se sim prossegue o Cadastro*/
    CadastraVoo(nVoo,orig,dest);
    system("pause");
    system("cls");
    main();} else{/*Se não imprime mensagem de erro*/
    printf("\n\n A ORIGEM E O DESTINO NÃO PODEM SER IGUAIS! \n\n");
    system("pause");
    system("cls");
    main();
    }
        }else{/*Se já existir o número do vôo imprime mensagem de erro*/
    printf("\n\n O VÔO %d JÁ EXISTE! \n\n", nVoo);
    system("pause");
    system("cls");
    main();
}


}
/* A funçaõ abaixo remove um vôo usando as entradas e saidas de dados*/
void RemovVoo(){

    int numeroVoo;
    printf("DIGITE O NÚMERO DO VÔO QUE DESEJA REMOVER: ");
    scanf("%d", &numeroVoo);
    if(verificar_voo(numeroVoo) == false){/*Verifica se o número do vôo não existe*/
    printf("\n NÃO EXISTE O VÔO %d CADASTRADO! \n\n", numeroVoo);
    system("pause");
    system("cls");
    main();
     }else{/*Se já existir o número do vôo imprime prossegue com a remoção*/
    Remove_voo(numeroVoo);
    system("pause");
    system("cls");
    main();
    }
}

/* A funçaõ abaixo imprime um vôo usando as entradas e saidas de dados*/
void ImpVoos(){

    char nomeAer[10];

    if(contadorVoo == 0){/*Checa se já existe pelo menos 1 vôo cadastrado*/
    printf("\n NÃO EXISTEM VÔOS CADASTRADOS! \n\n", nomeAer);
    system("pause");
    system("cls");
    main();
     }else{/*Se sim, prosegue com o a impressão dos dados*/
    printf("DIGITE O NOME AEROPORTO: ");
    scanf("%s", nomeAer);
    ImprimirVoos(nomeAer);
    system("pause");
    system("cls");
    main();
    }
}
/* A funçaõ abaixo imprime todos os vôos usando as entradas e saidas de dados*/
void ImpTudo(){

    if(contadorVoo == 0){/*Checa se já existe pelo menos 1 vôo cadastrado*/
    printf("\n NÃO EXISTEM VÔOS CADASTRADOS! \n\n");
    system("pause");
    system("cls");
    main();
     }else{/*Se sim, prosegue com o a impressão dos dados*/
    ImprimirTudo();
    system("pause");
    system("cls");
    main();
    }
}


/* A funçaõ abaixo procura os vôos usando as entradas e saidas de dados*/
void ProcuraV(){

 int codO, codD;
    if(contadorVoo == 0){
    printf("\n NÃO EXISTEM VÔOS CADASTRADOS! \n\n");
    system("pause");
    system("cls");
    main();
     }else{
    printf("DIGITE O CÓDIGO DO AEROPORTO DE ORIGEM ");
    scanf("%d", &codO);
    printf("DIGITE O CÓDIGO DO AEROPORTO DE DESTINO: ");
    scanf("%d", &codD);
    ProcuraVoo(codO, codD,vet[posicao_Aero_cod(codO)].prox_dest);
    system("pause");
    system("cls");
    main();}

}


void Cadastro(){ /*CHAMA ESSE FUNÇÃO CASO QUEIRA CADASTRAR OS 5 AEROPORTOS DO EXEMPLO*/

CadastraAeroporto("BSB", 1);
contadorVet++;
aeroRes--;

CadastraAeroporto("CNF", 2);
contadorVet++;
aeroRes--;

CadastraAeroporto("GIG", 3);
contadorVet++;
aeroRes--;

CadastraAeroporto("GRU", 4);
contadorVet++;
aeroRes--;

CadastraAeroporto("SSA", 5);
contadorVet++;
aeroRes--;



}





void Topo(int aeroRestante){

printf(" _________________________         _____ \n");
printf("|                         |         | U |__       _____ \n");
printf("|      SISTEMA ANAC        |_________|   |/_______/___/_____________\n");
printf("|  TP:Estrutura de Dados   |          < /_/   .....................  `-|\n");
printf("|_________________________|            `-----------,----,-------------/ \n");
printf("                                                 _/____/ \n");
printf("| AINDA É POSSÍVEL CADASTRAR %d AEROPORTOS |\n \n", aeroRestante);
printf("| NÚMERO AEROPORTOS CADASTRADOS: %d | NÚMERO DE VÔOS CADASTRADOS: %d |\n \n", contadorVet, contadorVoo);
}


void Menu(){

printf("|---------|MENU|----------|\n");
printf("| 1 - CADASTRAR AEROPORTO |\n");
printf("| 2 - LISTAR AEROPORTOS   |\n");
printf("| 3 - CADASTRAR VÔOS      |\n");
printf("| 4 - REMOVER VÔOS        |\n");
printf("| 5 - IMPRIMIR VÔOS       |\n");
printf("| 6 - IMPRIMIR TUDO       |\n");
printf("| 7 - PROCURAR VÔOS       |\n");
printf("| 8 - SAIR                |\n");
printf("|-------------------------| \n");


}




int main(){

setlocale(LC_ALL, "Portuguese");
Topo(aeroRes);
Menu();

int opcao;

do{

printf("\nDIGITE O CÓDIGO DA OPERAÇÃO DESEJADA: ");
scanf("%d", &opcao);



}while(opcao >= 9 || opcao <= 0 );

switch(opcao){

case 1:
    CadAeroporto();
    break;

case 2:
     ImpAero();
    break;

 case 3:
     CadVoo();
    break;

  case 4:
     RemovVoo();
    break;

    case 5:
    ImpVoos();
    break;

    case 6:
    ImpTudo();
    break;

    case 7:
        ProcuraV();
      break;

    case 8:
        printf("\n\nATÉ LOGO!\n\n");
        exit(1);
         //Cadastro();
         //system("pause");
         //system("cls");
        // main();
break;

  }

}
