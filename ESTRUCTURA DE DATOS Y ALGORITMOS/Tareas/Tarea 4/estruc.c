//
// Created by josen on 09-06-2022.
//
#include "estruc.h"
#include <string.h>

#define COUNT 10

typedef struct node node;

// muestra los nodos inorder (I, R, D)
void show_nodes_inorder(struct node *root)
{
    if (root == NULL) {
        return;
    }
    show_nodes_inorder(root->left);
    printf("%f ", root->atacante->atack);
    show_nodes_inorder(root->right);

}

// muestra los nodos preorder (R, I, D)
void show_nodes_preorder(struct node *root)
{
    if (root == NULL) {
        return;
    }
    printf("%f ", root->atacante->atack);
    show_nodes_preorder(root->left);
    show_nodes_preorder(root->right);

}

// muestra los nodos postorder (I, D, R)
void show_nodes_postorder(struct node *root)
{
    if (root == NULL) {
        return;
    }
    show_nodes_postorder(root->left);
    show_nodes_postorder(root->right);
    printf("%f ", root->atacante->atack);

}

// funcion auxiliar maximo
int max(int a, int b)
{
    return (a > b)? a : b;
}

// funcion auxiliar height
// entrega la altura del nodo node
// OJO: node puede ser NULL en cuyo caso la altura es 0
// OJO: cuando node es una hoja la altura es 1
int height(struct node *node)
{
    if (node == NULL) {
        return 0;
    }
    return 1 + max(height(node->left), height(node->right));
}

// funcion auxiliar balance
// retorna el height del hijo izquierdo menos el height del hijo derecho
// Si node == NULL, entregamos 0
int balance(struct node *node)
{
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// rota hacia la derecha el arbol con raiz y
// asume que la raiz y junto al pivote y->left no son NULL
// retorna la nueva raiz del arbol
struct node *rightRotate(struct node *y)
{
    // x es el pivote (nueva raiz)
    struct node *x = y->left;
    // OJO: z podria ser NULL (lo cual no es un problema)
    struct node *z = x->right;

    // rotamos a la derecha
    x->right = y;
    y->left = z;

    // actualizamos el height de y e x
    // (height de los otros nodos no cambia; no hay que actualizar)
    y->height = height(y);
    x->height = height(x);

    return x;
}

// rota hacia la izquiera el arbol con raiz x
// asume que la raiz x junto al pivote x->right no son NULL
// retorna la nueva raiz del arbol
struct node *leftRotate(struct node *x)
{
    // y es el pivote (nueva raiz)
    struct node *y = x->right;
    // OJO: z podria ser NULL (lo cual no es un problema)
    struct node *z = y->left;

    // rotamos a la izquierda
    y->left = x;
    x->right = z;

    // actualizamos el height de y e x
    // (height de los otros nodos no cambia; no hay que actualizar)
    y->height = height(y);
    x->height = height(x);

    return y;
}

struct node *criterio_danger(struct node *node, struct persona*p){

        if (p->danger < node->atacante->danger) {
            node->left = insert2_0(node->left, p);
        } else {
            node->right = insert2_0(node->right, p);
        }

        // actualizamos height de node
        node->height = height(node);
        // calculamos balance de node
        // si balance > 1 o balance < -1, el nodo esta desbalanceado
        int node_balance = balance(node);

        // caso left left
        if (node_balance > 1 && p->danger < node->left->atacante->danger) {
            return rightRotate(node);
        }
        // caso right right
        if (node_balance < -1 && p->danger >= node->right->atacante->danger) {
            return leftRotate(node);
        }
        // caso left right
        if (node_balance > 1 && p->danger >= node->left->atacante->danger) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // caso right left
        if (node_balance < -1 && p->danger < node->right->atacante->danger) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;

   }
struct node *criterio_atack(struct node *node, struct persona*p){
    if (p->atack < node->atacante->atack) {
        node->left = insert2_0(node->left, p);
    } else {
        node->right = insert2_0(node->right, p);
    }

    // actualizamos height de node
    node->height = height(node);
    // calculamos balance de node
    // si balance > 1 o balance < -1, el nodo esta desbalanceado
    int node_balance = balance(node);

    // caso left left
    if (node_balance > 1 && p->atack < node->left->atacante->atack) {
        return rightRotate(node);
    }
    // caso right right
    if (node_balance < -1 && p->atack >= node->right->atacante->atack) {
        return leftRotate(node);
    }
    // caso left right
    if (node_balance > 1 && p->atack >= node->left->atacante->atack) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // caso right left
    if (node_balance < -1 && p->atack < node->right->atacante->atack) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
struct node *criterio_name(struct node *node, struct persona*p){
    if (strcmp(node->atacante->name, p->name) < 0) {
        node->left = insert2_0(node->left, p);
    } else {
        node->right = insert2_0(node->right, p);
    }

    // actualizamos height de node
    node->height = height(node);
    // calculamos balance de node
    // si balance > 1 o balance < -1, el nodo esta desbalanceado
    int node_balance = balance(node);

    // caso left left
    if (node_balance > 1 && strcmp(p->name , node->left->atacante->name)<0) {
        return rightRotate(node);
    }
    // caso right right
    if (node_balance < -1 && strcmp(p->name , node->left->atacante->name)>=0) {
        return leftRotate(node);
    }
    // caso left right
    if (node_balance > 1 &&strcmp(p->name , node->left->atacante->name)>=0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // caso right left
    if (node_balance < -1 && strcmp(p->name , node->left->atacante->name)<0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct node *insert2_0(struct node *node, struct persona*p){
    if (node == NULL) { // caso arbol vacio
        struct node *tmp = (struct node *)malloc(sizeof(struct node));
        tmp->atacante = p;
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->height = 1; // en este caso las hojas tienen altura 1
        return tmp;
    }
    struct node *node_tpm;
    if (p->danger != node->atacante->danger) {
         node_tpm= criterio_danger(node, p);
        return node_tpm;
    }
    else{
       if(node->atacante->atack!=p->atack){
           node_tpm= criterio_atack(node, p);
           return node_tpm;
       }/*
       else{
            if(strcmp(node->atacante->name,p->name)!=0){
                node_tpm= criterio_name(node,p);
                return node_tpm;
            }
       }
        */
    }
    return node;

}


// inserta el dato data al arbol AVL
// retorna la nueva raiz del arbol
struct node *insert(struct node *node, struct persona*p)
{
    if (node == NULL) { // caso arbol vacio
        struct node *tmp = (struct node *)malloc(sizeof(struct node));
        tmp->atacante = p;
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->height = 1; // en este caso las hojas tienen altura 1
        return tmp;
    }

    // caso en que el arbol es no vacio
    // en este caso la raiz es la misma, por eso hacemos "return node;" al final
    // llamamos recursivamente al metodo insert ya sea al lado izquierdo o derecho
    // actualizamos el hijo correpondiente con la nueva raiz obtenida
    if (p->danger < node->atacante->danger) {
        node->left = insert(node->left, p);
    }
    else {
        node->right = insert(node->right, p);
    }

    // actualizamos height de node
    node->height = height(node);
    // calculamos balance de node
    // si balance > 1 o balance < -1, el nodo esta desbalanceado
    int node_balance = balance(node);

    // caso left left
    if (node_balance > 1 && p->danger < node->left->atacante->danger) {
        return rightRotate(node);
    }
    // caso right right
    if (node_balance < -1 && p->danger >= node->right->atacante->danger) {
        return leftRotate(node);
    }
    // caso left right
    if (node_balance > 1 && p->danger >= node->left->atacante->danger) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // caso right left
    if (node_balance < -1 && p->danger < node->right->atacante->danger) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// busca el dato data en el arbol AVL
// retorna el primer nodo que se encuentra con el dato, o
// si el dato no esta se retorna NULL
struct node *search(struct node *root, struct persona*data)
{
    // caso base: ya sea root es NULL, es decir, el dato no esta, o
    // el dato esta en root. En cualquier caso hay que retornar root
    if(root == NULL || root->atacante->atack == data->atack) {
        return root;
    }

    // hacemos la busqueda ya sea a la izquierda o a la derecha,
    // y retornamos lo obtenido
    if(data->atack < root->atacante->atack) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

void print2DUtil(struct node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("(%s,%d,%3f)\n", root->atacante->name,root->atacante->danger,root->atacante->atack);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(struct node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}