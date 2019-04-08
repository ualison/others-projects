#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define true 1
#define false 0
//PROGRAMA PARA GERENCIAR UMA LOJA DE GAMES - GAMESTOP VERSÃO 1.2
//SOFTWARE DESENVOLVIDO POR UÁLISON RODRIGUES


void topomenu(){
printf("  #####       ###    ##     ## ########   ######  ########  #######  ########\n" );
printf(" ##    ##    ## ##   ###   ### ##        ##    ##    ##    ##     ## ##     ##\n");
printf(" ##         ##   ##  #### #### ##        ##          ##    ##     ## ##     ##\n");
printf(" ##   #### ##     ## ## ### ## ######     ######     ##    ##     ## ########\n");
printf(" ##    ##  ######### ##     ## ##              ##    ##    ##     ## ##  \n");
printf(" ##    ##  ##     ## ##     ## ##        ##    ##    ##    ##     ## ##  \n");
printf("  ######   ##     ## ##     ## ########   ######     ##     #######  ##\n");
printf("\n                         SISTEMA DE CADASTRO DE JOGOS V1.2");

}
void barras(char nomeCategoria[71]){
printf(" \n ______________________________________________________________________________\n");
printf("\n                                  %s", nomeCategoria);
printf("\n ______________________________________________________________________________\n");
}
void menuPrincipal(){
char escolha[] = "     MENU     ";
barras(escolha);
printf("                        |      1 - LOGIN             |\n");
printf("                        |      2 - CADASTRAR LOGIN   |\n");
printf("                        |      3 - SAIR              |\n");
}

void menuLogado(char usuario[10]){
system("cls");
barras("VOCÊ ESTÁ LOGADO!");
printf("\n\n                        |USER: %s|\n\n\n",usuario);
printf("                        |      4 - CADASTRAR JOGOS       |\n");
printf("                        |      5 - EXIBIR JOGOS          |\n");
printf("                        |      6 - REMOVER JOGOS         |\n");
printf("                        |      7 - PESQUISAR JOGOS       |\n");
printf("                        |      8 - ATUALIZAR JOGOS       |\n");
printf("                        |      9 - ESTOQUE               |\n");
printf("                        |     10 - LOGOFF                |\n");
}

struct jogo {
int codigo;
float preco;
char nome[201], genero[101], plataforma[21], distribuidora[151];
};

struct login{
char login[10];
char senha[10];
};

int logou_ou_nao(int a){//FUNÇÃO QUE INDICA SE O USUÁRIO ESTÁ LOGADO OU NÃO

if(a==1)
    return 1;
else
    return 0;
}
//FUNÇÃO QUE CRIA UM NOVO LOGIN A PARTIR DE UMA STRUCT
struct login* criar_login(char log[10], char sen[10]){
struct login* p = malloc(sizeof(struct login));
strcpy(p->login, log);
strcpy(p->senha, sen);

return p;
}
//FUNÇÃO PARA CRIAR UM JOGO
struct jogo* criar_jogo(int cod, char nomeJ[201], char gen[101], char plat[21],char distr[151],float prec){
struct jogo* j = malloc(sizeof(struct jogo));
j->codigo = cod;
strcpy(j->nome, nomeJ);
strcpy(j->genero, gen);
strcpy(j->plataforma, plat);
strcpy(j->distribuidora, distr);
j->preco = prec;

return j;
}
//VERIFICA SE EXISTE UMA STRING DENTRO DO ARQUIVO
int verificar_ocorrencia_txt(char str1[], char str2[], char nomeArq[30], int tam, FILE* arq){

  arq = fopen(nomeArq, "rt");

  while(fgets(str1, tam, arq) != NULL){

    if(strstr(str1, str2)!=NULL)
         return 1;
 }
  fclose(arq);
       return 0;
  }
//VERIFICA SE EXISTE UMA STRING DENTRO DO ARQUIVO BINARIO
  int verificar_ocorrencia_bin(char str1[], char str2[], char nomeArq[30], int tam, FILE* arq){

  arq = fopen(nomeArq, "rb");
  while(!feof(arq)){
    fread(str1,sizeof(char)*10,1,arq);

    if(strstr(str1, str2)!=NULL)
         return 1;
 }
  fclose(arq);
       return 0;
  }
//CONTA O NÚMERO DE OCORRENCIAS DE UMA STRING EM UM ARQUIVO DE TEXTO
int conta_registros(char str1[], char str2[], char nomeArq[30], int tam, FILE* arq){

  arq = fopen(nomeArq, "r");
  int cont=0;

  while(fgets(str1, tam, arq) != NULL){

    if(strstr(str1, str2)!=NULL)
         cont++;
 }
  fclose(arq);
       return cont;
  }
//COPIA O CONTEÚDO DE UM ARQUIVO DE TEXTO PARA O OUTRO
void copiar_arquivo(char nomeArq1[],char nomeArq2[]){
char temp[201];
FILE* arq1 = fopen(nomeArq1, "r");
FILE* arq2 = fopen(nomeArq2, "w");
 while(fgets(temp,201,arq1)!=NULL)
    fprintf(arq2,"%s", temp);
fclose(arq1);
fclose(arq2);
 }
//VERIFICA SE UM ARQUIVO DE TEXTO ESTÁ VAZIO
  int verificar_arquivo_txt(char nomeArq[],FILE* arq){
  char nome[10];
  arq = fopen(nomeArq, "rt");
  int i;
  for(i=0;fscanf(arq,"%s", nome)!=EOF;i++);
  if(i==0)
    return 1;
  else
   return 0;
  }

//FAZER LOGIN CASO JÁ EXISTA UM USUÁRIO
void fazer_login(){
system("cls");
topomenu();
barras("     LOGIN     ");
struct login ls;
FILE* log = fopen("login.txt", "r");
if(log == NULL)
        printf("                         ERRO AO ABRIR O ARQUIVO!");
        else{
    char aux[10];
    int logRes, logSen;
    printf("\n                              DIGITE O LOGIN: ");
    scanf("%s", ls.login);
    logRes = verificar_ocorrencia_txt(aux,ls.login,"login.txt",10,log);
    if(logRes == false){
        printf("\n\n                               USUÁRIO NÃO EXISTE!\n\n");
        system("pause");
        fclose(log);
        main(false,"");
        }else{
    printf("\n                              DIGITE A SENHA: ");
    scanf("%s", ls.senha);
    logSen = verificar_ocorrencia_bin(aux,ls.senha,"senha.bin",10,log);
    if(logSen == false){
        printf("\n\n                                SENHA NÃO EXISTE!\n\n");
        system("pause");
        fclose(log);
        main(false,"");
        }
        else{
            printf("\n \n                                  BEM-VINDO! %s\n\n", ls.login);
            system("pause");
            fclose(log);
            main(true, ls.login);
        }
    }
 }
}

int main(int estaLogado, char userAtv[10]){//FUNÇÃO MAIN
  setlocale(LC_ALL, "Portuguese");
  system("cls");
  topomenu();

if(strlen(userAtv)<4)
estaLogado = 0;
else
  estaLogado = 1;

if(logou_ou_nao(estaLogado) == true){//ESTÁ LOGADO
system("cls");
menuLogado(userAtv);
char tempUser[10];
strcpy(tempUser, userAtv);//BACKUP USUÁRIO
//ABERTURA DOS ARQUIVOS
FILE* listaGames = fopen("listaJogos.txt","at");
FILE* listaGamesR = fopen("listaJogos.txt","rt");
if(listaGames == NULL || listaGamesR == NULL){//TESTE PARA SABER SE O ARQUIVO ABRIU
    printf("ERRO AO ABRIR O ARQUIVO! ");
    exit(1);}
    else{//SE NÃO OCORRER ERRO

//VARIÁVEIS AUXILIARES
char aux2[201], aux3[201], jogoRemove[201],aux4[201],aux5[201],aux6[201],jogoAlterar[101];
struct jogo j;
int contador=0;
int option=0;
do{
printf("\n                                  DIGITE A OPÇÃO: ");
scanf("%d", &option);
} while(option <4);
switch(option){

case 4:
system("cls");
FILE* listaG = fopen("listaJogos.txt","at");
    barras("   CADASTRO DE JOGO   ");
    printf("\n                       DIGITE O CÓDIGO: ");
    scanf("%d", &j.codigo);
    printf("\n                       NOME DO JOGO: ");
    scanf("%s", j.nome);
    printf("\n                       GÊNERO: ");
    scanf("%s", j.genero);
    printf("\n                       PLATAFORMA: ");
    scanf("%s", j.plataforma);
    printf("\n                       DISTRIBUIDORA: ");
    scanf("%s", j.distribuidora);
    printf("\n                       DIGITE O PREÇO: ");
    scanf("%f", &j.preco);

   //  struct jogo* result2 = criar_jogo(j.codigo,j.nome,j.genero,j.plataforma,j.distribuidora,j.preco);
    fprintf(listaG,"%d %s %s %s %s R$-%.2f \n",j.codigo,j.nome,j.genero,j.plataforma,j.distribuidora,j.preco);
        if(ferror(listaG))
            printf("ERRO NA GRAVAÇÃO DOS DADOS");
        else
        printf("                CADASTRO REALIZADO COM SUCESSO!\n\n");
        fclose(listaG);
        system("pause");
        option = 0;
        main(true,tempUser);
        break;

 case 5:
    system("cls");
    barras("   EXIBIR JOGOS CADASTRADOS   ");
    printf("\n      | CÓD | NOME DO JOGO | GÊNERO | PLATAFORMA | DISTRIBUIDORA | PREÇO |\n");
    while(fgets(aux2, 201, listaGamesR) != NULL)
    printf("\n                   %s\n", aux2);
    system("pause");
    main(true, tempUser);
   break;

   case 6:
    system("cls");
    barras("   EXCLUIR UM REGISTRO   ");
    printf("\n\n                    DIGITE O NOME DO JOGO A SER EXCLUÍDO: ");
    scanf("%s", jogoRemove);
    FILE* backup = fopen("backup.txt", "w");
     while(fgets(aux2, 201, listaGamesR) != NULL){
        if(strstr(aux2, jogoRemove)!=NULL){
        printf("\n                        O SEGUINTE REGISTRO SERÁ EXCLUÍDO:\n\n                    %s\n\n", aux2);
        }else
        fprintf(backup,"%s",aux2);
     }
     fclose(backup);
     copiar_arquivo("backup.txt","listaJogos.txt");
     printf("\n                       O REGISTRO FOI EXCLUÍDO COM SUCESSO!\n\n");
     system("pause");
     main(true, tempUser);
     break;
 case 7:
    system("cls");
    barras("  PESQUISAR   ");
    printf("\n\n                     DIGITE UMA PALAVRA-CHAVE PARA A PESQUISA: ");
    scanf("%s", jogoRemove);
     while(fgets(aux2, 201, listaGamesR) != NULL){
        if(strstr(aux2, jogoRemove)!=NULL)
        printf("\n\n                      %s\n", aux2);
     }
     system("pause");
     main(true, tempUser);
     break;

    case 8:
    system("cls");
    barras("  ATUALIZAR CADASTRO  ");
    printf("\n\n                    DIGITE O NOME DO JOGO A SER ALTERADO: ");
    scanf("%s", jogoAlterar);

    FILE* backupA = fopen("backupAlt.txt", "w");
    FILE* listaGamesR = fopen("listaJogos.txt", "r");
    printf("\n\n                      O SEGUINTE REGISTRO SERÁ ALTERADO: ");

     while(fgets(aux4, 201, listaGamesR) != NULL){//INDICA QUAL REGISTRO SERÁ ALTERADO
        if(strstr(aux4, jogoAlterar)!=NULL)
        printf("                                             %s\n\n",aux4);
     }
    //fclose(listaGamesR);
    printf("\n                       DIGITE O CÓDIGO: ");
    scanf("%d", &j.codigo);
    printf("\n                       NOME DO JOGO: ");
    scanf("%s", j.nome);
    printf("\n                       GÊNERO: ");
    scanf("%s", j.genero);
    printf("\n                       PLATAFORMA: ");
    scanf("%s", j.plataforma);
    printf("\n                       DISTRIBUIDORA: ");
    scanf("%s", j.distribuidora);
    printf("\n                       DIGITE O PREÇO: ");
    scanf("%f", &j.preco);

    fprintf(backupA,"%d %s %s %s %s R$-%.2f \n",j.codigo,j.nome,j.genero,j.plataforma,j.distribuidora,j.preco);
    fclose(backupA);

    FILE* backupAR = fopen("backupAlt.txt", "r");//ARQUIVO PARA ARMAZENAR A LINHA MODIFICADA
    FILE* backup2 = fopen("backup.txt", "w");//ARQUIVO BACKUP COM TODAS AS LINHAS MAIS A MODIFICADA
    FILE* listaGamesR2 = fopen("listaJogos.txt","r");//ARQUIVO PARA LEITURA DA LISTA ORIGINAL

//ARMAZENA A LINHA QUE DESEJA SOBRESCREVER
    while(fgets(aux5, 201, backupAR) != NULL){
            fscanf(backupAR,"%s",aux5);
            }

//ARMAZENA NO BACKUP OS JOGOS COM A LINHA MODIFICADA
     while(fgets(aux6, 201, listaGamesR2) != NULL){
        if(strstr(aux6, jogoAlterar)!=NULL){
        fprintf(backup2,"%s",aux5);
        }else
        fprintf(backup2,"%s",aux6);
     }
     fclose(backupAR);
     fclose(listaGamesR2);
     fclose(backup2);
     copiar_arquivo("backup.txt","listaJogos.txt");
     printf("\n\n                        REGISTRO ATUALIZADO COM SUCESSO!\n\n");
     system("pause");
     main(true, tempUser);
     break;

   case 9:
        system("cls");
        barras("  ESTOQUE   ");FILE* listaGR = fopen("listaJogos.txt", "r");
        while(fgets(aux2, 201, listaGR) != NULL)
                contador++;

         printf("\n \n                     TOTAL DISPONÍVEL NO ESTOQUE É: %d JOGO(S)\n\n", contador);
         printf("                               PC =  %d JOGO(S)\n", conta_registros(aux3,"PC","listaJogos.txt",201,listaGR));
         printf("                              PS3 =  %d JOGO(S)\n", conta_registros(aux3,"PS3","listaJogos.txt",201,listaGR));
         printf("                              PS4 =  %d JOGO(S)\n", conta_registros(aux3,"PS4","listaJogos.txt",201,listaGR));
         printf("                          XBOX360 =  %d JOGO(S)\n", conta_registros(aux3,"XBOX360","listaJogos.txt",201,listaGR));
         printf("                          XBOXONE =  %d JOGO(S)\n", conta_registros(aux3,"XBOXONE","listaJogos.txt",201,listaGR));
         printf("                              WII =  %d JOGO(OS)\n", conta_registros(aux3,"Wii","listaJogos.txt",201,listaGR));
         printf("                              PS2 =  %d JOGO(OS)\n", conta_registros(aux3,"PS2","listaJogos.txt",201,listaGR));
       fclose(listaGR);
       system("pause");
       main(true, tempUser);
       break;

     case 10:
       system("cls");
       barras("  LOGOFF   ");
       printf("\n\n                              O usuário %s saiu!\n\n", tempUser);
       system("pause");
       main(false,"");
       break;
}
fclose(listaGamesR);
fclose(listaGames);
    }

}
else{//NÃO ESTA LOGADO______________________________________________________________________NÃO ESTA LOGADO__________________________
menuPrincipal();
int escolha;
do{
printf("\n                         DIGITE A OPÇÃO DESEJADA: ");
  scanf("%d", &escolha);
}while(escolha > 3);
  switch(escolha){

   case 1:
     system("cls");
     topomenu();
     barras("    LOGIN     ");
     FILE* log = fopen("login.txt", "rt");
     if(log == NULL)
        printf("                         ERRO AO ABRIR O ARQUIVO!");
     else{//SE NÃO DER ERRO AO ABRIR O ARQUIVO
     if(verificar_arquivo_txt("login.txt",log) == true){//VERIFICA SE O ARQUIVO ESTÁ VAZIO
         printf("\n                              NÃO EXISTE CADASTRO!\n \n");
         system("pause");
         main(false," ");
                   }
    else{
    fazer_login(); //FAZER LOGIN
    main(false," ");

         }}

    case 2://CADASTRAR LOGIN
    system("cls");
    topomenu();
    barras("CADASTRAR LOGIN");
         struct login res;
         FILE* arqLog = fopen("login.txt", "at");
         FILE* arqSen = fopen("senha.bin","ab");
         printf("\n                        DIGITE O NOVO USUÁRIO(MÁX. 9 CARAC.): ");
         scanf("%s", res.login);
         printf("\n                        DIGITE A SENHA:(MÁX. 9 CARAC.): ");
         scanf("%s", res.senha);
    if(strlen(res.login)>10 || strlen(res.senha)>10){//VERIFICA SE O USUÁRIO DIGITOU A QUANTIDADE PERMITIDA DE DIGITOS
    printf("\n\n               EXCEDIDO O NÚMERO MÁXIMO DE CARACTERES - TENTE DE NOVO! \n\n");
    system("pause");
    fclose(arqLog);
    fclose(arqSen);
    main(false," ");

 }
 else{//SE TIVER DIGITADO OS CARACTERES CORRETAMENTE
         struct login* result = criar_login(res.login, res.senha);
         fprintf(arqLog,"%s\n",result->login);
         fwrite(result->senha,sizeof(struct login),1,arqSen);
         printf("\n\n                            CADASTRO REALIZADO COM SUCESSO!\n\n");
         system("pause");
         fclose(arqLog);
         fclose(arqSen);
         main(false," ");
     break;

     case 3://SAIR DO PROGRAMA
         system("cls");
         barras("VOCÊ SAIU DO SISTEMA!");
         printf("\n\n                                        ATÉ BREVE!\n\n");
         exit(1);
         break;
  }//FECHA O SWITCH
  }
}
}


