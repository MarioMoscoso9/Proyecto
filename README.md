## 1Mario Armando Moscoso Becerra ||A01712209
# Descripción del Algoritmo de Ranking NFL Temporadas 2018 a 2023
En este código se desarrolló un sistema para el análisis de la información sobre la liga de fútbol americano NFL (National Football League), donde se analizan las siguientes estadísticas:

- Touchdowns: Es cuando un jugador lleva el balón más allá de la línea de anotación, es decir, a la zona de anotación, ya sea corriendo o atrapando un pase dentro de la zona de anotación.
- Intercepciones: Ocurre cuando un jugador de la defensa atrapa un pase lanzado por el quarterback del equipo contrario, cambiando la posesión del balón e interrumpiendo el avance de la ofensiva.
- Pases completados: Se refiere a los pases que el quarterback lanza y que son atrapados por un receptor de su equipo sin que el balón toque el suelo.
- Sacks (capturas): Ocurre cuando un jugador defensivo derriba al quarterback del equipo detrás de la línea de golpeo mientras este intenta dar un pase.

El código implementa el algoritmo de Merge Sort para ordenar vectores que contienen las estadísticas seleccionadas por el usuario, así como el año también seleccionado por el usuario.

El código utiliza un ciclo while que se ejecuta mientras haya líneas en el archivo .txt y se detiene cuando getline devuelve false. Además, se toman en cuenta las líneas vacías o espacios en el .txt para que el ciclo continúe. Adicionalmente, se verifica si la línea contiene un #, que indica un comentario, para saltar esa línea y continuar el bucle.

En el código se hace uso de stringstream, una clase de la biblioteca de C++ que brinda una forma de manipular cadenas de texto. Específicamente, se utiliza para obtener las estadísticas a modo de cadena de texto para posteriormente transformarlas a entero con ayuda del comando stoi (string to integer) y una variable temporal.

Se utiliza un switch para, dependiendo de la elección del usuario conforme a la estadística de su interés, guardar los valores en el vector rank. También se guarda en un vector los nombres de los equipos de tal manera que, dependiendo de la estadística, se incluyan los nombres de los equipos en las estadísticas. Cabe recalcar que se utiliza el tipo de dato size_t, ya que se usa para representar tamaños de objetos como los vectores. Finalmente, se utiliza el sort para ordenar las estadísticas de menor a mayor y se hace otro vector para ordenar los nombres de los equipos de acuerdo a las estadísticas.

## Cómo compilar y ejecutar

Para compilar el archivo:

```bash
g++ ord.h main.cpp -o proyecto
```
Para correr el archivo:
```bash
./proyecto
```

## Subcompetencias

### SICT0301: Evalúa los componentes
Se realizó el programa usando el algoritmo de ordenamiento Merge Sort, el cual divide el vector en mitades, ordena cada mitad de forma recursiva y luego fusiona las partes ordenadas. La complejidad espacial de Merge Sort es O(n) ya que se necesita espacio adicional para los vectores usados durante la ejecución y tiene una complejidad temporal de O(n log n) en el peor caso, promedio y mejor, significando que el tiempo requerido para ordenar los datos es predecible y controlable.

### SICT0302: Toma decisiones
Se tuvieron que ordenar aproximadamente 600 datos, para lo cual el Merge Sort se presentó como una opción adecuada y eficiente por estas razones:
- Aunque 600 datos no son muy grandes, Merge Sort maneja eficientemente conjuntos de datos medianos a grandes, por lo que el rendimiento de O(n log n) asegura que el tiempo de ejecución no se degrade significativamente.
- Aunque requiere espacio adicional O(n) debido a los vectores temporales, este requisito es muy manejable para 600 datos, ya que no debería ser un problema tomando en cuenta el conjunto de datos.
- Dado que el tamaño de los datos es adecuado para ser manejado en memoria, Merge Sort es una excelente opción, ya que el algoritmo divide el conjunto de datos en subvectores más pequeños y los fusiona, lo que es eficiente cuando el tamaño de los datos no supera la capacidad de la memoria disponible.
