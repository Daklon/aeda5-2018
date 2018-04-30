#ifndef NODEBB_H
#define NODEBB_H
#include "DNI.h"

template<typename Clave>
class NodeBB
{
public:
    NodeBB(){} //revisar, lo mismo es mejor quitarlo
    NodeBB(Clave x){
        this->data = x;
        this->numOfCopies = 1;
        this->father_ptr = nullptr;
        this->leftChildren_ptr = nullptr;
        this->rightChildren_ptr = nullptr;
    }

    void SetFather(NodeBB *father){
        this->father_ptr = father;
    }

    NodeBB *GetFather(){
        return this->father_ptr;
    }

    void SetLeftChildren(NodeBB *leftchildren){
        this->leftChildren_ptr = leftchildren;
    }

    NodeBB *GetLeftChildren(){
        return this->leftChildren_ptr;
    }

    void SetRightChildren(NodeBB *rightchildren){
        this->rightChildren_ptr = rightchildren;
    }

    NodeBB *GetRightChildren(){
        return this->rightChildren_ptr;
    }

    Clave GetClave(){
        return this->data;
    }

    void SetClave(Clave data){
        this->data = data;
    }

    void IncreaseCounter(){
        this->numOfCopies++;
    }

    void DecreaseCounter(){
        this->numOfCopies--;
    }

    int GetNumOfCopies(){
        return this->numOfCopies;
    }

    void SetNumOfCopies(int numOfCopies){
        this->numOfCopies = numOfCopies;
    }

private:
    NodeBB *father_ptr;
    NodeBB *leftChildren_ptr;
    NodeBB *rightChildren_ptr;
    Clave data;
    int numOfCopies;
};

#endif
