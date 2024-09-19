#include "ord.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    vector<string> equipos;
    vector<int> rank;
    int ano, td, inte, cmp, sck;
    string linea;
    ifstream archivo("estadisticas.txt");

    // Solicitar al usuario el año de interés
    int ano_interes;
    cout << "Ingrese el año que desea filtrar (2018-2023): ";
    cin >> ano_interes;

    // Solicitar la estadística a analizar
    int opcion;
    cout << "Ingresa la estadística a analizar (poner únicamente el número 1-4)" << endl;
    cout << "1. Touchdowns" << endl
         << "2. Intercepciones" << endl
         << "3. Pases completos" << endl
         << "4. Sacks (capturas)" << endl;
    cin >> opcion;

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

            // Almacenar los datos si el año coincide con el año de interes 
            if (ano_interes == ano) {
                equipos.push_back(equipo);
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
                    default:
                        cout << "Opción inválida." << endl;
                }
            }
        }
        archivo.close();
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

    // Imprimir los elementos del vector sin ordenar
    cout << "Datos para el año " << ano_interes << " de la estadística " << tipo << " de los 32 equipos de la NFL sin ordenar:" << endl;
    for (size_t i = 0; i < rank.size(); ++i) {
        cout << equipos[i] << ": " << rank[i] << endl;
    }
    cout << endl;

    // Ordenar los datos en orden de menor a mayor 
    Sorts<int> sorts;
    vector<int> sortedRank = sorts.mergeSort(rank);

    // Crear un vector para los equipos ordenados confrome a las estadisticas ya ordenadas
    vector<string> sortedEquipos(rank.size());
    
    for (size_t i = 0; i < rank.size(); ++i) {
        for (size_t j = 0; j < rank.size(); ++j) {
            if (rank[j] == sortedRank[i]) {
                sortedEquipos[i] = equipos[j];
                break;
            }
        }
    }

    // Imprimir los elementos del vector rank junto con los nombres de los equipos.
    cout << "Datos ya ordenados:" << endl;
    for (size_t i = 0; i < sortedRank.size(); ++i) {
        cout << sortedEquipos[i] << ": " << sortedRank[i] << endl;
    }
    cout << endl;

    return 0;
}

