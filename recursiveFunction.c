#include <stdio.h>

/* verificar se um vetor é balanciado, o valor da soma do primeiro e do ultimo tem que 
dar o valor do segundo com o penultimo e assim por diante */

int balanceadaT(int *vetor, int inicio, int fim, int valor){
    if (inicio > fim)
    {
        return 1;
    }
    int aux = vetor[inicio] + vetor[fim];
    if (valor != aux)
    {   
        return 0;
    }
    return balanceadaT(vetor, inicio+1, fim-1, valor);
}

int balanceada(int *vetor, int inicio, int fim){
    return balanceadaT(vetor, inicio, fim, vetor[inicio] + vetor[fim]);
}

int main()
{
    int vetor1[] = {3,3,5,8,9,10,11,27,32,41,45,51};
    int vetor[] = {1,3,7,11,15,17};
    printf("%d\n", balanceada(vetor1, 0, 11));
    printf("%d", balanceada(vetor, 0, 5));
}