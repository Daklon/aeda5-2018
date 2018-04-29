#ifndef TREEABB_H
#define TREEABB_H

#include "DNI.h"
#include "nodeBB.h"
#include <vector>
#include <string>

template<typename Clave>
class Treeabb
{
public:
    Treeabb(){
        this->numOfElements = 0;
        this->numOfComparisons = 0;
        this->head = nullptr;
        this->temp_data = nullptr;
        this->temp_head = nullptr;
    }

    NodeBB<Clave>* Buscar(Clave x){
        this->temp_head = this->head;
        Clave temp_clave;
        bool itera = true;
        NodeBB<Clave> *encontrado = nullptr;
        //iteramos
        while(itera){
            temp_clave = this->temp_head->GetClave();
            //incrementamos las comparaciones
            this->numOfComparisons++;
            //si el nodo "raiz" es la clave, la devolvemos
            if(x == temp_clave){
                itera = false;
                encontrado = temp_head;
            } else if(x < temp_clave){
                //recorremos subarbol izquierdo
                if(this->temp_head->GetLeftChildren() != nullptr){
                    //establecemos el siguiente nodo como "raiz" y iteramos en el bucle
                    this->temp_head = this->temp_head->GetLeftChildren();
                } else {
                    //si es null, hemos llegado al fina, el elemento no esta en el arbol
                    itera = false;
                    encontrado = nullptr;
                }
            } else if(x > temp_clave){
                //recorremos subarbol derecho
                if(this->temp_head->GetRightChildren() != nullptr){
                    //establecemos el siguiente nodo como "raiz" y iteramos en el bucle
                    this->temp_head = this->temp_head->GetRightChildren();
                } else {
                    //si es null, hemos llegado al final, el elemento no esta en el arbol
                    itera = false;
                    encontrado = nullptr;
                }
            }
        }
        return encontrado;
    }

    void Insertar(Clave x){
        //si el arbol esta vacio
        if(this->numOfElements == 0){
            this->head = new NodeBB<Clave>(x);
            this->numOfElements++;
        //si no esta vacio
        } else {
            bool itera = true;
            this->temp_head = this->head;
            this->temp_data = new NodeBB<Clave>(x);
            while (itera) {
                //aumentamos el contador
                this->numOfComparisons++;
                //subarbol derecho
                if (x > this->temp_head->GetClave()){
                    //si es null, insertamos
                    if(this->temp_head->GetRightChildren() == nullptr){
                        this->temp_head->SetRightChildren(this->temp_data);
                        this->temp_data->SetFather(this->temp_head);
                        this->numOfElements++;
                        itera = false;
                    //si no es null, entramos e iteramos
                    } else {
                        this->temp_head = this->temp_head->GetRightChildren();
                    }
                //subarbol izquierdo
                } else if(x < this->temp_head->GetClave()){
                    //si es null entramos
                    if(this->temp_head->GetLeftChildren() == nullptr){
                        this->temp_head->SetLeftChildren(this->temp_data);
                        this->temp_data->SetFather(this->temp_head);
                        this->numOfElements++;
                        itera = false;
                    //si no es null entramos e iteramos
                    } else {
                        this->temp_head = this->temp_head->GetLeftChildren();
                    }
                } else {
                    //si estamos insertando una copia, aumentamos el contador de copias
                    this->temp_head->IncreaseCounter();
                }
            }
        }
    }

    void Eliminar(Clave x){
        bool itera=true;
        this->temp_head = this->Buscar(x);
        //si el nodo no tiene hijos
        if(this->temp_head->GetLeftChildren() == nullptr && this->temp_head->GetRightChildren() == nullptr){
            if(this->temp_head->GetFather()->GetRightChildren() == this->temp_head){
                //compruebo si el nodo a borrar es el derecho de su padre y lo borro
                this->temp_head->GetFather()->SetRightChildren(nullptr);
                delete this->temp_head;
            } else {
                //si no, el nodo a borrar es el izquierdo de su padre, lo borro
                this->temp_head->GetFather()->SetLeftChildren(nullptr);
                delete this->temp_head;
                this->numOfElements;
            }
            //si el nodo tiene dos hijos
        } else if(this->temp_head->GetLeftChildren() != nullptr && this->temp_head->GetRightChildren() != nullptr){


            //si el nodo tiene un solo hijo
        } else {
            if(this->temp_head->GetFather()->GetRightChildren() == this->temp_head){
                //compruebo si el nodo a borrar es el derecho de su padre y lo borro
                if(temp_head->GetRightChildren() != nullptr){
                    this->temp_head->GetFather()->SetRightChildren(this->temp_head->GetRightChildren());
                } else {
                    this->temp_head->GetFather()->SetRightChildren(this->temp_head->GetLeftChildren());
                }
                delete this->temp_head;
                this->numOfElements--;
            } else {
                //si no, el nodo a borrar es el izquierdo de su padre, lo borro
                if(temp_head->GetRightChildren() != nullptr){
                    this->temp_head->GetFather()->SetLeftChildren(this->temp_head->GetRightChildren());
                } else {
                    this->temp_head->GetFather()->SetLeftChildren(this->temp_head->GetLeftChildren());
                }
                delete this->temp_head;
                this->numOfElements--;
            }
        }
    }

    void print(){
        //recorrer el arbol y ir guardandolo todo en la matriz output

        //pintar la matriz output por pantalla
    }

    int GetComparisons(){
        return this->numOfComparisons;
    }
    void ResetStatistics(){
        this->numOfComparisons=0;
    }
private:
    std::vector<std::string> output;
    NodeBB<Clave> *head;
    NodeBB<Clave> *temp_head;
    NodeBB<Clave> *temp_data;
    int numOfElements;
    int numOfComparisons;
};


#endif
