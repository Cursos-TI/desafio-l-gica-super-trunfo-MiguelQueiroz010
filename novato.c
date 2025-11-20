#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

typedef struct{
  // Área para definição das variáveis para armazenar as propriedades das cidades
  char state_code;      //Código do Estado
  char card_code[10];   //Código da Carta Completo
  char city_name[40];   //Nome da Cidade

  int population;       //População
  int turistic_points;  //Número de Pontos Turísticos

  float area;           //Área em km²
  float pib;            //Produto Interno Bruto [PIB]

  //Adicionar Densidade Populacional e PIB per Capita
  float population_density;
  float pib_per_capita;

  int index;            //Índice da Carta

  } SuperCard;

SuperCard GetValues(int card_index)
{
  SuperCard Entry;
  Entry.index = card_index;

  printf("\n\nDigite os dados para a carta %d:\n\n", card_index);
  
  printf("\nCódigo do Estado: ");
  scanf(" %c", &Entry.state_code);
  printf("\nCódigo da Carta: ");
  scanf(" %s", &Entry.card_code);
  printf("\nNome da Cidade: ");
  scanf(" %[^\n]", &Entry.city_name); //O [] são os caracteres lidos e o ^\n indica que ele vai
  //ler enquanto (condição) ^ = negativo, não encontrar uma quebra \n.
  
  printf("\nNúmero de Habitantes: ");
  scanf("%d", &Entry.population);
  printf("\nÁrea da Cidade(km²): ");
  scanf("%f", &Entry.area);
  printf("\nPIB: ");
  scanf("%f",&Entry.pib);
  printf("\nNúmero de Pontos Turísticos: ");
  scanf("%d", &Entry.turistic_points);

  Entry.population_density = Entry.population / Entry.area;
  Entry.pib_per_capita = Entry.pib / Entry.population;

  return Entry;
}

void ShowValues(SuperCard card)
{
  //Imprime [para cada] Carta
  printf(
    "\n\nCarta %d:"
    "\nEstado: %c"
    "\nCódigo: %c%s"
    "\nNome da Cidade: %s"
    "\nPopulação: %d"
    "\nÁrea: %.2f km²"
    "\nPIB: %.2f bilhões de reais"
    "\nNúmero de Pontos Turísticos: %d"
    "\nDensidade Populacional: %2.f hab/km²"
    "\nPIB per Capita: %2.f reais",
    card.index,
    card.state_code,
    card.state_code, card.card_code,
    card.city_name,
    card.population,
    card.area,
    card.pib,
    card.turistic_points,
    card.population_density,
    card.pib_per_capita);
}

int main() {
  //Limpa o console
  system("cls");
  system("clear");

  // Mensagem de Sistema
  printf("Sistema de Cadastro de Cartas\nCoded by Miguel A. Queiroz\n-------------------");
  
  //Pegar os dados das Cartas
  SuperCard cartas[2];
  cartas[0] = GetValues(1); //Carta 1

  //Limpa o console
  system("cls");
  system("clear");

  cartas[1] = GetValues(2); //Carta 2

  //Limpa o console
  system("cls");
  system("clear");

  //Mostrar dados das Cartas
  // Mensagem de Sistema
  printf("Sistema de Cadastro de Cartas\nCoded by Miguel A. Queiroz\n-------------------\n");
  printf("\nDADOS APURADOS\n----------------");

  ShowValues(cartas[0]);  //Carta 1
  ShowValues(cartas[1]);  //Carta 2

  //Comparação das Cartas
  printf("\nComparação de cartas (Atributo: PIB):\n\n");

  //Exibir os atributos para cada Carta
  printf("Carta %d - %s: %.2f bilhões de reais\n", cartas[0].index, cartas[0].city_name, cartas[0].pib);
  printf("Carta %d - %s: %.2f bilhões de reais\n", cartas[1].index, cartas[1].city_name, cartas[1].pib);

  //Comparar atributos
  if(cartas[0].pib > cartas[1].pib)
    printf("Resultado: Carta %d (%s) venceu!", cartas[0].index,  cartas[0].city_name);
  else if(cartas[0].pib < cartas[1].pib)
    printf("Resultado: Carta %d (%s) venceu!", cartas[1].index,  cartas[1].city_name);
  else
    printf("Houve um empate!");

  //Encerramento
  printf("\n\nFim do programa\n\n");

return 0;
} 
