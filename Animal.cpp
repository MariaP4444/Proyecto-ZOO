//
// Created by Lenovo on 31/03/2023.
//

#include "Animal.h"

Animal::Animal(string nombre, string especie, string estadoDeSalud, int id, int tempMaxA, int tempMinA,
               int cantHorasDormidas, int cantMaxDormir, bool jugar, bool comer, int edad, vector<string> juguetes)
        : nombre(nombre), especie(especie), estadoDeSalud(estadoDeSalud), id(id), tempMaxA(tempMaxA),
          tempMinA(tempMinA), cantHorasDormidas(cantHorasDormidas), cantMaxDormir(cantMaxDormir), jugar(jugar),
          comer(comer), edad(edad), juguetes(juguetes) {}

string Animal::getNombre() {
    return this->nombre;
}

void Animal::setNombre(string nombre) {
    Animal::nombre = nombre;
}

string Animal::getEspecie() {
    return this->especie;
}

void Animal::setEspecie(string especie) {
    Animal::especie = especie;
}

string Animal::getEstadoDeSalud() {
    return this->estadoDeSalud;
}

void Animal::setEstadoDeSalud(string estadoDeSalud) {
    Animal::estadoDeSalud = estadoDeSalud;
}

string Animal::getAliemtacion() {
    return this->alimentacion;
}

void Animal::setAliemtacion(string alimentacion) {
    Animal::alimentacion = alimentacion;
}

int Animal::getId() {
    return this->id;
}

void Animal::setId(int id) {
    Animal::id = id;
}

int Animal::getTempMaxA() {
    return this->tempMaxA;
}

void Animal::setTempMaxA(int tempMaxA) {
    Animal::tempMaxA = tempMaxA;
}

int Animal::getTempMinA() {
    return this->tempMinA;
}

void Animal::setTempMinA(int tempMinA) {
    Animal::tempMinA = tempMinA;
}

int Animal::getCantHorasDormidas() {
    return this->cantHorasDormidas;
}

void Animal::setCantHorasDormidas(int cantHorasDormidas) {
    Animal::cantHorasDormidas = cantHorasDormidas;
}

int Animal::getCantMaxDormir() {
    return this->cantMaxDormir;
}

void Animal::setCantMaxDormir(int cantMaxDormir) {
    Animal::cantMaxDormir = cantMaxDormir;
}

bool Animal::getJugar() {
    return this->jugar;
}

void Animal::setJugar(bool jugar) {
    Animal::jugar = jugar;
}

bool Animal::getComer() {
    return this->comer;
}

void Animal::setComer(bool comer) {
    Animal::comer = comer;
}

int Animal::getEdad() {
    return this->edad;
}

void Animal::setEdad(int edad) {
    Animal::edad = edad;
}

void Animal::menuAnimal() {
    int opc, edad, hDormir;
    string salud;
    do {
        cout << "\n** Seleccine el dato a cambiar\n";
        cout << "1. Edad\n";
        cout << "2. Estado de salud\n";
        cout << "3. Horas de suenio maximas\n";
        cout << "4. Cantidad de porciones en dieta\n";
        cout << "5. Agregar juguetes\n";
        cout << "0. Guardar y salir\n";

        cin >> opc;

        switch (opc) {
            case 1:
                cin >> edad;
                this->setEdad(edad);
                break;
            case 2:
                cin.ignore();
                getline(cin, salud, '\n');
                for (char &c: salud) {
                    c = std::tolower(c);
                }
                this->setEstadoDeSalud(salud);
                break;
            case 3:
                cin >> hDormir;
                this->setTempMaxA(hDormir);
                break;
            case 4:
                break;

            case 5:
                break;

            case 6:
                break;
            default:
                break;
        }
    } while (opc != 0);
}

int aseguradorDeCantAlimetos(){
    int cantidadComidad;
    do{
        cout << "Por favor ingrese la cantidad de Kg que come el animal del alimento: " << endl;
        cin >> cantidadComidad;
    }while(cantidadComidad<= 0);

    return cantidadComidad;
}

void Animal::elegirAlim(string tipoAlim) {
    if (tipoAlim == "carnivoro") {
        cout << "- Res" << endl;
        this->alimentos.insert(make_pair("res", aseguradorDeCantAlimetos()));
        cout << "- Pollo" << endl;
        this->alimentos.insert(make_pair("pollo", aseguradorDeCantAlimetos()));
        cout << "- Pescado" << endl;
        this->alimentos.insert(make_pair("pescado", aseguradorDeCantAlimetos()));
    } else if (tipoAlim == "herbivoro") {
        cout << "- Frutas" << endl;
        this->alimentos.insert(make_pair("frutas", aseguradorDeCantAlimetos()));
        cout << "- Verduras" << endl;
        this->alimentos.insert(make_pair("Verduras", aseguradorDeCantAlimetos()));
        cout << "- Granos" << endl;
        this->alimentos.insert(make_pair("granos", aseguradorDeCantAlimetos()));
    } else if (tipoAlim == "omnivoro") {
        cout << "- Res" << endl;
        this->alimentos.insert(make_pair("res", aseguradorDeCantAlimetos()));
        cout << "- Pollo" << endl;
        this->alimentos.insert(make_pair("pollo", aseguradorDeCantAlimetos()));
        cout << "- Pescado" << endl;
        cout << "- Frutas" << endl;
        this->alimentos.insert(make_pair("frutas", aseguradorDeCantAlimetos()));
        cout << "- Verduras" << endl;
        this->alimentos.insert(make_pair("Verduras", aseguradorDeCantAlimetos()));
    }
}

unordered_map<string, int> Animal::getAlimentos() {
    return this->alimentos;
}

void Animal::setAlimentos(unordered_map<string, int> alimentos) {
    Animal::alimentos = alimentos;
}






