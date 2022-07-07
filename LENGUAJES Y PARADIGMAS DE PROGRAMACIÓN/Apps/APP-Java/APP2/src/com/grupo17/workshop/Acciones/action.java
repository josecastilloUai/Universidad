package com.grupo17.workshop.Acciones;

import com.grupo17.workshop.biblioteca.libro;
import java.util.List;
import java.util.Scanner;

public class action extends find{ //Clase de acciones de la biblioteca virtual.

    public void buscarLibro(List<libro> libro){ //Procedimiento que Buscará un libro e imprimirá sus datos.
        Find(libro); //Se hace la búsqueda filtrada dentro de la Arraylist.
    }

    public void agregarLibro(List<libro> libro){ //Procedimiento que agrega un libro a la Arraylist dada.
        Scanner input = new Scanner(System.in);  // Se crea un Scanner object.
        String[] datos_libro = input.nextLine().split(" "); //Se ingresan los datos y se guardan en una lista de Strings. Los datos se toman por cada espacio.
        libro aux = new libro(datos_libro[0], datos_libro[1], Integer.parseInt(datos_libro[2]),Integer.parseInt(datos_libro[3]), datos_libro[4], Integer.parseInt(datos_libro[5]), datos_libro[6], datos_libro[7]); //Se crea un objeto libro nuevo.
        libro.add(aux); //Se añade el libro a la Arraylist.
    }
    public void quitarLibro(List<libro> libro){ //Procedimiento que quita un libro de la Arraylist dada.
        String nombre_libro = introducirLibro(); //Se introduce el título del libro solicitado.

        for(int i=0; i<=(libro.size()-1); i++){ //Ciclo que busca el libro por el título.
            if (nombre_libro.equals(libro.get(i).getTitulo())==true){
                libro.remove(i); //Si se encuentra, se elimina.
            }
        }
    }

    public void editarLibro(List<libro> libro){ //Procedimiento que edita los atributos de un libro de la Arraylist dada.
        Cambio(libro);
    }

    public void Alternativas(List<libro> libro){ //Procedimiento que permite modificar, eliminar o añadir libros con base en las secciones, pisos y sedes.
        String accion = elegirAccion(); //Se ingresa la acción a hacer. Dependiendo de la acción, se hará lo correspondiente.

        if (accion.equals("modificar") ==true){
            editarLibro(libro);
        }if (accion.equals("eliminar") ==true){
            System.out.println("Para eliminar esta variable, se debe eliminar el libro o los libros asociados a esta.");
            quitarLibro(libro);
        }if (accion.equals("añadir") ==true){
            agregarLibro(libro);
        }
    }
}
