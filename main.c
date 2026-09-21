/*
 *  ==============================================
 *  Autores: Antônio Gonçalves dos Santos;
 *           Bernardo Quaiatto Signor;
 *
 *          UFN - Ciência da Computação
 *          Algoritmos e Programação B
 *  ==============================================
 *
 * No nosso dia-a-dia, durante a resolução de problemas e sua
 * implementação, nos deparamos com diferentes tipos de dados
 * e manipulações desses dados, que precisam ser elaboradas.
 * Com o uso de ferramentas de edição e compilação de programas,
 * faça um programa para gerenciar o Controle de Medicamentos,
 * conforme a descrição:
 *      Uma farmácia pública controla os medicamentos disponibilizados
 *      pelo governo às pessoas cadastradas. Desenvolva parte do
 *      controle desta farmácia, fazendo o Controle de Medicamentos,
 *      cujos dados são:
 *          - Medicamentos;                         -> char[128]
 *          - Princípio ativo;                      -> char[128]
 *          - Laboratório;                          -> char[128]
 *          - Quantidade em estoque;                -> int
 *          - Unidade (caixa, ml, comprimido, ...); -> char[32]
 *          - Data de validade;                     -> struct DataType
 *          - Preço custo (R$);                     -> float
 *
 * Desenvolva um algoritmo com a estrutura de dados para
 * armazenar os dados de N medicamentos. Posteriormente,
 * execute cada uma das ações a seguir (apresente um Menu
 * de opções ao usuário para facilitar a escolha):
 *      - Listar todos os medicamentos e seus dados;
 *      - Listar os medicamentos de um laboratório informado
 *          pelo usuário;
 *      - Calcular e mostrar a quantidade de medicamentos com
 *          quantidade menor à informada pelo usuário;
 *      - Cacular o valor total pago pelos medicamentos.
 */

#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
// #include <windows.h>

#define TAM128 128
#define TAM32 32
#define MAX_MED 100

// --- ESTRUTURAS DE DADOS ---

typedef struct {
    int dia;
    int mes;
    int ano;
} DataType;

typedef struct {
    char nome[TAM128];
    char principio_ativo[TAM128];
    char laboratorio[TAM128];
    int quantidade;
    char unidade[TAM32];
    DataType validade;
    float preco_custo;
} Medicamento;

// --- FUNÇÕES AUXILIARES ---


void clean_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void remove_line_break(char str[]) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// --- FUNÇÕES DO SISTEMA ---

void show_menu() {
    printf("\n===============================\n");
    printf("\tCONTROLE DE MEDICAMENTOS");
    printf("\n===============================\n");
}

int cadastrar_medicamento(Medicamento estoque[], int total) {
    if (total >= MAX_MED) {
        printf("\nLimite máximo de medicamentos atingido!\n");
        return total;
    }
    
    printf("\n--- CADASTRO DE MEDICAMENTO ---\n");

    printf("Nome do medicamento: ");
    fgets(estoque[total].nome, TAM128, stdin);
    remove_line_break(estoque[total].nome);

    printf("Princípio ativo: ");
    fgets(estoque[total].principio_ativo, TAM128, stdin);
    remove_line_break(estoque[total].principio_ativo);
    
    printf("Laboratório: ");
    fgets(estoque[total].laboratorio, TAM128, stdin);
    remove_line_break(estoque[total].laboratorio);

    printf("Quantidade em estoque: ");
    scanf("%d", &estoque[total].quantidade);

    clean_buffer();
    printf("Unidade (ex: caixa, ml, comprimido): ");
    fgets(estoque[total].unidade, TAM32, stdin);
    remove_line_break(estoque[total].unidade);
    
    printf("Data de validade (DD MM AAAA): ");
    scanf("%d %d %d", &estoque[total].validade.dia, &estoque[total].validade.mes, &estoque[total].validade.ano);

    printf("Preço de custo (R$): ");
    scanf("%f", &estoque[total].preco_custo);
    clean_buffer();

    printf("\nMedicamento cadastrado com sucesso!\n");

    return total + 1;
}

void listar_medicamentos(Medicamento estoque[], int total) {
    if (total == 0) {
        printf("\nNenhum medicamento cadastrado.\n");
        return;
    }
    
    printf("\n--- LISTA DE MEDICAMENTOS ---\n");
    for (int i = 0; i < total; i++) {
        printf("\n[%d] Nome: %s\n", i + 1, estoque[i].nome);
        printf("\tPrincípio Ativo: %s\n", estoque[i].principio_ativo);
        printf("\tLaboratório: %s\n", estoque[i].laboratorio);
        printf("\tEstoque: %d %s\n", estoque[i].quantidade, estoque[i].unidade);
        printf("\tValidade: %02d/%02d/%04d\n", estoque[i].validade.dia, estoque[i].validade.mes, estoque[i].validade.ano);
        printf("\tPreço de Custo: R$ %.2f\n", estoque[i].preco_custo);
    }
}

void listar_por_laboratorio(Medicamento estoque[], int total) {
    if (total == 0) {
        printf("\nNenhum medicamento cadastrado.\n");
        return;
    }

    char lab_busca[TAM128];
    printf("\nDigite o nome do laboratorio: ");
    fgets(lab_busca, TAM128, stdin);
    remove_line_break(lab_busca);

    int encontrados = 0;
    printf("\n--- MEDICAMENTOS DO LABORATORIO: %s ---\n", lab_busca);
    for (int i = 0; i < total; i++) {
        if (strcasecmp(estoque[i].laboratorio, lab_busca) == 0) {
            printf("- %s (Estoque: %d %s) | Validade: %02d/%02d/%04d\n",
                   estoque[i].nome, estoque[i].quantidade, estoque[i].unidade,
                   estoque[i].validade.dia, estoque[i].validade.mes, estoque[i].validade.ano);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum medicamento encontrado para este laboratório.\n");
    }
}

void contar_estoque_baixo(Medicamento estoque[], int total) {
    if (total == 0) {
        printf("\nNenhum medicamento cadastrado.\n");
        return;
    }

    int limite, contador = 0;
    printf("\nDigite a quantidade limite: ");
    scanf("%d", &limite);
    clean_buffer();

    for (int i = 0; i < total; i++) {
        if (estoque[i].quantidade < limite) {
            contador++;
        }
    }

    printf("\nQuantidade de medicamentos com estoque menor que %d: %d\n", limite, contador);
}

void calcular_valor_total(Medicamento estoque[], int total) {
    if (total == 0) {
        printf("\nNenhum medicamento cadastrado.\n");
        return;
    }

    float soma = 0.0;
    for (int i = 0; i < total; i++) {
        soma += (estoque[i].quantidade * estoque[i].preco_custo);
    }

    printf("\nValor total investido no estoque: R$ %.2f\n", soma);
}

// --- CÓDIGO PRINCIPAL ---

int main() {
    setlocale(LC_ALL, "Portuguese");


    Medicamento estoque[MAX_MED];
    int total_medicamentos = 0;
    int opt = -1;
    

    while (opt != 0) {
        printf("\n========================================\n");
        printf("\tCONTROLE DE MEDICAMENTOS");
        printf("\n========================================\n");
        printf("1. Cadastrar Medicamento\n");
        printf("2. Listar todos os medicamentos\n");
        printf("3. Listar por laboratório\n");
        printf("4. Contar estoque abaixo de um limite\n");
        printf("5. Calcular valor total do estoque\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opt);
        clean_buffer();

        switch (opt) {
            case 1:
                total_medicamentos = cadastrar_medicamento(estoque, total_medicamentos);
                break;
            case 2:
                listar_medicamentos(estoque, total_medicamentos);
                break;
            case 3:
                listar_por_laboratorio(estoque, total_medicamentos);
                break;
            case 4:
                contar_estoque_baixo(estoque, total_medicamentos);
                break;       
            case 5:
                calcular_valor_total(estoque, total_medicamentos);
                break;
            case 0:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
