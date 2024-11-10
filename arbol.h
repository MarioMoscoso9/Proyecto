//Mario Armando Moscoso Becerra||A01712209
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
