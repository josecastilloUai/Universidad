package com.grupo17.workshop.Acciones;

import java.util.Scanner;

public class specificaction{ //Clase que cuenta con procedimientos básicos para el correcto y ágil funcionamiento de las demás clases del paquete.
    public String introducirLibro(){ //Función que solicita ingresar el titulo de un libro. Devuelve un String con el valor ingresado.
        Scanner input = new Scanner(System.in);  // Create a Scanner object
        System.out.println("Título del libro: ");
        String nombre_libro = input.nextLine();
        return nombre_libro;
    }
    public String elegirCarac(){ //Función que solicita ingresar el atributo de un libro. Devuelve un String con el valor ingresado.
        Scanner input = new Scanner(System.in);  // Create a Scanner object
        System.out.println("Ingrese que atributo desea modificar/buscar (Primera letra con mayusucula, resto con minusculas): ");
        String carac = input.nextLine();
        return carac;
    }
    public String elegirAccion(){ //Función que solicita ingresar la acción a realizar para un libro. Devuelve un String con el valor ingresado.
        Scanner input = new Scanner(System.in);  // Create a Scanner object
        System.out.println("Ingrese que dato desea hacer (modificar, eliminar o añadir): ");
        String accion = input.nextLine();
        return accion;
    }

    public String introducirDato(){ //Función que solicita ingresar un nuevo valor para un atributo de un libro. Devuelve un String con el valor ingresado.
        Scanner input = new Scanner(System.in);  // Create a Scanner object
        System.out.println("Introduzca el nuevo valor: ");
        String dato_spec = input.nextLine();
        return dato_spec;
    }
    public String filtrarDato(){ //Función que solicita ingresar el filtro de búsqueda de uno o varios libros. Devuelve un String con el valor ingresado.
        Scanner input = new Scanner(System.in);  // Create a Scanner object
        System.out.println("Ingrese el valor del atributo para filtrar la búsqueda: ");
        String filtro = input.nextLine();
        return filtro;
    }
}
