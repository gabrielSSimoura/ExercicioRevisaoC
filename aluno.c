#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
    char *nome;
    float nota;
};

#include "aluno.h"

Aluno *IniciaAluno(float nota, char *nome)
{
    Aluno *novoAluno = (Aluno *)malloc(sizeof(Aluno));
    novoAluno->nota = nota;
    novoAluno->nome = strdup(nome);

    return novoAluno;
}

float RetornaNotaAluno(Aluno *aluno)
{
    return aluno->nota;
}

char *RetornaNomeAluno(Aluno *aluno)
{
    return aluno->nome;
}

void ImprimeAluno(Aluno *aluno)
{
    printf("%s,%.2f\n", aluno->nome, aluno->nota);
}

void ApagaAluno(Aluno *aluno)
{
    if (aluno)
    {
        free(aluno->nome);
        free(aluno);
    }
}

int RetornaSituacaoAluno(Aluno *aluno)
{
    if (aluno->nota >= 7)
    {
        return 1;
    }
    else
        return 0;
}

int VerificaNotaEMediaAluno(Aluno *aluno, float media)
{
    if (aluno->nota > media)
    {
        return 1;
    }
    else
        return 0;
}
