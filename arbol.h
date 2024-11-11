// Mario Armando Moscoso Becerra || A01712209
#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
#include <string>
#include <map>  
using namespace std;

class Estadisticas {
public:
    int touchdowns;
    int intercepciones;
    int completos;
    int sacks;

    Estadisticas(int td, int inte, int cmp, int sck)
        : touchdowns(td), intercepciones(inte), completos(cmp), sacks(sck) {}

    Estadisticas() : touchdowns(0), intercepciones(0), completos(0), sacks(0) {}
};


class Nodo {
public:
    string equipo;
    map<int, Estadisticas> estadisticasPorAno; 
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(const std::string& eq)
        : equipo(eq), izquierda(NULL), derecha(NULL) {}
};

class Arbol {
private:
    Nodo* raiz;
    void insertar(Nodo*& nodo, const std::string& equipo, int anio, Estadisticas estadistica);
    Nodo* buscar(Nodo* nodo, const std::string& equipo) const;

public:
    Arbol() : raiz(NULL) {}

    void insertar(const std::string& equipo, int ano, Estadisticas estadistica) {
        insertar(raiz, equipo, ano, estadistica);
    }
    
    void buscarYMostrarEstadisticas(const std::string& equipo, int anio) const;
};

/*
Inserta un equipo con sus estadísticas por año en el árbol binario de búsqueda.
- Mejor caso: O(1), cuando el árbol está vacío y se inserta en la raíz, ya que cuando el árbol está vacío 
  y el nodo se inserta directamente en la raíz, sin necesidad de recorrer.
- Caso promedio: O(log n) en un árbol balanceado ya que en un árbol balanceado, cada inserción 
  implica recorrer solo una rama hacia la posición de inserción, lo cual toma tiempo logarítmico.
- Peor caso: O(n) si el árbol está completamente desbalanceado y se comporta como una lista. Ocurre en un 
  árbol desbalanceado (como una lista), donde cada inserción tiene que recorrer toda la "lista" hasta el final.
*/
void Arbol::insertar(Nodo*& nodo, const std::string& equipo, int ano, Estadisticas estadistica) {
    if (nodo == NULL) {
        nodo = new Nodo(equipo);
        nodo->estadisticasPorAno[ano] = estadistica;  
    } else if (equipo < nodo->equipo) {
        insertar(nodo->izquierda, equipo, ano, estadistica);
    } else if (equipo > nodo->equipo) {
        insertar(nodo->derecha, equipo, ano, estadistica);
    } else {
        nodo->estadisticasPorAno[ano] = estadistica;
    }
}

/*
Busca un nodo en el árbol binario de búsqueda que contenga el equipo especificado.
- Mejor caso: O(1), cuando el equipo está en la raíz ya que la búsqueda es inmediata.
- Caso promedio: O(log n) en un árbol balanceado ya que la búsqueda en cada nivel reduce a la mitad el 
  número de nodos a recorrer, resultando en complejidad logarítmica.
- Peor caso: O(n) si el árbol está desbalanceado. Ocurre en un árbol desbalanceado, donde se requiere 
  recorrer todos los nodos de una "lista" hasta encontrar el valor o alcanzar un nodo nulo.
*/
Nodo* Arbol::buscar(Nodo* nodo, const std::string& equipo) const {
    if (nodo == NULL) {
        return NULL; 
    } else if (equipo == nodo->equipo) {
        return nodo; 
    } else if (equipo < nodo->equipo) {
        return buscar(nodo->izquierda, equipo);
    } else {
        return buscar(nodo->derecha, equipo);
    }
}

/*
Busca un equipo en el árbol y muestra las estadísticas del año especificado si existen.
- Mejor caso: O(1), si el equipo está en la raíz y las estadísticas para el año están en la primera posición 
  del mapa. Sucede si el equipo buscado está en la raíz y el año solicitado es el primero en el mapa estadisticasPorAno.
- Caso promedio: O(log n) para la búsqueda en el árbol + O(log m) para la búsqueda en el mapa, donde n es 
  el número de nodos y m es el número de años registrados para el equipo. En promedio, el acceso a ambos 
  es logarítmico (si el árbol está balanceado y el mapa usa un árbol balanceado internamente).
- Peor caso: O(n) para la búsqueda en el árbol (árbol desbalanceado) + O(log m) para la búsqueda en el mapa. 
  Ocurre si el árbol está desbalanceado y requiere recorrer muchos nodos. El acceso al año en el mapa sigue 
  siendo O(log m) dado que map utiliza un árbol balanceado internamente.
*/
void Arbol::buscarYMostrarEstadisticas(const std::string& equipo, int ano) const {
    Nodo* resultado = buscar(raiz, equipo);
    if (resultado != NULL) {
        if (resultado->estadisticasPorAno.find(ano) != resultado->estadisticasPorAno.end()) {
            Estadisticas stats = resultado->estadisticasPorAno[ano];
            cout << "Estadísticas del equipo " << equipo << " en el año " << ano << ":\n";
            cout << "Touchdowns: " << stats.touchdowns << endl;
            cout << "Intercepciones: " << stats.intercepciones << endl;
            cout << "Pases completos: " << stats.completos << endl;
            cout << "Sacks: " << stats.sacks << endl;
        } else {
            cout << "No hay estadísticas para el año " << ano << " para el equipo " << equipo << "." << endl;
        }
    } else {
        cout << "El equipo " << equipo << " no fue encontrado en las estadísticas." << endl;
    }
}

#endif // ARBOL_H
