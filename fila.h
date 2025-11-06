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

long long heap_cmp = 0;
long long heap_swaps = 0;

//função que inicia o heap
void InicHeap (struct heap *Heap);

#endif
