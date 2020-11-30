#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct // Armazenar informa��es do cliente
{
	char nome[30];
	int ano;
	float montante_compras;
} cliente;

int main(int argc, char *argv[]) {
	// Declara��o de vari�veis	
	int tamanho = sizeof(cliente);
	cliente *cadastro; // Ponteiro para vetor de vari�veis tipo cliente
	int quantidade_cadastros = 0; // Contador de cadastros
	// Reserva espa�o para 10 cadastros do tipo cliente
	cadastro = (cliente *)malloc(20*tamanho);
	// Tratamento de erro na aloca��o
	if (cadastro == NULL)
	{
		printf("ERRO: Mem�ria insuficiente");
	}
	else {
	// Executar sistema
		menu_inicial(cadastro, &quantidade_cadastros);
	}
	return 0;
}
// ========== Fim do main() =============
// Funcionalidades
void menu_inicial(cliente *cadastro_clientes, int *quantidade_cadastros) {
	int opcao; // Recebe o n�mero selecionado pelo usu�rio
	
	system("cls"); // Limpa a tela
	printf("Tamanh %d", sizeof(cadastro_clientes));
	printf("=== CADASTRO DE CLIENTES ===\n\n");
	printf("1 - Cadastrar novo cliente\n");
	printf("2 - Remover cliente\n");
	printf("3 - Registrar compra\n");
	printf("4 - Exibir compras de um determinado cliente\n");
	printf("5 - Exibir o cliente com maior montante\n");
	printf("6 - Virada de m�s: atualizar montantes\n");
	printf("\nSelecione uma op��o: ");
	scanf("%d", &opcao);
	switch (opcao)
	{
		case 1:
		 	incluir_cliente(cadastro_clientes, quantidade_cadastros);
		 	break;
		case 4: 
			listar_montante(cadastro_clientes, quantidade_cadastros);
			break;
		case 5:
			listar_melhor_comprador(cadastro_clientes, quantidade_cadastros);
			break;
		default:
			/* Digitou op��o inv�lida:
			Retorna ao estado inicial */
			menu_inicial(cadastro_clientes, quantidade_cadastros); 
			break;
	}
}
//----------------- incluir um novo cliente ---------------------
void incluir_cliente(cliente *cadastro_clientes, int *quantidade_cadastros) {
	int posicao = *quantidade_cadastros;
	system("cls"); // Limpa a tela
	printf("=== CADASTRO DE CLIENTES ===\n\n");
	// Confere se a lista est� cheia
	if (posicao % 10 == 0) // a lista estoura nos �ndices m�ltiplos de 10
	{
		// Realocar, adicionando mais 10 posi��es
		cadastro_clientes = realloc(cadastro_clientes, (posicao + 10)*sizeof(cliente));
	}	
	// Solicita dados para o cadastro
	// Nome do cliente
	printf("Insira o nome do cliente: ");
	scanf("%s", &cadastro_clientes[posicao].nome);
	// Ano de nascimento
	printf("\nInsira o ano de nascimento: ");
	scanf("%d", &cadastro_clientes[posicao].ano);
	// Montante inicial � zerado
	cadastro_clientes[posicao].montante_compras = 0.0;
	*quantidade_cadastros += 1; // Incrementa contador de cadastros
	printf("\n\nCadastro conclu�do na posi��o %d:", *quantidade_cadastros);
	printf("\nNome: %s\nAno de nascimento: %d\nMontante de compras: R$ %f\n\n", cadastro_clientes[posicao].nome, cadastro_clientes[posicao].ano, cadastro_clientes[posicao].montante_compras);
	system("pause");	
	menu_inicial(cadastro_clientes, quantidade_cadastros);
}
//------ remover cliente -----------
// se ( quantidade de clientes caia abaixo de uma dezena redonda)
// ent�o desalocar a �ltima dezena
//
// ----- atualizar o montante de compras do cliente realizadas no m�s corrente ---------------
// fun��o:
// Iterar por todo o vetor

//- zerar todos os montantes de compras por ocasi�o da virada de m�s
//
//- listar o cliente melhor comprador
void listar_melhor_comprador(cliente *cadastro_clientes, int *quantidade_cadastros) {
	cliente melhor_comprador = cadastro_clientes[0];
	int contador;
	system("cls"); // Limpa a tela
	printf("=== CADASTRO DE CLIENTES ===\n\n");
	if (*quantidade_cadastros == 0) {
		printf("Nenhum cliente cadastrado.\n\n");
		system("pause");	
		menu_inicial(cadastro_clientes, quantidade_cadastros);
	}
	else
	{
		printf("Pessoa com o maior volume de compras no m�s:\n\n");
		// itera da posi��o 2 (�ndice 1 no vetor) at� a posi��o final
		for (contador = 1; contador < *quantidade_cadastros; contador++)
		{
			if (cadastro_clientes[contador].montante_compras > melhor_comprador.montante_compras) {
				melhor_comprador = cadastro_clientes[contador];
			}
		}
		printf("\nNome: %s\nAno de nascimento: %d\nMontante de compras: R$ %f\n\n", melhor_comprador.nome, melhor_comprador.ano, melhor_comprador.montante_compras);
	}
}
//- exibir um montante de compras de um cliente espec�fico.
void listar_montante(cliente *cadastro_clientes, int *quantidade_cadastros) {
	char nome[30];
	int contador;
	int comparacao;
	system("cls"); // Limpa a tela
	printf("=== CADASTRO DE CLIENTES ===\n\n");
	if (*quantidade_cadastros == 0) {
		printf("Nenhum cliente cadastrado.\n\n");
		system("pause");	
		menu_inicial(cadastro_clientes, quantidade_cadastros);
	}
	else {
		printf("Buscar cliente\nInforme o nome do cliente: ");
		scanf("%s", &nome);
		for (contador = 0; contador < *quantidade_cadastros; contador++)
		{
			comparacao = strcmp(cadastro_clientes[contador].nome, nome);
			if (comparacao == 0) 
			{
				printf("\n\nMontante do cliente: %f",cadastro_clientes[contador].montante_compras);
				break;
			}
		}
		if (comparacao != 0) // N�o encontrou correspond�ncia
		{
			printf("\n\n Cliente n�o foi encontrado.\n");
		}
	}
}
//- atualizar o montante de compras de um cliente espec�fico.
void atualizar_montante(cliente *cadastro_clientes, int *quantidade_cadastros) {
	char nome[30];
	int contador;
	int comparacao;
	float adicao;
	cliente cliente_atual;
	system("cls"); // Limpa a tela
	printf("=== CADASTRO DE CLIENTES ===\n\n");
	if (*quantidade_cadastros == 0) {
		printf("Nenhum cliente cadastrado.\n\n");
		system("pause");	
		menu_inicial(cadastro_clientes, quantidade_cadastros);
	}
	else {
		printf("Buscar cliente\nInforme o nome do cliente: ");
		scanf("%s", &nome);
		for (contador = 0; contador < *quantidade_cadastros; contador++)
		{
			comparacao = strcmp(cadastro_clientes[contador].nome, nome);
			if (comparacao == 0) 
			{
				cliente_atual = cadastro_clientes[contador];
				break;
			}
		}
		if (comparacao != 0) // N�o encontrou correspond�ncia
		{
			printf("\n\n Cliente n�o foi encontrado.\n");
		}
	}
}


