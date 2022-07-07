package com.grupo17.workshop;

import  com.grupo17.workshop.archivos.archivo;
import com.grupo17.workshop.biblioteca.libro;
import com.grupo17.workshop.vista.choicemenu;
import java.util.List;

public class App2 {

    public static void main(String [] args){

        archivo the_file = new archivo(args[0]); //Se da el archivo (Si es que se corre de la terminal. El archivo csv está en la carpeta src).
        //Si se quiere correr desde Intellij, se le debe pasar la dirección completa o mover inventario.csv en el mismo lugar que la carpeta APP2.
        List<libro> libro = the_file.leerDatos(); //Se crea el Arraylist con todos los libros del csv.
        choicemenu M = new choicemenu(libro); //Se crea la instancia del menu con el arraylist seleccionado.

        while(true) {
            M.init(); //Se inicializa el menu.
            int eleccion = M.getChoice(); //Se solicita la eleccion
            if (eleccion == 0){break;} //Si es igual a 0, se rompe el ciclo y se termina todo.
            M.decision(); //En caso contrario, se llama un procedimiento que actua según la elección del usuario.
            the_file.rewrite(libro); //Se reescribe el csv.
       }
    }
}
