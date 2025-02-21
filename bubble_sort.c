#include <stdio.h>

// Função para realizar o Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    // Laço externo para percorrer todos os elementos
    for (i = 0; i < n - 1; i++) {
        // Laço interno para comparar e trocar os elementos adjacentes
        for (j = 0; j < n - i - 1; j++) {
            // Se o elemento da esquerda for maior que o da direita, troca
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função para imprimir o vetor
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original: \n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Vetor ordenado: \n");
    printArray(arr, n);

    return 0;
}
