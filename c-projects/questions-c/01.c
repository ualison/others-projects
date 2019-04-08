#include <stdio.h>
#include <string.h>

/* A função abaixo recebe dois vetores de char(strings) str1[],  str2[]
 * e um inteiro i = 0, e devolve 1 se as strings forem iguais ou 0  se não*/
int strings_rec(char str1[], char str2[], int i){

if(str1[i] != str2[i])
    return 0;

if(str1[i] == '\0' && str2[i] == '\0')
    return 1;
printf("pá\n");
return strings_rec(str1, str2, i+1);

}



int main(){

char s1[] = "UFCee";
char s2[] = "UFC";
printf("%d", strings_rec(s1, s2,0));

}

