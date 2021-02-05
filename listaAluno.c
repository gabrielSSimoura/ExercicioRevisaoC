#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaAluno.h"

struct celulaAluno
{
    Aluno *aluno;
    CelulaAluno *proxima;
};

struct listaAluno
{
    CelulaAluno *Prim;
    CelulaAluno *Ult;
};

/*Inicializa uma Lista de Aluno;
 *inputs: (void);
 *outputs: TAD (ListaAluno*) devidamente alocado;
 *pré-condição: 
 *pós-condição: (ListaAluno*) de retorno existente;
*/
ListaAluno *IniciaListaAluno()
{
    ListaAluno *listaAluno = (ListaAluno *)malloc(sizeof(ListaAluno));
    listaAluno->Prim = NULL;
    listaAluno->Ult = NULL;

    return listaAluno;
}

/*Retorna um TAD CelulaAluno da Lista de Aluno;
 *inputs: TAD (ListaAluno*) e string com nome do aluno;
 *outputs: TAD (CelulaContribuicao*)  ;
 *pré-condição TAD (ListaAluno*) existente: 
 *pós-condição: (CelulaAluno*) de retorno existente;
*/
CelulaAluno *RetornaCelulaAlunoListaAluno(ListaAluno *listaAluno, char *nome)
{
    CelulaAluno *celulaAtual;

    //faz a busca
    for (celulaAtual = listaAluno->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        if (strcmp(RetornaNomeAluno(celulaAtual->aluno), nome) == 0)
        {
            return celulaAtual; //Existe Aluno;
        }
    }
    return NULL; //Não Existe Aluno com esse nome;
}

/*Retorna um TAD de Aluno da Lista de Aluno;
 *inputs: TAD (ListaAluno*) e string com nome do aluno ;
 *outputs: TAD (Aluno*);
 *pré-condição TAD (ListaAluno*) existente: 
 *pós-condição: (Aluno*) de retorno existente;
*/
Aluno *RetornaAlunoListaAluno(ListaAluno *listaAluno, char *nome)
{
    CelulaAluno *celulaAtual = RetornaCelulaAlunoListaAluno(listaAluno, nome);

    if (celulaAtual)
    {
        return celulaAtual->aluno;
    }
    else
    {
        return NULL;
    }
}

/*Insere Aluno uma celula da Lista de Aluno;
 *inputs: TAD (ListaAluno*), (Aluno*);
 *outputs: (void);
 *pré-condição TAD (ListaAluno*), (Aluno*) existentes: 
 *pós-condição:  Aluno adicionado na Celula da Lista de Aluno;
*/
void InsereAlunoListaAluno(ListaAluno *listaAluno, Aluno *aluno)
{
    CelulaAluno *novoAluno = (CelulaAluno *)malloc(sizeof(CelulaAluno));
    novoAluno->aluno = aluno;

    if (listaAluno->Prim == NULL)
    {
        listaAluno->Prim = novoAluno;
        listaAluno->Ult = novoAluno;
    }
    listaAluno->Ult->proxima = novoAluno;
    listaAluno->Ult = novoAluno;
    novoAluno->proxima = NULL;
}

/*Retira uma celula da Lista de Aluno;
 *inputs: TAD (ListaAluno*), string com o  nome do aluno;
 *outputs: (void);
 *pré-condição TAD (ListaAluno*) existente: 
 *pós-condição: Celula da Lista retirada, (ListaContribuição*) modificada;
*/
void RetiraListaAluno(ListaAluno *listaAluno, char *nome)
{
    CelulaAluno *celulaAtual;
    CelulaAluno *celulaAnterior = NULL;

    //faz a busca

    for (celulaAtual = listaAluno->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        if (strcmp(RetornaNomeAluno(celulaAtual->aluno), nome) == 0)
        {
            break;
        }

        celulaAnterior = celulaAtual;
    }

    if (celulaAtual == NULL)
    {
        return;
    }

    // Caso for o único elemento da lista;
    if (celulaAtual == listaAluno->Prim && celulaAtual == listaAluno->Ult)
    {
        listaAluno->Prim = listaAluno->Ult = NULL;
    }

    else if (celulaAtual == listaAluno->Prim)
    {
        listaAluno->Prim = celulaAtual->proxima;
    }

    else if (celulaAtual == listaAluno->Ult)
    {
        listaAluno->Ult = celulaAnterior;
        listaAluno->Ult->proxima = NULL;
    }
    else
    {
        celulaAnterior->proxima = celulaAtual->proxima;
    }

    free(celulaAtual);
}

/*Imprime a Lista de Aluno
 *inputs: TAD (ListaAluno*) existente, arquivo da página, arquivo de log;
 *outputs: (void);
 *pré-condição: (ListaAluno*, arquivo da página e arquivo de log existentes;
 *pós-condição: (ListaAluno*) não modificada;
*/
void ImprimeListaAluno(FILE *saida, ListaAluno *listaAluno)
{
    CelulaAluno *celulaAtual;

    for (celulaAtual = listaAluno->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        ImprimeAluno(celulaAtual->aluno);
    };
}

/*Verifica pelo nome se o Aluno existe ou não na Lista de Aluno
 *inputs: TAD (ListaAluno*), string com o nome do aluno;
 *outputs: (int);
 *pré-condição: (ListaAluno*) existente;
 *pós-condição: variável inteira existente para receber o valor do status da busca;
*/
int BuscaAlunoListaAluno(ListaAluno *listaAluno, char *nome)
{
    CelulaAluno *celulaAtual;

    //faz a busca
    for (celulaAtual = listaAluno->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        if (strcmp(RetornaNomeAluno(celulaAtual->aluno), nome) == 0)
        {
            return 1; //Existe Aluno;
        }
    }
    return 0; //Não Existe Aluno;
}

/*Apaga a Lista de Aluno;
 *inputs: TAD (ListaAluno*);
 *outputs: (void);
 *pré-condição TAD (ListaAluno*) existente: 
 *pós-condição:  (ListaAluno*) apagada;
*/
void ApagaListaAluno(ListaAluno *listaAluno)
{

    CelulaAluno *celulaAtual = listaAluno->Prim;
    CelulaAluno *celulaSeguinte;

    while (celulaAtual != NULL)
    {
        celulaSeguinte = celulaAtual->proxima;
        if (celulaAtual)
        {

            if (celulaAtual->aluno)
            {
                ApagaAluno(celulaAtual->aluno);
            }
            free(celulaAtual);
        }

        celulaAtual = celulaSeguinte;
    }

    free(listaAluno);
}

/*Calcula a Media da Lista de Alunos
 *inputs: TAD (ListaAluno*);
 *outputs: (float);
 *pré-condição TAD (ListaAluno*) existente: 
 *pós-condição:  variavel float existente;
*/
float CalculaMediaTurma(ListaAluno *listaAluno)
{
    float media = 0.0;
    int tamanhoTurma;

    CelulaAluno *celulaAtual = listaAluno->Prim;

    for (tamanhoTurma = 0, celulaAtual = listaAluno->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima, tamanhoTurma++)
    {
        media += RetornaNotaAluno(celulaAtual->aluno);
    }

    if (tamanhoTurma == 0)
    {
        media = 0;
    }

    else
    {
        media = media / tamanhoTurma;
    }

    return media;
}

/*Imprime a situação final Lista de Aluno
 *inputs: TAD (ListaAluno*) existente, arquivo da página, arquivo de log;
 *outputs: (void);
 *pré-condição: (ListaAluno*, arquivo da página e arquivo de log existentes;
 *pós-condição: (ListaAluno*) não modificada;
*/
void ImprimeSituacaoFinalTurma(FILE *saidaCsv, FILE *saida, ListaAluno *listaAluno, float media)
{
    int situacao; //(1) = aprovado; (0) = PF

    CelulaAluno *celulaAtual;

    fprintf(saidaCsv, "Nome,Nota,Situação\n");

    for (celulaAtual = listaAluno->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        fprintf(saidaCsv, "%s,%.2f", RetornaNomeAluno(celulaAtual->aluno), RetornaNotaAluno(celulaAtual->aluno));
        situacao = RetornaSituacaoAluno(celulaAtual->aluno);

        if (VerificaNotaEMediaAluno(celulaAtual->aluno, media))
        {
            fprintf(saida, "%s\n", RetornaNomeAluno(celulaAtual->aluno));
        }
        if (situacao)
        {
            fprintf(saidaCsv, ",Aprovado\n");
        }
        else
            fprintf(saidaCsv, ",Prova Final\n");
    };
}
