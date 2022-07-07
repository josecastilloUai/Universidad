package com.grupo17.workshop.vista;

import com.grupo17.workshop.Acciones.action;
import com.grupo17.workshop.biblioteca.libro;

import java.util.List;

public class submenu extends menu{
    action action = new action();

    public submenu(int choice) {
        super(choice);
    } //Setter.

    //Procedimiento del sub menu, cada uno es acorde a la elección del usuario.
    public void Submenu1(List<libro> libro){ //Muestra todos los libros.
        System.out.println("Ha elegido mostrar todos los libros. A continuación se muestran todos los libros disponibles en la biblioteca.\n");
        System.out.println("Titulo; Autor; Anio; Numero estante; Seccion estante; Piso; Edificio; Sede");
        for(int i=0; i<=(libro.size()-1); i++) {
            libro.get(i).printDatos();
        }
    }
    public void Submenu2(List<libro> libro){ //Busca un libro por título.
        System.out.println("Ha elegido buscar un libro. Ingrese el titulo del libro que desea buscar");
        action.buscarLibro(libro);
    }
    public void Submenu3(List<libro> libro){  //Agrega un libro.
        System.out.println("Ha elegido Agregar un libro. A continuación ingrese los datos del libro separados por un espacio simple");
        action.agregarLibro(libro);
    }
    public void Submenu4(List<libro> libro){ //Elimina un libro.
        System.out.println("Ha elegido eliminar un libro.");
        action.quitarLibro(libro);
    }
    public void Submenu5(List<libro> libro){ //Modifica un libro.
        System.out.println("Ha elegido modificar un libro.\n");
        System.out.println("Primero escriba el nombre del titulo, luego la caracteristica que desea modificar y por ultimo el valor por el que desea reemplazar.");
        action.editarLibro(libro);
    }
    public void Submenu6(List<libro> libro){ //Se actua según la sede.
        System.out.println("Ha elegido la opción 6. Elija que hacer con la variable sede de algún libro");
        action.Alternativas(libro);
    }
    public void Submenu7(List<libro> libro){ //Se actua según el piso.
        System.out.println("Ha elegido la opción 7. Elija que hacer con la variable piso de algún libro");
        action.Alternativas(libro);
    }
    public void Submenu8(List<libro> libro){ //Se actua según la sección.
        System.out.println("Ha elegido la opción 8. Elija que hacer con la variable seccion de algún libro");
        action.Alternativas(libro);
    }
}
