//
// Created by josen on 09-06-2022.
//

#ifndef TAREA_4_ESTRUC_H
#define TAREA_4_ESTRUC_H
#include <stdio.h>
#include <stdlib.h>
// estructura para nodos de arboles AVL
typedef struct persona {
    int danger;
    float atack;
    char name[100]
} persona;
// estructura para nodos de arboles AVL
struct node {
    struct persona*atacante;
    struct node *left;
    struct node *right;
    int height;
};

// muestra los nodos inorder (I, R, D)
void show_nodes_inorder(struct node *root);
// muestra los nodos preorder (R, I, D)
void show_nodes_preorder(struct node *root);
// muestra los nodos postorder (I, D, R)
void show_nodes_postorder(struct node *root);

// funcion auxiliar maximo
int max(int a, int b);

// funcion auxiliar height
// entrega la altura del nodo node
// OJO: node puede ser NULL en cuyo caso la altura es 0
// OJO: cuando node es una hoja la altura es 1
int height(struct node *node);

// funcion auxiliar balance
// retorna el height del hijo izquierdo menos el height del hijo derecho
// Si node == NULL, entregamos 0
int balance(struct node *node);


// rota hacia la derecha el arbol con raiz y
// asume que la raiz y junto al pivote y->left no son NULL
// retorna la nueva raiz del arbol
struct node *rightRotate(struct node *y);

// rota hacia la izquiera el arbol con raiz x
// asume que la raiz x junto al pivote x->right no son NULL
// retorna la nueva raiz del arbol
struct node *leftRotate(struct node *x);

struct node *criterio_danger(struct node *node, struct persona*p);
struct node *criterio_atack(struct node *node, struct persona*p);
struct node *criterio_name(struct node *node, struct persona*p);

struct node *insert2_0(struct node *node, struct persona*p);

struct node *insert(struct node *node, struct persona*p);
void print2D(struct node *root);
void print2DUtil(struct node *root, int space);

struct node *criterio_danger(struct node *node, struct persona*p);
#endif //TAREA_4_ESTRUC_H
