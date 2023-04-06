//
// Created by Lenovo on 31/03/2023.
//

#include "Habitat.h"

Habitat::Habitat(string nombre, int tempMax, int tempMin): nombre(nombre), tempMax(tempMax), tempMin(tempMin){}

string convertidorStringMinuscula2(string palabra){
    for(char& c : palabra){
        c = std::tolower(c);
    }
    return palabra;
}

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
    return nullptr;
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
        cout << "--------------------------------------------------------" << endl;
    }
}

bool listaDietasDisponibles(string tipoDieta){
    vector<string> dietasDispo;
    dietasDispo.push_back("carnivoro");
    dietasDispo.push_back("hervivoro");
    dietasDispo.push_back("omnivoro");

    if(find(dietasDispo.begin(),dietasDispo.end(),tipoDieta)!= dietasDispo.end()){
        return true;
    }
    else{
        return false;
    }

}


void Habitat::agregarAnimal(int idAnimalNuevo, int tempMaxA, int tempMinA) {
    string nombreTemp, especie, estadoDeSalud, alimentacion, jugueteNom;
    int  cantMaxDormir, cantJuguetes, edad;
    vector<string> juguetesTemp;


    cout << "Ingrese el nombre del animal: " << endl;
    cin.ignore();
    getline(cin, nombreTemp, '\n');

    cout << "Ingrese la especie del animal: " << endl;
    cin.ignore();
    getline(cin, especie, '\n');

    cout << "Ingrese el estado de salud del  animal: " << endl;
    cin.ignore();
    getline(cin, estadoDeSalud, '\n');

    do {
        cout << "Ingrese la edad del animal " << endl;
        cin >> edad;
    }while(edad <= 0 || edad > 100);

    do {
        cout << "Ingrese las horas de sueño del animal " << endl;
        cin >> cantMaxDormir;
    }while(cantMaxDormir >= 0);


    do {
        cout << "Ingrese el numero de jugetes que va a tener el animal " << endl;
        cin >> cantJuguetes;
    }while(cantJuguetes >= 0);

    while(cantJuguetes > 0){
        cout << "Ingrese ingrese el nombre del juguete " << endl;
        cin.ignore();
        getline(cin, jugueteNom, '\n');
        jugueteNom= convertidorStringMinuscula2(jugueteNom);
        juguetesTemp.push_back(jugueteNom);
        cantJuguetes--;
    }


    do{
        cout << "\nTipo de dieta disponible:" << endl;
        cout << "\n - Carnivoro \n - Hervivoro \n - Omnivoro" << endl;
        cout << "Ingrese el tipo de alimentacion del  animal: " << endl;
        cin.ignore();
        getline(cin, alimentacion, '\n');
        alimentacion = convertidorStringMinuscula2(alimentacion);
    }while(!listaDietasDisponibles(alimentacion));


    nombreTemp = convertidorStringMinuscula2(nombreTemp);
    especie = convertidorStringMinuscula2(especie);
    estadoDeSalud = convertidorStringMinuscula2(estadoDeSalud);
    // 0 porque suponemos que animal no ha dormido al momento de ingresar
    Animal* nuevoAnimal = new Animal(nombreTemp, especie, estadoDeSalud,idAnimalNuevo,tempMaxA,tempMinA,0,cantMaxDormir,false,false,edad,juguetesTemp);

    nuevoAnimal->elegirAlim(alimentacion);

    this->animales.insert(make_pair(idAnimalNuevo, nuevoAnimal));
}
