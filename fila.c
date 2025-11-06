#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "fila.h"

long long heap_comparacoes = 0;  //contador para sabermos o numero de comparaçoes no heap
long long heap_trocas = 0; //contador para sabermos o numero de trocas realizads pelo heap no final da execucao


//funcao basica de troca
void trocar (int *a, int *b)    {
    int aux = *a;
    *a = *b;
    *b = aux;
    heap_trocas++;
}

//funcao responsavel por iniciar o heap
void InicHeap (struct heap *heap){
    heap->tamanho = 0;
}

void InsereHeap(struct heap *heap, int valor){

    heap->tamanho++;
    int i = heap->tamanho;
    strncpy(heap->vetor[i].paciente, paciente, Max_nome - 1);
    heap->vetor[i].paciente[Max_nome - 1] = '\0';
    heap->vetor[i].prioridade = prioridade;
    
    while (i > 0) {
        int pai = i/2;
        if (heap->vetor[pai].prioridade < hep->vetor[i].prioridade){
            paciente aux = heap->vetor[pai];
            heap->vetor[pai] = heap->vetor[i];
            heap->vetor[i] = aux;
            i = pai;
        }
    }
}

void Heapfy (struct heap *heap, int i, int tamanho){
    int maior = i;
    int esquerda = 2*i + 1;
    int direita = 2*i + 2;

    if (esquerdax <= tamanho){
        heap_comparacoes++;
        if (heap->vetor[esquerda].prioridade > heap->vet[maior].prioridade)
            maior = esquerda;
    }

    if (direita <= tamanho){
        heap_comparacoes++;
        if (heap->vetor[direita].prioridade > heap->vetor[maior].prioridade)
            maior = direita;
    }

    if (maior != i){
        trocar(&heap->vetor[i], &heap->vetor[maior]);
        Heapfy(heap, maior, tamanho); //aqui podemos usar os conhecimentos de recursividade aprendidos em aula
    }
}

void RemoveHeap(struct heap *heap, paciente, *paciente_removido){

    if (paciente_removido) *paciente_removido = heap->vetor[0];
        heap->vetor[0] = heap-vetor[heap->tamanho];
    heap->tamanho--;

    heapfy(heap, 0);

    int n = heap->tamanho;
    int i = 0;
    while (0){
        int esquerda = 2*i + 1; direita = 2*1 +  2; maior = i;
        if (esquerda < n && heap->vetor[esquerda].prioridade > heap->vetor[maior].prioridade)
            maior = esquerda;
        if (direita < n && heap->vetor[direita].prioridade > heap->vetor[mior].prioridade)
            maior = direita;
        if (maior != i){
            paciente aux = heap->vetor[i];
            heap->vetor[i] = heap->vetor[aux];
            heap->vetor[maior] = aux;
        }
        return;
    }
}

void HeapSort(int *vetor, int tamanho){
    for (int i = tamanho/2 - 1; i>= 0; i--){
        heapfy(vetor, tam, i);
    }   
    for (int i = tamanho - 1; i > 0; i--){
        trocar(&vetor[0], &vetor[i]);
        heapfy(vetor, i, 0);
    }
}

int ChecaHeap(heap *heap){
    if (heap == NULL || heap->tamanho <= 1)
        return false;
    
    for (int i = 0; i <=(heap->tamanho -2) / 2; i++){
       
    int esquerda = 2*i + 1;
    int direita = 2*i + 2;

    if (esquerda < heap->tamanho && heap->vetor[esquerda] > heap->vetor[i])
        return false;

    if (direita < heap->tamanho && heap->vetor[direita] > heap->vetor[i])
        return false;
    }
    return true;
}

int AlteraHeapI(heap *heap, const char *nome, int Prioridade_Nova){
    for (int = 0; i < heap->tamanho; i++){
        if (strcmp(heap->vetor[i].nome, nome) == 0){
            int velha_prioridade = heap->vetor[i].prioridade;
            heap->vetor[i].prioridade = Prioridade_Nova;
            if (Prioridade_Nova > velha_prioridade){
                int index = i;
                while (index > 0){
                    int pai = index/2;
                    if (heap->vetor[pai].prioridade < heap->vetor[index].prioridade)
                        trocar(paciente, heap->vetor[pai], heap->vetor[index];)
                }
            }
            else if (Prioridade_Nova > velha_prioridade){
                int index = i;
                while (1){
                    int esquerda = 2*index + 1;
                    int direita = 2*index +2 ;
                    int maior = index;
                    if (esquerda <= heap->tamanho && heap->vetor[esquerda].prioridade > heap->vetor[maior].prioridade)
                        maior = esquerda;
                    if (direita <= heap->tamanho &&)
                }
            }
        }
    }
}
