//Érick de Oliveira Teixeira
//2017001437
//COM112 - Atividade 2 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Produto
{
	int codigo;
	float preco;
	char desc[30];
}produto;


int main(void)
{
	int i, n;
	
	printf("Quantidade de produtos a cadastrar: ");
	scanf("%d", &n);
	printf("\n");
	setlocale(LC_ALL,"Portuguese");
	
	produto prod[n];
	
	for (i = 0; i < n; i++) //Leitura dos dados
	{
		fflush(stdin);
		printf("Produto %d:\n\n", i+1);
		printf("Código: ");
		scanf("%d", &prod[i].codigo);
		printf("Nome: ");
		scanf(" %s", &prod[i].desc);
		printf("Preço: ");
		scanf("%f", &prod[i].preco);
		fflush(stdin);
		printf("\n");
	}
	
	int troca = 1, cont = 1;
	produto aux;
	
	while (cont <= n && troca == 1) //Implementação do Bubble Sort
	{
		troca = 0;
		for (i = 0; i < n-1; i++)
		{	
			if (strcmp (prod[i].desc , prod[i+1].desc) > 0)
			{
				troca = 1;
				aux = prod[i];
				prod[i] = prod[i+1];
				prod[i+1] = aux;
			}
		}
		cont++;
	}
	
	printf("\nProdutos em ordem alfabética:\n\n"); //Mostrando resultados
	for (i = 0; i < n; i++)
	{
		printf("%d\n", prod[i].codigo);
		printf("%s\n", prod[i].desc);
		printf("%.2f\n\n", prod[i].preco);
	}	
	
	int cod, flag = 0, k = 0;
	printf("Digite o código de um produto para busca sequencial no vetor ordenado alfabeticamente: "); 
	scanf("%d", &cod);
	
	for (i = 0; i < n; i++) //Realiza busca sequencial por código
	{
		k++;
		if (prod[i].codigo == cod)
		{
			flag = 1;
			printf("\n");
			printf("Código: %d\n", prod[i].codigo);
			printf("Descrição: %s\n", prod[i].desc);
			printf("Preço: %.2f\n", prod[i].preco);
			printf("N° de comparações: %d\n\n", k);
			break;
		}
	}
	if (flag == 0) printf("\nProduto não encontrado.\n\n");
	
	return 0;		
}
