#ifndef ALUNO_H_
#define ALUNO_H_

#include <stdio.h>

typedef struct aluno Aluno;

Aluno *IniciaAluno(float nota, char *nome);

char *RetornaNomeAluno(Aluno *aluno);

float RetornaNotaAluno(Aluno *aluno);

void ImprimeAluno(Aluno *aluno);

void ApagaAluno(Aluno *aluno);

int RetornaSituacaoAluno(Aluno *aluno);

int VerificaNotaEMediaAluno(Aluno *aluno, float media);
#endif /*ALUNO_H_*/