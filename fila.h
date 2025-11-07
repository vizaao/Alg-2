#ifndef fila_de_prioridades
#define fila_de_prioridades

#define true 1
#define false 0

#define Maximo_Pacientes 1024
#define Max_nome 20

//definir a estrutura para os pacientes
struct paciente { 
    char paciente[Max_nome];
    int prioridade;
} paciente;

struct heap{
    struct paciente vetor[Maximo_Pacientes];
    int tamanho;
}heap;

//funcao para trocar pacientes
void trocar (paciente *a, paciente *b);

//função que inicia o heap
void InicHeap (struct heap *Heap);

//transforma o vetor em um heap maximo
void Heapfy (struct heap *heap, int i);

//funcao responsavel por adicionar novos pacientes na fila
void InsereHeap(struct heap *heap, paciente novo);

//funcao responsavel por remover os pacientes atendidos da fila
void RemoveHeap(struct heap *heap, paciente *removido);

//funcao que imprime o estado da fila
void ImprimeHeap(struct heap *heap);

//funcao responsavel por alterar a prioridade entre os pacientes da fila
int AlteraHeap(struct heap *heap, char nome[], int nova);

//constroi a fila de pacientes
void ConstroiHeap(struct heap *heap);

#endif
