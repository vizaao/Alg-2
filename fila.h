#ifndef fila_de_prioridades
#define fila_de_prioridades

#define true 1
#define false 0

#define Maximo_Pacientes 1024
#define Max_nome 20

// definir a estrutura para os pacientes
struct paciente { 
    char paciente[Max_nome];
    int prioridade;
};

// definir a estrutura do heap
struct heap {
    struct paciente vetor[Maximo_Pacientes];
    int tamanho;
};

// funcao para trocar pacientes
void trocar(struct paciente *a, struct paciente *b);

// função que inicia o heap
void InicHeap(struct heap *heap);

// transforma o vetor em um heap máximo
void Heapfy(struct heap *heap, int i);

// funcao responsavel por adicionar novos pacientes na fila
void InsereHeap(struct heap *heap, struct paciente novo);

// funcao responsavel por remover os pacientes atendidos da fila
int RemoveHeap(struct heap *heap, struct paciente *removido);

// funcao que imprime o estado da fila
void ImprimeHeap(struct heap *heap);

// funcao responsavel por alterar a prioridade entre os pacientes da fila
int AlteraHeap(struct heap *heap, char nome[], int nova);

// constroi a fila de pacientes
void ConstroiHeap(struct heap *heap);

// funcao responsavel por conferir se a fila de prioridades é um heap valido
void ChecaHeap(struct heap *heap);

// funcao que implementa o algoritmo de ordenacao heapsort
void HeapSort(struct heap *h);

// funcao que retorna o índice da mediana entre o primeiro, meio e último
int Mediana(struct heap *h, int a, int b);

// funcao que particiona o vetor e conta comparações/trocas
int Particiona(struct heap *h, int a, int b, int *comparacoes, int *trocas);

// funcao que ordena o heap por quicksort recursivo
void QuickSort(struct heap *h, int a, int b, int *comparacoes, int *trocas);

// funcao que ordena o heap por selectsort
void SelectSort(struct heap *h, int *comparacoes, int *trocas);

#endif
