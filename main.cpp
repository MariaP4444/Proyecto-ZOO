

#include <iostream>
#include <algorithm>

#include "Habitat.h"
#include "Zoo.h"
#include "Animal.h"

using namespace std;

string convertidorStringMinuscula(string palabra){
    for(char& c : palabra){
        c = std::tolower(c);
    }
    return palabra;
}

// CUARTA OPCION

void cuartaOpcion(Zoo* pZoo, int opc){

    //Primero: pedir info del habitat del animal

    Habitat *tHabitat;
    Animal *tAnimal;
    string nombreHab, actividad;
    int idAnimal;
    cout << "Ingrese el habitat del animal: " << endl;
    cin >> nombreHab;

    nombreHab = convertidorStringMinuscula(nombreHab);

    //busco el habitat para listar los animales de ese habitat
    tHabitat = pZoo->devolverPunteroVec(nombreHab);
    tHabitat->listarAnimales();

    //una vez listados, le pido al usuario que escriba el id deseado para obtener el puntero
    cout << "Ingrese el id del animal " << endl;
    cin >> idAnimal;
    tAnimal = tHabitat->devolverPunteroAn(idAnimal);

    if(opc == 4) {
        tAnimal->menuAnimal(pZoo->getCarnivoro(), pZoo->getHerbivoro());
    }
    else{
        cout << "Ingrese la actividad a realizar " << endl;
        cin >> actividad;
        tAnimal->interactAnimal(actividad);
    }

}

//SEGUNDA OPCION

bool opcionHabitatDis(string habitat, vector<string> habitatsDisponibles){

    if(find(habitatsDisponibles.begin(),habitatsDisponibles.end(),habitat)!= habitatsDisponibles.end()){
        return true;
    }
    else{
        return false;
    }

}

void segundaOpcion(Zoo* pZoo){
    string  habitat;
    int tempMaxA, tempMinA;
    int contadorOp = 1;
    Habitat* habitatTemp;

    cout << "Ingrese la temperatura minima del animal " << endl;
    cin >> tempMinA;
    cout << "Ingrese la temperatura maxima del animal  " << endl;
    cin >> tempMaxA;

    if(!pZoo->exieteHabitatTemp(tempMaxA, tempMinA)) {
        throw invalid_argument("No hay ningun habitat disponible para este animal");
    }

    cout << "-- Segun estos datos los habitats disponibles para el animal son:" << endl;
    vector<string> habitatsDisponibles= pZoo->listaHabitatsDisponibles(tempMaxA, tempMinA);


    for (int i = 0; i < habitatsDisponibles.size(); i++){
        cout << contadorOp <<".   "<<habitatsDisponibles[i]<< endl;
        contadorOp ++;
    }

    cin.ignore();
    do{
        cout << "Ingrese el nombre del habitat a cual desea ingresar al animal: " << endl;
        getline(cin, habitat, '\n');
        habitat = convertidorStringMinuscula(habitat);
    } while (!opcionHabitatDis(habitat,habitatsDisponibles));

    habitatTemp= pZoo->devolverPunteroVec(habitat);
    habitatTemp->agregarAnimal(pZoo->getCantAnimales(),tempMaxA, tempMinA);

    pZoo->setCantAnimales(pZoo->getCantAnimales()+1);
}

// PRIMERA OPCION

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
        cout << "\n~~~~~~~~~~~~~~~~~~~~~ ZOO: "<< pZoo->getNombre()<< "~~~~~~~~~~~~~~~~~~~~~"<<"\n";
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
        cout << "\n~~~~~~~~~~~~~~~~~~~~~ ZOO: "<< pZoo->getNombre()<< "~~~~~~~~~~~~~~~~~~~~~"<<"\n";
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
                break;
            case 3:
                pZoo->listarHabitatsConAnimales();
                break;
            case 4:
                cuartaOpcion(pZoo, opc);
                break;
            case 5:
                cuartaOpcion(pZoo, opc);

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

    vector<string> tCarnivoro;
    vector<string> tHerviboro;
    Zoo* pZoo = new Zoo();

    tCarnivoro.push_back("vieiras");
    tCarnivoro.push_back("gambas");
    tCarnivoro.push_back("almejas");
    tCarnivoro.push_back("visceras");
    tCarnivoro.push_back("huevos");
    tCarnivoro.push_back("cerdo");
    tCarnivoro.push_back("pollo");
    tCarnivoro.push_back("res");
    tCarnivoro.push_back("pescado");

    tHerviboro.push_back("semillas");
    tHerviboro.push_back("raices");
    tHerviboro.push_back("hojas");
    tHerviboro.push_back("corteza");
    tHerviboro.push_back("savia");
    tHerviboro.push_back("flores");
    tHerviboro.push_back("nectar");
    tHerviboro.push_back("polen");
    tHerviboro.push_back("frutas");
    tHerviboro.push_back("verduras");
    tHerviboro.push_back("granos");

    pZoo->setNombre("MAVA");

    pZoo->setCarnivoro(tCarnivoro);
    pZoo->setHerbivoro(tHerviboro);

    pZoo->registrarHabitat("polar",-60,0);
    pZoo->registrarHabitat("selvatico",20,40);
    pZoo->registrarHabitat("acuatico",1,19);
    pZoo->registrarHabitat("desertico",40,60);

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
