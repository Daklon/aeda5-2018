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

    void Buscar(Clave x){

    }

    void Insertar(Clave x){
        if(numOfElements == 0){
            head = new NodeBB<Clave>(x);
            this->numOfElements++;
        } else {
            bool itera = true;
            this->temp_head = head;
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

    }
    
private:
    NodeBB<Clave> *head;
    NodeBB<Clave> *temp_head;
    NodeBB<Clave> *temp_data;
    int numOfElements;
};


#endif
