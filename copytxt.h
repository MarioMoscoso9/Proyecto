#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void ingresarEstadisticas(const std::string& year) {
    std::ofstream prueba("prueba.txt"); //Archivo temporal

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

// Función para transferir datos de el archivo temporal a estadiaticas.txt
void transferirDatos() {
    std::ifstream prueba("prueba.txt");
    std::ofstream archivoPrincipal("estadisticas.txt", std::ios::app);

    if (!prueba.is_open() || !archivoPrincipal.is_open()) {
        std::cerr << "No se pudo abrir prueba.txt o estadisticas.txt.\n";
        return;
    }

    // Dos saltos de linea para conservar formato.
    archivoPrincipal << "\n\n";

    std::string linea;
    while (getline(prueba, linea)) {
        archivoPrincipal << linea << "\n"; 
    }

    prueba.close();
    archivoPrincipal.close();
    std::cout << "Datos transferidos de prueba.txt a estadisticas_nfl.txt.\n";
}