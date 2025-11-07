#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <time.h>   
#include "fila.h" 

// variaveis responsaveis por armazenar o numero de trocas e comparacoes do heap 
extern long long heap_comparacoes;
extern long long heap_trocas;

// funcao para limpar o buffer de entrada 
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// funcao que roda os testes de ordenacao com um vetor de 1024 elementos
void rodarTestes() {
    printf("--------------------------------------------\n");
    printf("Rodando Testes de Ordenação\n");
    printf("--------------------------------------------\n");

    // cria um heap para ordenar
    struct heap heapMestre;
    InicHeap(&heapMestre);
    heapMestre.tamanho = Maximo_Pacientes; // no maximo 1024 posicoes

    printf("Gerando 1024 pacientes com prioridades aleatórias...\n");
    for (int i = 0; i < Maximo_Pacientes; i++) {
        struct paciente p;
        p.prioridade = rand() % 1000; // aqui definimos a prioridade dos "pacientes"
        sprintf(p.paciente, "Paciente%d", i); // nome dado a cada paciente
        
        // usamos um vetor auxiliar aqui
        heapMestre.vetor[i] = p;
    }
    printf("Vetor aleatório gerado.\n\n");

    // criamos copias do vetor para testar com os 3 algoritmos diferentes
    struct heap heapParaQuick = heapMestre;
    struct heap heapParaSelect = heapMestre;
    struct heap heapParaHeapSort = heapMestre;

    // inicializamos os contadores de trocas e comparacoes para o quick e o select
    int compQuick = 0, trocasQuick = 0;
    int compSelect = 0, trocasSelect = 0;

    // testando com o quicksort
    printf("Executando QuickSort (com mediana de 3)...\n");
    QuickSort(&heapParaQuick, 0, heapParaQuick.tamanho - 1, &compQuick, &trocasQuick);
    printf("Resultado: %d comparações, %d trocas.\n\n", compQuick, trocasQuick);

    // testando com o selectsort
    printf("Executando SelectSort...\n");
    SelectSort(&heapParaSelect, &compSelect, &trocasSelect);
    printf("Resultado: %d comparações, %d trocas.\n\n", compSelect, trocasSelect);

    // testando com o heapsort
    printf("Executando HeapSort...\n");
    
    // zeramos os contadores do heap pq as funcoes do pronto socorro as utilizam
    heap_comparacoes = 0;
    heap_trocas = 0;
    HeapSort(&heapParaHeapSort);

    printf("Resultado: %lld comparações, %lld trocas.\n\n", heap_comparacoes, heap_trocas);
    
    printf("--------------------------------------------\n");
    printf("Testes concluídos.\n");
    printf("--------------------------------------------\n");
}


// menu do pronto socorro 
int main() {
    struct heap filaDePacientes;
    InicHeap(&filaDePacientes);
    int opcao;

    // funcao para gerar vetor aleatorio com 1024 elementos 
    srand(time(NULL));

    printf("Bem-vindo ao Pronto Socorro Heap or Quick.\n");

    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Inserir Paciente\n");
        printf("2. Chamar Próximo Paciente (Remover)\n");
        printf("3. Alterar Prioridade de Paciente\n");
        printf("4. Imprimir Fila Atual\n");
        printf("5. Checar Propriedade do Heap\n");
        printf("6. Rodar Testes de Ordenação (N=1024)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        
        scanf("%d", &opcao);
        limparBuffer(); 

        switch (opcao) {
            case 1: { // InsereHeap
                struct paciente novo;
                printf("Nome do paciente (máximo 19 caracteres): ");
                scanf("%19s", novo.paciente); 
                printf("Prioridade (quanto maior, mais urgente): ");
                scanf("%d", &novo.prioridade);
                limparBuffer();
                
                InsereHeap(&filaDePacientes, novo);
                printf("Paciente %s inserido.\n", novo.paciente);
                break;
            }
            case 2: { // RemoveHeap
                struct paciente removido;
                if (RemoveHeap(&filaDePacientes, &removido)) {
                    printf("Paciente Removido: %s (Prioridade: %d)\n", removido.paciente, removido.prioridade);
                } else {
                    printf("Fila vazia!\n");
                }
                break;
            }
            case 3: { // AlteraHeap
                char nome[Max_nome];
                int novaPrioridade;
                printf("Nome do paciente a alterar: ");
                scanf("%19s", nome);
                printf("Nova prioridade: ");
                scanf("%d", &novaPrioridade);
                limparBuffer();

                if (AlteraHeap(&filaDePacientes, nome, novaPrioridade)) {
                    printf("Prioridade de %s alterada.\n", nome);
                } else {
                    printf("Paciente %s não encontrado!\n", nome);
                }
                break;
            }
            case 4: // ImprimeHeap
                ImprimeHeap(&filaDePacientes);
                break;
            case 5: // ChecaHeap
                ChecaHeap(&filaDePacientes);
                break;
            case 6: // roda os testes com os diferentes algoritmos de ordenacao
                rodarTestes();
                break;
            case 0: // sai do programa
                printf("Finalizando o programa\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}