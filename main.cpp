#include "arbol.h"
#include "ord.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm> // Para std::sort
using namespace std;
#include <algorithm>
#include <cctype>

int main() {
    char continuar;

    do {
        vector<string> equipos;
        vector<int> rank;
        Arbol arbol; // Instancia del árbol para buscar equipos
        int ano, td, inte, cmp, sck;
        string linea;
        ifstream archivo("estadisticas.txt");
        

        // Solicitar al usuario el año de interés
        int ano_interes;
        cout << "Ingrese el año que desea filtrar (2018-2023): ";
        cin >> ano_interes;

        // Solicitar la estadística a analizar
        int opcion;
        cout << "Ingresa la estadística a analizar (poner únicamente el número 1-5)" << endl;
        cout << "1. Touchdowns" << endl
             << "2. Intercepciones" << endl
             << "3. Pases completos" << endl
             << "4. Sacks (capturas)" << endl
             << "5. Buscar equipo" << endl;
        cin >> opcion;

        // Validar la opción
        if (opcion < 1 || opcion > 5) {
            cout << "Opción inválida. Por favor, elige una opción del 1 al 5." << endl;
            continue; // Volver al inicio del bucle
        }

        if (archivo.is_open()) {
            while (getline(archivo, linea)) {
                // Saltar las líneas de comentarios y líneas vacías
                if (linea.empty() || linea[0] == '#') continue;

                stringstream ss(linea);
                string equipo, tempStr;

                // Leer año
                if (!getline(ss, tempStr, ',')) continue;
                ano = stoi(tempStr);

                // Leer equipo
                if (!getline(ss, equipo, ',')) continue;

                // Leer TD
                if (!getline(ss, tempStr, ',')) continue;
                td = stoi(tempStr);

                // Leer INT
                if (!getline(ss, tempStr, ',')) continue;
                inte = stoi(tempStr);

                // Leer CMP
                if (!getline(ss, tempStr, ',')) continue;
                cmp = stoi(tempStr);

                // Leer SCK
                if (!getline(ss, tempStr)) continue;
                sck = stoi(tempStr);

                // Almacenar los datos si el año coincide con el año de interés 
                if (ano_interes == ano) {
                    equipos.push_back(equipo);

                    // Crear objeto Estadisticas con los datos
                    Estadisticas stats(td, inte, cmp, sck); 
                    arbol.insertar(equipo, ano, stats); // Insertar equipo, año y estadísticas en el árbol

                    // Imprimir diagnóstico
                    
                    switch (opcion) {
                        case 1:
                            rank.push_back(td);
                            break;
                        case 2:
                            rank.push_back(inte);
                            break;
                        case 3:
                            rank.push_back(cmp);
                            break;
                        case 4:
                            rank.push_back(sck);
                            break;
                        case 5: // Esta opción no almacena estadísticas
                            break;
                    }
                }
            }
            archivo.close();
        } else {
            cout << "Error al abrir el archivo." << endl;
            return 1;
        }

        // Verificar que se hayan encontrado estadísticas para el año
        if (rank.empty() && opcion != 5) {
            cout << "No se encontraron estadísticas para el año " << ano_interes << "." << endl;
            continue;
        }

        string tipo;
        if (opcion == 1) {
            tipo = "Touchdowns";
        } else if (opcion == 2) {
            tipo = "Intercepciones";
        } else if (opcion == 3) {
            tipo = "Pases completos";
        } else if (opcion == 4) {
            tipo = "Sacks (capturas)";
        }

        // Mostrar datos
        if (opcion != 5) {
            cout << "Datos para el año " << ano_interes << " de la estadística " << tipo << " de los 32 equipos de la NFL:" << endl;
            for (size_t i = 0; i < rank.size(); ++i) {
                cout << equipos[i] << ": " << rank[i] << endl;
            }
            cout << endl;

            // Ordenar los índices basado en los valores en rank
            vector<size_t> indices(rank.size());
            for (size_t i = 0; i < rank.size(); ++i) {
                indices[i] = i;
            }

            sort(indices.begin(), indices.end(), [&rank](size_t a, size_t b) {
                return rank[a] < rank[b]; // Ordenar por los valores en rank
            });

            // Crear vectores ordenados
            vector<string> sortedEquipos(rank.size());
            vector<int> sortedRank(rank.size());

            for (size_t i = 0; i < indices.size(); ++i) {
                sortedEquipos[i] = equipos[indices[i]];
                sortedRank[i] = rank[indices[i]];
            }

            // Imprimir los elementos del vector ya ordenados
            cout << "Datos ya ordenados de la estadística " << tipo << " :" << endl;
            for (size_t i = 0; i < sortedRank.size(); ++i) {
                cout << sortedEquipos[i] << ": " << sortedRank[i] << endl;
            }
            cout << endl;
        } else { // Opción para buscar equipo
            string equipo_buscado;
            cout << "Ingrese el nombre del equipo que desea buscar: ";
            cin.ignore(); // Limpiar el buffer
            getline(cin, equipo_buscado);

           arbol.buscarYMostrarEstadisticas(equipo_buscado, ano_interes);
        }

        // Preguntar si el usuario desea realizar otra búsqueda
        cout << "¿Desea realizar otra búsqueda? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    return 0;
}
