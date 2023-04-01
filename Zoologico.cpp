//
// Created by Lenovo on 31/03/2023.
//

#include "Zoologico.h"

bool Zoologico::getExistenHabitat()  {
    return this->existenHabitat;
}

void Zoologico::setExistenHabitat(bool existenHabitat) {
    Zoologico::existenHabitat = existenHabitat;
}

int Zoologico::getCantAnimales() {
    return this->cantAnimales;
}

void Zoologico::setCantAnimales(int cantAnimales) {
    Zoologico::cantAnimales = cantAnimales;
}

string Zoologico::getNombre(){
    return this->nombre;
}

void Zoologico::setNombre(string nombre) {
    Zoologico::nombre = nombre;
}
