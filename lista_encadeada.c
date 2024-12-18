#include <stdio.h>
#include <stdlib.h>

// Estrutura do no
struct Node {
    int data;
    struct Node *next;
};

// Funcao para criar um novo no
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if( newNode == NULL) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Funcao para inserir um no no inicio da lista
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Funcao para inserir um nó no final da lista
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNOde = createNode(data);
    if( *head == NULL ) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while( temp->next != NULL ) {
        temp = temp->next;
    }
    temp->next = NewNode;
}

// Funcao para remover o primeiro nó da lista
void deleteFirst(struct Node **head) {
    if( *head == NULL ) {
        printf("A lista esta vazia.\n");
        return;
    }
    struct Node *temp = *head;
    *head = temp->next;
    free(temp);
}

// Funcao para remover o último nó da lista
void deleteLast(struct Node **head) {
    if (*head == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Funcao para exibir os elementos da lista
void displayList(struct Node *head) {
    if (head == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Funcao para liberar a memoria da lista
void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL; // Lista inicialmente vazia

    // Testando a insercao no inicio
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    // Testando a insercao no final
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    // Exibindo a lista
    printf("Lista apos insercoes: ");
    displayList(head);

    // Removendo o primeiro no
    deleteFirst(&head);
    printf("Lista apos remocao do primeiro no: ");
    displayList(head);

    // Removendo o último no
    deleteLast(&head);
    printf("Lista apos remocao do ultimo no: ");
    displayList(head);

    // Liberando a memória alocada
    freeList(head);

    return 0;
}