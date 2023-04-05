//
// Created by Lenovo on 31/03/2023.
//

#include "Animal.h"

Animal::Animal(string nombre, string especie, string estadoDeSalud, int id, int tempMaxA, int tempMinA, int cantHorasDormidas, int cantMaxDormir, bool jugar, bool comer, int edad): nombre(nombre), especie(especie), estadoDeSalud(estadoDeSalud), id(id), tempMaxA(tempMaxA), tempMinA(tempMinA), cantHorasDormidas(cantHorasDormidas), cantMaxDormir(cantMaxDormir), jugar(jugar), comer(comer), edad(edad){}

string Animal::getNombre(){
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

string Animal::getAlimentacion(){
    return this->alimentacion;
}

void Animal::setAlimentacion(string alimentacion) {
    Animal::alimentacion = alimentacion;
}

int Animal::getId(){
    return this->id;
}

void Animal::setId(int id){
    Animal::id = id;
}

int Animal::getTempMaxA(){
    return this->tempMaxA;
}

void Animal::setTempMaxA(int tempMaxA) {
    Animal::tempMaxA = tempMaxA;
}

int Animal::getTempMinA(){
    return this->tempMinA;
}

void Animal::setTempMinA(int tempMinA) {
    Animal::tempMinA = tempMinA;
}

int Animal::getCantHorasDormidas(){
    return this->cantHorasDormidas;
}

void Animal::setCantHorasDormidas(int cantHorasDormidas) {
    Animal::cantHorasDormidas = cantHorasDormidas;
}

int Animal::getCantMaxDormir(){
    return this->cantMaxDormir;
}

void Animal::setCantMaxDormir(int cantMaxDormir) {
    Animal::cantMaxDormir = cantMaxDormir;
}

bool Animal::getJugar(){
    return this->jugar;
}

void Animal::setJugar(bool jugar) {
    Animal::jugar = jugar;
}

bool Animal::getComer(){
    return this->comer;
}

void Animal::setComer(bool comer) {
    Animal::comer = comer;
}

vector<string> Animal::getJugetes(){
    return this->jugetes;
}

void Animal::agregarJugete(string juegueteNuevo) {
    this->jugetes.push_back(juegueteNuevo);
}

int Animal::getEdad(){
    return this->edad;
}

void Animal::setEdad(int edad) {
    Animal::edad = edad;
}

void Animal::menuAnimal(string nombre){
    int opc;
    do
    {
        cout << "\n** Seleccine el dato a cambiar\n";
        cout << "1. Edad\n";
        cout << "2. Estado de salud\n";
        cout << "3. Horas de suenio maximas\n";
        cout << "4. Horas de suenio maximas\n";
        cout << "5. Cantidad de porciones en dieta\n";
        cout << "6. Agregar juguetes\n";
        cout << "0. Guardar y salir\n";

        cin >> opc;

        switch (opc)
        {
            case 1:
                int edad;
                cin >> this->setEdad();

                break;
            case 2:
                string salud;
                cin.ignore();
                getline(cin, salud, '\n');
                this->setEstadoDeSalud(salud);

                break;
            case 3:
                int hDormir;
                cin >> this->setTempMaxA();

                break;

            case 4:
                int hDormir;
                cin >> this->setTempMaxA();

                break;

            case 5:
                int hDormir;
                cin >> this->setTempMaxA();

                break;

            case 6:
                int hDormir;
                cin >> this->setTempMaxA();

                break;

            default:
                break;
        }
    } while (opc != 0);
}

void Animal::elegirAlim(int tipoAlim){
    if(tipoAlim == 1){
        this->alimentacion = "Carnivoro";
        this->alimentos.push_back("carne");
        this->alimentos.push_back("pescado");
        this->alimentos.push_back("presa");
    }
    else if(tipoAlim == 2){
        this->alimentacion = "Herbivoro";
        this->alimentos.push_back("fruta");
        this->alimentos.push_back("pasto");
        this->alimentos.push_back("vegetal");
    }
    else if(){
        this->alimentacion = "Omnivoro";
        this->alimentos.push_back("fruta");
        this->alimentos.push_back("pasto");
        this->alimentos.push_back("carne");
        this->alimentos.push_back("pescado");
    }
}



