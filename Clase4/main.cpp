#include <iostream>
#include <vector>
#include <sstream>

struct Item {
    std::string identificador;
    std::string nombre;
    std::vector<double> valor;

};

std::vector<std::string> split(const std::string &s, char delimitador) {

    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimitador)) {
        tokens.push_back(token);
    }
    return tokens;

}


Item procesarLinea(std::string linea) {
    Item item;
    // Separar primer (,)
    std::vector<std::string> secciones = split(linea, ',');
    if (secciones.size() == 3) {
        item.identificador = secciones[0];
        item.nombre = secciones[1];
        // buscar y separar los corchetes
        std::string valoresCompletos = secciones[2];
        size_t inicio = valoresCompletos.find("[");
        size_t final = valoresCompletos.find("]");
        auto soloValores = valoresCompletos.substr(inicio + 1, final - inicio - 1);
        std::vector<std::string> listaValores = split(soloValores, ';');
        for (const auto& valor : listaValores) {
            item.valor.push_back(atof(valor.c_str()));
        }


    }
    return item;


}

int main() {
    std::string entrada = "SN-001, Sensor_Humedad, [45.5; 48.2; 42.0]";

    Item resultado = procesarLinea(entrada);

    std::cout << "ID: " << resultado.identificador << std::endl;
    std::cout << "Nombre: " << resultado.nombre << std::endl;
    std::cout << "Valores Leidos: " << resultado.valor.size() << std::endl;
    return 0;
}
