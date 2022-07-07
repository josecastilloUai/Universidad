#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruc.h"
int main() {

    struct node *root = NULL;

    struct persona p={.name="juan",.atack=0.5,.danger=1};
    struct persona p1={.name="pablo",.atack=0.1,.danger=3};
    struct persona p2={.name="mario",.atack=0.5,.danger=4};
    struct persona p3={.name="sofia",.atack=0.2,.danger=5};
    struct persona p4={.name="blopa",.atack=0.3,.danger=5};
    struct persona p5={.name="anton",.atack=0.6,.danger=1};
    struct persona p6={.name="cuca",.atack=0.4,.danger=1};
    struct persona p7={.name="padre",.atack=0.1,.danger=3};
    root=insert2_0(root,&p);
    root=insert2_0(root,&p1);
    root=insert2_0(root,&p2);
    root=insert2_0(root,&p3);
    root=insert2_0(root,&p4);
    root=insert2_0(root,&p5);
    root=insert2_0(root,&p6);
    root=insert2_0(root,&p7);
    printf("(name,danger,atack)\n");
    print2D(root);

    return 0;
}