

#include <iostream>
#include <algorithm>

#include "Habitat.h"
#include "Zoo.h"

using namespace std;

bool opcionHabitatDis(string habitat, vector<string> habitatsDisponibles){

    if(find(habitatsDisponibles.begin(),habitatsDisponibles.end(),habitat)!= habitatsDisponibles.end()){
        return true;
    }
    else{
        return false;
    }

}

void segundaOpcion(Zoo* pZoo){
    string nombre, especie, estadoDeSalud, habitat, edad;
    int tempMaxA, tempMinA, cantMaxDormir;
    int contadorOp = 1;


    cout << "Ingrese la temperatura minima del animal " << endl;
    cin >> tempMaxA;
    cout << "Ingrese la temperatura maxima del animal  " << endl;
    cin >> tempMinA;

    if(!pZoo->exieteHabitatTemp(tempMaxA, tempMinA)) {
        throw invalid_argument("No hay ningun habitat disponible para este animal");
    }

    cout << "-- Segun estos datos los habitats disponibles para el animal son:" << endl;
    vector<string> habitatsDisponibles= pZoo->listaHabitatsDisponibles(tempMaxA, tempMinA);


    for (int i = 0; i < habitatsDisponibles.size(); i++){
        cout << contadorOp <<".   "<<habitatsDisponibles[i]<< endl;
        contadorOp ++;
    }

    do{
        cout << "Ingrese el nombre del habitat a cual desea ingresar al animal: " << endl;
        cin.ignore();
        getline(cin, habitat, '\n');
        for(char& c : habitat){
            c = std::tolower(c);
        }
    } while (!opcionHabitatDis(habitat,habitatsDisponibles));

    cout << "Ingrese el nombre del animal: " << endl;
    cin.ignore();
    getline(cin, nombre, '\n');

    cout << "Ingrese la especie del animal: " << endl;
    cin.ignore();
    getline(cin, especie, '\n');

    cout << "Ingrese el estado de salud del  animal: " << endl;
    cin.ignore();
    getline(cin, estadoDeSalud, '\n');

    cout << "Ingrese la edad del animal " << endl;
    cin >> edad;

    cout << "Ingrese las horas de sueño del animal " << endl;
    cin >> cantMaxDormir;


}

void primeraOpcion(Zoo* pZoo){
    string nombre;
    int tMin, tMax;

    cout << "Ingrese nombre del habitat " << endl;
    cin.ignore();
    getline(cin, nombre, '\n');
    cout << "Ingrese la temperatura minima del habitat " << endl;
    cin >> tMin;
    cout << "Ingrese la temperatura maxima del habitat " << endl;
    cin >> tMax;

    for(char& c : nombre){
        c = std::tolower(c);
    }

    pZoo->registrarHabitat(nombre, tMin, tMax);

}

void mostrarMenu1(Zoo* pZoo){
    int opc;
    do{
        cout << "\n** Zoo MAVA\n";
        cout << "1. Agregar habitat\n";
        cout << "0. Salir\n" << endl;

        cin >> opc;
        switch (opc)
        {
            case 1:
                primeraOpcion(pZoo);
                opc = -1;
                break;
            case 0:
                cout << "ADIOS" << endl;
                break;
            case -1:
                break;
            default:
                cout << "Error: la opcion seleccionada no existe " << endl;
                break;
        }
    }while (opc != -1 && opc != 0);
}

void mostrarMenu2(Zoo* pZoo) {
    int id, opc, cantAnimales = 0;

    do
    {
        cout << "\n** Zoo MAVA\n";
        cout << "1. Agregar habitat\n";
        cout << "2. Agregar anima\n";
        cout << "3. Lista de habitats y animales\n";
        cout << "4. Modificar informacion de animal\n";
        cout << "5. Visitar habitat \n";
        cout << "0. Salir\n" << endl;


        cin >> opc;

        switch (opc)
        {
            case 1:
                primeraOpcion(pZoo);
                id++;
                break;
            case 2:
                try{
                    segundaOpcion(pZoo);
                }
                catch (invalid_argument e){
                    cout << "Por favor crea un habitat para este animal y luego lo vuelves a intentar"<< endl;
                }
                //Zoo->mostrarInfo();

                break;
            case 3:
                cout << "1. Agregar habitat\n";
                break;
            case 4:


                break;
            case 5:


                break;
            case 0:
                cout << "ADIOS" << endl;
                break;
            default:
                cout << "Error: la opcion seleccionada no existe " << endl;
                break;
        }
    } while (opc != 0);
}

int main() {

    Zoo* pZoo = new Zoo();
    if(pZoo->getZooNoVacio()){
        mostrarMenu2(pZoo);

    }
    else{
        mostrarMenu1(pZoo);
        mostrarMenu2(pZoo);
    }
    delete pZoo;
    return 0;

}

/*
vector<Habitat*>::iterator itVectorHab;

for (itVectorHab = this->animales.begin(); itVectorHab != this->animales.end(); ++itVectorHab){
Habitat* HabitatTemp = *itVectorHab;
HabitatTemp->mostrarAnimales;
}
*/