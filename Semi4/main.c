/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Asus
 *
 * Created on 26 de Setembro de 2017, 14:04
 */

#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int opcao =0;


    printf("Portinho e MiniMarina Productions EC e nois 2017.\n");
    do {
        printf("\nDigite a opcao desejada de acordo com o menu\n 1-Criar lista\n 2-Inserir aluno na lista\n 3-Excluir aluno da lista\n 4-Imprimir a lista\n 5-Imprimir nos na lista\n 6-buscar aluno na lista\n 7-Liberar lista \n 8-Sair\nOpcao:");
        scanf("%i", &opcao);

        switch (opcao) {
            case 1:
            {
              
                break;
            }
            case 2:
            {

           
                break;
            }
            case 3:
            {
              
                break;
            }
            case 4:
            {
                
                break;
            }
            case 5:
            {
               
                break;
            }
            case 6:
            {
               
                break;
            }
            case 7:
            {
                
                break;
            }

        }
    } while (opcao != 8);
    printf("\nSaindo...\n");
    return (EXIT_SUCCESS);
}

