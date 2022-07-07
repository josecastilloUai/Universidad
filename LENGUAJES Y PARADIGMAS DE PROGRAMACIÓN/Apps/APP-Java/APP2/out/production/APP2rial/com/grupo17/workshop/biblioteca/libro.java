package com.grupo17.workshop.biblioteca;

public class libro { //Clase que contiene la estructura de un libro junto con distintas funciones.
    //Atributos:
    private String titulo;
    private String autor;
    private int año;
    private int estante_numero;
    private String estante_seccion;
    private int piso;
    private String edificio;
    private String sede;

    public libro(String titulo, String autor, int año, int estante_numero, String estante_seccion, int piso, String edificio, String sede) { //Setter.
        this.titulo = titulo;
        this.autor = autor;
        this.año = año;
        this.estante_numero = estante_numero;
        this.estante_seccion = estante_seccion;
        this.piso = piso;
        this.edificio = edificio;
        this.sede = sede;
    }
    //Setters que sirven para modificar los valores del libro en cuestión luego de definirlo.
    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }
    public void setAutor(String autor) {
        this.autor = autor;
    }
    public void setAño(int año) {
        this.año = año;
    }
    public void setEstante_numero(int estante_numero) {
        this.estante_numero = estante_numero;
    }
    public void setEstante_seccion(String estante_seccion) {
        this.estante_seccion = estante_seccion;
    }
    public void setPiso(int piso) {
        this.piso = piso;
    }
    public void setEdificio(String edificio) {
        this.edificio = edificio;
    }
    public void setSede(String sede) {
        this.sede = sede;
    }

    //Para acceder a los atributos (imprimir u otra cosa), hay que usar un get. (Getters)
    public String getTitulo(){
        return titulo;
    }
    public String getAutor() {
        return autor;
    }
    public int getAño() {
        return año;
    }
    public int getEstante_numero() {
        return estante_numero;
    }
    public String getEstante_seccion() {
        return estante_seccion;
    }
    public int getPiso() {
        return piso;
    }
    public String getEdificio() {
        return edificio;
    }
    public String getSede() {
        return sede;
    }

    public void printDatos(){ //Procedimiento que imprime los atributos del libro.
        System.out.println(titulo + ", " + autor + ", " + año + ", " + estante_numero + ", " + estante_seccion + ", " + piso + ", " + edificio + ", " + sede);
    }
}
