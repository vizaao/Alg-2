#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "fila.h"


void trocar (int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}


void InicHeap (struct heap *heap){
    heap->tamanho = 0;
}

void InsereHeap(struct heap *heap, int valor){
    if (heap->tamanho >= maximo - 1)
        return;
    
    heap->tamanho++;
    int i = heap->tamanho;
    heap->vetor[i] = valor;

    while (i > 1 && heap->vetor[i/2] < heap->vetor[i]){
        int aux = heap->vetor[i/2];
        heap->vetor[i/2] = heap->vetor[i];
        heap->vetor[i] = aux;
        i = i / 2;
    }
}

void Heapfy (struct heap *heap, int i){
    int maior = i;
    int esquerda = 2*i;
    int direita = 2*i + 1;

    if (esquerda < tamanho && vetor[esquerda] > vetor[maior])
        maior = esquerda;

    if (direita < tamanho && vetor[direita] > vetor[maior])
        maior = direita;

    if (maior != 1){
        int aux = heap->vetor[i];
        heap->vetor[i] = heap->vetor[maior];
        heap->vetor[maior] = aux;
        Heapfy(heap, maior); //aqui podemos usar os conhecimentos de recursividade aprendidos em aula
    }
}

void RemoveHeap(struct heap *heap){
    heap->vetor[0] = heap->vetor[heap->tamanho-1];
    heap->tamanho--;
    heapfy(heap->vetor, heap->tamanho, 0);
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

int ChecaHeap(heap *heap{

})
