package com.grupo17.workshop.vista;

import com.grupo17.workshop.biblioteca.libro;
import java.util.List;

public class choicemenu extends submenu{ //Clase que dependiendo de la decisión del usuario, ejecutará un procedimiento de cierta manera.
    private static List<libro> libro;

    public choicemenu(List<com.grupo17.workshop.biblioteca.libro> libro){ //Setter
        super(choice);
        this.libro = libro;
    }
    public void decision(){ //Procedimiento que dependiendo de la decisión, ejecutará cierta función del SubMenu.

        if(choice==1){
            Submenu1(libro);
        } else if (choice==2) {
            Submenu2(libro);
        } else if (choice==3) {
            Submenu3(libro);
        } else if (choice==4) {
            Submenu4(libro);
        } else if (choice==5) {
            Submenu5(libro);
        } else if (choice==6) {
            Submenu6(libro);
        } else if (choice==7) {
            Submenu7(libro);
        } else if (choice==8) {
            Submenu8(libro);
        }
    }
}
