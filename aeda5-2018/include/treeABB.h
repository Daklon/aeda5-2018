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
        this->temp_head = this->Buscar(x);

        if(this->temp_head->GetLeftChildren() == nullptr && this->temp_head->GetRightChildren() == nullptr){
            //si el nodo no tiene hijos
            if(this->temp_head == this->head){
                this->head = this->DeleteNodeWithoutChildren(this->temp_head);

            } else {
                this->DeleteNodeWithoutChildren(this->temp_head);
            }

        } else if(this->temp_head->GetLeftChildren() != nullptr && this->temp_head->GetRightChildren() != nullptr){
            //si el nodo tiene dos hijos
            if(this->temp_head == this->head){
                this->head = this->DeleteNodeWithTwoChildren(this->temp_head);
            } else {
                this->DeleteNodeWithTwoChildren(this->temp_head);
            }

        } else {
            //si el nodo tiene un solo hijo
            if(this->temp_head == this->head){
                this->head = this->DeleteNodeWithOneChildren(this->temp_head);
            } else {
                this->DeleteNodeWithOneChildren(this->temp_head);
            }
        }
    }

    void print(){
        //recorrer el arbol y ir guardandolo todo en la matriz output
        this->recorrido(this->head,0);
        //pintar la matriz output por pantalla
        for(int i=0;i<this->output.size();i++){
            std::cout << this->output.at(i) << std::endl;
        }
        this->output.clear();
    }


    int GetComparisons(){
        return this->numOfComparisons;
    }
    void ResetStatistics(){
        this->numOfComparisons=0;
    }

private:

    //recorremos recursivamente, primero por la mitad izquierda, guardando en un buffer el arbol
    void recorrido(NodeBB<Clave> *head,int depth){
        std::string data;
        if(head != nullptr){

            data = "[" + to_string(head->GetClave()) + ']';

            if(depth < this->output.size()){
                this->output.at(depth) += data;
            } else {
                this->output.push_back("Nivel ");
                this->output.at(depth) += std::to_string(depth) + ": " + data;
            }

            this->recorrido(head->GetLeftChildren(),depth+1);
            this->recorrido(head->GetRightChildren(),depth+1);
        } else {

            data = "[.]";

            if(depth < this->output.size()){
                this->output.at(depth) += data;
            } else {
                this->output.push_back("Nivel ");
                this->output.at(depth) += std::to_string(depth) + ": " +data;
            }
        }
    }

    //obtenemos el menor nodo de un subarbol dado
    NodeBB<Clave>* GetSmallestNode(NodeBB<Clave> *head){
        bool itera = true;
        while(itera){
            if(head->GetLeftChildren() == nullptr){
                itera = false;
            } else {
                head = head->GetLeftChildren();
            }
        }
        return head;
    }

    //obtenemos el mayor nodo de un subarbol dado
    NodeBB<Clave>* GetBigestNode(NodeBB<Clave> *head){
        bool itera = true;
        while(itera){
            if(head->GetRightChildren() == nullptr){
                itera = false;
            } else {
                head = head->GetRightChildren();
            }
        }
        return head;
    }

    NodeBB<Clave>* DeleteNodeWithoutChildren(NodeBB<Clave> *head){
        if(head->GetFather() != nullptr){
            if(head->GetFather()->GetRightChildren() == head){
                //compruebo si el nodo a borrar es el derecho de su padre y lo borro
                head->GetFather()->SetRightChildren(nullptr);
            } else {
                //si no, el nodo a borrar es el izquierdo de su padre, lo borro
                head->GetFather()->SetLeftChildren(nullptr);
            }
        }
        this->numOfElements--;
        delete head;

        return nullptr;
    }

    NodeBB<Clave>* DeleteNodeWithOneChildren(NodeBB<Clave> *head){
        NodeBB<Clave> *temp_head_ptr;
        if(head->GetFather() != nullptr){
            if(head->GetFather()->GetRightChildren() == head){
                //compruebo si el nodo a borrar es el derecho de su padre y reemplazo punteros
                if(head->GetRightChildren() != nullptr){
                    head->GetFather()->SetRightChildren(head->GetRightChildren());
                } else {
                    head->GetFather()->SetRightChildren(head->GetLeftChildren());
                }
            } else {
                //si no, el nodo a borrar es el izquierdo de su padre, reemplazo punteros
                if(head->GetRightChildren() != nullptr){
                    head->GetFather()->SetLeftChildren(head->GetRightChildren());
                } else {
                    head->GetFather()->SetLeftChildren(head->GetLeftChildren());
                }
            }
        } else {
            if(head->GetRightChildren() != nullptr){
                temp_head_ptr = head->GetRightChildren();

            } else {
                temp_head_ptr = head->GetLeftChildren();
            }
            temp_head_ptr->SetFather(nullptr);
        }
        this->numOfElements--;
        delete head;
        return temp_head_ptr;
    }

    NodeBB<Clave>* DeleteNodeWithTwoChildren(NodeBB<Clave> *head){
        Clave temp_key;
        int temp_numOfCopies;
        NodeBB<Clave> *temp_key_ptr;
        if(this->deleteside){
            temp_key_ptr = this->GetBigestNode(head->GetLeftChildren());
            this->deleteside = false;
        } else {
            temp_key_ptr = this->GetSmallestNode(head->GetRightChildren());
            this->deleteside = true;
        }

        //guardamos el valor del nodo elegido
        temp_key = temp_key_ptr->GetClave();
        //y el numero de copias
        temp_numOfCopies = temp_key_ptr->GetNumOfCopies();
        //eliminamos el nodo elegido(lo vamos a mover a la raiz)
        this->Eliminar(temp_key);
        //establecemos el valor del nodo a eliminar al nodo elegido para sustituirlo
        head->SetClave(temp_key);
        //y su número de copias
        head->SetNumOfCopies(temp_numOfCopies);
        //devolvemos head, por ahora no es necesario ya que el puntero no cambia, solo su valor
        return head;
    }

private:
    std::vector<std::string> output;
    NodeBB<Clave> *head;
    NodeBB<Clave> *temp_head;
    NodeBB<Clave> *temp_data;
    int numOfElements;
    int numOfComparisons;
    bool deleteside = false;
};


#endif
