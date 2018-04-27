#include "com112_file.h"
#include "com112_sort.h"

int menu(void); //Menu Interativo
void relatorio(int comp, int mov, double tempo); //Imprime dados estatíticos
void relatorioGeral(int backup[], int n); //Arquivo de comparação entre os métodos

//--------------------------------------------------------------------------------------------
//--RECOMENDAÇÃO:
//--Para vetores grandes (Ex. 50000) ordenados com métodos menos eficientes (Ex. Bubble Sort),
//--usar o tipo long int para as variáveis mov e comp, para evitar o problema de overflow.
//--------------------------------------------------------------------------------------------

int main(void)
{
	int op, flag;
	setlocale(LC_ALL, "Portuguese");
	
	printf("\t Ordenação de vetores\n\n");
	printf(" 1 - Usar arquivo 'com112_entrada.txt' como entrada\n");
	printf(" 2 - Gerar novo arquivo com números aleatórios\n\n");
	printf(" Opção desejada: ");
	scanf("%d", &op);
	
	switch (op)
	{
		case 1:
			break;
		case 2:
			criaArquivo(); //Gerar números aleatorios para 'com112_entrada.txt'
			break;
		default:
			printf("\n\n Insira uma opção válida!!\n\n\n");
			main();
	}
	
	flag = menu(); 	//A variável flag indica qual algoritmo de ordenação usar
	
	//Armazenando os dados de entrada em um vetor:
	int i, n;
	freopen("com112_entrada.txt", "r", stdin);
	
	scanf("%d", &n); //Tamanho do vetor
	int vet[n]; //Aloacando o vetor com o tamanho necessário
	for (i = 0; i < n; i++)
	{
		scanf("%d", &vet[i]);
	}
	
	int backup[n]; //Cópia identica do vetor de entrada para cálculo de dados estatísticos
	for (i = 0; i < n; i++)
	{
		backup[i] = vet[i];
	}
	
	int comp = 0, mov = 0;
	double tempo;
	clock_t inicio, fim;

	
	//Direcionando o vetor para ser ordenado de acordo com o algoritmo escolhido
	switch (flag)
	{
		case 1:
			BubbleSort(vet, n, &comp, &mov, &tempo); //Ordena com Bubble Sort
			gravaResultado(vet, n); //Grava em 'com112_saida.txt'
			relatorio(comp, mov, tempo); //Imprime relatório da tela
			break;
		case 2:
			SelectionSort(vet, n, &comp, &mov, &tempo); //Ordena com Selection Sort
			gravaResultado(vet, n); //Grava em 'com112_saida.txt'
			relatorio(comp, mov, tempo); //Imprime relatório da tela
			break;
		case 3:
			InsertionSort(vet, n, &comp, &mov, &tempo); //Ordena com Insertion Sort
			gravaResultado(vet, n); //Grava em 'com112_saida.txt'
			relatorio(comp, mov, tempo); //Imprime relatório da tela
			break;
		case 4:
			inicio = clock(); //Marca início do Merge Sort
			mergeSort(vet, 0, (n-1), &comp, &mov); //Ordena com Merge Sort
			fim = clock(); //Marca fim do Merge Sort
			tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC; //Calcula tempo de execução
			relatorio(comp, mov, tempo); //Imprime relatório da tela
			gravaResultado(vet, n); //Grava em 'com112_saida.txt'
			break;
		case 5:
			inicio = clock(); //Marca início do Quick Sort
			quickSort(vet, 0, (n-1), &comp, &mov);//Ordena com Quick Sort
			fim = clock(); //Marca fim do Quick Sort
			gravaResultado(vet, n); //Grava em 'com112_saida.txt'
			tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC; //Calcula tempo de execução
			printf("\n\nTempo: %lf\n\n", tempo);
			relatorio(comp, mov, tempo);  //Imprime relatório da tela
			//system("com112_saida.txt");
			break;
	} 
	
	//Criando Relatório de comparação entre os algoritmos
	relatorioGeral(backup, n);
	
	return 0;
}

int menu(void)
{
	int op;
	
	printf("\n\n\t Escolha um algoritmo para ordenar\n\n");
	printf(" 1 - Bubble Sort\n");
	printf(" 2 - Selection Sort\n");
	printf(" 3 - Insertion Sort\n");
	printf(" 4 - Merge Sort\n");
	printf(" 5 - Quick Sort\n\n");
	printf(" Opção desejada: ");
	scanf("%d", &op);
	
	switch (op)
	{
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 3;
		case 4:
			return 4;
		case 5:
			return 5;
		default:
			printf("\n\n Insira uma opção válida!!\n\n");
			menu();
	}	
}

void relatorio(int comp, int mov, double tempo)
{
	printf("\n\n");
	printf(" Vetor Ordenado!!\n\n");
	printf(" Confira o vetor ordenado no arquivo 'com112_saida.txt'\n");
	printf(" Confira a comparação entre os algoritmos no arquivo 'com112_relatorio.txt'\n\n");
	printf("\n Estatísticas do algoritmo escolhido:\n\n");
	printf(" Tempo de execução: %lf s\n", tempo);
	printf(" Número de comparações entre elementos do vetor: %d\n", comp);
	printf(" Número de movimentações entre elementos do vetor: %d\n\n", mov);
}

void relatorioGeral(int backup[], int n)
{
	int i, comp = 0, mov = 0;
	double tempo;
	FILE *arq = CriaArquivo_Relatorio();
	int vet[n];
	
	for (i = 0; i < n; i++) //Preenchendo o vetor vet[] com dados do vetor backup[]
	{
		vet[i] = backup[i];
	}
	
	//Dados Estatísticos para o método Bubble Sort
	fprintf(arq, "Número de elementos ordenados: %d\n\n", n);
	fprintf(arq, "Método Bubble Sort\n\n");
	BubbleSort(vet, n, &comp, &mov, &tempo);
	fprintf(arq, "Tempo de execução: %lf s\n", tempo);
	fprintf(arq, "Número de comparações: %d\n", comp);
	fprintf(arq, "Número de movimentações: %d\n\n", mov);
	comp = mov = 0;
	
	for (i = 0; i < n; i++) //Preenchendo o vetor vet[] com dados do vetor backup[]
	{
		vet[i] = backup[i];
	}
	
	//Dados estatísticos para o método Selection Sort
	fprintf(arq, "Método Selection Sort\n\n");	
	SelectionSort(vet, n, &comp, &mov, &tempo);
	fprintf(arq, "Tempo de execução: %lf s\n", tempo);
	fprintf(arq, "Número de comparações: %d\n", comp);
	fprintf(arq, "Número de movimentações: %d\n\n", mov);
	comp = mov = 0;
	
	for (i = 0; i < n; i++) //Preenchendo o vetor vet[] com dados do vetor backup[]
	{
		vet[i] = backup[i];
	}
	
	//Dados estatísticos para o método Insertion Sort
	fprintf(arq, "Método Insertion Sort\n\n");
	InsertionSort(vet, n, &comp, &mov, &tempo);
	fprintf(arq, "Tempo de execução: %lf s\n", tempo);
	fprintf(arq, "Número de comparações: %d\n", comp);
	fprintf(arq, "Número de movimentações: %d\n\n", mov);
	comp = mov = 0;
	
	for (i = 0; i < n; i++) //Preenchendo o vetor vet[] com dados do vetor backup[]
	{
		vet[i] = backup[i];
	}
	
	//Dados estatíscos para o método Merge Sort
	fprintf(arq, "Método Merge Sort\n\n");
	clock_t inicio, fim;
	inicio = clock();
	mergeSort(vet, 0, (n-1), &comp, &mov);
	fim = clock();
	tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
	fprintf(arq, "Tempo de execução: %lf s\n", tempo);
	fprintf(arq, "Número de comparações: %d\n", comp);
	fprintf(arq, "Número de movimentações: %d\n\n", mov);
	comp = mov = 0;
	
	for (i = 0; i < n; i++) //Preenchendo o vetor vet[] com dados do vetor backup[]
	{
		vet[i] = backup[i];
	}
	
	//Dados estatísticos para o Método Quick Sort
	fprintf(arq, "Método Quick Sort\n\n");
	clock_t inicio2, fim2;
	inicio2 = clock();
	quickSort(vet, 0, (n-1), &comp, &mov);
	fim2 = clock();
	tempo = ((double)(fim2-inicio2))/CLOCKS_PER_SEC;
	fprintf(arq, "Tempo de execução: %lf s\n", tempo);
	fprintf(arq, "Número de comparações: %d\n", comp);
	fprintf(arq, "Número de movimentações: %d\n\n", mov);
	fclose(arq);
}
