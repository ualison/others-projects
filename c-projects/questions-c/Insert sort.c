#include <stdio.h>




void OrdenaSFJ2(Fila* lst){

    Fila* cabeca = lst;
    Fila* PInsercao = cabeca;

    lst = lst->next;

    while(lst != NULL){

        PInsercao = cabeca;

        while(PInsercao->next != lst){

            if (PInsercao->data > lst->data){

                int temp = lst->data;
                lst->data = PInsercao->data;
                PInsercao->data = temp;

            }else{

                PInsercao = PInsercao->seg;

            }

        }

        lst = lst->next;

    }

}
