//Érick de Oliveira Teixeira
//2017001437
//COM112 - Atividade 2 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define qnt_func 10 //Quantidade de funcionários a serem cadastrados

typedef struct Funcionario
{
	char nome[40];
	float salario;
}funcionario;

int main(void)
{
	int i, j;
	funcionario func[qnt_func];

	setlocale(LC_ALL, "Portuguese");

	for (i = 0; i < qnt_func; i++) //Lendo informações dos funcionários
	{
		printf("\t Cadastro do Funcionário N° %d:\n\n", i+1);
		printf("Nome: ");
		scanf(" %s", &func[i].nome);
		printf("Salário: ");
		scanf(" %f", &func[i].salario);
		fflush(stdin);
		printf("\n");
	}

	//Ordenando por ordem decrescente de salário
	
	printf("\nOrdenando funcionários por ordem decrescente de salário:\n\n\n");

	int troca = 1, cont = 1;
	funcionario aux;

	while (cont <= qnt_func && troca == 1) //Implementação Bubble Sort decrescente
	{
		troca = 0;
		for (i = 0; i <= qnt_func-1; i++)
		{
			if (func[i].salario < func[i+1].salario)
			{
				troca = 1;
				aux = func[i];
				func[i] = func[i+1];
				func[i+1] = aux;
			}
		}
		cont++;
	}
	
	for (i = 0; i < qnt_func; i++)
	{
		printf("Nome: %s\n", func[i].nome);
		printf("Salário: %.2f\n\n", func[i].salario);
	}
	
	//Ordenando por ordem alfabética
	
	printf("\nFuncionários ordenados por ordem alfabética:\n\n\n");
	
	troca = 1;
	cont = 1;
	
	while (cont <= qnt_func && troca == 1) //Implementação do Bubble Sort crescente
	{
		troca = 0;
		for (i = 0; i < qnt_func-1; i++)
		{	
			if (strcmp (func[i].nome , func[i+1].nome) > 0)
			{
				troca = 1;
				aux = func[i];
				func[i] = func[i+1];
				func[i+1] = aux;
			}
		}
		cont++;
	}
	
	for (i = 0; i < qnt_func; i++)
	{
		printf("Nome: %s\n", func[i].nome);
		printf("Salário: %.2f\n\n", func[i].salario);
	}
	
	return 0;	
}
