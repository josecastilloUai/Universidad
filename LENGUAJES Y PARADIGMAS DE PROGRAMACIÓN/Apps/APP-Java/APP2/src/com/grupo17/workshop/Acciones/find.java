package com.grupo17.workshop.Acciones;

import com.grupo17.workshop.biblioteca.libro;
import java.util.List;

public class find extends edition{ //Clase que modifica un libro.

    public void Find(List<libro> libro){ //Procedimiento que filtra la búsqueda de un atributo dentro del Arraylist.
        String  filtro= elegirCarac(); //Se introduce atributo a cambiar.
        String atributo = filtrarDato();
        for(int i=0; i<=(libro.size()-1); i++){ //Se recorren todos los libros dentro del ArrayList.
            if (filtro.equals("Titulo")==true) { //Si el filtro ingresado es Titulo, se muestran todos los libros que contienen un Atributo ingresado similar al Titulo dentro del ArrayList.
                if (libro.get(i).getTitulo().contains(atributo)){
                    libro.get(i).printDatos();
                }
            }
            else if (filtro.equals("Autor")==true){ //Si el filtro ingresado es Autor, se muestran todos los libros que contienen un Atributo ingresado similar al Autor dentro del ArrayList.
                if (libro.get(i).getAutor().contains(atributo)){
                    libro.get(i).printDatos();
                }
            }
            else if (filtro.equals("Año")==true){ //Si el filtro ingresado es Año, se muestran todos los libros que contienen un Atributo ingresado igual al Año dentro del ArrayList.
                if (Integer.parseInt(atributo) == libro.get(i).getAño()){
                    libro.get(i).printDatos();
                }
            }
            else if (filtro.equals("Estante_numero")==true){ //Si el filtro ingresado es Estante_numero, se muestran todos los libros que contienen un Atributo ingresado igual a Estante_numero dentro del ArrayList.
                if (Integer.parseInt(atributo) == libro.get(i).getEstante_numero()){
                    libro.get(i).printDatos();
                }
            }
            else if (filtro.equals("Estante_seccion")==true){ //Si el filtro ingresado es Estante_seccion, se muestran todos los libros que contienen un Atributo ingresado similar a Estante_seccion dentro del ArrayList.
                if (libro.get(i).getEstante_seccion().contains(atributo)){
                    libro.get(i).printDatos();
                }
            }
            else if (filtro.equals("Piso")==true){ //Si el filtro ingresado es Piso, se muestran todos los libros que contienen un Atributo ingresado igual al Piso dentro del ArrayList.
                if (Integer.parseInt(atributo) == libro.get(i).getPiso()){
                    libro.get(i).printDatos();
                }
            }
            else if (filtro.equals("Edificio")==true){ //Si el filtro ingresado es Edificio, se muestran todos los libros que contienen un Atributo ingresado similar al Edificio dentro del ArrayList.
                if (libro.get(i).getEdificio().contains(atributo)){
                    libro.get(i).printDatos();
                }
            }
            else if (filtro.equals("Sede")==true){ //Si el filtro ingresado es Sede, se muestran todos los libros que contienen un Atributo ingresado similar a la Sede dentro del ArrayList.
                if (libro.get(i).getSede().contains(atributo)){
                    libro.get(i).printDatos();
                }
            }
        }
    }
}

