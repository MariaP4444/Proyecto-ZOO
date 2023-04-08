//
// Created by Lenovo on 31/03/2023.
//

#include "Habitat.h"

Habitat::Habitat(string nombre, int tempMax, int tempMin): nombre(nombre), tempMax(tempMax), tempMin(tempMin){}

//Funcion que dado un string, retorna en la misma en minusculas, para evitar errores al comparar strings
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

//Metodo que imprime la informacion basica de los animales, se utiliza cuando se visita un habitat
void Habitat::listarAnimales(){

    unordered_map <int, Animal*>::iterator itMapA;
    cout << "Los animales de este habitat son:\n";

    for (itMapA = this->animales.begin(); itMapA != this->animales.end(); ++itMapA){
        cout << " -Nombre: " << itMapA->second->getNombre() << endl;
        cout << " -Especie: " << itMapA->second->getEspecie() << endl;
        cout << " -ID: " << itMapA->first << endl;
        cout << "---------------------------------" << endl;
    }
}

//Imprime toda la informacion del los animales en un habitat
void Habitat::infoCompletaAn(){

    unordered_map <int, Animal*>::iterator itMapA;
    int contador = 1;
    cout << "-------------------------Los animales de este habitat son:--------------------------\n";
    if(this->animales.empty()){
        cout << "     OPS No hay animales por el momento" << endl;
    }
    else{
        for (itMapA = this->animales.begin(); itMapA != this->animales.end(); ++itMapA){
            Animal* tAnimal = itMapA->second;
            cout << " ++++++++++++++++ Animal N°" << contador << " ++++++++++++++++" << endl;
            cout << "  Nombre: " << tAnimal->getNombre() << endl;
            cout << "  Especie: " << tAnimal->getEspecie() << endl;
            cout << "  ID: " << itMapA->first << endl;
            cout << "  Estado de salud: " << tAnimal->getEstadoDeSalud() << endl;
            cout << "  Alimentacion: " << tAnimal->getAliemtacion() << endl;
            cout << "  Edad: " << tAnimal->getEdad() << endl;
            cout << "  Temperatura minima: " << tAnimal->getTempMinA() << endl;
            cout << "  Temperatura maxima: " << tAnimal->getTempMaxA() << endl;
            cout << "  Horas de suenio por dia: " << tAnimal->getCantMaxDormir() << endl;
            cout << "  Horas dormidas el dia de hoy: " << tAnimal->getCantHorasDormidas() << endl;
            cout << "  Ha jugado el dia de hoy: " << tAnimal->getJugar() << endl;
            cout << "  Ha comido el dia de hoy: " << tAnimal->getComer() << endl << endl;
            cout << "  Esta es la lista de alimetos del animal: " << endl;
            tAnimal->mostrarMapAlimentacion();
            cout << "  Esta es la lista de juguetes del animal: " << endl;
            tAnimal->mostrarJuguetes();
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            contador++;
        }
    }

}
//Esta funcion comprueba si la dieta ingresada por el usuario es una dieta permitida
bool listaDietasDisponibles(string tipoDieta){
    vector<string> dietasDispo;
    dietasDispo.push_back("carnivoro");
    dietasDispo.push_back("herbivoro");
    dietasDispo.push_back("omnivoro");

    if(find(dietasDispo.begin(),dietasDispo.end(),tipoDieta)!= dietasDispo.end()){
        return true;
    }
    else{
        return false;
    }

}

//Este metodo pide todos los datos del animal, a excepcion de las cantidades de los alimentos
void Habitat::agregarAnimal(int idAnimalNuevo, int tempMaxA, int tempMinA) {
    string nombreTemp, especie, estadoDeSalud, alimentacion, jugueteNom;
    int  cantMaxDormir, cantJuguetes, edad;
    vector<string> juguetesTemp;

    cout << "Ingrese el nombre del animal: " << endl;
    getline(cin, nombreTemp, '\n');


    cout << "Ingrese la especie del animal: " << endl;
    getline(cin, especie, '\n');


    cout << "Ingrese el estado de salud del  animal: " << endl;
    getline(cin, estadoDeSalud, '\n');


    do {
        cout << "Ingrese la edad del animal:" << endl;
        cin >> edad;
        if(!cin.good()){
            throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
        }
    }while(edad <= 0 || edad > 100);

    do {
        cout << "Ingrese las horas de sueño del animal: " << endl;
        cin >> cantMaxDormir;
        if(!cin.good()){
            throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
        }
    }while(cantMaxDormir <= 0);


    do {
        cout << "Ingrese el numero de jugetes que va a tener el animal: " << endl;
        cin >> cantJuguetes;
        if(!cin.good()){
            throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
        }
    }while(cantJuguetes <= 0);

    cin.ignore();
    while(cantJuguetes > 0){
        cout << " - Ingrese ingrese el nombre del juguete: " << endl;
        getline(cin, jugueteNom, '\n');
        jugueteNom= convertidorStringMinuscula2(jugueteNom);
        juguetesTemp.push_back(jugueteNom);
        cantJuguetes--;
    }

    cin.ignore();
    do{
        cout << "\nTipo de dieta disponible:" << endl;
        cout << "\n - Carnivoro \n - Herbivoro \n - Omnivoro" << endl;
        cout << "Ingrese el tipo de alimentacion del  animal: " << endl;
        getline(cin, alimentacion, '\n');

        alimentacion = convertidorStringMinuscula2(alimentacion);
    }while(!listaDietasDisponibles(alimentacion));


    nombreTemp = convertidorStringMinuscula2(nombreTemp);
    especie = convertidorStringMinuscula2(especie);
    estadoDeSalud = convertidorStringMinuscula2(estadoDeSalud);
    // 0 porque suponemos que animal no ha dormido al momento de ingresar
    Animal* nuevoAnimal = new Animal(nombreTemp, especie, estadoDeSalud,idAnimalNuevo,tempMaxA,tempMinA,0,cantMaxDormir,false,false,edad,juguetesTemp, alimentacion);

    //Agrega los alimentos que van por defecto
    nuevoAnimal->elegirAlim(alimentacion);

    this->animales.insert(make_pair(idAnimalNuevo, nuevoAnimal));
    cout << nuevoAnimal->getNombre() << " fue llevado a su nueva habitat " << this->getNombre() <<endl;
}
