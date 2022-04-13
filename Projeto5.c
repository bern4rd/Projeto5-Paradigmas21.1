#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "util.h"

//********************************************************************//
//  UFRPE - DC - Paradigmas de programação 21.1 (2022)                //
//  Projeto 5                                                         //
//  Felipe Bernard / Pedro Camara                                     //
//********************************************************************//

void menu();

int main(){
    
    limparTela();
    printf("\n\nVersionamento de programas em C (Usando #ifdef)\n\n");
    usleep(2000*1000); //2segundos
    menu();

    return 0;
}
