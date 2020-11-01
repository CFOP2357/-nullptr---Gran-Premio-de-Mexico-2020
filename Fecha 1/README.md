# Fecha 1 \#GranPremioMX2020

## H

*dp, fuerza bruta, greedy*

dp en tiempo O(n)

## G

*Diccionario*

Crear un diccionario que mapea los términos a la cantidad de golpes por encima o por debajo del *par* que necesito el golfista, sumar el par mas el valor del termino obtenido para cada hoyo. Si es el caso *hole in one* no sumar el valor del par del hoyo, sumar unicamente uno (1).

## E
*fuerza bruta, teoria de numeros*

Probar todas las posibilidades. Sea $n$ el tamaño de la cadena.
* Generamos todas las permutaciones de la cadena, esto es O(n!).
* Para cada una de estas permutaciones generamos todas las combinaciones de tres números. Esto se puede hacer en O(n^2).
* Para cada uno de estos tres números comprobamos que es primo, siendo el posible primo un número k basta con una prueba de primalidad O(sqrt(k)).
* Si todos los numeros son primos actualizar si el producto es menor a la respuesta que se tiene hasta el momento.

## D

*data structures, search and sorting*

Contar cuántos elementos tienen elementos más grandes a su derecha, tener guardado en un multiset los elementos que están a la derecha, conforme se va iterando irlos eliminando del multiset, cuando se encuentra un elemento que se va a mover, entonces este se va hacia la derecha (no lo eliminan del multiset)

## I:
*strings, lenguaje*

Para las reglas 1, 2 y la primera parte de la 3 (tener al menos un digito) para cada caracter revisamos que se encuentren en los intervalos de caracteres ascii ['a', 'b'], ['A', 'B'] y ['0', '9'] respectivamente

Para la segunda parte de la regla 3 (no dos digitos consecutivos) buscamos todas las subcadenas invaalidas dentro de la contraseña
  ```
  {"01", "12", "23", "34", "45", "56", "67", "78", "89",
   "98", "87", "76", "65", "54", "43", "32", "21", "10"}
  ```
  
Para la regla 4 bucamos cada uno de los caracteres en la cada
  ```
  {".", "#", "$", "%", "/", "(", "&", ")"}
  ```
  
Para regla 5 revisamos el tamaño de la cadena.

Para este problema es recomendable usar un contenedor especializado en el manejo de cadenas de texto en conjunto con las herramientas del lenguaje para realizar las busquedas de subcadenas.
  

## A:

*implementation, search and sorting*

Crear un arreglo de set con prioridad de mayor en donde se guarde para cada i, todas sus j con todas las preferencias (para Q)

Crear un set con prioridad de mayor que guarde todos los pares y sus preferencias.

Tener un mapa en donde la llave sea un par, para cada conjunto  {i, j} se va guardando cuantas ocurrencias existen

* **R: O(log n)**

  Actualizar el mapa (sumar 1 a la posición {i, j}), agregar ese nuevo conjunto {producto, {i, j}} a los set (no actualizar, solo agregar, de todos modos el más grande se mantiene en begin)

* **Q: O(1)**

  Solo checar el set en la posición i del arreglo: si no tiene elementos la respuesta es “no info”, si los primeros dos elementos tienen el mismo valor en el producto la respuesta es “múltiple”, si no imprimir el par de begin()

* **B: O(1)**

  Lo mismo que con Q pero en el arreglo de todo

## C:
*data structures, graph*

Verlo como un grafo, una arista conecta dos palabras. Encontrar las componentes conexas con Union Find en un mapa de {string, string}, poner como raíz de cada componente la palabra más chica, al final solo imprimir la raíz de la componente a la que pertenece cada palabra que se quiere buscar.

## B:

Contar las inversiones de cada elemento, para poder hacerlo en O(nlogn) usar Segment Tree.

## K: (dio WA)

Verlo como un grafo ponderado, el costo de cada arista es la suma de sus dos vértices.
Hacer árbol de expansión mínima, si aún queda posibilidad de agregar más aristas, irlas poniendo de menor a mayor mientras se pueda.

## F: (dio WA)

Comprobar si los platillos son suficientes para satisfacer las peticiones mínimas de casa juez y el total de platos a pedir. Calcular una permutación parcial. Si esto es posible elegir la cantidad de platillos faltantes desde los que no se sirvieron (Elegir k elementos de entre n conjuntos finitos distintos), no alcanzamos a generar fórmula/algoritmo que lo calculara a tiempo.
