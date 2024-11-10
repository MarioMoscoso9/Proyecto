#include "arbol.h"
#include "ord.h"
#include "copytxt.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
#include <algorithm>
#include <cctype>

int main() {
    char continuar;
    vector<string> equipos;
    vector<int> rank;
    Arbol arbol;
    int ano, td, inte, cmp, sck;
    string linea;
    ifstream archivo("estadisticas.txt");

    do {
        int opcion1;
        cout << "¿Qué desea hacer? (poner únicamente 1 o 2)" << endl;
        cout << "1. Búsqueda de estadísticas" << endl;
        cout << "2. Actualizar estadísticas (temporada)" << endl;
        cin >> opcion1;

        if (opcion1 < 1 || opcion1 > 2) {
            cout << "Opción inválida. Por favor, elige una opción del 1 o 2." << endl;
            continue; 
        }

        if (opcion1 == 1) {
            int ano_interes;
            cout << "Ingrese el año que desea filtrar (2018-2023): ";
            cin >> ano_interes;

            int opcion;
            cout << "Ingresa la estadística a analizar (poner únicamente el número 1-5)" << endl;
            cout << "1. Touchdowns" << endl
                 << "2. Intercepciones" << endl
                 << "3. Pases completos" << endl
                 << "4. Sacks (capturas)" << endl
                 << "5. Buscar equipo" << endl;
            cin >> opcion;

            if (opcion < 1 || opcion > 5) {
                cout << "Opción inválida. Por favor, elige una opción del 1 al 5." << endl;
                continue;
            }

            // Complejidad de lectura del archivo: O(n), donde n es el número de líneas
            if (archivo.is_open()) {
                while (getline(archivo, linea)) {
                    // Saltar las líneas de comentarios y líneas vacías
                    if (linea.empty() || linea[0] == '#') continue;

                    stringstream ss(linea);
                    string equipo, tempStr;

                    if (!getline(ss, tempStr, ',')) continue;
                    ano = stoi(tempStr);

                    if (!getline(ss, equipo, ',')) continue;

                    if (!getline(ss, tempStr, ',')) continue;
                    td = stoi(tempStr);

                    if (!getline(ss, tempStr, ',')) continue;
                    inte = stoi(tempStr);

                    if (!getline(ss, tempStr, ',')) continue;
                    cmp = stoi(tempStr);

                    if (!getline(ss, tempStr)) continue;
                    sck = stoi(tempStr);

                    // Almacenar los datos si el año coincide con el año de interés 
                    if (ano_interes == ano) {
                        equipos.push_back(equipo);

                        
                        Estadisticas stats(td, inte, cmp, sck); 
                        arbol.insertar(equipo, ano, stats); // Insertar equipo
                    
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
                            case 5:
                                break;
                        }
                    }
                }
                archivo.close();
            } else {
                cout << "Error al abrir el archivo." << endl;
                return 1;
            }

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

            // Mostrar datos sin ordenar
            if (opcion != 5) {
                cout << "Datos para el año " << ano_interes << " de la estadística " << tipo << " de los 32 equipos de la NFL ordenados alfabéticamente:" << endl;
                for (size_t i = 0; i < rank.size(); ++i) {
                    cout << equipos[i] << ": " << rank[i] << endl;
                }
                cout << endl;

                vector<size_t> indices(rank.size());
                for (size_t i = 0; i < rank.size(); ++i) {
                    indices[i] = i;
                }

                sort(indices.begin(), indices.end(), [&rank](size_t a, size_t b) {
                    return rank[a] < rank[b];
                });

                vector<string> sortedEquipos(rank.size());
                vector<int> sortedRank(rank.size());

                for (size_t i = 0; i < indices.size(); ++i) {
                    sortedEquipos[i] = equipos[indices[i]];
                    sortedRank[i] = rank[indices[i]];
                }

                cout << "Datos ya ordenados de la estadística " << tipo << " :" << endl;
                for (size_t i = 0; i < sortedRank.size(); ++i) {
                    cout << sortedEquipos[i] << ": " << sortedRank[i] << endl;
                }
                cout << endl;
            } else {
                string equipo_buscado;
                cout << "Ingrese el nombre del equipo que desea buscar (minúsculas): ";
                cin.ignore(); // Limpiar el buffer
                getline(cin, equipo_buscado);

                arbol.buscarYMostrarEstadisticas(equipo_buscado, ano_interes);
            }
        }

        if (opcion1 == 2) {
            std::string year;
            std::cout << "Ingrese el año para las estadísticas: ";
            std::cin >> year;

            ingresarEstadisticas(year);
            transferirDatos();
        }

        cout << "¿Desea realizar otra búsqueda? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    return 0;
}
