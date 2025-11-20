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

typedef struct {
  int index;
  char nome[40];
  int exists;
  int code;
} ListItem;

void Comparar(SuperCard card_a, SuperCard card_b)
{
  ListItem show_itens[] = {
        {1, "População", 1, 10},
        {2, "Área", 1,20},
        {3, "PIB", 1,30},
        {4, "Pontos Turísticos", 1,40},
        {5, "Densidade Populacional", 1,50},
        {6, "PIB per Capita", 1,60}
    };

  /*
  Códigos de atributos:
  1 - População
  2 - Área
  3 - PIB
  4 - Número de Pontos Turísticos
  5 - Densidade Demográfica
  6 - PIB per Capita
  */

  //Atributos selecionados e resultado de comparação base
  ListItem atribute_1, atribute_2;
  int compare_1, compare_2;

  menu_atributo_1:
  //Mostrar os atributos disponíveis 1º
  printf("\n\nEscolha o primeiro atributo para fazer a comparação das cartas:\n\n");
  for (int i = 0; i < 5; i++) {
        printf("%d - %s\n", show_itens[i].index, show_itens[i].nome);
    }


  int choice_num;
  printf("Digite o código do atributo: ");
  scanf("%d", &choice_num); //Ler a escolha

   if (choice_num < 1 || choice_num > 5) {
        printf("Opção inválida!\n\n");
        goto menu_atributo_1;
    }

  atribute_1 = show_itens[choice_num-1];

  //Remover da lista o item selecionado
  show_itens[choice_num-1].exists = 0; //Flag para remover o item selecionado da lista [bool]

  for(int i = 0, c = 1; i<5; i++)
  {
    //Reindexar todos os outros itens
    if(show_itens[i].exists == 0)
      show_itens[i].index = 0;
    else
    {
      show_itens[i].index = c;
      c++;
    }
  }

  menu_atributo_2:
  //Mostrar os atributos disponíveis 2º
  printf("\n\nEscolha o segundo atributo para fazer a comparação das cartas:\n\n");
  for (int i = 0; i < 5; i++) {
    if(show_itens[i].index != 0)
        printf("%d - %s\n", show_itens[i].index, show_itens[i].nome);
    }
  
  printf("Digite o código do atributo: ");
  scanf("%d", &choice_num); //Ler a escolha

  if (choice_num < 1 || choice_num > 4) {
        printf("Opção inválida!\n\n");
        goto menu_atributo_2;
    }

  for (int i = 0; i < 5; i++) {
    if(show_itens[i].index == choice_num)
      atribute_2 = show_itens[i];
    }


  //Variáveis para valores dos Atributos escolhidos
  float attr_1_a, attr_1_b, attr_2_a, attr_2_b;
  float res_1, res_2;
  
  //Comparações do Atributo 1
  switch (atribute_1.code)
  {
  case 10: //População
    attr_1_a = (float)card_a.population;
    attr_1_b = (float)card_b.population;
    res_1 = attr_1_a > attr_1_b ? 1 : 0;
    break;
  case 20: //Área
    attr_1_a = (float)card_a.area;
    attr_1_b = (float)card_b.area;
    res_1 = attr_1_a > attr_1_b ? 1 : 0;
    break;
  case 30: //PIB
    attr_1_a = (float)card_a.pib;
    attr_1_b = (float)card_b.pib;
    res_1 = attr_1_a > attr_1_b ? 1 : 0;
    break;
  case 40: //Pontos Turísticos
    attr_1_a = (float)card_a.turistic_points;
    attr_1_b = (float)card_b.turistic_points;
    res_1 = attr_1_a > attr_1_b ? 1 : 0;
    break;
  case 50: //Densidade Populacional
    attr_1_a = (float)card_a.population_density;
    attr_1_b = (float)card_b.population_density;
    res_1 = attr_1_a < attr_1_b ? 1 : 0;
    break;
  case 60: //PIB per Capita
    attr_1_a = (float)card_a.pib_per_capita;
    attr_1_b = (float)card_b.pib_per_capita;
    res_1 = attr_1_a > attr_1_b ? 1 : 0;
    break;
  }

  //Comparações do Atributo 2
  switch (atribute_2.code)
  {
  case 10: //População
    attr_2_a = (float)card_a.population;
    attr_2_b = (float)card_b.population;
    res_2 = attr_2_a > attr_2_b ? 1 : 0;
    break;
  case 20: //Área
    attr_2_a = (float)card_a.area;
    attr_2_b = (float)card_b.area;
    res_2 = attr_2_a > attr_2_b ? 1 : 0;
    break;
  case 30: //PIB
    attr_2_a = (float)card_a.pib;
    attr_2_b = (float)card_b.pib;
    res_2 = attr_2_a > attr_2_b ? 1 : 0;
    break;
  case 40: //Pontos Turísticos
    attr_2_a = (float)card_a.turistic_points;
    attr_2_b = (float)card_b.turistic_points;
    res_2 = attr_2_a > attr_2_b ? 1 : 0;
    break;
  case 50: //Densidade Populacional
    attr_2_a = (float)card_a.population_density;
    attr_2_b = (float)card_b.population_density;
    res_2 = attr_2_a > attr_2_b ? 1 : 0;
    break;
  case 60: //PIB per Capita
    attr_2_a = (float)card_a.pib_per_capita;
    attr_2_b = (float)card_b.pib_per_capita;
    res_2 = attr_2_a > attr_2_b ? 1 : 0;
    break;
  }

  //Soma dos atributos de cada carta
  float soma_card_a, soma_card_b;

  soma_card_a = attr_1_a + attr_1_a;
  soma_card_b = attr_2_a + attr_2_b;

  //Exibir resultados
  printf("\n--------RESULTADOS----------\n");
  printf("Carta %s X Carta %s\n"
    "Atributo 1: %s\nCarta 1: %2.f | Carta 2: %2.f\n\n" //Corrigir empates
    "Atributo 2: %s\nCarta 1: %2.f | Carta 2: %2.f\n\n"
    "Somas:\n\n"
    "Carta 1: %2.f\n"
    "Carta 2: %2.f\n"
    "Resultado Final\n\n",
    card_a.city_name,
    card_b.city_name,
    atribute_1.nome,
    attr_1_a,
    attr_1_b,
    atribute_2.nome,
    attr_2_a,
    attr_2_b,
    soma_card_a,
    soma_card_b
  );

  //Resultado Final
  if(soma_card_a == soma_card_b)
    printf("Houve um empate!\n");
  else
  {
    printf("Carta %d venceu a disputa!\n", soma_card_a > soma_card_b ? 1: 2);
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
