// Mario Armando Moscoso Becerra || A01712209
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*
La función para ingresar estadísticas y guardarlas en un archivo temporal tiene una 
complejidad de O(n) en todos los casos, donde n es el número de equipos. Esto se debe 
a que se recorre una vez el vector de equipos para pedir y almacenar las estadísticas de cada uno
*/
void ingresarEstadisticas(const std::string& year) {
    std::ofstream prueba("prueba.txt"); // Archivo temporal

    if (!prueba.is_open()) {
        std::cerr << "No se pudo abrir prueba.txt.\n";
        return;
    }

    std::vector<std::string> equipos = {
        "49ers", "bears", "bengals", "bills", "broncos", "browns", "buccaneers",
        "cardinals", "chargers", "chiefs", "colts", "cowboys", "dolphins", "eagles",
        "falcons", "giants", "jaguars", "jets", "lions", "packers", "panthers",
        "patriots", "raiders", "rams", "ravens", "commanders", "saints", "seahawks",
        "steelers", "texans", "titans", "vikings"
    };

    int puntos, victorias, yardasTotales, perdidas;

    for (const auto& equipo : equipos) {
        std::cout << "Ingrese las estadísticas para el equipo " << equipo << ":\n";
        std::cout << "Puntos anotados: ";
        std::cin >> puntos;
        std::cout << "Victorias: ";
        std::cin >> victorias;
        std::cout << "Yardas totales: ";
        std::cin >> yardasTotales;
        std::cout << "Pérdidas de balón: ";
        std::cin >> perdidas;

        prueba << year << "," << equipo << "," << puntos << "," << victorias << ","
               << yardasTotales << "," << perdidas << "\n";
    }

    prueba.close();
    std::cout << "Estadísticas ingresadas en prueba.txt.\n";
}

/*
La función para transferir datos entre archivos tiene una complejidad de O(m) en todos los 
casos, donde m es el número de líneas en el archivo temporal (prueba.txt). El proceso consiste 
en leer cada línea del archivo temporal y escribirla en el archivo principal, por lo que el tiempo 
depende únicamente de la cantidad de líneas a transferir.
*/
void transferirDatos() {
    std::ifstream prueba("prueba.txt");
    std::ofstream archivoPrincipal("estadisticas.txt", std::ios::app);

    if (!prueba.is_open() || !archivoPrincipal.is_open()) {
        std::cerr << "No se pudo abrir prueba.txt o estadisticas.txt.\n";
        return;
    }

    // Dos saltos de línea para conservar formato.
    archivoPrincipal << "\n\n";

    std::string linea;
    while (getline(prueba, linea)) {
        archivoPrincipal << linea << "\n"; 
    }

    prueba.close();
    archivoPrincipal.close();
    std::cout << "Datos transferidos de prueba.txt a estadisticas_nfl.txt.\n";
}
