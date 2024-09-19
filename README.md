# Descripcion algoratimo de ranking NFL temporadas 2018 a 2023
En este codigo se desarrollo un sistema para el analisis de la informacion sobre la liga de futbol americano NFL (National Football League) donde se analizan las siguientes estadisticas:
- Touchdowns: Es cuando un jugador lleva el balon mas alla de la linea de anotacion es decir a la zona de anotacion ya sea corriendo o atrapando un pase dentro de la zona de anotacion.
- Intercepciones: Ocurre cunado un jugador de la defensa atrapa un pase lanzado por el quaterback del equipo contrario, cambiando la posesion del balon, interrumpiendo el avance de la ofensiva.
- Pases completados: Se refiere a los pases que el quarterback lanza y que son atrapados por un receptor de su equipo sin que el balon toque el suelo.
- Sacks (capturas): Ocurre cunado un jugador defensivo derriba al quaterback del equipo detras de la linea de golpeo minetras este intenta dar un pase.

El codigo implementa el algoritmo de Merge Sort utilizando y ordenando vectores los cuales ordenan las estadisticas seleccionadas por el usuario asi como el año de igual forma seleccionado por el usuario. 

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
Se realizo en programa usando el algoritmo de ordenamiento Merge Sort el cual divide en mitades el vector, y ordena de mitad de forma recursiva y luego fusiona las partes ordenadas. La complejidad espacial de Merge sort es O(n) ya que se necesita espacio adicional para los vectores usados en el tiempo de ejecucion y tiene una complejidad temporal de O(n log n) en el peor caso, promedio y mejor, signficando que el tiempo requerido para ordenar los datos es predecible y controlable.

### SICT0302: Toma decisiones
Se tuvieron que ordenar aproximadamente 600 datos, para lo cual el Merge Sort se presentó como una opcion adecuada y eficiente por estas razones:
- Aunque 600 datos no son muy grabdes Merge Sort maneja eficientemente conjuntos de datos medianos a grandes por lo que el rendimiento de O (n log n) asegura que el tiempo de ejecucion no se degrade significativamente.
- Aunque requiere espacio adicional O(n) dado los vectores temporales, este requisito es muy manejable para 600 datos ya que no deberia sert un porblema tomando en  cuenta el conjunto de datos.
- Ya que el tamaño de datos es adecuado para ser manejado en memoria Merge es una gran opcion ya que el lgoritmo divide el conjunto de datos en subvectores más pequeños y los fusiona, lo que es eficiente cuando el tamaño de los datos no supera la capacidad de la memoria disponible.
