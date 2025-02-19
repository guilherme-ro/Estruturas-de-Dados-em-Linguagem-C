#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó
typedef struct No {
    int valor;
    struct No* prox;
} No;

No* inicializar() {
    return NULL; // Lista vazia
}

void inserirInicio(No** head, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;

    if (*head == NULL) {
        novo->prox = novo;  // O nó aponta para si mesmo se a lista estiver vazia
        *head = novo;
    } else {
        No* temp = *head;
        while (temp->prox != *head) { // Percorrendo até o último nó
            temp = temp->prox;
        }
        temp->prox = novo; // O último nó aponta para o novo nó
        novo->prox = *head; // O novo nó aponta para o primeiro nó
        *head = novo;  // Atualiza a cabeça da lista
    }
}

void inserirFinal(No** head, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;

    if (*head == NULL) {
        novo->prox = novo;  // O nó aponta para si mesmo se a lista estiver vazia
        *head = novo;
    } else {
        No* temp = *head;
        while (temp->prox != *head) { // Percorrendo até o último nó
            temp = temp->prox;
        }
        temp->prox = novo;  // O último nó aponta para o novo nó
        novo->prox = *head;  // O novo nó aponta para o primeiro nó
    }
}

void removerInicio(No** head) {
    if (*head == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    
    No* temp = *head;
    if (temp->prox == *head) { // Se a lista tiver apenas um nó
        free(temp);
        *head = NULL;
    } else {
        No* ultimo = *head;
        while (ultimo->prox != *head) { // Encontrar o último nó
            ultimo = ultimo->prox;
        }
        *head = temp->prox; // Atualiza a cabeça da lista
        ultimo->prox = *head; // O último nó agora aponta para o novo primeiro nó
        free(temp);
    }
}

void removerFinal(No** head) {
    if (*head == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    
    No* temp = *head;
    if (temp->prox == *head) { // Se a lista tiver apenas um nó
        free(temp);
        *head = NULL;
    } else {
        No* penultimo = NULL;
        while (temp->prox != *head) { // Percorre até o penúltimo nó
            penultimo = temp;
            temp = temp->prox;
        }
        penultimo->prox = *head; // O penúltimo nó agora aponta para o primeiro nó
        free(temp);
    }
}

void exibirLista(No* head) {
    if (head == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    
    No* temp = head;
    do {
        printf("%d -> ", temp->valor);
        temp = temp->prox;
    } while (temp != head);
    
    printf("(circular)\n");
}

int listaVazia(No* head) {
    return head == NULL;
}

No* buscarValor(No* head, int valor) {
    if (head == NULL) {
        return NULL; // Lista vazia
    }

    No* temp = head;
    do {
        if (temp->valor == valor) {
            return temp;
        }
        temp = temp->prox;
    } while (temp != head);

    return NULL; // Não encontrou o valor
}

int main() {
    No* lista = inicializar();

    inserirInicio(&lista, 10);
    inserirFinal(&lista, 20);
    inserirInicio(&lista, 5);
    exibirLista(lista);  // Deve exibir: 5 -> 10 -> 20 -> (circular)

    removerInicio(&lista);
    exibirLista(lista);  // Deve exibir: 10 -> 20 -> (circular)

    removerFinal(&lista);
    exibirLista(lista);  // Deve exibir: 10 -> (circular)

    if (buscarValor(lista, 10)) {
        printf("Valor encontrado!\n");
    } else {
        printf("Valor não encontrado!\n");
    }

    return 0;
}
