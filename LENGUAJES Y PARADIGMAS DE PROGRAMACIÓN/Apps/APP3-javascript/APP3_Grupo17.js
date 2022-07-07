var _= require("underscore");
const {readFileSync, promises: fsPromises} = require('fs');

function syncReadFile(filename) { //Función que lee el archivo.
  const contents = readFileSync(filename, 'utf-8');
  const arr = contents.split(/\r?\n/); //Separa el archivo texto por fila.
  return arr;
}

function toNumber(array,i){ //Función que convierte una matriz (matriz de matrices en este caso) de strings en una de números.
  if(array[i]==null){} //Caso base. Si es nulo, se termina la función y retorna null.
  else {
    array[i]= array[i].map(Number); //Toma la primera fila y la convierte en números.
    toNumber(array,i+1); //Se hace lo mismo con la siguiente fila.
  }
  return array; //Retorna el array.
}

function splitrow(data,i) {//Función separa las filas. 
  if (data[i]==null){return}//Caso base. Si es nulo, se termina la función y retorna null.
  else{
    data[i]=data[i].split(" "); //Se separa las filas por espacio.
    splitrow(data,i+1); //Se hace lo mismo con la siguiente fila.
  }
  return toNumber(data,0); //Se retorna la matriz (se pasa de strings a números).
}

function findxy(array , x , y){ //Función que encuentra ciertas coordenadas. Se le da una matriz y dos números (x e y de una coordenada).
  if (!array){return null} //Caso base
  else { 
    return array.find(coordinate => coordinate[0]==y && coordinate[1]==x); //Se busca en la matriz de path (matriz de matrices, donde cada matriz dentro de esta contiene 2 valores, x e y). Retorna null si no se encuentran los valores en orden.
  }
}

function initxy(array, y){ //Función que busca las coordenas iniciales del laberinto (asumiendo que siempre se parte del lado izquierdo y que habrá un 0 en la primera fila).
  let init_path = [];

  if(array[y][0]==1){ //Si en la posición hay un 1, se avanza hacia abajo en la primera fila.
    return initxy(array,y+1);
  }
  else { //Si se encuentra un 0, se inserta en init_path y se termina la recursión.
    init_path.push([0,y]);
  }
  return init_path; //Se retornan las coordenadas iniciales.
}

function findPaths( mat, path,  i, j) { //Función que recorre el laberinto. Se avanza si hay un 0, si hay un 1 no se puede avanzar. Se imprimen los posibles caminos.
    if (mat == null || mat.length == 0) { //Caso base, matriz nula o sin datos.
        return;
    }

    let M = mat.length; //Cantidad filas que posee la matriz.
    let N = mat[0].length; //Cantidad columnas que posee la matriz.

    //Si se llega a la última columna de la matriz, y el valor observado es igual a cero, entonces se agrega la última coordenada al path y luego se termina la función, mostrando por pantalla todos los posibles caminos.
    if (j==N-1 && mat[i][j]==0) {
        path.push([j,i]);
        console.log("Posible camino:\n");
        console.log(path, "\n");
        path.pop();
        return;
    }

    path.push([j,i]); //Se agrega la coordenada actual al path.

    //Desplazamiento hacia la derecha.
    if ((i >= 0 && i < M && j + 1 >= 0 && j + 1 < N && mat[i][j+1] == 0 && findxy(path,i, j+1)==null)) {
        findPaths(mat, path, i, j + 1);
    }

    //Desplazamiento hacia abajo.
    if ((i + 1 >= 0 && i + 1 < M && j >= 0 && j < N && mat[i+1][j] == 0 && findxy(path,i+1, j)==null)) {
        findPaths(mat, path, i + 1, j);
    }

    //Desplazamiento hacia arriba.
    if ((i - 1 >= 0 && j >= 0 && j < N && mat[i-1][j] == 0 && findxy(path,i-1, j)==null)){
        findPaths(mat, path, i - 1, j);
    }

    //Desplazamiento hacia la izquierda.
    if ((i >= 0 && i < M && j -1 >= 0 && mat[i][j+1] == 0 && findxy(path,i, j-1)==null)) {
        findPaths(mat, path, i, j - 1);
    }

    path.pop(); //Backtracking: Se elimina la coordenada actual del path si no se cumple ninguna de las condiciones.
}
let data = syncReadFile('./input.txt'); //Se lee el archivo y se convierte en matriz su contenido(se debe darle el nombre correcto del archivo)
let Mat = splitrow(data,0); //Se convierte la matriz de strings a números y se separan por filas.
//console.log(Mat) //Muestra el laberinto

let init_x_y = initxy(Mat,0); //Coordenada iniciales
let path = []; //Lista vacia que corresponde al camino que se puede recorrer en el laberinto
findPaths(Mat, path, init_x_y[0][1], init_x_y[0][0]); //
