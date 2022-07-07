#define TABLE_SIZE 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "personas.h"
#define TABLE_SIZE 5

personas *hash_table[TABLE_SIZE]; //

FILE * openingFile(char *filename){ //Función que abre el archivo csv y lo devuelve como archivo para ser utilizado.
    FILE *fp;
    fp = fopen(filename,"r");
    return fp;
}

void init_hash_tablet(){ //Método que inicializa la tabla hash llenandola con valores nulos.
    for(int i=0;i<=TABLE_SIZE;i++){
        hash_table[i]=NULL;
    }
}

void print_table(){ //Método que imprime la tabla hash.
    printf("\tKEY\t (name, attack_prob)");
    printf("\n");
    for(int i=1;i<=TABLE_SIZE;i++){ //Con este ciclo for se recorren los distintos nodos y se van imprimiendo sus valores
        if(hash_table[i]==NULL){
            printf("\t%i\t----\t----\n",i); //Si el nodo es nulo, se imprime vacio.
        }
        else{ //En este caso se recorre todo el nodo imprimiendolos en orden.
            printf("\t%i\t",i);
            personas *tmp=hash_table[i];
            while (tmp!=NULL){
                printf("(%s, %f)",tmp->name,tmp->attack_prob);
                printf(" ");
                tmp=tmp->next; //Con esta linea se mueven las posiciones.
            }
            printf("\n");
        }
    }
}

bool hash_table_insert(personas*p){ //Función que inserta los valores en la Hash table.
    //Si es nulo no lo coloca en la tabla hash.
    if(p==NULL) return false;
    //Se colocan en la fila de segun su danger_category.
    int index= p -> danger_category;
    //Se coloca al lado de del siguiente nodo.
    p->next=hash_table[index];
    hash_table[index]=p;
    return true;
}

void getData(FILE *the_file){ //Método que obtiene los datos del csv y los guarda en la tabla hash.
    //Variables que se usarán durante todo el método.
    char line[100]; //Variable donde se irán guardando las lineas del csv.
    char *save; //Variable donde se irán tomando los datos de las lineas. Parte del inicio y toma hasta la coma, y sigue así hasta el final.
    char *nombre; //Variable donde se guardan los nombres de las personas.
    int danger; //Variable que guarda los valores de danger_category.
    float attack; //Variable que guarda los valores de attack_prob.
    int i = 1; //Variables de apoyo
    int a = 0;

    while (fgets(line, 100, the_file) != NULL){ //Ciclo que va recorriendo las lineas del archivo csv.
        personas *temporal = (personas *) malloc(sizeof(personas)); //Aquí se crea una persona cuyos datos se irán llenando con los tomados en el csv.

        if (a==0){ //Este if hace que si es la primera linea del csv (encabezados), no la tome y continue con la siguiente iteración.
            a++;
            continue;
        }

        //Aquí se empiezan a guardar los valores de las lineas del cvs separadas por comas en la persona temporal.
        save = strtok(line, ",");
        strcpy(temporal->name, save);

        save = strtok(NULL, ",");
        temporal->danger_category = atoi(save);

        save = strtok(NULL, ",");
        if (strcmp(save, "\n")==0){ //Condición que hace que si la persona no tiene probabilidad se llena con -1.
            attack = -1;
        }
        else if (strlen(save) == 1){ //Está condición es la misma que arriba.
            attack = -1;
        }
        else{ //En caso de que no sea nula se guarda su valor de attack_prob.
            attack = atof(save);
            i++;
        }
        temporal->attack_prob = attack;
        hash_table_insert(temporal); //Luego se inserta a la persona temporal con sus datos actuales en la tabla hash.
    }
    fclose(the_file); //Se cierra el archivo.
}

void write(char txt_salida[], int cant){ //Método que escribe el archivo de salida y lo crea en caso de no existir.
    int n = 1;
    FILE *fout;
    fout = fopen(txt_salida, "w+");
    //Se recorre cada uno de los nodos de la Hash table y se escribe el nombre obtenido dentro del archivo de salida, hasta completar la cantidad de enemigos solicitados por el usuario.
    for (int i=5; i>=1; i--){
        personas *p = hash_table[i];
        while (p!=NULL){
            fprintf(fout, "%s\n", p->name);
            n++;
            p=p->next;
            if (n>cant){
                fclose(fout);
            }
        }
    }
    fclose(fout);
}

int hash_len(int i){//Función que cuenta los datos que tiene el nodo i.
    int counter = 0;
    //Selecionamos la Fila/nodo.
    personas *tmp = hash_table[i];
    //Se recorren los valores del nodo en cuestión. Se van contando (counter).
    while (tmp!=NULL){
        if (tmp->attack_prob != -1) {
            counter += 1;
        }
        tmp=tmp->next;
    }
    return counter; //Se devuelve el contador.
}

void orden(){ //Función que ordena la Hash table según los criterios para cada categoría de peligrosidad.
    char* nombre;
    float attack;
    int seguro = 0;
    //Comenzamos el ciclo para recorrer todos los nodos de la Hash table.
    for(int i=1;i<=5;i++) {
        struct personas *it = hash_table[i], *index = NULL;
        if (hash_table[i] == NULL) { // caso lista vacia
            return;
        }
            //Criterio de ordenamiento para las categorías de peligrosidad 1 y 2.
        else if (i==1 || i==2){
            //Se recorre una estructura "iterador" y se compara con una "temporal", en la cual a través de BubbleSort, se reordenan los datos.
            while (it != NULL) {
                index = it->next;
                while (index != NULL) {
                    //Además, dentro de las condiciones para el ordenamiento, los datos se almacenan de mayor a menor, y en caso de tener probabilidad -1, se ordenan alfabéticamente también.
                    if (it->attack_prob < index->attack_prob || (it->attack_prob == index->attack_prob && strcmp(it->name, index->name) > 0)) {
                        strcpy(nombre, it->name);
                        attack = it->attack_prob;

                        strcpy(it->name, index->name);
                        it->attack_prob = index->attack_prob;

                        strcpy(index->name, nombre);
                        index->attack_prob = attack;
                    }
                    index = index->next;
                }
                it = it->next;
            }
        }
        //Criterio de ordenamiento para la categoría de peligrosidad 3
        else if (i==3){
            //Con la función hash_len obtenemos la cantidad de enemigos con probabilidad de ataque distinta de -1.
            int len_hash = hash_len(3);
            //Comenzamos el ciclo de comparación.
            while (it!=NULL){
                index = it->next;
                //Aquí se almacenarán al principio la cantidad de enemigos que tengan probabilidad de ataque distinta de -1, correspondientes a la mitad menos uno y ordenados de mayor a menor.
                if(seguro<=(len_hash/2)-1) {
                    while (index != NULL) {
                        if (((it->attack_prob == -1) && (index->attack_prob != -1)) || (it->attack_prob < index->attack_prob)) {
                            strcpy(nombre, index->name);
                            attack = index->attack_prob;

                            strcpy(index->name, it->name);
                            index->attack_prob = it->attack_prob;

                            strcpy(it->name, nombre);
                            it->attack_prob = attack;
                        }
                        index = index->next;
                    }
                }
                //Una vez se cumpla el primer requisito, comenzarán a almacenarse aquellos que tengan probabilidad igual a -1, alfabéticamente.
                else {
                    while (index != NULL) {
                        if ((it->attack_prob != -1) && (index->attack_prob == -1) || (it->attack_prob == index->attack_prob && strcmp(it->name, index->name) > 0)) {
                            strcpy(nombre, it->name);
                            attack = it->attack_prob;

                            strcpy(it->name, index->name);
                            it->attack_prob = index->attack_prob;

                            strcpy(index->name, nombre);
                            index->attack_prob = attack;
                        }
                        //Una vez ordenados, aquellos enemigos restantes que aún tienen probabilidad de ataque distinta de -1, serán ordenados al final, de mayor a menor, cumpliendo con todo el criterio.
                        if ((it->attack_prob != -1) && (index->attack_prob != -1) && (it->attack_prob < index->attack_prob)){
                            strcpy(nombre, it->name);
                            attack = it->attack_prob;

                            strcpy(it->name, index->name);
                            it->attack_prob = index->attack_prob;

                            strcpy(index->name, nombre);
                            index->attack_prob = attack;
                        }
                        index = index->next;
                    }
                }
                it=it->next;
                seguro=seguro+1;
            }
        }
        //Criterio de ordenamiento para las categorías de peligrosidad 4 y 5
        else if (i==4 || i==5){
            while (it != NULL) {
                index = it->next;
                while (index != NULL) {
                    //Al contrario del primer criterio de ordenamiento, aquí se almacenan al principio aquellos enemigos que tienen probabilidad de ataque igual a -1, ordenados alfabéticamente y posteriormente se ordenan de mayor a menor aquellos que poseen probabilidad de ataque distinta de -1.
                    if (it->attack_prob < index->attack_prob || (it->attack_prob == index->attack_prob && strcmp(it->name, index->name) > 0)) {
                        strcpy(nombre, it->name);
                        attack = it->attack_prob;

                        strcpy(it->name, index->name);
                        it->attack_prob = index->attack_prob;

                        strcpy(index->name, nombre);
                        index->attack_prob = attack;
                    }
                    if (it->attack_prob != -1) {
                        if (index->attack_prob == -1){
                            strcpy(nombre, it->name);
                            attack = it->attack_prob;

                            strcpy(it->name, index->name);
                            it->attack_prob = index->attack_prob;

                            strcpy(index->name, nombre);
                            index->attack_prob = attack;
                        }
                    }
                    else {
                        if (index->attack_prob == -1 && strcmp(it->name, index->name) > 0) {
                            strcpy(nombre, it->name);
                            attack = it->attack_prob;

                            strcpy(it->name, index->name);
                            it->attack_prob = index->attack_prob;

                            strcpy(index->name, nombre);
                            index->attack_prob = attack;
                        }
                    }
                    index = index->next;
                }
                it = it->next;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    //Se han incluído dos print_table() comentados, para poder visibilizar la Hash table al inicio del programa (después de extraer los datos del archivo de entrada) y al final del programa (después del ordenamiento).
    //Para su correcto funcionamiento, solamente "descomentar" las 3 líneas de código de más abajo.
    FILE *the_file = openingFile(argv[1]);
    init_hash_tablet();
    getData(the_file);
    //print_table();
    //printf("\n\n");
    orden();
    //print_table();
    int cant = atoi(argv[2]);
    write(argv[3], cant);
    return 0;
}