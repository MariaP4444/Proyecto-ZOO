//
// Created by Lenovo on 31/03/2023.
//

#include "Habitat.h"

Habitat::Habitat(string nombre, int tempMax, int tempMin): nombre(nombre), tempMax(tempMax), tempMin(tempMin){}

string Habitat::getNombre(){
    return this->nombre;
}

void Habitat::setNombre(string nombre) {
    Habitat::nombre = nombre;
}

int Habitat::getTempMax(){
    return this->tempMax;
}

void Habitat::setTempMax(int tempMax) {
    Habitat::tempMax = tempMax;
}

int Habitat::getTemMin(){
    return this->temMin;
}

void Habitat::setTemMin(int temMin) {
    Habitat::temMin = temMin;
}
