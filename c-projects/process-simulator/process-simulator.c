#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define true 1
#define false 0

typedef struct processo{
char id[10];
int instante;
int Dcpu;
int Ddisco;
int Drede;
int prioridade;
struct processo* seg;
}Proc;

typedef struct filaProcessos{
Proc* ini;
Proc* fim;
}Fila;

typedef struct Computador{
int ID;
Fila* CPU;
Fila* DISCO1;
Fila* DISCO2;
}Comp;

/* Variáveis globais necessárias para capturar os dados do processamento*/
int numeroProcessos = 0, relogio = 0, tempoTotalRede = 0, tempoEsperaTotal = 0, ProcTotal = 0;

/* Vetor de estrutura de computadores, uso máximo de 15 computadores, possibilidade de
 * ser aumentado, se for o desejo do usuário*/
Comp* Computers[15];

/* Esta função recebe uma string data e uma string esc_politica
 * e grava em um arquivo os dados de cabeçalho*/
void GravarRelCabecalho(char data[], char esc_politica[]){

FILE *arqs= fopen("RELATORIO.txt", "at");
if(arqs == NULL){
    printf("\nARQUIVO NÃO ENCONTRADO!");
    exit(1);
}
else{
    fprintf(arqs,"\n----------------------------------------------------------------------------------------\n");
    fprintf(arqs,"  ########################### RELATÓRIO - NEOLOOK OS ##################################### ");
    fprintf(arqs,"\n----------------------------------------------------------------------------------------\n");
    fprintf(arqs,"      Nº DE PROCESSOS SIMULADOS: %d   DATA E HORA: %s", numeroProcessos,data);
    fprintf(arqs,"------------------------------------------------------------------------------------------\n");
    fprintf(arqs,"                              ESCALONAMENTO:  %s\n", esc_politica);
    fprintf(arqs,"------------------------------------------------------------------------------------------\n");
    fclose(arqs);}
    }

/* Esta função recebe valor IDcomp representando um computador e grava em um
 * arquivo os dados de cabeçalho*/
void GravarRelatorioComp(int IDcomp){

FILE *arqs= fopen("RELATORIO.txt", "at");
if(arqs == NULL){
    printf("\nARQUIVO NÃO ENCONTRADO!");
    exit(1);
}
else{
    fprintf(arqs,"\n-------------------------------------------------------------------------------------\n");
    fprintf(arqs,"*************************|COMPUTADOR|-| %d | - |FILA CPU|*****************************\n",IDcomp);
    fprintf(arqs,"--------------------------------------------------------------------------------------\n");
    fprintf(arqs,"| PROCESSO | ESCALONAMENTO | TEMPO DE CPU | TEMPO DE DISCO |  PRI  | TEMPO DE ESPERA |\n");
    fprintf(arqs,"--------------------------------------------------------------------------------------\n");
    }
    fclose(arqs);
}

/* Esta função recebe valor IDcomp>=1 representando um computador e um valor 2<=IDdisco<=1
 * representando um disco e grava em um arquivo os dados de cabeçalho Referente aos DISCOS*/
void GravarRelatorioDisc(int IDcomp, int IDdisco){

FILE *arqs= fopen("RELATORIO.txt", "at");
if(arqs == NULL){
    printf("\nARQUIVO NÃO ENCONTRADO!");
    exit(1);
    }
else{
    fprintf(arqs,"\n-------------------------------------------------------------------------------------\n");
    fprintf(arqs,"*************************|COMPUTADOR|-| %d | - |FILA DISCO %d|************************\n",IDcomp, IDdisco);
    fprintf(arqs,"--------------------------------------------------------------------------------------\n");
    fprintf(arqs,"| PROCESSO | ESCALONAMENTO | TEMPO DE CPU | TEMPO DE DISCO |  PRI  | TEMPO DE ESPERA |\n");
    fprintf(arqs,"--------------------------------------------------------------------------------------\n");
    }
    fclose(arqs);
}
/* Esta função grava em um arquivo os dados de cabeçalho referente a REDE*/
void GravarRelatorioRede(){

FILE *arqs= fopen("RELATORIO.txt", "at");
if(arqs == NULL){
    printf("\nARQUIVO NÃO ENCONTRADO!");
    exit(1);
    }
else{
    fprintf(arqs,"\n-------------------------------------------------------------------------------------\n");
    fprintf(arqs,"**********************************|  FILA REDE  |*************************************\n");
    fprintf(arqs,"--------------------------------------------------------------------------------------\n");
    fprintf(arqs,"| PROCESSO | ESCALONAMENTO | TEMPO DE CPU | TEMPO DE REDE |  PRI  | TEMPO DE ESPERA |\n");
    fprintf(arqs,"--------------------------------------------------------------------------------------\n");
    }
    fclose(arqs);
}
/* Esta função recebe uma string idProc com o ID de um processo, uma string esc com escalonamento utilizado
 * um valor tcpu>=1 com o tempo de CPU de um processo, um valor tdisco>=1 com o tempo de DISCO de um
 * processo um valor prio>=1 coma prioridade de um processo e um valor espera>=0 com o tempo de espera
 * de um processo e grava esses dados em um arquivo referente a fila de uma CPU*/
void GravarRelatorioC(char idProc[], char esc[], int tcpu, int tdisco, int prio, int espera){

FILE *arqs= fopen("RELATORIO.txt", "at");
if(arqs == NULL){
    printf("\nARQUIVO NÃO ENCONTRADO!");
    exit(1);
    }
else{
    fprintf(arqs,"|   %s     |      %s       |       %d     |       %d       |   %d   |        %d      |\n", idProc,esc,tcpu, tdisco, prio, espera);
    fprintf(arqs,"--------------------------------------------------------------------------------------\n");
}
fclose(arqs);
}

/* Esta função recebe uma string idProc com o ID de um processo, uma string esc com escalonamento utilizado
 * um valor tcpu>=1 com o tempo de CPU de um processo, um valor tdisco>=1 com o tempo de DISCO de um
 * processo um valor prio>=1 coma prioridade de um processo e um valor espera>=0 com o tempo de espera
 * de um processo e grava esses dados em um arquivo referente a fila de um DISCO*/
void GravarRelatorioD(char idProc[], char esc[], int tcpu, int tdisco, int prio, int espera){

FILE *arqs= fopen("RELATORIO.txt", "at");
if(arqs == NULL){
    printf("\nARQUIVO NÃO ENCONTRADO!");
    exit(1);
}
else{
    fprintf(arqs,"|   %s     |      %s       |       %d      |       %d      |   %d   |        %d      |\n", idProc,esc,tcpu, tdisco, prio, espera);
    fprintf(arqs,"--------------------------------------------------------------------------------------\n");
}
fclose(arqs);
}

/* Esta função recebe uma string idProc com o ID de um processo, uma string esc com escalonamento utilizado
 * um valor tcpu>=1 com o tempo de CPU de um processo, um valor trede>=1 com o tempo de REDE de um processo
 * um valor prio>=1 coma prioridade de um processo e um valor espera>=0 com o tempo de espera de um processo
 * e grava esses dados em um arquivo referente a fila da REDE*/
void GravarRelatorioR(char idProc[], char esc[], int tcpu, int trede, int prio, int espera){

FILE *arqs= fopen("RELATORIO.txt", "at");
if(arqs == NULL){
    printf("\nARQUIVO NÃO ENCONTRADO!");
    exit(1);
    }
else{
    fprintf(arqs,"|   %s     |      %s       |       %d      |       %d      |   %d   |        %d      |\n", idProc,esc,tcpu, trede, prio, espera);
    fprintf(arqs,"--------------------------------------------------------------------------------------\n");
}
fclose(arqs);
}

/* Esta função recebe um valor tempEsp>=0 referente ao tempo de espera de um recurso e um valor
 * quant>=0 com a quantidade de processos numa fila de um determinado recurso*/
void GravarTempoEspera(int tempEsp, int quant){
int aux = tempEsp;
aux/=quant;/* Cálculo do tempo médio de espera*/
tempoEsperaTotal += aux;/* Armazena o tempo médio de espera em cada recurso*/
FILE *arqs= fopen("RELATORIO.txt", "at");
if(arqs == NULL){
    printf("\nARQUIVO NÃO ENCONTRADO!");
    exit(1);
    }
else{
    fprintf(arqs,"|             TEMPO MÉDIO DE ESPERA NESTE RECURSO FOI DE %d UNIDADE(S)                 |\n", aux);
    fprintf(arqs,"--------------------------------------------------------------------------------------\n");
}
fclose(arqs);
}

/* Esta função recebe um valor tempProc>=0 referente ao tempo de processamento de um recurso e um valor
 * quant>=0 com a quantidade de processos numa fila de um determinado recurso*/
void GravarTempoProcessamento(int tempProc, int quant){
int aux = tempProc;
aux/=quant;
FILE *arqs= fopen("RELATORIO.txt", "at");
if(arqs == NULL){
    printf("\nARQUIVO NÃO ENCONTRADO!");
    exit(1);
    }
else{
    fprintf(arqs,"|           TEMPO MÉDIO DE PROCESSAMENTO NESTE RECURSO FOI DE %d UNIDADE(S)            |\n", aux);
    fprintf(arqs,"--------------------------------------------------------------------------------------\n");
}
fclose(arqs);
}

/* Esta função recebe uma string esc referente ao escalonamento utilizado na simulação e grava em um arquivo
 * os resultados finais de uma simulação*/
void GravarTempoDadosFinais( char esc[]){
int aux = tempoEsperaTotal, aux2 = ProcTotal;/*armazena as os valores das variaveis com os tempos totais de espera e processamento*/
float tempProc = numeroProcessos;/*armazena o número de processos*/
aux/=numeroProcessos;/*calcula a média de espera*/
tempProc/=aux2;/*calcula a taxa de processamento*/
FILE *arqs= fopen("RELATORIO.txt", "at");
if(arqs == NULL){
    printf("\nARQUIVO NÃO ENCONTRADO!");
    exit(1);
    }
else{
    fprintf(arqs,"\n|++++++++++++++++++++++ POLÍTICA DE ESCALONAMENTO: %s ++++++++++++++++++++++++++|\n", esc);
    fprintf(arqs,"           * TAXA PROCESSAMENTO NO NEOLOOK: %f UNIDADE(S) DE TEMPO                \n", tempProc);
    fprintf(arqs,"----------------------------------------------------------------------------------\n");
    fprintf(arqs,"           * TEMPO MÉDIO DE ESPERA NO NEOLOOK: %d UNIDADE(S) DE TEMPO             \n", aux);
    fprintf(arqs,"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}
fclose(arqs);
}

/*Esta função recebe uma fila de lista encadeada f sem cabeça e grava em um arquivo o conteudo de f*/
void GravarlistaProcessos(Fila *f){
Proc* p;

FILE *arqs= fopen("RELATORIO.txt", "at");
if(arqs == NULL){
    printf("\nARQUIVO NÃO ENCONTRADO!");
    exit(1);
    }
else{
    fprintf(arqs,"-------------------------PROCESSOS NA FILA INICIAL---------------------------------\n");
    for(p =f->ini; p != NULL; p = p->seg)
    fprintf(arqs,"                             %s %d %d %d %d %d\n", p->id, p->instante, p->Dcpu, p->Ddisco, p->Drede, p->prioridade);
    fprintf(arqs,"-----------------------------------------------------------------------------------\n");
}
fclose(arqs);
}
/*Esta função recebe valor n>=1, uma matriz matrizProc[n][5] e uma string nomeArquivo
 *e grava em um arquivo o conteudo de matrizProc*/
void gravaProcessosArquivo(int n,int matrizProc[n][5], char nomeArquivo[]){

  FILE* arq =  fopen(nomeArquivo, "at");
  char nome[5];
if(arq == NULL){
    printf("Erro, não foi possível abrir o arquivo! \n");
    exit(1);
    }
	else{
        int i, j;
        for(i = 0; i < n; i++){
          for(j = 0; j < 5; j++)
           fprintf(arq,"%4d",matrizProc[i][j]);

       fprintf(arq,"\n");
        }
    }
  fclose(arq);
}
/*Esta função cria uma fila de lista encadeada sem cabeça vazia*/
Fila* fila_criar(){
Fila* f = (Fila*) malloc(sizeof(Fila));
f->ini = f->fim = NULL;
return f;
}

/*Esta função recebe uma fila de lista encadeada f sem cabeça e devolve 1
 * se f está vazia ou 0 se não*/
int fila_vazia(Fila* f){
return(f->ini == NULL);
}

/*Esta função recebe uma de lista encadeada lst sem cabeça e imprime o conteudo de lst*/
void imprima(Proc *lst){
Proc* p;
for(p =lst; p != NULL; p = p->seg)
    printf("%s %d %d %d %d %d \n",p->id, p->instante, p->Dcpu, p->Ddisco, p->Drede, p->prioridade);
}

/*Esta função recebe uma fila de lista encadeada f sem cabeça e imprime o conteudo de f*/
void imprimaFila(Fila *f){
Proc* p;
for(p =f->ini; p != NULL; p = p->seg)
    printf("%s %d %d %d %d %d \n",p->id, p->instante, p->Dcpu, p->Ddisco, p->Drede, p->prioridade);
}

/*Esta função recebe uma fila de lista encadeada fila sem cabeça e uma lista encadeada Proc
 * e insere um processo na posição final de fila*/
void InsereFila(Fila* fila, Proc* proces){

Proc *nP = (Proc*) malloc(sizeof(Proc));
strcpy(nP->id,proces->id);
nP->instante = proces->instante;
nP->Dcpu = proces->Dcpu;
nP->Ddisco = proces->Ddisco;
nP->Drede = proces->Drede;
nP->prioridade = proces->prioridade;
nP->seg = NULL;
if(fila->fim != NULL)
    fila->fim->seg = nP;
else
   fila->ini = nP;

fila->fim = nP;
}



/*Esta função recebe uma fila de lista encadeada fila sem cabeça e remove a posição inicial de fila */
void RemoveFila(Fila *fila){
 Proc *p;
 if(fila_vazia(fila)){
    printf("\n A FILA DO ESCALONAMENTO ESTÁ VAZIA!\n");
    system("pause");
 }
   p = fila->ini;
   fila->ini = p->seg;
   if(fila->ini ==NULL)
    fila->fim = NULL;
   free (p);
}

/* Esta função recebe uma lista encadeada a e uma lista encadeada b e faz a troca do processo a pelo processo b*/
void troca(Proc *a, Proc *b){
int temp1, temp2, temp3, temp4, temp5;
char aux[10];

	strcpy(aux, a->id);
	strcpy(a->id, b->id);
    strcpy(b->id, aux);

    temp1 = a->instante;
    a->instante = b->instante;
    b->instante = temp1;

    temp2 = a->Dcpu;
    a->Dcpu = b->Dcpu;
    b->Dcpu = temp2;

	temp3 = a->Ddisco;
    a->Ddisco = b->Ddisco;
    b->Ddisco = temp3;

	temp4 = a->Drede;
    a->Drede = b->Drede;
    b->Drede = temp4;

	temp5 = a->prioridade;
    a->prioridade = b->prioridade;
    b->prioridade = temp5;

}
/* Esta função recebe uma fila de lista encadeada lst sem cabeça e rearranja lst em ordem crescente com
 * base nos tempos de CPU*/
void OrdenaSJF_cpu(Fila* lst){
    int trocado, i;
    Proc *p;
    Proc *aux = NULL;

    if (lst->ini == NULL){/* Checar se a lista está vazia */
	    printf("\n A FILA ESTÁ VAZIA\n");
        exit(1);}
    do {
        trocado = false;
        p = lst->ini;

        while (p->seg != aux){
            if (p->Dcpu > p->seg->Dcpu){
                troca(p, p->seg);
                trocado = true;}
            p = p->seg;
        }
        aux = p;
    } while (trocado);
}

/* Esta função recebe uma fila de lista encadeada lst sem cabeça e rearranja lst em ordem crescente com
 * base na PRIORIDADE*/
void OrdenaSJF_pri(Fila* lst)
{
    int trocado, i;
    Proc *p;
    Proc *aux = NULL;

    if (lst->ini == NULL){/* Checar se a lista está vazia */
	    printf("\n A FILA ESTÁ VAZIA\n");
        exit(1);}
    do {
        trocado = false;
        p = lst->ini;

        while (p->seg != aux){
            if (p->prioridade > p->seg->prioridade){
                troca(p, p->seg);
                trocado = true;}
            p = p->seg;
        }
        aux = p;
    } while (trocado);
}

/* Esta função recebe uma fila de lista encadeada lst sem cabeça e rearranja lst em ordem crescente com
 * base nos tempos de REDE*/
void OrdenaSJF_Rede(Fila* lst){
    int trocado, i;
    Proc *p;
    Proc *aux = NULL;

    if (lst->ini == NULL){/* Checar se a lista está vazia */
	    printf("\n A FILA ESTÁ VAZIA\n");
        exit(1);}
    do {
        trocado = false;
        p = lst->ini;

        while (p->seg != aux){
            if (p->Drede > p->seg->Drede){
                troca(p, p->seg);
                trocado = true;}
            p = p->seg;
        }
        aux = p;
    } while (trocado);
}

/* Esta função recebe uma fila de lista encadeada lst sem cabeça e rearranja lst em ordem crescente com
 * base nos tempos de DISCO*/
void OrdenaSJF_disco(Fila* lst){
 int trocado, i;
    Proc *p;
    Proc *aux = NULL;

    if (lst->ini == NULL){/* Checar se a lista está vazia */
	    printf("\n A FILA ESTÁ VAZIA\n");
        exit(1);}
    do {
        trocado = false;
        p = lst->ini;

        while (p->seg != aux){
            if (p->Ddisco > p->seg->Ddisco){
                troca(p, p->seg);
                trocado = true;}
            p = p->seg;
        }
        aux = p;
    } while (trocado);
}

/* Esta função recebe uma estrutura recurso representando um computador, uma fila de lista encadeada
 * sem cabeça Rede, uma string escalonamento e um valor idpc>=1 representando o ID de um computador
 * e faz o processamento de cada processo nas filas de recurso*/
void Processamento(Comp* recurso, Fila * Rede, char escalonamento[], int idpc){

int aux = 0, aux2 = 0, aux3 =0, tempoEsperaCPU = 0, tempoEsperaD1 = 0, tempoEsperaD2 = 0, quantproc = 0;
int tempoCPU =0, tempoDisco = 0, tempoDisco2 = 0;
if(recurso->CPU->ini != NULL){/*Checa se a fila de CPU não está vazia*/

/*Checa o escalonamento usado e se a respectiva fila possui mais de dois processos*/
if(strcmp(escalonamento, "SJF") == 0 || strcmp(escalonamento, "sjf") == 0 && recurso->CPU->ini->seg != NULL)
     OrdenaSJF_cpu(recurso->CPU);/*Ordena a fila*/
else if(strcmp(escalonamento, "PRI") == 0 || strcmp(escalonamento, "pri") == 0 && recurso->CPU->ini->seg != NULL)
     OrdenaSJF_pri(recurso->CPU);/*Ordena a fila em ordem crescente referente a prioridade*/

GravarRelatorioComp(recurso->ID);/*Grava o cabeçalho no arquivo*/

 while(recurso->CPU->ini != NULL){/*Processa a fila da CPU*/

    int disc = 1 + rand()%2;/*Sorteia um disco*/
    tempoCPU = recurso->CPU->ini->Dcpu;/* Guarda os tempos em cada processo na fila*/
     quantproc++;/*conta o número de processos na fila*/

    if(recurso->ID == idpc){/*Grava apenas os dados de processos por computador*/
    tempoEsperaCPU+=aux;/* Tempo total de espera*/
    GravarRelatorioC(recurso->CPU->ini->id,escalonamento,recurso->CPU->ini->Dcpu,
	                 recurso->CPU->ini->Ddisco, recurso->CPU->ini->prioridade, aux);/*Grava no arquivo os dados sobre essa fila*/

    }
     aux+=tempoCPU;/* Tempo de espera por processo*/

    if(disc == 1){
    InsereFila(recurso->DISCO1,recurso->CPU->ini);/* Insere o processo na respectiva fila de DISCO*/
    RemoveFila(recurso->CPU);/* Remove o processo da fila de CPU*/

    } else if(disc == 2){
    InsereFila(recurso->DISCO2,recurso->CPU->ini);
    RemoveFila(recurso->CPU);
      }
}/*fim do while*/
ProcTotal+=aux;/*Armazena o tempo de processamento total em cada recurso*/
GravarTempoProcessamento(aux,quantproc);/*Grava no arquivo o processamento do recurso*/
GravarTempoEspera(tempoEsperaCPU, quantproc);/*Grava no arquivo o tempo de espra médio do recurso*/
quantproc = 0;

    if(recurso->DISCO1->ini != NULL){/*Checa se a fila de DISCO não está vazia*/

        GravarRelatorioDisc(recurso->ID, 1);/*Grava o cabeçalho no arquivo*/
        if(strcmp(escalonamento, "SJF") == 0 || strcmp(escalonamento, "sjf") == 0 && recurso->DISCO1->ini->seg != NULL)
         OrdenaSJF_disco(recurso->DISCO1);
       else if(strcmp(escalonamento, "PRI") == 0 || strcmp(escalonamento, "pri") == 0 && recurso->DISCO1->ini->seg != NULL)
         OrdenaSJF_pri(recurso->DISCO1);/*Ordena a fila em ordem crescente referente a prioridade*/

         while(recurso->DISCO1->ini != NULL){/*Processa fila de DISCO*/
            tempoDisco = recurso->DISCO1->ini->Ddisco;
            quantproc++;
            if(recurso->ID == idpc){
               tempoEsperaD1+=aux2;
               GravarRelatorioD(recurso->DISCO1->ini->id,escalonamento,recurso->DISCO1->ini->Dcpu,
			                     recurso->DISCO1->ini->Ddisco, recurso->DISCO1->ini->prioridade, aux2);
             }
            aux2+=tempoDisco;
            InsereFila(Rede,recurso->DISCO1->ini);/* Insere o processo na fila de rede*/
            RemoveFila(recurso->DISCO1);/* Remove o processo na fila de DISCO*/
    }/*fim do while*/
ProcTotal+=aux2;
GravarTempoProcessamento(aux2,quantproc);
GravarTempoEspera(tempoEsperaD1, quantproc);
  }

   quantproc =0;
      if(recurso->DISCO2->ini != NULL){
         GravarRelatorioDisc(recurso->ID, 2);/*Grava o cabeçalho no arquivo*/
        if(strcmp(escalonamento, "SJF") == 0 || strcmp(escalonamento, "sjf") == 0 && recurso->DISCO2->ini->seg != NULL)
           OrdenaSJF_disco(recurso->DISCO2);
        else if(strcmp(escalonamento, "PRI") == 0 || strcmp(escalonamento, "pri") == 0 && recurso->DISCO2->ini->seg != NULL)
           OrdenaSJF_pri(recurso->DISCO2);

         while(recurso->DISCO2->ini != NULL){
            tempoDisco2 = recurso->DISCO2->ini->Ddisco;
             quantproc++;
            if(recurso->ID == idpc){
            tempoEsperaD2+=aux3;
            GravarRelatorioD(recurso->DISCO2->ini->id,escalonamento,recurso->DISCO2->ini->Dcpu,
			                  recurso->DISCO2->ini->Ddisco, recurso->DISCO2->ini->prioridade, aux3);
             }
            aux3+=tempoDisco2;
            InsereFila(Rede,recurso->DISCO2->ini);
            RemoveFila(recurso->DISCO2);
             }/*fim do while*/
    ProcTotal+=aux3;
    GravarTempoProcessamento(aux3,quantproc);
    GravarTempoEspera(tempoEsperaD2, quantproc);
    }

}else printf("\n O PC %d NÃO TINHA PROCESSOS À EXECUTAR\n", recurso->ID);

}

/*Esta função recebe uma fila de lista encadeada r representando uma fila de REDE e uma
 * string esc representando um escalonamento e faz o processamento de r*/
void Processamento_rede(Fila* r, char esc[]){
int tempoEsperaR = 0, quantproc = 0, auxr = 0;
if(r->ini != NULL){/*Verifica se a fila não está vazia*/
        GravarRelatorioRede();/*Grava o cabeçalho da REDE no arquivo*/
        if(strcmp(esc, "SJF") == 0 || strcmp(esc, "sjf") == 0)
           OrdenaSJF_Rede(r);/*Ordena a fila em ordem crescente referente ao tempo de REDE*/
        else if(strcmp(esc, "PRI") == 0 || strcmp(esc, "pri") == 0)
           OrdenaSJF_pri(r);/*Ordena a fila em ordem crescente referente a prioridade*/

         while(r->ini != NULL){/*Faz o processamento da fila*/
           quantproc++;/*Conta o número de processos na respectiva fila*/
           tempoTotalRede = r->ini->Drede;
           tempoEsperaR+=auxr;
           /*Grava no aquivo os dados sobre os processos na fila*/
           GravarRelatorioR(r->ini->id,esc,r->ini->Dcpu,r->ini->Drede, r->ini->prioridade, auxr);
           auxr+=tempoTotalRede;
           RemoveFila(r);
    }
ProcTotal+=auxr;
GravarTempoProcessamento(auxr, quantproc);
GravarTempoEspera(tempoEsperaR, quantproc);
} else printf("\nA FILA DA REDE ESTÁ VAZIA!");

}
/* Esta função recebe uma string arquivo com o nome de um arquivo e devolve
 * o número de linhas de arquivo*/
int contarProcessos(char arquivo[]){
FILE *arq= fopen(arquivo, "rt");
  char caractere;
  int existe_linhas = false;
  int quant_linhas = 0;

  while((caractere = fgetc(arq)) != EOF){
    existe_linhas = true;

    if(caractere == '\n')
      quant_linhas++;

  }
  if(!existe_linhas)
    quant_linhas++;

numeroProcessos = quant_linhas;
fclose(arq);
return quant_linhas;
}

/*Esta função recebe uma string nomeArquivo com o nome de um aquivo e um valor numProcessos>=1
 * referente ao ID de uma processo e devolve uma célula de lista encadeada com os dados de uma
 * linha numProcessos no arquivo*/
Proc* criaProcessos(char nomeArquivo[], int numProcessos){
  int matrizProc[numProcessos][5];/*Matriz onde será armazenado as linhas e colunas do arquivo*/
  FILE* arq =  fopen(nomeArquivo, "rt");
  int i, j, a, b, cont = 0;
if(arq == NULL){
    printf("Erro, não foi possível abrir o arquivo! \n");
	exit(1);}
	else{ for(a = 0; a < numProcessos; a++)
             for(b = 0; b < 5; b++)
               fscanf(arq,"%d",&matrizProc[a][b]);/* Salva os dados do arquivo para a matriz*/

     Proc* criarP= (Proc*) malloc(sizeof(Proc));/* Cria uma célula do tipo Proc para armazenar uma linha da matriz*/

     for(i = 0; i < numProcessos; i++){
          for(j = 0; j < 5; j++){
            if(i == numProcessos-1){/* Armazena em criarP apenas a linha referente a numProcessos*/
            sprintf(criarP->id,"P%d",numProcessos);/*Cria uma ID para o processo*/
                 if(i == cont && j ==0)
            criarP->instante =  matrizProc[i][j];
            else if(i == cont && j ==1)
             criarP->Dcpu =  matrizProc[i][j];
            else if(i == cont && j ==2)
             criarP->Ddisco =  matrizProc[i][j];
            else if(i == cont && j ==3)
             criarP->Drede =  matrizProc[i][j];
            else if(i == cont && j ==4)
             criarP->prioridade =matrizProc[i][j];
            }
        }
        cont++;
     }
  criarP->seg =NULL;
  return criarP;/* retorna a célula com um processo*/
     }
}
/* Esta função recebe uma fila de lista encadeada fcfs sem cabeça e vazia , um valor numProc>=10
 * com o número de processos no arquivo e uma string NomArq com o nome do arquivo e devolve fcfs
 * como uma fila não vazia contendo os processos do arquivo*/
Fila* EscalonadorCOMUM(Fila* fcfs,int numProc, char NomArq[]){

int i;
Proc *aux  = (Proc*) malloc(sizeof(Proc));

for(i=1; i<=numProc;i++){/*Cria o número de células da fila*/
Proc *nP = (Proc*) malloc(sizeof(Proc));
aux = criaProcessos(NomArq, i);/* Cria os processos*/
strcpy(nP->id,aux->id);
nP->instante = aux->instante;
nP->Dcpu = aux->Dcpu;
nP->Ddisco = aux->Ddisco;
nP->Drede = aux->Drede;
nP->prioridade = aux->prioridade;
nP->seg = NULL;
if(fcfs->fim != NULL)
    fcfs->fim->seg = nP;/*aponta o fim da fila*/
else
   fcfs->ini = nP;/*aponta o inicio da fila*/

fcfs->fim = nP;/*aponta o fim da fila*/
}
printf("\nOS SEGUINTES PROCESSOS FORAM GERADOS A PARTIR DO ARQUIVO:\n");
imprimaFila(fcfs);/*Imprime a fila na ordem FIFO, ordem padrão*/
free(aux);
return fcfs;
}

/*Esta função recebe uma string nArq e grava uma matriz em um arquivo*/
void entradaProcArquivos(char nArq[]){
int proc[3][5] = {{0,10,20,3,1},{10,2,15,5,1},{12,5,50,30,2}};
gravaProcessosArquivo(3,proc, nArq);
}


int main(int argc, char *argv[]){
setlocale(LC_ALL, "Portuguese");
//entradaProcArquivos(argv[2]);
int com = atoi(argv[3]);/*numero de computadores da simulação*/
int semente = atoi(argv[4]);;

int i;
for(i = 0; i < com; i++){/*Cria a quantidade de computadores fornecidas*/
Computers[i] = (Comp*) malloc(sizeof(Comp));;
Computers[i]->ID = i+1;
Computers[i]->CPU = (Fila*) malloc(sizeof(Fila));
Computers[i]->DISCO1 = (Fila*) malloc(sizeof(Fila));
Computers[i]->DISCO2 = (Fila*) malloc(sizeof(Fila));
Computers[i]->CPU->ini = Computers[i]->CPU->fim = NULL;
Computers[i]->DISCO1->ini = Computers[i]->DISCO1->fim = NULL;
Computers[i]->DISCO2->ini = Computers[i]->DISCO2->fim = NULL;}

Fila* rede = (Fila*) malloc(sizeof(Fila));/*Cria uma fila de rede*/
rede->ini = rede->fim = NULL;

srand(semente);

Fila * NORMAL = EscalonadorCOMUM(fila_criar(),contarProcessos(argv[2]),argv[2]);/*Cria uma fila na ordem FCFS*/

time_t rawtime;/*\Argumentos para capturar a data e a hora do sistema*/
struct tm * timeinfo;
time ( &rawtime );
timeinfo = localtime ( &rawtime );

GravarRelCabecalho(asctime (timeinfo),argv[1]);/*Grava o cabeçalho principal*/
GravarlistaProcessos(NORMAL);/*Grava a fila de processos no aquivo*/

while(NORMAL->ini != NULL){/*Processa a fila principal pelo instante de chegada*/
if(relogio == NORMAL->ini->instante){
int pc = 0 + rand()%com;/*Sorteia um computador em 0 e com*/
InsereFila(Computers[pc]->CPU,NORMAL->ini);
RemoveFila(NORMAL);}
relogio++;}

int p;
for(p = 0; p < com; p++){/*Processa cada computador*/
int id = p+1;
Processamento(Computers[p],rede,argv[1], id);}

Processamento_rede(rede, argv[1]);/*Processa a Rede*/

GravarTempoDadosFinais(argv[1]);/*Grava os dados finais da simulação no aquivo*/
printf("\n\nFIM DA SIMULAÇÃO! - OS DADOS DA SIMULAÇÃO ESTÃO EM Relatorio.txt.\n");
system("Relatorio.txt");/*Abre o arquivo contendo o Relatório da simulação (Windows)*/
exit(1);
}
