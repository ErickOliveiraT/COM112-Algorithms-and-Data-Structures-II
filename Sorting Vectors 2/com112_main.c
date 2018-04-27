#include "com112_file.h"
#include "com112_sort.h"

int menu(void); //Menu Interativo
void relatorio(int comp, int mov, double tempo); //Imprime dados estat�ticos
void relatorioGeral(int backup[], int n); //Arquivo de compara��o entre os m�todos

//--------------------------------------------------------------------------------------------
//--RECOMENDA��O:
//--Para vetores grandes (Ex. 50000) ordenados com m�todos menos eficientes (Ex. Bubble Sort),
//--usar o tipo long int para as vari�veis mov e comp, para evitar o problema de overflow.
//--------------------------------------------------------------------------------------------

int main(void)
{
	int op, flag;
	setlocale(LC_ALL, "Portuguese");
	
	printf("\t Ordena��o de vetores\n\n");
	printf(" 1 - Usar arquivo 'com112_entrada.txt' como entrada\n");
	printf(" 2 - Gerar novo arquivo com n�meros aleat�rios\n\n");
	printf(" Op��o desejada: ");
	scanf("%d", &op);
	
	switch (op)
	{
		case 1:
			break;
		case 2:
			criaArquivo(); //Gerar n�meros aleatorios para 'com112_entrada.txt'
			break;
		default:
			printf("\n\n Insira uma op��o v�lida!!\n\n\n");
			main();
	}
	
	flag = menu(); 	//A vari�vel flag indica qual algoritmo de ordena��o usar
	
	//Armazenando os dados de entrada em um vetor:
	int i, n;
	freopen("com112_entrada.txt", "r", stdin);
	
	scanf("%d", &n); //Tamanho do vetor
	int vet[n]; //Aloacando o vetor com o tamanho necess�rio
	for (i = 0; i < n; i++)
	{
		scanf("%d", &vet[i]);
	}
	
	int backup[n]; //C�pia identica do vetor de entrada para c�lculo de dados estat�sticos
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
			relatorio(comp, mov, tempo); //Imprime relat�rio da tela
			break;
		case 2:
			SelectionSort(vet, n, &comp, &mov, &tempo); //Ordena com Selection Sort
			gravaResultado(vet, n); //Grava em 'com112_saida.txt'
			relatorio(comp, mov, tempo); //Imprime relat�rio da tela
			break;
		case 3:
			InsertionSort(vet, n, &comp, &mov, &tempo); //Ordena com Insertion Sort
			gravaResultado(vet, n); //Grava em 'com112_saida.txt'
			relatorio(comp, mov, tempo); //Imprime relat�rio da tela
			break;
		case 4:
			inicio = clock(); //Marca in�cio do Merge Sort
			mergeSort(vet, 0, (n-1), &comp, &mov); //Ordena com Merge Sort
			fim = clock(); //Marca fim do Merge Sort
			tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC; //Calcula tempo de execu��o
			relatorio(comp, mov, tempo); //Imprime relat�rio da tela
			gravaResultado(vet, n); //Grava em 'com112_saida.txt'
			break;
		case 5:
			inicio = clock(); //Marca in�cio do Quick Sort
			quickSort(vet, 0, (n-1), &comp, &mov);//Ordena com Quick Sort
			fim = clock(); //Marca fim do Quick Sort
			gravaResultado(vet, n); //Grava em 'com112_saida.txt'
			tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC; //Calcula tempo de execu��o
			printf("\n\nTempo: %lf\n\n", tempo);
			relatorio(comp, mov, tempo);  //Imprime relat�rio da tela
			//system("com112_saida.txt");
			break;
	} 
	
	//Criando Relat�rio de compara��o entre os algoritmos
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
	printf(" Op��o desejada: ");
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
			printf("\n\n Insira uma op��o v�lida!!\n\n");
			menu();
	}	
}

void relatorio(int comp, int mov, double tempo)
{
	printf("\n\n");
	printf(" Vetor Ordenado!!\n\n");
	printf(" Confira o vetor ordenado no arquivo 'com112_saida.txt'\n");
	printf(" Confira a compara��o entre os algoritmos no arquivo 'com112_relatorio.txt'\n\n");
	printf("\n Estat�sticas do algoritmo escolhido:\n\n");
	printf(" Tempo de execu��o: %lf s\n", tempo);
	printf(" N�mero de compara��es entre elementos do vetor: %d\n", comp);
	printf(" N�mero de movimenta��es entre elementos do vetor: %d\n\n", mov);
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
	
	//Dados Estat�sticos para o m�todo Bubble Sort
	fprintf(arq, "N�mero de elementos ordenados: %d\n\n", n);
	fprintf(arq, "M�todo Bubble Sort\n\n");
	BubbleSort(vet, n, &comp, &mov, &tempo);
	fprintf(arq, "Tempo de execu��o: %lf s\n", tempo);
	fprintf(arq, "N�mero de compara��es: %d\n", comp);
	fprintf(arq, "N�mero de movimenta��es: %d\n\n", mov);
	comp = mov = 0;
	
	for (i = 0; i < n; i++) //Preenchendo o vetor vet[] com dados do vetor backup[]
	{
		vet[i] = backup[i];
	}
	
	//Dados estat�sticos para o m�todo Selection Sort
	fprintf(arq, "M�todo Selection Sort\n\n");	
	SelectionSort(vet, n, &comp, &mov, &tempo);
	fprintf(arq, "Tempo de execu��o: %lf s\n", tempo);
	fprintf(arq, "N�mero de compara��es: %d\n", comp);
	fprintf(arq, "N�mero de movimenta��es: %d\n\n", mov);
	comp = mov = 0;
	
	for (i = 0; i < n; i++) //Preenchendo o vetor vet[] com dados do vetor backup[]
	{
		vet[i] = backup[i];
	}
	
	//Dados estat�sticos para o m�todo Insertion Sort
	fprintf(arq, "M�todo Insertion Sort\n\n");
	InsertionSort(vet, n, &comp, &mov, &tempo);
	fprintf(arq, "Tempo de execu��o: %lf s\n", tempo);
	fprintf(arq, "N�mero de compara��es: %d\n", comp);
	fprintf(arq, "N�mero de movimenta��es: %d\n\n", mov);
	comp = mov = 0;
	
	for (i = 0; i < n; i++) //Preenchendo o vetor vet[] com dados do vetor backup[]
	{
		vet[i] = backup[i];
	}
	
	//Dados estat�scos para o m�todo Merge Sort
	fprintf(arq, "M�todo Merge Sort\n\n");
	clock_t inicio, fim;
	inicio = clock();
	mergeSort(vet, 0, (n-1), &comp, &mov);
	fim = clock();
	tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
	fprintf(arq, "Tempo de execu��o: %lf s\n", tempo);
	fprintf(arq, "N�mero de compara��es: %d\n", comp);
	fprintf(arq, "N�mero de movimenta��es: %d\n\n", mov);
	comp = mov = 0;
	
	for (i = 0; i < n; i++) //Preenchendo o vetor vet[] com dados do vetor backup[]
	{
		vet[i] = backup[i];
	}
	
	//Dados estat�sticos para o M�todo Quick Sort
	fprintf(arq, "M�todo Quick Sort\n\n");
	clock_t inicio2, fim2;
	inicio2 = clock();
	quickSort(vet, 0, (n-1), &comp, &mov);
	fim2 = clock();
	tempo = ((double)(fim2-inicio2))/CLOCKS_PER_SEC;
	fprintf(arq, "Tempo de execu��o: %lf s\n", tempo);
	fprintf(arq, "N�mero de compara��es: %d\n", comp);
	fprintf(arq, "N�mero de movimenta��es: %d\n\n", mov);
	fclose(arq);
}
