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

int Habitat::getTempMin(){
    return this->tempMin;
}

void Habitat::setTempMin(int tempMin) {
    Habitat::tempMin = tempMin;
}


Animal* Habitat::devolverPunteroAn(int id){

    unordered_map <int, Animal*>::iterator itMapA;

    for (itMapA = this->animales.begin(); itMapA != this->animales.end(); ++itMapA){
        if(itMapA->first == id){
            return itMapA->second;
        }
    }
}

void Habitat::listarAnimales(){

    unordered_map <int, Animal*>::iterator itMapA;
    cout << "Los animales de este habitat son:\n";

    for (itMapA = this->animales.begin(); itMapA != this->animales.end(); ++itMapA){
        cout << "Nombre: " << itMapA->second->getNombre() << endl;
        cout << "Especie: " << itMapA->second->getEspecie() << endl;
        cout << "ID: " << itMapA->first << endl;
        cout << "----------------" << endl;
    }
}

void Habitat::infoCompletaAn(){

    unordered_map <int, Animal*>::iterator itMapA;
    cout << "Los animales de este habitat son:\n";

    for (itMapA = this->animales.begin(); itMapA != this->animales.end(); ++itMapA){
        Animal* tAnimal = itMapA->second;

        cout << "Nombre: " << tAnimal->getNombre() << endl;
        cout << "Especie: " << tAnimal->getEspecie() << endl;
        cout << "ID: " << itMapA->first << endl;
        cout << "Estado de salud: " << tAnimal->getEstadoDeSalud() << endl;
        cout << "Alimentacion: " << tAnimal->getAliemtacion() << endl;
        cout << "Edad: " << tAnimal->getEdad() << endl;
        cout << "Temperatura minima: " << tAnimal->getTempMinA() << endl;
        cout << "Temperatura maxima: " << tAnimal->getTempMaxA() << endl;
        cout << "Horas de suenio por dia: " << tAnimal->getCantMaxDormir() << endl;
        cout << "Horas dormidas el dia de hoy: " << tAnimal->getCantHorasDormidas() << endl;
        cout << "Ha jugado el dia de hoy: " << tAnimal->getJugar() << endl;
        cout << "Ha comido el dia de hoy: " << tAnimal->getComer() << endl << endl;
        cout << "----------------" << endl << endl;
    }
}