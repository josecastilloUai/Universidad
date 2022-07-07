package com.grupo17.workshop.vista;

import java.util.Scanner;

public class menu {
    protected static int choice;

    public menu(int choice) {
        this.choice = choice;
    }

    public void init(){ //Procedimiento que inicia el menú.

        System.out.println("\nBienvenido a la biblioteca UAI, ¿Que le gustaria hacer?, a continuación se muestran las acciones disponibles.\n");
        System.out.println("0.- Salir.");
        System.out.println("1.- Mostrar todos los libros disponibles.");
        System.out.println("2.- Buscar un libro.");
        System.out.println("3.- Agregar un libro.");
        System.out.println("4.- Quitar un libro.");
        System.out.println("5.- Editar un libro.");
        System.out.println("6.- Agregar/Quitar/Modificar sede de un libro.");
        System.out.println("7.- Agregar/Quitar/Modificar piso de un libro.");
        System.out.println("8.- Agregar/Quitar/Modificar seccion de un libro.");

        Scanner input = new Scanner(System.in);  // Create a Scanner object
        System.out.println("Ingrese su opción: ");
        int eleccion = Integer.parseInt(input.nextLine());
        this.choice = eleccion; //Se guarda y se settea la elección del usuario.
    }
    public int getChoice() {
        return choice;
    }
}
