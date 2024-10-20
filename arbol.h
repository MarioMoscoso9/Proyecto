#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include <string>
#include <map>  // Para almacenar estadísticas por año

// Estructura que almacena las estadísticas de un equipo
struct Estadisticas {
    int touchdowns;
    int intercepciones;
    int completos;
    int sacks;

    // Constructor que inicializa los valores de Estadisticas
    Estadisticas(int td, int inte, int cmp, int sck)
        : touchdowns(td), intercepciones(inte), completos(cmp), sacks(sck) {}

    // Constructor por defecto
    Estadisticas() : touchdowns(0), intercepciones(0), completos(0), sacks(0) {}
};


// Nodo del árbol
struct Nodo {
    std::string equipo;
    std::map<int, Estadisticas> statsPorAnio; // Mapa para estadísticas por año
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(const std::string& eq)
        : equipo(eq), izquierda(nullptr), derecha(nullptr) {}
};

class Arbol {
private:
    Nodo* raiz;

    // Inserta un nodo en el árbol, asociando un equipo con estadísticas por año
    void insertar(Nodo*& nodo, const std::string& equipo, int anio, Estadisticas estadistica);

    // Busca un nodo en el árbol y devuelve las estadísticas si lo encuentra
    Nodo* buscar(Nodo* nodo, const std::string& equipo) const;

public:
    Arbol() : raiz(nullptr) {}

    // Función pública para insertar un equipo y sus estadísticas
    void insertar(const std::string& equipo, int anio, Estadisticas estadistica) {
        insertar(raiz, equipo, anio, estadistica);
    }

    // Función pública para buscar un equipo y mostrar sus estadísticas si lo encuentra
    void buscarYMostrarEstadisticas(const std::string& equipo, int anio) const;
};

// Implementación de insertar: agrega o actualiza estadísticas para un equipo en un año
void Arbol::insertar(Nodo*& nodo, const std::string& equipo, int anio, Estadisticas estadistica) {
    if (nodo == nullptr) {
        nodo = new Nodo(equipo);
        nodo->statsPorAnio[anio] = estadistica;  // Guardar las estadísticas para ese año
    } else if (equipo < nodo->equipo) {
        insertar(nodo->izquierda, equipo, anio, estadistica);
    } else if (equipo > nodo->equipo) {
        insertar(nodo->derecha, equipo, anio, estadistica);
    } else {
        // Si el equipo ya existe, actualizamos las estadísticas para ese año
        nodo->statsPorAnio[anio] = estadistica;
    }
}

// Implementación de buscar: busca un equipo y retorna el nodo si lo encuentra
Nodo* Arbol::buscar(Nodo* nodo, const std::string& equipo) const {
    if (nodo == nullptr) {
        return nullptr; // No se encontró el equipo
    } else if (equipo == nodo->equipo) {
        return nodo; // Se encontró el equipo
    } else if (equipo < nodo->equipo) {
        return buscar(nodo->izquierda, equipo);
    } else {
        return buscar(nodo->derecha, equipo);
    }
}

// Función para buscar un equipo y mostrar sus estadísticas
void Arbol::buscarYMostrarEstadisticas(const std::string& equipo, int anio) const {
    Nodo* resultado = buscar(raiz, equipo);
    if (resultado != nullptr) {
        // Si el equipo existe, buscamos si tiene estadísticas para el año dado
        if (resultado->statsPorAnio.find(anio) != resultado->statsPorAnio.end()) {
            Estadisticas stats = resultado->statsPorAnio[anio];
            std::cout << "Estadísticas del equipo " << equipo << " en el año " << anio << ":\n";
            std::cout << "Touchdowns: " << stats.touchdowns << std::endl;
            std::cout << "Intercepciones: " << stats.intercepciones << std::endl;
            std::cout << "Pases completos: " << stats.completos << std::endl;
            std::cout << "Sacks: " << stats.sacks << std::endl;
        } else {
            std::cout << "No hay estadísticas para el año " << anio << " para el equipo " << equipo << "." << std::endl;
        }
    } else {
        std::cout << "El equipo " << equipo << " no fue encontrado en las estadísticas." << std::endl;
    }
}

#endif // ARBOL_H
