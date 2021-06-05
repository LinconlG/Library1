#include <stdio.h>
#include <stdlib.h>
#define MAX 100


typedef struct cadastro
{
	char titulo[50];
	int quantidade;
	int caixa;
	int tipo;
	int isbn;
	char editora[20];
	char autor[20];
	int edicao;
} CadastroObra;


void cabecalho();
void cadastrarObra(CadastroObra obra[MAX]);
void ListarObrasCaixa(int buscaCaixa, CadastroObra obra[MAX]);
void ListarObrasTipo(int buscaTipo, CadastroObra obra[MAX]);
int contarCadastro(CadastroObra obra[MAX]);

int main()
{

	CadastroObra obra[MAX];
	
	int opcao, buscaTipo, buscaCaixa;
	
	do{
		cabecalho();
		printf("\n1 - Cadastrar obras");
		printf("\n2 - Listar obra por caixa");
		printf("\n3 - Listar obra por tipo");
		printf("\n5 - Sair");
		printf("\nEscolha Opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				cadastrarObra(obra);
			break;
			case 2: 		
				printf("Informe a caixa que deseja exibir: ");
				fflush(stdin);
				scanf("%d", &buscaCaixa);
				ListarObrasCaixa(buscaCaixa, obra);
				printf("\n");
				getch();
			break;
			case 3: 
				printf("Informar Livro(1) ou Revista(2) ? ");
				fflush(stdin);
				scanf("%d", &buscaTipo);
				ListarObrasTipo(buscaTipo, obra);
				printf("\n");
				getch();
			break;
			case 5:
				printf("\nObrigado pela visita...");
				getch();
			break;
			default:
				printf("\n opcao invalida!");
				getch();
			break;
		}
	}while(opcao != 5);

	return 0;
}

void cabecalho(){
	system("cls");
	printf("------------------------------------------------------------- \n    20064277-5 \n LINCONL VIEIRA GARCIA \n ENGENHARIA DE SOFTWARE \n-------------------------------------------------------------");
}
void cadastrarObra(CadastroObra obra[MAX])
{
	cabecalho();
	int op2;
	int i;
	FILE * arq;
 
	arq = fopen("arquivomapa.txt", "a+");

	if(arq == NULL)
	{
		printf("\nErro ao abrir o arquivo \n");
		exit(1); 
	}
	
	do{
		
		printf("\nInforme o numero do item (comecando com 0): ");
		scanf("%d", &i);
			fflush(stdin);
		printf("\nTitulo:  ");
		gets(obra[i].titulo);
			fflush(stdin);
		printf("\nInforme a caixa: ");
		scanf("%d", &obra[i].caixa);
			fflush(stdin);
		printf("\nLivro(1) ou Revista(2) ? ");
		scanf("%d", &obra[i].tipo);
			fflush(stdin);
		printf("\nInforme a quantidade: ");
			fflush(stdin);
		scanf("%d", &obra[i].quantidade);
			fflush(stdin);
		printf("\nInforme o autor: ");
		gets(obra[i].autor);
			fflush(stdin);
		printf("\nInforme a editora: ");
		gets(obra[i].editora);
			fflush(stdin);
		printf("\nInforme a edicao: ");
		scanf("%d", &obra[i].edicao);
			fflush(stdin);
		printf("\nInforme ISBN: ");
		scanf("%d", &obra[i].isbn);
			fflush(stdin);
		fwrite(&obra[i], sizeof(CadastroObra), 1, arq);
		
		printf("\n quer cadastrar outra obra? \n  1- SIM   2- NAO \n ");
		scanf("%d", &op2);
		
	}while(op2 != 2);
		fclose(arq); 
}

int contarCadastros(CadastroObra obra[MAX])
{
	FILE * arq = fopen("arquivomapa.txt", "r");

	if(arq == NULL)
	{
		printf("\nErro ao abrir o arquivo \n");
		exit(1); 
	}

	int contagem = 0;
	while(1)
	{
			CadastroObra n;
		
			
			int cadastro = fread(&n, sizeof(CadastroObra), 1, arq);
			
			
			if(cadastro < 1)
				break;
			else
				obra[contagem] = n;
			contagem++;
	}
		fclose(arq); 
		return contagem;
}


void ListarObrasCaixa(int buscaCaixa, CadastroObra obra[MAX]){	
	cabecalho();
	
	int quantidadeObra = contarCadastros(obra);
	int i;
	
	
	for(i = 0; i < quantidadeObra; i++)
	{
		if(obra[i].caixa == buscaCaixa){
			
			printf("\nTitulo: %s \nAutor: %s \nEditora: %s \nEdicao: %d \nQuantidade: %d \nCaixa: %d \nISBN: %d \nTipo: %d \n \n ******************************************** \n \n", obra[i].titulo, obra[i].autor, obra[i].editora, obra[i].edicao, obra[i].quantidade, obra[i].caixa, obra[i].isbn, obra[i].tipo);
				
		}
	}
}
void ListarObrasTipo(int buscaTipo, CadastroObra obra[MAX]){
	cabecalho();
	
	int quantidadeObra = contarCadastros(obra);
	int i;
	
	
	for(i = 0; i < quantidadeObra; i++)
	{
		if(obra[i].tipo == buscaTipo){
			
			printf("\nTitulo: %s \nAutor: %s \nEditora: %s \nEdicao: %d \nQuantidade: %d \nCaixa: %d \nISBN: %d \nTipo: %d \n \n ******************************************** \n \n", obra[i].titulo, obra[i].autor, obra[i].editora, obra[i].edicao, obra[i].quantidade, obra[i].caixa, obra[i].isbn, obra[i].tipo);
				
		}
	}
}
