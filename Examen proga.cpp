#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Candidato {
    string nombre;
    string partidoPolitico;
    string plataforma;
    int votos = 0;
};

vector<Candidato> candidatos;

void registrarCandidato() {
    Candidato candidato;
    cout << "Ingrese el nombre del candidato: ";
    cin.ignore();
    getline(cin, candidato.nombre);
    cout << "Ingrese el partido politico del candidato: ";
    getline(cin, candidato.partidoPolitico);
    cout << "Ingrese la plataforma del candidato: ";
    getline(cin, candidato.plataforma);
    candidatos.push_back(candidato);
    cout << "Candidato registrado exitosamente.\n";
}

void votar() {
    int opcion;
    cout << "Seleccione un candidato para votar:\n";
    for (size_t i = 0; i < candidatos.size(); ++i) {
        cout << i + 1 << ". " << candidatos[i].nombre << " (" << candidatos[i].partidoPolitico << ")\n";
    }
    cout << "Ingrese el número de su opción: ";
    cin >> opcion;

    if (opcion > 0 && opcion <= candidatos.size()) {
        candidatos[opcion - 1].votos++;
        cout << "Voto registrado exitosamente.\n";
    } else {
        cout << "Opción no válida.\n";
    }
}

void mostrarResultados() {
    if (candidatos.empty()) {
        cout << "No hay candidatos registrados.\n";
        return;
    }

    int totalVotos = 0;
    for (const auto& candidato : candidatos) {
        totalVotos += candidato.votos;
    }

    Candidato ganador = candidatos[0];
    for (const auto& candidato : candidatos) {
        if (candidato.votos > ganador.votos) {
            ganador = candidato;
        }
    }

    cout << "Resultados de la elección:\n";
    for (const auto& candidato : candidatos) {
        double porcentaje = (totalVotos > 0) ? (candidato.votos * 100.0 / totalVotos) : 0;
        cout << candidato.nombre << " (" << candidato.partidoPolitico << "): " << candidato.votos << " votos (" << porcentaje << "%)\n";
    }

    cout << "\nEl ganador es: " << ganador.nombre << " del partido " << ganador.partidoPolitico << " con " << ganador.votos << " votos.\n";
}

void mostrarMenu() {
    cout << "Sistema de Votaciones Electrónicas\n";
    cout << "1. Ingresar Candidatos\n";
    cout << "2. Votaciones\n";
    cout << "3. Resultados\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
            case 1:
                registrarCandidato();
                break;
            case 2:
                votar();
                break;
            case 3:
                mostrarResultados();
                break;
            case 4:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
        }
    } while (opcion != 4);
    return 0;
}

