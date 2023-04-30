#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
struct node {
    int key;
    struct node *left;
    struct node *right;
    int height;
};

// Função para criar um novo nó
struct node* new_node(int key) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Função para obter a altura de um nó
int height(struct node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Função para obter o fator de balanceamento de um nó
int balance_factor(struct node *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Função para rotacionar um nó para a direita
struct node* rotate_right(struct node *node) {
    struct node *x = node->left;
    struct node *y = x->right;

    x->right = node;
    node->left = y;

    node->height = 1 + max(height(node->left), height(node->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// Função para rotacionar um nó para a esquerda
struct node* rotate_left(struct node *node) {
    struct node *x = node->right;
    struct node *y = x->left;

    x->left = node;
    node->right = y;

    node->height = 1 + max(height(node->left), height(node->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// Função para inserir um novo nó na árvore
struct node* insert_node(struct node* node, int key) {
    if (node == NULL)
        return new_node(key);

    if (key < node->key)
        node->left = insert_node(node->left, key);
    else if (key > node->key)
        node->right = insert_node(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balance_factor(node);

    // Caso 1: rotação simples à direita
    if (balance > 1 && key < node->left->key)
        return rotate_right(node);

    // Caso 2: rotação simples à esquerda
    if (balance < -1 && key > node->right->key)
        return rotate_left(node);

    // Caso 3: rotação dupla à direita
    if (balance > 1 && key > node->left->key) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    // Caso 4: rotação dupla à esquerda
    if (balance < -1 && key < node->right->key) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}

// Função para buscar um nó na árvore
struct node* search_node(struct node* node, int
