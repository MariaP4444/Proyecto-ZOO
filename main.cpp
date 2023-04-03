

#include <iostream>
#include "Habitat.h"
#include "Zoo.h"
using namespace std;

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
        cout << "2. Lista de habitats y animales\n";
        cout << "3. Agregar animal\n";
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
                //segundaOpcion();
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