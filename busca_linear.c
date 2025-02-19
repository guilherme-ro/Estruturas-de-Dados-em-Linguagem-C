#include <stdio.h>

// Função para realizar a busca linear
int buscaLinear(int arr[], int n, int chave) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == chave) {
            return i;  // Retorna o índice onde a chave foi encontrada
        }
    }
    return -1;  // Retorna -1 se a chave não for encontrada
}

int main() {
    int arr[] = {5, 3, 8, 6, 7, 2, 4};  // Exemplo de array
    int n = sizeof(arr) / sizeof(arr[0]);  // Número de elementos no array
    int chave = 6;  // Valor que desejamos procurar

    // Chama a função de busca linear
    int resultado = buscaLinear(arr, n, chave);

    // Verifica se o valor foi encontrado
    if (resultado != -1) {
        printf("Valor %d encontrado no índice %d.\n", chave, resultado);
    } else {
        printf("Valor %d não encontrado no array.\n", chave);
    }

    return 0;
}
