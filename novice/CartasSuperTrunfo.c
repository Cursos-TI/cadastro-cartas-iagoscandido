#include <stdio.h>
// Adicionado biblioteca de strings, o compilador estava apontando um warning
#include <string.h>

//
void prompt_card(int card_number);
void buffer_cleaner();
void print_card(char state, char code[4], char city[20], int population, float area, float pib, int tourist_points, int card_number);

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

int main()
{
  prompt_card(1);
  buffer_cleaner();
  prompt_card(2);

  return 0;
}

void prompt_card(int card_number)
{
  // Estado: Uma letra de 'A' a 'H' (representando um dos oito estados). Tipo: char
  char state;
  printf("Digite o estado (A a H):\n");
  // Espaço de linha adicionado para consumir a quebra pendente no buffer
  scanf(" %c", &state);

  /// Código da Carta: A letra do estado seguida de um número de 01 a 04 (ex: A01, B03). Tipo: char[] (um array de caracteres, ou string)
  char code[4];
  printf("Digite o codigo da carta.\nA letra do estado seguida de um número de 01 a 04 (ex: A01, B03):\n");
  scanf(" %s", code);

  buffer_cleaner();

  // Nome da Cidade: O nome da cidade. Tipo: char[] (string)
  char city[20];
  printf("Digite o nome da cidade:\n");
  fgets(city, sizeof(city), stdin);
  city[strcspn(city, "\n")] = 0;

  // População: O número de habitantes da cidade. Tipo: int
  int population;
  printf("Digite a população da cidade: ");
  scanf("%d", &population);

  // Área (em km²): A área da cidade em quilômetros quadrados. Tipo: float
  float area;
  printf("Digite a área da cidade em km²: ");
  scanf("%f", &area);

  // PIB: O Produto Interno Bruto da cidade. Tipo: float
  float pib;
  printf("Digite o PIB da cidade: ");
  scanf("%f", &pib);

  // Número de Pontos Turísticos: A quantidade de pontos turísticos na cidade. Tipo: int
  int tourist_points;
  printf("Digite o número de pontos turísticos na cidade: ");
  scanf("%d", &tourist_points);

  print_card(state, code, city, population, area, pib, tourist_points, card_number);
}

void print_card(char state, char code[4], char city[20], int population, float area, float pib, int tourist_points, int card_number)
{
  // Estrutura de saída:
  // Carta 1:
  // Estado: A
  // Código: A01
  // Nome da Cidade: São Paulo
  // População: 12325000
  // Área: 1521.11 km²
  // PIB: 699.28 bilhões de reais
  // Número de Pontos Turísticos: 50
  printf("\n\nCarta %d:\nEstado: %c\nCódigo: %s\nNome da Cidade: %s\nPopulação: %d\nÁrea: %f km²\nPIB: %f bilhões de reais\nNúmero de Pontos Turísticos: %d\n\n\n", card_number, state, code, city, population, area, pib, tourist_points);
}

void buffer_cleaner()
{
  // limpa o buffer
  // retirado do stackloverflow: https://stackoverflow.com/questions/7898215/how-can-i-clear-an-input-buffer-in-c
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}