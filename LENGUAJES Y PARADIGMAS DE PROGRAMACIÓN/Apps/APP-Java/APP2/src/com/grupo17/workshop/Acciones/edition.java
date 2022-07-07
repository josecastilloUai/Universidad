package com.grupo17.workshop.Acciones;

import com.grupo17.workshop.biblioteca.libro;

import java.util.List;

public class edition extends specificaction{ //Clase que modifica un libro.
    public void Cambio(List<libro> libro){ //Procedimiento que genera el cambio de un atributo de un libro del Arraylist.

        String nombre_libro = introducirLibro(); //Se introduce título del libro.
        String carac = elegirCarac(); //Se introduce atributo a cambiar.
        String new_dato = introducirDato(); //Se introduce nuevo valor del atributo a cambiar.
        int nro_libro = 0;

        for(int i=0; i<=(libro.size()-1); i++){ //Ciclo que busca el libro por título.
            if (nombre_libro.equals(libro.get(i).getTitulo())==true){
                nro_libro = i;
            }
        }

        System.out.println("¿Qué desea cambiar?");
        libro aux = libro.get(nro_libro); //Libro específico a cambiar.

        //Aquí según lo que se quiera cambiar, sé utiliza un nuevo setter del objeto libro con lo que se cambia su valor anterior.
        if (carac.equals("Titulo")==true) {
            aux.setTitulo(new_dato);
            System.out.println("Titulo editado correctamente");
        }
        else if (carac.equals("Autor")==true){
            aux.setAutor(new_dato);
            System.out.println("Autor editado correctamente");
        }
        else if (carac.equals("Año")==true){
            aux.setAño(Integer.parseInt(new_dato));
            System.out.println("Año editado correctamente");
        }
        else if (carac.equals("Estante_numero")==true){
            aux.setEstante_numero(Integer.parseInt(new_dato));
            System.out.println("Numero de estante editado correctamente");
        }
        else if (carac.equals("Estante_seccion")==true){
            aux.setEstante_seccion(new_dato);
            System.out.println("Seccion de estante editada correctamente");
        }
        else if (carac.equals("Piso")==true){
            aux.setPiso(Integer.parseInt(new_dato));
            System.out.println("Piso editado correctamente");
        }
        else if (carac.equals("Edificio")==true){
            aux.setEdificio(new_dato);
            System.out.println("Edificio editado correctamente");
        }
        else if (carac.equals("Sede")==true){
            aux.setSede(new_dato);
            System.out.println("Sede editada correctamente");
        }
    }
}
