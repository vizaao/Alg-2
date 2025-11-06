#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "fila.h"

long long heap_comparacoes = 0;  //contador para sabermos o numero de comparaçoes no heap
long long heap_trocas = 0; //contador para sabermos o numero de trocas realizads pelo heap no final da execucao


//funcao para trocar dois pacientes, incrementa o numero de trocas realizas no final
void trocar (paciente *a, paciente *b){
    paciente aux = *a;
    *a = *b;
    *b = aux;
    heap_trocas++;
}

//funcao responsavel por iniciar o heap
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

//essa funcao tem como objetivo adicionar pacientes novos na heap, até um certo limite
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

//quando o paciente é atendido, ele é removido da fila de priordade
void RemoveHeap(struct heap *heap, paciente *removido){
    if (heap->tamanho == 0)
        return 0;

    *removido = heap->vetor[0];
    heap->vetor[0] = heap->vetor[heap->tamanho - 1];
    heap->tamanho--;
    Heapfy(heap, 0);
    return 1;
}

//imprime o conteudo da heap
void ImprimeHeap(struct heap *heap){
    printf("\n Paciente: (tamanho=%d) :\n", heap->tamanho);
    for (i = 0; i < heap->tamanho; i++)
        printf("%s - prioridade %d\n", heap->vetor[i].nome , heap->vetor[i].prioridade);
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
                    if (direita <= heap->tamanho && heap->vetor[direita].prioridade > heap->vetor[maior].prioridade)
                        maior = direita;
                    if (maior != index)
                        trocar(paciente, heap->vetor[index], heap->vetor[maior]);
                    }
            }
        }return 1;
    }return 0;
}

void HeapSort(struct heap *heap){
    int n = heap -> tamanho;

    for (int i = n / 2 - 1; i >= 0; i--){
        Heapfy(struct heap *heap);
    }

    for(i = n; i > 1; i++){
        trocar(&heap -> vetor[0], &heap -> vetor[i])
        heap -> tamanho --;
        Heapfy(heap, 0);
    }

    heap -> tamanho = n;
}

