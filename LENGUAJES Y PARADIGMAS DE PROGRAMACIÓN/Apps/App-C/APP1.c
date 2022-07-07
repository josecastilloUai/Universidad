#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"

//-------------------------------------------------------------------
// Acciones
//-------------------------------------------------------------------
//Permite escribir los datos actualizados en el csv.
void reewrite(FILE *the_file, libro dato[], int cantidad){
    fprintf(the_file, "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede\n");
    for (int i=1; i<cantidad+2; i++){
        fprintf(the_file, "\"%s\",%s,%d,%d,%s,%d,%s,%s",dato[i].titulo, dato[i].autor, dato[i].ano, dato[i].estante_numero, dato[i].estante_seccion, dato[i].piso, dato[i].edificio, dato[i].sede);
    }
}

//Permite editar un libro, preguntandole al usuario los campos que desea modificar.
void edit(libro dato[], int cantidad){
    char titulo[60];
    char *ret;
    int campo;
    char str[2] = "\n";
    int decision;
    int key = 0;
    printf("\nQue libro desea modificar?: ");
    scanf("%s", &titulo);
    for (int i=1; i<cantidad+1; i++){
        ret = strstr(dato[i].titulo, titulo);
        if (ret){
            while(key==0){
                printf("\nQue campo desea modificar? \n");
                printf("\n(1) Titulo\n");
                printf("(2) Autor\n");
                printf("(3) Ano\n");
                printf("(4) Numero de estante\n");
                printf("(5) Seccion\n");
                printf("(6) Piso\n");
                printf("(7) Edificio\n");
                printf("(8) Sede\n");
                printf("\nIngrese opcion: ");
                scanf("%d", &campo);
                if (campo==1){
                    char new_title[60];
                    printf("\nIngrese nuevo titulo: ");
                    scanf("%s", &new_title);
                    strcpy(dato[i].titulo, new_title);
                }
                else if (campo==2){
                    char new_autor[60];
                    printf("\nIngrese nuevo autor: ");
                    scanf("%s", &new_autor);
                    strcpy(dato[i].autor, new_autor);
                }
                else if (campo==3){
                    char new_ano[60];
                    printf("\nIngrese nuevo ano: ");
                    scanf("%s", &new_ano);
                    dato[i].ano = atoi(new_ano);
                }
                else if (campo==4){
                    char new_estante[60];
                    printf("\nIngrese nuevo numero de estante: ");
                    scanf("%s", &new_estante);
                    dato[i].estante_numero = atoi(new_estante);
                }
                else if (campo==5){
                    char new_sec[60];
                    printf("\nIngrese nueva seccion de estante: ");
                    scanf("%s", &new_sec);
                    strcpy(dato[i].estante_seccion, new_sec);
                }
                else if (campo==6){
                    char new_piso[60];
                    printf("\nIngrese nuevo numero de piso: ");
                    scanf("%s", &new_piso);
                    dato[i].piso = atoi(new_piso);
                }
                else if (campo==7){
                    char new_edificio[60];
                    printf("\nIngrese nuevo edificio: ");
                    scanf("%s", &new_edificio);
                    strcpy(dato[i].edificio, new_edificio);
                }
                else if (campo==8){
                    char new_sede[60];
                    printf("\nIngrese nueva sede: ");
                    scanf("%s", &new_sede);
                    strncat(new_sede, &str, 2);
                    strcpy(dato[i].sede, new_sede);
                }
                int decision;
                printf("\nDesea modificar nuevamente? (Si (1) / No (2)): ");
                scanf("%d", &decision);
                if(decision==2){
                    key++;
                }
            }
        }
    }
}

//Permite cambiar sede, seccion o piso segun el usuario desee.
void search_change(libro dato[], int cambio, int cantidad){
    char titulo[60];
    char *ret;
    char sede[60];
    char sec[60];
    char piso[20];
    char str[2] = "\n";
    printf("\nIngrese titulo del libro: ");
    scanf("%s", &titulo);
    for (int i=1; i<cantidad+1; i++){
        ret = strstr(dato[i].titulo, titulo);
        if (ret){
            if (cambio == 1){
                printf("\nIngrese nueva Sede: ");
                scanf("%s", &sede);
                strncat(sede, &str, 2);
                strcpy(dato[i].sede, sede);
            }
            else if (cambio == 2){
                printf("\nIngrese nueva Seccion: ");
                scanf("%s", &sec);
                strcpy(dato[i].estante_seccion, sec);
            }
            else if (cambio == 3){
                printf("\nIngrese nuevo Piso: ");
                scanf("%s", &piso);
                dato[i].piso = atoi(piso);
            }
        }
    }
}

//Pregunta al usuario que opcion desea cambiar.
void change(libro dato[], int eleccion2, int cantidad){
    int cambio;
    char libro[60];
    if (eleccion2 == 1){
        //Cambiar SEDE
        search_change(dato, eleccion2, cantidad);
    }
    else if (eleccion2 == 2){
        //Cambiar SECCIÓN
        search_change(dato, eleccion2, cantidad);
    }
    else if (eleccion2 == 3){
        //Cambiar PISO
        search_change(dato, eleccion2, cantidad);
    }
}

//Permite buscar un libro de la biblioteca para obtener su informacion
void find(libro dato[], int cantidad){
    char titulo[60];
    char *ret;
    printf("\nIngrese titulo del libro: ");
    scanf("%s", &titulo);
    for (int i=1; i<cantidad+1; i++){
        ret = strstr(dato[i].titulo, titulo);
        if (ret){
            printf("\nLibro: %s\n", dato[i].titulo);
            printf("Autor: %s\n", dato[i].autor);
            printf("Ano: %d\n", dato[i].ano);
            printf("Numero de estante: %d\n", dato[i].estante_numero);
            printf("Seccion: %s\n", dato[i].estante_seccion);
            printf("Piso: %d\n", dato[i].piso);
            printf("Edificio: %s\n", dato[i].edificio);
            printf("Sede: %s\n", dato[i].sede);
        }
    }
}

//Permite agregar un nuevo libro a la biblioteca.
void agregar_libro(libro dato[], int cantidad){
    char str[2] = "\n";
    char new_titulo[60];
    printf("\nIngrese titulo del libro: ");
    scanf("%s", &new_titulo);
    char new_autor[60];
    printf("\nIngrese autor del libro: ");
    scanf("%s", &new_autor);
    char new_ano[60];
    printf("\nIngrese ano del libro: ");
    scanf("%s", &new_ano);
    char new_estante_numero[60];
    printf("\nIngrese número del estante del libro: ");
    scanf("%s", &new_estante_numero);
    char new_estante_seccion[60];
    printf("\nIngrese seccion del estante del libro: ");
    scanf("%s", &new_estante_seccion);
    char new_piso[60];
    printf("\nIngrese piso del libro: ");
    scanf("%s", &new_piso);
    char new_edificio[60];
    printf("\nIngrese edificio del libro: ");
    scanf("%s", &new_edificio);
    char new_sede[60];
    printf("\nIngrese sede del libro: ");
    scanf("%s", &new_sede);

    int nro = cantidad + 1;
    strcpy(dato[nro].titulo, new_titulo);
    strcpy(dato[nro].autor, new_autor);
    dato[nro].ano = atoi(new_ano);
    dato[nro].estante_numero = atoi(new_estante_numero);
    strcpy(dato[nro].estante_seccion, new_estante_seccion);
    dato[nro].piso = atoi(new_piso);
    strcpy(dato[nro].edificio, new_edificio);
    strncat(new_sede, &str, 2);
    strcpy(dato[nro].sede, new_sede);
}

//Permite eliminar un libro de la biblioteca
void eliminar_libro(libro dato[], int cantidad){
    char titulo[60];
    char *ret;
    printf("\nQue libro desea eliminar?: ");
    scanf("%s", &titulo);
    for (int i=0; i<cantidad+1; i++){
        ret = strstr(dato[i].titulo, titulo);
        if (ret){
            dato[i].nro = 0;
            strcpy(dato[i].titulo, " ");
            strcpy(dato[i].autor, " ");
            dato[i].ano = 0;
            dato[i].estante_numero = 0;
            strcpy(dato[i].estante_seccion, " ");
            dato[i].piso = 0;
            strcpy(dato[i].edificio, " ");
            strcpy(dato[i].sede, " \n");
        }
    }
}
//-------------------------------------------------------------------
//Menú
//-------------------------------------------------------------------
//Se abre el archivo en modo escritura.
FILE * closingFile(char *filename){
    FILE *fp2;
    fp2 = fopen(filename, "w");
    return fp2;
}

//Se imprime el menu por pantalla para que el usuario seleccion lo que desea realizar
int menu_opciones(){
    int eleccion;
    // presentarcion de las opciones
    printf("\n1) Agregar / Eliminar un Libro:\n");
    printf("2) Agregar / Eliminar una Sede:\n");
    printf("3) Editar un Libro:\n");
    printf("4) Cambiar un Libro de Sede / Seccion / Piso:\n");
    printf("5) Agregar / Eliminar Secciones:\n");
    printf("6) Agregar / Eliminar Pisos:\n");
    printf("7) Buscar un Libro:\n");
    printf("\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &eleccion);
    //retorna la elecion del usuario
    return eleccion;
}

//Permite agregar o quita un libro, guardando los cambios en la biblioteca
void agregar_quitar(libro dato[], int cantidad, char* filename, FILE *the_file){
    FILE *inventario = closingFile(filename);
    int eleccion;
    printf("\nSelecciona si desea Agregar (1) o Quitar (2) un Libro: ");
    scanf("%d", &eleccion);

    if(eleccion==1){
        printf("\n-Agregar libro-\n");
        agregar_libro(dato, cantidad);
    }
    else if(eleccion==2){
        printf("\n-Quitar Libro-\n");
        eliminar_libro(dato, cantidad);
    }
    reewrite(the_file, dato, cantidad);
    fclose(the_file);
}

//Permite agregar una sede o cambiar la sede de un libro segun el usuario desee.
void sede(libro dato[], int cantidad, char* filename, FILE *the_file){
    FILE *inventario = closingFile(filename);
    int eleccion;
    int eleccion2;
    printf("\nSelecciona si desea Agregar (1) o Quitar (2) una Sede: ");
    //el usuario debe ingresar una de las opciones
    scanf("%d", &eleccion);
    if(eleccion==1){
        printf("\nDesea anadir una Sede anadiendo un Libro (1) o cambiando la Sede de un Libro (2): ");
        scanf("%d", &eleccion2);
        if(eleccion2==1){
            agregar_libro(dato, cantidad);
        }
        if(eleccion2==2){
            change(dato, 1, cantidad);
        }
    }
    else if(eleccion==2){
        printf("\nDesea quitar una Sede quitando un Libro (1) o cambiando la Sede de un Libro (2): ");
        scanf("%d", &eleccion2);
        if(eleccion2==1){
            eliminar_libro(dato, cantidad);
        }
        if(eleccion2==2){
            change(dato, 1, cantidad);
        }
    }
    reewrite(the_file, dato, cantidad);
    fclose(the_file);
}

//Se guarda el cambio en la biblioteca cuando el usuario decide editar un libro
void editar(libro dato[], int cantidad, char* filename, FILE *the_file){
    FILE *inventario = closingFile(filename);
    edit(dato, cantidad);
    reewrite(the_file, dato, cantidad);
    fclose(the_file);
}

//Se guarda el cambio en la biblioteca cuando el usuario decide cambiar un libro de sede.
void cambiar(libro dato[], int cantidad, char* filename, FILE *the_file){
    FILE *inventario = closingFile(filename);
    int accion;
    printf("\nSelecciona si desea cambiar un Libro de Sede(1) / Seccion(2) / Piso(3): ");
    scanf("%d", &accion);
    change(dato, accion, cantidad);
    reewrite(the_file, dato, cantidad);
    fclose(the_file);
}

//Permite modificar las secciones, agregando o quitando.
void seccion(libro dato[], int cantidad, char* filename, FILE *the_file){
    FILE *inventario = closingFile(filename);
    int eleccion;
    int eleccion2;
    printf("\nSelecciona si Agregar (1) o Quitar (2) Secciones: ");
    scanf("%d", &eleccion);
    if(eleccion==1){
        printf("\nDesea anadir una Seccion anadiendo un Libro (1) o cambiando la Seccion de un Libro (2): ");
        scanf("%d", &eleccion2);
        if(eleccion2==1){
            agregar_libro(dato, cantidad);
        }
        if(eleccion2==2){
            change(dato, 2, cantidad);
        }
    }
    else if(eleccion==2){
        printf("\nDesea quitar una Sede quitando un Libro (1) o cambiar la Seccion de un Libro (2): ");
        scanf("%d", &eleccion2);
        if(eleccion2==1){
            eliminar_libro(dato, cantidad);
        }
        if(eleccion2==2){
            change(dato, 2, cantidad);
        }
    }
    reewrite(the_file, dato, cantidad);
    fclose(the_file);
}

//Permite modificar los pisos, agregando o quitando.
void piso(libro dato[], int cantidad, char* filename, FILE *the_file){
    FILE *inventario = closingFile(filename);
    int eleccion;
    printf("\nSelecciona si Agregar (1) o Quitar (2) Piso: ");
    scanf("%d", &eleccion);
    int eleccion2;
    if(eleccion==1){
        printf("\nDesea anadir un Piso anadiendo un Libro (1) o cambiar el Piso de un Libro (2): ");
        scanf("%d", &eleccion2);
        if(eleccion2==1){
            agregar_libro(dato, cantidad);
        }
        if(eleccion2==2){
            change(dato, 3, cantidad);
        }
    }
    else if(eleccion==2){
        printf("\nDesea quitar una Sede quitando un Libro (1) o  cambiar la Sede de un Libro (2)");
        scanf("%d", &eleccion2);
        if(eleccion2==1){
            eliminar_libro(dato, cantidad);
        }
        if(eleccion2==2){
            change(dato, 3, cantidad);
        }
    }
    reewrite(the_file, dato, cantidad);
    fclose(the_file);
}

//Se busca un libro.
void buscarlibro(libro dato[], int cantidad){
    find(dato, cantidad);
}

//Se dividen los casos segun el usuario ingrese la accion que desea realizar.
void sub_menu(int eleccion, libro dato[], int cantidad, char* filename, FILE *the_file){
    int n=0;
    switch (eleccion)
    {
        case 1:
            agregar_quitar(dato, cantidad, filename, the_file);
            break;
        case 2:
            sede(dato, cantidad, filename, the_file);
            break;
        case 3:
            editar(dato, cantidad, filename, the_file);
            break;
        case 4:
            cambiar(dato, cantidad, filename, the_file);
            break;
        case 5:
            seccion(dato, cantidad, filename, the_file);
            break;
        case 6:
            piso(dato, cantidad, filename, the_file);
            break;
        case 7:
            buscarlibro(dato, cantidad);
            break;
        default:
            // solo si el usuario ingresa una opcion que no este comtemplada
            printf("Ingresar un numero que este en la lista\n\n");
            break;
    }
}

//-------------------------------------------------------------------
// Funciones y procedimientos base
//-------------------------------------------------------------------

//Permite saber la cantidad de libros existentes en la biblioteca
int cantidad_libros(FILE *the_file){
    char line[1000];
    int counter = -1;
    while (fgets(line, 1000, the_file) != NULL){
        counter++;
    }
    return counter;
}

//Se abre el archivo donde se encuentra la biblioteca
FILE * openingFile(char *filename){
    FILE *fp;
    fp = fopen(filename,"r");
    return fp;
}

//Se define la estructura de cada libro.
libro* getLibros(FILE *the_file){

    libro *dato = (libro*) malloc(5000*sizeof(libro));

    char line[1000];
    char *sp;
    int row_count = 1;
    int counter = 1;
    int i = 1;

    while (fgets(line, 1000, the_file) != NULL){

        int a = 0;
        dato[i].nro = counter;

        if (row_count == 1){
            row_count++;
            continue;
        }

        if (line[0] == '"'){
            sp = strtok(line, "\"");
            a++;
        }

        if (a == 0){
            sp = strtok(line, ",");
        }

        strcpy(dato[i].titulo, sp);
        sp = strtok(NULL, ",");

        strcpy(dato[i].autor, sp);
        sp = strtok(NULL, ",");

        dato[i].ano = atoi(sp);
        sp = strtok(NULL, ",");

        dato[i].estante_numero = atoi(sp);
        sp = strtok(NULL, ",");

        strcpy(dato[i].estante_seccion, sp);
        sp = strtok(NULL, ",");

        dato[i].piso = atoi(sp);
        sp = strtok(NULL, ",");

        strcpy(dato[i].edificio, sp);
        sp = strtok(NULL, ",");

        strcpy(dato[i].sede, sp);
        sp = strtok(NULL, ",");

        i++;
        counter++;
    }

    for (int i=counter; i<counter+3; i++){
        dato[i].nro = i;
        strcpy(dato[i].titulo, " ");
        strcpy(dato[i].autor, " ");
        dato[i].ano = 0;
        dato[i].estante_numero = 0;
        strcpy(dato[i].estante_seccion, " ");
        dato[i].piso = 0;
        strcpy(dato[i].edificio, " ");
        strcpy(dato[i].sede, " ");
    }

    fclose(the_file);
    return dato;
}

//Se rescatan las selecciones del usuario, ademas de obtene la estructura de los libros
void showContentAsStruct(FILE *the_file, int cantidad, char* filename){

    if (the_file==NULL){
        printf("ERROR");
        exit(0);
    }
    libro *dato = getLibros(the_file);
    int valor_menu = menu_opciones();
    sub_menu(valor_menu, dato, cantidad, filename, the_file);
    //se usara para terminar el loop
}

//Se da la salida del menu
int preguntar_salir(void){
    int rest;
    printf("\nDesea salir del programa? Ingrese un numero distinto de 0: ");
    scanf("%d",&rest);
    return rest;
}
//-------------------------------------------------------------------
//Funcion principal donde se ordenan todas las acciones y procedimientos.
int main(int argc, char *argv[]) {

    FILE *the_file = openingFile(argv[1]);
    FILE *the_file2 = openingFile(argv[1]);
    int a = cantidad_libros(the_file);
    int n=0;
    while(n==0){
        showContentAsStruct(the_file2, a, argv[1]);
        n=preguntar_salir();
    }
    return 0;
}

