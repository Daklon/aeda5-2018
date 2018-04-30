#include <iostream>
#include "treeABB.h"
#include <vector>
#include "random"

using namespace std;

int tamArbol,nPruebas,mode,min1,max1,average1,min2,max2,average2;

void AskData(){
    cout << "Introduzca el tamaño del arbol:";
    cin >> tamArbol;
    cout << "Introduzca el numero de pruebas:";
    cin >> nPruebas;
}

void SelectMode(){
    cout << "--------------------------------" << endl;
    cout << "    Arbol de busqueda binario"<< endl<<endl;
    cout << "Elija el modo:" <<endl<< "0 - Demostracion"<<endl<<"1 - Estadistica"<<endl;
    cin >> mode;
}

void PrintStatistics(){
    cout << "     Numero de comparaciones" << endl;
    cout << "           " << "N" << "  " << "Pruebas"<< " " << "Minimo"<< " " << "Medio" << " " << "Maximo" << endl;
    cout << "Busqueda" << "  " << tamArbol<< "     " << nPruebas << "      " << min1 << "      " << (average1/nPruebas) << "     " << max1 << endl;
    cout << "Insercion" << " " << tamArbol<< "     " << nPruebas << "      " << min2 << "      " << (average2/nPruebas) << "     " << max2 << endl;
}

void CheckStatistics(int numOfComparisons, int fase){
    if(fase == 1){
        if(min1 == -1){
            min1 = numOfComparisons;
        } else if(min1 > numOfComparisons){
            min1 = numOfComparisons;
        }

        if(max1 == -1){
            max1 = numOfComparisons;
        } else if(max1 < numOfComparisons){
            max1 = numOfComparisons;
        }

        average1 += numOfComparisons;
    } else if(fase == 2){
        if(min2 == -1){
            min2 = numOfComparisons;
        } else if(min2 > numOfComparisons){
            min2 = numOfComparisons;
        }

        if(max2 == -1){
            max2 = numOfComparisons;
        } else if(max2 < numOfComparisons){
            max2 = numOfComparisons;
        }

        average2 += numOfComparisons;
    }
}

void DemoMode(){
    int input,value;
    bool run = true;
    Treeabb<int> arbol;
    while(run){
        cout << endl << "[0] Salir" << endl;
        cout << "[1] Insertar Clave" << endl;
        cout << "[2] Eliminar Clave" << endl;
        cin >> input;
        if(input == 0){
            run = false;
        } else if(input == 1){
            cout << "Introduzca el valor de la clave a insertar:";
            cin >> value;
            arbol.Insertar(value);
            arbol.print();
        } else if(input == 2){
            cout << "Introduzca el valor de la clave a eliminar:";
            cin >> value;
            arbol.Eliminar(value);
            arbol.print();
        }
    }
}

int main()
{
    SelectMode();

    if(mode == 0){
        DemoMode();
    } else if(mode==1){
        //estadistica
        AskData();
        //creamos el banco de pruebas
        vector<DNI> testbench;
        for(int i=0;i<2*tamArbol;i++){
            DNI aleat;
            testbench.push_back(aleat);
        }
        //creamos el arbol y insertamos la mitad de elementos del banco de pruebas
        Treeabb<DNI> arbol;
        for(int i=0;i<tamArbol;i++){
            arbol.Insertar(testbench.at(i));
        }

        //reseteamos estadisitcas
        arbol.ResetStatistics();
        min1 = -1;
        max1 = -1;
        average1 = 0;

        //generador números aleatorios
        std::random_device rd;
        std::mt19937 eng(rd());
        std::uniform_int_distribution<> distr(0,tamArbol-1);

        //fase 1: prueba de busqueda
        for(int i=0;i<nPruebas;i++){
            arbol.Buscar(testbench.at(distr(eng)));
            CheckStatistics(arbol.GetComparisons(),1);
            arbol.ResetStatistics();
        }

        //fase2: inserción
        //reseteamos estadisticas
        arbol.ResetStatistics();
        min2 = -1;
        max2 = -1;
        average2 = 0;

        //generador de numeros aleatorios
        std::uniform_int_distribution<> distr2(tamArbol-1,(tamArbol*2)-1);

        //buscamos las npruebas claves que no están en el arbol
        for(int i=0;i<nPruebas;i++){
            arbol.Buscar(testbench.at(distr2(eng)));
            CheckStatistics(arbol.GetComparisons(),2);
            arbol.ResetStatistics();
        }

        //hemos acabado, mostramos los resultados
        PrintStatistics();

    } else if(mode == 2){
        Treeabb<int> arbol;
        arbol.Insertar(8);
        arbol.Insertar(3);
        arbol.Insertar(10);
        arbol.Insertar(1);
        arbol.Insertar(6);
        arbol.Insertar(14);
        arbol.Insertar(4);
        arbol.Insertar(7);
        arbol.Insertar(13);
        arbol.print();
    } else {
        cout << "Modo incorrecto";
        return 0;
    }
    return 0;
}
