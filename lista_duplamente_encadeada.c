#include <stdio.h>
#include <stdlib.h>

// Estrutura do no da lista duplamente encadeada
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Funcao para criar um novo no
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if( newNode == NULL ) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Funcao para inserir um no no inicio da lista
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// Funcao para inserir um no no final da lista
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Funcao para remover o primeiro no
void deleteFirst(struct Node **head) {
    if (*head == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    struct Node *temp = *head;
    *head = temp->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Funcao para remover o ultimo no
void deleteLast(struct Node **head) {
    if (*head == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL; // A lista tem apenas um elemento
    }
    free(temp);
}

// Funcao para exibir a lista da frente para tras
void displayForward(struct Node *head) {
    if (head == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Funcao para exibir a lista de tras para frente
void displayBackward(struct Node *head) {
    if (head == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Funcao para liberar a memoria alocada para a lista
void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node *head = NULL; // Lista inicialmente vazia

    // Testando a insercao no inicio
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    // Testando a insercao no final
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    // Exibindo a lista da frente para tras
    printf("Lista da frente para tras: ");
    displayForward(head);

    // Exibindo a lista de tras para frente
    printf("Lista de tras para frente: ");
    displayBackward(head);

    // Removendo o primeiro no
    deleteFirst(&head);
    printf("Lista apos remocao do primeiro no: ");
    displayForward(head);

    // Removendo o ultimo no
    deleteLast(&head);
    printf("Lista apos remocao do ultimo no: ");
    displayForward(head);

    // Liberando a memoria alocada
    freeList(head);

    return 0;
}
