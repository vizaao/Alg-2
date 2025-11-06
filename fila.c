#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "fila.h"

long long heap_comparacoes = 0;  //contador para sabermos o numero de comparaçoes no heap
long long heap_trocas = 0; //contador para sabermos o numero de trocas realizads pelo heap no final da execucao


//funcao para trocar dois pacientes, incrementa o numero de trocas realizas no final
// CORRIGIDO: 'paciente' alterado para 'struct paciente'
void trocar (struct paciente *a, struct paciente *b){
    struct paciente aux = *a; // CORRIGIDO: tipo da var 'aux'
    *a = *b;
    *b = aux;
    heap_trocas++;
}

//funcao responsavel por iniciar o heap
void InicHeap (struct heap *h){ // 'struct heap' já estava correto no original
    h->tamanho = 0;
}

void Heapfy (struct heap *h, int i){
    int maior = i;
    int esquerda = 2*i + 1;
    int direita = 2*i + 2;

    if (esquerda < h->tamanho){
        heap_comparacoes++;
        if (h->vetor[esquerda].prioridade > h->vetor[maior].prioridade)
            maior = esquerda;
    }

    if (direita < h->tamanho){
        heap_comparacoes++;
        if (h->vetor[direita].prioridade > h->vetor[maior].prioridade)
            maior = direita;
    }

    if (maior != i){
        trocar(&h->vetor[i], &h->vetor[maior]);
        Heapfy(h, maior); //aqui podemos usar os conhecimentos de recursividade aprendidos em aula
    }
}

//essa funcao tem como objetivo adicionar pacientes novos na heap, até um certo limite
// CORRIGIDO: 'paciente' alterado para 'struct paciente'
void InsereHeap(struct heap *h, struct paciente novo){
    if (h->tamanho >= Maximo_Pacientes)
        return;

    int i = h->tamanho;
    h->vetor[i] = novo;
    h->tamanho++;
    
    while (i > 0) {
        int pai = (i - 1) / 2;
        heap_comparacoes++;
        if (h->vetor[pai].prioridade < h->vetor[i].prioridade){
            trocar(&h->vetor[pai], &h->vetor[i]);
            i = pai;
        } else break;
    }
}

//quando o paciente é atendido, ele é removido da fila de priordade
// CORRIGIDO: 'void' -> 'int' e 'paciente' -> 'struct paciente'
int RemoveHeap(struct heap *h, struct paciente *removido){
    if (h->tamanho == 0)
        return 0;

    *removido = h->vetor[0];
    h->vetor[0] = h->vetor[h->tamanho - 1];
    h->tamanho--;
    Heapfy(h, 0);
    return 1;
}

//imprime o conteudo da heap
void ImprimeHeap(struct heap *h){
    printf("\n Paciente: (tamanho=%d) :\n", h->tamanho);
    // CORRIGIDO: 'i' declarado; 'vetor[i].nome' -> 'vetor[i].paciente'
    for (int i = 0; i < h->tamanho; i++)
        printf("%s - prioridade %d\n", h->vetor[i].paciente , h->vetor[i].prioridade);
}


// CORRIGIDO: Assinatura original 'heap *heap' alterada para 'struct heap *h' para consistência
int ChecaHeap(struct heap *h){
    if (h == NULL || h->tamanho <= 1)
        return true;
    
    for (int i = 0; i <=(h->tamanho -2) / 2; i++){
       
    int esquerda = 2*i + 1;
    int direita = 2*i + 2;

    // CORRIGIDO: Comparando '.prioridade'
    if (esquerda < h->tamanho && h->vetor[esquerda].prioridade > h->vetor[i].prioridade)
        return false;

    // CORRIGIDO: Comparando '.prioridade'
    if (direita < h->tamanho && h->vetor[direita].prioridade > h->vetor[i].prioridade)
        return false;
    }
    return true;
}

int AlteraHeap(struct heap *h, char nome[], int nova){
    for (int i = 0; i < h->tamanho; i++){
        // CORRIGIDO: 'vetor[i].nome' -> 'vetor[i].paciente'
        if (strcmp(h->vetor[i].paciente, nome) == 0){
            int velha_prioridade = h->vetor[i].prioridade;
            h->vetor[i].prioridade = nova;
            if (nova > velha_prioridade){
                int j = i;
                while (j > 0){
                    int pai = (j - 1) / 2;
                    heap_comparacoes++;
                    if (h->vetor[pai].prioridade < h->vetor[j].prioridade){
                        trocar(&h->vetor[pai], &h->vetor[j]);
                        j = pai;
                    } else break;    
                }
            } else {
                Heapfy(h, i);
            }
            return 1; // CORRIGIDO: 'return 1' movido para dentro
        }
    }
    return 0;
}

void ConstroiHeap(struct heap *h){
    for (int i = (h->tamanho / 2) - 1; i >= 0; i--){
        Heapfy(h, i);
    }
}

void HeapSort(struct heap *h){
    int n = h -> tamanho;

    ConstroiHeap(h);

    // CORRIGIDO: Lógica do loop for
    for(int i = n - 1; i > 0; i--){
        trocar(&h -> vetor[0], &h -> vetor[i]);
        h -> tamanho --;
        Heapfy(h, 0);
    }

    h -> tamanho = n;
}

