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
    int opcao = 0;
    Lista * lista;
    char mat[20];
    
    
    printf("Portinho e MiniMarina Productions EC e nois 2017.\n");
    do {
        //Atualiza a lista sempre que entra no loop.
        lista = iniciar();
        printf("\nDigite a opcao desejada de acordo com o menu\n 1-Cadastrar Aluno \n 2-Excluir Aluno \n 3-Mostrar Alunos \n 4-Sair\nOpcao:");
        scanf("%i", &opcao);
        setbuf(stdin, NULL);
        switch (opcao) {
            case 1:
            {
                cadastrar();
                printf("Aluno cadastrado com sucesso!!!\n\n");
                break;
            }
            case 2:
            {
                //Lê a mtricula do aluno que será exlcuido
                printf("Digite a matricula de quem voce deseja excluir:  \n");
                fgets(mat, sizeof(mat), stdin);
                setbuf(stdin, NULL);
                excluir(lista,mat);
                printf("Sucesso");
                break;
            }
            case 3:
            {
                mostrar(lista);
                break;
            }
            case 4:
            {
                printf("\nSaindo...\n");
                break;
            }
            default:
            {
                printf("\nOpcao invalida.");
            }

        }
        free(lista);
    } while (opcao != 4);

    return (EXIT_SUCCESS);
}

