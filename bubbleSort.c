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
void bubbleSort(int arr[], int n){
    int aux;
    //leva o menor numero da ultima posiçao para a primeira
    for (int j = 0; j < n; j++)
    {
        //percorre o vetor
        for (int i = 0; i < n - 1; i++)
        {
            if(arr[i+1] < arr[i]){
                aux = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = aux;
            }
        }
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

    bubbleSort(vetor, 50000);
    
    t_fim = time(NULL);

    tempo = difftime(t_fim, t_ini);
    printf("terminou em: %f\n", tempo);
    printf(EstaOrdemCrescente(vetor, 50000) ? "Esta em ordem crescente\n" : "Nao esta em ordem crescente\n");


    return 0;
}