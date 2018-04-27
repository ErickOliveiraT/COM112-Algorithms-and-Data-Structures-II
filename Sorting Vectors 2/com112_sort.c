#include "com112_sort.h"
#include "com112_file.h"

void BubbleSort(int vet[], int n, int *comp, int *mov, double *tempo)
{
	int i, troca = 1, cont = 1, aux;
	clock_t inicio, fim;
	
	inicio = clock(); //Marca o inicio do processo

	while (cont <= n && troca == 1) //Implementa��o bubble sort crescente
	{
		troca = 0;
		for (i = 0; i < n-1; i++)
		{	
			(*comp)++; //Incrementa n�mero de compara��es
			if (vet[i] > vet[i+1])
			{
				(*mov)++; //Incrementa n�mero de movimenta��es
				troca = 1;
				aux = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = aux;
			}
		}
		cont++;
	}
	
	fim = clock(); //Marca o fim do processo
	
	(*tempo) = ((double)(fim-inicio))/CLOCKS_PER_SEC; //Calcula o tempo gasto
} 

void SelectionSort(int vet[], int n, int *comp, int *mov, double *tempo)
{ 
  int i, j, menor, aux;
  clock_t inicio, fim;
  
  inicio = clock(); //Marca o inicio do processo
  
  for (i = 0; i < n-1; i++) //Implementa��o selection sort
  {
    menor = i;
    for (j = (i+1); j < n; j++)
    {
     (*comp)++; //Incrementa n�mero de compara��es	
     if(vet[j] < vet[menor]) menor = j;
    }
    
    (*comp)++; //Incrementa n�mero de compara��es	
	if (vet[i] != vet[menor])
    {
	 (*mov)++; //Incrementa n�mero de movimenta��es
	 aux = vet[i];
     vet[i] = vet[menor];
     vet[menor] = aux;
    }
  }
  
  fim = clock(); //Marca o fim do processo;
  
  (*tempo) = ((double)(fim-inicio))/CLOCKS_PER_SEC; //Calcula o tempo de execu��o
}

void InsertionSort(int vet[], int n, int *comp, int *mov, double *tempo) 
{
  int eleito, j, i; 
  clock_t inicio, fim;
  
  inicio = clock(); //Marca o inicio do processo
  
  for(i = 1; i < n; i++) //Implementa��o insertion sort
  {
    eleito = vet[i];
    j = i - 1;
    
    (*comp)++; //Imcrementa n�mero de compara��es

    while(j >= 0 && vet[j] > eleito)
    {     
      (*comp)++; //Imcrementa n�mero de compara��es
      (*mov)++; //Imcrementa n�mero de movimenta��es
	  
	  vet[j+1] = vet[j];
      j--;
    }
    
    vet[j+1] = eleito;
  }
  
  fim = clock(); //Marca o fim do processo
  
  (*tempo) = ((double)(fim-inicio))/CLOCKS_PER_SEC;
}

void quickSort(int vect[], int l, int r, int *comp, int *mov) //Invoca recursivamente a fun��o de divis�o do vetor at� que este seja indivis�vel, e ordenado
{
	int q;
	
	if(l < r) //Existe mais de um elemento no subvetor/vetor
	{
		q = divisor(vect, l, r, comp, mov);
		quickSort(vect, l, q, comp, mov);
		quickSort(vect, q+1, r, comp, mov);
	}
}

int divisor(int vect[], int l, int r, int *comp, int *mov) //Divide o vetor entre piv�s para ordenar
{
	int m, i, j; //Piv�, i e j auxiliares tempor�rios
	int aux = 0; //Auxiliar para troca
	
	m = vect[(l+r)/2];
	i = l-1;
	j = r+1;
	
	while(i < j) //Se encontra um valor da direita do piv� menor do que da esquerda invoca a fun��o de troca dos elementos
	{
		do
		{
			--j;
			(*comp)++;
		}while(vect[j] > m);
		
		(*comp)--; //Desconsidera a primeira incrementa��o no do{ (que n�o conta como compara��o)
		
		do
		{
			i++;
			(*comp)++;
		}while(vect[i] < m);
		
		(*comp)--; //Desconsidera a primeira incrementa��o no do{ (que n�o conta como compara��o)
		
		if(i < j)
		{
			(*mov)++; //Incrementa contagem de troca (movimenta��es)
			aux = vect[i];
			vect[i] = vect[j];
			vect[j] = aux;
		}
	}
	
	return j;
}

void merge(int X[], int inicio, int meio, int fim, int *comp, int *mov)
{
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 =  fim - meio;
 
    //Vetores de armazenamento tempor�rio
    int L[n1], R[n2];
 
    //Preenchendo os vetores tempor�rios
    for (i = 0; i < n1; i++)
        L[i] = X[inicio + i];
    for (j = 0; j < n2; j++)
        R[j] = X[meio + 1+ j];
 
    i = 0; 
    j = 0;
    k = inicio; 
    
    while (i < n1 && j < n2)
    {
        (*comp)++;
		if (L[i] <= R[j])
        {
            (*mov)++;
			X[k] = L[i];
            i++;
        }
        else
        {
            (*mov)++;
			X[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        (*mov)++;
		X[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        (*mov)++;
		X[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int X[], int inicio, int fim, int *comp, int *mov)
{
    if (inicio < fim)
    {
        int meio = inicio+(fim-inicio)/2; //Calcula meio
 
        //Realiza processo recursivo
        mergeSort(X, inicio, meio, comp, mov);
        mergeSort(X, meio+1, fim, comp, mov);
 
        merge(X, inicio, meio, fim, comp, mov);
    }
}
