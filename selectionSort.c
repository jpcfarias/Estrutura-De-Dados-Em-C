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

//acha o menor index e troca com o primeiro - O(n^2) - nao é estavel
void selectionSort(int arr[], int n){
    int aux,min_idx;
    //pega o menor index no caso a primeira posiçao no vetor e percorre o vetor inteiro achando algum numero menor
    for (int i = 0; i < n - 1; i++)
    {
        min_idx = i;
        //o for com o j pega o numero na frente
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
            
        }

        aux = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = aux;
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

    selectionSort(vetor, 50000);
    
    t_fim = time(NULL);

    tempo = difftime(t_fim, t_ini);
    printf("terminou em: %f\n", tempo);
    printf(EstaOrdemCrescente(vetor, 50000) ? "Esta em ordem crescente\n" : "Nao esta em ordem crescente\n");


    return 0;
}