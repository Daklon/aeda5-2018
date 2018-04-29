#ifndef TREEABB_H
#define TREEABB_H

#include "DNI.h"
#include "nodeBB.h"

template<typename Clave>
class Treeabb
{
public:
    Treeabb(){
        this->numOfElements = 0;
        this->head = nullptr;
    }

    NodeBB* Buscar(Clave x){
        this->temp_head = this->head;
        Clave temp_clave;
        bool itera = true;
        NodeBB *encontrado = nullptr;
        //iteramos
        while(itera){
            temp_clave = this->temp_head->GetClave();
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
        if(this->numOfElements == 0){
            this->head = new NodeBB<Clave>(x);
            this->numOfElements++;
        } else {
            bool itera = true;
            this->temp_head = this->head;
            this->temp_data = new NodeBB<Clave>(x);
            while (itera) {
                if (x > this->temp_head->GetClave()){
                    if(this->temp_head->GetRightChildren() == nullptr){
                        this->temp_head->SetRightChildren(this->temp_data);
                        this->temp_data->SetFather(this->temp_head);
                        this->numOfElements++;
                        itera = false;
                    } else {
                        this->temp_head = this->temp_head->GetRightChildren();
                    }
                } else if(x < this->temp_head->GetClave()){
                    if(this->temp_head->GetLeftChildren() == nullptr){
                        this->temp_head->SetLeftChildren(this->temp_data);
                        this->temp_data->SetFather(this->temp_head);
                        this->numOfElements++;
                        itera = false;
                    } else {
                        this->temp_head = this->temp_head->GetLeftChildren();
                    }
                } else {
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
            } else {
                //si no, el nodo a borrar es el izquierdo de su padre, lo borro
                if(temp_head->GetRightChildren() != nullptr){
                    this->temp_head->GetFather()->SetLeftChildren(this->temp_head->GetRightChildren());
                } else {
                    this->temp_head->GetFather()->SetLeftChildren(this->temp_head->GetLeftChildren());
                }
                delete this->temp_head;
            }
        }
    }

    void print(){

    }
    
private:
    NodeBB<Clave> *head;
    NodeBB<Clave> *temp_head;
    NodeBB<Clave> *temp_data;
    int numOfElements;
};


#endif
