#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "listaAluno.h"

void insereAluno(FILE *entrada, ListaAluno *listaAlunos);

int main(int argc, char const *argv[])
{
    char *nome;
    float media;

    if (argv[1] == 0)
    {
        printf("Digite o nome do arquivo: ");

        char nomeArquivo[100];

        scanf("%s", nomeArquivo);
        nome = strdup(nomeArquivo);
    }
    else
    {
        nome = strdup(argv[1]);
    }

    FILE *entrada;
    FILE *saida;
    FILE *saidaCsv;

    ListaAluno *listaAlunos = IniciaListaAluno();

    entrada = fopen(nome, "r");

    if (entrada == NULL)
    {
        printf("ERRO: O arquivo de entrada não foi aberto!\n");
        return 0;
    }

    saida = fopen("saida-tela.txt", "w");

    if (saida == NULL)
    {
        printf("ERRO: O arquivo de saida não foi aberto!\n");
        return 0;
    }
    saidaCsv = fopen("saida.csv", "w");

    if (saidaCsv == NULL)
    {
        printf("ERRO: O arquivo de saida.csv não foi aberto!\n");
        return 0;
    }

    int tamanho;
    fscanf(entrada, "%d", &tamanho);

    for (int i = 0; i < tamanho; i++)
    {
        insereAluno(entrada, listaAlunos);
    }

    media = CalculaMediaTurma(listaAlunos);
    ImprimeSituacaoFinalTurma(saidaCsv, saida, listaAlunos, media);

    ApagaListaAluno(listaAlunos);

    fclose(saidaCsv);
    fclose(entrada);
    fclose(saida);
    free(nome);
    return 0;
}

void insereAluno(FILE *entrada, ListaAluno *listaAlunos)
{
    float nota;
    char nomeAluno[30];

    fscanf(entrada, "%f", &nota);
    fscanf(entrada, "%s", nomeAluno);

    Aluno *novoAluno = IniciaAluno(nota, nomeAluno);
    InsereAlunoListaAluno(listaAlunos, novoAluno);
}
