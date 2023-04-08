//
// Created by Lenovo on 31/03/2023.
//

#include <limits>
#include "Animal.h"

Animal::Animal(string nombre, string especie, string estadoDeSalud, int id, int tempMaxA, int tempMinA,
               int cantHorasDormidas, int cantMaxDormir, bool jugar, bool comer, int edad, vector<string> juguetes, string alimentacion)
        : nombre(nombre), especie(especie), estadoDeSalud(estadoDeSalud), id(id), tempMaxA(tempMaxA),
          tempMinA(tempMinA), cantHorasDormidas(cantHorasDormidas), cantMaxDormir(cantMaxDormir), jugar(jugar),
          comer(comer), edad(edad), juguetes(juguetes), alimentacion(alimentacion){}


//Funcion que dado un string, retorna en la misma en minusculas, para evitar errores al comparar strings
string convertidorStringMinuscula3(string palabra){
    for(char& c : palabra){
        c = std::tolower(c);
    }
    return palabra;
}

string Animal::getNombre() {
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

string Animal::getAliemtacion() {
    return this->alimentacion;
}

void Animal::setAliemtacion(string alimentacion) {
    Animal::alimentacion = alimentacion;
}

int Animal::getId() {
    return this->id;
}

void Animal::setId(int id) {
    Animal::id = id;
}

int Animal::getTempMaxA() {
    return this->tempMaxA;
}

void Animal::setTempMaxA(int tempMaxA) {
    Animal::tempMaxA = tempMaxA;
}

int Animal::getTempMinA() {
    return this->tempMinA;
}

void Animal::setTempMinA(int tempMinA) {
    Animal::tempMinA = tempMinA;
}

int Animal::getCantHorasDormidas() {
    return this->cantHorasDormidas;
}

void Animal::setCantHorasDormidas(int cantHorasDormidas) {
    Animal::cantHorasDormidas = cantHorasDormidas;
}

int Animal::getCantMaxDormir() {
    return this->cantMaxDormir;
}

void Animal::setCantMaxDormir(int cantMaxDormir) {
    Animal::cantMaxDormir = cantMaxDormir;
}

bool Animal::getJugar() {
    return this->jugar;
}

void Animal::setJugar(bool jugar) {
    Animal::jugar = jugar;
}

bool Animal::getComer() {
    return this->comer;
}

void Animal::setComer(bool comer) {
    Animal::comer = comer;
}

int Animal::getEdad() {
    return this->edad;
}

void Animal::setEdad(int edad) {
    Animal::edad = edad;
}

unordered_map<string, int> Animal::getAlimentos() {
    return this->alimentos;
}

void Animal::setAlimentos(unordered_map<string, int> alimentos) {
    Animal::alimentos = alimentos;
}

//Indica retornando un booleano si el juguete ingresado esta entre los juguetes del animal
// Si esta, entonces lo elimina
bool Animal::eliminarJuguetes(string jugueteElimanar) {
    if(find(this->juguetes.begin(),this->juguetes.end(),jugueteElimanar)!= this->juguetes.end()){
        this->juguetes.erase(find(this->juguetes.begin(),this->juguetes.end(),jugueteElimanar));
        return true;
    }
    else{
        return false;
    }
}

/*Se asegura que la cantidad de kg ingresada sea como minimo 1
 * Funciones que lo usan:
 * editarAlimento
 * agregarAlimentoaMap
 * agregarAlimentoaMapOmnivoro
 * elegirAlim
*/
int aseguradorDeCantAlimetos(){
    int cantidadComidad;
    do{
        cout << "Por favor ingrese la cantidad de Kg que come el animal del alimento: " << endl;
        cin >> cantidadComidad;
        if(!cin.good()){
            throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
        }
    }while(cantidadComidad<= 0);

    return cantidadComidad;
}

// Recorre la lista de alimentos que estan en la dieta del animal, muestra la informacion de cada uno y
// el usuario elige entre cambiarlo o mantenerlo, al cambiarlo, se asegura que ponga al menos 1kg
void Animal::editarAlimento() {
    unordered_map <string, int>::iterator itMapA;
    int kg = 0;

    for (itMapA = this->alimentos.begin(); itMapA != this->alimentos.end(); ++itMapA) {
        int opc = 0;

        cout << "  Alimento: " << itMapA->first << endl;
        cout << "  Kg: " << itMapA->second << endl;
        cout << "------------------------------------" << endl;

        while(opc != 1 && opc != 2){

            cout << "1.Editar" << endl;
            cout << "2.Guardar" << endl;
            cin >> opc;

            if(!cin.good()){
                throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
            }

        }
        if (opc == 1) {
            bool terminado = false;
            do {
                try {
                    itMapA->second = aseguradorDeCantAlimetos();
                    terminado = true;
                }
                catch (const invalid_argument error) {
                    cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    terminado = false;
                }
            }
            while(terminado == false);

        }
    }
}

//Retorna un booleano indicando si el alimento ingresado pertenece al tipo de alimentacion del animal
bool buscarAlimentoenListaDieta(string alimento,vector<string> dieta){
    if(find(dieta.begin(),dieta.end(),alimento) != dieta.end()){
        return true;
    }
    else{
        return false;
    }
}

//Pide los datos del alimento a añadir, se asegura que pertenezca al tipo de alimentacion del animal, que no este repetido
// y que la cantidad sea valida. Funciona para las dietas carnivoras o herbivoras
void Animal::agregarAlimentoaMap(vector<string> dieta) {
    string alimentoAgregar;
    if(this->alimentos.size()< dieta.size()){
        do{
            cout << "Ingrese el nombre del alimento:"<< endl;
            getline(cin, alimentoAgregar, '\n');
            alimentoAgregar = convertidorStringMinuscula3(alimentoAgregar);
            if(this->alimentos.count(alimentoAgregar)) {
                cout << "Este alimento ya esta agregado a la dieta del animal " << endl;
            }
        }while(!buscarAlimentoenListaDieta(alimentoAgregar,dieta) && !this->alimentos.count(alimentoAgregar));
        //caso de manejo para evitar ingresar alimento que no sea del tipo de dieta del animal y evitar repetir alimentos

        bool terminado = false;
        do {
            try {
                this->alimentos.insert(make_pair(alimentoAgregar,aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }
        while(terminado == false);

    }
    else{
        cout << " Al parecer el animal ya cuenta con la capacidad maxima de alimentos disponibles" << endl;
    }
}

//Hace lo mismo que "agregarAlimentoaMap", pero acomodado para las dietas omnivoras
void Animal::agregarAlimentoaMapOmnivoro(vector<string> dieta1,vector<string> dieta2) {
    string alimentoAgregar;
    if(this->alimentos.size()< dieta1.size()+ dieta2.size()){
        do{
            cout << "Ingrese el nombre del alimento:"<< endl;
            getline(cin, alimentoAgregar, '\n');
            alimentoAgregar = convertidorStringMinuscula3(alimentoAgregar);
            if(this->alimentos.count(alimentoAgregar)) {
                cout << "Este alimento ya esta agregado a la dieta del animal " << endl;
            }
        }while(!buscarAlimentoenListaDieta(alimentoAgregar,dieta1)&& !buscarAlimentoenListaDieta(alimentoAgregar,dieta2) && !this->alimentos.count(alimentoAgregar));

        bool terminado = false;
        do {
            try {
                this->alimentos.insert(make_pair(alimentoAgregar,aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }
        while(terminado == false);

    }
    else{
        cout << " Al parecer el animal ya cuenta con la capacidad maxima de alimentos disponibles" << endl;
    }
}

//Dado un alimento a eliminar busca si existe en el mapa "alimentos"
bool Animal::eliminarAlimento(string alimento) {
    if(this->alimentos.count(alimento)){
        this->alimentos.erase(alimento);
        cout << "Se ha eliminado: " << alimento << endl;
        return true;
    }
    else{
        cout << " No se ha encontrado el alimento que desea eliminar, vuelve a intentarlo" << endl;
        return false;
    }
}

//Menu para cambiar datos del animal
void Animal::menuAnimal(vector<string> dietaCarnivora, vector<string> dietaHerbivora) {
    int opc, edad, hDormir,cantJuguetes;
    string salud,jugueteNom, jugueteEliminar, alimentoEliminar;
    bool terminado = false;
    do {
        cout << "\n** Seleccine el dato a cambiar\n";
        cout << "1. Edad\n";
        cout << "2. Estado de salud\n";
        cout << "3. Horas de suenio maximas\n";
        cout << "4. Cantidad de kg en dieta\n";
        cout << "5. Agregar juguetes\n";
        cout << "6. Eliminar juguete\n";
        cout << "7. Agregar alimeto a la dieta del animal\n";
        cout << "8. Eliminar alimeto de la dieta del animal\n";
        cout << "0. Guardar y salir"<< endl;

        cin >> opc;
        if(!cin.good()){
            throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
        }

        switch (opc) {
            case 1:
                do {
                    cout << "Ingrese la nueva edad del animal: " << endl;
                    cin >> edad;

                    if(!cin.good()){
                        throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
                    }
                    if(edad < this->edad){
                        cout << "Esta edad es menor a la edad actual del animal" << endl;
                    }

                }while(edad < this->edad || edad > 100);// caso de manejo para que la nueva edad este en un rango permitido
                this->setEdad(edad);
                cout << "Ahora la edad del animal es de "<<this->getEdad() << endl;
                break;

            case 2:
                cin.ignore();
                cout << "Ingrese el estado actual de salud del animal: " << endl;
                getline(cin, salud, '\n');

                salud = convertidorStringMinuscula3(salud);
                this->setEstadoDeSalud(salud);
                cout << "Ahora el estado de salud del animal es de "<<this->getEstadoDeSalud()<< endl;
                break;

            case 3:
                do {
                    cout << "Ingrese las nuevas horas de sueño del animal: " << endl;
                    cin >> hDormir;

                    if(!cin.good()){
                        throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
                    }

                }while(hDormir <= 0); //caso de manejo para que el animal duerma al menos 1 hora
                this->setCantMaxDormir(hDormir);
                cout << "Ahora las horas de suenio del animal son de "<<this->getCantMaxDormir() << endl;
                break;
            case 4:
                do {
                    try {
                        editarAlimento();
                        cout << "Ya se edito con exito las porciones de alimentos" << endl;
                        terminado = true;
                    }
                    catch (const invalid_argument error) {
                        cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        terminado = false;
                    }
                }
                while(terminado == false);
                terminado = false;
                break;

            case 5:
                do {
                    cout << "Ingrese el numero de juguetes que va agregar a la lista del animal: " << endl;
                    cin >> cantJuguetes;

                    if(!cin.good()){
                        throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
                    }

                }while(cantJuguetes <= 0);//caso de excepcion para que añada al menos 1 juguete

                cin.ignore();
                while(cantJuguetes > 0){
                    cout << " - Ingrese ingrese el nombre del juguete: " << endl;
                    getline(cin, jugueteNom, '\n');

                    jugueteNom= convertidorStringMinuscula3(jugueteNom);
                    this->juguetes.push_back(jugueteNom);
                    cantJuguetes--;
                }
                cout << "Se agrego corectamente el/los jueguete/s" << endl;
                break;
            case 6:
                cin.ignore();
                //condicional para evitar que el animal se quede sin juguetes
                if(juguetes.size() == 1){
                    cout << "No puede eliminar el unico juguete de " << nombre << endl;
                }
                else {
                    do {
                        cout << "Ingrese el nombre: " << endl;
                        getline(cin, jugueteEliminar, '\n');

                        jugueteEliminar = convertidorStringMinuscula3(jugueteEliminar);
                    } while (!eliminarJuguetes(jugueteEliminar)); //caso de excepcion para no ingresar un juguete que no se puede eliminar
                    cout << "Se elimino correctamente el juguete" << jugueteEliminar << endl;
                }
                break;
            case 7:
                cin.ignore();
                if(alimentacion == "carnivoro"){
                    agregarAlimentoaMap(dietaCarnivora);
                }
                else if(alimentacion == "herbivoro"){
                    cin.ignore();
                    agregarAlimentoaMap(dietaHerbivora);
                }
                else{
                    cin.ignore();
                    agregarAlimentoaMapOmnivoro(dietaHerbivora,dietaCarnivora);
                }
                cout << "Se agrego corectamente el alimento" << endl;
                break;
            case 8:
                cin.ignore();
                do {
                    cout << "Ingrese el alimento: " << endl;
                    getline(cin, alimentoEliminar, '\n');
                    alimentoEliminar = convertidorStringMinuscula3(alimentoEliminar);
                }while(!eliminarAlimento(alimentoEliminar)); //caso de manejo para no ingresar un alimento que no se puede eliminar
                cout << "Se elimino correctamente el alimento "<<alimentoEliminar << endl;
                break;
            default:
                break;
        }
    } while (opc != 0);
}

//Este metodo imprime los juguetes del animal y pide al usuario escoger uno para jugar
// Imprime mensaje confirmando que el animal esta jugando con el juguete escogido
void Animal::jugando(string nombre) {
    int opc;
    cout << "**Juguetes de " << nombre << endl;

    for (int i = 0; i < this->juguetes.size(); i++) {
        cout << i+1 << ". " << juguetes[i] << endl;
    }

    do {
        cout << "Ingrese una opcion: " << endl;
        cin >> opc;

        if(!cin.good()){
            throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
        }

        opc -=1;
    }while(opc < 0 || opc > juguetes.size());

    cout << nombre << " esta jugando con su " << juguetes[opc] << endl;

}

//Busca un alimento en la dieta del animal
bool Animal::existeAlim(string alimento) {
    unordered_map <string, int>::iterator itMapA;
    for (itMapA = this->alimentos.begin(); itMapA != this->alimentos.end(); ++itMapA) {
        if(itMapA->first == alimento){
            return true;
        }
    }
    cout << "Alimento no valido para el animal" << endl;
    return false;
}

//Este metodo imprime los alimentos del animal, verifica que sea parte de su dieta
// y pide al usuario escoger uno con la cantidad de kg de alimento, esta cantidad debe coincidir con la del mapa "alimentos"
// Imprime mensaje confirmando que el animal esta comiendo el alimento escogido
void Animal::comiendo(string nombre) {
    string alimento;
    int kg;
    bool existe = false;

    while(!existe){
        cout << "Ingrese el alimento : " << endl;
        cin >> alimento;
        existe = existeAlim(alimento);
    }
    do {
        cout << "Ingrese la cantidad de kilogramos de alimento: " << endl;
        cin >> kg;
    }while(kg != this->alimentos[alimento]);
    //

    cout << nombre << " esta comiendo " << kg << "kg de " << alimento << endl;
}

//Pide al usuario la cantidad de horas que el animal va a dormir
// teniendo en cuenta las horas que el animal ha dormido en el dia verifica si la cantidad ingresada
// sobrepasa el limite de sueño
// Imprime mensaje confirmando que el animal va a dormir la cantidad de horas ingresadas
void Animal::durmiendo() {
    int hDormir;
    if (cantHorasDormidas < cantMaxDormir) {
        do {
            cout << "Ingrese las horas de suenio: " << endl;
            cin >> hDormir;

            if(!cin.good()){
                throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
            }

            if (this->cantMaxDormir < hDormir + this->cantHorasDormidas) {
                cout << "Esta cantidad se excede del limite de suenio del animal " << endl;
            }
        } while (this->cantMaxDormir < hDormir + this->cantHorasDormidas);
        this->cantHorasDormidas += hDormir;

        cout << nombre << " va a dormir durante " << hDormir << " hora(s)" << endl;
    }
    else{
        cout << nombre <<" ya ha dormido suficiente el dia de hoy" << endl;
    }
}

//Menu para elegir una actividad para el animal: jugar, comer o dormir
// verifica si el animal ya comio o jugo en dia de hoy
void Animal::interactAnimal(string opc) {
    string nombre = this->getNombre();
    bool terminado = false;

    if(opc == "jugar") {
        do {
            try {
                if(!jugar) {
                    jugando(nombre);
                    this->jugar = true;
                }
                else{
                    cout << nombre <<" ya ha jugado el dia de hoy" << endl;
                }
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }
        while(terminado == false);
        terminado = false;
    }
    else if(opc == "comer") {

        if(!comer) {
            comiendo(nombre);
            this->comer = true;
        }
        else{
            cout << nombre <<" ya ha comido el dia de hoy" << endl;
        }

    }
    else if(opc == "dormir") {
        do {
            try {
                durmiendo();
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }
        while(terminado == false);
        terminado = false;
    }
    else {
        throw invalid_argument("Esta no es una actividad posible");
    }


}

//Esta funcion agrega ciertos alimentos por defecto segun el tipo de dieta
//y le pide al usuario ingresar las cantidades
void Animal::elegirAlim(string tipoAlim) {
    bool terminado = false;
    if (tipoAlim == "carnivoro") {

        cout << "- Res" << endl;
        do {
            try {
                this->alimentos.insert(make_pair("res", aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }
        while(terminado == false);
        terminado = false;

        cout << "- Pollo" << endl;
        do {
            try {
                this->alimentos.insert(make_pair("pollo", aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }while(terminado == false);
        terminado = false;

        cout << "- Pescado" << endl;
        do {
            try {
                this->alimentos.insert(make_pair("pescado", aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }while(terminado == false);
        terminado = false;

    } else if (tipoAlim == "herbivoro") {

        cout << "- Frutas" << endl;

        do {
            try {
                this->alimentos.insert(make_pair("frutas", aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }while(terminado == false);
        terminado = false;

        cout << "- Verduras" << endl;
        bool terminado = false;
        do {
            try {
                this->alimentos.insert(make_pair("verduras", aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }while(terminado == false);
        terminado = false;

        cout << "- Granos" << endl;
        do {
            try {
                this->alimentos.insert(make_pair("granos", aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }while(terminado == false);
        terminado = false;

    } else if (tipoAlim == "omnivoro") {

        cout << "- Res" << endl;
        do {
            try {
                this->alimentos.insert(make_pair("res", aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }
        while(terminado == false);
        terminado = false;

        cout << "- Pollo" << endl;
        do {
            try {
                this->alimentos.insert(make_pair("pollo", aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }
        while(terminado == false);
        terminado = false;

        cout << "- Frutas" << endl;
        do {
            try {
                this->alimentos.insert(make_pair("frutas", aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }
        while(terminado == false);
        terminado = false;

        cout << "- Verduras" << endl;
        do {
            try {
                this->alimentos.insert(make_pair("verduras", aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }
        while(terminado == false);
        terminado = false;
    }
}


//Metodo que imprime los alimentos de un animal con sus respectivas cantidades
void Animal::mostrarMapAlimentacion() {
    unordered_map<string, int>::iterator itMapP;
    int contador = 1;

    for (itMapP = this->alimentos.begin(); itMapP != this->alimentos.end(); ++itMapP){
        cout << "   -- ALIMENTO:"<< contador<< "--"<<endl;
        cout << "       Nombre: " << itMapP->first<< endl;
        cout << "       Cantidad de kg: " << itMapP->second<< endl;
        contador++;
    }
}

//Metodo que imprime los juguetes de un animal
void Animal::mostrarJuguetes() {
    vector<string>::iterator itVector;
    int contador = 1;

    for (itVector = this->juguetes.begin(); itVector!= this->juguetes.end(); ++itVector){
        cout << contador << ". " << (*itVector) << endl;
        contador++;
    }
}
