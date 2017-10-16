/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include<stdio.h>
#include<stdlib.h>
/* 
 * File:   cabecalho.h
 * Author: Asus
 *
 * Created on 26 de Setembro de 2017, 14:09
 */



struct aluno{
    char nome[80];
    char email[80];
    char matricula[20];
    char telefone[10];
    
}list;
typedef struct aluno Aluno;
//Lista contem ponteiro para o aluno e o numero de alunos
struct lista{
    Aluno * aluno;
    int n;
    Aluno  * prox; 
};
typedef struct lista Lista;


void excluir(Lista * lista, char *mat);
Lista * iniciar();
void cadastrar();
void mostrar(Lista * lista);