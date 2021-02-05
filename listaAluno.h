#ifndef LISTAALUNO_H
#define LISTAALUNO_H

#include <stdio.h>

typedef struct celulaAluno CelulaAluno;
typedef struct listaAluno ListaAluno;
#include "aluno.h"

/*Inicializa uma Lista de Aluno;
 *inputs: (void);
 *outputs: TAD (ListaAluno*) devidamente alocado;
 *pré-condição: 
 *pós-condição: (ListaAluno*) de retorno existente;
*/
ListaAluno *IniciaListaAluno();

/*Retorna um TAD CelulaAluno da Lista de Aluno;
 *inputs: TAD (ListaAluno*) e string com nome do aluno;
 *outputs: TAD (CelulaContribuicao*)  ;
 *pré-condição TAD (ListaAluno*) existente: 
 *pós-condição: (CelulaAluno*) de retorno existente;
*/
CelulaAluno *RetornaCelulaAlunoListaAluno(ListaAluno *listaAluno, char *nome);

/*Retorna um TAD de Aluno da Lista de Aluno;
 *inputs: TAD (ListaAluno*) e string com nome do aluno ;
 *outputs: TAD (Aluno*);
 *pré-condição TAD (ListaAluno*) existente: 
 *pós-condição: (Aluno*) de retorno existente;
*/
Aluno *RetornaAlunoListaAluno(ListaAluno *listaAluno, char *nome);

/*Retira uma celula da Lista de Aluno;
 *inputs: TAD (ListaAluno*), string com o  nome do aluno;
 *outputs: (void);
 *pré-condição TAD (ListaAluno*) existente: 
 *pós-condição: Celula da Lista retirada, (ListaContribuição*) modificada;
*/
void RetiraListaAluno(ListaAluno *listaAluno, char *nome);

/*Insere Aluno uma celula da Lista de Aluno;
 *inputs: TAD (ListaAluno*), (Aluno*);
 *outputs: (void);
 *pré-condição TAD (ListaAluno*), (Aluno*) existentes: 
 *pós-condição:  Aluno adicionado na Celula da Lista de Aluno;
*/
void InsereAlunoListaAluno(ListaAluno *listaAluno, Aluno *aluno);

/*Verifica pelo nome se o Aluno existe ou não na Lista de Aluno
 *inputs: TAD (ListaAluno*), string com o nome do aluno;
 *outputs: (int);
 *pré-condição: (ListaAluno*) existente;
 *pós-condição: variável inteira existente para receber o valor do status da busca;
*/
int BuscaAlunoListaAluno(ListaAluno *listaAluno, char *nome);

/*Imprime a Lista de Aluno
 *inputs: TAD (ListaAluno*) existente, arquivo da página, arquivo de log;
 *outputs: (void);
 *pré-condição: (ListaAluno*, arquivo da página e arquivo de log existentes;
 *pós-condição: (ListaAluno*) não modificada;
*/
void ImprimeListaAluno(FILE *saida, ListaAluno *listaAluno);

/*Apaga a Lista de Aluno;
 *inputs: TAD (ListaAluno*);
 *outputs: (void);
 *pré-condição TAD (ListaAluno*) existente: 
 *pós-condição:  (ListaAluno*) apagada;
*/
void ApagaListaAluno(ListaAluno *listaAluno);

/*Calcula a Media da Lista de Alunos
 *inputs: TAD (ListaAluno*);
 *outputs: (float);
 *pré-condição TAD (ListaAluno*) existente: 
 *pós-condição:  variavel float existente;
*/
float CalculaMediaTurma(ListaAluno *listaAluno);

/*Imprime a situação final Lista de Aluno
 *inputs: TAD (ListaAluno*) existente, arquivo da página, arquivo de log;
 *outputs: (void);
 *pré-condição: (ListaAluno*, arquivo da página e arquivo de log existentes;
 *pós-condição: (ListaAluno*) não modificada;
*/
void ImprimeSituacaoFinalTurma(FILE *saidaCsv, FILE *saida, ListaAluno *listaAluno, float media);

#endif