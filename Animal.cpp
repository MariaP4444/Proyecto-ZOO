//
// Created by Lenovo on 31/03/2023.
//

#include "Animal.h"

Animal::Animal(string nombre, string especie, string estadoDeSalud, int id, int tempMaxA, int tempMinA, int cantHorasDormidas, int cantMaxDormir, bool jugar, bool comer): nombre(nombre), especie(especie), estadoDeSalud(estadoDeSalud), id(id), tempMaxA(tempMaxA), tempMinA(tempMinA), cantHorasDormidas(cantHorasDormidas), cantMaxDormir(cantMaxDormir), jugar(jugar), comer(comer){}
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



