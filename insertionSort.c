#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int EstaOrdemCrescente(int vetor[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i - 1] > vetor[i]) {
            return 0;
        }
    }
    return 1; 
}

//O(n^2) - é estavel
void insertionSort(int arr[], int n){
    int aux, k;
    for (int i = 1; i < n; i++)
    {
        k = i;
        for (int j = i - 1; j >= 0 && arr[k] < arr[j]; j--)
        {
            aux = arr[j];
            arr[j] = arr[k];
            arr[k] = aux;
            k--;
        }
        
    }
}

void insertionSortOptimized(int arr[], int n) {
   int i, key, j;
   for (i = 1; i < n; i++) {
       key = arr[i];
       j = i - 1;

        //otimizado, verifica se quem esta a esquerda é menor que o atual se sim ele ja pula pro proximo
        //entao nao precisa trocar os elementos da esquerda
       while (j >= 0 && arr[j] > key) {
           arr[j + 1] = arr[j];
           j = j - 1;
       }
       arr[j + 1] = key;
   }
}

int main()
{
    //codigo para gerar numeros aleatorios para testa o tempo das funçoes de ordenaçao
    int vetor[50000];

    for (int i = 0; i < 50000; i++)
    {
        vetor[i] = rand();
    }
    
    float tempo;
    time_t t_ini, t_fim; 

    t_ini = time(NULL);

    insertionSort(vetor, 50000);
    
    t_fim = time(NULL);

    tempo = difftime(t_fim, t_ini);
    printf("terminou em: %f\n", tempo);
    printf(EstaOrdemCrescente(vetor, 50000) ? "Esta em ordem crescente\n" : "Nao esta em ordem crescente\n");


    return 0;
}