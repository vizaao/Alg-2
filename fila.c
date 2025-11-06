#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "fila.h"

long long heap_comparacoes = 0;  //contador para sabermos o numero de comparaçoes no heap
long long heap_trocas = 0; //contador para sabermos o numero de trocas realizads pelo heap no final da execucao


//funcao basica de troca
void trocar (int *a, int *b){
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
    if (heap->tamanho >= Max)
        return;
    
    int i = heap->tamanho++;
    heap->vetor[i] = valor;

    while (i > 0 && heap->vetor[(i - 1) / 2] < heap->vetor[i]){
        trocar(&heap->vetor[i], &heap->[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void Heapfy (struct heap *heap, int i, int tamanho){
    int maior = i;
    int esquerda = 2*i + 1;
    int direita = 2*i + 2;

    if (esquerda <= tamanho){
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

void RemoveHeap(struct heap *heap){

    int raiz = heap->vetor[0];

    heap->vetor[0] = heap->vetor[--heap->tamanho];
    heapfy(heap, 0);
    return raiz;
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
})

void imprimeheap(heap *heap){
    if(heap -> tamanho == NULL){
        printf("heap vazia");
        return;
    }

    printf("heap: ");
    for (int i = 1; i <= heap -> tamanho; i++){
        printf("%d", heap -> vetor[i]);
    }
    
    printf("/n");
}
