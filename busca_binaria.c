#include <stdio.h>

// Função para realizar a busca binária
int buscaBinaria(int arr[], int n, int chave) {
    int esquerda = 0;    // Índice inicial
    int direita = n - 1; // Índice final

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2; // Calcula o índice do meio

        // Verifica se a chave está no meio
        if (arr[meio] == chave) {
            return meio;  // Retorna o índice onde a chave foi encontrada
        }

        // Se a chave for menor que o valor no meio, a chave deve estar na metade esquerda
        if (arr[meio] > chave) {
            direita = meio - 1;
        }
        // Se a chave for maior que o valor no meio, a chave deve estar na metade direita
        else {
            esquerda = meio + 1;
        }
    }

    return -1;  // Retorna -1 se a chave não for encontrada
}

int main() {
    int arr[] = {2, 3, 4, 5, 6, 7, 8};  // Exemplo de array ordenado
    int n = sizeof(arr) / sizeof(arr[0]);  // Número de elementos no array
    int chave = 6;  // Valor que desejamos procurar

    // Chama a função de busca binária
    int resultado = buscaBinaria(arr, n, chave);

    // Verifica se o valor foi encontrado
    if (resultado != -1) {
        printf("Valor %d encontrado no índice %d.\n", chave, resultado);
    } else {
        printf("Valor %d não encontrado no array.\n", chave);
    }

    return 0;
}
