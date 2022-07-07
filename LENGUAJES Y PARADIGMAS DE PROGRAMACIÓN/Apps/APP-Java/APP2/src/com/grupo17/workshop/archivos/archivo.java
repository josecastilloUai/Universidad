package com.grupo17.workshop.archivos;

import com.grupo17.workshop.biblioteca.libro;
import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class archivo { //Clase archivo, la cual tiene de atributo el directorio del archivo y de función leer el csv dado, el cual es almacenado en un ArrayList.
    private static String nombre;
    public archivo(String newNombre) { //Setter
        this.nombre = newNombre;
    } //Setter.

    public List<libro> leerDatos(){ //Función que devuelve un ArrayList del objeto Libros. Se lee del csv dado.

        String line = ""; //Este string irá guardando las lineas del csv.
        List<libro> libro = new ArrayList<libro>(); //Creamos una lista vacía.
        int count = 0; //Contador que sirve para salta la primera linea con los encabezados.

        try {
            BufferedReader obj = new BufferedReader(new FileReader(nombre)); //Se lee el archivo.
            while ((line = obj.readLine()) != null){ //Se le dice que linea tome el valor de cada linea del archivo csv. Este ciclo finaliza cuando no hay más que leer.

                String[] values = line.split("\""); //Aquí se le dice que separe la linea por comillas y la guarde en una lista de Strings. (Esto es debido a que el archivo original tiene algunos titulos entre comillas, lo cual genera problemas).

                if(count==0){
                    count++; //Se salta los encabezados.
                    continue;
                }
                if (values.length==1){ //Si no hay comillas en la línea, entra en esta condición.
                    String[] aux = line.split(","); //Por lo tanto, se le dice que separe la línea por las comas y almacena en una lista de Strings.
                    libro texto = new libro(aux[0], aux[1], Integer.parseInt(aux[2]), Integer.parseInt(aux[3]), aux[4], Integer.parseInt(aux[5]), aux[6], aux[7]); //Luego cada valor de la lista es dado para que se cree un nuevo libro
                    libro.add(texto); //Por último se añade este libro a la ArrayList.
                }
                else { //En caso de que si existan comillas en la línea, entra aquí.
                    String[] aux2 = values[2].split(","); //Se le dice que el resto de la línea (después del título que está entre comillas) se separe por comas.
                    libro texto = new libro(values[1], aux2[1], Integer.parseInt(aux2[2]), Integer.parseInt(aux2[3]), aux2[4], Integer.parseInt(aux2[5]), aux2[6], aux2[7]); //Se le dan los nuevos valores para que se cree un nuevo libro.
                    libro.add(texto); //Se añade el libro a la Arraylist.
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("El archivo no existe!");
            throw new RuntimeException(e);
        } catch (IOException e) {
            System.out.println("Error.");
            throw new RuntimeException(e);
        }
        return libro;
    }

    public void rewrite(List<libro> libro){ //Procedimiento que reescribe el csv con las modificaciones al Arraylist de libros.
        try {
            BufferedWriter re = new BufferedWriter(new FileWriter(nombre)); //Se abre el archivo en modo escritura.
            re.write("titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede"); //Se le dan los encabezados.
            for(int i=0; i<=(libro.size()-1); i++){ //Ciclo donde se van escribiendo los datos de todos los libros del ArrayList dado.
                libro aux= libro.get(i);
                re.write("\n"+("\""+aux.getTitulo()+"\"" +","+aux.getAutor() +"," + aux.getAño() + "," +aux.getEstante_numero()  + "," +  aux.getEstante_seccion()+ "," + aux.getPiso()  + "," + aux.getEdificio() + ","+ aux.getSede()));
            }
            re.close(); //Se cierra el archivo.
        }catch (IOException e){ System.out.println("Error.") ;e.printStackTrace();}
    }
}
