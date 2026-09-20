/*
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
// #include <windows.h>

// --- VARIÁVEIS "GLOBAIS" ---
#define TAM128 128
#define TAM32 32

typedef struct {
  int day;
  int month;
  int year;
} DataType;

// --- DEFINIÇÃO DE FUNÇÕES ---

void show_menu();

// --- CÓDIGO PRINCIPAL ---

int main() {

  printf("Hello, World!");
  return 0;
}
