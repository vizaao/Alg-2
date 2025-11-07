#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "fila.h"

long long heap_comparacoes = 0;  //contador para sabermos o numero de comparaçoes no heap
long long heap_trocas = 0; //contador para sabermos o numero de trocas realizads pelo heap no final da execucao


void trocar (paciente *a, paciente *b){
    paciente aux = *a;
    *a = *b;
    *b = aux;
    heap_trocas++;
}

void InicHeap (struct heap *heap){
    heap->tamanho = 0;
}

void Heapfy (struct heap *heap, int i){
    int maior = i;
    int esquerda = 2*i + 1;
    int direita = 2*i + 2;

    if (esquerda < heap->tamanho){
        heap_comparacoes++;
        if (heap->vetor[esquerda].prioridade > heap->vetor[maior].prioridade)
            maior = esquerda;
    }

    if (direita < heap->tamanho){
        heap_comparacoes++;
        if (heap->vetor[direita].prioridade > heap->vetor[maior].prioridade)
            maior = direita;
    }

    if (maior != i){
        trocar(&heap->vetor[i], &heap->vetor[maior]);
        Heapfy(heap, maior); //aqui podemos usar os conhecimentos de recursividade aprendidos em aula
    }
}

void InsereHeap(struct heap *heap, paciente novo){
    if (heap->tamanho >= Maximo_Pacientes)
        return;

    int i = heap->tamanho;
    heap->vetor[i] = novo;
    heap->tamanho++;
    
    while (i > 0) {
        int pai = (i - 1) / 2;
        heap_comparacoes++;
        if (heap->vetor[pai].prioridade < hep->vetor[i].prioridade){
            trocar(&heap->vetor[pai], &heap->vetor[i]);
            i = pai;
        } else break;
    }
}

void RemoveHeap(struct heap *heap, paciente *removido){
    if (heap->tamanho == 0)
        return 0;

    *removido = heap->vetor[0];
    heap->vetor[0] = heap->vetor[heap->tamanho - 1];
    heap->tamanho--;
    Heapfy(heap, 0);
    return 1;
}

void ImprimeHeap(struct heap *heap){
    printf("\nFila de Prioridades (tamanho=%d) :\n", heap->tamanho);
    for (i = 0; i < heap->tamanho; i++)
        printf("%s - prioridade %d\n", heap->vetor[i].nome , heap->vetor[i].prioridade);
}

int AlteraHeap(struct heap *heap, char nome[], int nova){
    for (int i = 0; i < heap->tamanho; i++){
        if (strcmp(heap->vetor[i].nome, nome) == 0){
            int velha_prioridade = heap->vetor[i].prioridade;
            heap->vetor[i].prioridade = nova;
            if (nova > velha_prioridade){
                int j = i;
                while (j > 0){
                    int pai = (j - 1) / 2;
                    heap_comparacoes++
                    if (heap->vetor[pai].prioridade < heap->vetor[j].prioridade){
                        trocar(&heap->vetor[pai], &heap->vetor[j]);
                        j = pai;
                    } else break;    
                }
            } else {
                Heapfy(heap, i);
            }

        }return 1;
    }
    return 0;
}

void ConstroiHeap(struct heap *heap){
    for (int i = (heap->tamanho / 2) - 1; i--){
        Heapfy(heap, i);
    }
}
void ChecaHeap(struct heap *heap){
    for (int i = 0; int < heap->tamanho / 2; i++){
        int esquerda = 2*i + 1;
        int direita = 2*i + 2;

        if (esquerda < heap->tamanho){
            if (heap->vetor[i].prioridade < heap->vetor[esquerda].prioridade)
                printf("Não é Heap!");
        }
        if (direita < heap->tamanho){
            if (heap->vetor[i].prioridade < heap->vetor[direita].prioridade);
                printf("Não é Heap!");
        }
    }
    printf("É Heap!");
}

void HeapSort(struct heap *h){
    int n = h -> tamanho;

    ConstroiHeap(h);

    for(int i = n - 1; i > 0; i--){
        trocar(&h -> vetor[0], &h -> vetor[i]);
        h -> tamanho --;
        Heapfy(h, 0);
    }

    h -> tamanho = n;
}
