#ifndef fila_de_prioridades
#define fila_de_prioridades

#define true 1
#define false 0

#define Maximo_pacientes 1024
#define Max_nome 20

//definir a estrutura para os pacientes
// CORRIGIDO: Removido 'paciente' no final da definição
struct paciente { 
    char paciente[Max_nome];
    int prioridade;
};

// CORRIGIDO: Removido 'heap' no final e 'paciente' -> 'struct paciente'
struct heap{
    struct paciente vetor[Maximo_pacientes];
    int tamanho;
}heap;
};

//funcao para trocar pacientes
// CORRIGIDO: 'paciente' -> 'struct paciente'
void trocar (struct paciente *a, struct paciente *b);

//função que inicia o heap
// CORRIGIDO: 'struct heap *Heap' -> 'struct heap *h' para padronizar
void InicHeap (struct heap *h);

//transforma o vetor em um heap maximo
void Heapfy (struct heap *h, int i);

//funcao responsavel por adicionar novos pacientes na fila
// CORRIGIDO: 'paciente' -> 'struct paciente'
void InsereHeap(struct heap *h, struct paciente novo);

//funcao responsavel por remover os pacientes atendidos da fila
void RemoveHeap(struct heap *heap, paciente *removido);
// CORRIGIDO: 'void' -> 'int', 'paciente' -> 'struct paciente', ';' adicionado
int RemoveHeap(struct heap *h, struct paciente *removido);

//funcao que imprime o estado da fila
void ImprimeHeap(struct heap *h);

//funcao responsavel por alterar a prioridade entre os pacientes da fila
int AlteraHeap(struct heap *heap, char nome[], int nova);

//constroi a fila de pacientes
void ConstroiHeap(struct heap *heap);

//funcao responsavel por conferir se a fila de prioridades é um heap valido
void ChecaHeap(struct heap *heap)

//funcao que implementa o algoritmo de ordenacao heapsort, usado para criar uma fila em ordem
void HeapSort(struct heap *h)
int AlteraHeap(struct heap *h, char nome[], int nova);

// --- CORRIGIDO: Protótipos que faltavam foram adicionados ---
int ChecaHeap(struct heap *h);

void ConstroiHeap(struct heap *h);

void HeapSort(struct heap *h);

#endif
