#include "com112_file.h"
#include "com112_sort.h"

void criaArquivo()
{
	int n, i, a, b;
	FILE *arq;
	
	arq = fopen("com112_entrada.txt", "w");
	if (!arq) erro(); //Indica erro na manipula��o do arquivo
	
	printf("\n\n\t Gerar n�meros aleat�rios\n\n");
	printf(" Quantidade de n�meros: ");
	scanf("%d", &n);
	printf(" Insira um intervalo [a,b] para limitar os n�meros: ");
	scanf("%d %d", &a, &b);
	
	//Gerando n�meros aleat�rios e colocando no arquivo 'com112_entrada.txt'
	srand((unsigned)time(NULL));
	
	fprintf(arq,"%d\n", n);
	for (i = 0; i < n; i++)
	{
		fprintf(arq, "%d ", a + rand() % (b-a));
	}
	fclose(arq);
}

void gravaResultado(int vet[], int n)
{
	int i;
	FILE *write;
	
	write = fopen("com112_saida.txt", "w");
	if (!write) erro();
	
	fprintf(write, "%d\n", n);
	for (i = 0; i < n; i++)
	{
		fprintf(write, "%d ", vet[i]);
	}
	fclose(write);
}

void erro()
{
	printf("\n\n Houve um erro, na manipula��o d arquivo. Por favor, tente novamente!\n\n");
	Sleep(60);
	exit(0);
}

FILE *CriaArquivo_Relatorio()
{
	FILE *arq;
	arq = fopen("com112_relatorio.txt", "w");
	if (!arq) erro();
	
	return arq;	
}
