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
        if (heap->vetor[pai].prioridade < heap->vetor[i].prioridade){
            trocar(&heap->vetor[pai], &heap->vetor[i]);
            i = pai;
        } else break;
    }
}

int RemoveHeap(struct heap *heap, paciente *removido){
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
    for (int i = 0; i < heap->tamanho; i++)
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
                    heap_comparacoes++;
                    if (heap->vetor[pai].prioridade < heap->vetor[j].prioridade){
                        trocar(&heap->vetor[pai], &heap->vetor[j]);
                        j = pai;
                    } else break;    
                }
            } else {
                Heapfy(heap, i);
            }
            return 1;
        }
    }
    return 0;
}

void ConstroiHeap(struct heap *heap){
    for (int i = (heap->tamanho / 2) - 1; i >= 0; i--){
        Heapfy(heap, i);
    }
}

void ChecaHeap(struct heap *heap){
    for (int i = 0; i < heap->tamanho / 2; i++){
        int esquerda = 2*i + 1;
        int direita = 2*i + 2;

        if (esquerda < heap->tamanho){
            if (heap->vetor[i].prioridade < heap->vetor[esquerda].prioridade)
                printf("Não é Heap!");
        }
        if (direita < heap->tamanho){
            if (heap->vetor[i].prioridade < heap->vetor[direita].prioridade)
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

int mediana(struct heap *h, int a, int b){
    int meio = (a + b) / 2;
    int x = h -> vetor[a].prioridade;
    int y = h -> vetor[meio].prioridade;
    int z = h -> vetor[b].prioridade;

    if ((x <= y && y <= z) || (z <= y && y <= x))
        return meio;
    else if ((y <= x && x <= z) || (z <= x && x <= y))
        return a;
    else
        return b;
}

int Particiona(struct heap *h, int a, int b, int *comparacoes, int *trocas){
    int pivo_indice = mediana(h, a, b);
    int pivo_prio = h -> vetor[pivo_indice].prioridade;  
    trocar(&h -> vetor[pivo_indice], &h -> vetor[b]);
    (*trocas)++;

    int m = a - 1;
    for (int i = a; i <= b - 1; i++) {
        (*comparacoes)++;
        if (h -> vetor[i].prioridade <= pivo_prio) {
            m++;
            trocar(&h -> vetor[m], &h -> vetor[i]);
            (*trocas)++;
        }
    }

    trocar(&h -> vetor[m + 1], &h -> vetor[b]);
    (*trocas)++;
    return m + 1;
}

void quicksort(struct heap *h, int a, int b, int *comparacoes, int *trocas){
    if (a >= b)
        return;

    int m = Particiona(h, a, b, comparacoes, trocas);
    quicksort(h, a, m - 1, comparacoes, trocas);
    quicksort(h, m + 1, b, comparacoes, trocas);
}

void selectsort(int vetor[], int n, int *comparacoes, int *trocas){
    *comparacoes = 0;
    *trocas = 0;

    for (int i = 0; i < n - 1; i++){
        int menor = i;

        for (int j = i + 1; j < n; j++){
            (*comparacoes)++;
            if (vetor[j] < vetor[menor]){
                menor = j;
            }
        }

        if (menor != i){
            int aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
            (*trocas)++;
        }
    }
}

