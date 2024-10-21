## Mario Armando Moscoso Becerra ||A01712209
# Descripción del Algoritmo de Ranking NFL Temporadas 2018 a 2023
## Descripcion avance 1:
En este código se desarrolló un sistema para el análisis de la información sobre la liga de fútbol americano NFL (National Football League), donde se analizan las siguientes estadísticas:

- Touchdowns: Es cuando un jugador lleva el balón más allá de la línea de anotación, es decir, a la zona de anotación, ya sea corriendo o atrapando un pase dentro de la zona de anotación.
- Intercepciones: Ocurre cuando un jugador de la defensa atrapa un pase lanzado por el quarterback del equipo contrario, cambiando la posesión del balón e interrumpiendo el avance de la ofensiva.
- Pases completados: Se refiere a los pases que el quarterback lanza y que son atrapados por un receptor de su equipo sin que el balón toque el suelo.
- Sacks (capturas): Ocurre cuando un jugador defensivo derriba al quarterback del equipo detrás de la línea de golpeo mientras este intenta dar un pase.

El código implementa el algoritmo de Merge Sort para ordenar vectores que contienen las estadísticas seleccionadas por el usuario, así como el año también seleccionado por el usuario.

El código utiliza un ciclo while que se ejecuta mientras haya líneas en el archivo .txt y se detiene cuando getline devuelve false. Además, se toman en cuenta las líneas vacías o espacios en el .txt para que el ciclo continúe. Adicionalmente, se verifica si la línea contiene un #, que indica un comentario, para saltar esa línea y continuar el bucle.

En el código se hace uso de stringstream, una clase de la biblioteca de C++ que brinda una forma de manipular cadenas de texto. Específicamente, se utiliza para obtener las estadísticas a modo de cadena de texto para posteriormente transformarlas a entero con ayuda del comando stoi (string to integer) y una variable temporal.

Se utiliza un switch para, dependiendo de la elección del usuario conforme a la estadística de su interés, guardar los valores en el vector rank. También se guarda en un vector los nombres de los equipos de tal manera que, dependiendo de la estadística, se incluyan los nombres de los equipos en las estadísticas. Cabe recalcar que se utiliza el tipo de dato size_t, ya que se usa para representar tamaños de objetos como los vectores. Finalmente, se utiliza el sort para ordenar las estadísticas de menor a mayor y se hace otro vector para ordenar los nombres de los equipos de acuerdo a las estadísticas.

## Descripcion avance 2:
En el segundo avance correspondiente a almacenar datos en una estructura de datos se opto por dejar las anteriores funciones intactas es decir el ord.h con las mismas funciones del avance 1, en este avance se añadió arbol.h, el cual tiene como finalidad implementar un árbol de búsqueda binaria, el cual más adelante se explicará que se utiliza para insertar el nombre y las estadísticas de los equipos de la NFL, y que el usuario sea capaz de buscar cualquier equipo en el año deseado y el programa presentará las estadísticas. El arbol.h se caracteriza por tener primeramente la clase Estadisticas, la cual nos ayuda a organizar el conjunto de datos que mandaremos posteriormente al árbol, además de facilitar la manipulación de las mismas. Posteriormente, se declara la clase Nodo, la cual se encargará de almacenar el nombre del equipo, siendo cada equipo un nodo. Es importante resaltar que se utiliza la librería map para asociar cada equipo con las estadísticas específicas para cada año, ya que facilita almacenar, buscar y organizar los datos.

De igual manera, se implementó la clase Arbol, la cual es la encargada de organizar a los equipos y estadísticas mediante el uso del árbol. Como sabemos, cada nodo contiene un equipo, un mapa de las estadísticas y punteros hacia sus nodos izquierdo y derecho. Existen miembros presentes como:

```bash
- void insertar(Nodo*& nodo, const std::string& equipo, int anio, Estadisticas estadistica);

- Nodo* buscar(Nodo* nodo, const std::string& equipo) const;

```

De los cuales, void insertar es una función privada encargada de insertar un equipo y sus estadísticas en el árbol; este podría también ser utilizado en caso de actualizar las estadísticas de los equipos. Este método se complementa con el método público void insertar, el cual permite insertar un equipo, año y estadísticas en el árbol. Llama a la versión privada y recursiva de insertar, comenzando desde la raíz del árbol.

Por otro lado, el método Nodo* buscar es una función privada recursiva que busca un equipo específico en el árbol, comenzando desde el nodo dado. Si encuentra el equipo, devuelve el puntero a ese nodo. Este método, de igual manera, se complementa con el método void buscarYMostrarEstadisticas, que busca un equipo en el árbol y muestra las estadísticas del equipo para el año solicitado.

### Cambios sobre el primer avance
1  Únicamente se modificó el main para poder implementar la nueva función del programa correspondiente a buscar un equipo de la NFL. Primeramente se declara una instancia de la clase árbol para manejar las estadísticas de los equipos. Posteriormente se le añade la opción que permite al usuario buscar un equipo y se ha añadido un fragmento que valida si la opción ingresada por el usuario es válida.

Se continúa agregando un objeto de Estadísticas y se inserta en el árbol con el nombre del equipo y las estadísticas, donde por medio de una validación se verifica si se han encontrado las estadísticas del equipo seleccionado. Finalmente, está el fragmento de código donde se desarrolla que si el usuario eligió la opción de buscar un equipo, se solicita el nombre y se manda a llamar buscarYMostrarEstadisticas.

2  Otro cambio fue la implementación de un ciclo do-while que permite al usuario decidir si lleva a cabo otra búsqueda o no.

## Cómo compilar y ejecutar

Para compilar el archivo:

```bash
g++ ord.h arbol.h  main.cpp -o avance
```
Para correr el archivo:
```bash
./avance
```

## Subcompetencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Se realizó el programa usando el algoritmo de ordenamiento Merge Sort, el cual divide el vector en mitades, ordena cada mitad de forma recursiva y luego fusiona las partes ordenadas. La complejidad espacial de Merge Sort es O(n) ya que se necesita espacio adicional para los vectores usados durante la ejecución y tiene una complejidad temporal de O(n log n) en el peor caso, promedio y mejor, significando que el tiempo requerido para ordenar los datos es predecible y controlable.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.

La nueva función implementada se llevó a cabo con el uso de un árbol de búsqueda binaria, el cual, como sabemos, tiene una raíz y nodos, ya sea izquierdos o derechos. El análisis de complejidad de un árbol de búsqueda binaria radica en el tiempo que requieren las operaciones principales de este (inserción, búsqueda, eliminación y recorridos). Como se mencionó anteriormente, en este programa no es necesario ni insertar equipos ni eliminar, por lo que únicamente analizaremos la búsqueda y recorridos, los cuales tienen una complejidad de:
- Para el caso de búsqueda, en el caso promedio es O(log n). Si el árbol está balanceado, se puede encontrar un nodo en tiempo logarítmico al seguir el camino de comparaciones desde la raíz hacia abajo. Por otro lado, para el caso peor es O(n), ya que en un árbol desbalanceado se podría necesitar recorrer todos los nodos, lo que lleva tiempo lineal.

- Para el caso de recorridos, en cualquier caso es O(n). Cualquiera de los métodos de recorrido implica visitar cada nodo exactamente una vez, por lo que la complejidad es lineal con respecto al número de nodos. Esta complejidad se mantiene constante independientemente del equilibrio del árbol.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Se tuvieron que ordenar aproximadamente 600 datos, para lo cual el Merge Sort se presentó como una opción adecuada y eficiente por estas razones:

- Aunque 600 datos no son muy grandes, Merge Sort maneja eficientemente conjuntos de datos medianos a grandes, por lo que el rendimiento de O(n log n) asegura que el tiempo de ejecución no se degrade significativamente.

- Aunque requiere espacio adicional O(n) debido a los vectores temporales, este requisito es muy manejable para 600 datos, ya que no debería ser un problema tomando en cuenta el conjunto de datos.

- Dado que el tamaño de los datos es adecuado para ser manejado en memoria, Merge Sort es una excelente opción, ya que el algoritmo divide el conjunto de datos en subvectores más pequeños y los fusiona, lo que es eficiente cuando el tamaño de los datos no supera la capacidad de la memoria disponible.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.

Se opto por usar un arbol de busqueda binaria por diversas razones entre estas se encuentran:

- Los árboles de búsqueda binaria permiten realizar búsquedas de manera eficiente. En un árbol balanceado, el tiempo promedio de búsqueda es O(log n), lo que es significativamente más rápido que buscar en una lista desordenada, que tendría una complejidad de O(n).

- Al almacenar los equipos en un ABB, se mantiene una estructura ordenada que facilita no solo la búsqueda, sino también en el recorrido de datos. Esto es especialmente útil si se desea realizar análisis adicionales, como listar equipos en orden alfabético o por estadísticas.

- Si se diera el caso de querer añadir equipos Las operaciones de inserción y eliminación en un ABB se realizan de manera eficiente, lo que facilita la actualización de datos, además, a medida que se agregan más equipos y estadísticas, un ABB puede manejar grandes volúmenes de datos sin un impacto significativo en el rendimiento, siempre que se mantenga balanceado.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
Considero que al implementar un árbol de búsqueda binaria, se puede considerar que se está estableciendo un mecanismo efectivo para consultar información esto porque:

- Un ABB permite realizar búsquedas en tiempo logarítmico O(log n) en promedio, lo que significa que el tiempo requerido para encontrar un dato específico se reduce significativamente en comparación con estructuras de datos lineales, como listas o vectores.

- Los nodos en un ABB están organizados de tal manera que, para cualquier nodo, todos los nodos en su subárbol izquierdo son menores y todos los nodos en su subárbol derecho son mayores. Esto quiere decir que se puede navegar eficientemente a través de la estructura, facilitando la consulta de información ya que se eceuntra de nuy buena manera organizado.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

Se utilizó un ifstream para abrir y leer el archivo estadisticas.txt. Esto permite cargar datos desde un archivo externo en lugar de depender de datos dentro del programa, ademas existe un control de errores adecuado para verificar si el archivo se ha abierto correctamente. Si hay un problema al abrir el archivo, se muestra un mensaje de error y se termina el programa. Esto asegura que el programa no intente procesar datos si el archivo no está disponible para leerse, adicionalmente, el código incluye lógica para omitir líneas de comentarios y líneas vacías. Esto asegura que solo se procesen las líneas que contienen datos relevantes, mejorando el programa. Finalmente, antes de procesar los datos, se valida la opción ingresada por el usuario. Esto previene errores de entrada y mejora la experiencia del usuario.