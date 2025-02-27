#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó de lista ligada (para as arestas)
struct Nodo {
    int vertice;
    struct Nodo* proximo;
};

// Estrutura para representar o grafo
struct Grafo {
    int numVertices;
    struct Nodo** listaAdjacente;  // Array de listas de adjacência
};

// Função para criar um grafo com um número de vértices
struct Grafo* criarGrafo(int numVertices) {
    struct Grafo* grafo = (struct Grafo*)malloc(sizeof(struct Grafo));
    grafo->numVertices = numVertices;

    // Alocando memória para as listas de adjacência
    grafo->listaAdjacente = (struct Nodo**)malloc(numVertices * sizeof(struct Nodo*));

    // Inicializando todas as listas de adjacência como NULL
    for (int i = 0; i < numVertices; i++) {
        grafo->listaAdjacente[i] = NULL;
    }

    return grafo;
}

// Função para adicionar uma aresta no grafo (não direcionada)
void adicionarAresta(struct Grafo* grafo, int vertice1, int vertice2) {
    // Adicionando a aresta de vertice1 para vertice2
    struct Nodo* novoNodo1 = (struct Nodo*)malloc(sizeof(struct Nodo));
    novoNodo1->vertice = vertice2;
    novoNodo1->proximo = grafo->listaAdjacente[vertice1];
    grafo->listaAdjacente[vertice1] = novoNodo1;

    // Adicionando a aresta de vertice2 para vertice1 (não direcionada)
    struct Nodo* novoNodo2 = (struct Nodo*)malloc(sizeof(struct Nodo));
    novoNodo2->vertice = vertice1;
    novoNodo2->proximo = grafo->listaAdjacente[vertice2];
    grafo->listaAdjacente[vertice2] = novoNodo2;
}

// Função para exibir o grafo
void exibirGrafo(struct Grafo* grafo) {
    for (int i = 0; i < grafo->numVertices; i++) {
        struct Nodo* temp = grafo->listaAdjacente[i];
        printf("Vértice %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertice);
            temp = temp->proximo;
        }
        printf("NULL\n");
    }
}

// Função para liberar a memória do grafo
void liberarGrafo(struct Grafo* grafo) {
    for (int i = 0; i < grafo->numVertices; i++) {
        struct Nodo* temp = grafo->listaAdjacente[i];
        while (temp) {
            struct Nodo* paraDeletar = temp;
            temp = temp->proximo;
            free(paraDeletar);
        }
    }
    free(grafo->listaAdjacente);
    free(grafo);
}

// Função principal
int main() {
    int numVertices = 5;

    // Criando um grafo com 5 vértices
    struct Grafo* grafo = criarGrafo(numVertices);

    // Adicionando arestas no grafo (grafo não direcionado)
    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 4);
    adicionarAresta(grafo, 1, 4);
    adicionarAresta(grafo, 1, 2);
    adicionarAresta(grafo, 2, 3);
    adicionarAresta(grafo, 3, 4);

    // Exibindo o grafo
    exibirGrafo(grafo);

    // Liberando a memória alocada
    liberarGrafo(grafo);

    return 0;
}
