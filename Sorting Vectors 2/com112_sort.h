//com112_sort.h

void BubbleSort(int vet[], int n, int *comp, int *mov, double *tempo); //Algortimo Bubble Sort
void SelectionSort(int vet[], int n, int *comp, int *mov, double *tempo); //Algortimo Selection Sort
void InsertionSort(int vet[], int n, int *comp, int *mov, double *tempo); //Algoritmo Insertion Sort
int divisor(int vect[], int l, int r, int *comp, int *mov); //Divide o vetor entre pivôs para ordenar (Algoritmo Quick Sort)
void quickSort(int vect[], int l, int r, int *comp, int *mov); //Invoca recursivamente a função de divisão do vetor até que este seja indivisível, e ordenado (Algoritmo Quick Sort)
void mergeSort(int X[], int inicio, int fim, int *comp, int *mov); //Função recursiva que realiza a divisão (Algoritmo Merge Sort)
void merge(int X[], int inicio, int meio, int fim, int *comp, int *mov); //Função que ordena/intercala (Algoritmo Merge Sort)

