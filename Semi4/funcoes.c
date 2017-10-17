/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcoes.c
 * Author: Asus
 *
 * Created on 12 de Outubro de 2017, 14:13
 */

#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"
#include <string.h>

Lista * iniciar() {
    //Atualiza a lista de acordo com o arquivo
    Lista * lista = NULL;
    FILE *file;
    char texto [250];
    int cont = 0, x = 0;
    int tamanho = 0;
    int i;
    if ((file = fopen("entrada.txt", "rt")) == NULL) {
        printf("\nArquivo novo criao.");

    }

    while ((fscanf(file, "%[^\n]\n", texto) != EOF)) {
        tamanho++;
    }
    fclose(file);
    //Lê o número de linhas e dividi por 4 para dar o número de alunos.
 
    if ((file = fopen("entrada.txt", "rt")) == NULL) {
    }
    
    //Lê cada linha e atribui o campo lido de acordo com a sua posição no arquivo.
    while ((fscanf(file, "%[^\n]\n", texto) != EOF)) {
        Aluno *a = (Aluno *) malloc((tamanho / 4) * sizeof (Aluno));
        setbuf(stdin, NULL);
        if (cont == 0) {
            strcpy(a->nome, texto);
        }
        if (cont == 1) {
            strcpy(a->email, texto);
        }
        if (cont == 2) {
            strcpy(a->matricula, texto);
        }
        if (cont == 3) {
            strcpy(a->telefone, texto);
            cont = 0;
            Lista * novo = (Lista*) malloc(sizeof (Lista));
            novo->aluno = a;
            novo->n = tamanho / 4;
            novo->prox = lista;
            x++;
            cont--;
        }
        
        cont++;
    }
    //Reseta o ponteiro do aluno.
    while (lista != NULL) {
        Lista *t = lista->prox;
        printf("\n %s", lista->aluno->matricula);
        free(lista);
       lista = t;
    }
    
    fclose(file);

    return lista;
}


void cadastrar() {
    FILE *file;
    char nome[80];
    char email[80];
    char matricula[20];
    char telefone[10];
    //Lê os dados para cadastrar no arquivo
    setbuf(stdin, NULL);
    printf("Digite o nome do aluno a ser cadastrado: ");
    fgets(nome, sizeof (nome), stdin);
    setbuf(stdin, NULL);

    printf("Digite o email do aluno: ");
    fgets(email, sizeof (email), stdin);
    setbuf(stdin, NULL);

    printf("Digite a matricula do aluno: ");
    fgets(matricula, sizeof (matricula), stdin);
    setbuf(stdin, NULL);

    printf("Digite o telefone do aluno: ");
    fgets(telefone, sizeof (telefone), stdin);
    setbuf(stdin, NULL);
    
    //Abre o arquivo em modo append para não sob-escrever os dados já escritos.
    if ((file = fopen("entrada.txt", "a")) == NULL) {
        printf("Acesso negado.");

    }
    //Escreve os dados no arquivo.
    fputs(nome, file);
    
    fputs(email, file);
    
    fputs(matricula, file);
    
    fputs(telefone, file);
  


    fclose(file);
}

void mostrar(Lista * lista) {
    if(lista!=NULL){
        printf("\nNome: %s", lista->aluno->nome);
        printf("\nE-mail: %s", lista->aluno->email);
        printf("\nMatricula: %s", lista->aluno->matricula);
        printf("\nTelefone: %s\n", lista->aluno->telefone);
        mostrar(lista->prox);
    }
}

void excluir(Lista * lista, char * mat) {
    FILE *file;
    Lista *p = lista;
    int cont = 0;
    int opcao = 0;
    //Cria um novo arquivo chamado novo.txt em modo de escrita.
    if ((file = fopen("novo.txt", "w")) == NULL) {
        printf("Acesso negado.");

    }
    //Faz um loop de acordo com o número de alunos na lista
    for (cont = 0; cont < p->n; cont++) {

        //Compara a matricula na lista com a informada
        //strtok foi usado para tirar o \n no final inserido pelo fgets
        opcao = strcmp(p->aluno->matricula, strtok(mat, "\n"));


        if (opcao != 0) {
            //Escreve os dados no arquivo novo
            fputs(p->aluno->nome, file);
            fputs("\n", file);
            setbuf(stdin, NULL);
            fputs(p->aluno->email, file);
            fputs("\n", file);
            setbuf(stdin, NULL);
            fputs(p->aluno->matricula, file);
            fputs("\n", file);
            setbuf(stdin, NULL);
            fputs(p->aluno->telefone, file);
            fputs("\n", file);
            setbuf(stdin, NULL);
        }
        p=p->prox;

    }
    fclose(file);


    //Deleta o arquivo antigo
    if (remove("entrada.txt") != 0) {
        printf("Erro");
    }



    //Renomeia o arquivo novo para o mesmo nome do antigo
    if (rename("novo.txt", "entrada.txt") != 0) {
        printf("Erro");
    }


}