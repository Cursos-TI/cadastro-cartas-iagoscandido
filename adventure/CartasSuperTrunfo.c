#include <stdio.h>
// Adicionado biblioteca de strings, o compilador estava apontando um warning
#include <string.h>

//
void prompt_card(int card_number);
void buffer_cleaner();
void print_card(char state, char code[4], char city[20], int population, float area, float pib, int tourist_points, int card_number, float density, float pib_per_capta);
void should_print_card_with_sample_data(int card_number);
float calculate_population_density(int population, float area);
float calculate_pib_per_capta(float pib, float population);

int main()
{
  prompt_card(1);
  buffer_cleaner();
  prompt_card(2);

  return 0;
}

void should_print_card_with_sample_data(int card_number)
{
  // Estado: Uma letra de 'A' a 'H' (representando um dos oito estados). Tipo: char
  char state;
  printf("Digite o estado (A a H): ");
  // Espaço de linha adicionado para consumir a quebra pendente no buffer
  state = 'A';

  /// Código da Carta: A letra do estado seguida de um número de 01 a 04 (ex: A01, B03). Tipo: char[] (um array de caracteres, ou string)
  char code[4];
  printf("Digite o codigo da carta.\nA letra do estado seguida de um número de 01 a 04 (ex: A01, B03): ");
  strcpy(code, "A01");

  buffer_cleaner();

  // Nome da Cidade: O nome da cidade. Tipo: char[] (string)
  char city[20];
  printf("Digite o nome da cidade: ");
  strcpy(city, "São Paulo");
  city[strcspn(city, "\n")] = 0;

  // População: O número de habitantes da cidade. Tipo: int
  int population;
  printf("Digite a população da cidade: ");
  population = 12325000;
  // Área (em km²): A área da cidade em quilômetros quadrados. Tipo: float
  float area;
  printf("Digite a área da cidade em km²: ");
  area = 1521.11;

  // PIB: O Produto Interno Bruto da cidade. Tipo: float
  float pib;
  printf("Digite o PIB da cidade: ");
  pib = 699.28;

  // Número de Pontos Turísticos: A quantidade de pontos turísticos na cidade. Tipo: int
  int tourist_attractions;
  printf("Digite o número de pontos turísticos na cidade: ");
  tourist_attractions = 50;

  // Densidade Populacional: A densidade populacional da cidade (População / Área). Tipo: float
  float density = calculate_population_density(population, area);

  // PIB per Capita: O PIB per capita da cidade (PIB / População). Tipo: float
  float pib_per_capta = calculate_pib_per_capta(pib, population);

  // Printa o card
  print_card(state, code, city, population, area, pib, tourist_attractions, card_number, density, pib_per_capta);
}

void prompt_card(int card_number)
{
  // Estado: Uma letra de 'A' a 'H' (representando um dos oito estados). Tipo: char
  char state;
  printf("Digite o estado (A a H): ");
  // Espaço de linha adicionado para consumir a quebra pendente no buffer
  scanf(" %c", &state);

  /// Código da Carta: A letra do estado seguida de um número de 01 a 04 (ex: A01, B03). Tipo: char[] (um array de caracteres, ou string)
  char code[4];
  printf("Digite o codigo da carta.\nA letra do estado seguida de um número de 01 a 04 (ex: A01, B03): ");
  scanf(" %s", code);

  buffer_cleaner();

  // Nome da Cidade: O nome da cidade. Tipo: char[] (string)
  char city[20];
  printf("Digite o nome da cidade: ");
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
  int tourist_attractions;
  printf("Digite o número de pontos turísticos na cidade: ");
  scanf("%d", &tourist_attractions);

  // Densidade Populacional: A densidade populacional da cidade (População / Área). Tipo: float
  float density = calculate_population_density(population, area);

  // PIB per Capita: O PIB per capita da cidade (PIB / População). Tipo: float
  float pib_per_capta = calculate_pib_per_capta(pib, population);

  // Printa o card
  print_card(state, code, city, population, area, pib, tourist_attractions, card_number, density, pib_per_capta);
}

void print_card(char state, char code[4], char city[20], int population, float area, float pib, int tourist_attractions, int card_number, float density, float pib_per_capta)
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
  // Densidade Populacional: 8102.47 hab/km²
  // PIB per Capita: 56724.32 reais
  printf("\n\n-----------Carta: %d-----------\n", card_number);
  printf("Estado: %c\n", state);
  printf("Código: %s\n", code);
  printf("Nome da Cidade: %s\n", city);
  printf("População: %d\n", population);
  printf("Área: %.2f km²\n", area);
  printf("PIB: %.2f bilhões de reais\n", pib);
  printf("Número de Pontos Turísticos: %d\n", tourist_attractions);
  printf("-----------Dados-----------\n");
  printf("Densidade Populacional: %.2f hab/km²\n", density);
  printf("PIB per Capita: %.2f reais\n", pib_per_capta);
  printf("\n");
}

void buffer_cleaner()
{
  // limpa o buffer
  // retirado do stackloverflow: https://stackoverflow.com/questions/7898215/how-can-i-clear-an-input-buffer-in-c
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

float calculate_population_density(int population, float area)
{
  return population / area;
}

float calculate_pib_per_capta(float pib, float population)
{
  // conversão do pib para real
  return (pib * 1000000000) / population;
}