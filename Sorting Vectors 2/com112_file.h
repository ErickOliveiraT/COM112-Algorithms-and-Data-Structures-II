//com112_file.h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void criaArquivo(); //Gera uma lista de n�meros aleat�rios para ser usado como entrada
void gravaResultado(int vet[], int n); //Imprime o vetor ordenado no arquivo 'com112_saida.txt'
void erro(); //Aviso de erro na manipula��o de arquivos
FILE *CriaArquivo_Relatorio(); //Cria arquivo da compara��o entre os algoritmos
