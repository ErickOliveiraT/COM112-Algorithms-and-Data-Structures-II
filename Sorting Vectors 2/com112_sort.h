//com112_sort.h

void BubbleSort(int vet[], int n, int *comp, int *mov, double *tempo); //Algortimo Bubble Sort
void SelectionSort(int vet[], int n, int *comp, int *mov, double *tempo); //Algortimo Selection Sort
void InsertionSort(int vet[], int n, int *comp, int *mov, double *tempo); //Algoritmo Insertion Sort
int divisor(int vect[], int l, int r, int *comp, int *mov); //Divide o vetor entre piv�s para ordenar (Algoritmo Quick Sort)
void quickSort(int vect[], int l, int r, int *comp, int *mov); //Invoca recursivamente a fun��o de divis�o do vetor at� que este seja indivis�vel, e ordenado (Algoritmo Quick Sort)
void mergeSort(int X[], int inicio, int fim, int *comp, int *mov); //Fun��o recursiva que realiza a divis�o (Algoritmo Merge Sort)
void merge(int X[], int inicio, int meio, int fim, int *comp, int *mov); //Fun��o que ordena/intercala (Algoritmo Merge Sort)

