#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;


struct RegistroLog {
    string tipo;
    string mensaje;
};

RegistroLog parsearLinea(string linea) {
    RegistroLog entrada;
    auto poscionDosPuntos = linea.find(':');
    if (poscionDosPuntos != string::npos) {
        // substr(inicio, longitud)
        entrada.tipo = linea.substr(0, poscionDosPuntos);
        // substr(inicio ) -> hasta el gginal
        entrada.mensaje = linea.substr(poscionDosPuntos + 1);
    }else {
        entrada.tipo = "NO SE PUEDE SABER";
        entrada.mensaje = linea;
    }
    return entrada;
}
int main() {
    ifstream archivoEntrada("../entrada.txt");
    vector<RegistroLog> listaRegistros;
    map<string, int> estadisticas;
    if (!archivoEntrada.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }
    string lineaActual;
    while (getline(archivoEntrada, lineaActual)) {
        // Parsear la linea
        RegistroLog log = parsearLinea(lineaActual);
        listaRegistros.push_back(log);
        estadisticas[log.tipo]++;

    }
    archivoEntrada.close();


    ofstream archivoSalida("../reporte.txt");
    cout << "Generando Reporte" << endl;

    archivoSalida << "Reporte de Logs" << endl;
    archivoSalida << "Total de registros procesados: " << listaRegistros.size() << endl;

    return 0;
}