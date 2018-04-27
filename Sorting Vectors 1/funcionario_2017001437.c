//�rick de Oliveira Teixeira
//2017001437
//COM112 - Atividade 2 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define qnt_func 10 //Quantidade de funcion�rios a serem cadastrados

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

	for (i = 0; i < qnt_func; i++) //Lendo informa��es dos funcion�rios
	{
		printf("\t Cadastro do Funcion�rio N� %d:\n\n", i+1);
		printf("Nome: ");
		scanf(" %s", &func[i].nome);
		printf("Sal�rio: ");
		scanf(" %f", &func[i].salario);
		fflush(stdin);
		printf("\n");
	}

	//Ordenando por ordem decrescente de sal�rio
	
	printf("\nOrdenando funcion�rios por ordem decrescente de sal�rio:\n\n\n");

	int troca = 1, cont = 1;
	funcionario aux;

	while (cont <= qnt_func && troca == 1) //Implementa��o Bubble Sort decrescente
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
		printf("Sal�rio: %.2f\n\n", func[i].salario);
	}
	
	//Ordenando por ordem alfab�tica
	
	printf("\nFuncion�rios ordenados por ordem alfab�tica:\n\n\n");
	
	troca = 1;
	cont = 1;
	
	while (cont <= qnt_func && troca == 1) //Implementa��o do Bubble Sort crescente
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
		printf("Sal�rio: %.2f\n\n", func[i].salario);
	}
	
	return 0;	
}
