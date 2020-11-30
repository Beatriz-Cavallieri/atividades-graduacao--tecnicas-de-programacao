#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Declaração da estrutura struct que contém os dados de um veículo

struct veiculo {
	char marca[20];
	char modelo[20];
	int ano;
	char placa[7];
};

/****************************************************************/
// main

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	int quantidade = 0;
	int opcao;
	struct veiculo lista_veiculos[10];
	int opcao_menu;
	printf("====== CADASTRO DE VEÍCULOS ======\n\n");
	printf("Selecione uma opção:\n\n");
	printf("1 - Adicionar um veículo\n");
	printf("2 - Listar todos os veículos\n");
	printf("3 - Filtrar pelo ano de fabricação\n");
	printf("4 - Filtrar pelo modelo\n\n");
	scanf("%d", &opcao_menu);	

	switch(opcao_menu)
	{
		case 1:
			adicionar_veiculo(lista_veiculos, &quantidade);
			break;
		case 2:
			listar_veiculos_cadastrados(lista_veiculos, quantidade);
			break;
		case 3:
			menu_filtro_ano(lista_veiculos, quantidade);
			break;	
		case 4:
			listar_veiculos_modelo(lista_veiculos, quantidade);
			break;
		default:
		//	system("cls"); 
			printf("\n\n ERRO: Opção inválida. Selecione uma opção válida\n\n");
			scanf("%d", &opcao_menu);
			break;	
	}	
	
		
	return 0;
}
/****************************************************************/
// Declaração de funções


// Lista todos os veículos que estão cadastrados
void listar_veiculos_cadastrados(struct veiculo v[], int quantidade) {
	if (quantidade == 0) {
		printf("Cadastro vazio.\n");
	}
	else {
		int i;
		for (i = 0; i <= quantidade; i++) {
			printf("Marca: %s\nModelo: %s\nAno: %d\nPlaca: %s\n\n", v[i].marca,  v[i].modelo,  v[i].ano,  v[i].placa);			
		}
	}
}

// Adiciona um novo veículo ao cadastro
void adicionar_veiculo(struct veiculo lista[], int *quantidade) {
	int quantidade_inicial = *quantidade;
	struct veiculo novo;
	if (quantidade_inicial >= 10 ) {
		printf("ERRO: Limite de cadastro atingido/n");
	}
	else {
		printf("Digite a marca do veículo:\n");
		scanf("%d", &novo.marca);
		printf("\nDigite o modelo do veículo:\n");
		scanf("%d", &novo.modelo);
		printf("\nDigite o ano do veículo:\n");
		scanf("%d", &novo.ano);
		printf("\nDigite a placa do veículo:\n");
		scanf("%d", &novo.placa);
		
		lista[quantidade_inicial] = novo;
		*quantidade = quantidade_inicial + 1;	
		printf("Adicionado carro de placa %s na posição %d de cadastro\n\n", lista[quantidade_inicial].placa, quantidade_inicial + 1);
	}
}

// Listar os veículos filtrando por ano de fabricação
void listar_veiculos_ano_exato(struct veiculo v[], int quantidade, int ano) {
	if (quantidade == 0) {
		printf("Cadastro vazio.\n\n");
	}
	else {
		printf("Veículos do ano %d no cadastro:\n\n", ano);
		int i;
		for (i = 0; i <= quantidade; i++) {
			if (v[i].ano == ano) {
		printf("Marca: %s\nModelo: %s\nPlaca: %s\n\n", v[i].marca,  v[i].modelo,  v[i].placa);			}
			
		}
	}
}
// Listar veículos com o ano de fabricação acima de um certo valor especificado pelo usuário
void listar_veiculos_ano_minimo(struct veiculo v[], int quantidade, int ano) {
	if (quantidade == 0) {
		printf("Cadastro vazio.\n\n");
	}
	else {
		printf("Veículos de anos a partir do ano %d no cadastro:\n\n", ano);
		int i;
		for (i = 0; i <= quantidade; i++) {
			if (v[i].ano >= ano) {
				printf("Marca: %s\nModelo: %s\nAno: %d\nPlaca: %s\n\n", v[i].marca,  v[i].modelo,  v[i].ano,  v[i].placa);				
			}
		}
	}
}
// Listar os veículos filtrando-se pelo modelo
void listar_veiculos_modelo(struct veiculo v[], int quantidade) {
	char modelo[20];
	system("cls"); 
	printf("Digite o modelo: ");
	scanf("%d", &modelo);
	if (quantidade == 0) {
		printf("Cadastro vazio.\n\n");
	}
	else {
		printf("Veículos do modelo %s no cadastro:\n\n", modelo);
		int i;
		for (i = 0; i <= quantidade; i++) {
			int compara_modelo = strcmp(v[i].modelo, modelo); 
			if (compara_modelo == 0) {
				printf("Ano: %d\nPlaca: %s\n\n", v[i].ano,  v[i].placa);				
			}
			
		}
	}
}
void menu_filtro_ano(struct veiculo v[], int quantidade) {
	system("cls"); 
	int opcao = 0, ano = 0;
	printf("=== Busca de veículos pelo ano de fabricação ===\n\n");
	printf("Selecione a forma de busca:\n");
	printf("1 - Busca pelo ano exato\n");
	printf("2 - Busca pelo ano mínimo\n");
	printf("3 - Busca pelo ano máximo\n\n");
	scanf("%d", &opcao);
	system("cls");
	printf("=== Busca de veículos pelo ano ===\n\n");
	switch(opcao)
	{
		case 1:
			printf("Digite o ano: ");
			scanf("%d", &ano);
			break;
		case 2:
			printf("Digite o ano mínimo: ");
			scanf("%d", &ano);
			break;
		case 3:
			printf("Digite o ano máximo: ");
			scanf("%d", &ano);
		default: 
			printf("\n\n ERRO: Opção inválida.");
			break;	
	}		
}

/**************** FIM DO PROGRAMA ******************/
