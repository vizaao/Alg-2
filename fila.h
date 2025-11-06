#ifndef fila_de_prioridades
#define fila_de_prioridades

//definir a estrutura para os pacientes
struct paciente { 
    char paciente[20];
    int prioridade;
} paciente;

struct fila{
    struct paciente *Paciente; // apontador para o vetor de pacientes
    int tamanho; //tamanho atual da fila
    int capacidade; //tamanho total da fila
} fila;

struct heap{
    struct paciente a[20];
    int tamanho;
}heap;

//função que inicia o heap
void InicHeap (struct heap *Heap);

#endif
