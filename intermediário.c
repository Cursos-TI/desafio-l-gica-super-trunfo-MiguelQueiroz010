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

void Comparar(SuperCard card_a, SuperCard card_b)
{
  //Menu para comparação das Cartas
  printf("\n\nSelecione o atributo para fazer a comparação das cartas:\n\n"
  "1 - População\n"
  "2 - Área\n"
  "3 - PIB\n"
  "4 - Número de Pontos Turísticos\n"
  "5 - Densidade Demográfica\n\n"
  "Digite o número correspondente: "
  );

  int choice_num;
  scanf("%d", &choice_num); //Ler a escolha

  switch (choice_num)
  {
    case 1: //População

    //Comparação das Cartas
    printf("\nComparação de cartas (Atributo: População):\n\n");

    //Exibir os atributos para cada Carta
    printf("Carta %d - %s: %d habitantes\n", card_a.index, card_a.city_name, card_a.population);
    printf("Carta %d - %s: %d habitantes\n", card_b.index, card_b.city_name, card_b.population);

    //Comparar atributos
    if(card_a.population > card_b.population)
      printf("Resultado: Carta %d (%s) venceu!", card_a.index,  card_a.city_name);
    else if(card_a.population < card_b.population)
      printf("Resultado: Carta %d (%s) venceu!", card_b.index,  card_b.city_name);
    else
      printf("Houve um empate!");

    break;

    case 2: //Área

    //Comparação das Cartas
    printf("\nComparação de cartas (Atributo: Área):\n\n");

    //Exibir os atributos para cada Carta
    printf("Carta %d - %s: %.2f km²\n", card_a.index, card_a.city_name, card_a.area);
    printf("Carta %d - %s: %.2f km²\n", card_b.index, card_b.city_name, card_b.area);

    //Comparar atributos
    if(card_a.area > card_b.area)
      printf("Resultado: Carta %d (%s) venceu!", card_a.index,  card_a.city_name);
    else if(card_a.area < card_b.area)
      printf("Resultado: Carta %d (%s) venceu!", card_b.index,  card_b.city_name);
    else
      printf("Houve um empate!");
    break;

    case 3: //PIB

    //Comparação das Cartas
    printf("\nComparação de cartas (Atributo: PIB):\n\n");

    //Exibir os atributos para cada Carta
    printf("Carta %d - %s: %.2f bilhões de reais\n", card_a.index, card_a.city_name, card_a.pib);
    printf("Carta %d - %s: %.2f bilhões de reais\n", card_b.index, card_b.city_name, card_b.pib);

    //Comparar atributos
    if(card_a.pib > card_b.pib)
      printf("Resultado: Carta %d (%s) venceu!", card_a.index,  card_a.city_name);
    else if(card_a.pib < card_b.pib)
      printf("Resultado: Carta %d (%s) venceu!", card_b.index,  card_b.city_name);
    else
      printf("Houve um empate!");

    break;

    case 4: //Número de Pontos Turísticos

    //Comparação das Cartas
    printf("\nComparação de cartas (Atributo: Número de Pontos Turísticos):\n\n");

    //Exibir os atributos para cada Carta
    printf("Carta %d - %s: %d\n", card_a.index, card_a.city_name, card_a.turistic_points);
    printf("Carta %d - %s: %d\n", card_b.index, card_b.city_name, card_b.turistic_points);

    //Comparar atributos
    if(card_a.turistic_points > card_b.turistic_points)
      printf("Resultado: Carta %d (%s) venceu!", card_a.index,  card_a.city_name);
    else if(card_a.turistic_points < card_b.turistic_points)
      printf("Resultado: Carta %d (%s) venceu!", card_b.index,  card_b.city_name);
    else
      printf("Houve um empate!");
    break;

    case 5: //Densidade Demográfica (population_density) *regra invertida: menor valor vence

    //Comparação das Cartas
    printf("\nComparação de cartas (Atributo: Densidade Demográfica):\n\n");

    //Exibir os atributos para cada Carta
    printf("Carta %d - %s: %.2f habitantes por km²\n", card_a.index, card_a.city_name, card_a.population_density);
    printf("Carta %d - %s: %.2f habitantes por km²\n", card_b.index, card_b.city_name, card_b.population_density);

    //Comparar atributos
    if(card_a.population_density < card_b.population_density)
      printf("Resultado: Carta %d (%s) venceu!", card_a.index,  card_a.city_name);
    else if(card_a.population_density > card_b.population_density)
      printf("Resultado: Carta %d (%s) venceu!", card_b.index,  card_b.city_name);
    else
      printf("Houve um empate!");
    break;
  
  default:
    printf("Opção inválida!! - Tente novamente em 3 segundos...\n");

    sleep(3);

    //Limpa o console
    system("cls");
    system("clear");

    //Reiniciar
    Comparar(card_a, card_b);
    break;
  }
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

  //Iniciar comparação
  Comparar(cartas[0], cartas[1]);

  //Encerramento
  printf("\n\nFim do programa\n\n");

return 0;
} 
