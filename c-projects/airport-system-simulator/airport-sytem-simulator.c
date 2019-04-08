#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define true 1
#define false 0

/* Struct Voos contendo n�mero do v�o, destino e origem e um ponteiro *seg para o pr�ximo voo*/
struct Voos{
int numVoo, destino, origem;

struct Voos *seg;

};

typedef struct Voos voo;

/* Struct aeporto contendo o c�digo e o nome deste, e um ponteiro *prox_dest apontando para o primeiro v�o*/
struct aeroporto{

int cod;
char* nome;
struct Voos *prox_dest;

};
typedef struct aeroporto aero;

/*  Vari�veis Globais necess�rias ao funcionamento do programa:
*   aeroRes: ser� decrementado a medida que forem feitos novos cadastros de aeroportos.
*   contadorVet: ser� incrementado e decrementado a medida que forem feitos cadastros no vetor de structs aero vet.
*   contadorVoo: ser� incrementado e decrementado a medida que forem feitos cadastros de v�os.*/
int aeroRes = 100, contadorVet = 0, contadorVoo = 0;

/*  Vetor de structs do tipo aero de tamanho 100 que ir� guardar todas as posi��es dos aeroportos cadastrados*/
aero vet[100];


/*  A fun��o abaixo recebe um ponteiro de char(String) e um valor inteiro
*   codigo>= 1 e cadastra no vetor de structs vet[0...99] as posi��es
*   indicadas por  contadorVet referente a cada item da struct aero.*/
void CadastraAeroporto(char* cidade, int codigo){
      vet[contadorVet].cod = codigo;
      vet[contadorVet].nome = cidade;
      vet[contadorVet].prox_dest = NULL;
      printf("%d %s \n",vet[contadorVet].cod, vet[contadorVet].nome);
}

/* A fun��o abaixo  percorre o vetor de structs aero vet[0..contadorVet-1] e imprime na tela  as
*  posi��es referente ao c�digo vet[0..contadorVet-1].cod e o nome vet[0..contadorVet-1].nome .*/
void ImprimirAero(){

int i;
  for(i=0; i < contadorVet;i++)
       printf("C�DIGO: %d NOME: %s \n",vet[i].cod, vet[i].nome);
  if(contadorVet <= 0)
     printf("\nVOC� AINDA N�O CADASTROU UM AEROPORTO!\n \n");
}

/*  A fun��o abaixo  recebe um numero c�digo >=1 referente a um aeroporto
*   e retorna a posi��o no vetor de structs vet[0..contadorVet-1] .*/
int posicao_Aero_cod(int codigo){
int i;
for(i=0; i < contadorVet; i++)
    if(vet[i].cod == codigo)
        return i;
}

/*  A fun��o abaixo  recebe um ponteiro de char(String) nomeAe referente ao nome
*  de um  aeroporto e retorna a posi��o no vetor de structs vet[0..contadorVet-1] .*/
int posicao_Aero_nome(char* nomeAe){
int i;
for(i=0; i < contadorVet; i++)
    if(vet[i].nome == nomeAe)
         return i;
}

/*  A fun��o abaixo  recebe um numero dadoVoo >=1 referente ao cadastro de um v�o
 *  na c�lula voo* e retorna a posi��o no vetor de structs vet[0..contadorVoo-1] .*/
int posicao_Aero_voo(int dadoVoo){
int i;
for(i=0; i < contadorVoo; i++)
    if(vet[i].prox_dest->numVoo == dadoVoo)
         return i;
}

/*  A fun��o abaixo  recebe um ponteiro de char(String) nomeAero referente ao nome de um aeroporto e verifica
*   se nomeAero existe no vetor de structs vet[0..contadorVet-1] , retorna 1 se existir e 0 se n�o.*/
int BuscaAeroporto(char* nomeAero){
 int i;
  for(i=0; i < contadorVet;i++)
    if(strcmp(vet[i].nome,nomeAero) == 0)
        return 1;

 return 0;

}


/*  A fun��o abaixo  recebe um vetor de char(String) n referente ao nome de um aeroporto e verifica
*   se n existe no vetor de structs vetor de structs vet[0..contadorVet-1]  e retorna  c�digo  referente
*   do  aeroporto  vet[0..contadorVet-1] .cod .*/
int BuscaCodAeroporto(char n[]){
 int i;
  for(i=0; i < contadorVet;i++)
    if(strcmp(vet[i].nome,n) == 0)
        return vet[i].cod;
}

/*  A fun��o abaixo  recebe um n�mero pos>=1 referente ao c�digo um aeroporto e verifica
*   se n existe no vetor de structs vetor de structs aero vet[0..contadorVet-1].cod  e retorna
* o nome  referente do  aeroporto  vet[0..contadorVet-1] .nome .*/
char* BuscaNomeAeroporto(int pos){
 int i;
  for(i=0; i < contadorVet;i++)
    if(vet[i].cod == pos)
        return vet[i].nome;

 return "N�O EXISTE AEROPORTO COM ESSE C�DIGO!";

}


/*  A fun��o abaixo  recebe um n�mero nVoo>=1 referente ao v�o um aeroporto vet[0..contadorVet-1].numVoo
 *  e verifica se  existe na lista encadeada de voos o nome  referente do  aeroporto  vet[0..contadorVet-1] .nome
 *  e retorna 1 se numVoo existir ou 0 se n�o.*/
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


/*  A fun��o abaixo  recebe um n�mero NumVoo>=1, n�mero  codOrigem >= 1 e um n�mero  codDestino >= 1  e
 *  verifica se codOrigem e codDestino est�o cadastrado no vetor de structs aero  vet[0..99] e insere esse elementos
 *  nas posi��es de uma nova c�lula do tipo voo *y*/
void CadastraVoo(int NumVoo, int codOrigem, int codDestino){

if(BuscaAeroporto(BuscaNomeAeroporto(codOrigem)) && BuscaAeroporto(BuscaNomeAeroporto(codDestino))){/*Verifica se tanto CodOrigem e CodDestino est�o cadastrados no vetor de structs aero vet[0..99]*/
 voo *y;
 y = (voo*) malloc(sizeof(voo));
 y->numVoo = NumVoo;
 y->origem = codOrigem;
 y->destino = codDestino;
 y->seg =  vet[posicao_Aero_cod(codOrigem)].prox_dest;/*Fun��o posicao_Aero_cod retorna a posi��o onde se encontra codOrigem*/
vet[posicao_Aero_cod(codOrigem)].prox_dest= y;

 printf("\n \n CADASTRO REALIZADO COM SUCESSO!\n \n| V�O: %d, ORIGEM: %s e DESTINO: %s |\n\n",y->numVoo, BuscaNomeAeroporto(y->origem), BuscaNomeAeroporto(y->destino));
 contadorVoo++;
} else
   printf("\n UM OU DOIS AEROPORTOS N�O EST�O CADASTRADOS!\n \n");

}

/*  A fun��o abaixo  recebe um n�mero nv>=1, n�mero representando um n�mero de
*   um v�o do tipo voo* e percorre a c�lula anterior *ant e seguinte  *p->seg
*   de uma lista do tipo voo* p e retira a c�lula referente ao v�o nv*/
void Remove_voo(int nv){
 voo* ant = NULL;
 voo* p = vet[posicao_Aero_voo(nv)].prox_dest;/*Fun��o posicao_Aero_voo retorna a posi��o onde se encontra o v�o nv em vet*/

 while(p != NULL && p->numVoo != nv){
    ant = p;
    p = p->seg;
 }


 if(p == NULL)/* N�o achou, imprime a mensagem*/
    printf("\n\n O V�O N�O EST� CADASTRADO! \n\n");


if(ant == NULL)/* Retira o elemento do inicio*/
    vet[posicao_Aero_voo(nv)].prox_dest = p->seg;
else/* Retira o elemento do meio da lista*/
    ant->seg = p->seg;

free(p);
printf("\n\n O V�O %d FOI REMOVIDO COM SUCESSO!\n\n", nv);
contadorVoo--;
}


/*  A fun��o abaixo  recebe um vetor de char(String) nomeA representando o nome de um aeroporto cadastrado
 *  no vetor se structs vet[0..99] percorre o voo* p e imprime na tela as posi��es na celula voo* p referentes
 *  ao nome do aeroporto*/
void ImprimirVoos(char nomeA[]){
voo* p; int i =0;
if(BuscaAeroporto(nomeA)==1){/* Verifica se o  nome do aeroporto existe*/
    while( i < 100){

      for(p = vet[i].prox_dest; p!=NULL; p=p->seg)
        if(BuscaCodAeroporto(nomeA) == p->origem)/* Converte o nome do aeroporto no seu respectivo c�digo de origem*/
             printf("NumVoo: %d  Orig: %s  Dest: %s\n", p->numVoo, BuscaNomeAeroporto(p->origem), BuscaNomeAeroporto(p->destino));

         i++;
     }
}else printf("\n\n ESTE AEROPORTO N�O EST� CADASTRADO!  \n\n");

}

/*  A fun��o abaixo  percorre o vetor de structs vet[0..99] e voo* p
*   e imprime todas as posi��es da c�lula voo* p e vet[0..99] */
void ImprimirTudo(){
voo* p; int i =0;
while( i < 100){

      for(p = vet[i].prox_dest; p!=NULL; p=p->seg)
      printf("NumVoo: %d  Orig: %s Dest: %s\n", p->numVoo, BuscaNomeAeroporto(p->origem), BuscaNomeAeroporto(p->destino));
     i++;
}
}

/*  A fun��o abaixo  recebe um numero codOrig>=1 e codDest>=1 e voo* lst
*   imprime todas as posi��es os v�os em lst onde existem codOrig e codDestino
*   retorna NULL quando chegar ao fim de lst*/
voo *ProcuraVoo(int codOrig, int codDest, voo *lst){

   if(lst == NULL)
    return NULL;

     if(lst->origem == codOrig ||  lst->destino == codDest)
       printf("\n\n V�o: %d   Origem: %s    Destino: %s \n\n", lst->numVoo, BuscaNomeAeroporto(lst->origem), BuscaNomeAeroporto(lst->destino));

  return ProcuraVoo(codOrig, codDest, lst->seg);
}


/* Fun�a� abaixo cadastra um aeroporto usando as entradas e saidas de dados*/
void CadAeroporto(){
	if(aeroRes >= 0){/*Checa se atingiu o n�mero m�ximo de de aeroportos*/
   char nomeA[10];
   int codigo;

    printf("DIGITE O NOME DO AEROPORTO: ");
    scanf("%s", &nomeA);
    printf("DIGITE O C�DIGO DO AEROPORTO: ");
    scanf("%d", &codigo);
    CadastraAeroporto(nomeA, codigo);
    contadorVet++;
    aeroRes--;
    system("cls");
    main();}else{
    	printf("\n\nVOC� ATINGIU O N�MERO M�XIMO DE CADASTROS DE AEROPORTOS!\n\n");
	}
}

/* A fun�a� abaixo chama a fun��o ImprimirAero() e imprime todos os aeroportos cadastrados*/
void ImpAero(){

    ImprimirAero();
    system("pause");
    system("cls");
    main();
}

/* Fun�a� abaixo cadastra um v�o usando as entradas e saidas de dados*/
void CadVoo(){

   int nVoo, orig, dest;
    printf("DIGITE O N�MERO DO V�O: ");
    scanf("%d", &nVoo);
    if(verificar_voo(nVoo) == false){/*Verifica se o n�mero do v�o j� existe*/

    printf("DIGITE O C�DIGO DO AEROPORTO DE ORIGEM: ");
    scanf("%d", &orig);
    printf("DIGITE O C�DIGO DO AEROPORTO DE DESTINO: ");
    scanf("%d", &dest);

    if(orig != dest){/*Checa se a Origem e o Destino s�o diferentes, se sim prossegue o Cadastro*/
    CadastraVoo(nVoo,orig,dest);
    system("pause");
    system("cls");
    main();} else{/*Se n�o imprime mensagem de erro*/
    printf("\n\n A ORIGEM E O DESTINO N�O PODEM SER IGUAIS! \n\n");
    system("pause");
    system("cls");
    main();
    }
        }else{/*Se j� existir o n�mero do v�o imprime mensagem de erro*/
    printf("\n\n O V�O %d J� EXISTE! \n\n", nVoo);
    system("pause");
    system("cls");
    main();
}


}
/* A fun�a� abaixo remove um v�o usando as entradas e saidas de dados*/
void RemovVoo(){

    int numeroVoo;
    printf("DIGITE O N�MERO DO V�O QUE DESEJA REMOVER: ");
    scanf("%d", &numeroVoo);
    if(verificar_voo(numeroVoo) == false){/*Verifica se o n�mero do v�o n�o existe*/
    printf("\n N�O EXISTE O V�O %d CADASTRADO! \n\n", numeroVoo);
    system("pause");
    system("cls");
    main();
     }else{/*Se j� existir o n�mero do v�o imprime prossegue com a remo��o*/
    Remove_voo(numeroVoo);
    system("pause");
    system("cls");
    main();
    }
}

/* A fun�a� abaixo imprime um v�o usando as entradas e saidas de dados*/
void ImpVoos(){

    char nomeAer[10];

    if(contadorVoo == 0){/*Checa se j� existe pelo menos 1 v�o cadastrado*/
    printf("\n N�O EXISTEM V�OS CADASTRADOS! \n\n", nomeAer);
    system("pause");
    system("cls");
    main();
     }else{/*Se sim, prosegue com o a impress�o dos dados*/
    printf("DIGITE O NOME AEROPORTO: ");
    scanf("%s", nomeAer);
    ImprimirVoos(nomeAer);
    system("pause");
    system("cls");
    main();
    }
}
/* A fun�a� abaixo imprime todos os v�os usando as entradas e saidas de dados*/
void ImpTudo(){

    if(contadorVoo == 0){/*Checa se j� existe pelo menos 1 v�o cadastrado*/
    printf("\n N�O EXISTEM V�OS CADASTRADOS! \n\n");
    system("pause");
    system("cls");
    main();
     }else{/*Se sim, prosegue com o a impress�o dos dados*/
    ImprimirTudo();
    system("pause");
    system("cls");
    main();
    }
}


/* A fun�a� abaixo procura os v�os usando as entradas e saidas de dados*/
void ProcuraV(){

 int codO, codD;
    if(contadorVoo == 0){
    printf("\n N�O EXISTEM V�OS CADASTRADOS! \n\n");
    system("pause");
    system("cls");
    main();
     }else{
    printf("DIGITE O C�DIGO DO AEROPORTO DE ORIGEM ");
    scanf("%d", &codO);
    printf("DIGITE O C�DIGO DO AEROPORTO DE DESTINO: ");
    scanf("%d", &codD);
    ProcuraVoo(codO, codD,vet[posicao_Aero_cod(codO)].prox_dest);
    system("pause");
    system("cls");
    main();}

}


void Cadastro(){ /*CHAMA ESSE FUN��O CASO QUEIRA CADASTRAR OS 5 AEROPORTOS DO EXEMPLO*/

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
printf("| AINDA � POSS�VEL CADASTRAR %d AEROPORTOS |\n \n", aeroRestante);
printf("| N�MERO AEROPORTOS CADASTRADOS: %d | N�MERO DE V�OS CADASTRADOS: %d |\n \n", contadorVet, contadorVoo);
}


void Menu(){

printf("|---------|MENU|----------|\n");
printf("| 1 - CADASTRAR AEROPORTO |\n");
printf("| 2 - LISTAR AEROPORTOS   |\n");
printf("| 3 - CADASTRAR V�OS      |\n");
printf("| 4 - REMOVER V�OS        |\n");
printf("| 5 - IMPRIMIR V�OS       |\n");
printf("| 6 - IMPRIMIR TUDO       |\n");
printf("| 7 - PROCURAR V�OS       |\n");
printf("| 8 - SAIR                |\n");
printf("|-------------------------| \n");


}




int main(){

setlocale(LC_ALL, "Portuguese");
Topo(aeroRes);
Menu();

int opcao;

do{

printf("\nDIGITE O C�DIGO DA OPERA��O DESEJADA: ");
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
        printf("\n\nAT� LOGO!\n\n");
        exit(1);
         //Cadastro();
         //system("pause");
         //system("cls");
        // main();
break;

  }

}
