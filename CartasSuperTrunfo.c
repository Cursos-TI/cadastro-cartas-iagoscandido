#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

int main()
{
  // Área para definição das variáveis para armazenar as propriedades das cidades

  // Área para entrada de dados

  // Área para exibição dos dados da cidade

  // Estado: Uma letra de 'A' a 'H' (representando um dos oito estados). Tipo: char
  char card_state;
  printf("Digite o estado (A a H):\n");
  scanf("%c", &card_state);

  /// Código da Carta: A letra do estado seguida de um número de 01 a 04 (ex: A01, B03). Tipo: char[] (um array de caracteres, ou string)
  char card_code[5];
  printf("Digite o codigo da carta.\nA letra do estado seguida de um número de 01 a 04 (ex: A01, B03):\n");
  scanf("%s", &card_code);

  // limpa o buffer
  // retirado do stackloverflow
  // source: https://stackoverflow.com/questions/7898215/how-can-i-clear-an-input-buffer-in-c
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;

  // Nome da Cidade: O nome da cidade. Tipo: char[] (string)
  char card_city[20];
  printf("Digite o nome da cidade:\n");
  fgets(card_city, sizeof(card_city), stdin);
  card_city[strcspn(card_city, "\n")] = 0;

  // População: O número de habitantes da cidade. Tipo: int
  int card_population;
  printf("Digite a população da cidade: ");
  scanf("%d", &card_population);

  // Área (em km²): A área da cidade em quilômetros quadrados. Tipo: float
  float card_area;
  printf("Digite a área da cidade em km²: ");
  scanf("%f", &card_area);

  // PIB: O Produto Interno Bruto da cidade. Tipo: float
  float card_pib;
  printf("Digite o PIB da cidade: ");
  scanf("%f", &card_pib);

  // Número de Pontos Turísticos: A quantidade de pontos turísticos na cidade. Tipo: int
  int card_tourist_points;
  printf("Digite o número de pontos turísticos na cidade: ");
  scanf("%d", &card_tourist_points);

  // Estrutura de saída:
  // Carta 1:
  // Estado: A
  // Código: A01
  // Nome da Cidade: São Paulo
  // População: 12325000
  // Área: 1521.11 km²
  // PIB: 699.28 bilhões de reais
  // Número de Pontos Turísticos: 50
  printf("\n\nCarta 1:\nEstado: %c\nCódigo: %s\nNome da Cidade: %s\nPopulação: %d\nÁrea: %f km²\nPIB: %f bilhões de reais\nNúmero de Pontos Turísticos: %d\n", card_state, card_code, card_city, card_population, card_area, card_pib, card_tourist_points);

  char card2_state;
  printf("Digite o estado da segunda carta (A a H):\n");
  scanf(" %c", &card2_state);

  char card2_code[5];
  printf("Digite o codigo da segunda carta.\nA letra do estado seguida de um número de 01 a 04 (ex: A01, B03):\n");
  scanf("%s", &card2_code);

  char card2_city[20];
  printf("Digite o nome da cidade da segunda carta:\n");
  fgets(card2_city, sizeof(card2_city), stdin);
  card2_city[strcspn(card2_city, "\n")] = 0;

  while ((c = getchar()) != '\n' && c != EOF)
    ;

  int card2_population;
  printf("Digite a população da segunda cidade: ");
  scanf("%d", &card2_population);

  float card2_area;
  printf("Digite a área da segunda cidade em km²: ");
  scanf("%f", &card2_area);

  float card2_pib;
  printf("Digite o PIB da segunda cidade: ");
  scanf("%f", &card2_pib);

  int card2_tourist_points;
  printf("Digite o número de pontos turísticos na segunda cidade: ");
  scanf("%d", &card2_tourist_points);

  printf("\n\nCarta 2:\nEstado: %c\nCódigo: %s\nNome da Cidade: %s\nPopulação: %d\nÁrea: %f km²\nPIB: %f bilhões de reais\nNúmero de Pontos Turísticos: %d\n", card2_state, card2_code, card2_city, card2_population, card2_area, card2_pib, card2_tourist_points);

  return 0;
}
